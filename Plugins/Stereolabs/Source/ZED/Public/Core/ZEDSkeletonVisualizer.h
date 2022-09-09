//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "../../../Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "../../../Stereolabs/Public/Core/StereolabsCameraProxy.h"

#include "ZEDSkeletonVisualizer.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(ZEDSkeletonVisualizer, Log, All);

/*
 * Actor that manage the ZED Skeleton Visualizer
 */
UCLASS(Category = "Stereolabs|Zed")
class ZED_API AZEDSkeletonVisualizer : public AActor
{
	GENERATED_BODY()

public:
	AZEDSkeletonVisualizer();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaSeconds) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

	/*
	 * @return True if the Object Detection module is enabled
	 */
	bool IsObjectDetectionEnabled();

	/*
	 * Enable the Object Detection in the SDK.
	 */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Zed|ObjectDetection")
	bool EnableObjectDetection();

	/*
	 * Disable the Object Detection module.
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|ObjectDetection")
	void DisableObjectDetection();

private :

	UFUNCTION()
	void OnZEDReady(bool bSuccess, ESlErrorCode ErrorCode, const FVector& Location, const FRotator& Rotation);

public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|ObjectDetection")
	bool bStartObjectDetectionAutomatically;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|ObjectDetection")
	FSlObjectDetectionParameters ObjectDetectionParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|ObjectDetection")
	FSlObjectDetectionRuntimeParameters ObjectDetectionRuntimeParameters;

	UPROPERTY(BlueprintReadWrite, Category = "Zed")
	FSlObjects Objects;
};
