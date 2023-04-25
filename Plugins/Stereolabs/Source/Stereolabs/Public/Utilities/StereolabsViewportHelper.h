//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "StereolabsViewportHelper.generated.h"

/*
 * Helper class to cache viewport data
 *
 * Example :
 *
 * UGameViewportClient* GameViewport = GetLocalPlayer()->ViewportClient;
 * check(GameViewport);
 *
 *	ViewportHelper.Update(GameViewport->Viewport->GetSizeXY());
 *
 */
USTRUCT(BlueprintType)
struct STEREOLABS_API FSlViewportHelper
{
	GENERATED_BODY()

public:
	FSlViewportHelper();

	/** Add to viewport resize event to automatically update */
	void AddToViewportResizeEvent(class UGameViewportClient* NewGameViewportClient);

	/** Update cache */
	void Update(const FIntPoint& ViewportSize = FIntPoint());

	/** Return true if in viewport */
	FORCEINLINE bool IsInViewport(int32 X, int32 Y)
	{
		return (X >= RangeX.X && Y >= RangeY.X && X <= RangeX.Y && Y <= RangeY.Y);
	}

	FIntPoint ConvertScreenSpaceToImageSpace(const FIntPoint ScreenPosition);

public:
	/** X/Y offsets if ratio is not 16/9 */
	FVector2D Offset;

	/** Range to scale width */
	FVector2D RangeX;

	/** Range to scale height */
	FVector2D RangeY;

	/** Current size */
	FIntPoint Size;

	/** Current screen ratio */
	float ScreenRatio;

private:
	/** Viewport resize event handler */
	FDelegateHandle ViewportResizedEventHandle;

	/** Current game viewport rendering the game */
	UGameViewportClient* GameViewportClient;
};
