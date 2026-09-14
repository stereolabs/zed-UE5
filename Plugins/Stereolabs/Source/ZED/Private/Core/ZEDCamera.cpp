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
#include "Engine/TextureRenderTarget2D.h"

DEFINE_LOG_CATEGORY(ZEDCamera);

#if WITH_EDITOR
#define ZED_CONFIG_FILE_PATH			FPaths::Combine(*FPaths::ProjectDir(), *FString("Saved/Config/ZED/ZED.ini"))
#define ZED_CAMERA_CONFIG_FILE_PATH     FPaths::Combine(*FPaths::ProjectDir(), *FString("Saved/Config/ZED/Camera.ini"))
#define DEFAULT_VERBOSE_FILE_PATH       FPaths::Combine(*FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()), *FString("Binaries/Win64/ZedLog.txt"))
#else
#define ZED_CONFIG_FILE_PATH			FPaths::Combine(*FPaths::ConvertRelativePathToFull("../../"), *FString("Saved/Config/ZED/ZED.ini"))
#define ZED_CAMERA_CONFIG_FILE_PATH     FPaths::Combine(*FPaths::ConvertRelativePathToFull("../../"), *FString("Saved/Config/ZED/Camera.ini"))
#define DEFAULT_VERBOSE_FILE_PATH       FPaths::Combine(*FPaths::ConvertRelativePathToFull("."),      *FString("ZedLog.txt"))
#endif

static bool IsGConfigAvailable()
{
	if (!GConfig)
	{
		SL_LOG_E(ZEDCamera, "GConfig not available");
		return false;
	}

	return true;
}

static FString GetParameterGroupConfigPath(EZEDParameterGroup Group)
{
	return Group == EZEDParameterGroup::PG_CameraSettings ? ZED_CAMERA_CONFIG_FILE_PATH : ZED_CONFIG_FILE_PATH;
}

#define ZED_CAMERA_LOG(Format, ...) SL_LOG(ZEDCamera, Format, ##__VA_ARGS__)
#define ZED_CAMERA_LOG_W(Format, ...) SL_LOG_W(ZEDCamera, Format, ##__VA_ARGS__)
#define ZED_CAMERA_LOG_E(Format, ...) SL_LOG_E(ZEDCamera, Format, ##__VA_ARGS__)
#define ZED_CAMERA_LOG_F(Format, ...) SL_LOG_F(ZEDCamera, Format, ##__VA_ARGS__)

AZEDCamera::AZEDCamera()
	:
	LeftEyeColor(nullptr),
	LeftEyeDepth(nullptr),
	LeftEyeRenderTarget(nullptr),
	DepthResolution( ESlDepthResolution::DR_Half ),
	DepthResolutionInPixels( ForceInit ),
	ImageView( ESlView::V_Left ),
	CameraRenderPlaneDistance( 0.f ),
	ZedLeftEyeMaterialInstanceDynamic( nullptr ),
	bShowZedImage( true ),
	bLoadParametersFromConfigFile( false ),
	bLoadCameraSettingsFromConfigFile( false ),
	bDepthOcclusion( true ),
	DepthClampThreshold( 0.f ),
	Batch( nullptr ),
	ZedSourceMaterial( nullptr ),
	bCurrentDepthEnabled( false ),
	bInit( false ),
	LeftRoot( nullptr ),
	LeftCamera( nullptr ),
	LeftPlane( nullptr ),
	ViewCamera( nullptr )
{
	if (InitParameters.VerboseFilePath.IsEmpty())
	{
		InitParameters.VerboseFilePath = DEFAULT_VERBOSE_FILE_PATH;
	}

	DepthClampThreshold = InitParameters.DepthMaximumDistance;

	// Controller tick the camera to make it the first actor to tick
	PrimaryActorTick.bCanEverTick = false;

	static ConstructorHelpers::FObjectFinder<UMaterial> ZedMaterial(TEXT("Material'/Stereolabs/ZED/Materials/Mono/M_ZED_Mono.M_ZED_Mono'"));
	ZedSourceMaterial = ZedMaterial.Object;

	// components creation
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	LeftRoot = CreateDefaultSubobject<USceneComponent>(TEXT("LeftRoot"));
	LeftCamera = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("LeftCamera"));
	LeftPlane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftPlane"));
	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));

	// The capture sits at the actor origin, the plane root is pushed in front of it
	LeftRoot->SetupAttachment(RootComponent);
	LeftCamera->SetupAttachment(RootComponent);
	LeftPlane->SetupAttachment(LeftRoot);

	// The optical origin is the actor origin, not the offset render plane root
	ViewCamera->SetupAttachment(RootComponent);

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

	// Hidden while the camera is not opened, so a level-placed camera does not show a bare plane.
	// Rendering re-enables it through InitializeRenderingCpp.
	LeftPlane->SetVisibility(false);
}

