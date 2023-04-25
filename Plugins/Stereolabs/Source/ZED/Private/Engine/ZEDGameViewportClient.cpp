//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Classes/ZEDGameViewportClient.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Classes/ZEDLocalPlayer.h"

#include "EngineGlobals.h"
#include "Engine.h"
#include "Engine/GameEngine.h"
#include "Engine/Console.h"
#include "EngineModule.h"
#include "LegacyScreenPercentageDriver.h"
#include "SubtitleManager.h"
#include "AudioDevice.h"
#include "ContentStreaming.h"
#include "BufferVisualizationData.h"
#include "SceneViewExtension.h"
#include "FXSystem.h"
#include "RenderCore.h"
#include "ImageUtils.h"
#include "SceneViewExtension.h"
#include "DynamicResolutionState.h"


/**
 * Declares a rendering command type with 0 parameters.
 */
#define ENQUEUE_UNIQUE_RENDER_COMMAND(TypeName,Code) \
	class EURCMacro_##TypeName : public FRenderCommand \
	{ \
	public: \
		TASKNAME_FUNCTION(TypeName) \
		TASK_FUNCTION(Code) \
	}; \
	{ \
		LogRenderCommand(TypeName); \
		if(ShouldExecuteOnRenderThread()) \
		{ \
			CheckNotBlockedOnRenderThread(); \
			check(ENamedThreads::GameThread != ENamedThreads::GetRenderThread()); \
			TGraphTask<EURCMacro_##TypeName>::CreateTask().ConstructAndDispatchWhenReady(); \
		} \
		else \
		{ \
			EURCMacro_##TypeName TempCommand; \
			FScopeCycleCounter EURCMacro_Scope(TempCommand.GetStatId()); \
			TempCommand.DoTask(ENamedThreads::GameThread, FGraphEventRef() ); \
		} \
	}

/**
* UI Stats
*/
DECLARE_CYCLE_STAT(TEXT("UI Drawing Time"), STAT_UIDrawingTime, STATGROUP_UI);

static TAutoConsoleVariable<int32> CVarSetBlackBordersEnabled(
	TEXT("r.BlackBorders"),
	0,
	TEXT("To draw black borders around the rendered image\n")
	TEXT("(prevents artifacts from post processing passes that read outside of the image e.g. PostProcessAA)\n")
	TEXT("in pixels, 0:off"),
	ECVF_Default);

static TAutoConsoleVariable<float> CVarSecondaryScreenPercentage( // TODO: make it a user settings instead?
	TEXT("r.SecondaryScreenPercentage.GameViewport"),
	0,
	TEXT("Override secondary screen percentage for game viewport.\n")
	TEXT(" 0: Compute secondary screen percentage = 100 / DPIScalefactor automaticaly (default);\n")
	TEXT(" 1: override secondary screen percentage."),
	ECVF_Default);


UZEDGameViewportClient::UZEDGameViewportClient(const FObjectInitializer& ObjectInitializer)
	:
	UGameViewportClient(ObjectInitializer)
{
}

UZEDGameViewportClient::~UZEDGameViewportClient()
{

}

/**
* Draw debug info on a game scene view.
*/
class FGameViewDrawer : public FViewElementDrawer
{
public:


};

/** Util to find named canvas in transient package, and create if not found */
static UCanvas* GetCanvasByName(FName CanvasName)
{
	// Cache to avoid FString/FName conversions/compares
	static TMap<FName, UCanvas*> CanvasMap;
	UCanvas** FoundCanvas = CanvasMap.Find(CanvasName);
	if (!FoundCanvas)
	{
		UCanvas* CanvasObject = FindObject<UCanvas>(GetTransientPackage(), *CanvasName.ToString());
		if (!CanvasObject)
		{
			CanvasObject = NewObject<UCanvas>(GetTransientPackage(), CanvasName);
			CanvasObject->AddToRoot();
		}

		CanvasMap.Add(CanvasName, CanvasObject);
		return CanvasObject;
	}

	return *FoundCanvas;
}

