//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "CoreMinimal.h"
#include "TickableEditorObject.h"
#include "UObject/Object.h"
#include "UObject/WeakObjectPtr.h"

#include "ZEDEditorCameraSession.generated.h"

class AZEDCamera;

/*
 * Camera session running in the level editor, outside of play.
 * Stands in for AZEDPlayerController: opens the camera and ticks the camera actor so the image
 * and depth textures keep being updated without a game world, pawn or HUD.
 */
UCLASS()
class ZEDEDITOR_API UZEDEditorCameraSession : public UObject, public FTickableEditorObject
{
	GENERATED_BODY()

public:
	/** The session owned by the ZEDEditor module, created on first use */
	static UZEDEditorCameraSession* Get();
	static void Destroy();

	/*
	 * Open the camera for a level placed actor
	 * @param InCamera The actor to run the session on
	 * @param OutError Reason the session could not be started
	 */
	bool Start(AZEDCamera* InCamera, FString& OutError);

	/** Close the camera and restore the actor */
	void Stop();

	bool IsRunning() const { return bSessionActive; }

	AZEDCamera* GetCamera() const { return Camera.Get(); }

	/** FTickableEditorObject interface */
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override { return bSessionActive && Camera.IsValid(); }
	virtual TStatId GetStatId() const override { RETURN_QUICK_DECLARE_CYCLE_STAT(UZEDEditorCameraSession, STATGROUP_Tickables); }

private:
	static void Create();

	void OpenCamera();

	/** Initialize the camera actor once the camera is opened */
	UFUNCTION()
	void CameraOpened();

	/** Open the camera once the neural depth model is optimized */
	UFUNCTION()
	void AIModelOptimized();

	/** A world going away or a play session starting takes the camera with it */
	void OnPreBeginPIE(bool bIsSimulating);
	void OnMapOpened(const FString& Filename, bool bAsTemplate);

	/** Level the actor to the real camera once the IMU has reported, keeping the authored yaw */
	void ApplyStartRotation();

	TWeakObjectPtr<AZEDCamera> Camera;

	/** Restored on stop, so a session never leaves a modified transform behind */
	FRotator AuthoredRotation = FRotator::ZeroRotator;

	bool bAppliedStartRotation = false;

	/** True between Start and Stop, so Stop can never close a camera this session does not own */
	bool bSessionActive = false;

	FDelegateHandle PreBeginPIEHandle;
	FDelegateHandle MapOpenedHandle;
	FDelegateHandle PreExitHandle;

	/*
	 * Opening the camera mutates the actor components, which would dirty the level.
	 * A session is not something to save, so the flag is put back as it was.
	 */
	bool bWasPackageDirty = false;
};
