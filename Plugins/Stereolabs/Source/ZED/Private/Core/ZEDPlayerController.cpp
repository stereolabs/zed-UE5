//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDPlayerController.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"
#include "ZED/Classes/ZEDGameInstance.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"
#include "UMG.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(ZEDPlayerController);

#define SHOW_ZED_MESSAGE(Canvas, Font, TextItem, Position, RowHeight)\
	if (Font && Font->ImportOptions.bUseDistanceFieldAlpha)\
	{\
		TextItem.BlendMode = SE_BLEND_MaskedDistanceFieldShadowed;\
	}\
	else\
	{\
		TextItem.EnableShadow(FColor::Black);\
	}\
	Canvas->Canvas->DrawItem(String);\
	Position.Y += RowHeight;\

/** Activate/Deactivate noise */
//static TAutoConsoleVariable<int32> CVarZEDNoise(
//	TEXT("r.ZED.Noise"),
//	0,
//	TEXT("1 to enable noise, 0 to disable"),
//	ECVF_RenderThreadSafe
//);

/** Show ZED FPS */
static TAutoConsoleVariable<int32> CVarZEDShowFPS(
	TEXT("r.ZED.ShowFPS"),
	0,
	TEXT("1 to show, 0 to hide"),
	ECVF_RenderThreadSafe
);

AZEDPlayerController::AZEDPlayerController()
	:
	PawnClass(AZEDPawn::StaticClass()),
	CameraClass(AZEDCamera::StaticClass()),
	ZedPawn(nullptr),
	ZedCamera(nullptr),
	bUseDefaultBeginPlay(true),
	bOpenZedCameraAtInit(true),
	bIsFirstPlayer(false),
	bPawnWasPlaced(false),
	bCameraWasPlaced(false),
	CurrentFPSTimerBadFPS(0.0f),
	CurrentFPSTimerGoodFPS(0.0f),
	CurrentCameraFPSTimerBadFPS(0.0f),
	CurrentCameraFPSTimerGoodFPS(0.0f),
	CurrentNoiseValue(0),
	bTickZedCamera(false),
	bInit(false),
	bShowLowCameraFPS(false),
	bShowLowAppFPS(false),
	bZedCameraDisconnected(false)
{

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bTickEvenWhenPaused = false;
	PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;

	static ConstructorHelpers::FObjectFinder<UMaterial> PostProcessFadeMaterial(TEXT("Material'/Stereolabs/ZED/Materials/M_ZED_Fade.M_ZED_Fade'"));
	PostProcessFadeSourceMaterial = PostProcessFadeMaterial.Object;

	static ConstructorHelpers::FObjectFinder<UMaterial> PostProcessZedMaterial(TEXT("Material'/Stereolabs/ZED/Materials/M_ZED_PostProcess.M_ZED_PostProcess'"));
	PostProcessZedSourceMaterial = PostProcessZedMaterial.Object;
	
	static ConstructorHelpers::FObjectFinder<UCurveFloat> FadeCurve(TEXT("CurveFloat'/Stereolabs/ZED/Utility/C_Fade.C_Fade'"));
	FadeTimelineCurve = FadeCurve.Object;

	FadeTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("FadeTimeline"));
	FadeTimeline->SetTimelineLength(0.75f);

	FadeFunction.BindUFunction(this, "Fading");
	FadeTimeline->AddInterpFloat(FadeTimelineCurve, FadeFunction);
}

