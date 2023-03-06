//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDCamera.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "ZED/Public/Core/ZEDPlayerController.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"
#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/KismetRenderingLibrary.h"

#include <sl_mr_core/Rendering.hpp>
#include <sl_mr_core/latency.hpp>
#include <sl_mr_core/antidrift.hpp>

#include "IXRTrackingSystem.h"

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
	//LeftEyeNormals(nullptr),
	RightEyeColor(nullptr),
	RightEyeDepth(nullptr),
	//RightEyeNormals(nullptr),
	LeftEyeRenderTarget(nullptr),
	RightEyeRenderTarget(nullptr),
	HMDRenderPlaneDistance(1000.0f),
	RenderingMode(ESlRenderingMode::RM_None),
	bUseHMDTrackingAsOrigin(false),
	Batch(nullptr),
	CurrentDepthTextureQualityPreset(1),
	bPositionalTrackingInitialized(false),
	bHMDHasTrackers(false),
	bCurrentDepthEnabled(false),
	bInit(false),
	bShowZedImage(true),
	ImageView(ESlView::V_Left)
{
	// Controller tick the camera to make it the first actor to tick
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial> ZedMaterial(TEXT("Material'/Stereolabs/ZED/Materials/Mono/M_ZED_Mono.M_ZED_Mono'"));
	ZedSourceMaterial = ZedMaterial.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial> HMDLeftEyeMaterial(TEXT("Material'/Stereolabs/ZED/Materials/Stereo/M_ZED_HMDLeftEye.M_ZED_HMDLeftEye'"));
	HMDLeftEyeSourceMaterial = HMDLeftEyeMaterial.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial> HMDRightEyeMaterial(TEXT("Material'/Stereolabs/ZED/Materials/Stereo/M_ZED_HMDRightEye.M_ZED_HMDRightEye'"));
	HMDRightEyeSourceMaterial = HMDRightEyeMaterial.Object;

	// components creation
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	InterLeftRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InterLeftRoot"));
	InterLeftPlaneRotationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InterLeftPlaneRotationRoot"));
	InterLeftPlaneTranslationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InterLeftPlaneTranslationRoot"));
	InterRightRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InterRightRoot"));
	InterRightPlaneRotationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InterRightPlaneRotationRoot"));
	InterRightPlaneTranslationRoot = CreateDefaultSubobject<USceneComponent>(TEXT("InterRightPlaneTranslationRoot"));
	InterLeftCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("InterLeftCamera"));
	InterRightCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("InterRightCamera"));
	InterLeftPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InterLeftPlane"));
	InterRightPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InterRightPlane"));
	FinalRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FinalRoot"));
	FinalTwRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FinalTwRoot"));
	FinalLeftPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FinalLeftPlane"));
	FinalRightPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FinalRightPlane"));

	// Attachment
	InterLeftRoot->SetupAttachment(RootComponent);
	InterRightRoot->SetupAttachment(InterLeftRoot);
	InterLeftPlaneRotationRoot->SetupAttachment(InterLeftRoot);
	InterRightPlaneRotationRoot->SetupAttachment(InterRightRoot);
	InterLeftPlaneTranslationRoot->SetupAttachment(InterLeftPlaneRotationRoot);
	InterRightPlaneTranslationRoot->SetupAttachment(InterRightPlaneRotationRoot);
	InterLeftCamera->SetupAttachment(InterLeftRoot);
	InterRightCamera->SetupAttachment(InterRightRoot);
	InterLeftPlane->SetupAttachment(InterLeftPlaneTranslationRoot);
	InterRightPlane->SetupAttachment(InterRightPlaneTranslationRoot);
	FinalRoot->SetupAttachment(RootComponent);
	FinalTwRoot->SetupAttachment(FinalRoot);
	FinalLeftPlane->SetupAttachment(FinalTwRoot);
	FinalRightPlane->SetupAttachment(FinalTwRoot);

	// Initial camera setup
	InterLeftCamera->bCaptureEveryFrame = true;
	InterLeftCamera->bCaptureOnMovement = false;
	InterLeftCamera->SetAutoActivate(false);
	InterRightCamera->bCaptureEveryFrame = true;
	InterRightCamera->bCaptureOnMovement = false;
	InterRightCamera->SetAutoActivate(false);

	// Add static mesh to planes
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlaneMesh(TEXT("StaticMesh'/Stereolabs/ZED/Shapes/SM_Plane_100x100.SM_Plane_100x100'"));
	InterLeftPlane->SetStaticMesh(PlaneMesh.Object);
	InterRightPlane->SetStaticMesh(PlaneMesh.Object);
	FinalLeftPlane->SetStaticMesh(PlaneMesh.Object);
	FinalRightPlane->SetStaticMesh(PlaneMesh.Object);

	// Initial planes rotation setup
	InterLeftPlane->SetRelativeRotation(FRotator(0, 90, 90));
	InterRightPlane->SetRelativeRotation(FRotator(0, 90, 90));
	FinalLeftPlane->SetRelativeRotation(FRotator(0, 90, 90));
	FinalRightPlane->SetRelativeRotation(FRotator(0, 90, 90));

	// Remove collision
	InterLeftPlane->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	InterRightPlane->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FinalLeftPlane->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	FinalRightPlane->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Remove shadow cast
	InterLeftPlane->SetCastShadow(false);
	InterRightPlane->SetCastShadow(false);
	FinalLeftPlane->SetCastShadow(false);
	FinalRightPlane->SetCastShadow(false);

	// Ignore Postprocessing
	InterLeftPlane->SetRenderCustomDepth(true);
	InterLeftPlane->CustomDepthStencilValue = 1;
	InterRightPlane->SetRenderCustomDepth(true);
	InterRightPlane->CustomDepthStencilValue = 1;
	FinalLeftPlane->SetRenderCustomDepth(true);
	FinalLeftPlane->CustomDepthStencilValue = 1;
	FinalRightPlane->SetRenderCustomDepth(true);
	FinalRightPlane->CustomDepthStencilValue = 1;

	InterLeftCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
	InterRightCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
	InterLeftCamera->PostProcessSettings.bOverride_VignetteIntensity = true;
	InterRightCamera->PostProcessSettings.bOverride_VignetteIntensity = true;
	InterLeftCamera->PostProcessSettings.VignetteIntensity = 0;
	InterRightCamera->PostProcessSettings.VignetteIntensity = 0;
	InterLeftCamera->PostProcessSettings.bOverride_ToneCurveAmount = true;
	InterLeftCamera->PostProcessSettings.ToneCurveAmount = 0;
	InterRightCamera->PostProcessSettings.bOverride_ToneCurveAmount = true;
	InterRightCamera->PostProcessSettings.ToneCurveAmount = 0;
	InterLeftCamera->PostProcessSettings.bOverride_BloomIntensity = true;
	InterLeftCamera->PostProcessSettings.BloomIntensity = 0;
	InterRightCamera->PostProcessSettings.bOverride_BloomIntensity = true;
	InterRightCamera->PostProcessSettings.BloomIntensity = 0;

	InterLeftCamera->PostProcessSettings.bOverride_AutoExposureBias = true;
	InterRightCamera->PostProcessSettings.bOverride_AutoExposureBias = true;
	InterLeftCamera->PostProcessSettings.AutoExposureBias = 0;
	InterRightCamera->PostProcessSettings.AutoExposureBias = 0;
	InterLeftCamera->PostProcessSettings.bOverride_AutoExposureMaxBrightness = true;
	InterLeftCamera->PostProcessSettings.bOverride_AutoExposureMinBrightness = true;
	InterRightCamera->PostProcessSettings.bOverride_AutoExposureMaxBrightness = true;
	InterRightCamera->PostProcessSettings.bOverride_AutoExposureMinBrightness = true;
	InterLeftCamera->PostProcessSettings.AutoExposureMaxBrightness = 1.0f;
	InterLeftCamera->PostProcessSettings.AutoExposureMinBrightness = 1.0f;
	InterRightCamera->PostProcessSettings.AutoExposureMaxBrightness = 1.0f;
	InterRightCamera->PostProcessSettings.AutoExposureMinBrightness = 1.0f;
	// Set light channels
	InterLeftPlane->LightingChannels.bChannel0 = false;
	InterRightPlane->LightingChannels.bChannel0 = false;
	FinalLeftPlane->LightingChannels.bChannel0 = false;
	FinalRightPlane->LightingChannels.bChannel0 = false;
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

	UHeadMountedDisplayFunctionLibrary::SetSpectatorScreenMode(ESpectatorScreenMode::SingleEyeCroppedToFill);
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

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRenderingParameters, PerceptionDistance))
	{
		UpdatePlanesSizeCpp();
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRenderingParameters, PerceptionDistance))
	{
		UpdatePlanesSizeCpp();
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

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRenderingParameters, PerceptionDistance))
	{
		return UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled();
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

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZEDCamera, bUseHMDTrackingAsOrigin))
	{
		return UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled();
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

	// Stereo update
	if (RenderingMode == ESlRenderingMode::RM_Stereo)
	{
		FVector HMDLocation;
		FRotator HMDRotation;
		UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(HMDRotation, HMDLocation);

		// HMD tracking transform
		Eigen::Matrix4f SlHMDTransform = sl::unreal::ToEigenType(FTransform(HMDRotation, HMDLocation));

		// Current timestamp
		unsigned long long CurrentTimestamp = sl_get_current_timestamp(GSlCameraProxy->GetCameraID());

		// Set IMU prior
		if (GSlCameraProxy->bTrackingEnabled && GSlCameraProxy->GetCameraModel() == ESlModel::M_ZedM)
		{
			Eigen::Matrix4f PastTransform;
			bool bTransformRetrieved = sl::mr::latencyCorrectorGetTransform(CurrentTimestamp - 44000000, PastTransform, false);
			if (bTransformRetrieved)
			{
				GSlCameraProxy->SetIMUPrior(FTransform(sl::unreal::ToUnrealType(PastTransform)));
			}
		}

		// latency transform
		Eigen::Matrix4f SlLatencyTransform = Eigen::Matrix4f::Identity();

		// Latency corrector if new image
		if(bNewImage || bUpdateTracking)
		{
			// Add key pose
			sl::mr::latencyCorrectorAddKeyPose(sl::mr::keyPose(SlHMDTransform, CurrentTimestamp));

			// Latency corrector
			sl::mr::latencyCorrectorGetTransform(TrackingData.Timestamp.timestamp, SlLatencyTransform);
			SetHMDPlanesRotationCpp(sl::unreal::ToUnrealType(SlLatencyTransform).Rotator());
		}

		// Update HMD planes location
		SetHMDPlanesLocationCpp(HMDLocation);

		if (bUpdateTracking)
		{
			// Initialize drift corrector if failed because out of tracking area
			InitializeDriftCorrectorConstOffset(HMDLocation, HMDRotation);

			// Remove HMD origin from tracking
			FZEDTrackingData TmpTrackingData = TrackingData;
			TmpTrackingData.ZedPathTransform = TmpTrackingData.ZedPathTransform * TrackingOriginFromHMD.Inverse();

			sl::mr::trackingData SlTrackingData = sl::unreal::ToSlType(TmpTrackingData);
			sl::mr::driftCorrectorGetTrackingData(SlTrackingData, SlHMDTransform, SlLatencyTransform, bHMDHasTrackers && UHeadMountedDisplayFunctionLibrary::HasValidTrackingPosition(), true);

			TrackingData.ZedWorldTransform = (FTransform)sl::unreal::ToUnrealType(SlTrackingData.zedWorldTransform);
			TrackingData.OffsetZedWorldTransform = (FTransform)sl::unreal::ToUnrealType(SlTrackingData.offsetZedWorldTransform);
		}
	}
	// Mono update
	else
	{
		TrackingData.ZedWorldTransform		 = TrackingData.ZedPathTransform;
		TrackingData.OffsetZedWorldTransform = TrackingData.ZedWorldTransform;
	}

	// Update tracking data
	if (bUpdateTracking)
	{
		if (RenderingMode == ESlRenderingMode::RM_Stereo && TrackingParameters.TrackingType == ETrackingType::TrT_HMD)
		{
			// latency transform
			Eigen::Matrix4f SlLatencyTransform;
			// Latency corrector
			sl::mr::latencyCorrectorGetTransform(TrackingData.Timestamp.timestamp, SlLatencyTransform);
			FTransform latencyTransform = (FTransform)sl::unreal::ToUnrealType(SlLatencyTransform);

			FZEDTrackingData TmpTrackingData;
			TmpTrackingData.OffsetZedWorldTransform = latencyTransform;
			TmpTrackingData.ZedWorldTransform = AntiDriftParameters.CalibrationTransform * TmpTrackingData.OffsetZedWorldTransform;
			OnTrackingDataUpdated.Broadcast(TmpTrackingData);

			GZedRawLocation = TmpTrackingData.ZedWorldTransform.GetLocation();
			GZedRawRotation = TmpTrackingData.ZedWorldTransform.Rotator();

			GZedViewPointLocation = TmpTrackingData.OffsetZedWorldTransform.GetLocation();
			GZedViewPointRotation = TmpTrackingData.OffsetZedWorldTransform.Rotator();

			GZedTrackingData = TmpTrackingData;
		}
		else if (RenderingMode == ESlRenderingMode::RM_Stereo && TrackingParameters.TrackingType == ETrackingType::TrT_Mixte)
		{
			// latency transform
			Eigen::Matrix4f SlLatencyTransform;
			// Latency corrector
			sl::mr::latencyCorrectorGetTransform(TrackingData.Timestamp.timestamp, SlLatencyTransform);
			FTransform latencyTransform = (FTransform)sl::unreal::ToUnrealType(SlLatencyTransform);

			FZEDTrackingData TmpTrackingData;
			TmpTrackingData.OffsetZedWorldTransform.SetLocation(latencyTransform.GetLocation());

			TmpTrackingData.OffsetZedWorldTransform.SetRotation((AntiDriftParameters.CalibrationTransform.Inverse() * FTransform(TrackingData.IMURotator)).GetRotation());

			TmpTrackingData.ZedWorldTransform = AntiDriftParameters.CalibrationTransform * TmpTrackingData.OffsetZedWorldTransform;

			OnTrackingDataUpdated.Broadcast(TmpTrackingData);

			GZedRawLocation = TmpTrackingData.ZedWorldTransform.GetLocation();
			GZedRawRotation = TmpTrackingData.ZedWorldTransform.Rotator();

			GZedViewPointLocation = TmpTrackingData.OffsetZedWorldTransform.GetLocation();
			GZedViewPointRotation = TmpTrackingData.OffsetZedWorldTransform.Rotator();

			GZedTrackingData = TmpTrackingData;
		}
		else
		{
			GZedTrackingData = TrackingData;

			GZedRawLocation = TrackingData.ZedWorldTransform.GetLocation();
			GZedRawRotation = TrackingData.ZedWorldTransform.Rotator();

			GZedViewPointLocation = TrackingData.OffsetZedWorldTransform.GetLocation();
			GZedViewPointRotation = TrackingData.OffsetZedWorldTransform.Rotator();

			OnTrackingDataUpdated.Broadcast(TrackingData);
		}
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

			// Left normals
			//Batch->RemoveTexture(LeftEyeNormals);
			//LeftEyeNormals->Resize(DepthSize.X, DepthSize.Y);
			//Batch->AddTexture(LeftEyeNormals);

			ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
			//ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", LeftEyeNormals->Texture);

			if (RenderingMode == ESlRenderingMode::RM_Stereo)
			{
				// Right depth
				Batch->RemoveTexture(RightEyeDepth);
				RightEyeDepth->Resize(DepthSize.X, DepthSize.Y);
				Batch->AddTexture(RightEyeDepth);

				// Right normals
				//Batch->RemoveTexture(RightEyeNormals);
				//RightEyeNormals->Resize(DepthSize.X, DepthSize.Y);
				//Batch->AddTexture(RightEyeNormals);

				ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", RightEyeDepth->Texture);
				//ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", RightEyeNormals->Texture);
			}
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
				//ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", nullptr);

				Batch->RemoveTexture(LeftEyeDepth);
				delete LeftEyeDepth;
				LeftEyeDepth = nullptr;

				//Batch->RemoveTexture(LeftEyeNormals);
				//delete LeftEyeNormals;
				//LeftEyeNormals = nullptr;

				if (RenderingMode == ESlRenderingMode::RM_Stereo)
				{
					ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", nullptr);
					//ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", nullptr);

					Batch->RemoveTexture(RightEyeDepth);
					delete RightEyeDepth;
					RightEyeDepth = nullptr;

					//Batch->RemoveTexture(RightEyeNormals);
					//delete RightEyeNormals;
					//RightEyeNormals = nullptr;
				}
			}
			else
			{
				CreateLeftTextures(false);

				Batch->AddTexture(LeftEyeDepth);
				//Batch->AddTexture(LeftEyeNormals);

				ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
				//ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", LeftEyeNormals->Texture);

				if (RenderingMode == ESlRenderingMode::RM_Stereo)
				{
					CreateRightTextures(false);

					Batch->AddTexture(RightEyeDepth);
					//Batch->AddTexture(RightEyeNormals);

					ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", RightEyeDepth->Texture);
					//ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", RightEyeNormals->Texture);
				}
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

		if (GSlCameraProxy->GetCameraModel() == ESlModel::M_ZedM || GSlCameraProxy->GetCameraModel() == ESlModel::M_Zed2 || GSlCameraProxy->GetCameraModel() == ESlModel::M_Zed2i)
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
		//LeftEyeNormals = USlMeasureTexture::CreateGPUMeasureTexture("LeftEyeNormals", TextureSize.X, TextureSize.Y, ESlMeasure::M_Normals, true, ESlTextureFormat::TF_A32B32G32R32F);
	}
}

