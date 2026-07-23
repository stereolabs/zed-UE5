//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Engine/LocalPlayer.h"

#include "ZEDLocalPlayer.generated.h"

UCLASS()
class ZED_API UZEDLocalPlayer : public ULocalPlayer
{
	GENERATED_UCLASS_BODY()

public:
	// Injects the ZED left-camera optical center as an off-center projection offset so the virtual
	// camera's principal point matches the real camera. Reached each frame through the stock
	// ULocalPlayer::CalcSceneView -> CalcSceneViewInitOptions -> virtual GetProjectionData path.
	virtual bool GetProjectionData(FViewport* Viewport,
		FSceneViewProjectionData& ProjectionData,
		int32 StereoViewIndex = INDEX_NONE) const override;

	// Projection data built from the raw ZED pose and intrinsics, used by ZEDFunctionLibrary's
	// ProjectWorldToScreen / DeprojectScreenToWorld helpers.
	bool GetZEDProjectionData(FViewport* Viewport, FSceneViewProjectionData& ProjectionData) const;
};