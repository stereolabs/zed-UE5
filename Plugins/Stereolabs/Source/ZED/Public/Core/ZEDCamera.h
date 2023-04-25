//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "ZEDBaseTypes.h"
#include "ZEDInitializer.h"
#include "../../../Stereolabs/Public/Core/StereolabsTexture.h"
#include "../../../Stereolabs/Public/Core/StereolabsTextureBatch.h"
#include "../../../ThirdParty/MixedReality/include/sl_mr_core/defines.hpp"

#include "ZEDCamera.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(ZEDCamera, Log, All);

/*
 * Notify that the tracking data have been updated
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FZEDTrackingDataUpdatedDelegate, const FZEDTrackingData&, NewTrackingData);

/*
 * Notify that the actor is initialized
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FZEDCameraActorInitializedDelegate);

/*
 * Engine representation of the ZED. Spawnable in a level
 */
UCLASS(Category = "Stereolabs|Zed")
class ZED_API AZEDCamera : public AActor
{
	friend class AZEDPlayerController;

	GENERATED_BODY()

public:	
	AZEDCamera();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick( float DeltaSeconds ) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

public:

	/*
	 * Enable tracking using current tracking parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Tracking")
	void EnableTracking();

	/*
	 * Disable tracking
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Tracking")
	void DisableTracking();

	/*
	*Enable object detection using current object detection parameters
	*/
	UFUNCTION(BlueprintCallable, Category = "Zed|Object Detection")
	void EnableObjectDetection();

	/*
	 * Disable object detection
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Object Detection")
	void DisableObjectDetection();

	/*
	*Enable body tracking using current body tracking parameters
	*/
	UFUNCTION(BlueprintCallable, Category = "Zed|Body Tracking")
	void EnableBodyTracking();

	/*
	 * Disable body tracking
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Body Tracking")
	void DisableBodyTracking();

	/*
	 * Reset the tracking origin of the camera.
	 * Else use the current tracking data.
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Tracking")
	void ResetTrackingOrigin();

	/*
	 * Save the tracking area using current tracking parameters path
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Tracking")
	void SaveSpatialMemoryArea();

	/*
	 * Set the threading mode and enable/disable the grab thread
	 * @param NewValue The new threading mode
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Rendering")
	void EnableMultiThreadedRenderingMode(bool EnableMTR);

	/*
	 * Set Max depth distance.
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Runtime")
	void SetDepthClampThreshold(const float DepthDistance);

	UFUNCTION(BlueprintCallable, Category = "Zed|Runtime")
	void SetDepthOcclusion(const bool EnableOcclusion);

	/*
	 * Set the runtime parameters. Take effect next grab
	 * @param NewValue The news runtime parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Runtime")
	void SetRuntimeParameters(const FSlRuntimeParameters& NewValue);

	/*
	 * Set the object detection runtime parameters. Take effect next retrieve
	 * @param NewValue The news object detection runtime parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|OD")
	void SetObjectDetectionRuntimeParameters(const FSlObjectDetectionRuntimeParameters& NewValue);

	/*
	 * Set the body tracking runtime parameters. Take effect next retrieve
	 * @param NewValue The news body tracking runtime parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|OD")
	void SetBodyTrackingRuntimeParameters(const FSlBodyTrackingRuntimeParameters& NewValue);

	/*
	 * Get the current body tracking runtime parameters.
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|OD")
	FSlBodyTrackingRuntimeParameters GetBodyTrackingRuntimeParameters();

	/*
	 * Set the camera settings. Take effect next grab 
	 * @param NewValue The news camera settings
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Camera")
	void SetCameraSettings(const FSlVideoSettings& NewValue);

	/*
	 * Enable recording using Init and SVO parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SVO")
	ESlErrorCode EnableSVORecording();

	/*
	 * Disable SVO recording
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SVO")
	void DisableSVORecording();

	/*
	 * Enable/Disable SVO playback looping
	 * @param bLooping True to loop
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SVO")
	void SetSVOPlaybackLooping(bool bLooping);

	/*
	 * Initialize parameters
	 * @param ZedInitializer The initializer
	 */
	void InitializeParameters(AZEDInitializer* ZedInitializer);

	/*
	 * Initialize actor
	 */
	void Init();
	
	// ------------------------------------------------------------------

private:
	/*
	 * Callback function for the grab delegate
	 * @param ErrorCode Grab error code
	 * @param Timestamp Image timestamp
	 */
	UFUNCTION()
	void GrabCallback(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp);

	/*
	 * Zed closed
	 */
	UFUNCTION()
	void CameraClosed();

	// ------------------------------------------------------------------

private:
	/*
	 * Create left eye textures
	 *
	 * @param bCeateColorTexture True to create color texture
	 */
	void CreateLeftTextures(bool bCreateColorTexture = true);
	
