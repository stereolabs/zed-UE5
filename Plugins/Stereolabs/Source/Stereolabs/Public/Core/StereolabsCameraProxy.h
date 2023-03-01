//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Engine/GameInstance.h"

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Utilities/StereolabsViewportHelper.h"
#include "Stereolabs/Public/Core/StereolabsMesh.h"

THIRD_PARTY_INCLUDES_START
#include "../../../ThirdParty/sl_zed_c/include/sl/c_api/zed_interface.h"
THIRD_PARTY_INCLUDES_END

#include "StereolabsCameraProxy.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(SlCameraProxy, Log, All);

/*
 * Delegates using two params
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSlCameraProxyTwoParamsDelegate, bool, bSuccess, ESlErrorCode, ErrorCode);

/*
 * Delegates using one param
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlCameraProxyOneParamDelegate, bool, bEnabled);

/*
 * Simple dynamic multicast delegate
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSlCameraProxyDelegate);

/*
 * Notify tracking enables/reset
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FSlCameraProxyTrackingDelegate, bool, bSuccess, ESlErrorCode, ErrorCode, const FVector&, Location, const FRotator&, Rotation);

/*
 * Notify spatial mapping paused
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlCameraProxySpatialMappingPausedDelegate, bool, bPaused);

/* 
 * Notify grab done
 */
DECLARE_MULTICAST_DELEGATE_TwoParams(FSlCameraProxyGrabDelegate, ESlErrorCode, const FSlTimestamp&);

/*
* Notify new objects are retrieved
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlCameraProxyRetrieveObjectsDelegate, const FSlObjects&, objects);

/*
* Notify new bodies are retrieved
*/
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSlCameraProxyRetrieveBodiesDelegate, const FSlBodies&, bodies);

class FOpenCameraAsyncTask;
class FEnableTrackingAsyncTask;
class FAIOptimizationAsyncTask;
class FResetTrackingAsyncTask;

/** Create the instance */
extern STEREOLABS_API void CreateSlCameraProxyInstance();

/** Free the instance */
extern STEREOLABS_API void FreeSlCameraProxyInstance();

/*
 * Handle for Grab delegate in blueprint
 */
USTRUCT(BlueprintType)
struct STEREOLABS_API FGrabDelegateHandle
{
	GENERATED_BODY()

	FGrabDelegateHandle()
	{
	}

	FGrabDelegateHandle(const FDelegateHandle& Handle)
		:
		Handle(Handle)
	{
	}

	FGrabDelegateHandle& operator=(const FDelegateHandle& NewHandle)
	{
		Handle = NewHandle;
		return *this;
	}

	FDelegateHandle Handle;
};

/*
 * Interface for blueprint actors that need to be added to OnGrabDoneDelegate
 */
UINTERFACE()
class STEREOLABS_API UGrabCallbackInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/*
 * Interface implementation
 */
class STEREOLABS_API IGrabCallbackInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	/*
	 * Grab callback
	 * @param ErrorCode The grab error code
	 * @param Timestamp Image timestamp
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GrabCallback(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp);
};


/*
 * Proxy to access Zed camera SDK functions.
 * Thread safe if accessed from game thread.
 */
UCLASS(Category = "Stereolabs")
class STEREOLABS_API USlCameraProxy : public UObject
{
	friend class USlFunctionLibrary;
	friend class FOpenCameraAsyncTask;
	friend class FEnableTrackingAsyncTask;
	friend class FAIOptimizationAsyncTask;
	friend class FResetTrackingAsyncTask;

	GENERATED_BODY()

public:
	USlCameraProxy();

	virtual void BeginDestroy() override;

