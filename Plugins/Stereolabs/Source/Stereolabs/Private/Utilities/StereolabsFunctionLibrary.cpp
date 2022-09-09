//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"
#include "StereolabsPrivatePCH.h"
#include "IXRTrackingSystem.h"

#include <sl_mr_core/latency.hpp>
#include <sl_mr_core/Rendering.hpp>

#include <iostream>
#include <fstream>
#include <string>

DEFINE_LOG_CATEGORY(SLFunctionLibrary);

float USlFunctionLibrary::ConvertDepthToDistance(const FSlViewportHelper& ViewportHelper, const FVector2D& ScreenPosition, float Depth)
{
	static const FVector2D OutputRangeX(0, GSlCameraProxy->RetrieveMatSize.X);
	static const FVector2D OutputRangeY(0, GSlCameraProxy->RetrieveMatSize.Y);

	uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(ViewportHelper.RangeX, OutputRangeX, ScreenPosition.X);
	uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(ViewportHelper.RangeY, OutputRangeY, ScreenPosition.Y);

	float InvHFocal = 1.0f / GSlCameraProxy->RetrieveLeftCameraParameters.HFocal;

	float DeprojX = ((float)X - GSlCameraProxy->RetrieveLeftCameraParameters.OpticalCenterX) * Depth * InvHFocal;
	float DeprojY = ((float)Y - GSlCameraProxy->RetrieveLeftCameraParameters.OpticalCenterY) * Depth * InvHFocal;

	return FMath::Sqrt(DeprojX*DeprojX + DeprojY*DeprojY + Depth*Depth);
}

float USlFunctionLibrary::ConvertCustomDepthToDistance(const FSlCameraParameters& CameraParameters, const FVector2D& Position, float Depth)
{
	float InvHFocal = 1.0f / CameraParameters.HFocal;

	float DeprojX = ((float)Position.X - CameraParameters.OpticalCenterX) * Depth * InvHFocal;
	float DeprojY = ((float)Position.Y - CameraParameters.OpticalCenterY) * Depth * InvHFocal;

	return FMath::Sqrt(DeprojX*DeprojX + DeprojY*DeprojY + Depth*Depth);
}

FVector2D USlFunctionLibrary::GetRenderPlaneSize(const FIntPoint& ImageResolution, float VerticalFOV, float PlaneDistance)
{
	return sl::unreal::ToUnrealType(sl::mr::computeRenderPlaneSize(sl::unreal::ToSlMrType2(ImageResolution), VerticalFOV, PlaneDistance));
}

FVector2D USlFunctionLibrary::GetRenderPlaneSizeWithGamma(UObject* WorldContextObject, const FIntPoint& ImageResolution, float PerceptionDistance, float ZedFocal, float PlaneDistance)
{
	float EyeToZedDistance = 0.0f;

	if (GEngine->StereoRenderingDevice.IsValid() && GEngine->StereoRenderingDevice->IsStereoEnabled() && GEngine->XRSystem.IsValid() && GEngine->XRSystem->GetHMDDevice())
	{
		EyeToZedDistance = sl::mr::getEyeToZEDDistance(sl::unreal::ToSlType(GEngine->XRSystem->GetSystemName()));
	}
#if WITH_EDITOR
	else
	{
		SL_LOG_E(SLFunctionLibrary, "Eye to Zed distance not available for this HMD");

		return FVector2D();
	}
#endif

	float HMDFocal = 0.0f;

	if (GEngine->StereoRenderingDevice.IsValid() && GEngine->StereoRenderingDevice->IsStereoEnabled() && GEngine->XRSystem.IsValid() && GEngine->XRSystem->GetHMDDevice())
	{
		sl::mr::Resolution HMDScreenResolution;

		FName Type = GEngine->XRSystem->GetSystemName();
		if (Type == TEXT("SteamVR"))
		{
			HMDScreenResolution.width = 3024;
			HMDScreenResolution.height = 1680;
		}
		else if (Type == TEXT("OculusHMD"))
		{
			HMDScreenResolution.width = 2720;
			HMDScreenResolution.height = 1600;
		}
		else
		{
			SL_LOG_E(SLFunctionLibrary, "HMD not supported");
		}

		FMatrix ProjectionMatrix = GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(eSSE_LEFT_EYE);

		HMDFocal = sl::mr::computeHMDFocal(HMDScreenResolution, ProjectionMatrix.M[0][0], ProjectionMatrix.M[1][1]);
	}
#if WITH_EDITOR
	else
	{
		SL_LOG_E(SLFunctionLibrary, "Focal not available for this HMD");

		return FVector2D();
	}
#endif

	return sl::unreal::ToUnrealType(sl::mr::computeRenderPlaneSizeWithGamma(sl::unreal::ToSlMrType2(ImageResolution), PerceptionDistance, EyeToZedDistance, PlaneDistance, HMDFocal, ZedFocal));
}