void UZEDGameViewportClient::Draw(FViewport* InViewport, FCanvas* SceneCanvas)
{
	//Valid SceneCanvas is required.  Make this explicit.
	check(SceneCanvas);

	BeginDrawDelegate.Broadcast();

	const bool bStereoRendering = GEngine->IsStereoscopic3D(InViewport);
	FCanvas* DebugCanvas = InViewport->GetDebugCanvas();

	// Create a temporary canvas if there isn't already one.
	static FName CanvasObjectName(TEXT("CanvasObject"));
	UCanvas* CanvasObject = GetCanvasByName(CanvasObjectName);
	CanvasObject->Canvas = SceneCanvas;

	// Create temp debug canvas object
	FIntPoint DebugCanvasSize = InViewport->GetSizeXY();
	static FName DebugCanvasObjectName(TEXT("DebugCanvasObject"));
	UCanvas* DebugCanvasObject = GetCanvasByName(DebugCanvasObjectName);
	DebugCanvasObject->Canvas = DebugCanvas;
	DebugCanvasObject->Init(DebugCanvasSize.X, DebugCanvasSize.Y, NULL, DebugCanvas);

	static const auto DebugCanvasInLayerCVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("vr.DebugCanvasInLayer"));
	const bool bDebugInLayer = bStereoRendering && (DebugCanvasInLayerCVar && DebugCanvasInLayerCVar->GetValueOnAnyThread() != 0);

	if (DebugCanvas)
	{
		DebugCanvas->SetScaledToRenderTarget(bStereoRendering);
		DebugCanvas->SetStereoRendering(bStereoRendering);
		DebugCanvas->SetUseInternalTexture(bDebugInLayer);
	}
	if (SceneCanvas)
	{
		SceneCanvas->SetScaledToRenderTarget(bStereoRendering);
		SceneCanvas->SetStereoRendering(bStereoRendering);
	}

	bool bUIDisableWorldRendering = false;
	FGameViewDrawer GameViewDrawer;

	UWorld* MyWorld = GetWorld();

	// create the view family for rendering the world scene to the viewport's render target
	FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
		InViewport,
		MyWorld->Scene,
		EngineShowFlags)
		.SetRealtimeUpdate(true));

#if WITH_EDITOR
	if (GIsEditor)
	{
		// Force enable view family show flag for HighDPI derived's screen percentage.
		ViewFamily.EngineShowFlags.ScreenPercentage = true;
	}
