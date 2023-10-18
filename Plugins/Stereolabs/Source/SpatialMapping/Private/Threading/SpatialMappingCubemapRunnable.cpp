//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "SpatialMapping/Private/Threading/SpatialMappingCubemapRunnable.h"
#include "SpatialMappingPrivatePCH.h"
#include "SpatialMapping/Public/Core/SpatialMappingCubemapManager.h"

FSpatialMappingCubemapRunnable::FSpatialMappingCubemapRunnable(FSpatialMappingCubemapProxy* CubemapProxy)
	:
	bPixelsInitialized(false),
	CubemapProxy(CubemapProxy)
{
}

bool FSpatialMappingCubemapRunnable::Init()
{
	OutputBuffersLDR.AddZeroed(6);
	OutputBuffersHDR.AddZeroed(6);
	
	return FSlRunnable::Init();
}

uint32 FSpatialMappingCubemapRunnable::Run()
{
	FPlatformProcess::SleepNoStats(0.0f);

	while (bIsRunning)
	{
		if (bIsSleeping)
		{
			FPlatformProcess::ConditionalSleep([this]() -> bool {
				return !bIsSleeping;
			});
		}

		Timer.Start();

		if (!CubemapProxy->bComplete && CubemapProxy->Cubemap && bPixelsInitialized)
		{
			ConverToTextureCube();
			bPixelsInitialized = false;
			CubemapProxy->bComplete = true;
		}

		Timer.Stop();

		if (Timer.CanSleep())
		{
			FPlatformProcess::Sleep(Timer.GetSleepingTimeSeconds());
		}
	}

	return 0;
}

void FSpatialMappingCubemapRunnable::Stop()
{
	FSlRunnable::Stop();
}

void FSpatialMappingCubemapRunnable::Exit()
{
	CubemapProxy = nullptr;
}

void FSpatialMappingCubemapRunnable::Start(float Frequency)
{
	static uint64 ThreadCounter = 0;

	Timer.SetFrequency(Frequency);

	FString ThreadName("ZEDCubemapMakerThread");
	ThreadName.AppendInt(ThreadCounter++);

	Thread = FRunnableThread::Create(this, *ThreadName, 0, TPri_BelowNormal);
}

void FSpatialMappingCubemapRunnable::GetPixels()
{
	const EPixelFormat PixelFormat = CubemapProxy->TextureTarget->GetFormat();
	ETextureSourceFormat TextureFormat = TSF_Invalid;
	switch (PixelFormat)
	{
		case PF_FloatRGBA:
			TextureFormat = TSF_RGBA16F;
			break;
		case PF_B8G8R8A8:
			TextureFormat = TSF_BGRA8;
			break;
	}

	FTextureRenderTargetCubeResource* CubeResource = (FTextureRenderTargetCubeResource*)static_cast<FTextureRenderTargetResource*>(CubemapProxy->TextureTarget->GetResource());

	if (CubeResource && TextureFormat != TSF_Invalid)
	{
		switch (TextureFormat)
		{
			case TSF_BGRA8:
			{
				AsyncTask(ENamedThreads::GameThread, [this, CubeResource = CubeResource]()
				{
					for (int32 SliceIndex = 0; SliceIndex < 6; SliceIndex++)
					{
						CubeResource->ReadPixels(OutputBuffersLDR[SliceIndex], FReadSurfaceDataFlags(RCM_UNorm, (ECubeFace)SliceIndex));
					}

					bPixelsInitialized = true;
				});
			}
			break;
			case TSF_RGBA16F:
			{
				AsyncTask(ENamedThreads::GameThread, [this, CubeResource = CubeResource]()
				{
					for (int32 SliceIndex = 0; SliceIndex < 6; SliceIndex++)
					{
						CubeResource->ReadPixels(OutputBuffersHDR[SliceIndex], FReadSurfaceDataFlags(RCM_UNorm, (ECubeFace)SliceIndex));
					}

					bPixelsInitialized = true;
				});
			}
			break;
		}
	}
}

