//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDPawn.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDPlayerController.h"
#include "UMG.h"
#include "Math/UnrealMathUtility.h"

#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"

AZEDPawn::AZEDPawn() :
	EnableLerp(true),
	LerpIntensity(10.0),
	IsFrozen(false),
	ToggleFreeze(false),
	UseRotationOffset(true),
	StartOffsetLocation(FVector::ZeroVector),
	PreviousLocation(FVector::ZeroVector),
	PreviousToCurrentLocation(FVector::ZeroVector),
	TranslationMultiplier(FVector::OneVector),
	PrevVirtualLocation(FVector::ZeroVector),
	VirtualLocation(FVector::ZeroVector),
	SetFloorAsOriginCorrected(false)
{
	TransformOffset = FTransform();
	ToggleFreeze = false;
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SpringArm = CreateDefaultSubobject<USceneComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCineCameraComponent>(TEXT("MainCamera"));
	Camera->SetupAttachment(SpringArm);
	Camera->SetFieldOfView(80);

	VirtualCamera = CreateDefaultSubobject<UVCamComponent>(TEXT("VirtualCamera"));
	VirtualCamera->SetupAttachment(Camera);

	Camera->bConstrainAspectRatio = true;
	Camera->PostProcessSettings.VignetteIntensity = 0.0f;
	Camera->PostProcessSettings.bOverride_VignetteIntensity = true;

	// Widget material
	static ConstructorHelpers::FObjectFinder<UMaterial> ZedWidgetMaterial(TEXT("Material'/Stereolabs/ZED/Materials/M_ZED_3DWidgetPassthroughNoDepth.M_ZED_3DWidgetPassthroughNoDepth'"));
	ZedWidgetSourceMaterial = ZedWidgetMaterial.Object;

	// Zed loading source widget
	static ConstructorHelpers::FObjectFinder<UClass> ZedLoadingWidgetBlueprint(TEXT("'/Stereolabs/ZED/Blueprints/HUD/Loading/W_ZED_Loading.W_ZED_Loading_C'"));
	ZedLoadingSourceWidget = ZedLoadingWidgetBlueprint.Object;

	// Zed error source widget
	static ConstructorHelpers::FObjectFinder<UClass> ZedErrorWidgetBlueprint(TEXT("'/Stereolabs/ZED/Blueprints/HUD/Error/W_ZED_Error.W_ZED_Error_C'"));
	ZedErrorSourceWidget = ZedErrorWidgetBlueprint.Object;

	// Zed loading widget
	ZedLoadingWidget = CreateDefaultSubobject<UZEDWidget>(TEXT("LoadingMessage"));
	ZedLoadingWidget->SetupAttachment(Camera);
	ZedLoadingWidget->SetWorldScale3D(FVector(0.5f));
	ZedLoadingWidget->SetRelativeLocation(FVector(300.0f, 0.0f, 0.0f));
	ZedLoadingWidget->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	ZedLoadingWidget->WidgetComponent->SetMaterial(0, ZedWidgetSourceMaterial);
	ZedLoadingWidget->WidgetComponent->SetWidgetSpace(EWidgetSpace::World);
	ZedLoadingWidget->WidgetComponent->SetWidgetClass(ZedLoadingSourceWidget);
	ZedLoadingWidget->WidgetComponent->SetDrawSize(FVector2D(1920, 1080));
	ZedLoadingWidget->WidgetComponent->SetGeometryMode(EWidgetGeometryMode::Cylinder);
	ZedLoadingWidget->WidgetComponent->SetCylinderArcAngle(80.0f);
	ZedLoadingWidget->WidgetComponent->SetBlendMode(EWidgetBlendMode::Transparent);
	ZedLoadingWidget->SetVisibility(false);

	// Zed error widget
	ZedErrorWidget = CreateDefaultSubobject<UZEDWidget>(TEXT("ErrorMessage"));
	ZedErrorWidget->SetupAttachment(Camera);
	ZedErrorWidget->SetWorldScale3D(FVector(0.5f));
	ZedErrorWidget->SetRelativeLocation(FVector(300.0f, 0.0f, 0.0f));
	ZedErrorWidget->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	ZedErrorWidget->WidgetComponent->SetMaterial(0, ZedWidgetSourceMaterial);
	ZedErrorWidget->WidgetComponent->SetWidgetSpace(EWidgetSpace::World);
	ZedErrorWidget->WidgetComponent->SetWidgetClass(ZedErrorSourceWidget);
	ZedErrorWidget->WidgetComponent->SetDrawSize(FVector2D(1920, 1080));
	ZedErrorWidget->WidgetComponent->SetGeometryMode(EWidgetGeometryMode::Cylinder);
	ZedErrorWidget->WidgetComponent->SetCylinderArcAngle(80.0f);
	ZedErrorWidget->WidgetComponent->SetBlendMode(EWidgetBlendMode::Transparent);
	ZedErrorWidget->SetVisibility(false);

	AutoPossessPlayer = EAutoReceiveInput::Disabled;
	
	static ConstructorHelpers::FObjectFinder<UMaterial> RemapMaterial(TEXT("Material'/Stereolabs/Stereolabs/Materials/M_SL_RPP.M_SL_RPP'"));
	RemapSourceMaterial = RemapMaterial.Object;
}