	// ------------------------------------------------------------------

public:
	/*
	 * @return The ZED SDK version as a string with the following format : MAJOR.MINOR.PATCH
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed sdk version"), Category = "Stereolabs|Zed|Camera")
	static FString GetSDKVersion();

	/*
	 * Wait for a Zed camera to be connected and initialize it asynchronously.
	 * @param InitParameters Parameters to initialize
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "open zed camera"), Category = "Zed|Camera")
	void OpenCamera(const FSlInitParameters& InitParameters);

	/*
	 * Close the Zed camera. Disable Grab.
	 * Automatically called when destroyed.
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "close zed camera"), Category = "Zed|Camera")
	void CloseCamera();

	/*
	 * @return True if the Zed is opened
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "is zed opened"), Category = "Zed|Camera")
	bool IsCameraOpened();

	/*
	 * @return True if the Zed is connected
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "is zed connected"), Category = "Stereolabs|Zed|Camera")
	static bool IsCameraConnected();

	/*
	 * @return The array of device properties
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get camera list"), Category = "Stereolabs|Zed|Camera")
	static TArray<FSlDeviceProperties> GetCameraList();

	/*
	 * @return The current camera settings
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed camera settings"), Category = "Zed|Camera")
	FSlVideoSettings GetCameraSettings();

	/*
	 * Set the camera settings
	 * @param NewCameraSettings The camera settings to set
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "set zed camera settings"), Category = "Zed|Camera")
	void SetCameraSettings(FSlVideoSettings& NewCameraSettings);

	/*
	 * Get the current timestamp
	 * @param TimeReference The timestamp time reference
	 * @return			    The current timestamp
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed current settings"), Category = "Zed|Camera")
	FSlTimestamp GetTimestamp(ESlTimeReference TimeReference);

	/*
	 * Set the runtime parameters
	 * @param NewRuntimeParameters The runtime parameters
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set zed camera runtime parameters"), Category = "Zed|Camera")
	void SetRuntimeParameters(const FSlRuntimeParameters& NewRuntimeParameters);

	/*
	 * Set the object detection runtime parameters
	 * @param NewObjectDetectionRuntimeParameters The object detection runtime parameters
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set zed camera object detection runtime parameters"), Category = "Zed|Object Detection")
	void SetObjectDetectionRuntimeParameters(const FSlObjectDetectionRuntimeParameters& NewObjectDetectionRuntimeParameters);

	/*
	 * Set the body tracking runtime parameters
	 * @param NewBodyTrackingRuntimeParameters The body tracking runtime parameters
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set zed camera body tracking runtime parameters"), Category = "Zed|Body Tracking")
	void SetBodyTrackingRuntimeParameters(const FSlBodyTrackingRuntimeParameters& NewBodyTrackingRuntimeParameters);

	/*
	 * Get the camera informations
	 * @param CustomResolution		   Custom resolution to retrieve the information. Set to FIntPoint(0, 0) to retrieve current camera informations.
	 * @return CurrentCameraInformation The current camera information
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed camera information"), Category = "Zed|Camera")
	FSlCameraInformation GetCameraInformation(const FIntPoint& CustomResolution);

	/*
	 * Enable the tracking of the Zed camera asynchronously
	 * @param NewTrackingParameters The parameters to enable the tracking with
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "enable zed tracking"), Category = "Zed|Tracking")
	void EnableTracking(const FSlPositionalTrackingParameters& NewTrackingParameters);

	/*
	 * Disable the tracking of the Zed camera
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "disable zed tracking"), Category = "Zed|Tracking")
	void DisableTracking();

	/*
	 * Reset the tracking of the Zed camera. will  flush the area database built/loaded.
	 * @param Rotation The new initial rotation
	 * @param Location The new initial location
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "reset zed tracking"), Category = "Zed|Tracking")
	void ResetTracking(const FRotator& Rotation, const FVector& Location);

	/*
	 * Get the current pose
	 * @param Pose			 The current pose
	 * @parem ReferenceFrame The reference frame, world or camera
	 * @return				 The tracking state
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed pose"), Category = "Zed|Tracking")
	ESlTrackingState GetPosition(FSlPose& Pose, ESlReferenceFrame ReferenceFrame);

	/*
	 * Get the current IMU data
	 * @param IMUData The current IMU data
	 * @return  		 The error code
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed imud ata"), Category = "Zed|Tracking")
	ESlErrorCode GetIMUData(FSlIMUData& IMUData, ESlTimeReference TimeReference);

	/*
	 * Set IMU rotation prior
	 * @param Transform The transform containing the rotation
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set zed imu prior"), Category = "Zed|Tracking")
	void SetIMUPrior(const FTransform& Transform);

	/*
	 * @return True if tracking enabled
	 */
	UFUNCTION(BlueprintPure, Category = "Zed|Tracking")
	bool IsTrackingEnabled();