void AZEDCamera::BeginPlay()
{
	Super::BeginPlay();

	// A level-placed camera can exist in a world without a ZED game instance (no camera proxy)
	if (GSlCameraProxy)
	{
		GSlCameraProxy->OnCameraClosed.AddDynamic(this, &AZEDCamera::CameraClosed);
	}
	else
	{
		ZED_CAMERA_LOG_E("No camera proxy available: the game instance must inherit from UZEDGameInstance");
	}

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

	const FProperty* Property = PropertyChangedEvent.Property;
	FName PropertyName = Property ? Property->GetFName() : NAME_None;

	if (Property && Property->GetOwnerStruct())
	{
		FString StructName = Property->GetOwnerStruct()->GetName();
		if (StructName == FString("SlVideoSettings"))
		{
			SetCameraSettings(CameraSettings);
		}

		if (StructName == FString("SlRuntimeParameters"))
		{
			SetRuntimeParameters(RuntimeParameters);
		}
	}
	// A whole struct is replaced at once by the load, reset and undo of a parameter group
	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZEDCamera, CameraSettings))
	{
		SetCameraSettings(CameraSettings);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZEDCamera, RuntimeParameters))
	{
		SetRuntimeParameters(RuntimeParameters);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZEDCamera, InitParameters))
	{
		GSlCameraProxy->SetSVOPlaybackLooping(InitParameters.bLoop);
		SetDepthClampThreshold(DepthClampThreshold);
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

	if (PropertyName == GET_MEMBER_NAME_CHECKED(AZEDCamera, EditorPreviewPlaneDistance) && bInit)
	{
		SetEditorPreviewPlaneDistance();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool AZEDCamera::CanEditChange(const FProperty* InProperty) const
{
	if (!InProperty)
	{
		return Super::CanEditChange(InProperty);
	}

	FName PropertyName = InProperty->GetFName();

	// Design time (level editor, no camera session): authoring rules
	if (!GSlCameraProxy)
	{
		if (InProperty->GetOwnerStruct())
		{
			FString StructName = InProperty->GetOwnerStruct()->GetName();

			if (StructName == FString("SlCameraSettings"))
			{
				return !(InitParameters.InputType == ESlInputType::IT_SVO);
			}

			if (StructName == FString("SlRuntimeParameters"))
			{
				if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRuntimeParameters, ReferenceFrame))
				{
					return false;
				}

				return true;
			}
		}

		if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, Resolution) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(FSlRecordingParameters, VideoFilename) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(FSlRecordingParameters, CompressionMode)
			)
		{
			return !(InitParameters.InputType == ESlInputType::IT_SVO);
		}

		if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, SvoPath) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, bRealTime) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, bLoop))
		{
			return (InitParameters.InputType == ESlInputType::IT_SVO);
		}

		if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, StreamIP) ||
			PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, StreamPort))
		{
			return (InitParameters.InputType == ESlInputType::IT_STREAM);
		}

		if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, DepthMode))
		{
			return RuntimeParameters.bEnableDepth;
		}

		if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlPositionalTrackingParameters, bEnablePoseSmoothing))
		{
			return TrackingParameters.bEnableAreaMemory;
		}

		return Super::CanEditChange(InProperty);
	}

	// Runtime (camera session live)
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

bool AZEDCamera::ValidateForEditorSession(FString& OutError) const
{
	if (RuntimeParameters.ReferenceFrame != ESlReferenceFrame::RF_World)
	{
		OutError = TEXT("Reference frame must be World");
		return false;
	}

	// Init() binds the depth texture to the material, and CreateLeftTextures only creates it when depth is on
	if (!RuntimeParameters.bEnableDepth)
	{
		OutError = TEXT("Depth must be enabled in the runtime parameters");
		return false;
	}

	return true;
}

void AZEDCamera::BeginEditorSession()
{
	check(GSlCameraProxy);

	GSlCameraProxy->OnCameraClosed.AddDynamic(this, &AZEDCamera::CameraClosed);

	SetEditorPreviewPlaneDistance();

	LoadParametersAndSettings();
	PrepareForOpening();
}

