//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "../../../Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "../../../Stereolabs/Public/Core/StereolabsCameraProxy.h"

#include "ZED3DObjectVisualizer.generated.h"


DECLARE_LOG_CATEGORY_EXTERN(ZED3DObjectVisualizer, Log, All);

/*
 * Actor that manage the ZED 3D Object Visualizer
 */
UCLASS(Category = "Stereolabs|Zed")
class ZED_API AZED3DObjectVisualizer : public AActor
{
	GENERATED_BODY()

public:
	AZED3DObjectVisualizer();

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
	UFUNCTION(BlueprintPure, Category = "Zed|ObjectDetection")
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

	UFUNCTION(BlueprintCallable, Category = "Zed|ObjectDetection")
	void OnZEDReady(bool bSuccess, ESlErrorCode ErrorCode, const FVector& Location, const FRotator& Rotation);

	void Visualize3DBoundingBoxes();

	AActor* GetBBoxForObject(SL_ObjectData obj);

public :

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlObjectDetectionParameters ObjectDetectionParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlObjectDetectionRuntimeParameters ObjectDetectionRuntimeParameters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<AActor> BBox3D;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bStartObjectDetectionAutomatically;

private:

	SL_Objects Objects;

	TMap<int, AActor*> LiveBBoxes;
};