	/*
	 * Save the tracking area
	 * @param AreaSavingPath The path to save the tracking area
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Tracking")
	bool SaveSpatialMemoryArea(const FString& AreaSavingPath);

	/*
	 * @return The spatial memory export state
	 */
	UFUNCTION(BlueprintPure, Category = "Zed|Tracking")
	ESlSpatialMemoryExportingState GetSpatialMemoryExportState();

	/*
	 * Enable Zed spatial mapping
	 * @param SpatialMappingParameters The spatial mapping parameter to use
	 * @return True is spatial mapping enabled
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "enable zed spatial mapping"), Category = "Zed|Scanning")
	bool EnableSpatialMapping(const FSlSpatialMappingParameters& SpatialMappingParameters);

	/*
	 * Disable Zed spatial mapping
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "disable zed spatial mapping"), Category = "Zed|Scanning")
	void DisableSpatialMapping();

	/*
	 * Pause Zed spatial mapping
	 * @param bPause True to pause, false to resume
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "pause zed spatial mapping"), Category = "Zed|Scanning")
	void PauseSpatialMapping(bool bPause);

	/*
	 * Passthrough function for requestMeshAsync
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "request zed mesh async"), Category = "Zed|Scanning")
	void RequestMeshAsync();

	/*
	 * Passthrough function for getMeshIsReadyAsync
	 * @return True if the mesh is ready 
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "get zed mesh is ready"), Category = "Zed|Scanning")
	bool GetMeshIsReadyAsync();

	/*
	 * Passthrough function for retrieveMeshAsync
	 * @param Mesh The mesh to retrieve
	 * @return true if the mesh is retrieved
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "retrieve zed mesh async"), Category = "Zed|Scanning")
	bool RetrieveMeshAsync(USlMesh* Mesh);
		
	/*
	 * Extract the mesh. This is therefore a blocking function. Update the mesh after calling this function.
	 * @param Mesh The mesh to fill
	 * @return	   True if the mesh is available 
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "extract zed whole mesh"), Category = "Zed|Scanning")
	bool ExtractWholeMesh(USlMesh* Mesh);

	/*
	 * Retrieve a view/measure texture
	 * @param Texture The texture to retrieve
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "retrieve zed texture"), Category = "Zed|Rendering")
	bool RetrieveTexture(class USlTexture* Texture);

	/*
	 * Retrieve a view mat
	 * @param Mat		 The mat to store the result
	 * @param ViewType	 The view type to retrieve
	 * @param MemoryType The memory type of the retrieve
	 * @param Resolution The resolution of the mat
	 * @param Name		 The name of the mat
	 * @return True if the retrieve returned sl::SUCCESS
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "retrieve zed image"), Category = "Zed|Rendering")
	bool RetrieveImage(UPARAM(ref) FSlMat& Mat, ESlView ViewType, ESlMemoryType MemoryType, const FIntPoint& Resolution, ESlViewFormat ViewFormat);

	/*
	* Retrieve a measure mat
	* @param Mat		 The mat to store the result
	* @param MeasureType The measure type to retrieve
	* @param MemoryType  The memory type of the retrieve
	* @param Resolution  The resolution of the mat
	* @param Name		 The name of the mat
	* @return True if the retrieve returned sl::SUCCESS
	*/
	UFUNCTION(BlueprintCallable, meta = (Keywords = "retrieve zed measure"), Category = "Zed|Rendering")
	bool RetrieveMeasure(UPARAM(ref) FSlMat& Mat, ESlMeasure MeasureType, ESlMemoryType MemoryType, const FIntPoint& Resolution);