void AZEDCamera::SetEditorPreviewPlaneDistance()
{
	// In game the plane sits on the near clipping plane so it covers the whole view. Viewed from
	// outside in the level editor that is a centimeter wide speck, so the preview is pushed further out
	CameraRenderPlaneDistance = FMath::Max<float>(GNearClippingPlane + 0.001f, EditorPreviewPlaneDistance);

	if (bInit)
	{
		LeftRoot->SetRelativeLocation(FVector(CameraRenderPlaneDistance, 0, 0));
		SetPlaneSize(LeftPlane, CameraRenderPlaneDistance);
	}
}

void AZEDCamera::EndEditorSession()
{
	if (GSlCameraProxy)
	{
		DisableObjectDetection();
		GSlCameraProxy->OnCameraClosed.RemoveDynamic(this, &AZEDCamera::CameraClosed);
		GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
	}

	DisableRenderingCpp();
	ClearOutputs();

	// Leave the placed actor as the constructor built it, nothing of the session may end up saved in the level
	LeftCamera->TextureTarget = nullptr;
	LeftEyeRenderTarget = nullptr;
	LeftPlane->SetMaterial(0, nullptr);
	ZedLeftEyeMaterialInstanceDynamic = nullptr;

	// Undo the render plane layout SetupComponents computed from the camera calibration
	LeftRoot->SetRelativeLocation(FVector::ZeroVector);
	LeftPlane->SetWorldScale3D(FVector::OneVector);
	CameraRenderPlaneDistance = 0.f;

	bInit = false;
}
#endif

void AZEDCamera::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!GSlCameraProxy || !bInit || !Batch)
	{
		return;
	}

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

	// Enqueued after the batch, so they run on the render thread once the textures hold this frame
	UpdateColorOutput();
	UpdateDepthOutput();

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

		OnTrackingDataUpdated.Broadcast(TrackingData, DeltaSeconds);
	}

	// Depth retrieve toggle
	if (bCurrentDepthEnabled != RuntimeParameters.bEnableDepth)
	{
		bCurrentDepthEnabled = RuntimeParameters.bEnableDepth;

		if (!bCurrentDepthEnabled)
		{
			ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", nullptr);

			Batch->RemoveTexture(LeftEyeDepth);
			LeftEyeDepth->ConditionalBeginDestroy();
			LeftEyeDepth = nullptr;

			DepthResolutionInPixels = FIntPoint::ZeroValue;
		}
		else
		{
			CreateLeftTextures(false);

			Batch->AddTexture(LeftEyeDepth);

			ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
		}
	}
	// Depth texture resolution, normals will have the same size for performance purpose
	else if (bCurrentDepthEnabled)
	{
		const FIntPoint DepthSize = GetDepthTextureSize();
		if (DepthSize.X != LeftEyeDepth->Width || DepthSize.Y != LeftEyeDepth->Height)
		{
			Batch->RemoveTexture(LeftEyeDepth);
			LeftEyeDepth->Resize(DepthSize.X, DepthSize.Y);
			Batch->AddTexture(LeftEyeDepth);

			ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);

			DepthResolutionInPixels = DepthSize;
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

		// Logged on change, this runs at grab rate. The states that do not reach the pose update
		// below leave the actor standing still, so they cannot stay silent
		if ((int32)TrackingState != LastLoggedTrackingState)
		{
			LastLoggedTrackingState = (int32)TrackingState;

			switch (TrackingState)
			{
				case SL_POSITIONAL_TRACKING_STATE_OK:
					ZED_CAMERA_LOG("Positional tracking OK");
					break;
				case SL_POSITIONAL_TRACKING_STATE_FPS_TOO_LOW:
					ZED_CAMERA_LOG_W("FPS too low for good tracking");
					break;
				case SL_POSITIONAL_TRACKING_STATE_SEARCHING_FLOOR_PLANE:
					ZED_CAMERA_LOG_W("Searching the floor plane, the pose holds until it is found");
					break;
				case SL_POSITIONAL_TRACKING_STATE_UNAVAILABLE:
					ZED_CAMERA_LOG_W("Tracking could not follow the previous frame, the pose holds");
					break;
				case SL_POSITIONAL_TRACKING_STATE_OFF:
					ZED_CAMERA_LOG_W("Positional tracking is off");
					break;
				default:
					ZED_CAMERA_LOG_W("Positional tracking state %d", (int32)TrackingState);
					break;
			}
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

		LeftEyeColor = USlViewTexture::CreateGPUViewTexture("LeftEyeColor", Resolution.X, Resolution.Y, ImageView, true, ESlTextureFormat::TF_R8G8B8A8_UNORM);
	}

	if (RuntimeParameters.bEnableDepth)
	{
		const FIntPoint TextureSize = GetDepthTextureSize();

		LeftEyeDepth = USlMeasureTexture::CreateGPUMeasureTexture("LeftEyeDepth", TextureSize.X, TextureSize.Y, ESlMeasure::M_Depth, true, ESlTextureFormat::TF_R32_FLOAT);

		DepthResolutionInPixels = TextureSize;
	}
}