void AZEDCamera::CreateRightTextures(bool bCreateColorTexture/* = true*/)
{
	if (bCreateColorTexture)
	{
		FIntPoint Resolution = GSlCameraProxy->CameraInformation.CalibrationParameters.RightCameraParameters.Resolution;

		RightEyeColor = USlViewTexture::CreateGPUViewTexture("RightEyeColor", Resolution.X, Resolution.Y, ESlView::V_Right, true, ESlTextureFormat::TF_R8G8B8A8_SNORM);

	}

	if (RuntimeParameters.bEnableDepth)
	{
		FIntPoint TextureSize = GetSlTextureSizeFromPreset(CurrentDepthTextureQualityPreset);

		RightEyeDepth = USlMeasureTexture::CreateGPUMeasureTexture("RightEyeDepth", TextureSize.X, TextureSize.Y, ESlMeasure::M_DepthRight, true, ESlTextureFormat::TF_R32_FLOAT);
		//RightEyeNormals = USlMeasureTexture::CreateGPUMeasureTexture("RightEyeNormals", TextureSize.X, TextureSize.Y, ESlMeasure::M_NormalsRight, true, ESlTextureFormat::TF_A32B32G32R32F);
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

	if (ZedRightEyeMaterialInstanceDynamic) {
		ZedRightEyeMaterialInstanceDynamic->SetScalarParameterValue("MaxDepth", DepthDistance);
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

	// Reset positional tracking if using HMD
	bPositionalTrackingInitialized = false;
}

void AZEDCamera::ResetTrackingOrigin()
{
	// If using an HMD, reset SDK tracking with current HMD tracking
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		InitHMDTrackingData();
	}
	else
	{
		GSlCameraProxy->ResetTracking(TrackingParameters.Rotation, TrackingParameters.Location);
	}
}

void AZEDCamera::SaveSpatialMemoryArea()
{
	GSlCameraProxy->SaveSpatialMemoryArea(TrackingParameters.AreaFilePath);
}

void AZEDCamera::InitializeParameters(AZEDInitializer* ZedInitializer, bool bHMDEnabled)
{
	TrackingParameters = ZedInitializer->TrackingParameters;
	InitParameters = ZedInitializer->InitParameters;
	RuntimeParameters = ZedInitializer->RuntimeParameters;
	RenderingParameters = ZedInitializer->RenderingParameters;
	AntiDriftParameters = ZedInitializer->AntiDriftParameters;
	CameraSettings = ZedInitializer->CameraSettings;
	RecordingParameters = ZedInitializer->RecordingParameters;
	bUseHMDTrackingAsOrigin = ZedInitializer->bUseHMDTrackingAsOrigin;
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

	if (bUseHMDTrackingAsOrigin)
	{
		TrackingParameters.Location = FVector::ZeroVector;
		TrackingParameters.Rotation = FRotator::ZeroRotator;
	}

	if (bHMDEnabled)
	{
		InitParameters.bEnableRightSideMeasure = true;
	}
}

void AZEDCamera::Init(bool bHMDEnabled)
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

	if (bHMDEnabled)
	{
		FName deviceType = GEngine->XRSystem->GetSystemName();
		if(deviceType == TEXT("OculusHMD"))
			sl::mr::latencyCorrectorInitialize(sl::mr::eHmdType_Oculus);
		else if (deviceType == TEXT("SteamVR"))
			sl::mr::latencyCorrectorInitialize(sl::mr::eHmdType_Vive);

		if (TrackingParameters.bEnableTracking)
		{
			InitHMDTrackingData();
		}

		// Set first delay to 1.0f to fix HMD planes wrong location at startup
		GetWorldTimerManager().SetTimer(PlanesAntiDriftTimerHandle, this, &AZEDCamera::CorrectHMDPlanesDriftCpp, 10.0f, true, 1.0f);
	}

	SetCameraSettings(CameraSettings);
	if (RenderingMode == ESlRenderingMode::RM_None)
	{
		RenderingMode = bHMDEnabled ? ESlRenderingMode::RM_Stereo : ESlRenderingMode::RM_Mono;
	}
	SetRuntimeParameters(RuntimeParameters);
	SetObjectDetectionRuntimeParameters(ObjectDetectionRuntimeParameters);
	EnableMultiThreadedRenderingMode(true);

	ZedLeftEyeMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(ZedSourceMaterial, nullptr);
	ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("MinDepth", InitParameters.DepthMinimumDistance);
	ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("MaxDepth", InitParameters.DepthMaximumDistance);
	ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("DepthOcclusion", bDepthOcclusion);

	CreateLeftTextures();
	ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Color", LeftEyeColor->Texture);
	ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
	//ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", LeftEyeNormals->Texture);

	Batch->AddTexture(LeftEyeColor);

	HMDLeftEyeMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(HMDLeftEyeSourceMaterial, nullptr);

	if (!bHMDEnabled)
	{
		Batch->AddTexture(LeftEyeDepth);
		//Batch->AddTexture(LeftEyeNormals);
	}
	else
	{
		GSlCameraProxy->HMDToCameraOffset = AntiDriftParameters.CalibrationTransform.GetLocation().X;

		HMDRightEyeMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(HMDRightEyeSourceMaterial, nullptr);

		ZedRightEyeMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(ZedSourceMaterial, nullptr);
		ZedRightEyeMaterialInstanceDynamic->SetScalarParameterValue("MinDepth", InitParameters.DepthMinimumDistance);
		ZedRightEyeMaterialInstanceDynamic->SetScalarParameterValue("MaxDepth", InitParameters.DepthMaximumDistance);
		ZedLeftEyeMaterialInstanceDynamic->SetScalarParameterValue("DepthOcclusion", bDepthOcclusion);

		CreateRightTextures();
		ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Color", RightEyeColor->Texture);
		if (bCurrentDepthEnabled)
		{
			ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", RightEyeDepth->Texture);
			//ZedRightEyeMaterialInstanceDynamic->SetTextureParameterValue("Normals", RightEyeNormals->Texture);
		}

		Batch->AddTexture(RightEyeColor);
		if (bCurrentDepthEnabled)
		{
			Batch->AddTexture(LeftEyeDepth);
			Batch->AddTexture(RightEyeDepth);
			/*Batch->AddTexture(LeftEyeNormals);
			Batch->AddTexture(RightEyeNormals);*/
		}
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
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		sl::mr::driftCorrectorShutdown();
		sl::mr::latencyCorrectorShutdown();

		GetWorldTimerManager().ClearTimer(PlanesAntiDriftTimerHandle);
	}

	GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
	DisableObjectDetection();
	UHeadMountedDisplayFunctionLibrary::SetSpectatorScreenMode(ESpectatorScreenMode::SingleEyeCroppedToFill);

	if (Batch) Batch->Clear();
	if (LeftEyeColor) {
		LeftEyeColor->ConditionalBeginDestroy();
	}
	//if (LeftEyeNormals) {
	//	LeftEyeNormals->ConditionalBeginDestroy();
	//}
	if (LeftEyeDepth) {
		LeftEyeDepth->ConditionalBeginDestroy();
	}
	if (RightEyeColor) {
		RightEyeColor->ConditionalBeginDestroy();
	}
	//if (RightEyeNormals) {
	//	RightEyeNormals->ConditionalBeginDestroy();
	//}
	if (RightEyeDepth) {
		RightEyeDepth->ConditionalBeginDestroy();
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

void AZEDCamera::InitHMDTrackingData()
{
	sl::mr::driftCorrectorInitialize();

	sl::mr::driftCorrectorSetCalibrationTransform(sl::unreal::ToEigenType(AntiDriftParameters.CalibrationTransform));
	if (!bUseHMDTrackingAsOrigin)
	{
		sl::mr::driftCorrectorSetTrackingOffsetTransfrom(sl::unreal::ToEigenType(FTransform(TrackingParameters.Rotation, TrackingParameters.Location)));
	}
	else
	{
		sl::mr::driftCorrectorSetTrackingOffsetTransfrom(sl::unreal::ToEigenType(FTransform()));
	}

	bHMDHasTrackers = (UHeadMountedDisplayFunctionLibrary::GetNumOfTrackingSensors() > 0);

	FVector HMDLocation;
	FRotator HMDRotation;
	UHeadMountedDisplayFunctionLibrary::GetOrientationAndPosition(HMDRotation, HMDLocation);
	InitializeDriftCorrectorConstOffset(HMDLocation, HMDRotation);
}

bool AZEDCamera::InitializeDriftCorrectorConstOffset(const FVector& HMDLocation, const FRotator& HMDRotation)
{
	// If trackers and already initialized
	if (bPositionalTrackingInitialized)
	{
		return true;
	}

	bool bHasValidTrackingPosition = UHeadMountedDisplayFunctionLibrary::HasValidTrackingPosition();

	if (!bHMDHasTrackers ||
		bHMDHasTrackers && bHasValidTrackingPosition)
	{
		if (bUseHMDTrackingAsOrigin)
		{
			TrackingOriginFromHMD = FTransform(HMDRotation, HMDLocation) * AntiDriftParameters.CalibrationTransform;

			// Set HMD tracking data
			TrackingParameters.Location = TrackingOriginFromHMD.GetLocation();
			TrackingParameters.Rotation = TrackingOriginFromHMD.Rotator();
		}
		else
		{
			TrackingOriginFromHMD = FTransform(HMDRotation, HMDLocation) * FTransform(TrackingParameters.Rotation, TrackingParameters.Location) * AntiDriftParameters.CalibrationTransform;
		}

		GSlCameraProxy->ResetTracking(TrackingOriginFromHMD.Rotator(), TrackingOriginFromHMD.GetLocation());

		//if (GSlCameraProxy->GetCameraModel() == ESlModel::M_ZedM)
		//{
		//	sl::mr::driftCorrectorSetConstOffsetTransfrom(sl::unreal::ToSlType(AntiDriftParameters.CalibrationTransform * FTransform(FRotator::ZeroRotator, HMDLocation)));
		//}
		//else
		//{
			sl::mr::driftCorrectorSetConstOffsetTransfrom(sl::unreal::ToEigenType(AntiDriftParameters.CalibrationTransform * FTransform(HMDRotation, HMDLocation)));
		//}

		bPositionalTrackingInitialized = true;

		return true;
	}

	return false;
}

void AZEDCamera::AdjustLatencyCorrectionOffset(const unsigned long long time)
{
	sl::mr::latencyCorrectorAdjOffset(sl::Timestamp(time));
}

void AZEDCamera::ToggleFinalComponents(bool enable, bool stereo)
{
	FinalLeftPlane->SetVisibility(enable);
	if(stereo)
		FinalRightPlane->SetVisibility(enable);
	else
		FinalRightPlane->SetVisibility(false);
}

void AZEDCamera::ToggleInterComponents(bool enable, bool stereo)
{
	InterLeftPlane->SetVisibility(enable);
	InterLeftCamera->SetActive(enable);
	if (stereo)
	{
		InterRightPlane->SetVisibility(enable);
		InterRightCamera->SetActive(enable);
	}
	else
	{
		InterRightPlane->SetVisibility(false);
		InterRightCamera->SetActive(false);
	}
}

void AZEDCamera::SetupComponents(bool stereo)
{
	// Rectified camera param used for the setup (left = right in rectified)
	FSlCameraParameters cameraParam = USlFunctionLibrary::GetCameraProxy()->CameraInformation.CalibrationParameters.LeftCameraParameters;

	// Setup final plane material and render targets
	LeftEyeRenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), cameraParam.Resolution.X, cameraParam.Resolution.Y, ETextureRenderTargetFormat::RTF_RGBA8);
	HMDLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("RealVirtual", LeftEyeRenderTarget);
	InterLeftCamera->TextureTarget = LeftEyeRenderTarget;
	InterLeftCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
	FinalLeftPlane->SetMaterial(0, HMDLeftEyeMaterialInstanceDynamic);
	if (stereo)
	{
		RightEyeRenderTarget = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(), cameraParam.Resolution.X, cameraParam.Resolution.Y, ETextureRenderTargetFormat::RTF_RGBA8);
		HMDRightEyeMaterialInstanceDynamic->SetTextureParameterValue("RealVirtual", RightEyeRenderTarget);
		InterRightCamera->TextureTarget = RightEyeRenderTarget;
		InterRightCamera->CaptureSource = ESceneCaptureSource::SCS_FinalColorHDR;
		FinalRightPlane->SetMaterial(0, HMDRightEyeMaterialInstanceDynamic);
	}

	// Set camera FOV
	InterLeftCamera->FOVAngle = cameraParam.HFOV;
	if (stereo)
		InterRightCamera->FOVAngle = cameraParam.HFOV;

	// Set plane size
	SetPlaneSize(InterLeftPlane, CameraRenderPlaneDistance);
	if (stereo)
	{
		SetPlaneSize(InterRightPlane, CameraRenderPlaneDistance);
		if (RenderingParameters.SRemapEnable)
		{
			FVector2D HmdFocal = USlFunctionLibrary::GetHmdFocale();
			float finalPlaneDistanceSRemap = HMDRenderPlaneDistance * cameraParam.HFocal / ((HmdFocal.X + HmdFocal.Y) / 2.0f);
			SetPlaneSize(FinalLeftPlane, finalPlaneDistanceSRemap);
			SetPlaneSize(FinalRightPlane, finalPlaneDistanceSRemap);
		}
		else
		{
			SetPlaneSizeWithGamma(FinalLeftPlane, HMDRenderPlaneDistance);
			SetPlaneSizeWithGamma(FinalRightPlane, HMDRenderPlaneDistance);
		}
	}
	else
	{
		SetPlaneSize(FinalLeftPlane, HMDRenderPlaneDistance);
	}


	// Inter baseline offset
	if (stereo)
		InterRightRoot->SetRelativeLocation(FVector(0, 2.0f*USlFunctionLibrary::GetCameraProxy()->CameraInformation.HalfBaseline, 0));

	// Forward offset Inter
	InterLeftPlaneTranslationRoot->SetRelativeLocation(FVector(CameraRenderPlaneDistance, 0, 0));
	if (stereo)
		InterRightPlaneTranslationRoot->SetRelativeLocation(FVector(CameraRenderPlaneDistance, 0, 0));

	// Forward offset + optical center offset + baseline offset (Final planes)
	FVector4 opticalCenterOffsetsFinal = USlFunctionLibrary::GetOpticalCentersOffsets(cameraParam.Resolution, HMDRenderPlaneDistance);
	FinalLeftPlane->SetRelativeLocation(FVector(HMDRenderPlaneDistance, opticalCenterOffsetsFinal.X, -opticalCenterOffsetsFinal.Y));
	FinalLeftPlane->AddLocalOffset(FVector(-USlFunctionLibrary::GetCameraProxy()->CameraInformation.HalfBaseline, 0, 0));
	if (stereo)
	{
		FinalRightPlane->SetRelativeLocation(FVector(HMDRenderPlaneDistance, opticalCenterOffsetsFinal.Z, -opticalCenterOffsetsFinal.W));
		FinalRightPlane->AddLocalOffset(FVector(USlFunctionLibrary::GetCameraProxy()->CameraInformation.HalfBaseline, 0, 0));
	}

	// Optical center and baseline offsets (Inter planes)
	FVector4 opticalCenterOffsets = USlFunctionLibrary::GetOpticalCentersOffsets(cameraParam.Resolution, CameraRenderPlaneDistance);
	InterLeftPlane->SetRelativeLocation(FVector(0, opticalCenterOffsets.X, -opticalCenterOffsets.Y));
	if (stereo)
		InterRightPlane->SetRelativeLocation(FVector(0, opticalCenterOffsets.Z, -opticalCenterOffsets.W));

	// Set inter planes materials
	InterLeftPlane->SetMaterial(0, ZedLeftEyeMaterialInstanceDynamic);
	if (stereo)
		InterRightPlane->SetMaterial(0, ZedRightEyeMaterialInstanceDynamic);

	// Set camera projection matrix
	InterLeftCamera->bUseCustomProjectionMatrix = true;
	USlFunctionLibrary::GetSceneCaptureProjectionMatrix(InterLeftCamera->CustomProjectionMatrix, ESlEye::E_Left);
	if (stereo)
	{
		InterRightCamera->bUseCustomProjectionMatrix = true;
		USlFunctionLibrary::GetSceneCaptureProjectionMatrix(InterRightCamera->CustomProjectionMatrix, ESlEye::E_Right);

	// Set calibration Zed-HMD
		InterLeftRoot->SetRelativeLocation(AntiDriftParameters.CalibrationTransform.GetLocation());
		InterLeftPlaneRotationRoot->SetRelativeRotation(AntiDriftParameters.CalibrationTransform.GetRotation());
		InterRightPlaneRotationRoot->SetRelativeRotation(AntiDriftParameters.CalibrationTransform.GetRotation());
		UHeadMountedDisplayFunctionLibrary::SetSpectatorScreenTexture(InterLeftCamera->TextureTarget);
		UHeadMountedDisplayFunctionLibrary::SetSpectatorScreenMode(ESpectatorScreenMode::Texture);
	}

	// Show only list management
	InterLeftCamera->HideComponent(FinalLeftPlane);
	InterLeftCamera->HideComponent(FinalRightPlane);

	if (bShowZedImage) {
		UZEDFunctionLibrary::GetPlayerController(this)->bUseShowOnlyList = true;
		UZEDFunctionLibrary::GetPlayerController(this)->EmptyShowOnlyComponentList();
		UZEDFunctionLibrary::GetPlayerController(this)->AddShowOnlyComponent(FinalLeftPlane);
	}
	else {
		UZEDFunctionLibrary::GetPlayerController(this)->bUseShowOnlyList = false;
	}
	if (stereo)
	{
		InterRightCamera->HideComponent(FinalLeftPlane);
		InterRightCamera->HideComponent(FinalRightPlane);
		UZEDFunctionLibrary::GetPlayerController(this)->AddShowOnlyComponent(FinalRightPlane);
	}
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
	InterLeftCamera->AddOrUpdateBlendable(NewPostProcess, NewWeight);
	InterRightCamera->AddOrUpdateBlendable(NewPostProcess, NewWeight);
}

