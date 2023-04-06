//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"
#include "ZED/Public/Core/ZEDBaseTypes.h"

#include "ZEDInitializer.generated.h"


/*
 * Actor used to initialize Zed camera using configuration file
 */
UCLASS(Category = "Stereolabs|Zed")
class ZED_API AZEDInitializer : public AActor
{
	GENERATED_BODY()

public:
	AZEDInitializer();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

public:
	/* 
	 * Load all parameters and settings
	 */
	UFUNCTION(BlueprintCallable, Category="Zed")
	void LoadParametersAndSettings();

	/*
	 * Load config parameters 
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void LoadParameters();

	/* 
	 * Load camera settings 
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void LoadCameraSettings();

	/* 
	 * Load config parameters 
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SaveParameters();

	/*
	 * Load camera settings 
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SaveCameraSettings();

	/*
	 * Reset parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void ResetParameters();

	/*
	 * Reset camera settings
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void ResetSettings();

public:

	/** Type of view displayed on the scene.
	* Default is ESlView::LEFT.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	ESlView ImageView;

	/** Init parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlInitParameters InitParameters;

	/** Tracking parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlPositionalTrackingParameters TrackingParameters;

	/** Recording parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlRecordingParameters RecordingParameters;

	/** Runtime parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlRuntimeParameters RuntimeParameters;

	/** Rendering parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlRenderingParameters RenderingParameters;

	/* Object Detection parameters*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlObjectDetectionParameters ObjectDetectionParameters;

	/* Object Detection runtime parameters*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlObjectDetectionRuntimeParameters ObjectDetectionRuntimeParameters;

	/* Body Tracking parameters*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlBodyTrackingParameters BodyTrackingParameters;

	/* Body Tracking runtime parameters*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlBodyTrackingRuntimeParameters BodyTrackingRuntimeParameters;

	/** Camera settings */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlVideoSettings CameraSettings;

	/** Actors that will be attached to the pawn at startup. Actor's Transform will be local, and body weld. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	TArray<AActor*> ChildActors;

	/** Load parameters at runtime from config file and override preset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	uint8 bLoadParametersFromConfigFile:1;

	/** Load camera settings at runtime from config file and override preset  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	uint8 bLoadCameraSettingsFromConfigFile:1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	uint8 bDepthOcclusion : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	uint8 bShowZedImage : 1;

	/*
	* Can be used for Background substaction application.
	* If the depth of the image is greater than this threshold, shows the virtual scene instead
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	float DepthClampThreshold;
};