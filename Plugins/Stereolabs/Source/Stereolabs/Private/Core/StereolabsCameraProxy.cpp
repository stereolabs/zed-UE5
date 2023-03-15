//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Private/Threading/StereolabsGrabRunnable.h"
#include "Stereolabs/Private/Threading/StereolabsMeasureRunnable.h"
#include "Stereolabs/Private/Threading/StereolabsAIDetectionRunnable.h"
#include "Stereolabs/Public/Core/StereolabsTexture.h"
#include "Blueprint/WidgetLayoutLibrary.h"

DECLARE_CYCLE_STAT_EXTERN(TEXT("Grab"), STAT_Grab, STATGROUP_ZED, STEREOLABS_API);
DECLARE_CYCLE_STAT_EXTERN(TEXT("RetrieveMeasure"), STAT_RetrieveMeasure, STATGROUP_ZED, STEREOLABS_API);
DECLARE_CYCLE_STAT_EXTERN(TEXT("RetrieveImage"), STAT_RetrieveImage, STATGROUP_ZED, STEREOLABS_API);

DEFINE_STAT(STAT_Grab)
DEFINE_STAT(STAT_RetrieveMeasure)
DEFINE_STAT(STAT_RetrieveImage)

DEFINE_LOG_CATEGORY(SlCameraProxy);
#define SL_CAMERA_PROXY_LOG(Format, ...) SL_LOG(SlCameraProxy, Format, ##__VA_ARGS__)
#define SL_CAMERA_PROXY_LOG_W(Format, ...) SL_LOG_W(SlCameraProxy, Format, ##__VA_ARGS__)
#define SL_CAMERA_PROXY_LOG_E(Format, ...) SL_LOG_E(SlCameraProxy, Format, ##__VA_ARGS__)
#define SL_CAMERA_PROXY_LOG_F(Format, ...) SL_LOG_F(SlCameraProxy, Format, ##__VA_ARGS__)

void CreateSlCameraProxyInstance()
{
	check(IsInGameThread());

	if (!GSlCameraProxy)
	{
		GSlCameraProxy = NewObject<USlCameraProxy>();
		GSlCameraProxy->AddToRoot();
	}
}

void FreeSlCameraProxyInstance()
{
	check(IsInGameThread());

	if (GSlCameraProxy)
	{
		GSlCameraProxy->ConditionalBeginDestroy();
		GSlCameraProxy = nullptr;
	}
}