void AZEDCamera::SetHMDPlanesLocationCpp(const FVector& NewLocation)
{
	FinalRoot->SetRelativeLocation(NewLocation);
}

void AZEDCamera::SetHMDPlanesRotationCpp(const FRotator& Rotation)
{
	FinalTwRoot->SetRelativeRotation(Rotation);
}

void AZEDCamera::CorrectHMDPlanesDriftCpp()
{
	FinalTwRoot->SetRelativeLocation(FVector(0,0,0));
}

void AZEDCamera::DisableRenderingCpp()
{
	bool stereo = false;
	if (RenderingMode == ESlRenderingMode::RM_Stereo)
		stereo = true;

	ToggleInterComponents(false, stereo);
	ToggleFinalComponents(false, stereo);
}

void AZEDCamera::InitializeRenderingCpp()
{
	bool stereo = false;
	if (RenderingMode == ESlRenderingMode::RM_Stereo)
		stereo = true;

	SetupComponents(stereo);
	if (bShowZedImage) {
		ToggleInterComponents(true, stereo);
		ToggleFinalComponents(true, stereo);
	}
	else {
		ToggleInterComponents(false, stereo);
		ToggleFinalComponents(false, stereo);
	}
}

void AZEDCamera::UpdatePlanesSizeCpp()
{
	if (RenderingMode == ESlRenderingMode::RM_Stereo)
	{
		if (RenderingParameters.SRemapEnable)
		{
			FSlCameraParameters cameraParam = USlFunctionLibrary::GetCameraProxy()->CameraInformation.CalibrationParameters.LeftCameraParameters;
			FVector2D HmdFocal = USlFunctionLibrary::GetHmdFocale();
			float finalPlaneDistanceSRemap = HMDRenderPlaneDistance * cameraParam.HFOV / ((HmdFocal.X + HmdFocal.Y) / 2.0f);
			SetPlaneSize(FinalLeftPlane, finalPlaneDistanceSRemap);
			SetPlaneSize(FinalRightPlane, finalPlaneDistanceSRemap);
		}
		else
		{
			SetPlaneSizeWithGamma(FinalLeftPlane, HMDRenderPlaneDistance);
			SetPlaneSizeWithGamma(FinalRightPlane, HMDRenderPlaneDistance);
		}
	}
	else
	{
		SetPlaneSizeWithGamma(FinalLeftPlane, HMDRenderPlaneDistance);
	}
}
