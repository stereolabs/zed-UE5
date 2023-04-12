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

#define MONO_NOISE_OFFSET 0.85f

#define ADD_FVECTOR_2D(Vector, Value)\
	Vector.X += Value;\
	Vector.Y += Value;\

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


/** Show ZED FPS */
static TAutoConsoleVariable<int32> CVarZEDShowFPS(
	TEXT("r.ZED.ShowFPS"),
	0,
	TEXT("1 to show, 0 to hide"),
	ECVF_RenderThreadSafe
);

AZEDPlayerController::AZEDPlayerController()
	:
	CameraClass(AZEDCamera::StaticClass()),
	ZedCamera(nullptr),
	bUseDefaultBeginPlay(true),
	bOpenZedCameraAtInit(true),
	bIsFirstPlayer(false),
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
	if (bTickZedCamera)
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
		SpawnCamera(CameraClass);

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
			SpawnCamera(CameraClass);

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
				// Dedicated server spawn Camera before begin play
				if (ZedCamera)
				{
					OnCameraSpawned.Broadcast();
				}

				SpawnZedCameraActor();

				// Dedicated server spawn Camera before begin play
				if (ZedCamera)
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
		ZedCamera->OnTrackingDataUpdated.RemoveDynamic(ZedCamera, &AZEDCamera::ZedCameraTrackingUpdated);
	}

	GetWorldTimerManager().ClearTimer(NoiseTimerHandle);
}

UObject* AZEDPlayerController::SpawnCamera(UClass* NewCameraClass, bool bPossess)
{
	TArray<AActor*> ActorsToFind;
	UWorld* World = GetWorld();
	if (World)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), NewCameraClass, ActorsToFind);
	}

	if (ActorsToFind.Num() > 0) 
	{
		ZedCamera = Cast<AZEDCamera>(ActorsToFind[0]);
		World->SetNewWorldOrigin(FIntVector(ZedCamera->GetActorTransform().GetLocation().X, ZedCamera->GetActorTransform().GetLocation().Y, 0.0f) + World->OriginLocation);
		ZedCamera->SetStartOffsetLocation(ZedCamera->GetActorTransform().GetLocation());
	}
	else 
	{
		// Spawn ZedCamera
		ZedCamera = Cast<AZEDCamera>(GetWorld()->SpawnActor(NewCameraClass));
	}

	checkf(ZedCamera, TEXT("NeCameraClass must inherit from AZedCamera"));

	if (bPossess)
	{
		//Possess(ZedCamera);
	}

	OnCameraSpawned.Broadcast();

	return ZedCamera;
}

void AZEDPlayerController::SpawnZedCameraActor()
{
	ZedCamera = GetWorld()->SpawnActor<AZEDCamera>();
}

void AZEDPlayerController::Init()
{
	if (bInit)
	{
		return;
	}

	// Attach Zed camera actor to pawn
	//ZedCamera->AttachToComponent(ZedPawn->GetRootComponent(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false));

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
	ZedCamera->OnTrackingDataUpdated.AddDynamic(ZedCamera, &AZEDCamera::ZedCameraTrackingUpdated);

	// Enable fade post process
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

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
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

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

	ZedCamera->ZedLoadingWidget->SetVisibility(false);
	ZedCamera->ZedErrorWidget->SetVisibility(false);

	Internal_OpenZedCamera();
}