UGrabCallbackInterface::UGrabCallbackInterface(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

class FOpenCameraAsyncTask : public FNonAbandonableTask
{
	friend class FAsyncTask<FOpenCameraAsyncTask>;

public:
	FOpenCameraAsyncTask( const FSlInitParameters& InitParameters)
		:
		InitParameters(InitParameters)
	{}

protected:
	void DoWork()
	{
		SL_CAMERA_PROXY_LOG_W("Waiting for ZED to be connected");

		while (!USlCameraProxy::IsCameraConnected() && !GSlCameraProxy->bAbandonOpenTask)
		{
			GSlCameraProxy->SetOpenCameraErrorCode(ESlErrorCode::EC_CameraNotDetected);

			FPlatformProcess::SleepNoStats(0.01f);
		}

		if (!GSlCameraProxy->bAbandonOpenTask)
		{
			SL_CAMERA_PROXY_LOG_W("ZED connected");
			GSlCameraProxy->SetOpenCameraErrorCode(ESlErrorCode::EC_None);

			GSlCameraProxy->Internal_OpenCamera(InitParameters);
		}
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FOpenCameraAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

protected:
	FSlInitParameters InitParameters;
};

class FEnableTrackingAsyncTask : public FNonAbandonableTask
{
	friend class FAsyncTask<FEnableTrackingAsyncTask>;

public:
	FEnableTrackingAsyncTask(const FSlPositionalTrackingParameters& TrackingParameters)
		:
		TrackingParameters(TrackingParameters)
	{}

protected:
	void DoWork()
	{
		GSlCameraProxy->Internal_EnableTracking(TrackingParameters);
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FEnableTrackingAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

protected:
	FSlPositionalTrackingParameters TrackingParameters;
};

class FAIOptimizationAsyncTask : public FNonAbandonableTask
{
	friend class FAsyncTask<FAIOptimizationAsyncTask>;

public:
	FAIOptimizationAsyncTask(const ESlAIModels& AIModel)
		:
		AIModel(AIModel)
	{}

protected:
	void DoWork()
	{
		GSlCameraProxy->Internal_OptimizeAIModel(AIModel);
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FAIOptimizationAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}

protected:
	ESlAIModels AIModel;
};

USlCameraProxy::USlCameraProxy()
	:
	HMDToCameraOffset(0.0f),
	bTrackingEnabled(false),
	bSpatialMemoryEnabled(false),
	bSpatialMappingEnabled(false),
	bHitTestDepthEnabled(true),
	bHitTestNormalsEnabled(true),
	bSVOPlaybackEnabled(false),
	bSVORecordingEnabled(false),
	bSVORecordingFrames(false),
	bSVOPlaybackPaused(false),
	bSVOLooping(false),
	RetrieveMatSize(GetSlTextureSizeFromPreset(0)),
	OpenCameraAsyncTask(nullptr),
	EnableTrackingAsyncTask(nullptr),
	AIOptimizationAsyncTask(nullptr),
	OpenCameraErrorCode(ESlErrorCode::EC_None),
	bAbandonOpenTask(false),
	GrabWorker(nullptr),
	MeasuresWorker(nullptr),
	bCameraOpened(false),
	bGrabEnabled(false),
	bAutoGainAndExposure(true),
	CameraID(0)
{
}

void USlCameraProxy::BeginDestroy()
{
	// Disable grab thread
	if (GrabWorker)
	{
		GrabWorker->EnsureCompletion();
		delete GrabWorker;
		GrabWorker = nullptr;

		if (UnsignedLeftImage != nullptr) sl_mat_free(UnsignedLeftImage, SL_MEM_GPU);
	}

	// Disable measures thread
	if (MeasuresWorker)
	{
		MeasuresWorker->EnsureCompletion();
		delete MeasuresWorker;
		MeasuresWorker = nullptr;
	}

	// Disable ai thread
	if (ObjectDetectionWorker)
	{
		ObjectDetectionWorker->EnsureCompletion();
		delete ObjectDetectionWorker;
		ObjectDetectionWorker = nullptr;
	}

	// Disable ai thread
	if (BodyTrackingWorker)
	{
		BodyTrackingWorker->EnsureCompletion();
		delete BodyTrackingWorker;
		BodyTrackingWorker = nullptr;
	}


	CloseCamera();
	Super::BeginDestroy();
}

FString USlCameraProxy::GetSDKVersion()
{
	return FString(sl_get_sdk_version());
}

void USlCameraProxy::OpenCamera(const FSlInitParameters& InitParameters)
{
	if (OpenCameraAsyncTask)
	{
		return;
	}
	else if (sl_is_opened(CameraID))
	{
		AsyncTask(ENamedThreads::GameThread, [this] ()
		{
			SL_CAMERA_PROXY_LOG_W("ZED camera already opened");
		});

		return;
	}

	OpenCameraAsyncTask = new FAsyncTask<FOpenCameraAsyncTask>(InitParameters);
	OpenCameraAsyncTask->StartBackgroundTask();
}

void USlCameraProxy::Internal_OpenCamera(const FSlInitParameters& InitParameters)
{
	SL_CAMERA_PROXY_LOG("Initializing");

	SL_InitParameters sl_init_parameters;

	sl_init_parameters.input_type = (SL_INPUT_TYPE)InitParameters.InputType;
	sl_init_parameters.camera_device_id = CameraID;
	sl_init_parameters.camera_disable_self_calib = InitParameters.bDisableSelfCalibration;
	sl_init_parameters.camera_fps = InitParameters.FPS;
	sl_init_parameters.camera_image_flip = (SL_FLIP_MODE)InitParameters.VerticalFlipImage;
	sl_init_parameters.resolution = (SL_RESOLUTION)InitParameters.Resolution;
	sl_init_parameters.coordinate_system = SL_COORDINATE_SYSTEM_LEFT_HANDED_Z_UP;
	sl_init_parameters.coordinate_unit = SL_UNIT_CENTIMETER;
	sl_init_parameters.depth_minimum_distance = InitParameters.DepthMinimumDistance;
	sl_init_parameters.depth_maximum_distance = InitParameters.DepthMaximumDistance;
	sl_init_parameters.depth_mode = (SL_DEPTH_MODE)InitParameters.DepthMode;
	sl_init_parameters.enable_right_side_measure = InitParameters.bEnableRightSideMeasure;
	sl_init_parameters.sdk_gpu_id = FMath::FloorToInt(InitParameters.GPUID);
	sl_init_parameters.sdk_verbose = InitParameters.bVerbose;
	sl_init_parameters.depth_stabilization = InitParameters.DepthStabilization;
	sl_init_parameters.enable_image_enhancement = InitParameters.bEnableImageEnhancement;
	sl_init_parameters.sensors_required = InitParameters.bSensorsRequired;
	sl_init_parameters.enable_right_side_measure = InitParameters.bEnableRightSideMeasure;
	sl_init_parameters.svo_real_time_mode = InitParameters.bRealTime;
	sl_init_parameters.async_grab_camera_recovery = InitParameters.bAsyncGrabCameraRecovery;
	sl_init_parameters.open_timeout_sec = InitParameters.OpenTimeoutSec;

	InputType = (SL_INPUT_TYPE)InitParameters.InputType;
	bool IsCameraCreated = sl_create_camera(CameraID);

	SL_ERROR_CODE ErrorCode;
	do
	{
		ErrorCode = (SL_ERROR_CODE)sl_open_camera(CameraID, &sl_init_parameters, InitParameters.SerialNumber, TCHAR_TO_UTF8(*InitParameters.SvoPath), TCHAR_TO_UTF8(*InitParameters.StreamIP),
			InitParameters.StreamPort, TCHAR_TO_UTF8(*InitParameters.VerboseFilePath), TCHAR_TO_UTF8(*InitParameters.OptionalSettingPath),
				TCHAR_TO_UTF8(*InitParameters.OptionalOpencvCalibrationFile));

		SetOpenCameraErrorCode(sl::unreal::ToUnrealType(ErrorCode));

		if (ErrorCode != SL_ERROR_CODE_SUCCESS)
		{
			SL_CAMERA_PROXY_LOG_E("Error during initialization: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
			
			if (ErrorCode != SL_ERROR_CODE_CAMERA_NOT_DETECTED &&
				ErrorCode != SL_ERROR_CODE_SENSORS_NOT_AVAILABLE)
			{
				bAbandonOpenTask = true;
			}
		}

		FPlatformProcess::Sleep(0.01f);
	} while (ErrorCode != SL_ERROR_CODE_SUCCESS && !bAbandonOpenTask);

	if (bAbandonOpenTask)
	{
		AsyncTask(ENamedThreads::GameThread, [this] ()
		{
			SL_CAMERA_PROXY_LOG_W("Not initialized");
		});

		return;
	}

	SetOpenCameraErrorCode(ESlErrorCode::EC_None);

	AsyncTask(ENamedThreads::GameThread, [this, InitParameters]()
	{
		if (!GSlCameraProxy)
		{
			return;
		}

		if (InitParameters.InputType == ESlInputType::IT_SVO)
		{
			bSVOPlaybackEnabled = true;
		}

		SlCameraInformation = sl_get_camera_information(CameraID, 0, 0);
		CameraInformation = sl::unreal::ToUnrealType(*SlCameraInformation);
		SL_CameraParameters leftCameraParameters = sl_get_camera_information(CameraID, RetrieveMatSize.X, RetrieveMatSize.Y)->camera_configuration.calibration_parameters.left_cam;
		RetrieveLeftCameraParameters = sl::unreal::ToUnrealType(leftCameraParameters);

		GSlEyeHalfBaseline = CameraInformation.HalfBaseline;

		OpenCameraAsyncTask->EnsureCompletion(false);

		delete OpenCameraAsyncTask;
		OpenCameraAsyncTask = nullptr;

		SL_CAMERA_PROXY_LOG("Initialized");

		CUresult Result = cuCtxSetCurrent(sl_get_cuda_context(CameraID));

		if (Result != CUresult::CUDA_SUCCESS)
		{
			UE_LOG(LogTemp, Warning, TEXT("Can't set current CUDA context"));
		}
		bCameraOpened = true;

		OnCameraOpened.Broadcast();

		bGrabEnabled = true;
	});
}

void USlCameraProxy::CloseCamera()
{
	// Disable grab
	bGrabEnabled = false;

	bTrackingEnabled = false;
	bSpatialMappingEnabled = false;

	// Still trying to open the camera
	if (OpenCameraAsyncTask && !OpenCameraAsyncTask->IsDone())
	{
		bAbandonOpenTask = true;

		OpenCameraAsyncTask->EnsureCompletion(false);

		delete OpenCameraAsyncTask;
		OpenCameraAsyncTask = nullptr;
	}

	// Still trying to enable tracking
	if (EnableTrackingAsyncTask && !EnableTrackingAsyncTask->IsDone())
	{
		EnableTrackingAsyncTask->EnsureCompletion(false);

		delete EnableTrackingAsyncTask;
		EnableTrackingAsyncTask = nullptr;
	}

	if (bCameraOpened)
	{
		bCameraOpened = false;

		// Wait for current frame
		FlushRenderingCommands();

		// Disable grab thread
		if (GrabWorker)
		{
			EnableGrabThread(false);
		}

		// Disable AI thread
		if (ObjectDetectionWorker)
		{
			EnableObjectDetectionThread(false);
		}

		// Disable AI thread
		if (BodyTrackingWorker)
		{
			EnableBodyTrackingThread(false);
		}

		// Disable measures thread
		if (MeasuresWorker)
		{
			EnableHitTest(false);
		}

		// Reset data
		CameraInformation = FSlCameraInformation();

		// Broadcast
		OnCameraClosed.Broadcast();
	}

	sl_close_camera(CameraID);


}

void USlCameraProxy::EnableTracking(const FSlPositionalTrackingParameters& NewTrackingParameters)
{
	if (EnableTrackingAsyncTask)
	{
		SL_CAMERA_PROXY_LOG_E("Trying to enable tracking while tracking being enabled");
		return;
	}
	else if (bTrackingEnabled)
	{
		SL_CAMERA_PROXY_LOG_E("Trying to enable tracking but tracking already enabled");
		return;
	}

	EnableTrackingAsyncTask = new FAsyncTask<FEnableTrackingAsyncTask>(NewTrackingParameters);
	EnableTrackingAsyncTask->StartBackgroundTask();
}

void USlCameraProxy::Internal_EnableTracking(const FSlPositionalTrackingParameters& NewTrackingParameters)
{
	SL_ERROR_CODE ErrorCode = SL_ERROR_CODE_FAILURE;
	SL_ERROR_CODE IMUDataErrorCode = SL_ERROR_CODE_FAILURE;

	SL_PositionalTrackingParameters sl_positional_tracking_parameters;

	sl_positional_tracking_parameters.enable_area_memory = NewTrackingParameters.bEnableAreaMemory;
	sl_positional_tracking_parameters.enable_imu_fusion = NewTrackingParameters.bEnableImuFusion;
	sl_positional_tracking_parameters.enable_pose_smothing = NewTrackingParameters.bEnablePoseSmoothing;
	sl_positional_tracking_parameters.initial_world_position = sl::unreal::ToSlType2(NewTrackingParameters.Location);
	sl_positional_tracking_parameters.initial_world_rotation = sl::unreal::ToSlType(NewTrackingParameters.Rotation.Quaternion());
	sl_positional_tracking_parameters.set_as_static = NewTrackingParameters.bSetAsStatic;
	sl_positional_tracking_parameters.set_floor_as_origin = NewTrackingParameters.bSetFloorAsOrigin;
	sl_positional_tracking_parameters.set_gravity_as_origin = NewTrackingParameters.bSetGravityAsOrigin;

	SL_SCOPE_LOCK(Lock, GrabSection)
		ErrorCode = (SL_ERROR_CODE)sl_enable_positional_tracking(CameraID, &sl_positional_tracking_parameters, TCHAR_TO_UTF8(*NewTrackingParameters.AreaFilePath));

		IMUDataErrorCode = (SL_ERROR_CODE)sl_get_sensors_data(CameraID, &CurrentSensorsData, SL_TIME_REFERENCE_CURRENT);
	SL_SCOPE_UNLOCK

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't enable tracking: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
	}

	if (InputType == SL_INPUT_TYPE_USB && IMUDataErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't retrieve IMU Data after enable tracking: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
	}
	SL_Vector3 cam_imu_t;
	SL_Quaternion cam_imu_r;
	sl_get_camera_imu_transform(CameraID, &cam_imu_t, &cam_imu_r);

	sl::Rotation P = sl::Rotation(sl::Orientation(sl::float4(cam_imu_r.x, cam_imu_r.y, cam_imu_r.z, cam_imu_r.w)));

	SL_Quaternion imu_r = CurrentSensorsData.imu.orientation;
	sl::Rotation imu_pose = sl::Rotation(sl::Orientation(sl::float4(imu_r.x, imu_r.y, imu_r.z, imu_r.w)));

	imu_pose.setRotationVector(sl::float3(0,0,0));
	sl::Rotation Pp = P;
	Pp.transpose();
	FRotator IMURotation = sl::unreal::ToUnrealType(P * imu_pose * Pp).Rotator();

	AsyncTask(ENamedThreads::GameThread, [this, ErrorCode, NewTrackingParameters, IMURotation] ()
	{
		if (!GSlCameraProxy)
		{
			return;
		}

		EnableTrackingAsyncTask->EnsureCompletion(false);

		delete EnableTrackingAsyncTask;
		EnableTrackingAsyncTask = nullptr;

		bTrackingEnabled = (ErrorCode == SL_ERROR_CODE_SUCCESS);
		bSpatialMemoryEnabled = NewTrackingParameters.bEnableAreaMemory && bTrackingEnabled;

		OnTrackingEnabled.Broadcast(bTrackingEnabled, sl::unreal::ToUnrealType(ErrorCode), NewTrackingParameters.Location, IMURotation);
	});
}

void USlCameraProxy::DisableTracking()
{
	if (EnableTrackingAsyncTask)
	{
		SL_CAMERA_PROXY_LOG_E("Trying to disable tracking while tracking being enabled");
		return;
	}

	SL_SCOPE_LOCK(Lock, GrabSection)
		if (bTrackingEnabled)
		{
			sl_disable_positional_tracking(CameraID, "");

			bTrackingEnabled = false;
		}
	SL_SCOPE_UNLOCK

	bSpatialMemoryEnabled = false;

	OnTrackingDisabled.Broadcast();
}

void USlCameraProxy::ResetTracking(const FRotator& Rotation, const FVector& Location)
{
	SL_ERROR_CODE ErrorCode;
	SL_ERROR_CODE IMUDataErrorCode;
	SL_SCOPE_LOCK(Lock, GrabSection)
	ErrorCode = (SL_ERROR_CODE)sl_reset_positional_tracking(CameraID, sl::unreal::ToSlType(Rotation.Quaternion()), sl::unreal::ToSlType2(Location));
	IMUDataErrorCode = (SL_ERROR_CODE)sl_get_sensors_data(CameraID, &CurrentSensorsData, SL_TIME_REFERENCE_CURRENT);
	SL_SCOPE_UNLOCK

	bTrackingEnabled = (ErrorCode == SL_ERROR_CODE_SUCCESS);

		if (ErrorCode != SL_ERROR_CODE_SUCCESS)
		{
			SL_CAMERA_PROXY_LOG_E("Can't reset tracking: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		}

		if (IMUDataErrorCode != SL_ERROR_CODE_SUCCESS)
		{
			SL_CAMERA_PROXY_LOG_E("Can't retrieve IMU Data after reset tracking: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		}
		SL_Vector3 cam_imu_t;
		SL_Quaternion cam_imu_r;
		sl_get_camera_imu_transform(CameraID, &cam_imu_t, &cam_imu_r);

		sl::Rotation P = sl::Rotation(sl::Orientation(sl::float4(cam_imu_r.x, cam_imu_r.y, cam_imu_r.z, cam_imu_r.w)));

		SL_Quaternion imu_r = CurrentSensorsData.imu.orientation;
		sl::Rotation imu_pose = sl::Rotation(sl::Orientation(sl::float4(imu_r.x, imu_r.y, imu_r.z, imu_r.w)));

		sl::Rotation Pp = P;
		Pp.transpose();
		FRotator IMURotation = sl::unreal::ToUnrealType(P * imu_pose * Pp).Rotator();

	OnTrackingReset.Broadcast(bTrackingEnabled,sl::unreal::ToUnrealType(ErrorCode), Location, IMURotation);
}

ESlTrackingState USlCameraProxy::GetPosition(FSlPose& Pose, ESlReferenceFrame ReferenceFrame)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		SL_PoseData SlPose;
		SL_POSITIONAL_TRACKING_STATE TrackingState = (SL_POSITIONAL_TRACKING_STATE)sl_get_position_data(CameraID, &SlPose, (SL_REFERENCE_FRAME)ReferenceFrame);

		if (TrackingState == SL_POSITIONAL_TRACKING_STATE_FPS_TOO_LOW)
		{
			SL_CAMERA_PROXY_LOG_W("FPS too low for good tracking.");
		}
		else if (TrackingState == SL_POSITIONAL_TRACKING_STATE_SEARCHING)
		{
			SL_CAMERA_PROXY_LOG_W("Tracking trying to relocate.");
		}

		Pose = sl::unreal::ToUnrealType(SlPose);
		return (ESlTrackingState)TrackingState;
	SL_SCOPE_UNLOCK
}

ESlErrorCode USlCameraProxy::GetIMUData(FSlIMUData& IMUData, ESlTimeReference TimeReference)
{
	SL_ERROR_CODE ErrorCode = SL_ERROR_CODE_FAILURE;
	SL_SCOPE_LOCK(Lock, GrabSection)
		ErrorCode = (SL_ERROR_CODE)sl_get_sensors_data(CameraID, &CurrentSensorsData, (SL_TIME_REFERENCE)TimeReference);

		if (ErrorCode != SL_ERROR_CODE_SUCCESS)
		{
			SL_CAMERA_PROXY_LOG_E("Error while retrieving IMU data: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		}

		SL_Vector3 cam_imu_t;
		SL_Quaternion cam_imu_r;
		sl_get_camera_imu_transform(CameraID, &cam_imu_t, &cam_imu_r);

		sl::Rotation P = sl::Rotation(sl::Orientation(sl::float4(cam_imu_r.x, cam_imu_r.y, cam_imu_r.z, cam_imu_r.w)));

		SL_Quaternion imu_r = CurrentSensorsData.imu.orientation;
		sl::Rotation imu_pose = sl::Rotation(sl::Orientation(sl::float4(imu_r.x, imu_r.y, imu_r.z, imu_r.w)));

		sl::Rotation Pp = P;
		Pp.transpose();
		FRotator IMURotation = sl::unreal::ToUnrealType(P * imu_pose * Pp).Rotator();

		IMUData.Transform.SetRotation(IMURotation.Quaternion());

		return sl::unreal::ToUnrealType(ErrorCode);

	SL_SCOPE_UNLOCK
}

void USlCameraProxy::SetIMUPrior(const FTransform& Transform)
{
	sl_set_imu_prior_orientation(CameraID, sl::unreal::ToSlType(Transform.Rotator().Quaternion()));
}

bool USlCameraProxy::IsTrackingEnabled()
{
	return bTrackingEnabled;
}

bool USlCameraProxy::SaveSpatialMemoryArea(const FString& AreaSavingPath)
{
	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_save_area_map(CameraID, TCHAR_TO_UTF8(*AreaSavingPath));

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't save spatial memory: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));

		return false;
	}

	return (ErrorCode == SL_ERROR_CODE_SUCCESS);
}

ESlSpatialMemoryExportingState USlCameraProxy::GetSpatialMemoryExportState()
{
	return (ESlSpatialMemoryExportingState)sl_get_area_export_state(CameraID);
}

void USlCameraProxy::SetRuntimeParameters(const FSlRuntimeParameters& NewRuntimeParameters)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		RuntimeParameters = sl::unreal::ToSlType(NewRuntimeParameters);
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::SetObjectDetectionRuntimeParameters(const FSlObjectDetectionRuntimeParameters& NewObjectDetectionRuntimeParameters)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		ObjectDetectionRuntimeParameters = sl::unreal::ToSlType(NewObjectDetectionRuntimeParameters);
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::SetBodyTrackingRuntimeParameters(const FSlBodyTrackingRuntimeParameters& NewBodyTrackingRuntimeParameters)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		BodyTrackingRuntimeParameters = sl::unreal::ToSlType(NewBodyTrackingRuntimeParameters);
	SL_SCOPE_UNLOCK
}

FSlCameraInformation USlCameraProxy::GetCameraInformation(const FIntPoint& CustomResolution/* = FIntPoint::ZeroValue*/)
{
	if (CustomResolution == FIntPoint::ZeroValue)
	{
		return CameraInformation;
	}
	else
	{
		return sl::unreal::ToUnrealType(*sl_get_camera_information(CameraID, CustomResolution.X, CustomResolution.Y));
	}
}

bool USlCameraProxy::IsCameraOpened()
{
	return OpenCameraAsyncTask ? false : bCameraOpened && sl_is_opened(CameraID);
}

bool USlCameraProxy::IsCameraConnected()
{
	return true;// sl::Camera::getDeviceList().size() > 0; // TODO: check stability before using this.
}

TArray<FSlDeviceProperties> USlCameraProxy::GetCameraList()
{
	TArray<FSlDeviceProperties> DevicePropetiesList;

	return DevicePropetiesList;
}

int USlCameraProxy::GetCameraID()
{
	return CameraID;
}

SL_POSITIONAL_TRACKING_STATE USlCameraProxy::GetCameraPosition(SL_PoseData* pose, SL_REFERENCE_FRAME rframe)
{
	if (sl_is_opened(CameraID))
	{
		return (SL_POSITIONAL_TRACKING_STATE)sl_get_position_data(CameraID, pose, rframe);
	}
	else
		return SL_POSITIONAL_TRACKING_STATE_OFF;
}

SL_ERROR_CODE USlCameraProxy::GetCameraIMURotationAtImage(sl::Rotation& pose)
{
	if (sl_is_opened(CameraID)) {

		if (IMUErrorCode == SL_ERROR_CODE_SUCCESS)
		{
			SL_Vector3 cam_imu_t;
			SL_Quaternion cam_imu_r;
			sl_get_camera_imu_transform(CameraID, &cam_imu_t, &cam_imu_r);

			sl::Rotation P = sl::Rotation(sl::Orientation(sl::float4(cam_imu_r.x, cam_imu_r.y, cam_imu_r.z, cam_imu_r.w)));

			SL_Quaternion imu_r = CurrentSensorsData.imu.orientation;
			sl::Rotation imu_pose = sl::Rotation(sl::Orientation(sl::float4(imu_r.x, imu_r.y, imu_r.z, imu_r.w)));

			sl::Rotation Pp = P;
			Pp.transpose();

			imu_r = ImageRefSensorsData.imu.orientation;
			sl::Rotation imageRefImuRotation = sl::Rotation(sl::Orientation(sl::float4(imu_r.x, imu_r.y, imu_r.z, imu_r.w)));
			pose = P * imageRefImuRotation * Pp;
		}

		return IMUErrorCode;
	}
 	else
		return SL_ERROR_CODE_FAILURE;
}


void USlCameraProxy::Grab()
{
	SCOPE_CYCLE_COUNTER(STAT_Grab);

	if (!bGrabEnabled)
	{
		return;
	}

	SL_ERROR_CODE ErrorCode;

	SL_SCOPE_LOCK(Lock, SVOSection)
		if (bSVOPlaybackEnabled)
		{
			if (bSVOPlaybackPaused)
			{
				sl_set_svo_position(CameraID, CurrentSVOPlaybackPosition);
			}
		}
	SL_SCOPE_UNLOCK

	SL_SCOPE_LOCK(Lock, GrabSection)
		ErrorCode = (SL_ERROR_CODE)sl_grab(CameraID, &RuntimeParameters);
		IMUErrorCode = (SL_ERROR_CODE)sl_get_sensors_data(CameraID, &ImageRefSensorsData, SL_TIME_REFERENCE_IMAGE);
	SL_SCOPE_UNLOCK

	if (ErrorCode == SL_ERROR_CODE_SUCCESS)
	{
		SL_SCOPE_LOCK(Lock, SVOSection)
			if (bSVORecordingEnabled && bSVORecordingFrames)
			{
				SlRecordingStatus = sl_get_recording_status(CameraID);
				if (!SlRecordingStatus->status)
				{
					SL_CAMERA_PROXY_LOG_E("Can't record current frame");
				}
			}
		SL_SCOPE_UNLOCK
	}
	else if (ErrorCode == SL_ERROR_CODE_END_OF_SVOFILE_REACHED)
	{
		if (bSVOLooping)
		{
			sl_set_svo_position(CameraID, 0);

			AsyncTask(ENamedThreads::GameThread, [this]()
				{
				OnSVOLooping.Broadcast();
			});
		}
	}
	else
	{
		SL_CAMERA_PROXY_LOG_E("Grab error: \"%i\"", ErrorCode);

		if (ErrorCode == SL_ERROR_CODE_CAMERA_NOT_DETECTED)
		{
			if (bGrabEnabled)
			{
				bGrabEnabled = false;

				AsyncTask(ENamedThreads::GameThread, [this] ()
				{
					OnCameraDisconnected.Broadcast();
				});

				return;
			}
		}
	}

	SL_SCOPE_LOCK(Lock, GrabDelegateSection)
		OnGrabDoneDelegate.Broadcast(sl::unreal::ToUnrealType(ErrorCode), FSlTimestamp(sl_get_image_timestamp(CameraID)));
	SL_SCOPE_UNLOCK
}

FSlVideoSettings USlCameraProxy::GetCameraSettings()
{
	FSlVideoSettings CameraSettings;
	int value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_BRIGHTNESS, &value);
	CameraSettings.Brightness           = value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_CONTRAST, &value);
	CameraSettings.Contrast				= value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_HUE, &value);
	CameraSettings.Hue                  = value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_SATURATION, &value);
	CameraSettings.Saturation			= value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_SHARPNESS, &value);
	CameraSettings.Sharpness			= value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_GAMMA, &value);
	CameraSettings.Gamma                = value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_WHITEBALANCE_TEMPERATURE, &value);
	CameraSettings.WhiteBalance			= value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_GAIN, &value);
	CameraSettings.Gain					= value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_EXPOSURE, &value);
	CameraSettings.Exposure				= value;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_WHITEBALANCE_AUTO, &value);
	CameraSettings.bAutoWhiteBalance    = value == 0 ? false : true;

	sl_get_camera_settings(CameraID, SL_VIDEO_SETTINGS_AEC_AGC, &value);
	CameraSettings.bAutoGainAndExposure = value == 0 ? false : true;


	bAutoGainAndExposure = CameraSettings.bAutoGainAndExposure;
	CameraSettings.bDefault			    = false;

	return CameraSettings;
}

