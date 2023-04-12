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
	SetFloorAsOriginCorrected(false),
	PreviousLocation(FVector::ZeroVector),
	PreviousToCurrentLocation(FVector::ZeroVector),
	TranslationMultiplier(FVector::OneVector),
	VirtualLocation(FVector::ZeroVector),
	PrevVirtualLocation(FVector::ZeroVector)
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