	/*
	 * Retrieve a view mat
	 * @param Mat	     The mat to store the result
	 * @param ViewType	 The view type to retrieve
	 * @param MemoryType The memory type of the retrieve
	 * @param Resolution The resolution of the mat
	 * @param Name		 The name of the mat
	 * @return True if the retrieve returned sl::SUCCESS
	 */
	bool RetrieveImage(void* Mat, ESlView ViewType, ESlMemoryType MemoryType, const FIntPoint& Resolution, ESlViewFormat ViewFormat);

	/*
	 * Retrieve a measure mat
	 * @param Mat		  The mat to store the result
	 * @param MeasureType The measure type to retrieve
	 * @param MemoryType  The memory type of the retrieve
	 * @param Resolution  The resolution of the mat
	 * @param Name		  The name of the mat
	 * @return True if the retrieve returned sl::SUCCESS
	 */
	bool RetrieveMeasure(void* Mat, ESlMeasure MeasureType, ESlMemoryType MemoryType, const FIntPoint& Resolution);

	/*
	 * Retrieve the depth at the screen position
	 * @param ViewportHelper    The viewport helper of the current view
	 * @param ScreenPositions   The screen position to check
	 * @return Depth		    The depth
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth"), Category = "Zed|Rendering")
	float GetDepth(const FSlViewportHelper& ViewportHelper, const FIntPoint& ScreenPosition);

	/*
	 * Retrieve the depths at the screen positions
	 * @param ViewportHelper The viewport helper of the current view
	 * @param ScreenPositions  The screen positions to check
	 * @return Depths		   The depths
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth"), Category = "Zed|Rendering")
	TArray<float> GetDepths(const FSlViewportHelper& ViewportHelper, const TArray<FIntPoint>& ScreenPositions);

	/*
	 * Retrieve the normal at the screen position
	 * @param ViewportHelper   The viewport helper of the current view
	 * @param ScreenPositions  The screen position to check
	 * @return Normal	       The normal associated
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth"), Category = "Zed|Rendering")
	FVector GetNormal(const FSlViewportHelper& ViewportHelper, const FIntPoint& ScreenPosition);

	/*
	 * Retrieve the normals at the screen positions
	 * @param ViewportHelper   The viewport helper of the current view
	 * @param ScreenPositions  The screen positions to check
	 * @param Normals		   The normals
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth"), Category = "Zed|Rendering")
	TArray<FVector> GetNormals(const FSlViewportHelper& ViewportHelper, const TArray<FIntPoint>& ScreenPositions);

	/*
	* Retrieve the depth and normal at the screen position
    * @param ViewportHelper   The viewport helper of the current view
	* @param ScreenPositions  The screen position to check
	* @param Normal	          The normal associated. If the normal = 0, it is not valid.
	*/
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth"), Category = "Zed|Rendering")
	void GetDepthAndNormal(const FSlViewportHelper& ViewportHelper, const FIntPoint& ScreenPosition, float& Depth, FVector& Normal);

