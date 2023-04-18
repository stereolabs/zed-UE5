//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDCamera.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "ZED/Public/Core/ZEDPlayerController.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"
#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "Kismet/KismetRenderingLibrary.h"

DEFINE_LOG_CATEGORY(ZEDCamera);

#define ZED_CAMERA_LOG(Format, ...) SL_LOG(ZEDCamera, Format, ##__VA_ARGS__)
#define ZED_CAMERA_LOG_W(Format, ...) SL_LOG_W(ZEDCamera, Format, ##__VA_ARGS__)
#define ZED_CAMERA_LOG_E(Format, ...) SL_LOG_E(ZEDCamera, Format, ##__VA_ARGS__)
#define ZED_CAMERA_LOG_F(Format, ...) SL_LOG_F(ZEDCamera, Format, ##__VA_ARGS__)

/** Preset for depth texture quality */
static TAutoConsoleVariable<int32> CVarZEDDepthTextureQualityPreset(
	TEXT("r.ZED.DepthTextureQualityPreset"),
	1,
	TEXT("Set the quality of the ZED depth texture.")
	TEXT("	0: low (default)")
	TEXT("	1: medium")
	TEXT("	2: high"),
	ECVF_RenderThreadSafe
	);

AZEDCamera::AZEDCamera()
	:
	LeftEyeColor(nullptr),
	LeftEyeDepth(nullptr),
	LeftEyeRenderTarget(nullptr),
	Batch(nullptr),
	CurrentDepthTextureQualityPreset(1),
	bCurrentDepthEnabled(false),
	bInit(false),
	bShowZedImage(true),
	ImageView(ESlView::V_Left)
{
	// Controller tick the camera to make it the first actor to tick
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial> ZedMaterial(TEXT("Material'/Stereolabs/ZED/Materials/Mono/M_ZED_Mono.M_ZED_Mono'"));
	ZedSourceMaterial = ZedMaterial.Object;

	// components creation
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	LeftRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LeftRoot"));
	LeftCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("LeftCamera"));
	LeftPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftPlane"));

	LeftRoot->SetupAttachment(RootComponent);
	LeftPlane->SetupAttachment(LeftRoot);

	// Initial camera setup
	LeftCamera->bCaptureEveryFrame = true;
	LeftCamera->bCaptureOnMovement = false;
	LeftCamera->SetAutoActivate(false);

	// Add static mesh to planes
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMesh(TEXT("StaticMesh'/Stereolabs/ZED/Shapes/SM_Plane_100x100.SM_Plane_100x100'"));
	LeftPlane->SetStaticMesh(PlaneMesh.Object);

	// Initial planes rotation setup
	LeftPlane->SetRelativeRotation(FRotator(0, 90, 90));

	// Remove collision
	LeftPlane->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Remove shadow cast
	LeftPlane->SetCastShadow(false);

	// Ignore Postprocessing
	LeftPlane->SetRenderCustomDepth(true);
	LeftPlane->CustomDepthStencilValue = 1;

	LeftCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
	LeftCamera->PostProcessSettings.bOverride_VignetteIntensity = true;
	LeftCamera->PostProcessSettings.VignetteIntensity = 0;
	LeftCamera->PostProcessSettings.bOverride_ToneCurveAmount = true;
	LeftCamera->PostProcessSettings.ToneCurveAmount = 0;

	LeftCamera->PostProcessSettings.bOverride_AutoExposureBias = true;
	LeftCamera->PostProcessSettings.AutoExposureBias = 0;
	LeftCamera->PostProcessSettings.bOverride_AutoExposureMaxBrightness = true;
	LeftCamera->PostProcessSettings.bOverride_AutoExposureMinBrightness = true;
	// Set light channels
	LeftPlane->LightingChannels.bChannel0 = false;
}

