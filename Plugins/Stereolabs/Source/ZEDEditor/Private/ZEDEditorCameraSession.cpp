//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZEDEditor/Public/ZEDEditorCameraSession.h"
#include "ZEDEditor/Private/ZEDEditorPrivatePCH.h"
#include "ZED/Public/Core/ZEDCamera.h"
#include "Editor.h"
#include "Engine/World.h"
#include "Misc/CoreDelegates.h"
#include "UObject/Package.h"
#include "UObject/UObjectGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"

DEFINE_LOG_CATEGORY_STATIC(ZEDEditorCameraSession, Log, All);

namespace
{
	UZEDEditorCameraSession* GZEDEditorCameraSession = nullptr;

	/** The neural depth modes need their model optimized before the camera can be opened with them */
	bool GetDepthAIModel(ESlDepthMode DepthMode, ESlAIModels& OutModel)
	{
		switch (DepthMode)
		{
			case ESlDepthMode::DM_Neural:      OutModel = ESlAIModels::AIM_NeuralDepth;      return true;
			case ESlDepthMode::DM_NeuralPlus:  OutModel = ESlAIModels::AIM_NeuralPlusDepth;  return true;
			case ESlDepthMode::DM_NeuralLight: OutModel = ESlAIModels::AIM_NeuralLightDepth; return true;
			default: return false;
		}
	}
}

UZEDEditorCameraSession* UZEDEditorCameraSession::Get()
{
	// Created on demand rather than at module startup, the first caller is the details panel
	if (!GZEDEditorCameraSession)
	{
		Create();
	}

	return GZEDEditorCameraSession;
}

void UZEDEditorCameraSession::Create()
{
	if (GZEDEditorCameraSession)
	{
		return;
	}

	GZEDEditorCameraSession = NewObject<UZEDEditorCameraSession>();
	GZEDEditorCameraSession->AddToRoot();

	GZEDEditorCameraSession->PreBeginPIEHandle = FEditorDelegates::PreBeginPIE.AddUObject(GZEDEditorCameraSession, &UZEDEditorCameraSession::OnPreBeginPIE);
	GZEDEditorCameraSession->MapOpenedHandle = FEditorDelegates::OnMapOpened.AddUObject(GZEDEditorCameraSession, &UZEDEditorCameraSession::OnMapOpened);
	GZEDEditorCameraSession->PreExitHandle = FCoreDelegates::OnPreExit.AddUObject(GZEDEditorCameraSession, &UZEDEditorCameraSession::Stop);
}

void UZEDEditorCameraSession::Destroy()
{
	if (!GZEDEditorCameraSession)
	{
		return;
	}

	FEditorDelegates::PreBeginPIE.Remove(GZEDEditorCameraSession->PreBeginPIEHandle);
	FEditorDelegates::OnMapOpened.Remove(GZEDEditorCameraSession->MapOpenedHandle);
	FCoreDelegates::OnPreExit.Remove(GZEDEditorCameraSession->PreExitHandle);

	// On editor exit the UObject system is already torn down by the time modules unload, and
	// OnPreExit has stopped the session before that
	if (UObjectInitialized())
	{
		GZEDEditorCameraSession->Stop();
		GZEDEditorCameraSession->RemoveFromRoot();
	}

	GZEDEditorCameraSession = nullptr;
}

