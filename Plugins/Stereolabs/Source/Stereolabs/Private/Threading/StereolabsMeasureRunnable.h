//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Threading/StereolabsRunnable.h"


DECLARE_LOG_CATEGORY_EXTERN(SlMeasureThread, Log, All);

struct FSlMeasureRunnableMatBuffer
{
	FSlMeasureRunnableMatBuffer();

	/** True if the buffer is free to use */
	bool bIsFree;

	/** True if the buffer is updated */
	bool bIsUpdated;

	/** True if depth enabled for this buffer */
	bool bDepthEnabled;

	/** True if normals enabled for this buffer */
	bool bNormalsEnabled;

	/** Current mats used by the buffer */
	TArray<void*, TFixedAllocator<2>> Mats;
};

/*
 * Retrieve thread which should be at least twice as fast as grab thread
 */
class FSlMeasureRunnable : public FSlRunnable
{
public:
	FSlMeasureRunnable();

public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;
	virtual void Start(float Frequency) override;

	/*
	 * Toggle depth and normals
	 * @param bEnableDepth   True to enable depth retrieve
	 * @param bEnableNormals True to enable normals retrieve
	 */
	void SetDepthAndNormals(bool bEnableDepth, bool bEnableNormals);

	/*
	 * @param ScreenPosition The screen position
	 * @param ViewportSizeX	 The viewport size width
	 * @param ViewportSizeY  The viewport size height
	 * @return The depth at the screen position
	 */
	float GetDepth(const FIntPoint& ScreenPosition, const FVector2D& InputRangeX, const FVector2D& InputRangeY);

	/*
	 * @param ScreenPositions The screen positions
	 * @param ViewportSizeX	 The viewport size width
	 * @param ViewportSizeY  The viewport size height
	 * @return The depths at the screen positions
	 */
	TArray<float> GetDepths(const TArray<FIntPoint>& ScreenPositions, const FVector2D& InputRangeX, const FVector2D& InputRangeY);

	/*
	 * @param ScreenPosition The screen position
	 * @param ViewportSizeX	 The viewport size width
	 * @param ViewportSizeY  The viewport size height
	 * @return The normal at the screen position
	 */
	FVector GetNormal(const FIntPoint& ScreenPosition, const FVector2D& InputRangeX, const FVector2D& InputRangeY);

	/*
	 * @param ScreenPositions The screen positions
	 * @param ViewportSizeX	 The viewport size width
	 * @param ViewportSizeY  The viewport size height
	 * @return The normals at the screen positions
	 */
	TArray<FVector> GetNormals(const TArray<FIntPoint>& ScreenPositions, const FVector2D& InputRangeX, const FVector2D& InputRangeY);

	/*
	 * @param ScreenPosition The screen position
	 * @param ViewportSizeX	 The viewport size width
	 * @param ViewportSizeY  The viewport size height
	 * @return The depth and normal at the screen position
	 */
	FVector4 GetDepthAndNormal(const FIntPoint& ScreenPosition, const FVector2D& InputRangeX, const FVector2D& InputRangeY);

	/*
	 * @param ScreenPositions The screen positions
	 * @param ViewportSizeX	 The viewport size width
	 * @param ViewportSizeY  The viewport size height
	 * @return The depths and normals at the screen positions
	 */
	TArray<FVector4> GetDepthsAndNormals(const TArray<FIntPoint>& ScreenPositions, const FVector2D& InputRangeX, const FVector2D& InputRangeY);

private:
	/*
	 * Grab delegate callback
	 * @param ErrorCode Grab error code
	 */
	void GrabCallback(ESlErrorCode ErrorCode);

private:
	/** True if depth retrieve enabled */
	FThreadSafeBool bDepthEnabled;

	/** True if normals retrieve enabled */
	FThreadSafeBool bNormalsEnabled;

	/** Pool of mats */
	TArray<FSlMeasureRunnableMatBuffer, TFixedAllocator<3>> BuffersPool;

	/** Current used buffer */
	FSlMeasureRunnableMatBuffer* Buffer;

	/** Update Section */
	FCriticalSection UpdateSection;

	/** Depth Section */
	FCriticalSection GetSection;

	/** Handle to remove callback from delegate */
	FDelegateHandle GrabDelegateHandle;

	/** Range [0, mats width] */
	FVector2D OutputRangeX;

	/** Range [0, mats height] */
	FVector2D OutputRangeY;
};
