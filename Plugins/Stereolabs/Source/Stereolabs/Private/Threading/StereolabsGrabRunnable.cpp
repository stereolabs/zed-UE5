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


		// Compute Grab fps.
		std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		auto GrabTime = now.count() - PreviousTS.count();
		float CurrentFPS = (1000.0f / GrabTime);
		Fps = (Fps + CurrentFPS) / 2;
		PreviousTS = now;
		FPlatformProcess::SleepNoStats(0.001f);
	}

	SL_LOG(SlGrabThread, "FPS image %f", Fps);
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

	PreviousTS = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	Fps = 0;

	SL_LOG(SlGrabThread, "Thread started");
}