	// ------------------------------------------------------------------

public:
	/** Tracking data dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|Tracking")
	FZEDTrackingDataUpdatedDelegate OnTrackingDataUpdated;

	/** Actor initialized */
	UPROPERTY(BlueprintAssignable, Category = "Zed|Camera")
	FZEDCameraActorInitializedDelegate OnCameraActorInitialized;

	// ------------------------------------------------------------------

	/** Left eye image texture */
	UPROPERTY(BlueprintReadOnly, Category = "Zed|Textures")
	USlTexture* LeftEyeColor;

	/** Left eye depth texture  */
	UPROPERTY(BlueprintReadOnly, Category = "Zed|Textures")
	USlTexture* LeftEyeDepth;

	/** Render target left eye */
	UPROPERTY(BlueprintReadWrite, Category = "Zed|Textures")
	UTextureRenderTarget2D* LeftEyeRenderTarget;

	/** Type of view displayed on the scene.
	* Default is ESlView::LEFT.
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	ESlView ImageView;

	// ------------------------------------------------------------------

	/** Runtime parameters */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zed")
	FSlRuntimeParameters RuntimeParameters;

	/** Camera settings */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Zed")
	FSlVideoSettings CameraSettings;

	// ------------------------------------------------------------------

	/** Config rendering parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlRenderingParameters RenderingParameters;

	/**  Render distance of the ZED planes */
	UPROPERTY(BlueprintReadWrite, Category = "Zed|Rendering")
	float CameraRenderPlaneDistance;

	// ------------------------------------------------------------------

	/** The current tracking data */
	UPROPERTY(BlueprintReadOnly, Category = "Zed|Tracking")
	FZEDTrackingData TrackingData;

	/** Tracking parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
    FSlPositionalTrackingParameters TrackingParameters;

	// ------------------------------------------------------------------

	/** Dynamic left Zed eye material */
	UPROPERTY(BlueprintReadWrite, Category = "Zed|Rendering")
	UMaterialInstanceDynamic* ZedLeftEyeMaterialInstanceDynamic;

	// ------------------------------------------------------------------

	/** Object Detection Parameters */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlObjectDetectionParameters ObjectDetectionParameters;

	/* Object Detection runtime parameters*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlObjectDetectionRuntimeParameters ObjectDetectionRuntimeParameters;

	/** Body Tracking Parameters */

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlBodyTrackingParameters BodyTrackingParameters;

	/* Object Detection runtime parameters*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlBodyTrackingRuntimeParameters BodyTrackingRuntimeParameters;

	// ------------------------------------------------------------------

	/** Recording parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlRecordingParameters RecordingParameters;

	// ------------------------------------------------------------------
	
	/** When enabled, the real world can occlude (cover up) virtual objects that are behind it. Otherwise, virtual objects will appear in front. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	uint8 bDepthOcclusion : 1;

	/** Max depth distance. Can be modified at runtime */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	float DepthClampThreshold;

private:

	/** Current batch */
	UPROPERTY()
	USlTextureBatch* Batch;

	/** Init parameters */
	FSlInitParameters InitParameters;

	/** Zed material resource */
	UPROPERTY()
	UMaterial* ZedSourceMaterial;

	/** The tracking data of the current grab frame */
	FZEDTrackingData CurrentFrameTrackingData;

	/** The grab delegate handle */
	FDelegateHandle GrabDelegateHandle;

	/** Update section if grab is threaded */
	FCriticalSection TrackingUpdateSection;

	/** Plane anti drift timer handle */
	FTimerHandle PlanesAntiDriftTimerHandle;

	/** Current depth texture quality preset */
	int32 CurrentDepthTextureQualityPreset;

	/** True if depth enabled */
	uint8 bCurrentDepthEnabled:1;

	/** True if initialized */
	uint8 bInit:1;

	uint8 bShowZedImage:1;

	/************************ Section from old blueprint **********************/

	public:

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Components")
		USceneComponent * LeftRoot;

		/** Left intermediate camera (virtual equivalent of physical left zed camera) */
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Components")
		USceneCaptureComponent2D* LeftCamera;

		/** Intermediate left plane on which Zed left image is displayed */
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Components")
		UStaticMeshComponent* LeftPlane;

	private:

		void ToggleComponents(bool enable);
		void SetupComponents();
		void SetPlaneSizeWithGamma(UStaticMeshComponent* plane, float planeDistance);
		void SetPlaneSize(UStaticMeshComponent* plane, float planeDistance);

		void AddOrUpdatePostProcessCpp(UMaterialInterface* NewPostProcess, float NewWeight);

		void DisableRenderingCpp();
		void InitializeRenderingCpp();
};