void AZEDPlayerController::PostRenderFor(APlayerController* PC, UCanvas* Canvas, FVector CameraPosition, FVector CameraDir)
{
	Super::PostRenderFor(PC, Canvas, CameraPosition, CameraDir);

	UFont* Font = GEngine->GetLargeFont();

	FLinearColor Color;
	FVector2D Position;

	const int32 RowHeight = FMath::TruncToInt(Font->GetMaxCharHeight() * 1.1f);
	
	const FVector2D Scale(1.1f, 1.1f);

	if (CVarZEDShowFPS.GetValueOnAnyThread() && GSlCameraProxy->IsCameraOpened())
	{
		Color = ZEDFPS >= 58.0f ? FColor::Green : ZEDFPS >= 45.0f ? FColor::Yellow : FColor::Red;

		{
			FCanvasTextItem String(Position, FText::FromString(FString::Printf(TEXT("%5.2f FPS"), ZEDFPS)), Font, Color);
			String.Scale = Scale;

			Position = FVector2D(40.0f, FMath::TruncToInt(GetLocalPlayer()->ViewportClient->Viewport->GetSizeXY().Y * 0.20f));
			String.Position = Position;

			SHOW_ZED_MESSAGE(Canvas, Font, String, Position, RowHeight);
		}

		{
			FCanvasTextItem String(Position, FText::FromString(FString::Printf(TEXT("%5.2f ms"), 1.0f / ZEDFPS * 100.0f)), Font, Color);
			String.Scale = Scale;

			SHOW_ZED_MESSAGE(Canvas, Font, String, Position, RowHeight);
		}
	}
}

void AZEDPlayerController::Tick(float DeltaSeconds)
{
	//ZedPawn->SetActorScale3D(FVector(1, 1, 1));

	if (bTickZedCamera && IsValid(ZedCamera))
	{
		ZedCamera->Tick(DeltaSeconds);
	}

	Super::Tick(DeltaSeconds);
}

void AZEDPlayerController::BeginPlay()
{
	bIsFirstPlayer = (GetWorld()->GetFirstPlayerController() == this);

	bool bIsStandalone = UKismetSystemLibrary::IsStandalone(this);
	bool bIsLocal = IsLocalPlayerController();

#if WITH_EDITOR
	// Listen server or client
	if (bIsFirstPlayer && bIsLocal)
	{
		// Check game instance type
		UZEDGameInstance* ZedGameInstance = Cast<UZEDGameInstance>(GetGameInstance());

		checkf(ZedGameInstance, TEXT("Game instance must inherit from UZEDGameInstance"));
	}
#endif

	// User begin play
	Super::BeginPlay();

	if (bUseDefaultBeginPlay)
	{
		MakeDefaultInit();
	}
}

void AZEDPlayerController::MakeDefaultInit()
{
	bIsFirstPlayer = (GetWorld()->GetFirstPlayerController() == this);

	bool bIsStandalone = UKismetSystemLibrary::IsStandalone(this);
	bool bIsLocal = IsLocalPlayerController();

	// Standalone
	if (bIsStandalone)
	{
		SpawnPawn(PawnClass);

		// First player
		if (bIsFirstPlayer)
		{
			SpawnZedCameraActor();

			Init();
		}
	}
	// Client or server
	else
	{
		// Server
		if (HasAuthority())
		{
			SpawnPawn(PawnClass);

			// Listen server controller and first player
			if (bIsLocal && bIsFirstPlayer)
			{
				SpawnZedCameraActor();

				Init();
			}
		}
		// Client
		else
		{
			// First player
			if (bIsFirstPlayer)
			{
				// Dedicated server spawn pawn before begin play
				if (ZedPawn)
				{
					OnPawnSpawned.Broadcast();
				}

				SpawnZedCameraActor();

				// Dedicated server spawn pawn before begin play
				if (ZedPawn)
				{
					Init();
				}
			}
		}
	}
}

void AZEDPlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (!bIsFirstPlayer || !IsLocalPlayerController())
	{
		return;
	}

	if (GSlCameraProxy)
	{
		if (GSlCameraProxy->IsCameraOpened())
		{
			GSlCameraProxy->CloseCamera();
		}

		GSlCameraProxy->OnCameraDisconnected.RemoveDynamic(this, &AZEDPlayerController::ZedCameraDisconnected);
		GSlCameraProxy->OnCameraClosed.RemoveDynamic(this, &AZEDPlayerController::ZedCameraClosed);
		GSlCameraProxy->OnTrackingEnabled.RemoveDynamic(this, &AZEDPlayerController::ZedCameraTrackingEnabled);
		GSlCameraProxy->OnSVOLooping.RemoveDynamic(this, &AZEDPlayerController::ZedSVOIsSetBackInTime);
		GSlCameraProxy->OnSVOSetBackInTime.RemoveDynamic(this, &AZEDPlayerController::ZedSVOIsSetBackInTime);

	}

	if (ZedCamera)
	{
		ZedCamera->OnCameraActorInitialized.RemoveDynamic(this, &AZEDPlayerController::ZedCameraActorInitialized);

		if (ZedPawn)
		{
			ZedCamera->OnTrackingDataUpdated.RemoveDynamic(ZedPawn, &AZEDPawn::ZedCameraTrackingUpdated);
		}
	}
}