void FSpatialMappingCubemapRunnable::ConverToTextureCube()
{
	// Check render target size is valid and power of two.
	if (CubemapProxy->TextureTarget->SizeX != 0 && !(CubemapProxy->TextureTarget->SizeX & (CubemapProxy->TextureTarget->SizeX - 1)))
	{
		const EPixelFormat PixelFormat = CubemapProxy->TextureTarget->GetFormat();
		ETextureSourceFormat TextureFormat = TSF_Invalid;
		switch (PixelFormat)
		{
			case PF_FloatRGBA:
				TextureFormat = TSF_RGBA16F;
				break;
			case PF_B8G8R8A8:
				TextureFormat = TSF_BGRA8;
				break;
		}

		// The r2t resource will be needed to read its surface contents
		FTextureRenderTargetCubeResource* CubeResource = (FTextureRenderTargetCubeResource*)static_cast<FTextureRenderTargetResource*>(CubemapProxy->TextureTarget->GetResource());
		if (CubeResource && TextureFormat != TSF_Invalid)
		{
			bool bSRGB = true;
			// if render target gamma used was 1.0 then disable SRGB for the static texture
			if (FMath::Abs(CubeResource->GetDisplayGamma() - 1.0f) < KINDA_SMALL_NUMBER)
			{
				bSRGB = false;
			}

			int32 MipSize = CalculateImageBytes(CubemapProxy->TextureTarget->SizeX, CubemapProxy->TextureTarget->SizeX, 0, PixelFormat);

			if (CubemapProxy->Cubemap->GetPlatformData())
			{
				delete CubemapProxy->Cubemap->GetPlatformData();
				CubemapProxy->Cubemap->SetPlatformData( nullptr );
			}

			CubemapProxy->Cubemap->SetPlatformData( new FTexturePlatformData() );
			CubemapProxy->Cubemap->GetPlatformData()->SizeX = CubemapProxy->TextureTarget->SizeX;
			CubemapProxy->Cubemap->GetPlatformData()->SizeY = CubemapProxy->TextureTarget->SizeX;
			CubemapProxy->Cubemap->GetPlatformData()->PixelFormat = PixelFormat;

			{
				FTexture2DMipMap* Mip = new FTexture2DMipMap(CubemapProxy->Cubemap->GetPlatformData()->Mips[0]);
				Mip->SizeX = CubemapProxy->TextureTarget->SizeX;
				Mip->SizeY = CubemapProxy->TextureTarget->SizeX;
				Mip->BulkData.Lock(LOCK_READ_WRITE);
					Mip->BulkData.Realloc(Mip->SizeX * Mip->SizeY * 6 * GPixelFormats[PixelFormat].BlockBytes);
				Mip->BulkData.Unlock();
			}

			FTexture2DMipMap& Mip = CubemapProxy->Cubemap->GetPlatformData()->Mips[0];
			uint8* SliceData = (uint8*)Mip.BulkData.Lock(LOCK_READ_WRITE);
			
			switch (TextureFormat)
			{
				case TSF_BGRA8:
				{
					for (int32 SliceIndex = 0; SliceIndex < 6; SliceIndex++)
					{
						FMemory::Memcpy((FColor*)(SliceData + SliceIndex * MipSize), OutputBuffersLDR[SliceIndex].GetData(), MipSize);
					}
				}
				break;
				case TSF_RGBA16F:
				{
					for (int32 SliceIndex = 0; SliceIndex < 6; SliceIndex++)
					{
						FMemory::Memcpy((FFloat16Color*)(SliceData + SliceIndex * MipSize), OutputBuffersHDR[SliceIndex].GetData(), MipSize);
					}
				}
				break;
			}

			Mip.BulkData.Unlock();

			CubemapProxy->Cubemap->SRGB = bSRGB;
			// If HDR source image then choose HDR compression settings..
			CubemapProxy->Cubemap->CompressionSettings = TextureFormat == TSF_RGBA16F ? TextureCompressionSettings::TC_HDR : TextureCompressionSettings::TC_Default;
#if WITH_EDITORONLY_DATA
			CubemapProxy->Cubemap->CompressionNone = true;
			CubemapProxy->Cubemap->CompressionNoAlpha = true;
			CubemapProxy->Cubemap->DeferCompression = true;
			CubemapProxy->Cubemap->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
#endif
		}
	}
}