bool USlCameraProxy::EnableSpatialMapping(const FSlSpatialMappingParameters& SpatialMappingParameters)
{
	SL_ERROR_CODE ErrorCode;

	SL_SCOPE_LOCK(Lock, GrabSection)
		SL_SpatialMappingParameters SpatialMappingParams = sl::unreal::ToSlType(SpatialMappingParameters);
		ErrorCode = (SL_ERROR_CODE)sl_enable_spatial_mapping(CameraID, &SpatialMappingParams);
	SL_SCOPE_UNLOCK

	bSpatialMappingEnabled = (ErrorCode == SL_ERROR_CODE_SUCCESS);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't enable spatial mapping: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		return bSpatialMappingEnabled;
	}

	OnSpatialMappingEnabled.Broadcast(bSpatialMappingEnabled, sl::unreal::ToUnrealType(ErrorCode));

	return bSpatialMappingEnabled;
}

void USlCameraProxy::DisableSpatialMapping()
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		sl_disable_spatial_mapping(CameraID);
	SL_SCOPE_UNLOCK

	bSpatialMappingEnabled = false;

	OnSpatialMappingDisabled.Broadcast();
}

void USlCameraProxy::PauseSpatialMapping(bool bPause)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		sl_pause_spatial_mapping(CameraID, bPause);
	SL_SCOPE_UNLOCK

	OnSpatialMappingPaused.Broadcast(bPause);
}