FIntPoint AZEDCamera::GetDepthTextureSize() const
{
	static_assert((int32)ESlDepthResolution::DR_Full == 0 && (int32)ESlDepthResolution::DR_Eighth == 3,
		"ESlDepthResolution is used as a power of two divisor, so its order carries the meaning");

	const FIntPoint ImageSize = GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution;
	const int32 Shift = (int32)DepthResolution;

	// A power of two divisor keeps the image aspect ratio and never rounds to zero on a valid image
	return FIntPoint(FMath::Max(ImageSize.X >> Shift, 1), FMath::Max(ImageSize.Y >> Shift, 1));
}

namespace
{
	/** Resize and reformat an output target so a straight copy from a ZED texture is possible */
	bool ConformRenderTarget(UTextureRenderTarget2D* Target, int32 Width, int32 Height, EPixelFormat Format, bool bLinearGamma)
	{
		if (Target->SizeX == Width && Target->SizeY == Height && Target->GetFormat() == Format && Target->bForceLinearGamma == bLinearGamma)
		{
			return false;
		}

		// OverrideFormat takes precedence over RenderTargetFormat and InitAutoFormat leaves it alone.
		// With it set, IsSRGB is just !bForceLinearGamma
		Target->OverrideFormat = Format;
		Target->bForceLinearGamma = bLinearGamma;
		Target->ClearColor = FLinearColor::Black;

		// Recreates the resource itself
		Target->InitAutoFormat(Width, Height);

		return true;
	}

	void CopyTextureToRenderTarget(UTexture2D* Source, UTextureRenderTarget2D* Target)
	{
		FTextureResource* SourceResource = Source->GetResource();

		// GetRenderTargetResource asserts on the rendering thread
		FTextureRenderTargetResource* TargetResource = Target->GameThread_GetRenderTargetResource();

		if (!SourceResource || !TargetResource)
		{
			return;
		}

		ENQUEUE_RENDER_COMMAND(ZEDCopyToRenderTarget)(
			[SourceResource, TargetResource](FRHICommandListImmediate& RHICmdList)
			{
				FRHITexture* SourceRHI = SourceResource->TextureRHI;
				FRHITexture* TargetRHI = TargetResource->GetRenderTargetTexture();

				if (!SourceRHI || !TargetRHI ||
					SourceRHI->GetDesc().Extent != TargetRHI->GetDesc().Extent ||
					SourceRHI->GetDesc().Format != TargetRHI->GetDesc().Format)
				{
					return;
				}

				RHICmdList.Transition(FRHITransitionInfo(SourceRHI, ERHIAccess::Unknown, ERHIAccess::CopySrc));
				RHICmdList.Transition(FRHITransitionInfo(TargetRHI, ERHIAccess::Unknown, ERHIAccess::CopyDest));

				RHICmdList.CopyTexture(SourceRHI, TargetRHI, FRHICopyTextureInfo());

				RHICmdList.Transition(FRHITransitionInfo(TargetRHI, ERHIAccess::CopyDest, ERHIAccess::SRVMask));
			});
	}
}

void AZEDCamera::ClearOutputs()
{
	// Depth 0 is what the composite depth mesh treats as no sample, so its mask drops those vertices
	if (ColorOutput)
	{
		UKismetRenderingLibrary::ClearRenderTarget2D(this, ColorOutput, FLinearColor::Black);
	}

	if (DepthOutput)
	{
		UKismetRenderingLibrary::ClearRenderTarget2D(this, DepthOutput, FLinearColor::Black);
	}
}

