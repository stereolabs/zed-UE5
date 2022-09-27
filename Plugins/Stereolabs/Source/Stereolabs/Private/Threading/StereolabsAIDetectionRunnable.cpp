//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "StereolabsAIDetectionRunnable.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"


DEFINE_LOG_CATEGORY(SlAIThread);

bool FSlAIDetectionRunnable::Init()
{
	return FSlRunnable::Init();
}

uint32 FSlAIDetectionRunnable::Run()
{
	FPlatformProcess::SleepNoStats(0.0f);

	/*while (bIsRunning)
	{
		if (GSlCameraProxy->IsObjectDetectionEnabled()) 
		{
			GSlCameraProxy->RetrieveObjects();

		}
		FPlatformProcess::SleepNoStats(0.001f);
	}*/

	return 0;
}

void FSlAIDetectionRunnable::Stop()
{
	FSlRunnable::Stop();

	GSlCameraProxy->DisableObjectDetection();

	GSlCameraProxy->RemoveFromGrabDelegate(AIRetrieveDelegateHandle);

	SL_LOG(SlGrabThread, "AI Thread stopped");
}

void FSlAIDetectionRunnable::Exit()
{
}

void FSlAIDetectionRunnable::Start(float Frequency)
{
	static uint64 ThreadCounter = 0;

	Timer.SetFrequency(Frequency);

	FString ThreadName("SlAIRunnable");
	ThreadName.AppendInt(ThreadCounter++);

	Thread = FRunnableThread::Create(this, *ThreadName, 0, TPri_BelowNormal);

	AIRetrieveDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
		{
			RetrieveObjects(ErrorCode, Timestamp);
		});

	SL_LOG(SlGrabThread, "AI Thread started");
}

void FSlAIDetectionRunnable::RetrieveObjects(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp) {

	if (bIsRunning && GSlCameraProxy->IsObjectDetectionEnabled())
	{
		GSlCameraProxy->RetrieveObjects();
	}
}