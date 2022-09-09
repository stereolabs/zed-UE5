//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "MotionControllerComponent.h"
#include "DevicesMotionController.generated.h"

/*
 *	Actor which can provide a MotionController transform with a delay in millisecond. AActor is needed for timer.
 */
UCLASS(Category = "Stereolabs|Controllers")
class DEVICES_API ADevicesMotionController : public AActor
{
	GENERATED_BODY()

public:
	ADevicesMotionController();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void Start();

	UFUNCTION()
	void Stop();

public:

	UFUNCTION(BlueprintCallable, Category = "Zed")
	void ModifyLatencyTime(const int& NewLatencyInMs);

	UFUNCTION(BlueprintCallable, Category = "Zed")
	int GetModifiedLatencyTime();



private:
	/*
	 * Get the motion controller transform delayed of "LatencyTime" milliseconds 
	 * @return The transform
	 */
	FTransform GetDelayedTransform();

	/** Function called by the timer. It add a new motion controller transform to the buffer and remove the old one if we have enough */
	void UpdateTransformBuffer();

	/*
	 * Get the transform of the motion controller relative to the ZED
	 * @param Transform The out transform
	 * @return True if the transform is valid
	 */
	bool GetTransform(FTransform& Transform);

public:
	/** MotionController */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Instanced)
	UMotionControllerComponent* MotionController;

private:
	/** Latency time add to controller pose (in ms) */
	int32 LatencyTime;

	/** Buffer containing previous controller transforms (one transform each frame) */
	TArray<FTransform, TFixedAllocator<70>> TransformBuffer;

	/** Update transform timer handle */
	FTimerHandle TimerHandle;

	/**  */
	bool isDeviceInitialized = false;

	/**  */
	bool bHmdTranslationUsed = false;
};