#endif
	FSceneViewExtensionContext Context(InViewport);
	auto ActiveExtensions = GEngine->ViewExtensions->GatherActiveExtensions(Context);
	ViewFamily.ViewExtensions = ActiveExtensions;

	for (auto ViewExt : ViewFamily.ViewExtensions)
	{
		ViewExt->SetupViewFamily(ViewFamily);
	}

	ESplitScreenType::Type SplitScreenConfig = GetCurrentSplitscreenConfiguration();
	ViewFamily.ViewMode = EViewModeIndex(ViewModeIndex);
	EngineShowFlagOverride(ESFIM_Game, (EViewModeIndex)ViewModeIndex, ViewFamily.EngineShowFlags, false);

	if (ViewFamily.EngineShowFlags.VisualizeBuffer && AllowDebugViewmodes())
	{
		// Process the buffer visualization console command
		FName NewBufferVisualizationMode = NAME_None;
		static IConsoleVariable* ICVar = IConsoleManager::Get().FindConsoleVariable(FBufferVisualizationData::GetVisualizationTargetConsoleCommandName());
		if (ICVar)
		{
			static const FName OverviewName = TEXT("Overview");
			FString ModeNameString = ICVar->GetString();
			FName ModeName = *ModeNameString;
			if (ModeNameString.IsEmpty() || ModeName == OverviewName || ModeName == NAME_None)
			{
				NewBufferVisualizationMode = NAME_None;
			}
			else
			{
				if (GetBufferVisualizationData().GetMaterial(ModeName) == NULL)
				{
					// Mode is out of range, so display a message to the user, and reset the mode back to the previous valid one
					UE_LOG(LogConsoleResponse, Warning, TEXT("Buffer visualization mode '%s' does not exist"), *ModeNameString);
					NewBufferVisualizationMode = CurrentBufferVisualizationMode;
					// todo: cvars are user settings, here the cvar state is used to avoid log spam and to auto correct for the user (likely not what the user wants)
					ICVar->Set(*NewBufferVisualizationMode.GetPlainNameString(), ECVF_SetByCode);
				}
				else
				{
					NewBufferVisualizationMode = ModeName;
				}
			}
		}

		if (NewBufferVisualizationMode != CurrentBufferVisualizationMode)
		{
			CurrentBufferVisualizationMode = NewBufferVisualizationMode;
		}
	}

	TMap<ULocalPlayer*, FSceneView*> PlayerViewMap;

	FAudioDeviceHandle AudioDevice_ = MyWorld->GetAudioDevice();
	TArray<FSceneView*> Views;

	for (FLocalPlayerIterator Iterator(GEngine, MyWorld); Iterator; ++Iterator)
	{
		ULocalPlayer* LocalPlayer = *Iterator;
		if (LocalPlayer)
		{
			APlayerController* PlayerController = LocalPlayer->PlayerController;

			// PreZedEdit
			// removed ((ViewFamily.IsMonoscopicFarFieldEnabled()) ? 3 :
			const int32 NumViews = bStereoRendering ? GEngine->StereoRenderingDevice->GetDesiredNumberOfViews(bStereoRendering) : 1;

			for (int32 i = 0; i < NumViews; ++i)
			{
				// Calculate the player's view information.
				FVector		ViewLocation;
				FRotator	ViewRotation;

				//EStereoscopicPass PassType = bStereoRendering ? GEngine->StereoRenderingDevice->GetViewPassForIndex(bStereoRendering, i) : EStereoscopicPass::eSSP_FULL;
				int32 EyeViewIndex = bStereoRendering ? i : (int32)EStereoscopicEye::eSSE_MONOSCOPIC;
				//PreZedEdit
				FSceneView* View = static_cast<UZEDLocalPlayer*>(LocalPlayer)->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, InViewport, &GameViewDrawer, EyeViewIndex);

				if (View)
				{
					Views.Add(View);

					if (View->Family->EngineShowFlags.Wireframe)
					{
						// Wireframe color is emissive-only, and mesh-modifying materials do not use material substitution, hence...
						View->DiffuseOverrideParameter = FVector4f(0.f, 0.f, 0.f, 0.f);
						View->SpecularOverrideParameter = FVector4f(0.f, 0.f, 0.f, 0.f);
					}
					else if (View->Family->EngineShowFlags.OverrideDiffuseAndSpecular)
					{
						View->DiffuseOverrideParameter = FVector4f(GEngine->LightingOnlyBrightness.R, GEngine->LightingOnlyBrightness.G, GEngine->LightingOnlyBrightness.B, 0.0f);
						View->SpecularOverrideParameter = FVector4f(.1f, .1f, .1f, 0.0f);
					}
					else if (View->Family->EngineShowFlags.ReflectionOverride)
					{
						View->DiffuseOverrideParameter = FVector4f(0.f, 0.f, 0.f, 0.f);
						View->SpecularOverrideParameter = FVector4f(1, 1, 1, 0.0f);
						View->NormalOverrideParameter = FVector4f(0, 0, 1, 0.0f);
						View->RoughnessOverrideParameter = FVector2D(0.0f, 0.0f);
					}

					if (!View->Family->EngineShowFlags.Diffuse)
					{
						View->DiffuseOverrideParameter = FVector4f(0.f, 0.f, 0.f, 0.f);
					}

					if (!View->Family->EngineShowFlags.Specular)
					{
						View->SpecularOverrideParameter = FVector4f(0.f, 0.f, 0.f, 0.f);
					}

					View->CurrentBufferVisualizationMode = CurrentBufferVisualizationMode;

					View->CameraConstrainedViewRect = View->UnscaledViewRect;

					// If this is the primary drawing pass, update things that depend on the view location
					if (i == 0)
					{
						// Save the location of the view.
						LocalPlayer->LastViewLocation = ViewLocation;

						PlayerViewMap.Add(LocalPlayer, View);

						// Update the listener.
						if (AudioDevice_.IsValid() && PlayerController != NULL)
						{
							bool bUpdateListenerPosition = true;

							// If the main audio device is used for multiple PIE viewport clients, we only
							// want to update the main audio device listener position if it is in focus
							if (GEngine)
							{
								FAudioDeviceManager* AudioDeviceManager = GEngine->GetAudioDeviceManager();

								// If there is more than one world referencing the main audio device
								if (AudioDeviceManager->GetNumMainAudioDeviceWorlds() > 1)
								{
									FAudioDeviceHandle MainAudioDeviceHandle = GEngine->GetMainAudioDevice();
									if (AudioDevice_ == MainAudioDeviceHandle && !bHasAudioFocus)
									{
										bUpdateListenerPosition = false;
									}
								}
							}

							if (bUpdateListenerPosition)
							{
								FVector Location;
								FVector ProjFront;
								FVector ProjRight;
								PlayerController->GetAudioListenerPosition(/*out*/ Location, /*out*/ ProjFront, /*out*/ ProjRight);

								FTransform ListenerTransform(FRotationMatrix::MakeFromXY(ProjFront, ProjRight));

								ListenerTransform.SetTranslation(Location);
								ListenerTransform.NormalizeRotation();

								uint32 ViewportIndex = PlayerViewMap.Num() - 1;
								AudioDevice->SetListener(MyWorld, ViewportIndex, ListenerTransform, (View->bCameraCut ? 0.f : MyWorld->GetDeltaSeconds()));
							}
						}
						if (i ==  eSSE_LEFT_EYE)
						{
							// Save the size of the left eye view, so we can use it to reinitialize the DebugCanvasObject when rendering the console at the end of this method
							DebugCanvasSize = View->UnscaledViewRect.Size();
						}

					}

					// Add view information for resource streaming. Allow up to 5X boost for small FOV.
					const float StreamingScale = 1.f / FMath::Clamp<float>(View->LODDistanceFactor, .2f, 1.f);
					IStreamingManager::Get().AddViewInformation(View->ViewMatrices.GetViewOrigin(), View->UnscaledViewRect.Width(), View->UnscaledViewRect.Width() * View->ViewMatrices.GetProjectionMatrix().M[0][0]);
					MyWorld->ViewLocationsRenderedLastFrame.Add(View->ViewMatrices.GetViewOrigin());
				}
			}
		}
	}

	FinalizeViews(&ViewFamily, PlayerViewMap);

	// Update level streaming.
	MyWorld->UpdateLevelStreaming();

	// Find largest rectangle bounded by all rendered views.
	uint32 MinX = InViewport->GetSizeXY().X, MinY = InViewport->GetSizeXY().Y, MaxX = 0, MaxY = 0;
	uint32 TotalArea = 0;
	{
		for (int32 ViewIndex = 0; ViewIndex < ViewFamily.Views.Num(); ++ViewIndex)
		{
			const FSceneView* View = ViewFamily.Views[ViewIndex];

			FIntRect UpscaledViewRect = View->UnscaledViewRect;

			MinX = FMath::Min<uint32>(UpscaledViewRect.Min.X, MinX);
			MinY = FMath::Min<uint32>(UpscaledViewRect.Min.Y, MinY);
			MaxX = FMath::Max<uint32>(UpscaledViewRect.Max.X, MaxX);
			MaxY = FMath::Max<uint32>(UpscaledViewRect.Max.Y, MaxY);
			TotalArea += UpscaledViewRect.Width() * UpscaledViewRect.Height();
		}

		// To draw black borders around the rendered image (prevents artifacts from post processing passes that read outside of the image e.g. PostProcessAA)
		{
			int32 BlackBorders = FMath::Clamp(CVarSetBlackBordersEnabled.GetValueOnGameThread(), 0, 10);

			if (ViewFamily.Views.Num() == 1 && BlackBorders)
			{
				MinX += BlackBorders;
				MinY += BlackBorders;
				MaxX -= BlackBorders;
				MaxY -= BlackBorders;
				TotalArea = (MaxX - MinX) * (MaxY - MinY);
			}
		}
	}

	// If the views don't cover the entire bounding rectangle, clear the entire buffer.
	bool bBufferCleared = false;
	if (ViewFamily.Views.Num() == 0 || TotalArea != (MaxX - MinX)*(MaxY - MinY) || bDisableWorldRendering)
	{
		bool bStereoscopicPass = (ViewFamily.Views.Num() != 0 && ViewFamily.Views[0]->StereoPass != EStereoscopicPass::eSSP_FULL);
		if (bDisableWorldRendering || !bStereoscopicPass) // TotalArea computation does not work correctly for stereoscopic views
		{
			SceneCanvas->Clear(FLinearColor::Transparent);
		}

		bBufferCleared = true;
	}

	// Force screen percentage show flag to be turned off if not supported.
	if (!ViewFamily.SupportsScreenPercentage())
	{
		ViewFamily.EngineShowFlags.ScreenPercentage = false;
	}

	// Set up secondary resolution fraction for the view family.
	if (!bStereoRendering && ViewFamily.SupportsScreenPercentage())
	{
		float CustomSecondaruScreenPercentage = CVarSecondaryScreenPercentage.GetValueOnGameThread();

		if (CustomSecondaruScreenPercentage > 0.0)
		{
			// Override secondary resolution fraction with CVar.
			ViewFamily.SecondaryViewFraction = FMath::Min(CustomSecondaruScreenPercentage / 100.0f, 1.0f);
		}
		else
		{
			// Automatically compute secondary resolution fraction from DPI.
			ViewFamily.SecondaryViewFraction = GetDPIDerivedResolutionFraction();
		}

		check(ViewFamily.SecondaryViewFraction > 0.0f);
	}

	checkf(ViewFamily.GetScreenPercentageInterface() == nullptr,
		TEXT("Some code has tried to set up an alien screen percentage driver, that could be wrong if not supported very well by the RHI."));

	// Setup main view family with screen percentage interface by dynamic resolution if screen percentage is supported.
	//
	// Do not allow dynamic resolution to touch the view family if not supported to ensure there is no possibility to ruin
	// game play experience on platforms that does not support it, but have it enabled by mistake.
	if (ViewFamily.EngineShowFlags.ScreenPercentage && GEngine->GetDynamicResolutionState() && GEngine->GetDynamicResolutionState()->IsSupported())
	{
		GEngine->EmitDynamicResolutionEvent(EDynamicResolutionStateEvent::BeginDynamicResolutionRendering);
		GEngine->GetDynamicResolutionState()->SetupMainViewFamily(ViewFamily);
	}

	// If a screen percentage interface was not set by dynamic resolution, then create one matching legacy behavior.
	if (ViewFamily.GetScreenPercentageInterface() == nullptr)
	{
		bool AllowPostProcessSettingsScreenPercentage = false;
		float GlobalResolutionFraction = 1.0f;

		if (ViewFamily.EngineShowFlags.ScreenPercentage)
		{
			// Allow FPostProcessSettings::ScreenPercentage.
			AllowPostProcessSettingsScreenPercentage = true;

			// Get global view fraction set by r.ScreenPercentage.
			GlobalResolutionFraction = FLegacyScreenPercentageDriver::GetCVarResolutionFraction();
		}

		ViewFamily.SetScreenPercentageInterface(new FLegacyScreenPercentageDriver(
			ViewFamily, GlobalResolutionFraction, AllowPostProcessSettingsScreenPercentage));
	}
	else if (bStereoRendering)
	{
		// Change screen percentage method to raw output when doing dynamic resolution with VR if not using TAA upsample.
		for (FSceneView* View : Views)
		{
			if (View->PrimaryScreenPercentageMethod == EPrimaryScreenPercentageMethod::SpatialUpscale)
			{
				View->PrimaryScreenPercentageMethod = EPrimaryScreenPercentageMethod::RawOutput;
			}
		}
	}

	// Draw the player views.
	if (!bDisableWorldRendering && !bUIDisableWorldRendering && PlayerViewMap.Num() > 0) //-V560
	{
		GetRendererModule().BeginRenderingViewFamily(SceneCanvas, &ViewFamily);
	}
	else
	{
		// Does not exist anymore
		// Make sure RHI resources get flushed if we're not using a renderer
		ENQUEUE_UNIQUE_RENDER_COMMAND(UGameViewportClient_FlushRHIResources,
		{
			FRHICommandListExecutor::GetImmediateCommandList().ImmediateFlush(EImmediateFlushType::FlushRHIThreadFlushResources);
		});

	}

	// Beyond this point, only UI rendering independent from dynamc resolution.
	GEngine->EmitDynamicResolutionEvent(EDynamicResolutionStateEvent::EndDynamicResolutionRendering);

	// Clear areas of the rendertarget (backbuffer) that aren't drawn over by the views.
	if (!bBufferCleared)
	{
		// clear left
		if (MinX > 0)
		{
			SceneCanvas->DrawTile(0, 0, MinX, InViewport->GetSizeXY().Y, 0.0f, 0.0f, 1.0f, 1.f, FLinearColor::Black, NULL, false);
		}
		// clear right
		if (MaxX < (uint32)InViewport->GetSizeXY().X)
		{
			SceneCanvas->DrawTile(MaxX, 0, InViewport->GetSizeXY().X, InViewport->GetSizeXY().Y, 0.0f, 0.0f, 1.0f, 1.f, FLinearColor::Black, NULL, false);
		}
		// clear top
		if (MinY > 0)
		{
			SceneCanvas->DrawTile(MinX, 0, MaxX, MinY, 0.0f, 0.0f, 1.0f, 1.f, FLinearColor::Black, NULL, false);
		}
		// clear bottom
		if (MaxY < (uint32)InViewport->GetSizeXY().Y)
		{
			SceneCanvas->DrawTile(MinX, MaxY, MaxX, InViewport->GetSizeXY().Y, 0.0f, 0.0f, 1.0f, 1.f, FLinearColor::Black, NULL, false);
		}
	}

	// Remove temporary debug lines.
	if (MyWorld->LineBatcher != nullptr)
	{
		MyWorld->LineBatcher->Flush();
	}

	if (MyWorld->ForegroundLineBatcher != nullptr)
	{
		MyWorld->ForegroundLineBatcher->Flush();
	}

	// Draw FX debug information.
	if (MyWorld->FXSystem)
	{
		MyWorld->FXSystem->DrawDebug(SceneCanvas);
	}

	// Render the UI.
	{
		SCOPE_CYCLE_COUNTER(STAT_UIDrawingTime);

		// render HUD
		bool bDisplayedSubtitles = false;
		for (FConstPlayerControllerIterator Iterator = MyWorld->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			APlayerController* PlayerController = Iterator->Get();
			if (PlayerController)
			{
				ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);
				if (LocalPlayer)
				{
					FSceneView* View = PlayerViewMap.FindRef(LocalPlayer);
					if (View != NULL)
					{
						// rendering to directly to viewport target
						FVector CanvasOrigin(View->UnscaledViewRect.Min.X, View->UnscaledViewRect.Min.Y, 0.f);

						CanvasObject->Init(View->UnscaledViewRect.Width(), View->UnscaledViewRect.Height(), View, SceneCanvas);

						// Set the canvas transform for the player's view rectangle.
						check(SceneCanvas);
						SceneCanvas->PushAbsoluteTransform(FTranslationMatrix(CanvasOrigin));
						CanvasObject->ApplySafeZoneTransform();

						// Render the player's HUD.
						if (PlayerController->MyHUD)
						{
							//SCOPE_CYCLE_COUNTER(STAT_HudTime);

							DebugCanvasObject->SceneView = View;
							PlayerController->MyHUD->SetCanvas(CanvasObject, DebugCanvasObject);

							PlayerController->MyHUD->PostRender();

							// Put these pointers back as if a blueprint breakpoint hits during HUD PostRender they can
							// have been changed
							CanvasObject->Canvas = SceneCanvas;
							DebugCanvasObject->Canvas = DebugCanvas;

							// A side effect of PostRender is that the playercontroller could be destroyed
							if (!IsValid(PlayerController))
							{
								PlayerController->MyHUD->SetCanvas(NULL, NULL);
							}
						}

						if (DebugCanvas != NULL)
						{
							DebugCanvas->PushAbsoluteTransform(FTranslationMatrix(CanvasOrigin));
							UDebugDrawService::Draw(ViewFamily.EngineShowFlags, InViewport, View, DebugCanvas);
							DebugCanvas->PopTransform();
						}

						CanvasObject->PopSafeZoneTransform();
						SceneCanvas->PopTransform();

						// draw subtitles
						if (!bDisplayedSubtitles)
						{
							FVector2D MinPos(0.f, 0.f);
							FVector2D MaxPos(1.f, 1.f);
							GetSubtitleRegion(MinPos, MaxPos);

							const uint32 SizeX = SceneCanvas->GetRenderTarget()->GetSizeXY().X;
							const uint32 SizeY = SceneCanvas->GetRenderTarget()->GetSizeXY().Y;
							FIntRect SubtitleRegion(FMath::TruncToInt(SizeX * MinPos.X), FMath::TruncToInt(SizeY * MinPos.Y), FMath::TruncToInt(SizeX * MaxPos.X), FMath::TruncToInt(SizeY * MaxPos.Y));
							FSubtitleManager::GetSubtitleManager()->DisplaySubtitles(SceneCanvas, SubtitleRegion, MyWorld->GetAudioTimeSeconds());
							bDisplayedSubtitles = true;
						}
					}
				}
			}
		}

		//ensure canvas has been flushed before rendering UI
		SceneCanvas->Flush_GameThread();
		if (DebugCanvas != NULL)
		{
			DebugCanvas->Flush_GameThread();
		}

		DrawnDelegate.Broadcast();

		// Allow the viewport to render additional stuff
		PostRender(DebugCanvasObject);

	}


	// Grab the player camera location and orientation so we can pass that along to the stats drawing code.
	FVector PlayerCameraLocation = FVector::ZeroVector;
	FRotator PlayerCameraRotation = FRotator::ZeroRotator;
	for (FConstPlayerControllerIterator Iterator = MyWorld->GetPlayerControllerIterator(); Iterator; ++Iterator)
	{
		(*Iterator)->GetPlayerViewPoint(PlayerCameraLocation, PlayerCameraRotation);
	}

	if (DebugCanvas)
	{
		// Reset the debug canvas to be full-screen before drawing the console
		// (the debug draw service above has messed with the viewport size to fit it to a single player's subregion)
		DebugCanvasObject->Init(DebugCanvasSize.X, DebugCanvasSize.Y, NULL, DebugCanvas);

		DrawStatsHUD(MyWorld, InViewport, DebugCanvas, DebugCanvasObject, DebugProperties, PlayerCameraLocation, PlayerCameraRotation);

		// Render the console absolutely last because developer input is was matter the most.
		if (ViewportConsole)
		{
			ViewportConsole->PostRender_Console(DebugCanvasObject);
		}
	}

	EndDrawDelegate.Broadcast();
}