//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Core/EnvironmentalLightingManager.h"
#include "EnvironmentalLightingPrivatePCH.h"

#include <sl_mr_core/EnvironmentalLighting.hpp>

/** Set environmental lighting max intensity */
//static TAutoConsoleVariable<float> CVarEnvLightMaxIntensity(
//	TEXT("r.ZED.EnvLightMaxIntensity"),
//	1.0f,
//	TEXT("Default to 1.0, range [0.005, 2.0]"),
//	ECVF_SetByConsole
//);

AEnvironmentalLightingManager::AEnvironmentalLightingManager()
	: 
	Light( nullptr ),
	bEnableEnvironmentalLighting( true ),
	EnvironmentalLightingIntensity( 1.0f ),
	LeftEyeTexture( nullptr ),
	Batch( nullptr )
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEnvironmentalLightingManager::BeginPlay()
{
	Super::BeginPlay();

	Batch = USlCPUTextureBatch::CreateCPUTextureBatch(FName("EnvironmentalLightingBatch"));

	sl::mr::environmentalLightingInitialize();

	SetActorTickEnabled(false);

	GSlCameraProxy->OnCameraOpened.AddDynamic(this, &AEnvironmentalLightingManager::ToggleTick);
	GSlCameraProxy->OnCameraClosed.AddDynamic(this, &AEnvironmentalLightingManager::ToggleTick);
}

void AEnvironmentalLightingManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	FlushRenderingCommands();

	if (GSlCameraProxy)
	{
		GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);

		GSlCameraProxy->OnCameraOpened.RemoveDynamic(this, &AEnvironmentalLightingManager::ToggleTick);
		GSlCameraProxy->OnCameraClosed.RemoveDynamic(this, &AEnvironmentalLightingManager::ToggleTick);
	}
	
	Batch->Clear();

	sl::mr::environmentalLightingShutdown();
}

void AEnvironmentalLightingManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UDirectionalLightComponent* LightComponent = Light ? static_cast<UDirectionalLightComponent*>(Light->GetLightComponent()) : nullptr;

	if (LightComponent && bEnableEnvironmentalLighting)
	{
		if (!GrabDelegateHandle.IsValid())
		{
			GrabDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp) {
				GrabCallback(ErrorCode, Timestamp);
			});
		}
		
		bool bUpdateLighting = Batch->Tick();
		if (bUpdateLighting)
		{
			FSlMat mat = LeftEyeTexture->Mat;
			sl::mr::environmentalLightingComputeDiffuseCoefficients((unsigned char *)sl_mat_get_ptr(mat.Mat, SL_MEM_CPU), sl_mat_get_width(mat.Mat), sl_mat_get_height(mat.Mat), sl_mat_get_channels(mat.Mat));
		}

		EnvironmentalLightingSettings.Exposure = sl::mr::environmentalLightingGetExposure(DeltaSeconds);
		EnvironmentalLightingSettings.Exposure += (EnvironmentalLightingSettings.Exposure > 0.1f ? 0.2f : 0.0f);
		EnvironmentalLightingSettings.Exposure = FMath::Min(2.0f, EnvironmentalLightingSettings.Exposure * 2.0f);
		UE_LOG(LogTemp, Warning, TEXT("%f"), EnvironmentalLightingSettings.Exposure);
		LightComponent->SetIntensity(FMath::Clamp(EnvironmentalLightingSettings.Exposure, 0.005f, EnvironmentalLightingIntensity));
	}
	else
	{
		GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
	}

}

void AEnvironmentalLightingManager::ToggleTick()
{
	if (GSlCameraProxy->IsCameraOpened())
	{
		LeftEyeTexture = USlViewTexture::CreateCPUViewTexture(FName("EnvLightingLeftView"), 128, 72, ESlView::V_Left, ESlViewFormat::VF_Unsigned);

		Batch->AddTexture(LeftEyeTexture);
	}
	else
	{
		Batch->Clear();

		if (LeftEyeTexture) {
			LeftEyeTexture->ConditionalBeginDestroy();
		}
	}

	SetActorTickEnabled(GSlCameraProxy->IsCameraOpened());
}

void AEnvironmentalLightingManager::GrabCallback(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp)
{
	if (ErrorCode != ESlErrorCode::EC_Success)
	{
		return;
	}

	Batch->RetrieveCurrentFrame(Timestamp);
}