void AZEDPlayerController::Internal_OpenZedCamera()
{

	ZedCamera->ZedLoadingWidget->WidgetComponent->SetGeometryMode(EWidgetGeometryMode::Plane);
	ZedCamera->ZedLoadingWidget->SetWorldScale3D(FVector(0.3f));

	ZedCamera->ZedErrorWidget->WidgetComponent->SetGeometryMode(EWidgetGeometryMode::Plane);
	ZedCamera->ZedErrorWidget->SetWorldScale3D(FVector(0.3f));

	if (ZedCamera->InitParameters.DepthMode == ESlDepthMode::DM_Neural && !GSlCameraProxy->CheckAIModelOptimization(ESlAIModels::AIM_NeuralDepth)) {

		GSlCameraProxy->OptimizeAIModel(ESlAIModels::AIM_NeuralDepth);
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

	// Set fade post process
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);
	// Set camera field of view
	if (ZedCamera->bShowZedImage)
		ZedCamera->Camera->SetFieldOfView(GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.HFOV);
	else 
		ZedCamera->Camera->SetFieldOfView(100.0f);

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
	ZedCamera->SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	ZedCamera->AddOrUpdatePostProcessCpp(PostProcessZedMaterialInstanceDynamic,  1.0f);
	//PreZedEdit
	/*ZedPawn->Camera->PostProcessSettings.bDeferredAA = false;
	ZedPawn->Camera->PostProcessSettings.bPostProcessing = false;
	ZedPawn->Camera->CameraRenderingSettings.bLighting = false;*/

	ZedCamera->ZedLoadingWidget->SetVisibility(false);
	ZedCamera->ZedErrorWidget->SetVisibility(false);

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

void AZEDPlayerController::UpdateNoise()
{
	int value = sl_get_camera_settings(GSlCameraProxy->GetCameraID(), SL_VIDEO_SETTINGS_GAIN, &value);
	FZEDNoiseFactors NoiseFactors = sl::unreal::ToUnrealType(sl::mr::computeNoiseFactors(value));

	ADD_FVECTOR_2D(NoiseFactors.R, MONO_NOISE_OFFSET);
	ADD_FVECTOR_2D(NoiseFactors.G, MONO_NOISE_OFFSET);
	ADD_FVECTOR_2D(NoiseFactors.B, MONO_NOISE_OFFSET);

	if (NoiseFactors.R == LastNoiseFactors.R)
	{
		return;
	}

	LastNoiseFactors = NoiseFactors;
	
	FLinearColor Red(NoiseFactors.R.X, NoiseFactors.R.Y, 0.0f);
	PostProcessZedMaterialInstanceDynamic->SetVectorParameterValue("RedFactors", Red);

	FLinearColor Green(NoiseFactors.G.X, NoiseFactors.G.Y, 0.0f);
	PostProcessZedMaterialInstanceDynamic->SetVectorParameterValue("GreenFactors", Green);

	FLinearColor Blue(NoiseFactors.B.X, NoiseFactors.B.Y, 0.0f);
	PostProcessZedMaterialInstanceDynamic->SetVectorParameterValue("BlueFactors", Blue);
}

void AZEDPlayerController::Fading(float FadingFactor)
{
	PostProcessFadeMaterialInstanceDynamic->SetScalarParameterValue("FadingFactor", FadingFactor);
}

void AZEDPlayerController::FadeIn()
{
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	FadeTimeline->ReverseFromEnd();
}

void AZEDPlayerController::FadeOut()
{
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

	FadeTimeline->PlayFromStart();
}

void AZEDPlayerController::DisableFadePostProcess()
{
	// If camera disconnected right before disabling fade post process
	if (!GSlCameraProxy->IsCameraConnected())
	{
		return;
	}
	
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 0.0f);
}

void AZEDPlayerController::Internal_ZedCameraDisconnected()
{
	//PreZedEdit
	/*ZedPawn->Camera->PostProcessSettings.bDeferredAA = true;
	ZedPawn->Camera->PostProcessSettings.bPostProcessing = true;
	ZedPawn->Camera->CameraRenderingSettings.bLighting = true;
	ZedPawn->Camera->CameraRenderingSettings.bVelocity = true;
	ZedPawn->Camera->PostProcessSettings.bVirtualObjectsPostProcess = false;*/

	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessZedMaterialInstanceDynamic, 0.0f);

	ZedCamera->DisableRenderingCpp();

	UpdateHUDZedDisconnected();

	FadeOut();

	ZedCamera->TrackingParameters.Location = ZedCamera->TrackingData.ZedWorldTransform.GetLocation();
	ZedCamera->TrackingParameters.Rotation = ZedCamera->TrackingData.ZedWorldTransform.GetRotation().Rotator();
	// Search for reconnection
	OpenZedCamera();
}

void AZEDPlayerController::ZedCameraDisconnected()
{
	SL_LOG_W(ZEDPlayerController, "ZedCameraDisconnected !");
	GetWorldTimerManager().ClearTimer(DisableFadePostProcessTimerHandle);
	ZedCamera->Camera->AddOrUpdateBlendable(PostProcessFadeMaterialInstanceDynamic, 1.0f);

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
		ZedCamera->Camera->AddOrUpdateBlendable(PostProcessZedMaterialInstanceDynamic, 0.0f);
	}
}

void AZEDPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(AZEDPlayerController, ZedCamera, COND_OwnerOnly, REPNOTIFY_OnChanged);
}

void AZEDPlayerController::OnRep_ZedCamera()
{
	if (bUseDefaultBeginPlay)
	{
		bool bIsLocal = IsLocalPlayerController();

		if (bIsLocal && bIsFirstPlayer)
		{
			Init();
		}
	}

	OnCameraSpawned.Broadcast();
}

void AZEDPlayerController::FadeOutToGame()
{
	FadeOut();

	GetWorldTimerManager().SetTimer(DisableFadePostProcessTimerHandle, this, &AZEDPlayerController::DisableFadePostProcess, 2.0f, false);
}

void AZEDPlayerController::UpdateHUDOpeningZed_Implementation()
{
#if WITH_EDITOR
	ZedCamera->ZedLoadingWidget->SetText(FText::FromString("Searching for ZED camera"));
#endif
	ZedCamera->ZedLoadingWidget->SetVisibility(true);
	ZedCamera->ZedLoadingWidget->FadeIn();
}

void AZEDPlayerController::UpdateHUDCheckOpeningZed_Implementation()
{
	ESlErrorCode OpenErrorCode = GSlCameraProxy->GetOpenCameraErrorCode();

	if (OpenErrorCode != ESlErrorCode::EC_Success && OpenErrorCode != ESlErrorCode::EC_None)
	{
		ZedCamera->ZedLoadingWidget->SetVisibility(false);

		ZedCamera->ZedErrorWidget->SetVisibility(true);
		ZedCamera->ZedErrorWidget->SetText(FText::FromString(USlFunctionLibrary::ErrorCodeToString(GSlCameraProxy->GetOpenCameraErrorCode())));
	}
	else
	{
		ZedCamera->ZedErrorWidget->SetVisibility(false);

		ZedCamera->ZedLoadingWidget->SetVisibility(true);
#if WITH_EDITOR
		ZedCamera->ZedLoadingWidget->SetText(FText::FromString("Opening camera"));
#endif
	}
}

void AZEDPlayerController::UpdateHUDZedOpened_Implementation()
{
#if WITH_EDITOR
	ZedCamera->ZedLoadingWidget->SetText(FText::FromString("Camera opened"));
#endif
	ZedCamera->ZedLoadingWidget->FadeOut();
}

void AZEDPlayerController::UpdateHUDEnablingZedTracking_Implementation()
{
#if WITH_EDITOR
	ZedCamera->ZedLoadingWidget->SetText(FText::FromString("Enabling tracking"));
#endif
}

void AZEDPlayerController::UpdateHUDOptimizingAIModel_Implementation()
{
#if WITH_EDITOR
	ZedCamera->ZedLoadingWidget->SetVisibility(true);
	ZedCamera->ZedLoadingWidget->SetText(FText::FromString("Optimizing Neural Depth AI Model \n Can take few minutes ..."));
	ZedCamera->ZedLoadingWidget->FadeIn();
#endif
}

void AZEDPlayerController::UpdateHUDZedTrackingEnabled_Implementation(bool bSuccess, ESlErrorCode ErrorCode)
{
	if (!bSuccess)
	{
		ZedCamera->ZedLoadingWidget->SetVisibility(false);

		ZedCamera->ZedErrorWidget->SetText(FText::FromString(USlFunctionLibrary::ErrorCodeToString(ErrorCode)));
		ZedCamera->ZedErrorWidget->SetVisibility(true);
	}
	else
	{
#if WITH_EDITOR
		ZedCamera->ZedLoadingWidget->SetText(FText::FromString("Tracking enabled"));
#endif
		ZedCamera->ZedLoadingWidget->FadeOut();
	}
}

void AZEDPlayerController::UpdateHUDZedDisconnected_Implementation()
{
	ZedCamera->ZedErrorWidget->SetText(FText::FromString(USlFunctionLibrary::ErrorCodeToString(ESlErrorCode::EC_CameraNotDetected)));
	ZedCamera->ZedErrorWidget->SetVisibility(true);
	ZedCamera->ZedErrorWidget->FadeIn();
}
