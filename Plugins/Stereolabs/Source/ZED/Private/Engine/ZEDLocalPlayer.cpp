//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Classes/ZEDLocalPlayer.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDPlayerController.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"

#include "HeadMountedDisplayFunctionLibrary.h"
#include "IHeadMountedDisplay.h"
#include "SceneViewExtension.h"
#include "HAL/PlatformApplicationMisc.h"
#include "IXRTrackingSystem.h"
#include "IXRCamera.h"

DECLARE_CYCLE_STAT(TEXT("CalcSceneView"), STAT_CalcSceneView, STATGROUP_Engine);

static TAutoConsoleVariable<int32> CVarViewportTest(
	TEXT("r.Test.ConstrainedView"),
	0,
	TEXT("Allows to test different viewport rectangle configuations (in game only) as they can happen when using Matinee/Editor.\n")
	TEXT("0: off(default)\n")
	TEXT("1..7: Various Configuations"),
	ECVF_RenderThreadSafe);


UZEDLocalPlayer::UZEDLocalPlayer(const FObjectInitializer& ObjectInitializer)
	: 
	Super(ObjectInitializer)
{
}

bool UZEDLocalPlayer::GetZEDProjectionData(FViewport* Viewport, FSceneViewProjectionData& ProjectionData) const
{
	// If the actor
	if ((Viewport == NULL) || (PlayerController == NULL) || (Viewport->GetSizeXY().X == 0) || (Viewport->GetSizeXY().Y == 0))
	{
		return false;
	}

	bool bNeedStereo = UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled();

	if (!bNeedStereo)
	{
		int32 X = FMath::TruncToInt(Origin.X * Viewport->GetSizeXY().X);
		int32 Y = FMath::TruncToInt(Origin.Y * Viewport->GetSizeXY().Y);

		X += Viewport->GetInitialPositionXY().X;
		Y += Viewport->GetInitialPositionXY().Y;

		uint32 SizeX = FMath::TruncToInt(Size.X * Viewport->GetSizeXY().X);
		uint32 SizeY = FMath::TruncToInt(Size.Y * Viewport->GetSizeXY().Y);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

		// We expect some size to avoid problems with the view rect manipulation
		if (SizeX > 50 && SizeY > 50)
		{
			int32 Value = CVarViewportTest.GetValueOnGameThread();

			if (Value)
			{
				int InsetX = SizeX / 4;
				int InsetY = SizeY / 4;

				// this allows to test various typical view port situations (todo: split screen)
				switch (Value)
				{
				case 1: X += InsetX; Y += InsetY; SizeX -= InsetX * 2; SizeY -= InsetY * 2; break;
				case 2: Y += InsetY; SizeY -= InsetY * 2; break;
				case 3: X += InsetX; SizeX -= InsetX * 2; break;
				case 4: SizeX /= 2; SizeY /= 2; break;
				case 5: SizeX /= 2; SizeY /= 2; X += SizeX;	break;
				case 6: SizeX /= 2; SizeY /= 2; Y += SizeY; break;
				case 7: SizeX /= 2; SizeY /= 2; X += SizeX; Y += SizeY; break;
				}
			}
		}
#endif

		FIntRect UnconstrainedRectangle = FIntRect(X, Y, X + SizeX, Y + SizeY);

		ProjectionData.SetViewRectangle(UnconstrainedRectangle);

		// Get the viewpoint.
		FMinimalViewInfo ViewInfo;
		GetViewPoint(/*out*/ ViewInfo);
		ViewInfo.Location = GZedRawLocation;
		ViewInfo.Rotation = GZedRawRotation;

		// Create the view matrix
		ProjectionData.ViewOrigin = ViewInfo.Location;
		ProjectionData.ViewRotationMatrix = FInverseRotationMatrix(ViewInfo.Rotation) * FMatrix(
			FPlane(0, 0, 1, 0),
			FPlane(1, 0, 0, 0),
			FPlane(0, 1, 0, 0),
			FPlane(0, 0, 0, 1));

		ViewInfo.OffCenterProjectionOffset = USlFunctionLibrary::GetOffCenterProjectionOffset();
		FMinimalViewInfo::CalculateProjectionMatrixGivenView(ViewInfo, AspectRatioAxisConstraint, ViewportClient->Viewport, /*inout*/ ProjectionData);
	}
	else
	{
		FIntPoint Resolution = GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.Resolution;

		FMinimalViewInfo ViewInfo;
		ViewInfo.Location = GZedRawLocation;
		ViewInfo.Rotation = GZedRawRotation;
		ViewInfo.AspectRatio = (float)Resolution.X/(float)Resolution.Y;
		ViewInfo.bConstrainAspectRatio = true;
		ViewInfo.FOV = GSlCameraProxy->CameraInformation.CalibrationParameters.LeftCameraParameters.HFOV;
		ViewInfo.ProjectionMode = ECameraProjectionMode::Perspective;

		// Create the view matrix
		ProjectionData.ViewOrigin = ViewInfo.Location;
		ProjectionData.ViewRotationMatrix = FInverseRotationMatrix(ViewInfo.Rotation) * FMatrix(
			FPlane(0, 0, 1, 0),
			FPlane(1, 0, 0, 0),
			FPlane(0, 1, 0, 0),
			FPlane(0, 0, 0, 1));

		ProjectionData.SetConstrainedViewRectangle(FIntRect(0, 0, Resolution.X, Resolution.Y));

		ViewInfo.OffCenterProjectionOffset = USlFunctionLibrary::GetOffCenterProjectionOffset();
		ProjectionData.ProjectionMatrix = ViewInfo.CalculateProjectionMatrix();
	}

	return true;
}