UObject* AZEDPlayerController::SpawnPawn(UClass* NewPawnClass, bool bPossess)
{
	TArray<AActor*> ActorsToFind;
	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), NewPawnClass, ActorsToFind);
	}

	if (ActorsToFind.Num() > 0)
	{
		ZedPawn = Cast<AZEDPawn>(ActorsToFind[0]);
		bPawnWasPlaced = true;
		//World->SetNewWorldOrigin(FIntVector(ZedPawn->GetActorTransform().GetLocation().X, ZedPawn->GetActorTransform().GetLocation().Y, 0.0f) + World->OriginLocation);
		//ZedPawn->SetStartOffsetLocation(ZedPawn->GetActorTransform().GetLocation());
	}
	else 
	{
		// Spawn pawn
		ZedPawn = Cast<AZEDPawn>(GetWorld()->SpawnActor(NewPawnClass));
	}

	checkf(ZedPawn, TEXT("NewPawnClass must inherit from AZedPawn"));

	if (bPossess)
	{
		Possess(ZedPawn);
	}

	OnPawnSpawned.Broadcast();

	return ZedPawn;
}

void AZEDPlayerController::SpawnZedCameraActor()
{
	UClass* NewCameraClass = CameraClass ? *CameraClass : AZEDCamera::StaticClass();

	// Adopt a level-placed camera if there is one, mirror of SpawnPawn
	TArray<AActor*> ActorsToFind;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), NewCameraClass, ActorsToFind);

	if (ActorsToFind.Num() > 0)
	{
		ZedCamera = Cast<AZEDCamera>(ActorsToFind[0]);
		bCameraWasPlaced = true;

		// Captured before the attach to the pawn overwrites it
		PlacedCameraTransform = ZedCamera->GetActorTransform();

		if (ActorsToFind.Num() > 1)
		{
			SL_LOG_W(ZEDPlayerController, "Several ZED camera actors are placed in the level, only %s is used", *ZedCamera->GetName());
		}
	}
	else
	{
		ZedCamera = GetWorld()->SpawnActor<AZEDCamera>(NewCameraClass);

		// A camera of another class placed in the level would silently be ignored, warn instead
		TArray<AActor*> OtherCameras;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AZEDCamera::StaticClass(), OtherCameras);
		if (OtherCameras.Num() > 1)
		{
			SL_LOG_W(ZEDPlayerController, "A ZED camera actor is placed in the level but does not derive from the controller's CameraClass, it is ignored");
		}
	}
}