bool UZEDEditorCameraSession::Start(AZEDCamera* InCamera, FString& OutError)
{
	if (Camera.IsValid())
	{
		OutError = TEXT("A camera session is already running in the editor");
		return false;
	}

	if (!IsValid(InCamera))
	{
		OutError = TEXT("No camera actor");
		return false;
	}

	const UWorld* World = InCamera->GetWorld();
	if (!World || World->WorldType != EWorldType::Editor)
	{
		OutError = TEXT("The camera actor must be placed in the level being edited");
		return false;
	}

	// One SDK session per device: a play session or another actor already owns the camera
	if (GSlCameraProxy)
	{
		OutError = TEXT("A camera session is already running, stop it before starting another one");
		return false;
	}

	if (!InCamera->ValidateForEditorSession(OutError))
	{
		return false;
	}

	Camera = InCamera;
	bSessionActive = true;
	AuthoredRotation = InCamera->GetActorRotation();
	bAppliedStartRotation = false;
	bWasPackageDirty = InCamera->GetOutermost()->IsDirty();

	CreateSlCameraProxyInstance();

	GSlCameraProxy->OnCameraOpened.AddDynamic(this, &UZEDEditorCameraSession::CameraOpened);

	InCamera->BeginEditorSession();

	ESlAIModels DepthAIModel;
	if (GetDepthAIModel(InCamera->InitParameters.DepthMode, DepthAIModel) && !GSlCameraProxy->CheckAIModelOptimization(DepthAIModel))
	{
		SL_LOG_W(ZEDEditorCameraSession, "Optimizing the depth AI model, the process can take a few minutes");

		GSlCameraProxy->OnAIModelOptimized.AddDynamic(this, &UZEDEditorCameraSession::AIModelOptimized);
		GSlCameraProxy->OptimizeAIModel(DepthAIModel, ESlAIType::AIT_Depth);
	}
	else
	{
		OpenCamera();
	}

	return true;
}

void UZEDEditorCameraSession::ApplyStartRotation()
{
	if (bAppliedStartRotation)
	{
		return;
	}

	// Zero until the first grab reports, and stays zero on models without an IMU
	const FRotator Imu = Camera->TrackingData.IMURotator;
	if (Imu.IsNearlyZero())
	{
		return;
	}

	// The IMU is gravity referenced, so pitch and roll are absolute but yaw has no world
	// reference. Play seeds its tracking origin from the placed actor, which comes to the same thing
	Camera->SetActorRotation(FRotator(Imu.Pitch, AuthoredRotation.Yaw, Imu.Roll));

	bAppliedStartRotation = true;
}

void UZEDEditorCameraSession::OpenCamera()
{
	GSlCameraProxy->OpenCamera(Camera->InitParameters);
}

void UZEDEditorCameraSession::AIModelOptimized()
{
	if (!Camera.IsValid())
	{
		return;
	}

	OpenCamera();
}

void UZEDEditorCameraSession::CameraOpened()
{
	if (!Camera.IsValid())
	{
		return;
	}

	Camera->Init();

	// Init mutates the actor components, that is session state and not something to save
	if (!bWasPackageDirty)
	{
		Camera->GetOutermost()->SetDirtyFlag(false);
	}
}

void UZEDEditorCameraSession::Stop()
{
	// Never touch a proxy this session does not own, a play session has one of its own
	if (!bSessionActive)
	{
		return;
	}

	bSessionActive = false;

	// Null when the actor was destroyed under us, the camera still has to go
	AZEDCamera* SessionCamera = Camera.Get();
	Camera = nullptr;

	if (GSlCameraProxy)
	{
		GSlCameraProxy->OnCameraOpened.RemoveDynamic(this, &UZEDEditorCameraSession::CameraOpened);
		GSlCameraProxy->OnAIModelOptimized.RemoveDynamic(this, &UZEDEditorCameraSession::AIModelOptimized);

		// Broadcasts OnCameraClosed, which frees the batch and the textures
		GSlCameraProxy->CloseCamera();
	}

	if (SessionCamera)
	{
		if (bAppliedStartRotation)
		{
			SessionCamera->SetActorRotation(AuthoredRotation);
			bAppliedStartRotation = false;
		}

		SessionCamera->EndEditorSession();
	}

	FreeSlCameraProxyInstance();

	if (SessionCamera && !bWasPackageDirty)
	{
		SessionCamera->GetOutermost()->SetDirtyFlag(false);
	}
}

void UZEDEditorCameraSession::Tick(float DeltaTime)
{
	if (!bSessionActive || !Camera.IsValid() || !GSlCameraProxy)
	{
		Stop();
		return;
	}

	// The grab loop runs on its own thread, this is the game thread pump that pushes the
	// retrieved frames into the textures
	Camera->Tick(DeltaTime);

	ApplyStartRotation();
}

void UZEDEditorCameraSession::OnPreBeginPIE(bool bIsSimulating)
{
	if (bSessionActive)
	{
		SL_LOG_W(ZEDEditorCameraSession, "Stopping the editor camera session, play is starting");
	}

	Stop();
}

void UZEDEditorCameraSession::OnMapOpened(const FString& Filename, bool bAsTemplate)
{
	Stop();
}
