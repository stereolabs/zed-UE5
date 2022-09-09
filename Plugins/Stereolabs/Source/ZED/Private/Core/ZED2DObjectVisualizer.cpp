//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZED2DObjectVisualizer.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"


DEFINE_LOG_CATEGORY(ZED2DObjectVisualizer);
#define SL_ZED2D_VISUALIZER_LOG_W(Format, ...) SL_LOG_W(ZED2DObjectVisualizer, Format, ##__VA_ARGS__)

AZED2DObjectVisualizer::AZED2DObjectVisualizer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AZED2DObjectVisualizer::BeginPlay()
{
	Super::BeginPlay();

	GSlCameraProxy->OnTrackingEnabled.AddDynamic(this, &AZED2DObjectVisualizer::OnZEDReady);
}

void AZED2DObjectVisualizer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AZED2DObjectVisualizer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (IsObjectDetectionEnabled())
	{
		SL_Objects objs;
		GSlCameraProxy->RetrieveObjects(objs, ObjectDetectionRuntimeParameters);
		Objects = sl::unreal::ToUnrealType(objs);
	}
}

#if WITH_EDITOR
void AZED2DObjectVisualizer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool AZED2DObjectVisualizer::CanEditChange(const FProperty* InProperty) const
{
	FName PropertyName = InProperty->GetFName();
	return Super::CanEditChange(InProperty);
}
#endif

bool AZED2DObjectVisualizer::IsObjectDetectionEnabled()
{
	return GSlCameraProxy->bObjectDetectionEnabled;
}

bool AZED2DObjectVisualizer::EnableObjectDetection()
{
	return GSlCameraProxy->EnableObjectDetection(ObjectDetectionParameters);
}

void AZED2DObjectVisualizer::DisableObjectDetection()
{
	GSlCameraProxy->DisableObjectDetection();
}

void AZED2DObjectVisualizer::OnZEDReady(bool bSuccess, ESlErrorCode ErrorCode, const FVector& Location, const FRotator& Rotation)
{
	if (bStartObjectDetectionAutomatically) {
		EnableObjectDetection();
	}
}

FIntPoint AZED2DObjectVisualizer::GetCameraResolution() {
	FIntPoint resolution = GSlCameraProxy->GetCameraInformation(FIntPoint::ZeroValue).Resolution;
	return resolution;
}
