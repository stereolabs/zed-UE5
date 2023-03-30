//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsTextureBatch.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

DEFINE_LOG_CATEGORY(SlTextureBatch);

/*
 * Retrieve the free buffer
 */
#define GET_TB_FREE_BUFFER() (BuffersPool.Num() ? ((BuffersPool[0].bIsFree && BuffersPool[0].Timestamp < CurrentFrameTimestamp.timestamp) ? &BuffersPool[0] : ((BuffersPool[1].bIsFree && BuffersPool[1].Timestamp < CurrentFrameTimestamp.timestamp) ?  &BuffersPool[1] : nullptr)) : nullptr);

/*
 * Init free buffer
 */
#define INIT_TB_FREE_BUFFER(Buffer)\
	Buffer->Timestamp = CurrentFrameTimestamp.timestamp;\
	Buffer->bIsUpdated = false;\

/*
 * Retrieve the current frame buffer
 */
#define GET_TB_CURRENT_FRAME_BUFFER() (BuffersPool.Num() ? ((BuffersPool[0].bIsUpdated && CurrentFrameTimestamp.timestamp == BuffersPool[0].Timestamp) ? &BuffersPool[0] : ((BuffersPool[1].bIsUpdated && CurrentFrameTimestamp.timestamp == BuffersPool[1].Timestamp) ?  &BuffersPool[1] : nullptr)) : nullptr)

/*
 * Init current frame buffer
 */
#define INIT_TB_CURRENT_FRAME_BUFFER(Buffer)\
	Buffer->bIsFree = false;\
	Buffer->bIsUpdated = false;\

/*
 * Free the texture pool if they are not used
 */
#define FREE_TB_TEXTURES_POOL()\
	for (auto TexturesIt = TexturesPool.CreateIterator(); TexturesIt; ++TexturesIt)\
	{\
		if (TexturesIt) sl_mat_free((*TexturesIt)->Mat.Mat, (SL_MEM)sl_mat_get_memory_type((*TexturesIt)->Mat.Mat));\
	}\

FSlTextueBatchMatBuffer::FSlTextueBatchMatBuffer()
	:
	Timestamp(ULONG_MAX),
	bIsFree(true),
	bIsUpdated(false)
{
}

FSlTextueBatchMatBuffer::~FSlTextueBatchMatBuffer()
{
}

USlTextureBatch::USlTextureBatch()
	:
	Name("Unnamed"),
	bAsyncRetrieveEnabled(false),
	bIsAutoAddToGrabDelegate(true)
{
}

void USlTextureBatch::BeginDestroy()
{
	FlushRenderingCommands();

	if (GSlCameraProxy)
	{
		GSlCameraProxy->OnGrabThreadEnabled.RemoveDynamic(this, &USlTextureBatch::SetAsyncRetrieveEnabled);
	}

	Super::BeginDestroy();
}

USlTextureBatch* USlTextureBatch::CreateTextureBatch(const FName& Name, ESlMemoryType Type)
{
	USlTextureBatch* TextureBatch = nullptr;
	
	if (Type == ESlMemoryType::MT_CPU)
	{
		TextureBatch = NewObject<USlCPUTextureBatch>();
	}
	else
	{
		TextureBatch = NewObject<USlGPUTextureBatch>();
	}

	TextureBatch->Name = Name;

	FString RHIName = GDynamicRHI->GetName();
	TextureBatch->bCudaInteropEnabled = RHIName.Equals("D3D11") ? true : false; // for the moment, cuda interop is only available with dx11

	GSlCameraProxy->OnGrabThreadEnabled.AddDynamic(TextureBatch, &USlTextureBatch::SetAsyncRetrieveEnabled);

	return TextureBatch;
}

