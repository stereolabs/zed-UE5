//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Private/Threading/StereolabsMeasureRunnable.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

DECLARE_CYCLE_STAT_EXTERN(TEXT("AsyncMeasureRetrieve"), STAT_AsyncMeasureRetrieve, STATGROUP_ZED, STEREOLABS_API);
DECLARE_CYCLE_STAT_EXTERN(TEXT("AsyncMeasureGPUtoCPU"), STAT_AsyncMeasureGPUtoCPU, STATGROUP_ZED, STEREOLABS_API);

DEFINE_STAT(STAT_AsyncMeasureRetrieve)
DEFINE_STAT(STAT_AsyncMeasureGPUtoCPU)

DEFINE_LOG_CATEGORY(SlMeasureThread);

#define GET_MR_FREE_BUFFER()	 (BuffersPool[0].bIsFree ? &BuffersPool[0] : (BuffersPool[1].bIsFree ? &BuffersPool[1] : &BuffersPool[2]))
#define GET_MR_UPDATED_BUFFER()  (BuffersPool[0].bIsUpdated ? &BuffersPool[0] : (BuffersPool[1].bIsUpdated ? &BuffersPool[1] : (BuffersPool[2].bIsUpdated ? &BuffersPool[2] : nullptr)))

FSlMeasureRunnableMatBuffer::FSlMeasureRunnableMatBuffer()
	:
	bIsFree(true),
	bIsUpdated(false),
	bDepthEnabled(false),
	bNormalsEnabled(false)
{
}

FSlMeasureRunnable::FSlMeasureRunnable()
	:
	bDepthEnabled(false),
	bNormalsEnabled(false),
	Buffer(nullptr)
{
	BuffersPool.SetNum(3);
	BuffersPool[0].Mats.SetNum(2);
	BuffersPool[1].Mats.SetNum(2);
	BuffersPool[2].Mats.SetNum(2);
}

bool FSlMeasureRunnable::Init()
{
	OutputRangeX = FVector2D(0.0f, GSlCameraProxy->RetrieveMatSize.X);
	OutputRangeY = FVector2D(0.0f, GSlCameraProxy->RetrieveMatSize.Y);

	GrabDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
	{
		GrabCallback(ErrorCode);
	});

	BuffersPool[1].Mats[0] = sl_mat_create_new(GSlCameraProxy->RetrieveMatSize.X, GSlCameraProxy->RetrieveMatSize.Y, SL_MAT_TYPE_F32_C1, SL_MEM_CPU);
	float Nan = NAN;
	sl_mat_set_to_float(BuffersPool[1].Mats[0], Nan, SL_MEM_CPU);

	BuffersPool[1].Mats[1] = sl_mat_create_new(GSlCameraProxy->RetrieveMatSize.X, GSlCameraProxy->RetrieveMatSize.Y, SL_MAT_TYPE_F32_C4, SL_MEM_CPU);
	SL_Vector4 value{ 0,0,0,0 };
	sl_mat_set_to_float4(BuffersPool[1].Mats[0], value, SL_MEM_CPU);


	Buffer = &BuffersPool[1];
	Buffer->bIsFree = false;

	return FSlRunnable::Init();
}

uint32 FSlMeasureRunnable::Run()
{
	FPlatformProcess::SleepNoStats(0.0f);

	while (bIsRunning)
	{
		Timer.Start();

		bool bUpdate = false;

		FSlMeasureRunnableMatBuffer* UpdateBuffer;
		SL_SCOPE_LOCK(Lock, UpdateSection)
			// Search for new available buffer
			UpdateBuffer = GET_MR_UPDATED_BUFFER();

			if (UpdateBuffer)
			{
				UpdateBuffer->bIsFree = false;
				UpdateBuffer->bIsUpdated = false;
			}
		SL_SCOPE_UNLOCK

		if (UpdateBuffer)
		{
			SCOPE_CYCLE_COUNTER(STAT_AsyncMeasureGPUtoCPU);

			if (UpdateBuffer->bDepthEnabled)
			{
				SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_mat_update_cpu_from_gpu(UpdateBuffer->Mats[0]);
				bUpdate = ErrorCode == SL_ERROR_CODE_SUCCESS;
	
				if (ErrorCode != SL_ERROR_CODE_SUCCESS)
				{
					SL_LOG_E(SlMeasureThread, "Error while updating depth texture: \"%i\"", ErrorCode);
				}
			}

			if (UpdateBuffer->bNormalsEnabled)
			{
				SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_mat_update_cpu_from_gpu(UpdateBuffer->Mats[1]);
				bUpdate = ErrorCode == SL_ERROR_CODE_SUCCESS;

				if (ErrorCode != SL_ERROR_CODE_SUCCESS)
				{
					SL_LOG_E(SlMeasureThread, "Error while updating normals texture: \"%i\"", ErrorCode);
				}
			}

			if(bUpdate)
			{
				SL_SCOPE_LOCK(Lock, UpdateSection)
					SL_SCOPE_LOCK(SubLock, GetSection)
						// Reset old
						if (Buffer)
						{
							Buffer->bIsFree = true;
						}

						// Set new
						Buffer = UpdateBuffer;
					SL_SCOPE_UNLOCK
				SL_SCOPE_UNLOCK
			}
		}

		Timer.Stop();

		if (Timer.CanSleep())
		{
			FPlatformProcess::Sleep(Timer.GetSleepingTimeSeconds());
		}
	}

	return 0;
}