bool UZEDLocalPlayer::GetProjectionData(FViewport* Viewport, 
	FSceneViewProjectionData& ProjectionData,
	int32 StereoViewIndex) const
{
	// If the actor
	if ((Viewport == NULL) || (PlayerController == NULL) || (Viewport->GetSizeXY().X == 0) || (Viewport->GetSizeXY().Y == 0))
	{
		return false;
	}

	int32 X = FMath::TruncToInt(Origin.X * Viewport->GetSizeXY().X);
	int32 Y = FMath::TruncToInt(Origin.Y * Viewport->GetSizeXY().Y);
	uint32 SizeX = FMath::TruncToInt(Size.X * Viewport->GetSizeXY().X);
	uint32 SizeY = FMath::TruncToInt(Size.Y * Viewport->GetSizeXY().Y);

#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)

	// We expect some size to avoid problems with the view rect manipulation
	if (SizeX > 50 && SizeY > 50)
	{
		int32 Value = CVarViewportTest.GetValueOnGameThread();

		if (Value)
		{
			int InsetX = SizeX / 4;
			int InsetY = SizeY / 4;

			// this allows to test various typical view port situations (todo: split screen)
			switch (Value)
			{
			case 1: X += InsetX; Y += InsetY; SizeX -= InsetX * 2; SizeY -= InsetY * 2; break;
			case 2: Y += InsetY; SizeY -= InsetY * 2; break;
			case 3: X += InsetX; SizeX -= InsetX * 2; break;
			case 4: SizeX /= 2; SizeY /= 2; break;
			case 5: SizeX /= 2; SizeY /= 2; X += SizeX;	break;
			case 6: SizeX /= 2; SizeY /= 2; Y += SizeY; break;
			case 7: SizeX /= 2; SizeY /= 2; X += SizeX; Y += SizeY; break;
			}
		}
	}
#endif

	FIntRect UnconstrainedRectangle = FIntRect(X, Y, X + SizeX, Y + SizeY);

	ProjectionData.SetViewRectangle(UnconstrainedRectangle);

	// Get the viewpoint.
	FMinimalViewInfo ViewInfo;
	GetViewPoint(/*out*/ ViewInfo);

	// If stereo rendering is enabled, update the size and offset appropriately for this pass
	const bool bNeedStereo((StereoViewIndex != INDEX_NONE) && GEngine->IsStereoscopic3D());
	const bool bIsHeadTrackingAllowed(GEngine->XRSystem.IsValid() && GEngine->XRSystem->IsHeadTrackingAllowed());
	if (bNeedStereo)
	{
		GEngine->StereoRenderingDevice->AdjustViewRect(StereoViewIndex, X, Y, SizeX, SizeY);
	}
	
	// scale distances for cull distance purposes by the ratio of our current FOV to the default FOV
	PlayerController->LocalPlayerCachedLODDistanceFactor = ViewInfo.FOV / FMath::Max<float>(0.01f, (PlayerController->PlayerCameraManager != NULL) ? PlayerController->PlayerCameraManager->DefaultFOV : 90.f);

	FVector StereoViewLocation = ViewInfo.Location;
	if (bNeedStereo || bIsHeadTrackingAllowed)
	{
		auto XRCamera = GEngine->XRSystem.IsValid() ? GEngine->XRSystem->GetXRCamera() : nullptr;
		if (XRCamera.IsValid())
		{
			AActor* ViewTarget = PlayerController->GetViewTarget();
			const bool bHasActiveCamera = ViewTarget && ViewTarget->HasActiveCameraComponent();
			XRCamera->UseImplicitHMDPosition(bHasActiveCamera);
		}

		if (GEngine->StereoRenderingDevice.IsValid())
		{
			//GEngine->StereoRenderingDevice->CalculateStereoViewOffset(StereoPass, ViewInfo.Rotation, GetWorld()->GetWorldSettings()->WorldToMeters, StereoViewLocation);
			StereoViewLocation += PlayerController->GetViewTarget()->GetActorRightVector() * (StereoViewIndex == eSSE_LEFT_EYE ? -GSlEyeHalfBaseline : GSlEyeHalfBaseline);
		}
	}

	// Create the view matrix
	ProjectionData.ViewOrigin = StereoViewLocation;
	ProjectionData.ViewRotationMatrix = FInverseRotationMatrix(ViewInfo.Rotation) * FMatrix(
		FPlane(0, 0, 1, 0),
		FPlane(1, 0, 0, 0),
		FPlane(0, 1, 0, 0),
		FPlane(0, 0, 0, 1));

	if (!bNeedStereo)
	{
		ViewInfo.OffCenterProjectionOffset = USlFunctionLibrary::GetOffCenterProjectionOffset();

		// Create the projection matrix (and possibly constrain the view rectangle)
		FMinimalViewInfo::CalculateProjectionMatrixGivenView(ViewInfo, AspectRatioAxisConstraint, ViewportClient->Viewport, /*inout*/ ProjectionData);

		FSceneViewExtensionContext Context(ViewportClient->Viewport);
		auto ActiveExtensions = GEngine->ViewExtensions->GatherActiveExtensions(Context);
		for (auto& ViewExt : ActiveExtensions)
		{
			ViewExt->SetupViewProjectionMatrix(ProjectionData);
		};
	}
	else
	{
		// Let the stereoscopic rendering device handle creating its own projection matrix, as needed
		ProjectionData.ProjectionMatrix = GEngine->StereoRenderingDevice->GetStereoProjectionMatrix(StereoViewIndex);

		// calculate the out rect
		ProjectionData.SetViewRectangle(FIntRect(X, Y, X + SizeX, Y + SizeY));
	}


	return true;
}