void USlTextureBatch::RetrieveCurrentFrame(const FSlTimestamp& ImageTimestamp)
{
	if (!IsInSlGrabThread() || !bAsyncRetrieveEnabled)
	{
		return;
	}

	SL_SCOPE_LOCK(Lock, RetrieveSection)
		SL_SCOPE_LOCK(SubLock, BuffersSection)
			CurrentFrameTimestamp = ImageTimestamp.timestamp;

			Buffers[0] = GET_TB_FREE_BUFFER();

			if (!Buffers[0])
			{
				return;
			}

			INIT_TB_FREE_BUFFER(Buffers[0]);
		SL_SCOPE_UNLOCK

		for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
		{
			USlTexture* Texture = *TextureIt;
			FIntPoint Resolution(Texture->Width, Texture->Height);

			bool bSuccess;

			if (Texture->IsTypeOf(ESlTextureType::TT_Measure))
			{
				SL_MAT_TYPE MeasureType = sl::unreal::MeasureToMatType((SL_MEASURE)(static_cast<USlMeasureTexture*>(Texture)->MeasureType));
				if (!Buffers[0]->Mats[TextureIt.GetIndex()]) {
					Buffers[0]->Mats[TextureIt.GetIndex()] = sl_mat_create_new(Resolution.X, Resolution.Y, MeasureType, sl::unreal::ToSlType2(Texture->GetMemoryType()));
				}

				bSuccess = GSlCameraProxy->RetrieveMeasure(Buffers[0]->Mats[TextureIt.GetIndex()], static_cast<USlMeasureTexture*>(Texture)->MeasureType, Texture->GetMemoryType(), Resolution);
			}
			else
			{
				SL_MAT_TYPE MatType = sl::unreal::ViewToMatType((SL_VIEW)(static_cast<USlViewTexture*>(Texture)->ViewType));
				if (!Buffers[0]->Mats[TextureIt.GetIndex()]) {
					Buffers[0]->Mats[TextureIt.GetIndex()] = sl_mat_create_new(Resolution.X, Resolution.Y, MatType, sl::unreal::ToSlType2(Texture->GetMemoryType()));
				}

				bSuccess = GSlCameraProxy->RetrieveImage(Buffers[0]->Mats[TextureIt.GetIndex()], static_cast<USlViewTexture*>(Texture)->ViewType, Texture->GetMemoryType(), Resolution, static_cast<USlViewTexture*>(Texture)->ViewFormat);
			}

			if (!bSuccess)
			{
				SL_LOG_E(SlTextureBatch, "Retrieve of texture %s for the batch %s failed.", *Texture->Name.ToString(), *Name.ToString());
			}

		}

		SL_SCOPE_LOCK(SubLock, BuffersSection)
			Buffers[0]->bIsUpdated = true;
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK

	Buffers[0] = nullptr;
}

