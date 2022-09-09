//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Engine/LocalPlayer.h"

#include "ZEDLocalPlayer.generated.h"

UCLASS()
class ZED_API UZEDLocalPlayer : public ULocalPlayer
{
	GENERATED_UCLASS_BODY()

private:
	FSceneViewStateReference ViewState;
	FSceneViewStateReference StereoViewState;

public:
	virtual bool GetProjectionData(FViewport* Viewport,
		FSceneViewProjectionData& ProjectionData,
		int32 StereoViewIndex = INDEX_NONE) const override;

	bool GetZEDProjectionData(FViewport* Viewport, FSceneViewProjectionData& ProjectionData) const;

	virtual FSceneView* CalcSceneView(class FSceneViewFamily* ViewFamily,
		FVector& OutViewLocation,
		FRotator& OutViewRotation,
		FViewport* Viewport,
		class FViewElementDrawer* ViewDrawer = NULL,
		int32 StereoViewIndex = INDEX_NONE) override;
};