void AZEDPlayerController::Init()
{
	if (bInit)
	{
		return;
	}

	// A placed camera defines the start pose; a placed pawn wins over it (its transform is already the start pose)
	if (bCameraWasPlaced && !bPawnWasPlaced)
	{
		ZedPawn->SetActorLocationAndRotation(PlacedCameraTransform.GetLocation(), PlacedCameraTransform.GetRotation());
	}
	else if (bCameraWasPlaced && bPawnWasPlaced)
	{
		SL_LOG_W(ZEDPlayerController, "Both a ZED pawn and a ZED camera actor are placed in the level: the pawn transform defines the start pose");
	}

	TrackingOriginPose = FTransform(ZedPawn->GetActorRotation(), ZedPawn->GetActorLocation());

	// Attach Zed camera actor to pawn. The render planes require the camera at relative identity to the pawn root.
	ZedCamera->AttachToComponent(ZedPawn->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	// Create dynamic post process
	PostProcessFadeMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(PostProcessFadeSourceMaterial, nullptr);
	PostProcessZedMaterialInstanceDynamic = UMaterialInstanceDynamic::Create(PostProcessZedSourceMaterial, nullptr);

	// Bind events to proxy
	GSlCameraProxy->OnAIModelOptimized.AddDynamic(this, &AZEDPlayerController::ZedReady);
	GSlCameraProxy->OnCameraOpened.AddDynamic(this, &AZEDPlayerController::ZedCameraOpened);
	GSlCameraProxy->OnCameraDisconnected.AddDynamic(this, &AZEDPlayerController::ZedCameraDisconnected);
	GSlCameraProxy->OnCameraClosed.AddDynamic(this, &AZEDPlayerController::ZedCameraClosed);
	GSlCameraProxy->OnTrackingEnabled.AddDynamic(this, &AZEDPlayerController::ZedCameraTrackingEnabled);
	GSlCameraProxy->OnSVOLooping.AddDynamic(this, &AZEDPlayerController::ZedSVOIsSetBackInTime);
	GSlCameraProxy->OnSVOSetBackInTime.AddDynamic(this, &AZEDPlayerController::ZedSVOIsSetBackInTime);

	// Bind event to Zed camera actor
	ZedCamera->OnCameraActorInitialized.AddDynamic(this, &AZEDPlayerController::ZedCameraActorInitialized);

	// Pawn tracking
	ZedCamera->OnTrackingDataUpdated.AddDynamic(ZedPawn, &AZEDPawn::ZedCameraTrackingUpdated);

	// Enable fade post process
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	// User init
	InitEvent();

	bInit = true;

	// Open camera next frame
	if (bOpenZedCameraAtInit)
	{
		GetWorldTimerManager().SetTimer(InitTimerHandle, this, &AZEDPlayerController::Internal_Init, 0.001f, false);
	}
}

void AZEDPlayerController::Internal_Init()
{
	OpenZedCamera();
}

void AZEDPlayerController::CloseZedCamera()
{
	GetWorldTimerManager().ClearTimer(DisableFadePostProcessTimerHandle);
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	FadeIn();

	GetWorldTimerManager().SetTimer(CloseZedCameraTimerHandle, this, &AZEDPlayerController::Internal_CloseZedCamera, 1.5f, false);
}

void AZEDPlayerController::Internal_CloseZedCamera()
{
	GSlCameraProxy->CloseCamera();

	ZedCamera->DisableRenderingCpp();

	FadeOut();
}

void AZEDPlayerController::OpenZedCamera()
{
	checkf(bInit, TEXT("Init() not called before opening the camera"));

	GetWorldTimerManager().ClearTimer(CameraOpeningTimerHandle);

	ZedPawn->ZedLoadingWidget->SetVisibility(false);
	ZedPawn->ZedErrorWidget->SetVisibility(false);

	Internal_OpenZedCamera();
}

void AZEDPlayerController::Internal_OpenZedCamera()
{

	ZedPawn->ZedLoadingWidget->WidgetComponent->SetGeometryMode(EWidgetGeometryMode::Plane);
	ZedPawn->ZedLoadingWidget->SetWorldScale3D(FVector(0.3f));

	ZedPawn->ZedErrorWidget->WidgetComponent->SetGeometryMode(EWidgetGeometryMode::Plane);
	ZedPawn->ZedErrorWidget->SetWorldScale3D(FVector(0.3f));

	// The camera actor owns all parameters, optionally overridden from the config files
	ZedCamera->LoadParametersAndSettings();

	// Apply the start pose after the config load so neither the placed transform nor the reconnect pose can be clobbered by ZED.ini
	if (bZedCameraDisconnected)
	{
		ZedCamera->TrackingParameters.Location = LastPoseLocation;
		ZedCamera->TrackingParameters.Rotation = LastPoseRotation;
	}
	else if ((bCameraWasPlaced || bPawnWasPlaced) && !ZedCamera->TrackingParameters.bOverrideTrackingOrigin)
	{
		ZedCamera->TrackingParameters.Location = TrackingOriginPose.GetLocation();
		ZedCamera->TrackingParameters.Rotation = TrackingOriginPose.GetRotation().Rotator();
	}

	// Do some work before Zed actor initialization
	OnPreZedCameraOpening.Broadcast();

	for (auto ChildrenIt = ZedCamera->ChildActors.CreateConstIterator(); ChildrenIt; ++ChildrenIt)
	{
		(*ChildrenIt)->AttachToActor(ZedPawn, FAttachmentTransformRules(EAttachmentRule::KeepRelative, true));
	}

	// Validate parameters
	ZedCamera->PrepareForOpening();

	if (ZedCamera->InitParameters.DepthMode == ESlDepthMode::DM_Neural && !GSlCameraProxy->CheckAIModelOptimization(ESlAIModels::AIM_NeuralDepth)) {

		GSlCameraProxy->OptimizeAIModel(ESlAIModels::AIM_NeuralDepth, ESlAIType::AIT_Depth);
		UpdateHUDOptimizingAIModel();
	}
	else if (ZedCamera->InitParameters.DepthMode == ESlDepthMode::DM_NeuralPlus && !GSlCameraProxy->CheckAIModelOptimization(ESlAIModels::AIM_NeuralPlusDepth))
	{
		GSlCameraProxy->OptimizeAIModel(ESlAIModels::AIM_NeuralPlusDepth, ESlAIType::AIT_Depth);
		UpdateHUDOptimizingAIModel();
	}
	else if (ZedCamera->InitParameters.DepthMode == ESlDepthMode::DM_NeuralLight && !GSlCameraProxy->CheckAIModelOptimization(ESlAIModels::AIM_NeuralLightDepth))
	{
		GSlCameraProxy->OptimizeAIModel(ESlAIModels::AIM_NeuralPlusDepth, ESlAIType::AIT_Depth);
		UpdateHUDOptimizingAIModel();
	}
	else
	{
		ZedReady();
	}
}

void AZEDPlayerController::ZedReady()
{
	// Open camera with parameters
	GSlCameraProxy->OpenCamera(ZedCamera->InitParameters);

	UpdateHUDOpeningZed();

	GetWorldTimerManager().SetTimer(CameraOpeningTimerHandle, this, &AZEDPlayerController::UpdateHUDCheckOpeningZed, 1.0f, true, 2.0f);
}

void AZEDPlayerController::ZedCameraOpened()
{
	GetWorldTimerManager().ClearTimer(CameraOpeningTimerHandle);

	bZedCameraDisconnected = false;

	// Set fade post process
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);
	// Set camera field of view
	if (ZedCamera->bShowZedImage)
		ZedPawn->Camera->SetFieldOfView(GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.HFOV);
	else 
		ZedPawn->Camera->SetFieldOfView(100.0f);

	// Init viewport helper
	UGameViewportClient* GameViewport = GetLocalPlayer()->ViewportClient;
	check(GameViewport);

	ViewportHelper.AddToViewportResizeEvent(GameViewport);
	ViewportHelper.Update(GameViewport->Viewport->GetSizeXY());

	UpdateHUDCheckOpeningZed();

	// Enable tracking
	if (ZedCamera->TrackingParameters.bEnableTracking)
	{
		UpdateHUDEnablingZedTracking();

		ZedCamera->EnableTracking();
	}
	else
	{
		UpdateHUDZedOpened();

		// Fade to hide zed camera actor init
		FadeIn();

		// Init zed camera actor
		GetWorldTimerManager().SetTimer(InitializeZedCameraActorTimerHandle, this, &AZEDPlayerController::Internal_InitializeZedCameraActor, 1.5f, false);
	}
}