	/*
	 * Retrieve the depths and normals at the screen position
	 * @param ViewportHelper   The viewport helper of the current view
	 * @param ScreenPositions  The screen position to check
	 * @param Normal	       The normal associated. If the normal = 0, it is not valid.
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth"), Category = "Zed|Rendering")
	void GetDepthsAndNormals(const FSlViewportHelper& ViewportHelper, const TArray<FIntPoint>& ScreenPositions, TArray<float>& Depths, TArray<FVector>& Normals);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "optimize AI Model"), Category = "Zed|AI")
	void OptimizeAIModel(const ESlAIModels& AIModel);

	/*
	 * Enable Zed Object Detection module
	 * @param ObjectDetectionParameters The object detection parameters to use
	 * @return True is object detection enabled
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "enable zed Object detection"), Category = "Zed|Object Detection")
	bool EnableObjectDetection(const FSlObjectDetectionParameters& ObjectDetectionParameters);

	/*
	 * Enable Zed Body Tracking module
	 * @param BodyTrackingParameters The body tracking parameters to use
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "enable zed body tracking"), Category = "Zed|Body Tracking")
	bool EnableBodyTracking(const FSlBodyTrackingParameters& BodyTrackingParameters);

	/*
	 * Tell if the Object detection module is enabled.
	 * @return True is object detection is enabled
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "is object detection enabled"), Category = "Zed|Object Detection")
	bool IsObjectDetectionEnabled();

	/*
	 * Tell if the Body Tracking module is enabled.
	 * @return True is Body Tracking is enabled
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "is Body Tracking enabled"), Category = "Zed|Body Tracking")
	bool IsBodyTrackingEnabled();

	/*
	 * Disable Zed Object Detection module
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "disable zed Object detection"), Category = "Zed|Object Detection")
	void DisableObjectDetection();

	/*
	 * Disable Zed Body Tracking module
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "disable zed Body Tracking"), Category = "Zed|Body Tracking")
	void DisableBodyTracking();

	/*
	 * Retrieve objects detected by the object detection module.
	 * @return True if returned sl::SUCCESS
	 */
	bool RetrieveObjects();

	/*
	 * Retrieve bodies detected by the body tracking module.
	 * @return True if returned sl::SUCCESS
	 */
	bool RetrieveBodies();

	/*
	 * Call this function to get the current error of the open camera async task.
	 * @return The current error code
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed async status"), Category = "Zed|Initialization")
	ESlErrorCode GetOpenCameraErrorCode();

	/*
	 * Toggle hit test depth and normals
	 * @param bEnableDepth   True to enable hit test depth
	 * @param bEnableNormals True to enable hit test normals
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set hit test depth normals"), Category = "Zed|Rendering")
	void SetHitTestDepthAndNormals(bool bEnableDepth, bool bEnableNormals);

	/*
	 * Start/Stop the hit test thread
	 * @param bEnabled True to start
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "enable hit test"), Category = "Zed|Rendering")
	void EnableHitTest(bool bEnabled);

	/*
	 * Enable SVO recording
	 * @param RecordingParameters     Recording Parameters
	 * @return The error code
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "enable svo recording"), Category = "Zed|SVO")
	ESlErrorCode EnableSVORecording(FSlRecordingParameters RecordingParameters);

	/*
	 * Disable SVO recording
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "disable svo recording"), Category = "Zed|SVO")
	void DisableSVORecording();

	/*
	 * Set the SVO playback position
	 * @param Position The new position
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set svo playback position"), Category = "Zed|SVO")
	void SetSVOPlaybackPosition(int Position);

	/*
	 * Get the current SVO playback position
	 * @return the playback position
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get svo playback position"), Category = "Zed|SVO")
	int GetSVOPlaybackPosition();

	/*
	 * Pause SVO playback at current frame
	 * @param bPause True to pause, false to resume
	 * @param NewSVOPosition Pause the SVO a the new position or the current if set to -1
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "pause svo playback"), Category = "Zed|SVO")
	void PauseSVOplayback(bool bPause, int NewSVOPosition = -1);

	/*
	 * Loop SVO playback
	 * @param bLoop True to loop, false to stop looping
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set looping svo playback"), Category = "Zed|SVO")
	void SetSVOPlaybackLooping(bool bLoop);

	/*
	 * Record SVO frames
	 * @param bRecord True to record, false to stop
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set looping svo playback"), Category = "Zed|SVO")
	void SetSVORecordFrames(bool bRecord);

	/*
	 * Get the current SVO number of frames
	 * @return the number of frames
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get svo number of frames"), Category = "Zed|SVO")
	int GetSVONumberOfFrames();

	/*
	 * Return the current recording state if recording is done automatically
	 * @return The current recording state
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get svo recording state"), Category = "Zed|SVO")
	FSlRecordingState GetSVORecordingState();

	/*
	 * Push the cuda context
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "push zed cuda context"), Category = "Zed|Camera")
	void PushCudaContext();

	/*
	 * Pop the cuda context
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "pop zed cuda context"), Category = "Zed|Camera")
	void PopCudaContext();
	
	/*
	 * @return the confidence threshold
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed confidence threshold"), Category = "Zed|Camera")
	int32 GetConfidenceThreshold();

	/*
	 * Set the confidence threshold
	 * @param NewConfidenceThreshold The new confidence threshold in range [1, 100]
	 */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "set zed confidence threshold"), Category = "Zed|Camera")
	void SetConfidenceThreshold(int32 NewConfidenceThreshold);

	/*
	 * Returns the current maximum distance of depth estimation
	 * @return The current maximum distance that can be computed
	*/
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth max range value"), Category = "Zed|Camera")
	float GetDepthMaxRangeValue();

	/*
	 * @return the closest measurable distance by the camera, according to the camera and the depth map parameters.
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed depth min range value"), Category = "Zed|Camera")
	float GetDepthMinRangeValue();

	/*
	 * @return The current FPS (or recorded FPS for SVO). Return -1.f if something goes wrong.
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed fps"), Category = "Zed|Camera")
	float GetCameraFPS();

	/*
	 * It is based on the difference of camera timestamps between two successful grab().
	 * @return The current FPS of the thread calling grab()
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed current fps"), Category = "Zed|Camera")
	float GetCurrentFPS();

	/*
	 * Returns the number of frame dropped since \ref grab has been called for the first time.
	 * Based on camera timestamp and FPS comparison.
	 * @return The number of frame dropped since first grab call.
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed frame drop count"), Category = "Zed|Camera")
	float GetFrameDroppedCount();


	/*
	 * @return The camera model
	 */
	UFUNCTION(BlueprintPure, meta = (Keywords = "get zed camera model"), Category = "Zed|Camera")
	FORCEINLINE ESlModel GetCameraModel()
	{
		return CameraInformation.CameraModel;
	}