void FSlMeasureRunnable::Stop()
{
	FSlRunnable::Stop();

	SL_LOG(SlMeasureThread, "Thread stopped");
}

void FSlMeasureRunnable::Exit()
{
	if (GSlCameraProxy)
	{
		GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
	}
}

void FSlMeasureRunnable::Start(float Frequency)
{
	static uint64 ThreadCounter = 0;

	Timer.SetFrequency(Frequency);

	FString ThreadName("SlMeasureRunnable");
	ThreadName.AppendInt(ThreadCounter++);

	Thread = FRunnableThread::Create(this, *ThreadName, 0, TPri_BelowNormal);

	SL_LOG(SlMeasureThread, "Thread started");
}

void FSlMeasureRunnable::GrabCallback(ESlErrorCode ErrorCode)
{
	SCOPE_CYCLE_COUNTER(STAT_AsyncMeasureRetrieve);

	if (!bDepthEnabled && !bNormalsEnabled)
	{
		return;
	}

	FSlMeasureRunnableMatBuffer* FreeBuffer = nullptr;
	SL_SCOPE_LOCK(Lock, UpdateSection)
		FreeBuffer = GET_MR_FREE_BUFFER();
		FreeBuffer->bIsUpdated = false;
		FreeBuffer->bDepthEnabled = bDepthEnabled;
		FreeBuffer->bNormalsEnabled = bNormalsEnabled;
	SL_SCOPE_UNLOCK

	if (FreeBuffer->bDepthEnabled)
	{
		if (!FreeBuffer->Mats[0]) {
			FreeBuffer->Mats[0] = sl_mat_create_new(GSlCameraProxy->RetrieveMatSize.X, GSlCameraProxy->RetrieveMatSize.Y, SL_MAT_TYPE_F32_C1, SL_MEM_GPU);
		}

		SL_ERROR_CODE Err = (SL_ERROR_CODE)sl_retrieve_measure(GSlCameraProxy->GetCameraID(), FreeBuffer->Mats[0], SL_MEASURE_DEPTH, SL_MEM_GPU, GSlCameraProxy->RetrieveMatSize.X, GSlCameraProxy->RetrieveMatSize.Y);
	}
	if(FreeBuffer->bNormalsEnabled)
	{
		if (!FreeBuffer->Mats[1]) {
			FreeBuffer->Mats[1] = sl_mat_create_new(GSlCameraProxy->RetrieveMatSize.X, GSlCameraProxy->RetrieveMatSize.Y, SL_MAT_TYPE_F32_C4, SL_MEM_GPU);
		}

		SL_ERROR_CODE Err = (SL_ERROR_CODE)sl_retrieve_measure(GSlCameraProxy->GetCameraID(), FreeBuffer->Mats[1], SL_MEASURE_NORMALS, SL_MEM_GPU, GSlCameraProxy->RetrieveMatSize.X, GSlCameraProxy->RetrieveMatSize.Y);
	}

	SL_SCOPE_LOCK(Lock, UpdateSection)
		FreeBuffer->bIsUpdated = true;
	SL_SCOPE_UNLOCK
}

void FSlMeasureRunnable::SetDepthAndNormals(bool bEnableDepth, bool bEnableNormals)
{
	SL_SCOPE_LOCK(Lock, UpdateSection)
		bDepthEnabled = bEnableDepth;
		bNormalsEnabled = bEnableNormals;
	SL_SCOPE_UNLOCK
}

float FSlMeasureRunnable::GetDepth(const FIntPoint& ScreenPosition, const FVector2D& InputRangeX, const FVector2D& InputRangeY)
{
	SL_SCOPE_LOCK(Lock, GetSection);
		void* DepthMat = Buffer->Mats[0];

		uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeX, OutputRangeX, ScreenPosition.X);
		uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeY, OutputRangeY, ScreenPosition.Y);

		float Depth;
		sl_mat_get_value_float(DepthMat, X, Y, &Depth, SL_MEM_CPU);

		return Depth;
	SL_SCOPE_UNLOCK
}