void AZEDPlayerController::ZedCameraTrackingEnabled(bool bSuccess, ESlErrorCode ErrorCode, const FVector& Location, const FRotator& Rotation)
{
	UpdateHUDZedTrackingEnabled(bSuccess, ErrorCode);

	if (bSuccess)
	{
		if (!ZedCamera->bInit)
		{
			// Fade to hide zed camera actor init
			FadeIn();
		}

		// Init zed camera actor
		GetWorldTimerManager().SetTimer(InitializeZedCameraActorTimerHandle, this, &AZEDPlayerController::Internal_InitializeZedCameraActor, 1.5f, false);
	}
}

void AZEDPlayerController::Internal_InitializeZedCameraActor()
{
	if (!ZedCamera->bInit)
	{
		// Init zed camera actor
		ZedCamera->Init();
	}
}

void AZEDPlayerController::ZedCameraActorInitialized()
{
	// Enable messages display
	GetHUD()->AddPostRenderedActor(this);
	GetHUD()->bShowOverlays = true;

	// Set HMD camera offset
	ZedPawn->SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	ZedCamera->AddOrUpdatePostProcessCpp(PostProcessZedMaterialInstanceDynamic,  1.0f);
	//PreZedEdit
	/*ZedPawn->Camera->PostProcessSettings.bDeferredAA = false;
	ZedPawn->Camera->PostProcessSettings.bPostProcessing = false;
	ZedPawn->Camera->CameraRenderingSettings.bLighting = false;*/

	ZedPawn->ZedLoadingWidget->SetVisibility(false);
	ZedPawn->ZedErrorWidget->SetVisibility(false);

	GetWorldTimerManager().SetTimer(FadeOutTimerHandle, this, &AZEDPlayerController::FadeOutToGame, 1.0f, false);

	bTickZedCamera = true;
}

