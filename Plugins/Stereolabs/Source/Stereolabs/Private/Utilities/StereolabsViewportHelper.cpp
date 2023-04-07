//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Utilities/StereolabsViewportHelper.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

FSlViewportHelper::FSlViewportHelper()
	:
	ScreenRatio(0.0f),
	GameViewportClient(nullptr)
{
}

void FSlViewportHelper::AddToViewportResizeEvent(UGameViewportClient* NewGameViewportClient)
{
	// Already init
	if (GameViewportClient)
	{
		return;
	}

	GameViewportClient = NewGameViewportClient;

	ViewportResizedEventHandle = FViewport::ViewportResizedEvent.AddLambda([this](FViewport* Viewport, uint32)
	{
		if (Viewport->GetClient() == GameViewportClient)
		{
			Update(Viewport->GetSizeXY());
		}
	});
}

void FSlViewportHelper::Update(const FIntPoint& ViewportSize)
{
	FIntPoint Resolution = GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution;

	// No update needed
	if (Size == ViewportSize)
	{
		return;
	}

	//Update
	Size = ViewportSize;

	ScreenRatio = (float)Size.X / (float)Size.Y;
	float ImageRatio = (float)Resolution.X / (float)Resolution.Y;

	// Not 16/9
	if (ScreenRatio < ImageRatio)
	{
		Offset.X = 0.0f;
		Offset.Y = (Size.Y - (Size.X / ImageRatio)) / 2;
	}
	else if (ScreenRatio > ImageRatio)
	{
		Offset.X = (Size.X - (Size.Y * ImageRatio)) / 2;
		Offset.Y = 0.0f;
	}
	else
	{
		Offset.X = 0.0f;
		Offset.Y = 0.0f;
	}


	RangeX.X = Offset.X;
	RangeX.Y = Size.X - Offset.X;

	RangeY.X = Offset.Y;
	RangeY.Y = Size.Y - Offset.Y;
}

FIntPoint FSlViewportHelper::ConvertScreenSpaceToImageSpace(const FIntPoint ScreenPosition) {
	FIntPoint imagePos = ScreenPosition;

	float ImageRatio = (float)GSlCameraProxy->CameraInformation.Resolution.X / (float)GSlCameraProxy->CameraInformation.Resolution.Y;
	FIntPoint ImageSize;

	ScreenRatio = (float)Size.X / (float)Size.Y;
	if (ScreenRatio < ImageRatio)
	{
		ImageSize.X = Size.X;
		ImageSize.Y = Size.X * 9 / 16.;

		Offset.X = abs(ImageSize.X - Size.X) / 2.;
		Offset.Y = abs(ImageSize.Y - Size.Y) / 2.;
	}
	else if (ScreenRatio > ImageRatio)
	{
		ImageSize.X = Size.Y * 16/9.;
		ImageSize.Y = Size.Y;

		Offset.X = abs(ImageSize.X - Size.X) / 2.;
		Offset.Y = abs(ImageSize.Y - Size.Y) / 2.;
	}
	else
	{
		ImageSize.X = Size.X;
		ImageSize.Y = Size.Y;

		Offset.X = abs(Size.X - ImageSize.X) / 2.;
		Offset.Y = abs(Size.Y - ImageSize.Y) / 2.;
	}

	imagePos.X = (ScreenPosition.X * (float)GSlCameraProxy->CameraInformation.Resolution.X / ImageSize.X) - Offset.X;
	imagePos.Y = (ScreenPosition.Y * (float)GSlCameraProxy->CameraInformation.Resolution.Y / ImageSize.Y) - Offset.Y;
	return imagePos;
}