TArray<float> FSlMeasureRunnable::GetDepths(const TArray<FIntPoint>& ScreenPositions, const FVector2D& InputRangeX, const FVector2D& InputRangeY)
{
	SL_SCOPE_LOCK(Lock, GetSection);
		TArray<float> Depths;
		Depths.Reserve(ScreenPositions.Num());

		void* DepthMat = Buffer->Mats[0];

		float Depth;

		for (auto Iterator = ScreenPositions.CreateConstIterator(); Iterator; ++Iterator)
		{
			uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeX, OutputRangeX, Iterator->X);
			uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeY, OutputRangeY, Iterator->Y);

			sl_mat_get_value_float(DepthMat, X, Y, &Depth, SL_MEM_CPU);
			Depths.Add(Depth);
		}

		return Depths;
	SL_SCOPE_UNLOCK
}

FVector FSlMeasureRunnable::GetNormal(const FIntPoint& ScreenPosition, const FVector2D& InputRangeX, const FVector2D& InputRangeY)
{
	SL_SCOPE_LOCK(Lock, GetSection);
		void* NormalsMat = Buffer->Mats[1];

		uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeX, OutputRangeX, ScreenPosition.X);
		uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeY, OutputRangeY, ScreenPosition.Y);

		SL_Vector4 Normal;
		sl_mat_get_value_float4(NormalsMat, X, Y, &Normal, SL_MEM_CPU);

		return FVector(Normal.x, Normal.y, Normal.z);
	SL_SCOPE_UNLOCK
}

TArray<FVector> FSlMeasureRunnable::GetNormals(const TArray<FIntPoint>& ScreenPositions, const FVector2D& InputRangeX, const FVector2D& InputRangeY)
{
	SL_SCOPE_LOCK(Lock, GetSection);
		TArray<FVector> Normals;
		Normals.Reserve(ScreenPositions.Num());

		void* NormalsMat = Buffer->Mats[1];

		for (auto Iterator = ScreenPositions.CreateConstIterator(); Iterator; ++Iterator)
		{
			uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeX, OutputRangeX, Iterator->X);
			uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeY, OutputRangeY, Iterator->Y);

			SL_Vector4 Normal;
			sl_mat_get_value_float4(NormalsMat, X, Y, &Normal, SL_MEM_CPU);

			Normals.Insert(FVector(Normal.x, Normal.y, Normal.z), Iterator.GetIndex());
		}

		return Normals;
	SL_SCOPE_UNLOCK
}

FVector4 FSlMeasureRunnable::GetDepthAndNormal(const FIntPoint& ScreenPosition, const FVector2D& InputRangeX, const FVector2D& InputRangeY)
{
	SL_SCOPE_LOCK(Lock, GetSection);
		void* DepthMat = Buffer->Mats[0];
		void* NormalsMat = Buffer->Mats[1];

		uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeX, OutputRangeX, ScreenPosition.X);
		uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeY, OutputRangeY, ScreenPosition.Y);

		SL_Vector4 Normal;
		sl_mat_get_value_float4(NormalsMat, X, Y, &Normal, SL_MEM_CPU);

		float Depth;
		sl_mat_get_value_float(DepthMat, X, Y, &Depth, SL_MEM_CPU);

		return FVector4(Normal.x, Normal.y, Normal.z, Depth);
	SL_SCOPE_UNLOCK
}

TArray<FVector4> FSlMeasureRunnable::GetDepthsAndNormals(const TArray<FIntPoint>& ScreenPositions, const FVector2D& InputRangeX, const FVector2D& InputRangeY)
{
	SL_SCOPE_LOCK(Lock, GetSection)
		TArray<FVector4> DepthsAndNormals;
		DepthsAndNormals.Reserve(ScreenPositions.Num());

		void* DepthMat = Buffer->Mats[0];
		void* NormalsMat = Buffer->Mats[1];

		SL_Vector4 Normal;
		float Depth;

		for (auto Iterator = ScreenPositions.CreateConstIterator(); Iterator; ++Iterator)
		{
			uint32 X = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeX, OutputRangeX, Iterator->X);
			uint32 Y = (uint32)FMath::GetMappedRangeValueUnclamped(InputRangeY, OutputRangeY, Iterator->Y);

			sl_mat_get_value_float4(NormalsMat, X, Y, &Normal, SL_MEM_CPU);
			sl_mat_get_value_float(DepthMat, X, Y, &Depth, SL_MEM_CPU);

			DepthsAndNormals.Insert(FVector4(Normal.x, Normal.y, Normal.z, Depth), Iterator.GetIndex());
		}

		return DepthsAndNormals;
	SL_SCOPE_UNLOCK
}