void AZEDCamera::UpdateColorOutput()
{
	if (!ColorOutput)
	{
		return;
	}

	if (!LeftEyeColor || !LeftEyeColor->Texture)
	{
		return;
	}

	// Matches the source texture so the copy is a straight blit, sRGB so it samples like any color texture
	if (ConformRenderTarget(ColorOutput, LeftEyeColor->Width, LeftEyeColor->Height, PF_R8G8B8A8, false))
	{
		ZED_CAMERA_LOG_W("Color output %s set to %dx%d RGBA8 sRGB",
			*ColorOutput->GetName(), LeftEyeColor->Width, LeftEyeColor->Height);
	}

	CopyTextureToRenderTarget(LeftEyeColor->Texture, ColorOutput);
}

void AZEDCamera::UpdateDepthOutput()
{
	if (!DepthOutput || !LeftEyeDepth || !LeftEyeDepth->Texture)
	{
		return;
	}

	if (ConformRenderTarget(DepthOutput, LeftEyeDepth->Width, LeftEyeDepth->Height, PF_R32_FLOAT, true))
	{
		ZED_CAMERA_LOG_W("Depth output %s set to %dx%d R32F to match the depth texture",
			*DepthOutput->GetName(), LeftEyeDepth->Width, LeftEyeDepth->Height);
	}

	CopyTextureToRenderTarget(LeftEyeDepth->Texture, DepthOutput);
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

void AZEDCamera::PrepareForOpening()
{
	bCurrentDepthEnabled = RuntimeParameters.bEnableDepth;

	checkf(RuntimeParameters.ReferenceFrame == ESlReferenceFrame::RF_World, TEXT("Reference frame must be World when using the ZEDCamera"));
}

void AZEDCamera::LoadParametersAndSettings()
{
	if (bLoadParametersFromConfigFile)
	{
		LoadParameters();
	}
	if (bLoadCameraSettingsFromConfigFile)
	{
		LoadCameraSettings();
	}
}

void AZEDCamera::LoadParameters()
{
	LoadParameterGroup(EZEDParameterGroup::PG_Init);
	LoadParameterGroup(EZEDParameterGroup::PG_Tracking);
	LoadParameterGroup(EZEDParameterGroup::PG_Runtime);
	LoadParameterGroup(EZEDParameterGroup::PG_Recording);
}

void AZEDCamera::LoadCameraSettings()
{
	LoadParameterGroup(EZEDParameterGroup::PG_CameraSettings);
}

void AZEDCamera::SaveParameters()
{
	SaveParameterGroup(EZEDParameterGroup::PG_Init);
	SaveParameterGroup(EZEDParameterGroup::PG_Tracking);
	SaveParameterGroup(EZEDParameterGroup::PG_Runtime);
	SaveParameterGroup(EZEDParameterGroup::PG_Recording);
}

void AZEDCamera::SaveCameraSettings()
{
	SaveParameterGroup(EZEDParameterGroup::PG_CameraSettings);
}

void AZEDCamera::LoadParameterGroup(EZEDParameterGroup Group)
{
	if (!IsGConfigAvailable())
	{
		return;
	}

	const FString Path = GetParameterGroupConfigPath(Group);

	// Write out every group sharing that file, so the next load finds all of them
	if (!GConfig->Find(Path))
	{
		if (Group == EZEDParameterGroup::PG_CameraSettings)
		{
			SaveParameterGroup(EZEDParameterGroup::PG_CameraSettings);
		}
		else
		{
			SaveParameterGroup(EZEDParameterGroup::PG_Init);
			SaveParameterGroup(EZEDParameterGroup::PG_Tracking);
			SaveParameterGroup(EZEDParameterGroup::PG_Runtime);
			SaveParameterGroup(EZEDParameterGroup::PG_Recording);
		}

		return;
	}

	switch (Group)
	{
		case EZEDParameterGroup::PG_Init:
			InitParameters.Load(Path);
			if (InitParameters.VerboseFilePath.IsEmpty())
			{
				InitParameters.VerboseFilePath = DEFAULT_VERBOSE_FILE_PATH;
			}
			break;
		case EZEDParameterGroup::PG_Tracking:
			TrackingParameters.Load(Path);
			break;
		case EZEDParameterGroup::PG_Runtime:
			RuntimeParameters.Load(Path);
			break;
		case EZEDParameterGroup::PG_Recording:
			RecordingParameters.Load(Path);
			break;
		case EZEDParameterGroup::PG_CameraSettings:
			CameraSettings.Load(Path);
			break;
	}
}

void AZEDCamera::SaveParameterGroup(EZEDParameterGroup Group)
{
	if (!IsGConfigAvailable())
	{
		return;
	}

	const FString Path = GetParameterGroupConfigPath(Group);

	switch (Group)
	{
		case EZEDParameterGroup::PG_Init:
#if WITH_EDITOR
			// An empty path means "use the default", don't bake the machine specific one into the config
			if (InitParameters.VerboseFilePath == DEFAULT_VERBOSE_FILE_PATH)
			{
				InitParameters.VerboseFilePath.Empty();
			}
#endif
			InitParameters.Save(Path);
			break;
		case EZEDParameterGroup::PG_Tracking:
			TrackingParameters.Save(Path);
			break;
		case EZEDParameterGroup::PG_Runtime:
			RuntimeParameters.Save(Path);
			break;
		case EZEDParameterGroup::PG_Recording:
			RecordingParameters.Save(Path);
			break;
		case EZEDParameterGroup::PG_CameraSettings:
			CameraSettings.Save(Path);
			break;
	}

	GConfig->Flush(false, *Path);
}

void AZEDCamera::ResetParameterGroup(EZEDParameterGroup Group)
{
	switch (Group)
	{
		case EZEDParameterGroup::PG_Init:
			InitParameters = FSlInitParameters();
			if (InitParameters.VerboseFilePath.IsEmpty())
			{
				InitParameters.VerboseFilePath = DEFAULT_VERBOSE_FILE_PATH;
			}
			DepthClampThreshold = InitParameters.DepthMaximumDistance;
			break;
		case EZEDParameterGroup::PG_Tracking:
			TrackingParameters = FSlPositionalTrackingParameters();
			break;
		case EZEDParameterGroup::PG_Runtime:
			RuntimeParameters = FSlRuntimeParameters();
			break;
		case EZEDParameterGroup::PG_Recording:
			RecordingParameters = FSlRecordingParameters();
			break;
		case EZEDParameterGroup::PG_CameraSettings:
			CameraSettings = FSlVideoSettings();
			break;
	}
}

void AZEDCamera::ResetParameters()
{
	ResetParameterGroup(EZEDParameterGroup::PG_Init);
	ResetParameterGroup(EZEDParameterGroup::PG_Tracking);
	ResetParameterGroup(EZEDParameterGroup::PG_Runtime);

	ObjectDetectionParameters = FSlObjectDetectionParameters();
	ObjectDetectionRuntimeParameters = FSlObjectDetectionRuntimeParameters();

	BodyTrackingParameters = FSlBodyTrackingParameters();
	BodyTrackingRuntimeParameters = FSlBodyTrackingRuntimeParameters();

	bDepthOcclusion = true;

	ImageView = ESlView::V_Left;

	bShowZedImage = true;
}

void AZEDCamera::ResetSettings()
{
	ResetParameterGroup(EZEDParameterGroup::PG_CameraSettings);
}

void AZEDCamera::Init()
{
	if (bInit)
	{
		return;
	}

	// So a new session logs its first tracking state even when it matches the previous one
	LastLoggedTrackingState = -1;

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
	if (LeftEyeDepth)
	{
		ZedLeftEyeMaterialInstanceDynamic->SetTextureParameterValue("Depth", LeftEyeDepth->Texture);
	}

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
		LeftEyeColor = nullptr;
	}
	if (LeftEyeDepth) {
		LeftEyeDepth->ConditionalBeginDestroy();
		LeftEyeDepth = nullptr;
	}

	DepthResolutionInPixels = FIntPoint::ZeroValue;

	ClearOutputs();

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

	// The scene capture renders the whole scene every frame into LeftEyeRenderTarget, which only
	// gameplay ever reads. An editor session shows the plane without paying for it
	const UWorld* World = GetWorld();
	LeftCamera->SetActive(enable && World && World->IsGameWorld());
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

	ViewCamera->SetFieldOfView(cameraParam.HFOV);
	ViewCamera->SetAspectRatio((float)cameraParam.Resolution.X / (float)cameraParam.Resolution.Y);
	ViewCamera->bConstrainAspectRatio = true;
	
	LeftRoot->SetRelativeLocation(FVector(CameraRenderPlaneDistance, 0, 0));
	// Set plane size
	SetPlaneSize(LeftPlane, CameraRenderPlaneDistance);

	// Set inter planes materials
	LeftPlane->SetMaterial(0, ZedLeftEyeMaterialInstanceDynamic);

	// Set camera projection matrix
	LeftCamera->bUseCustomProjectionMatrix = true;
	USlFunctionLibrary::GetSceneCaptureProjectionMatrix(LeftCamera->CustomProjectionMatrix, ESlEye::E_Left);
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
