//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Threading/StereolabsRunnable.h"

#include "Math/Float16Color.h"

/*
 * Build a cubemap asynchronously
 */ 
class FSpatialMappingCubemapRunnable : public FSlRunnable
{
public:
	FSpatialMappingCubemapRunnable(struct FSpatialMappingCubemapProxy* CubemapProxy);

public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Start(float Frequency) override;
	virtual void Stop() override;
	virtual void Exit() override;

public:
	/*
	 * Get the pixels of the texture target
	 */
	void GetPixels();

	/*
	 * Convert the texture target to cubemap
	 */
	void ConverToTextureCube();

private:
	/** True if the pixels are initialized */
	FThreadSafeBool bPixelsInitialized;

	/** The buffer of pixels in LDR */
	TArray<TArray<FColor>> OutputBuffersLDR;

	/** The buffer of pixels in HDR */
	TArray<TArray<FFloat16Color>> OutputBuffersHDR;

	/** Proxy */
	struct FSpatialMappingCubemapProxy* CubemapProxy;
};