void USlCameraProxy::RequestMeshAsync()
{
	sl_request_mesh_async(CameraID);
}

bool USlCameraProxy::GetMeshIsReadyAsync()
{
	return (sl_get_mesh_request_status_async(CameraID) == (int)SL_ERROR_CODE_SUCCESS);
}

bool USlCameraProxy::RetrieveMeshAsync(USlMesh* Mesh)
{
	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_update_whole_mesh(CameraID, &Mesh->NbVertices, &Mesh->NbTriangles);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't update mesh: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		return false;
	}

	Mesh->Vertices.SetNum(Mesh->NbVertices * 3);
	Mesh->Triangles.SetNum(Mesh->NbTriangles * 3);
	Mesh->UVs.SetNum(Mesh->NbVertices * 2);
	ErrorCode = (SL_ERROR_CODE)sl_retrieve_whole_mesh(CameraID, Mesh->Vertices.GetData(), Mesh->Triangles.GetData(), Mesh->UVs.GetData(), Mesh->Texture.GetData());

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't retrieve mesh: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		return false;
	}
	return (ErrorCode == SL_ERROR_CODE_SUCCESS);
}

bool USlCameraProxy::ExtractWholeMesh(USlMesh* Mesh)
{
	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_extract_whole_spatial_map(CameraID);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't extract the mesh: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		return false;
	}
	return  (ErrorCode == SL_ERROR_CODE_SUCCESS);
}