FVector4 USlFunctionLibrary::GetOpticalCentersOffsets(const FIntPoint& ImageResolution, float Distance)
{
	if (GSlCameraProxy->IsCameraOpened()) {
		return sl::unreal::ToUnrealType(sl::mr::computeOpticalCentersOffsets(sl::unreal::ToSlMrType(GSlCameraProxy->SlCameraInformation->camera_configuration.calibration_parameters.left_cam), sl::unreal::ToSlMrType(GSlCameraProxy->SlCameraInformation->camera_configuration.calibration_parameters.right_cam), sl::unreal::ToSlMrType2(ImageResolution), Distance));
	}
	else
		return FVector4::Zero();
}																																																	               

FVector2D USlFunctionLibrary::GetOffCenterProjectionOffset(ESlEye Eye)
{
	FVector2D OffCenterProjectionOffset;
	FSlCameraInformation CameraInformation = GSlCameraProxy->CameraInformation;

	float Width = (float)CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution.X;
	float Height = (float)CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution.Y;
	float OpticalCenterX = (Eye == ESlEye::E_Left ? CameraInformation.CalibrationParameters.LeftCameraParameters.OpticalCenterX : CameraInformation.CalibrationParameters.RightCameraParameters.OpticalCenterX);
	float OpticalCenterY = (Eye == ESlEye::E_Left ? CameraInformation.CalibrationParameters.LeftCameraParameters.OpticalCenterY : CameraInformation.CalibrationParameters.RightCameraParameters.OpticalCenterY);

	OffCenterProjectionOffset.X = 2.0f * ((Width - 1.0f * OpticalCenterX) / Width) - 1.0f;
	OffCenterProjectionOffset.Y = -2.0f * ((Height - 1.0f * OpticalCenterY) / Height) + 1.0f;

	return OffCenterProjectionOffset;
}

void USlFunctionLibrary::GetSceneCaptureProjectionMatrix(FMatrix& ProjectionMatrix, ESlEye Eye)
{
	FSlCameraInformation CameraInformation = GSlCameraProxy->CameraInformation;

	float XAxisMultiplier = 1.0f;
	float YAxisMultiplier = (float)CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution.X / (float)CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution.Y;
	float FOV = CameraInformation.CalibrationParameters.LeftCameraParameters.HFOV * (float)PI / 360.0f;

	if ((int32)ERHIZBuffer::IsInverted)
	{
		ProjectionMatrix = FReversedZPerspectiveMatrix(
			FOV,
			FOV,
			XAxisMultiplier,
			YAxisMultiplier,
			GNearClippingPlane,
			GNearClippingPlane
			);
	}
	else
	{
		ProjectionMatrix = FPerspectiveMatrix(
			FOV,
			FOV,
			XAxisMultiplier,
			YAxisMultiplier,
			GNearClippingPlane,
			GNearClippingPlane
			);
	}

	FVector2D OffCenterProjectionOffset = GetOffCenterProjectionOffset(Eye);

	const float Left = -1.0f + OffCenterProjectionOffset.X;
	const float Right = Left + 2.0f;
	const float Bottom = -1.0f + OffCenterProjectionOffset.Y;
	const float Top = Bottom + 2.0f;
	ProjectionMatrix.M[2][0] = (Left + Right) / (Left - Right);
	ProjectionMatrix.M[2][1] = (Bottom + Top) / (Bottom - Top);
}