void AZEDCamera::BeginPlay()
{
	Super::BeginPlay();

	GSlCameraProxy->OnCameraClosed.AddDynamic(this, &AZEDCamera::CameraClosed);
	CameraRenderPlaneDistance = GNearClippingPlane +0.001;
}

void AZEDCamera::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GSlCameraProxy)
	{
		DisableObjectDetection();
		GSlCameraProxy->OnCameraClosed.RemoveDynamic(this, &AZEDCamera::CameraClosed);
		GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
	}
	}

#if WITH_EDITOR
void AZEDCamera::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (!GSlCameraProxy)
	{
		Super::PostEditChangeProperty(PropertyChangedEvent);
		return;
	}

	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyChangedEvent.Property->GetOwnerStruct())
	{
		FString StructName = PropertyChangedEvent.Property->GetOwnerStruct()->GetName();
		if (StructName == FString("SlVideoSettings"))
		{
			SetCameraSettings(CameraSettings);
		}

		if (StructName == FString("SlRuntimeParameters"))
		{
			SetRuntimeParameters(RuntimeParameters);
		}
	}
	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, bLoop))
	{
		GSlCameraProxy->SetSVOPlaybackLooping(InitParameters.bLoop);
	}

	if (PropertyName == FName("DepthClampThreshold")) {
		SetDepthClampThreshold(DepthClampThreshold);
	}

	if (PropertyName == FName("bDepthOcclusion")) {
		SetDepthOcclusion(bDepthOcclusion);
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool AZEDCamera::CanEditChange(const FProperty* InProperty) const
{
	FName PropertyName = InProperty->GetFName();

	if (!GSlCameraProxy)
	{
		return false;
	}

	if (InProperty->GetOwnerStruct())
	{
		if (InProperty->GetOwnerStruct()->GetName() == FString("SlCameraSettings"))
		{
			return !GSlCameraProxy->bSVOPlaybackEnabled;
		}

		if (InProperty->GetOwnerStruct()->GetName() == FString("SlRuntimeParameters"))
		{
			if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRuntimeParameters, ReferenceFrame))
			{
				return false;
			}

			return true;
		}
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlVideoSettings, WhiteBalance))
	{
		return !CameraSettings.bAutoWhiteBalance;
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlVideoSettings, Gain) || PropertyName == GET_MEMBER_NAME_CHECKED(FSlVideoSettings, Exposure))
	{
		return !CameraSettings.bAutoGainAndExposure;
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlPositionalTrackingParameters, bEnableTracking))
	{
		return false;
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRecordingParameters, VideoFilename) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FSlRecordingParameters, CompressionMode))
	{
		return !GSlCameraProxy->bSVORecordingEnabled && GSlCameraProxy->GetSVONumberOfFrames() == -1;
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlPositionalTrackingParameters, bEnablePoseSmoothing))
	{
		return TrackingParameters.bEnableAreaMemory;
	}

	return Super::CanEditChange(InProperty);
}
#endif

void AZEDCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	bool bUpdateTracking = false;
	SL_SCOPE_LOCK(Lock, TrackingUpdateSection)
		if (GSlCameraProxy->bTrackingEnabled)
		{
			bUpdateTracking = TrackingData.Timestamp.timestamp != CurrentFrameTrackingData.Timestamp.timestamp;
			if (bUpdateTracking)
			{
				TrackingData = CurrentFrameTrackingData;
			}
		}
		else
		{
			TrackingData = CurrentFrameTrackingData;
		}
	SL_SCOPE_UNLOCK

	// Always tick to retrieve last images
	bool bNewImage = Batch->Tick();

	TrackingData.ZedWorldTransform		 = TrackingData.ZedPathTransform;
	TrackingData.OffsetZedWorldTransform = TrackingData.ZedWorldTransform;

	// Update tracking data
	if (bUpdateTracking)
	{
		GZedTrackingData = TrackingData;

		GZedRawLocation = TrackingData.ZedWorldTransform.GetLocation();
		GZedRawRotation = TrackingData.ZedWorldTransform.Rotator();

		GZedViewPointLocation = TrackingData.OffsetZedWorldTransform.GetLocation();
		GZedViewPointRotation = TrackingData.OffsetZedWorldTransform.Rotator();

		OnTrackingDataUpdated.Broadcast(TrackingData);
	}

	// Depth texture quality, normals will have the same size for performance purpose
	int32 GDepthTextureSizePreset = CVarZEDDepthTextureQualityPreset.GetValueOnGameThread();
	if (CurrentDepthTextureQualityPreset != GDepthTextureSizePreset)
	{
		CurrentDepthTextureQualityPreset = GDepthTextureSizePreset;

		if (bCurrentDepthEnabled)
		{
			FVector2D DepthSize = GetSlTextureSizeFromPreset(CurrentDepthTextureQualityPreset);

			// Left depth
			Batch->RemoveTexture(LeftEyeDepth);
			LeftEyeDepth->Resize(DepthSize.X, DepthSize.Y);
			Batch->AddTexture(LeftEyeDepth);

			ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
		}
		else
		{
			ZED_CAMERA_LOG_E("Resizing depth and normal without depth enabled in runtime parameters");
		}

		// Depth retrieve toggle
		if (bCurrentDepthEnabled != RuntimeParameters.bEnableDepth)
		{
			bCurrentDepthEnabled = RuntimeParameters.bEnableDepth;

			if (!bCurrentDepthEnabled)
			{
				ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", nullptr);

				Batch->RemoveTexture(LeftEyeDepth);
				delete LeftEyeDepth;
				LeftEyeDepth = nullptr;
			}
			else
			{
				CreateLeftTextures(false);

				Batch->AddTexture(LeftEyeDepth);

				ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
			}
		}
	}
}