bool USlCameraProxy::RetrieveTexture(USlTexture* Texture)
{
	return (
		Texture->IsTypeOf(ESlTextureType::TT_Measure) ?
		RetrieveMeasure(Texture->Mat, static_cast<USlMeasureTexture*>(Texture)->MeasureType, Texture->GetMemoryType(), FIntPoint(Texture->Width, Texture->Height)) :
		RetrieveImage(Texture->Mat, static_cast<USlViewTexture*>(Texture)->ViewType, Texture->GetMemoryType(), FIntPoint(Texture->Width, Texture->Height), static_cast<USlViewTexture*>(Texture)->ViewFormat)
	);
}

bool USlCameraProxy::RetrieveImage(FSlMat& Mat, ESlView ViewType, ESlMemoryType MemoryType, const FIntPoint& Resolution, ESlViewFormat ViewFormat)
{
	SL_MAT_TYPE MatType = sl::unreal::ViewToMatType((SL_VIEW)(ViewType));
	if (!Mat.Mat) {
		Mat.Mat = sl_mat_create_new(Resolution.X, Resolution.Y, MatType, sl::unreal::ToSlType2(MemoryType));
	}

	return (bool)RetrieveImage(Mat.Mat, ViewType, MemoryType, Resolution, ViewFormat);
}

bool USlCameraProxy::RetrieveMeasure(FSlMat& Mat, ESlMeasure MeasureType, ESlMemoryType MemoryType, const FIntPoint& Resolution)
{
	SL_MAT_TYPE MatType = sl::unreal::ViewToMatType((SL_VIEW)(MeasureType));
	if (!Mat.Mat) {
		Mat.Mat = sl_mat_create_new(Resolution.X, Resolution.Y, MatType, sl::unreal::ToSlType2(MemoryType));
	}
	return RetrieveMeasure(Mat.Mat, MeasureType, MemoryType, Resolution);
}

bool USlCameraProxy::RetrieveImage(void* Mat, ESlView ViewType, ESlMemoryType MemoryType, const FIntPoint& Resolution, ESlViewFormat ViewFormat)
{
	SCOPE_CYCLE_COUNTER(STAT_RetrieveImage);

	if (UnsignedLeftImage == nullptr) UnsignedLeftImage = sl_mat_create_new(Resolution.X, Resolution.Y, SL_MAT_TYPE_U8_C4, SL_MEM_GPU);

	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_retrieve_image(CameraID, UnsignedLeftImage, (SL_VIEW)ViewType, SL_MEM_GPU, Resolution.X, Resolution.Y);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Error while retrieving texture image : \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));

		return false;
	}

	if (ViewFormat == ESlViewFormat::VF_Unsigned)
	{
		Mat = UnsignedLeftImage;
	}
	else
	{
		ErrorCode = (SL_ERROR_CODE)sl_convert_image(UnsignedLeftImage, Mat, 0);
	}

	if (MemoryType == ESlMemoryType::MT_CPU)
	{
		sl_mat_update_cpu_from_gpu(Mat);
	}

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Error while converting texture image format : \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));

		return false;
	}

	return true;
}

bool USlCameraProxy::RetrieveMeasure(void* Mat, ESlMeasure MeasureType, ESlMemoryType MemoryType, const FIntPoint& Resolution)
{
	SCOPE_CYCLE_COUNTER(STAT_RetrieveMeasure);

	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_retrieve_measure(CameraID, Mat, (SL_MEASURE)MeasureType, sl::unreal::ToSlType2(MemoryType), Resolution.X, Resolution.Y);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Error while retrieving texture measure : \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
	}
	return (ErrorCode == SL_ERROR_CODE_SUCCESS);
}

void USlCameraProxy::SetCameraSettings(FSlVideoSettings& NewCameraSettings)
{
	bool bDefault = NewCameraSettings.bDefault;

	if (!bDefault)
	{
		NewCameraSettings.Brightness = FMath::Clamp(NewCameraSettings.Brightness,   0, 8);
		NewCameraSettings.Contrast = FMath::Clamp(NewCameraSettings.Contrast,	 0, 8);
		NewCameraSettings.Hue = FMath::Clamp(NewCameraSettings.Hue,			 0, 11);
		NewCameraSettings.Saturation = FMath::Clamp(NewCameraSettings.Saturation,   0, 8);
		NewCameraSettings.Gamma = FMath::Clamp(NewCameraSettings.Gamma, 1, 9);
		NewCameraSettings.Sharpness = FMath::Clamp(NewCameraSettings.Sharpness,    0, 8);
		NewCameraSettings.WhiteBalance = FMath::Clamp(NewCameraSettings.WhiteBalance, 2800, 6500);
		NewCameraSettings.Gain = FMath::Clamp(NewCameraSettings.Gain,		 0, 100);
		NewCameraSettings.Exposure = FMath::Clamp(NewCameraSettings.Exposure,	 0, 100);
	}

	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_BRIGHTNESS, !bDefault ? NewCameraSettings.Brightness : -1);
	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_CONTRAST, !bDefault ? NewCameraSettings.Contrast : -1);
	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_HUE, !bDefault ? NewCameraSettings.Hue : -1);
	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_SATURATION, !bDefault ? NewCameraSettings.Saturation : -1);
	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_GAMMA, !bDefault ? NewCameraSettings.Gamma : -1);
	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_HUE, !bDefault ? NewCameraSettings.Hue : -1);
	sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_SHARPNESS, !bDefault ? NewCameraSettings.Sharpness : -1);

	if (NewCameraSettings.bAutoGainAndExposure) {
		sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_AEC_AGC, 1);
	}
	else {
		sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_GAIN, NewCameraSettings.Gain);
		sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_EXPOSURE, NewCameraSettings.Exposure);
	}

	if (NewCameraSettings.bAutoWhiteBalance) {
		sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_WHITEBALANCE_AUTO, 1);

	}
	else
	{
		sl_set_camera_settings(CameraID, SL_VIDEO_SETTINGS_WHITEBALANCE_TEMPERATURE, NewCameraSettings.WhiteBalance);
	}

	bAutoGainAndExposure = NewCameraSettings.bAutoGainAndExposure;
}