void AZEDPawn::ZedCameraTrackingUpdated(const FZEDTrackingData& NewTrackingData)
{
	PreviousLocation = RealCameraTransform.GetLocation();
	RealCameraTransform = NewTrackingData.OffsetZedWorldTransform;
	PreviousToCurrentLocation = RealCameraTransform.GetLocation() - PreviousLocation;

	PrevVirtualLocation = VirtualLocation;
	VirtualLocation = PrevVirtualLocation + RealTranslationToVirtualTranslation(PreviousToCurrentLocation);

	if (ToggleFreeze) {
		if (IsFrozen) {
			// set new offset
			VirtualLocation = GetActorTransform().GetLocation();

			if (UseRotationOffset) {
				// Get the rotational difference between where the actor is facing and the "real" camera orientation.
				// [Actor - Real] is [Actor * Real.Inv] in quaternion 
				TransformOffset.SetRotation(GetActorTransform().GetRotation() * RealCameraTransform.GetRotation().Inverse());
			}
			else {
				TransformOffset.SetRotation(FQuat::Identity);
			}
		}
		IsFrozen = !IsFrozen;
		ToggleFreeze = false;
	}
}

void AZEDPawn::SetStartOffsetLocation(const FVector& locOffset) 
{
	StartOffsetLocation = locOffset;
	PrevVirtualLocation = locOffset;
	VirtualLocation = locOffset;
}

void AZEDPawn::Tick(float DeltaSeconds) 
{
	if (!IsFrozen) {
		if (EnableLerp)
		{
			// Apply rotational offset on transform as global rotation

			float lerpAlpha = DeltaSeconds * LerpIntensity;
			LerpTransform = UKismetMathLibrary::TLerp(
				LerpTransform, 
				FTransform(
					TransformOffset.GetRotation() * RealCameraTransform.GetRotation(),
					VirtualLocation,
					RealCameraTransform.GetScale3D()
				),
				FMath::Clamp(lerpAlpha, 0.0f, 1.0f));
			SetActorTransform(LerpTransform);
		}
		else
		{
			SetActorTransform(
				FTransform(
					TransformOffset.GetRotation() * RealCameraTransform.GetRotation(),
					VirtualLocation,
					RealCameraTransform.GetScale3D()
				)
			);

			LerpTransform = RealCameraTransform;
		}
	}
}

/** The realTranslation should be previousToCurrentLocation*/
FVector AZEDPawn::RealTranslationToVirtualTranslation(const FVector& realTranslation)
{
	FVector ret = FVector::ZeroVector;
	if (SetFloorAsOriginCorrected) {
		ret = TransformOffset.GetRotation() * (realTranslation * TranslationMultiplier);
	}
	else {
		ret = TransformOffset.GetRotation() * (realTranslation);
		SetFloorAsOriginCorrected = true;
	}
	return ret;
}

void AZEDPawn::InitRemap(FName HMDname, sl::RESOLUTION camRes, float dp)
{
	/*
	FSlCameraInformation camInfo = GSlCameraProxy->GetCameraInformation(FIntPoint(0, 0));
	FVector2D hmdFoc = USlFunctionLibrary::GetHmdFocale();
	int RemapRez = 2501;
	int RemapPrecision = 100;
	sl::Mat* Mx;
	sl::Mat* My;
	// Warning: b, Ipd and dp have to be in mm
	//TODO
	//sl::mr::computeSRemap(sl::unreal::ToSlType(HMDname), camRes, camInfo.HalfBaseline*20, camInfo.HalfBaseline*20, (hmdFoc.X + hmdFoc.Y)/2.0, camInfo.CalibrationParameters.LeftCameraParameters.HFocal, dp*10 + 100.0, -120.0, 100.0, sl::Resolution(RemapRez, RemapRez), RemapPrecision, Mx, My);
	RemapMx = USlFunctionLibrary::GenerateTextureFromSlMat(Mx);
	RemapMy = USlFunctionLibrary::GenerateTextureFromSlMat(My);

	RemapMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(RemapSourceMaterial, nullptr);
	RemapMaterialInstanceDynamic->SetTextureParameterValue(FName("Mx"), RemapMx);
	RemapMaterialInstanceDynamic->SetTextureParameterValue(FName("My"), RemapMy);
	RemapMaterialInstanceDynamic->SetScalarParameterValue(FName("Mwidth"), RemapMx->GetSizeX());
	RemapMaterialInstanceDynamic->SetScalarParameterValue(FName("Mheight"), RemapMx->GetSizeY());
	FMatrix ProjectionMatrixLeft = GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(EStereoscopicPass::eSSP_LEFT_EYE);
	RemapMaterialInstanceDynamic->SetScalarParameterValue(FName("OCxLeft"), ProjectionMatrixLeft.M[2][0] /2 + 0.5);
	RemapMaterialInstanceDynamic->SetScalarParameterValue(FName("OCyLeft"), -ProjectionMatrixLeft.M[2][1] /2 + 0.5);
	FMatrix ProjectionMatrixRight = GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(EStereoscopicPass::eSSP_RIGHT_EYE);
	RemapMaterialInstanceDynamic->SetScalarParameterValue(FName("OCxRight"), ProjectionMatrixRight.M[2][0] /2 + 0.5);
	RemapMaterialInstanceDynamic->SetScalarParameterValue(FName("OCyRight"), -ProjectionMatrixRight.M[2][1] /2 + 0.5);
	Camera->AddOrUpdateBlendable(RemapMaterialInstanceDynamic, 1.0f);
	*/
}