private:
	/*
	 * Initialize the ZED camera.
	 * @param FZEDInitParameters Init parameters of the ZED camera.
	 */
	void Internal_OpenCamera(const FSlInitParameters& InitParameters);

	/*
	 * Enable the tracking of the ZED camera
	 * @param NewTrackingParameters The parameters to enable the tracking with
	 */
	void Internal_EnableTracking(const FSlPositionalTrackingParameters& NewTrackingParameters);

	void Internal_OptimizeAIModel(const ESlAIModels& AIModel);

	// ------------------------------------------------------------------

public:
	/*
 	 * @return camera id. The camera may be closed.
 	 */
	int GetCameraID();

	/*
	 * Perform a grab with the current runtime parameters
	 */
	void Grab();

	/*
	* Check if the AI model used is optimized or not
	*/
	bool CheckAIModelOptimization(const ESlAIModels AiModel);

	/*
	* Easy access to sl::Pose
	*/
	SL_POSITIONAL_TRACKING_STATE GetCameraPosition(SL_PoseData* pose, SL_REFERENCE_FRAME rframe);

	/*
	* Easy access to IMU pose
	*/
	SL_ERROR_CODE GetCameraIMURotationAtImage(sl::Rotation& pose);

	/*
	 * Add a function to the grab delegate.
	 * Be sure to call RemoveFromGrabDelegate.
	 *
	 * @param Lambda The lambda function to add
	 * @return		 The delegate handle
	 */
	FDelegateHandle AddToGrabDelegate(TFunction<void(ESlErrorCode, const FSlTimestamp&)> Lambda);

	/*
	 * Remove handle from the grab delegate
	 */
	void RemoveFromGrabDelegate(FDelegateHandle& Handle);

	/*
	 * Add a function to the grab delegate in blueprint.
	 * Be sure to call RemoveFromGrabDelegate.
	 *
	 * @param Object The object that inherits from IGrabCallbackInterface
	 * @return		 The delegate handle
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "AddToGrabDelegate", meta = (Keywords = "add to zed grab"), Category = "Zed|Camera")
	FGrabDelegateHandle BP_AddToGrabDelegate(UObject* Object);

	/*
	 * Remove handle from the grab delegate in blueprint
	 *
	 * @param GrabDelegateHandle The handle to remove
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "RemoveFromGrabDelegate", meta = (Keywords = "remove from zed grab"), Category = "Zed|Camera")
	void BP_RemoveFromGrabDelegate(FGrabDelegateHandle GrabDelegateHandle);

	/*
	 * Enable/disable the grab thread
	 * @param bEnable True to enable
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Camera")
	void EnableGrabThread(bool bEnable);

	/*
	 * Enable/disable the AI thread
	 * @param bEnable True to enable
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Camera")
	void EnableObjectDetectionThread(bool bEnable);

	/*
	 * Enable/disable the AI thread
	 * @param bEnable True to enable
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Camera")
	void EnableBodyTrackingThread(bool bEnable);

	// ------------------------------------------------------------------

private:
	/*
	 * Set async status
	 */
	void SetOpenCameraErrorCode(ESlErrorCode ErrorCode);


	// ------------------------------------------------------------------