FSlTimestamp USlCameraProxy::GetTimestamp(ESlTimeReference TimeReference)
{
	if (TimeReference == ESlTimeReference::TR_Image)
	{
		SL_SCOPE_LOCK(Lock, GrabSection)
			return FSlTimestamp(sl_get_image_timestamp(CameraID));
		SL_SCOPE_UNLOCK
	}

	return FSlTimestamp(sl_get_current_timestamp(CameraID));
}

void USlCameraProxy::EnableGrabThread(bool bEnable)
{
	if (bEnable)
	{
		if (GrabWorker)
		{
			return;
		}

		GrabWorker = new FSlGrabRunnable();
		GrabWorker->Start(0.001f);

		OnGrabThreadEnabled.Broadcast(true);
	}
	else
	{
		if (!GrabWorker)
		{
			return;
		}

		GrabWorker->EnsureCompletion();
		delete GrabWorker;
		GrabWorker = nullptr;

		OnGrabThreadEnabled.Broadcast(false);
	}
}

void USlCameraProxy::EnableObjectDetectionThread(bool bEnable)
{
	if (bEnable)
	{
		if (ObjectDetectionWorker)
		{
			return;
		}

		ObjectDetectionWorker = new FSlObjectDetectionRunnable();
		ObjectDetectionWorker->Start(0.001f);

		//OnAIhreadEnabled.Broadcast(true);
	}
	else
	{
		if (!ObjectDetectionWorker)
		{
			return;
		}

		ObjectDetectionWorker->EnsureCompletion();
		delete ObjectDetectionWorker;
		ObjectDetectionWorker = nullptr;

		//OnAIWorkerThreadEnabled.Broadcast(false);
	}
}

void USlCameraProxy::EnableBodyTrackingThread(bool bEnable)
{
	if (bEnable)
	{
		if (BodyTrackingWorker)
		{
			return;
		}

		BodyTrackingWorker = new FSlBodyTrackingRunnable();
		BodyTrackingWorker->Start(0.001f);

		//OnAIhreadEnabled.Broadcast(true);
	}
	else
	{
		if (!BodyTrackingWorker)
		{
			return;
		}

		BodyTrackingWorker->EnsureCompletion();
		delete BodyTrackingWorker;
		BodyTrackingWorker = nullptr;

		//OnAIWorkerThreadEnabled.Broadcast(false);
	}
}

bool USlCameraProxy::CheckAIModelOptimization(const ESlAIModels AiModel)
{
	SL_AI_Model_status* ai_model_status = sl_check_AI_model_status((SL_AI_MODELS)AiModel, 0);

	if (!ai_model_status->optimized)
	{
		SL_CAMERA_PROXY_LOG_E("Detection model : %i is not downloaded/optimized", AiModel);
		return false;
	}
	return true;
}

void USlCameraProxy::OptimizeAIModel(const ESlAIModels& AIModel) {

	AIOptimizationAsyncTask = new FAsyncTask<FAIOptimizationAsyncTask>(AIModel);
	AIOptimizationAsyncTask->StartBackgroundTask();
}

void USlCameraProxy::Internal_OptimizeAIModel(const ESlAIModels& AIModel) {

	int err = sl_optimize_AI_model((SL_AI_MODELS)AIModel, 0);

	AsyncTask(ENamedThreads::GameThread, [this]()
		{
			if (!GSlCameraProxy)
			{
				return;
			}

			AIOptimizationAsyncTask->EnsureCompletion(false);

			delete AIOptimizationAsyncTask;
			AIOptimizationAsyncTask = nullptr;

			GSlCameraProxy->OnAIModelOptimized.Broadcast();

		});
}

void USlCameraProxy::SetOpenCameraErrorCode(ESlErrorCode ErrorCode)
{
	SL_SCOPE_LOCK(SubLock, AsyncStatusSection)
		OpenCameraErrorCode = ErrorCode;
	SL_SCOPE_UNLOCK
}


ESlErrorCode USlCameraProxy::GetOpenCameraErrorCode()
{
	SL_SCOPE_LOCK(Lock, AsyncStatusSection)
		return OpenCameraErrorCode;
	SL_SCOPE_UNLOCK
}

float USlCameraProxy::GetDepth(const FSlViewportHelper& ViewportHelper, const FIntPoint& ScreenPosition)
{
	ensureMsgf(MeasuresWorker && bHitTestDepthEnabled, TEXT("Depth hit tests must be enabled"));

	float Depth = MeasuresWorker->GetDepth(ScreenPosition, ViewportHelper.RangeX, ViewportHelper.RangeY);

	if (!FMath::IsFinite(Depth))
	{
		if (FMath::IsNaN(Depth) || Depth > 0.0f)
		{
			Depth = sl_get_init_parameters(CameraID)->depth_maximum_distance;
		}
		else
		{
			Depth = sl_get_init_parameters(CameraID)->depth_minimum_distance;
		}
	}

	return (Depth + HMDToCameraOffset);
}

TArray<float> USlCameraProxy::GetDepths(const FSlViewportHelper& ViewportHelper, const TArray<FIntPoint>& ScreenPositions)
{
	ensureMsgf(MeasuresWorker && bHitTestDepthEnabled, TEXT("Depth hit tests must be enabled"));

	TArray<float> Depths = MeasuresWorker->GetDepths(ScreenPositions, ViewportHelper.RangeX, ViewportHelper.RangeY);

	for (auto Iterator = Depths.CreateIterator(); Iterator; ++Iterator)
	{
		float& Depth = (*Iterator);

		if (!FMath::IsFinite(Depth))
		{
			if (FMath::IsNaN(Depth) || Depth > 0.0f)
			{
				Depth = sl_get_init_parameters(CameraID)->depth_maximum_distance;
			}
			else
			{
				Depth = sl_get_init_parameters(CameraID)->depth_minimum_distance;
			}
		}

		Depth += HMDToCameraOffset;
	}

	return Depths;
}

FVector USlCameraProxy::GetNormal(const FSlViewportHelper& ViewportHelper, const FIntPoint& ScreenPosition)
{
	ensureMsgf(MeasuresWorker && bHitTestNormalsEnabled, TEXT("Normals hit tests must be enabled"));

	FVector Normal = MeasuresWorker->GetNormal(ScreenPosition, ViewportHelper.RangeX, ViewportHelper.RangeY);

	float Size = Normal.SizeSquared();
	if (!FMath::IsFinite(Size) || FMath::IsNaN(Size))
	{
		Normal = FVector::ZeroVector;
	}

	return Normal;
}

TArray<FVector> USlCameraProxy::GetNormals(const FSlViewportHelper& ViewportHelper, const TArray<FIntPoint>& ScreenPositions)
{
	ensureMsgf(MeasuresWorker && bHitTestNormalsEnabled, TEXT("Normals hit tests must be enabled"));

	TArray<FVector> Normals = MeasuresWorker->GetNormals(ScreenPositions, ViewportHelper.RangeX, ViewportHelper.RangeY);

	for (auto Iterator = Normals.CreateIterator(); Iterator; ++Iterator)
	{
		FVector& Normal = (*Iterator);

		float Size = Normal.SizeSquared();
		if (!FMath::IsFinite(Size) || FMath::IsNaN(Size))
		{
			Normal = FVector::ZeroVector;
		}
	}

	return Normals;
}