FString USlFunctionLibrary::ErrorCodeToString(ESlErrorCode ErrorCode)
{
	FString ErrorCodeString;

	if (ErrorCode > ESlErrorCode::EC_None)
	{
		ErrorCodeString = FString("Error code not in range");
	}
	else
	{
		if (ErrorCode == ESlErrorCode::EC_None)
		{
			ErrorCodeString = "No Error";
		}
		else
		{
			FString Tmp = FString(sl::toString(sl::unreal::ToSlType(ErrorCode)).get());
			ErrorCodeString = Tmp.Left(1) + Tmp.ToLower().RightChop(1);
		}
	}

	return ErrorCodeString;
}

UTexture2D* Texture32BitFromImage_Internal(const int32 SrcWidth, const int32 SrcHeight, const std::vector<std::vector<float>> &SrcData)
{
	UTexture2D *texture = UTexture2D::CreateTransient(SrcWidth, SrcHeight, PF_R32_FLOAT);
	texture->CompressionSettings = TextureCompressionSettings::TC_HDR;
	texture->Filter = TextureFilter::TF_Bilinear;
	texture->SRGB = 0;
	texture->AddToRoot();
	texture->UpdateResource();
	FTexture2DMipMap &mip = texture->PlatformData->Mips[0];
	float *data = (float*)(mip.BulkData.Lock(LOCK_READ_WRITE));
	for (int32 i = 0; i < SrcHeight; i++)
	{
		for (int32 j = 0; j < SrcWidth; j++)
		{
			data[i*SrcWidth + j] = SrcData.at(i).at(j);
		}
	}
	mip.BulkData.Unlock();
	texture->UpdateResource();
	return texture;
}

UTexture2D* Texture32BitFromImage_Internal(const sl::Mat* mat)
{
	UTexture2D *texture = UTexture2D::CreateTransient(mat->getWidth(), mat->getHeight(), PF_R32_FLOAT);
	texture->CompressionSettings = TextureCompressionSettings::TC_HDR;
	texture->Filter = TextureFilter::TF_Bilinear;
	texture->SRGB = 0;
	texture->AddToRoot();
	texture->UpdateResource();
	FTexture2DMipMap &mip = texture->GetPlatformData()->Mips[0];
	float *data = (float*)(mip.BulkData.Lock(LOCK_READ_WRITE));
	for (int32 i = 0; i < mat->getHeight(); i++)
	{
		for (int32 j = 0; j < mat->getWidth(); j++)
		{
			 mat->getValue<float>(j, i, (data + i*mat->getWidth() + j));
		}
	}
	mip.BulkData.Unlock();
	texture->UpdateResource();
	return texture;
}

std::vector<std::vector<float>> readRows(std::istream& f) {
	std::string line;
	std::vector<std::vector<float>> rows;
	while (std::getline(f, line)) {
		std::vector<float> row;
		std::string entry;
		std::istringstream linestrm(line);
		while (std::getline(linestrm, entry, '\t')) {
			row.push_back(std::stof(entry));
		}
		rows.push_back(row);
	}
	return rows;
}

UTexture2D* USlFunctionLibrary::GenerateTextureFromTxtFile(const FString filepath)
{
	std::vector<std::vector<float>> Mx;
	std::string filepathSTD = (TCHAR_TO_UTF8(*filepath));


	std::ifstream myfile(filepathSTD);
	if (myfile.is_open())
	{
		Mx = readRows(myfile);
		myfile.close();
	}

	UTexture2D* texture = Texture32BitFromImage_Internal(Mx.at(0).size(), Mx.size(), Mx);
	return texture;
}

UTexture2D* USlFunctionLibrary::GenerateTextureFromSlMat(const sl::Mat* mat)
{
	UTexture2D* texture = Texture32BitFromImage_Internal(mat);
	return texture;
}

FVector2D USlFunctionLibrary::GetHmdFocale()
{
	FMatrix ProjectionMatrix = GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(eSSE_LEFT_EYE);
	FIntPoint IdealRenderSize = GEngine->XRSystem->GetHMDDevice()->GetIdealRenderTargetSize();
	FVector2D focales;
	focales.X = (IdealRenderSize.X / 4.0f * ProjectionMatrix.M[0][0]);
	focales.Y = (IdealRenderSize.Y / 2.0f * ProjectionMatrix.M[1][1]);
	SL_LOG_W(SLFunctionLibrary, "HMD focal compute on viewport %f x %f", (float)IdealRenderSize.X, (float)IdealRenderSize.Y);
	return focales;
}