void AZEDCamera::GrabCallback(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
{
	if (ErrorCode != ESlErrorCode::EC_Success)
	{
		return;
	}

	Batch->RetrieveCurrentFrame(Timestamp);

	SL_SCOPE_LOCK(Lock, TrackingUpdateSection)
		SL_PoseData Pose;
		SL_POSITIONAL_TRACKING_STATE TrackingState = GSlCameraProxy->GetCameraPosition(&Pose, SL_REFERENCE_FRAME_WORLD);
		CurrentFrameTrackingData.TrackingState = (ESlTrackingState)TrackingState;
		CurrentFrameTrackingData.Timestamp = Timestamp;

		if (TrackingState == SL_POSITIONAL_TRACKING_STATE_FPS_TOO_LOW)
		{
			ZED_CAMERA_LOG_W("FPS too low for good tracking.");
		}
		else if (TrackingState == SL_POSITIONAL_TRACKING_STATE_SEARCHING)
		{
			ZED_CAMERA_LOG_W("Tracking trying to relocate.");
		}

		// Get the IMU rotation
		if (TrackingState == SL_POSITIONAL_TRACKING_STATE_OK ||
			TrackingState == SL_POSITIONAL_TRACKING_STATE_FPS_TOO_LOW ||
			TrackingState == SL_POSITIONAL_TRACKING_STATE_SEARCHING)
		{
			CurrentFrameTrackingData.ZedPathTransform = sl::unreal::ToUnrealType(Pose).Transform;
		}

		if (GSlCameraProxy->GetCameraModel() != ESlModel::M_Zed)
		{
			sl::Rotation imuPose;
			SL_ERROR_CODE IMUErrorCode  = GSlCameraProxy->GetCameraIMURotationAtImage(imuPose);
			if (IMUErrorCode == SL_ERROR_CODE_SUCCESS)
			{
				CurrentFrameTrackingData.IMURotator = sl::unreal::ToUnrealType(imuPose).Rotator();
			}
			else
			{
				ZED_CAMERA_LOG_E("Error while getting IMU data : \"%i\"", ErrorCode);
			}

		}
	SL_SCOPE_UNLOCK
}

void AZEDCamera::CreateLeftTextures(bool bCreateColorTexture/* = true*/)
{
	if (bCreateColorTexture)
	{
		FIntPoint Resolution = GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution;

		LeftEyeColor = USlViewTexture::CreateGPUViewTexture("LeftEyeColor", Resolution.X, Resolution.Y, ImageView, true, ESlTextureFormat::TF_R8G8B8A8_SNORM);
	}

	if (RuntimeParameters.bEnableDepth)
	{
		FIntPoint TextureSize = GetSlTextureSizeFromPreset(CurrentDepthTextureQualityPreset);

		LeftEyeDepth = USlMeasureTexture::CreateGPUMeasureTexture("LeftEyeDepth", TextureSize.X, TextureSize.Y, ESlMeasure::M_Depth, true, ESlTextureFormat::TF_R32_FLOAT);
	}
}

void AZEDCamera::EnableMultiThreadedRenderingMode(const bool EnableMTR)
{
	GSlCameraProxy->EnableGrabThread(EnableMTR);
}

void AZEDCamera::SetDepthClampThreshold(const float DepthDistance) {
	if (ZedLeftEyeMaterialInstanceDynamic) {
		ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("MaxDepth", DepthDistance);
	}
}

void AZEDCamera::SetDepthOcclusion(const bool EnableOcclusion) {
	if (ZedLeftEyeMaterialInstanceDynamic) {
		ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("DepthOcclusion", bDepthOcclusion);
	}
}

void AZEDCamera::SetRuntimeParameters(const FSlRuntimeParameters& NewValue)
{
	RuntimeParameters = NewValue;
	GSlCameraProxy->SetRuntimeParameters(RuntimeParameters);
}

void AZEDCamera::SetObjectDetectionRuntimeParameters(const FSlObjectDetectionRuntimeParameters& NewValue)
{
	ObjectDetectionRuntimeParameters = NewValue;
	GSlCameraProxy->SetObjectDetectionRuntimeParameters(ObjectDetectionRuntimeParameters);
}

void AZEDCamera::SetBodyTrackingRuntimeParameters(const FSlBodyTrackingRuntimeParameters& NewValue)
{
	BodyTrackingRuntimeParameters = NewValue;
	GSlCameraProxy->SetBodyTrackingRuntimeParameters(BodyTrackingRuntimeParameters);
}

FSlBodyTrackingRuntimeParameters AZEDCamera::GetBodyTrackingRuntimeParameters()
{
	return GSlCameraProxy->GetBodyTrackingRuntimeParameters();
}

void AZEDCamera::SetCameraSettings(const FSlVideoSettings& NewValue)
{
	if (NewValue.bDefault)
	{
		CameraSettings = FSlVideoSettings();
		CameraSettings.bDefault = true;
	}
	else
	{
		CameraSettings = NewValue;
	}

	GSlCameraProxy->SetCameraSettings(CameraSettings);

	bool bAutoGainAndExposure = CameraSettings.bAutoGainAndExposure;
	bool bAutoWhiteBalance = CameraSettings.bAutoWhiteBalance;

	CameraSettings = GSlCameraProxy->GetCameraSettings();
	CameraSettings.bAutoGainAndExposure = bAutoGainAndExposure;
	CameraSettings.bAutoWhiteBalance = bAutoWhiteBalance;
}


void AZEDCamera::EnableTracking()
{
	GSlCameraProxy->EnableTracking(TrackingParameters);
}

void AZEDCamera::EnableObjectDetection()
{
	GSlCameraProxy->EnableObjectDetection(ObjectDetectionParameters);

	GSlCameraProxy->EnableObjectDetectionThread(true);
}

void AZEDCamera::DisableObjectDetection()
{
	if (GSlCameraProxy->IsObjectDetectionEnabled()) GSlCameraProxy->DisableObjectDetection();

	GSlCameraProxy->EnableObjectDetectionThread(false);
}

void AZEDCamera::EnableBodyTracking()
{
	GSlCameraProxy->EnableBodyTracking(BodyTrackingParameters);

	GSlCameraProxy->EnableBodyTrackingThread(true);
}

void AZEDCamera::DisableBodyTracking()
{
	if (GSlCameraProxy->IsBodyTrackingEnabled()) GSlCameraProxy->DisableBodyTracking();

	GSlCameraProxy->EnableBodyTrackingThread(false);
}

void AZEDCamera::DisableTracking()
{
	GSlCameraProxy->DisableTracking();
	}

void AZEDCamera::ResetTrackingOrigin()
{

	GSlCameraProxy->ResetTracking(TrackingParameters.Rotation, TrackingParameters.Location);

}

void AZEDCamera::SaveSpatialMemoryArea()
{
	GSlCameraProxy->SaveSpatialMemoryArea(TrackingParameters.AreaFilePath);
}

void AZEDCamera::InitializeParameters(AZEDInitializer* ZedInitializer)
{
	TrackingParameters = ZedInitializer->TrackingParameters;
	InitParameters = ZedInitializer->InitParameters;
	RuntimeParameters = ZedInitializer->RuntimeParameters;
	RenderingParameters = ZedInitializer->RenderingParameters;
	CameraSettings = ZedInitializer->CameraSettings;
	RecordingParameters = ZedInitializer->RecordingParameters;
	bDepthOcclusion = ZedInitializer->bDepthOcclusion;
	bShowZedImage = ZedInitializer->bShowZedImage;
	ImageView = ZedInitializer->ImageView;

	ObjectDetectionParameters = ZedInitializer->ObjectDetectionParameters;
	ObjectDetectionRuntimeParameters = ZedInitializer->ObjectDetectionRuntimeParameters;

	BodyTrackingParameters = ZedInitializer->BodyTrackingParameters;
	BodyTrackingRuntimeParameters = ZedInitializer->BodyTrackingRuntimeParameters;

	DepthClampThreshold = ZedInitializer->DepthClampThreshold;

	bCurrentDepthEnabled = RuntimeParameters.bEnableDepth;

	checkf(RuntimeParameters.ReferenceFrame == ESlReferenceFrame::RF_World, TEXT("Reference frame must be World when using the ZEDCamera"));
}

void AZEDCamera::Init()
{
	if (bInit)
	{
		return;
	}

	Batch = USlGPUTextureBatch::CreateGPUTextureBatch(FName("ZedCameraBatch"));

	if (InitParameters.bLoop)
	{
		GSlCameraProxy->SetSVOPlaybackLooping(true);
	}

	SetCameraSettings(CameraSettings);
	SetRuntimeParameters(RuntimeParameters);
	SetObjectDetectionRuntimeParameters(ObjectDetectionRuntimeParameters);
	SetBodyTrackingRuntimeParameters(BodyTrackingRuntimeParameters);
	EnableMultiThreadedRenderingMode(true);

	ZedLeftEyeMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(ZedSourceMaterial, nullptr);
	ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("MinDepth", InitParameters.DepthMinimumDistance);
	ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("MaxDepth", InitParameters.DepthMaximumDistance);
	ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("DepthOcclusion", bDepthOcclusion);

	CreateLeftTextures();
	ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Color", LeftEyeColor->Texture);
	ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);

	Batch->AddTexture(LeftEyeColor);

	if (bCurrentDepthEnabled)
	{
		Batch->AddTexture(LeftEyeDepth);
	
	}

	GrabDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
	{
		GrabCallback(ErrorCode, Timestamp);
	});

	InitializeRenderingCpp();

	OnCameraActorInitialized.Broadcast();

	bInit = true;
}


