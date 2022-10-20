//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Threading/StereolabsRunnable.h"
#include <chrono>

DECLARE_LOG_CATEGORY_EXTERN(SlGrabThread, Log, All);

/*
 * Grab thread
 */
class FSlGrabRunnable : public FSlRunnable
{
public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;
	virtual void Start(float Frequency) override;

private :

	std::chrono::milliseconds PreviousTS;
	float Fps;
};