public:
	/** Camera information after initialization */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	FSlCameraInformation CameraInformation;

	/** Left camera parameters for retrieve depth/normals */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	FSlCameraParameters RetrieveLeftCameraParameters;

	/** X offset relative to the center of the HMD */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	float HMDToCameraOffset;

	/** True if tracking enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bTrackingEnabled;

	/** True if spatial memory is currently enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSpatialMemoryEnabled;

	/** True if spatial memory is currently enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSpatialMappingEnabled;

	/** True if object detection is currently enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bObjectDetectionEnabled;

	/** True if body tracking is currently enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bBodyTrackingEnabled;

	/** True if hit test should return depth */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bHitTestDepthEnabled;

	/** True if hit tests should return normal */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bHitTestNormalsEnabled;

	/** True if SVO playback is enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSVOPlaybackEnabled;

	/** True if SVO recording is enabled */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSVORecordingEnabled;

	/** True if SVO is recording frames*/
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSVORecordingFrames;

	/** True if SVO playback is paused */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSVOPlaybackPaused;

	/** True if SVO is looping */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	bool bSVOLooping;

	/** Mat size of retrieve depth/normal for hit tests */
	UPROPERTY(BlueprintReadOnly, Category = "Zed")
	FIntPoint RetrieveMatSize;

	UPROPERTY(BlueprintReadOnly, Category = "Zed|Object Detection")
	FSlObjects objects;


	UPROPERTY(BlueprintReadOnly, Category = "Zed|Body Tracking")
	FSlBodies bodies;

public:
	/** Broadcast after the AI model is optimized*/
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnAIModelOptimized;

	/** Camera opened event dispatcher. Broadcast after the camera is opened. */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnCameraOpened;

	/** Camera closed event dispatcher. Broadcast before the camera is closed, but IsCameraOpened() will return false. */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnCameraClosed;

	/** Camera disconnected event dispatcher. Broadcast after camera disconnected. */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnCameraDisconnected;

	/** Tracking enabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyTrackingDelegate OnTrackingEnabled;

	/** Tracking disabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnTrackingDisabled;

	/** Tracking reset event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyTrackingDelegate OnTrackingReset;
	
	/** Grab enabled/disabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyOneParamDelegate OnGrabThreadEnabled;

	/** Hit test thread enabled/disabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyOneParamDelegate OnHitTestThreadEnabled;

	/** Spatial mapping enabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyTwoParamsDelegate OnSpatialMappingEnabled;

	/** Spatial mapping disabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnSpatialMappingDisabled;

	/** Spatial mapping paused/resumed event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxySpatialMappingPausedDelegate OnSpatialMappingPaused;

	/** Object detection enabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyTwoParamsDelegate OnObjectDetectionEnabled;

	/** Object detection retrieve event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyRetrieveObjectsDelegate OnObjectDetectionRetrieved;

	/** Body Tracking enabled event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyTwoParamsDelegate OnBodyTrackingEnabled;

	/** Body Tracking retrieve event dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyRetrieveBodiesDelegate OnBodyTrackingRetrieved;

	/** End of SVO has been reached and looping is enabled */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnSVOLooping;

	/** SVO position was set back in time */
	UPROPERTY(BlueprintAssignable, Category = "Zed")
	FSlCameraProxyDelegate OnSVOSetBackInTime;
	