void AZEDCamera::CameraClosed()
{
	GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
	DisableObjectDetection();

	if (Batch) Batch->Clear();
	if (LeftEyeColor) {
		LeftEyeColor->ConditionalBeginDestroy();
	}
	if (LeftEyeDepth) {
		LeftEyeDepth->ConditionalBeginDestroy();
	}
	bInit = false;
}

ESlErrorCode AZEDCamera::EnableSVORecording()
{
	return GSlCameraProxy->EnableSVORecording(RecordingParameters);
}

void AZEDCamera::DisableSVORecording()
{
	GSlCameraProxy->DisableSVORecording();
}

void AZEDCamera::SetSVOPlaybackLooping(bool bLooping)
{
	GSlCameraProxy->SetSVOPlaybackLooping(bLooping);
}

void AZEDCamera::ToggleComponents(bool enable)
{
	LeftPlane->SetVisibility(enable);
	LeftCamera->SetActive(enable);
}

void AZEDCamera::SetupComponents()
{
	// Rectified camera param used for the setup (left = right in rectified)
	FSlCameraParameters cameraParam = USlFunctionLibrary::GetCameraProxy()->CameraInformation.CalibrationParameters.LeftCameraParameters;

	// Setup final plane material and render targets
	LeftEyeRenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), cameraParam.Resolution.X, cameraParam.Resolution.Y, ETextureRenderTargetFormat::RTF_RGBA8);
	LeftCamera->TextureTarget = LeftEyeRenderTarget;
	LeftCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;

	// Set camera FOV
	LeftCamera->FOVAngle = cameraParam.HFOV;
	
	LeftRoot->SetRelativeLocation(FVector(CameraRenderPlaneDistance, 0, 0));
	// Set plane size
	SetPlaneSize(LeftPlane, CameraRenderPlaneDistance);

	// Set inter planes materials
	LeftPlane->SetMaterial(0, ZedLeftEyeMaterialInstanceDynamic);

	// Set camera projection matrix
	LeftCamera->bUseCustomProjectionMatrix = true;
	USlFunctionLibrary::GetSceneCaptureProjectionMatrix(LeftCamera->CustomProjectionMatrix, ESlEye::E_Left);
}

