//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Private/Threading/StereolabsGrabRunnable.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

DEFINE_LOG_CATEGORY(SlGrabThread);

bool FSlGrabRunnable::Init()
{
	return FSlRunnable::Init();
}

uint32 FSlGrabRunnable::Run()
{
	FPlatformProcess::SleepNoStats(0.0f);

	while (bIsRunning)
	{
		GSlCameraProxy->Grab();

		FPlatformProcess::SleepNoStats(0.001f);
	}

	return 0;
}

void FSlGrabRunnable::Stop()
{
	FSlRunnable::Stop();

	SL_LOG(SlGrabThread, "Thread stopped");
}

void FSlGrabRunnable::Exit()
{
	GSlIsGrabThreadIdInitialized = false;
}

void FSlGrabRunnable::Start(float Frequency)
{
	static uint64 ThreadCounter = 0;

	Timer.SetFrequency(Frequency);

	FString ThreadName("SlGrabRunnable");
	ThreadName.AppendInt(ThreadCounter++);

	Thread = FRunnableThread::Create(this, *ThreadName, 0, TPri_BelowNormal);
	GSlGrabThreadId = Thread->GetThreadID();
	GSlIsGrabThreadIdInitialized = true;

	SL_LOG(SlGrabThread, "Thread started");
}