private:
	/** Grab done event dispatcher */
	FSlCameraProxyGrabDelegate OnGrabDoneDelegate;

private:
	/** Open camera task */
	FAsyncTask<class FOpenCameraAsyncTask>* OpenCameraAsyncTask;

	/** Enable tracking task */
	FAsyncTask<class FEnableTrackingAsyncTask>* EnableTrackingAsyncTask;

	/** AI Model optimization async task */
	FAsyncTask<class FAIOptimizationAsyncTask>* AIOptimizationAsyncTask;

private:
	/** The status of the current async task */
	ESlErrorCode OpenCameraErrorCode;

	/** Section to synchronize get/set of the async status */
	FCriticalSection AsyncStatusSection;

	/** Section to access grab delegates */
	FCriticalSection GrabDelegateSection;

	/** Section to synchronize with grab */
	FCriticalSection GrabSection;

	/** Section to synchronize with SVO controls */
	FCriticalSection SVOSection;

	/** True to abandon the open camera task */
	FThreadSafeBool bAbandonOpenTask;

private:
	/** Runtime parameters */
	SL_RuntimeParameters RuntimeParameters;

	/** OD parameters */
	FSlObjectDetectionParameters ObjectDetectionParameters;

	/** Runtime parameters */
	SL_ObjectDetectionRuntimeParameters ObjectDetectionRuntimeParameters;

	/** BT parameters */
	FSlBodyTrackingParameters BodyTrackingParameters;

	/** Runtime parameters */
	SL_BodyTrackingRuntimeParameters BodyTrackingRuntimeParameters;
private:
	/** A worker to thread the Grab calls */
	class FSlGrabRunnable* GrabWorker;

	/** A worker to thread CPU depth get calls */
	class FSlMeasureRunnable* MeasuresWorker;

	/** A worker to thread OD */
	class FSlObjectDetectionRunnable* ObjectDetectionWorker;

	/** A worker to thread BT */
	class FSlBodyTrackingRunnable* BodyTrackingWorker;

private:
	/** True if camera opened by OpenCamera */
	bool bCameraOpened;

	/** True if grab enabled */
	FThreadSafeBool bGrabEnabled;

	/** True if gain and exposure are automatically set. This value is set based on the value set when calling SetCameraSettings(). */
	bool bAutoGainAndExposure;

	/** Current frame in SVO playback */
	int CurrentSVOPlaybackPosition;

	/** Recording state */
	SL_RecordingStatus* SlRecordingStatus;

	/** Camera informations needed if camera disconnected */
	SL_CameraInformation* SlCameraInformation;

	/** Pointer to image grabbed. Used internally.*/
	void* UnsignedLeftImage;

private:
	/** Underlying Zed camera */
	//sl::Camera Zed;

	int CameraID;

	SL_INPUT_TYPE InputType;

	/** Underlying sensors data (imu, ...)
	* One for current ts, one for image ts.
	*/
	SL_SensorsData CurrentSensorsData;
	SL_SensorsData ImageRefSensorsData;
	SL_ERROR_CODE IMUErrorCode;
};