void USlTextureBatch::AddTexture(USlTexture* Texture)
{
	check(!IsInRenderingThread());

	checkf(Texture, TEXT("Texture can't be null"));

	SL_SCOPE_LOCK(Lock, SwapSection)
		SL_SCOPE_LOCK(SubLock, RetrieveSection)
			TexturesPool.AddUnique(Texture);

			SL_SCOPE_LOCK(SubSubLock, BuffersSection)
				if (BuffersPool.Num())
				{
					BuffersPool[0].Mats.SetNum(TexturesPool.Num());
					BuffersPool[1].Mats.SetNum(TexturesPool.Num());
				}
			SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlTextureBatch::RemoveTexture(USlTexture* Texture)
{
	check(!IsInRenderingThread());

	SL_SCOPE_LOCK(Lock, SwapSection)
		SL_SCOPE_LOCK(SubLock, RetrieveSection)
			TexturesPool.Remove(Texture);

			SL_SCOPE_LOCK(SubSubLock, BuffersSection)
				if (BuffersPool.Num())
				{
					BuffersPool[0].Mats.SetNum(TexturesPool.Num());
					BuffersPool[1].Mats.SetNum(TexturesPool.Num());
				}
			SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlTextureBatch::Clear()
{
	check(!IsInRenderingThread());

	SL_SCOPE_LOCK(Lock, SwapSection)
		SL_SCOPE_LOCK(SubLock, RetrieveSection)
			TexturesPool.Empty();

			SL_SCOPE_LOCK(SubSubLock, BuffersSection)
				if (BuffersPool.Num())
				{
					BuffersPool[0].Mats.Empty();
					BuffersPool[1].Mats.Empty();
				}
			SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlTextureBatch::Reset()
{
	SL_SCOPE_LOCK(Lock, SwapSection)
		SL_SCOPE_LOCK(SubLock, RetrieveSection)

	SL_SCOPE_LOCK(SubSubLock, BuffersSection)
		if (BuffersPool.Num())
		{
			BuffersPool[0].Timestamp = ULONG_MAX;
			BuffersPool[0].bIsFree = true;
			BuffersPool[0].bIsUpdated = false;
			BuffersPool[1].Timestamp = ULONG_MAX;
			BuffersPool[1].bIsFree = true;
			BuffersPool[1].bIsUpdated = false;
		}
	SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
}


void USlTextureBatch::SetAsyncRetrieveEnabled(bool bEnabled)
{
	check(!IsInRenderingThread());

	if (bEnabled)
	{
		if (bAsyncRetrieveEnabled)
		{
			// Already enabled
			return;
		}

		BuffersPool.SetNum(TB_BUFFERS_POOL_SIZE);

		int32 Size = TexturesPool.Num() ? TexturesPool.Num() : 1;
		BuffersPool[0].Mats.SetNum(Size);
		BuffersPool[1].Mats.SetNum(Size);

		FREE_TB_TEXTURES_POOL();
	}
	else
	{
		if (!bAsyncRetrieveEnabled)
		{
			// Already disabled
			return;
		}

		SL_SCOPE_LOCK(Lock, SwapSection)
			SL_SCOPE_LOCK(SubLock, RetrieveSection)
				SL_SCOPE_LOCK(SubSubLock, BuffersSection)
					BuffersPool.Empty();
				SL_SCOPE_UNLOCK
			SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
	}

	bAsyncRetrieveEnabled = bEnabled;
}


bool USlTextureBatch::Tick()
{
	// Update data in any thread but not render thread
	check(!IsInRenderingThread());

	if (!bAsyncRetrieveEnabled)
	{
		SL_SCOPE_LOCK(Lock, RetrieveSection)

			for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
			{
				USlTexture* Texture = *TextureIt;

				bool bSuccess = GSlCameraProxy->RetrieveTexture(Texture);

				if (!bSuccess)
				{
					SL_LOG_E(SlTextureBatch, "Retrieve of texture %s for the batch %s failed.", *Texture->Name.ToString(), *Name.ToString());
				}
			}
		SL_SCOPE_UNLOCK

		return true;
	}
	else
	{
		SL_SCOPE_LOCK(Lock, SwapSection)
			SL_SCOPE_LOCK(SubLock, BuffersSection)
				Buffers[1] = GET_TB_CURRENT_FRAME_BUFFER();

				if (!Buffers[1] || !Buffers[1]->Mats.Num())
				{
					Buffers[1] = nullptr;

					return false;
				}

				INIT_TB_CURRENT_FRAME_BUFFER(Buffers[1]);
			SL_SCOPE_UNLOCK
			for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
			{
				sl_mat_swap(Buffers[1]->Mats[TextureIt.GetIndex()], (*TextureIt)->Mat.Mat);
			}

			SL_SCOPE_LOCK(SubLock, BuffersSection)
				Buffers[1]->bIsFree = true;
			SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK

		Buffers[1] = nullptr;

		return true;
	}
}

/** GPU */
void USlGPUTextureBatch::AddTexture(USlTexture* Texture)
{
	check(!IsInRenderingThread());

	checkf(Texture, TEXT("Texture can't be null"));
	checkf(Texture->Texture, TEXT("Can't add a texture without Texture2D created"));

	// Wait for current tick render command to finish
	FlushRenderingCommands();

	// Synchronize if async retrieve
	SL_SCOPE_LOCK(Lock, RetrieveSection)
		CudaResourcesPool.AddUnique(Texture->CudaResource);
		TexturesPool.AddUnique(Texture);

		SL_SCOPE_LOCK(SubLock, BuffersSection)
			if (BuffersPool.Num())
			{
				BuffersPool[0].Mats.SetNum(TexturesPool.Num());
				BuffersPool[1].Mats.SetNum(TexturesPool.Num());

			}
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlGPUTextureBatch::RemoveTexture(USlTexture* Texture)
{
	check(!IsInRenderingThread());

	// Wait for current tick render command to finish
	FlushRenderingCommands();

	// Synchronize if async retrieve
	SL_SCOPE_LOCK(Lock, RetrieveSection)
		CudaResourcesPool.RemoveSingle(Texture->CudaResource);
		TexturesPool.RemoveSingle(Texture);

		SL_SCOPE_LOCK(SubLock, BuffersSection)
			if (BuffersPool.Num())
			{
				BuffersPool[0].Mats.SetNum(TexturesPool.Num());
				BuffersPool[1].Mats.SetNum(TexturesPool.Num());
			}
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlGPUTextureBatch::Clear()
{
	check(!IsInRenderingThread());

	// Wait for current tick render command to finish
	FlushRenderingCommands();

	// Synchronize if async retrieve
	SL_SCOPE_LOCK(Lock, RetrieveSection)
		CudaResourcesPool.Empty();
		TexturesPool.Empty();

		SL_SCOPE_LOCK(SubLock, BuffersSection)
			if (BuffersPool.Num())
			{
				BuffersPool[0].Mats.Empty();
				BuffersPool[1].Mats.Empty();
			}
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlGPUTextureBatch::SetAsyncRetrieveEnabled(bool bEnabled)
{
	check(!IsInRenderingThread());

	if (bEnabled)
	{
		if (bAsyncRetrieveEnabled)
		{
			// Already enabled
			return;
		}

		// Wait for current tick render command to finish
		FlushRenderingCommands();

		BuffersPool.SetNum(TB_BUFFERS_POOL_SIZE);

		int32 Size = TexturesPool.Num() ? TexturesPool.Num() : 1;
		BuffersPool[0].Mats.SetNum(Size);
		BuffersPool[1].Mats.SetNum(Size);

		// Free textures mats
		FREE_TB_TEXTURES_POOL();
	}
	else
	{
		if (!bAsyncRetrieveEnabled)
		{
			// Already disabled
			return;
		}

		// Wait for current tick render command to finish
		FlushRenderingCommands();

		SL_SCOPE_LOCK(Lock, RetrieveSection)
			SL_SCOPE_LOCK(SubLock, BuffersSection)
				BuffersPool.Empty();
			SL_SCOPE_UNLOCK
		SL_SCOPE_UNLOCK
	}

	bAsyncRetrieveEnabled = bEnabled;
}

bool USlGPUTextureBatch::Tick()
{
	// Update data in any thread but not render thread
	check(!IsInRenderingThread());

	/* render commands are synchronized using FlushRenderCommands()
	   No need to synchronize internally */

	if (!bAsyncRetrieveEnabled)
	{
		ENQUEUE_RENDER_COMMAND(TickGPUBatch)(
			[this](FRHICommandListImmediate& RHICmdList)
			{
				int32 BatchSize = TexturesPool.Num();

				if (bCudaInteropEnabled)
				{
					GSlCameraProxy->PushCudaContext();

					cudaGraphicsMapResources(BatchSize, CudaResourcesPool.GetData(), 0);

					for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
					{
						USlTexture* Texture = *TextureIt;

						bool bSuccess = GSlCameraProxy->RetrieveTexture(Texture);

						if (!bSuccess)
						{
							SL_LOG_E(SlTextureBatch, "Retrieve of texture %s for the batch %s failed.", *Texture->Name.ToString(), *Name.ToString());
						}
						else
						{
							(*TextureIt)->UpdateTexture();
						}		
					}

					cudaGraphicsUnmapResources(BatchSize, CudaResourcesPool.GetData(), 0);

					GSlCameraProxy->PopCudaContext();
				}
				else
				{
					for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
					{
						USlTexture* Texture = *TextureIt;

						bool bSuccess = GSlCameraProxy->RetrieveTexture(Texture);

						if (!bSuccess)
						{
							SL_LOG_E(SlTextureBatch, "Retrieve of texture %s for the batch %s failed.", *Texture->Name.ToString(), *Name.ToString());
						}
						else
						{
							(*TextureIt)->UpdateTexture();
						}		
					}
				}
			}
		);

		return true;
	}
	else
	{
		SL_SCOPE_LOCK(SubLock, BuffersSection)
			Buffers[1] = GET_TB_CURRENT_FRAME_BUFFER();

			if (!Buffers[1] || !Buffers[1]->Mats.Num())
			{
				Buffers[1] = nullptr;

				return false;
			}

			INIT_TB_CURRENT_FRAME_BUFFER(Buffers[1]);
		SL_SCOPE_UNLOCK

		ENQUEUE_RENDER_COMMAND(TickGPUBatchAsyncRetrieve)(
			[this, &Buffer = *Buffers[1]](FRHICommandListImmediate& RHICmdList)
			{
				int32 BatchSize = TexturesPool.Num();

				if (bCudaInteropEnabled)
				{
					GSlCameraProxy->PushCudaContext();

					cudaGraphicsMapResources(BatchSize, CudaResourcesPool.GetData(), 0);

					for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
					{
						(*TextureIt)->UpdateTexture(Buffer.Mats[TextureIt.GetIndex()]);
					}

					cudaGraphicsUnmapResources(BatchSize, CudaResourcesPool.GetData(), 0);

					GSlCameraProxy->PopCudaContext();
				}
				else
				{
					for (auto TextureIt = TexturesPool.CreateIterator(); TextureIt; ++TextureIt)
					{
						(*TextureIt)->UpdateTexture(Buffer.Mats[TextureIt.GetIndex()]);
					}
				}

				SL_SCOPE_LOCK(Lock, BuffersSection)
					Buffer.bIsFree = true;
				SL_SCOPE_UNLOCK
			}
		);

		Buffers[1] = nullptr;

		return true;
	}
}

/** Simple GPU */
void USlSimpleGPUTextureBatch::AddTexture(USlTexture* Texture)
{
	checkf(!(Texture->Texture), TEXT("Can't add a texture with Texture2D created"));
	checkf(Texture->IsMemoryTypeOf(ESlMemoryType::MT_GPU), TEXT("Memory type mismatch betwwen texture %s and batch %s."), *Texture->Name.ToString(), *Name.ToString());

	Super::AddTexture(Texture);
}

/** CPU */
void USlCPUTextureBatch::AddTexture(USlTexture* Texture)
{
	checkf(Texture->IsMemoryTypeOf(ESlMemoryType::MT_CPU), TEXT("Memory type mismatch betwwen texture %s and batch %s."), *Texture->Name.ToString(), *Name.ToString());

	Super::AddTexture(Texture);
}