void USlCameraProxy::GetDepthAndNormal(const FSlViewportHelper& ViewportHelper, const FIntPoint& ScreenPosition, float& Depth, FVector& Normal)
{
	ensureMsgf(MeasuresWorker && bHitTestDepthEnabled && bHitTestNormalsEnabled, TEXT("Depth and Normals hit tests must be enabled"));

	FVector4 DepthAndNormal = MeasuresWorker->GetDepthAndNormal(ScreenPosition, ViewportHelper.RangeX, ViewportHelper.RangeY);

	Depth = DepthAndNormal.W;
	if (!FMath::IsFinite(Depth))
	{
		if (FMath::IsNaN(Depth) || Depth > 0.0f)
		{
			Depth = sl_get_init_parameters(CameraID)->depth_maximum_distance;
		}
		else
		{
			Depth = sl_get_init_parameters(CameraID)->depth_minimum_distance;
		}
	}

	Depth += HMDToCameraOffset;

	Normal = FVector(DepthAndNormal.X, DepthAndNormal.Y, DepthAndNormal.Z);
	float Size = Normal.SizeSquared();
	if (!FMath::IsFinite(Size) || FMath::IsNaN(Size))
	{
		Normal = FVector::ZeroVector;
	}
}

void USlCameraProxy::GetDepthsAndNormals(const FSlViewportHelper& ViewportHelper, const TArray<FIntPoint>& ScreenPositions, TArray<float>& Depths, TArray<FVector>& Normals)
{
	ensureMsgf(MeasuresWorker && bHitTestDepthEnabled && bHitTestNormalsEnabled, TEXT("Depth and Normals hit tests must be enabled"));

	TArray<FVector4> DepthsAndNormals = MeasuresWorker->GetDepthsAndNormals(ScreenPositions, ViewportHelper.RangeX, ViewportHelper.RangeY);

	int ScreenPositionsNums = ScreenPositions.Num();
	Depths.Reserve(ScreenPositionsNums);
	Normals.Reserve(ScreenPositionsNums);

	for (int ScreenPositionsIndex = 0; ScreenPositionsIndex < ScreenPositionsNums; ++ScreenPositionsIndex)
	{
		float Depth = DepthsAndNormals[ScreenPositionsIndex].Z;
		if (!FMath::IsFinite(Depth))
		{
			if (FMath::IsNaN(Depth) || Depth > 0.0f)
			{
				Depth = sl_get_init_parameters(CameraID)->depth_maximum_distance;
			}
			else
			{
				Depth = sl_get_init_parameters(CameraID)->depth_minimum_distance;
			}
		}
		Depths.Add(Depth + HMDToCameraOffset);

		FVector Normal(DepthsAndNormals[ScreenPositionsIndex]);
		float Size = Normal.SizeSquared();
		if (!FMath::IsFinite(Size) || FMath::IsNaN(Size))
		{
			Normal = FVector::ZeroVector;
		}
		Normals.Add(Normal);
	}
}

bool USlCameraProxy::EnableObjectDetection(const FSlObjectDetectionParameters& ODParameters) {
	SL_ERROR_CODE ErrorCode;


	ObjectDetectionParameters = ODParameters;
	SL_AI_MODELS ai_model = sl::unreal::cvtDetection((SL_OBJECT_DETECTION_MODEL)ObjectDetectionParameters.DetectionModel);

	SL_AI_Model_status* ai_model_status = sl_check_AI_model_status(ai_model, 0);

	if (!ai_model_status->optimized)
	{
		SL_CAMERA_PROXY_LOG_E("AI model : %i is not downloaded/optimized, please optimize it using the ZED Diagnostic tool (use the *-h* option to have all the informations needed", ObjectDetectionParameters.DetectionModel);
		return false;
	}

	SL_SCOPE_LOCK(Lock, GrabSection)

		SL_ObjectDetectionParameters ODParams = sl::unreal::ToSlType(ObjectDetectionParameters);
		ErrorCode = (SL_ERROR_CODE)sl_enable_object_detection(CameraID, &ODParams);
	SL_SCOPE_UNLOCK

	bObjectDetectionEnabled = (ErrorCode == SL_ERROR_CODE_SUCCESS);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't enable object detection: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
	}

	OnObjectDetectionEnabled.Broadcast(bObjectDetectionEnabled, sl::unreal::ToUnrealType(ErrorCode));
	return bObjectDetectionEnabled;
}

bool USlCameraProxy::EnableBodyTracking(const FSlBodyTrackingParameters& BTParameters) {
	SL_ERROR_CODE ErrorCode;


	BodyTrackingParameters = BTParameters;
	SL_AI_MODELS ai_model = sl::unreal::cvtDetection((SL_BODY_TRACKING_MODEL)BodyTrackingParameters.DetectionModel);

	SL_AI_Model_status* ai_model_status = sl_check_AI_model_status(ai_model, 0);

	if (!ai_model_status->optimized)
	{
		//SL_CAMERA_PROXY_LOG_E("Detection model : %i is not downloaded/optimized, please optimize it using the ZED Diagnostic tool (use the *-h* option to have all the informations needed", BodyTrackingParameters.DetectionModel);
		//return false;
	}

	SL_SCOPE_LOCK(Lock, GrabSection)
		SL_BodyTrackingParameters BTParams = sl::unreal::ToSlType(BodyTrackingParameters);
	ErrorCode = (SL_ERROR_CODE)sl_enable_body_tracking(CameraID, &BTParams);
	SL_SCOPE_UNLOCK

		bBodyTrackingEnabled = (ErrorCode == SL_ERROR_CODE_SUCCESS);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't enable BodyTracking: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
	}

	OnBodyTrackingEnabled.Broadcast(bBodyTrackingEnabled, sl::unreal::ToUnrealType(ErrorCode));
	return bBodyTrackingEnabled;
}

bool USlCameraProxy::IsObjectDetectionEnabled()
{
	return bObjectDetectionEnabled;
}

void USlCameraProxy::DisableObjectDetection()
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		sl_disable_object_detection(CameraID, 0, false);
	SL_SCOPE_UNLOCK

	bObjectDetectionEnabled = false;
}

void USlCameraProxy::DisableBodyTracking()
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		sl_disable_body_tracking(CameraID, 0, false);
	SL_SCOPE_UNLOCK

	bBodyTrackingEnabled = false;
}

bool USlCameraProxy::IsBodyTrackingEnabled()
{
	return bBodyTrackingEnabled;
}

bool USlCameraProxy::RetrieveObjects()
{
	SL_Objects sl_objects;
	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_retrieve_objects(CameraID, &ObjectDetectionRuntimeParameters, &sl_objects, 0);
	objects = sl::unreal::ToUnrealType(sl_objects);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't retrieve objects: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		return false;
	}

	AsyncTask(ENamedThreads::GameThread, [this, sl_objects]()
		{
			OnObjectDetectionRetrieved.Broadcast(objects);
		});
	return (ErrorCode == SL_ERROR_CODE_SUCCESS);
}

