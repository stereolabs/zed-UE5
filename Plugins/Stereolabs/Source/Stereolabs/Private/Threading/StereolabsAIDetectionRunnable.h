//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Threading/StereolabsRunnable.h"
#include <chrono>

DECLARE_LOG_CATEGORY_EXTERN(SlAIThread, Log, All);


class FSlObjectDetectionRunnable : public FSlRunnable
{
public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;
	virtual void Start(float Frequency) override;

	void RetrieveObjects(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp);

	FDelegateHandle AIRetrieveDelegateHandle;

private :
	float Fps;
	std::chrono::milliseconds PreviousTS;
	ESlObjectDetectionModel ObjectDetectionModel;
};


class FSlBodyTrackingRunnable : public FSlRunnable
{
public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual void Exit() override;
	virtual void Start(float Frequency) override;

	void RetrieveBodies(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp);

	FDelegateHandle AIRetrieveDelegateHandle;

private:
	float Fps;
	std::chrono::milliseconds PreviousTS;

	ESlBodyTrackingModel BodyTrackingModel;
};