//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "StereolabsAIDetectionRunnable.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"


DEFINE_LOG_CATEGORY(SlAIThread);

bool FSlObjectDetectionRunnable::Init()
{
	return FSlRunnable::Init();
}

uint32 FSlObjectDetectionRunnable::Run()
{
	if (!GSlCameraProxy->CheckAIModelOptimization((ESlAIModels)sl::unreal::cvtDetection((SL_OBJECT_DETECTION_MODEL)ObjectDetectionModel)))
	{	
		SL_LOG_W(SlAIThread, "Optimizing AI model. The process can take few minutes", (int)ObjectDetectionModel);
		FPlatformProcess::SleepNoStats(1.0f);
	}

	return 0;
}

void FSlObjectDetectionRunnable::Stop()
{
	FSlRunnable::Stop();

	GSlCameraProxy->DisableObjectDetection();

	GSlCameraProxy->RemoveFromGrabDelegate(AIRetrieveDelegateHandle);

	SL_LOG(SlAIThread, "OD Thread stopped");
	SL_LOG(SlAIThread, "FPS OD %f", Fps);
}

void FSlObjectDetectionRunnable::Exit()
{
}

void FSlObjectDetectionRunnable::Start(float Frequency)
{
	static uint64 ThreadCounter = 0;

	Timer.SetFrequency(Frequency);

	FString ThreadName("SlODRunnable");
	ThreadName.AppendInt(ThreadCounter++);

	Thread = FRunnableThread::Create(this, *ThreadName, 0);

	ObjectDetectionModel = GSlCameraProxy->GetObjectDetectionParameters().DetectionModel;

	AIRetrieveDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
		{
			RetrieveObjects(ErrorCode, Timestamp);
		});

	PreviousTS = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	SL_LOG(SlAIThread, "OD Thread started ");
}

void FSlObjectDetectionRunnable::RetrieveObjects(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp) {

	if (bIsRunning && GSlCameraProxy->IsObjectDetectionEnabled() && !GSlCameraProxy->bSVOPlaybackPaused)
	{
		GSlCameraProxy->RetrieveObjects();

		// Compute OD FPS
		std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		auto ObjectDetectionTime = now.count() - PreviousTS.count();
		float CurrentFPS = (1000.0f / ObjectDetectionTime);

		Fps = (Fps + CurrentFPS) / 2;
		PreviousTS = now;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////  Body Tracking ///////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////

bool FSlBodyTrackingRunnable::Init()
{
	return FSlRunnable::Init();
}

uint32 FSlBodyTrackingRunnable::Run()
{
	FPlatformProcess::SleepNoStats(5.0f);

	if (!GSlCameraProxy->CheckAIModelOptimization((ESlAIModels)sl::unreal::cvtDetection((SL_BODY_TRACKING_MODEL)BodyTrackingModel, (SL_BODY_FORMAT)GSlCameraProxy->GetBodyTrackingParameters().BodyFormat)))
	{
		SL_LOG_W(SlAIThread, "Optimizing AI model. The process can take few minutes");
	}

	return 0;
}

void FSlBodyTrackingRunnable::Stop()
{
	FSlRunnable::Stop();

	GSlCameraProxy->DisableBodyTracking();

	GSlCameraProxy->RemoveFromGrabDelegate(AIRetrieveDelegateHandle);

	SL_LOG(SlAIThread, "BT Thread stopped");
	SL_LOG(SlAIThread, "FPS BT %f", Fps);
}

void FSlBodyTrackingRunnable::Exit()
{
}

void FSlBodyTrackingRunnable::Start(float Frequency)
{
	static uint64 ThreadCounter = 0;

	Timer.SetFrequency(Frequency);

	FString ThreadName("SlBTRunnable");
	ThreadName.AppendInt(ThreadCounter++);

	Thread = FRunnableThread::Create(this, *ThreadName, 0);

	BodyTrackingModel = GSlCameraProxy->GetBodyTrackingParameters().DetectionModel;


	AIRetrieveDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
		{
			RetrieveBodies(ErrorCode, Timestamp);
		});

	PreviousTS = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	SL_LOG(SlAIThread, "BT Thread started ");
}

void FSlBodyTrackingRunnable::RetrieveBodies(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp) {

	if (bIsRunning && GSlCameraProxy->IsBodyTrackingEnabled() && !GSlCameraProxy->bSVOPlaybackPaused)
	{
		GSlCameraProxy->RetrieveBodies();

		// Compute OD FPS
		std::chrono::milliseconds now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
		auto ObjectDetectionTime = now.count() - PreviousTS.count();
		float CurrentFPS = (1000.0f / ObjectDetectionTime);

		Fps = (Fps + CurrentFPS) / 2;
		PreviousTS = now;
	}
}