bool USlCameraProxy::RetrieveBodies()
{
	SL_Bodies sl_bodies;
	SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_retrieve_bodies(CameraID, &BodyTrackingRuntimeParameters, &sl_bodies, 0);
	bodies = sl::unreal::ToUnrealType(sl_bodies, BodyTrackingParameters.BodyFormat);

	if (ErrorCode != SL_ERROR_CODE_SUCCESS)
	{
		SL_CAMERA_PROXY_LOG_E("Can't retrieve bodies: \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		return false;
	}

	AsyncTask(ENamedThreads::GameThread, [this, sl_bodies]()
		{
			OnBodyTrackingRetrieved.Broadcast(bodies);
		});
	return (ErrorCode == SL_ERROR_CODE_SUCCESS);
}

int USlCameraProxy::GetNumberOfKeypoints()
{
	if (BodyTrackingParameters.BodyFormat == ESlBodyFormat::BF_BODY_18)
	{
		return 18;
	}
	else if (BodyTrackingParameters.BodyFormat == ESlBodyFormat::BF_BODY_34)
	{
		return 34;
	}
	else if (BodyTrackingParameters.BodyFormat == ESlBodyFormat::BF_BODY_38)
	{
		return 38;
	}
	else if (BodyTrackingParameters.BodyFormat == ESlBodyFormat::BF_BODY_70)
	{
		return 70;
	}
	else
	{
		return 38;
	}
}

void USlCameraProxy::SetHitTestDepthAndNormals(bool bEnableDepth, bool bEnableNormals)
{
	bHitTestDepthEnabled = bEnableDepth;
	bHitTestNormalsEnabled = bEnableNormals;

	if (MeasuresWorker)
	{
		MeasuresWorker->SetDepthAndNormals(bEnableDepth, bEnableNormals);
	}
}

void USlCameraProxy::EnableHitTest(bool bEnabled)
{
	if (bEnabled)
	{
		if (MeasuresWorker)
		{
			return;
		}

		MeasuresWorker = new FSlMeasureRunnable();
		MeasuresWorker->SetDepthAndNormals(bHitTestDepthEnabled, bHitTestNormalsEnabled);
		MeasuresWorker->Start(30.0f);

		OnHitTestThreadEnabled.Broadcast(true);
	}
	else
	{
		if (!MeasuresWorker)
		{
			return;
		}

		MeasuresWorker->EnsureCompletion();
		delete MeasuresWorker;
		MeasuresWorker = nullptr;

		OnHitTestThreadEnabled.Broadcast(false);
	}
}

FDelegateHandle USlCameraProxy::AddToGrabDelegate(TFunction<void(ESlErrorCode, const FSlTimestamp&)> Lambda)
{
	SL_SCOPE_LOCK(Lock, GrabDelegateSection)
		return OnGrabDoneDelegate.AddLambda(Lambda);
	SL_SCOPE_UNLOCK
}

FGrabDelegateHandle USlCameraProxy::BP_AddToGrabDelegate(UObject* Object)
{
	checkf(Object->GetClass()->ImplementsInterface(UGrabCallbackInterface::StaticClass()), TEXT("Object must implement IGrabCallbackInterface interface"));

	FGrabDelegateHandle Handle = AddToGrabDelegate([Object](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp) {
		IGrabCallbackInterface::Execute_GrabCallback(Object, ErrorCode, Timestamp);
	});

	return Handle;
}

void USlCameraProxy::RemoveFromGrabDelegate(FDelegateHandle& Handle)
{
	SL_SCOPE_LOCK(Lock, GrabDelegateSection)
		if (Handle.IsValid())
		{
			OnGrabDoneDelegate.Remove(Handle);
			Handle.Reset();
		}
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::BP_RemoveFromGrabDelegate(FGrabDelegateHandle GrabDelegateHandle)
{
	RemoveFromGrabDelegate(GrabDelegateHandle.Handle);
}

ESlErrorCode USlCameraProxy::EnableSVORecording(FSlRecordingParameters RecordingParameters)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		SL_ERROR_CODE ErrorCode = (SL_ERROR_CODE)sl_enable_recording(CameraID, TCHAR_TO_UTF8(*RecordingParameters.VideoFilename), (SL_SVO_COMPRESSION_MODE)RecordingParameters.CompressionMode,
			RecordingParameters.Bitrate, RecordingParameters.TargetFramerate, RecordingParameters.bTranscodeStreamingInput);

		SL_SCOPE_LOCK(SubLock, SVOSection)
			bSVORecordingEnabled = (ErrorCode == SL_ERROR_CODE_SUCCESS);
		SL_SCOPE_UNLOCK

		if (!bSVORecordingEnabled)
		{
			SL_CAMERA_PROXY_LOG_E("Can't enable SVO recording : \"%s\"", *EnumToString(sl::unreal::ToUnrealType(ErrorCode)));
		}

		return sl::unreal::ToUnrealType(ErrorCode);
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::DisableSVORecording()
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		sl_disable_recording(CameraID);

		SL_SCOPE_LOCK(SubLock, SVOSection)
			bSVORecordingEnabled = false;
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::SetSVOPlaybackPosition(int Position)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		Position = FMath::Max(0, FMath::Min(sl_get_svo_number_of_frames(CameraID) - 1, Position));

		SL_SCOPE_LOCK(SubLock, SVOSection)
			if (bSVOPlaybackPaused)
			{
				CurrentSVOPlaybackPosition = Position;
			}
			else
			{
				sl_set_svo_position(CameraID, Position);

				AsyncTask(ENamedThreads::GameThread, [this]()
				{
					/* Current behavior: always reset the texture batch on svo position change.*/
					OnSVOSetBackInTime.Broadcast();
				});
			}
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

int USlCameraProxy::GetSVOPlaybackPosition()
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		SL_SCOPE_LOCK(SubLock, SVOSection)
			return sl_get_svo_position(CameraID);
		SL_SCOPE_UNLOCK
	SL_SCOPE_UNLOCK
}

int USlCameraProxy::GetSVONumberOfFrames()
{
	return sl_get_svo_number_of_frames(CameraID);
}


void USlCameraProxy::PauseSVOplayback(bool bPause, int NewSVOPosition/* = -1*/)
{
	SL_SCOPE_LOCK(SubLock, SVOSection)
		if (bPause)
		{
			CurrentSVOPlaybackPosition = NewSVOPosition >= 0 ? NewSVOPosition : sl_get_svo_position(CameraID) - 1;
		}

		bSVOPlaybackPaused = bPause;
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::SetSVOPlaybackLooping(bool bLoop)
{
	SL_SCOPE_LOCK(Lock, SVOSection)
		bSVOLooping = bLoop;
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::SetSVORecordFrames(bool bRecord)
{
	SL_SCOPE_LOCK(Lock, SVOSection)
		bSVORecordingFrames = bRecord;
	SL_SCOPE_UNLOCK
}

FSlRecordingState USlCameraProxy::GetSVORecordingState()
{
	SL_SCOPE_LOCK(Lock, SVOSection)
		return sl::unreal::ToUnrealType(*SlRecordingStatus);
	SL_SCOPE_UNLOCK
}

void USlCameraProxy::PushCudaContext()
{
	cuCtxPushCurrent(sl_get_cuda_context(CameraID));
}

void USlCameraProxy::PopCudaContext()
{
	CUcontext CudaContext = sl_get_cuda_context(CameraID);
	cuCtxPopCurrent(&CudaContext);
}

int32 USlCameraProxy::GetConfidenceThreshold()
{
	return sl_get_runtime_parameters(CameraID)->confidence_threshold;
}

void USlCameraProxy::SetConfidenceThreshold(int32 NewConfidenceThreshold)
{
	SL_SCOPE_LOCK(Lock, GrabSection)
		RuntimeParameters.confidence_threshold = NewConfidenceThreshold;
	SL_SCOPE_UNLOCK
}

float USlCameraProxy::GetDepthMaxRangeValue()
{
	return sl_get_init_parameters(CameraID)->depth_maximum_distance;
}

float USlCameraProxy::GetDepthMinRangeValue()
{
	return sl_get_init_parameters(CameraID)->depth_minimum_distance;
}

float USlCameraProxy::GetCameraFPS()
{
	return sl_get_camera_information(CameraID, 0, 0)->camera_configuration.fps;
}


float USlCameraProxy::GetCurrentFPS()
{
	return sl_get_current_fps(CameraID);
}

float USlCameraProxy::GetFrameDroppedCount()
{
	return sl_get_frame_dropped_count(CameraID);
}
