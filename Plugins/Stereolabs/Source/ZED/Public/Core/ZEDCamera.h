//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "GameFramework/Actor.h"
#include "ZEDBaseTypes.h"
#include "../../../Stereolabs/Public/Core/StereolabsTexture.h"
#include "../../../Stereolabs/Public/Core/StereolabsTextureBatch.h"
#include "ImageUtils.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Camera/CameraComponent.h"

#include "ZEDCamera.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(ZEDCamera, Log, All);

/*
 * Notify that the tracking data have been updated
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FZEDTrackingDataUpdatedDelegate, const FZEDTrackingData&, NewTrackingData, const float&, DeltaSeconds);

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

	/*
	 * Check that the parameters allow a camera session outside of play, without asserting
	 * @param OutError Reason the session can't be started
	 */
	bool ValidateForEditorSession(FString& OutError) const;

	/*
	 * Prepare the actor for a camera session driven by the editor instead of the player controller.
	 * Editor equivalent of BeginPlay, to call before opening the camera
	 */
	void BeginEditorSession();

	/*
	 * Release everything BeginEditorSession and Init set up and restore the placed components
	 */
	void EndEditorSession();

	/** Apply EditorPreviewPlaneDistance, resizing the plane when a session is already running */
	void SetEditorPreviewPlaneDistance();
#endif

#if WITH_EDITORONLY_DATA
	/*
	 * How far in front of the camera the preview plane is placed for a session started in the editor.
	 * The plane is scaled to cover the camera field of view at that distance, so a larger value
	 * gives a larger preview. Play always uses the near clipping plane instead
	 */
	UPROPERTY(EditAnywhere, Category = "Zed|Editor", meta = (ClampMin = "1.0", UIMin = "1.0", UIMax = "500.0"))
	float EditorPreviewPlaneDistance = 100.0f;
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
	 * Load all parameters and settings from the config files, if the load flags are set
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
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
	 * Save config parameters
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SaveParameters();

	/*
	 * Save camera settings
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

	/*
	 * Validate parameters right before the camera is opened
	 */
	void PrepareForOpening();

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

	/** Image resolution scaled down by DepthResolution */
	FIntPoint GetDepthTextureSize() const;

	/** Copy the left image into ColorOutput, resizing it first if it does not match */
	void UpdateColorOutput();

	/** Blank the output targets, so a closed camera does not leave its last frame driving them */
	void ClearOutputs();

	/** Copy the depth texture into DepthOutput, resizing it first if it does not match */
	void UpdateDepthOutput();
	
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
	UPROPERTY(BlueprintReadOnly, Transient, Category = "Zed|Textures")
	USlTexture* LeftEyeColor;

	/** Left eye depth texture  */
	UPROPERTY(BlueprintReadOnly, Transient, Category = "Zed|Textures")
	USlTexture* LeftEyeDepth;

	/** Render target left eye */
	UPROPERTY(BlueprintReadWrite, Transient, Category = "Zed|Textures")
	UTextureRenderTarget2D* LeftEyeRenderTarget;

	/*
	 * Optional render target the left image is copied into every frame, so it can be picked as an
	 * asset where a transient texture cannot be, such as a Composite plate layer.
	 * Reconfigured to the image size and RGBA8 sRGB when it does not already match, so it samples
	 * like any other color texture
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Output")
	UTextureRenderTarget2D* ColorOutput;

	/*
	 * Optional render target the metric depth is copied into every frame. The retrieved depth lives in
	 * a transient texture that no asset picker can list, so this is how it reaches anything that takes
	 * a texture asset, such as the Composite plugin depth mesh. Values are centimeters.
	 * Reconfigured to the depth texture size and R32f when it does not already match
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Output")
	UTextureRenderTarget2D* DepthOutput;

	/*
	 * Resolution the depth is retrieved at, as a fraction of the image. Sets the size of the depth
	 * texture and of DepthOutput. Can be changed while the camera runs
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Output")
	ESlDepthResolution DepthResolution;

	/** Size the depth is actually retrieved at, once DepthResolution is capped to the image */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category = "Zed|Output")
	FIntPoint DepthResolutionInPixels;

	/** Init parameters (resolution, depth mode, input type, SVO/stream source) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlInitParameters InitParameters;

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

	/**  Render distance of the ZED planes */
	UPROPERTY(BlueprintReadWrite, Category = "Zed|Rendering")
	float CameraRenderPlaneDistance;

	// ------------------------------------------------------------------

	/** The current tracking data */
	UPROPERTY(BlueprintReadOnly, Transient, Category = "Zed|Tracking")
	FZEDTrackingData TrackingData;

	/** Tracking parameters */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
    FSlPositionalTrackingParameters TrackingParameters;

	// ------------------------------------------------------------------

	/** Dynamic left Zed eye material */
	UPROPERTY(BlueprintReadWrite, Transient, Category = "Zed|Rendering")
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

	/** True to render the real camera image, false to keep the virtual scene only */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	bool bShowZedImage;

	/** Actors that will be attached to the pawn at startup. Actor's Transform will be local, and body weld. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	TArray<AActor*> ChildActors;

	/** Load parameters at runtime from config file and override preset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	bool bLoadParametersFromConfigFile;

	/** Load camera settings at runtime from config file and override preset  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	bool bLoadCameraSettingsFromConfigFile;

	// ------------------------------------------------------------------

	/** When enabled, the real world can occlude (cover up) virtual objects that are behind it. Otherwise, virtual objects will appear in front. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	bool bDepthOcclusion;

	/** Max depth distance. Can be modified at runtime */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	float DepthClampThreshold;

private:

	/** Current batch */
	UPROPERTY(Transient)
	USlTextureBatch* Batch;

	/** Zed material resource */
	UPROPERTY()
	UMaterial* ZedSourceMaterial;

	/** The tracking data of the current grab frame */
	FZEDTrackingData CurrentFrameTrackingData;

	/** SL_POSITIONAL_TRACKING_STATE last written to the log, so the state is only logged on change */
	int32 LastLoggedTrackingState = -1;

	/** The grab delegate handle */
	FDelegateHandle GrabDelegateHandle;

	/** Update section if grab is threaded */
	FCriticalSection TrackingUpdateSection;

	/** True if depth enabled */
	bool bCurrentDepthEnabled;

	/** True if initialized */
	bool bInit;

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

		/*
		 * Matches the real camera field of view once it is opened, so anything that composites
		 * through a camera actor can just point at this actor
		 */
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed|Components")
		UCameraComponent* ViewCamera;

	private:

		void ToggleComponents(bool enable);
		void SetupComponents();
		void SetPlaneSize(UStaticMeshComponent* plane, float planeDistance);

		void AddOrUpdatePostProcessCpp(UMaterialInterface* NewPostProcess, float NewWeight);

		void DisableRenderingCpp();
		void InitializeRenderingCpp();
};