FSceneView* UZEDLocalPlayer::CalcSceneView(class FSceneViewFamily* ViewFamily,
	FVector& OutViewLocation,
	FRotator& OutViewRotation,
	FViewport* Viewport,
	class FViewElementDrawer* ViewDrawer,
	int32 StereoViewIndex)
{
	//SCOPE_CYCLE_COUNTER(STAT_CalcSceneView);

	FSceneViewInitOptions ViewInitOptions;

	if (!CalcSceneViewInitOptions(ViewInitOptions, Viewport, ViewDrawer, StereoViewIndex))
	{
		return nullptr;
	}

	// Get the viewpoint...technically doing this twice
	// but it makes GetProjectionData better
	FMinimalViewInfo ViewInfo;
	GetViewPoint(ViewInfo);
	OutViewLocation = ViewInfo.Location;
	OutViewRotation = ViewInfo.Rotation;
	ViewInitOptions.bUseFieldOfViewForLOD = ViewInfo.bUseFieldOfViewForLOD;

	// Fill out the rest of the view init options
	ViewInitOptions.ViewFamily = ViewFamily;

	if (static_cast<AZEDPlayerController*>(PlayerController)->bUseShowOnlyList)
	{
		PlayerController->bRenderPrimitiveComponents = true;

		ViewInitOptions.ShowOnlyPrimitives.Emplace();

		static_cast<AZEDPlayerController*>(PlayerController)->BuildShowOnlyComponentList(ViewInitOptions.ShowOnlyPrimitives.GetValue());
	}
	else if (!PlayerController->bRenderPrimitiveComponents)
	{
		// Emplaces an empty show only primitive list.
		ViewInitOptions.ShowOnlyPrimitives.Emplace();
	}
	else
	{
		QUICK_SCOPE_CYCLE_COUNTER(STAT_BuildHiddenComponentList);
		PlayerController->BuildHiddenComponentList(OutViewLocation,  ViewInitOptions.HiddenPrimitives);
	}

	//@TODO: SPLITSCREEN: This call will have an issue with splitscreen, as the show flags are shared across the view family
	EngineShowFlagOrthographicOverride(ViewInitOptions.IsPerspectiveProjection(), ViewFamily->EngineShowFlags);

	FSceneView* const View = new FSceneView(ViewInitOptions);

	View->ViewLocation = OutViewLocation;
	View->ViewRotation = OutViewRotation;

	ViewFamily->Views.Add(View);

	{
		View->StartFinalPostprocessSettings(OutViewLocation);

		// CameraAnim override
		if (PlayerController->PlayerCameraManager)
		{
			TArray<FPostProcessSettings> const* CameraAnimPPSettings;
			TArray<float> const* CameraAnimPPBlendWeights;
			PlayerController->PlayerCameraManager->GetCachedPostProcessBlends(CameraAnimPPSettings, CameraAnimPPBlendWeights);

			for (int32 PPIdx = 0; PPIdx < CameraAnimPPBlendWeights->Num(); ++PPIdx)
			{
				View->OverridePostProcessSettings((*CameraAnimPPSettings)[PPIdx], (*CameraAnimPPBlendWeights)[PPIdx]);
			}
		}

		//	CAMERA OVERRIDE
		//	NOTE: Matinee works through this channel
		View->OverridePostProcessSettings(ViewInfo.PostProcessSettings, ViewInfo.PostProcessBlendWeight);

		View->EndFinalPostprocessSettings(ViewInitOptions);
	}

	// Camera override
	// PreZedEdit
	//View->FinalCameraRenderingSettings = ViewInfo.CameraRenderingSettings;

	for (int ViewExt = 0; ViewExt < ViewFamily->ViewExtensions.Num(); ViewExt++)
	{
		ViewFamily->ViewExtensions[ViewExt]->SetupView(*ViewFamily, *View);
	}

	return View;
}