void AZEDPlayerController::ZedSVOIsSetBackInTime()
{
	if (ZedCamera->bInit)
	{
		ZedCamera->Batch->Reset();
	}
}

void AZEDPlayerController::Fading(float FadingFactor)
{
	PostProcessFadeMaterialInstanceDynamic->SetScalarParameterValue("FadingFactor", FadingFactor);
}

void AZEDPlayerController::FadeIn()
{
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	FadeTimeline->ReverseFromEnd();
}

void AZEDPlayerController::FadeOut()
{
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	FadeTimeline->PlayFromStart();
}

void AZEDPlayerController::DisableFadePostProcess()
{
	// If camera disconnected right before disabling fade post process
	if (!GSlCameraProxy->IsCameraConnected())
	{
		return;
	}
	
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 0.0f);
}

void AZEDPlayerController::Internal_ZedCameraDisconnected()
{
	//PreZedEdit
	/*ZedPawn->Camera->PostProcessSettings.bDeferredAA = true;
	ZedPawn->Camera->PostProcessSettings.bPostProcessing = true;
	ZedPawn->Camera->CameraRenderingSettings.bLighting = true;
	ZedPawn->Camera->CameraRenderingSettings.bVelocity = true;
	ZedPawn->Camera->PostProcessSettings.bVirtualObjectsPostProcess = false;*/

	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessZedMaterialInstanceDynamic, 0.0f);

	ZedCamera->DisableRenderingCpp();

	UpdateHUDZedDisconnected();

	FadeOut();

	// Keep the last known pose so the reconnection restores it (applied after the config load in Internal_OpenZedCamera)
	LastPoseLocation = ZedCamera->TrackingData.ZedWorldTransform.GetLocation();
	LastPoseRotation = ZedCamera->TrackingData.ZedWorldTransform.GetRotation().Rotator();

	// Search for reconnection
	OpenZedCamera();
}

void AZEDPlayerController::ZedCameraDisconnected()
{
	SL_LOG_W(ZEDPlayerController, "ZedCameraDisconnected !");
	GetWorldTimerManager().ClearTimer(DisableFadePostProcessTimerHandle);
	ZedPawn->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	FadeIn();

	bZedCameraDisconnected = true;

	GSlCameraProxy->CloseCamera();

	GetWorldTimerManager().SetTimer(CameraDisconnectedTimerHandle, this, &AZEDPlayerController::Internal_ZedCameraDisconnected, 1.5f, false);
}

void AZEDPlayerController::ZedCameraClosed()
{
	bTickZedCamera = false;

	if (!bZedCameraDisconnected)
	{
		//PreZedEdit
		/*ZedPawn->Camera->PostProcessSettings.bDeferredAA = true;
		ZedPawn->Camera->PostProcessSettings.bPostProcessing = true;
		ZedPawn->Camera->CameraRenderingSettings.bLighting = true;
		ZedPawn->Camera->CameraRenderingSettings.bVelocity = true;*/

		//PreZedEdit
		//ZedPawn->Camera->PostProcessSettings.bVirtualObjectsPostProcess = false;
		ZedPawn->Camera->AddOrUpdateBlendable(PostProcessZedMaterialInstanceDynamic, 0.0f);
	}
}

void AZEDPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(AZEDPlayerController, ZedPawn, COND_OwnerOnly, REPNOTIFY_OnChanged);
}

void AZEDPlayerController::OnRep_ZedPawn()
{
	if (bUseDefaultBeginPlay)
	{
		bool bIsLocal = IsLocalPlayerController();

		if (bIsLocal && bIsFirstPlayer)
		{
			Init();
		}
	}

	OnPawnSpawned.Broadcast();
}

void AZEDPlayerController::FadeOutToGame()
{
	FadeOut();

	GetWorldTimerManager().SetTimer(DisableFadePostProcessTimerHandle, this, &AZEDPlayerController::DisableFadePostProcess, 2.0f, false);
}

void AZEDPlayerController::UpdateHUDOpeningZed_Implementation()
{
#if WITH_EDITOR
	ZedPawn->ZedLoadingWidget->SetText(FText::FromString("Searching for ZED camera"));
#endif
	ZedPawn->ZedLoadingWidget->SetVisibility(true);
	ZedPawn->ZedLoadingWidget->FadeIn();
}

void AZEDPlayerController::UpdateHUDCheckOpeningZed_Implementation()
{
	ESlErrorCode OpenErrorCode = GSlCameraProxy->GetOpenCameraErrorCode();

	sl::ERROR_CODE error_code = sl::unreal::ToSlType(OpenErrorCode);
	if (error_code > sl::ERROR_CODE::SUCCESS && error_code != sl::ERROR_CODE::LAST)
	{
		ZedPawn->ZedLoadingWidget->SetVisibility(false);
		ZedPawn->ZedErrorWidget->SetVisibility(true);
		ZedPawn->ZedErrorWidget->SetText(FText::FromString(USlFunctionLibrary::ErrorCodeToString(OpenErrorCode)));
	}
	else
	{
		ZedPawn->ZedErrorWidget->SetVisibility(false);

		ZedPawn->ZedLoadingWidget->SetVisibility(true);
#if WITH_EDITOR
		ZedPawn->ZedLoadingWidget->SetText(FText::FromString("Opening camera"));
#endif
	}
}

void AZEDPlayerController::UpdateHUDZedOpened_Implementation()
{
#if WITH_EDITOR
	ZedPawn->ZedLoadingWidget->SetText(FText::FromString("Camera opened"));
#endif
	ZedPawn->ZedLoadingWidget->FadeOut();
}

void AZEDPlayerController::UpdateHUDEnablingZedTracking_Implementation()
{
#if WITH_EDITOR
	ZedPawn->ZedLoadingWidget->SetText(FText::FromString("Enabling tracking"));
#endif
}

void AZEDPlayerController::UpdateHUDOptimizingAIModel_Implementation()
{
#if WITH_EDITOR
	ZedPawn->ZedLoadingWidget->SetVisibility(true);
	ZedPawn->ZedLoadingWidget->SetText(FText::FromString("Optimizing Neural Depth AI Model \n Can take few minutes ..."));
	ZedPawn->ZedLoadingWidget->FadeIn();
#endif
}

void AZEDPlayerController::UpdateHUDZedTrackingEnabled_Implementation(bool bSuccess, ESlErrorCode ErrorCode)
{
	if (!bSuccess)
	{
		ZedPawn->ZedLoadingWidget->SetVisibility(false);
		ZedPawn->ZedErrorWidget->SetText(FText::FromString(USlFunctionLibrary::ErrorCodeToString(ErrorCode)));
		ZedPawn->ZedErrorWidget->SetVisibility(true);
	}
	else
	{
#if WITH_EDITOR
		ZedPawn->ZedLoadingWidget->SetText(FText::FromString("Tracking enabled"));
#endif
		ZedPawn->ZedLoadingWidget->FadeOut();
	}
}

void AZEDPlayerController::UpdateHUDZedDisconnected_Implementation()
{
	ZedPawn->ZedErrorWidget->SetText(FText::FromString(USlFunctionLibrary::ErrorCodeToString(ESlErrorCode::EC_CameraNotDetected)));
	ZedPawn->ZedErrorWidget->SetVisibility(true);
	ZedPawn->ZedErrorWidget->FadeIn();
}