void AZEDCamera::SetPlaneSizeWithGamma(UStaticMeshComponent* plane, float planeDistance)
{
	FSlCameraParameters cameraParam = USlFunctionLibrary::GetCameraProxy()->CameraInformation.CalibrationParameters.LeftCameraParameters;

	FVector2D planeSize = USlFunctionLibrary::GetRenderPlaneSizeWithGamma(this, cameraParam.Resolution, RenderingParameters.PerceptionDistance, cameraParam.HFocal, planeDistance/100.0f); // because plane is already of side 100
	plane->SetWorldScale3D(FVector(planeSize.X, planeSize.Y, 1.0f));
}

void AZEDCamera::SetPlaneSize(UStaticMeshComponent* plane, float planeDistance)
{
	FSlCameraParameters cameraParam = USlFunctionLibrary::GetCameraProxy()->CameraInformation.CalibrationParameters.LeftCameraParameters;

	FVector2D planeSize = USlFunctionLibrary::GetRenderPlaneSize(cameraParam.Resolution, cameraParam.VFOV, planeDistance/100.0f); // because plane is already of side 100
	plane->SetWorldScale3D(FVector(planeSize.X, planeSize.Y, 1.0f));
}

void AZEDCamera::AddOrUpdatePostProcessCpp(UMaterialInterface* NewPostProcess, float NewWeight)
{
	LeftCamera->AddOrUpdateBlendable(NewPostProcess, NewWeight);
}

void AZEDCamera::DisableRenderingCpp()
{
	ToggleComponents(false);
}

void AZEDCamera::InitializeRenderingCpp()
{
	SetupComponents();
	if (bShowZedImage) 
	{
		ToggleComponents(true);
	}
	else 
	{
		ToggleComponents(false);
	}
}
