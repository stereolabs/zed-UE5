//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDSkeletonVisualizer.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"


DEFINE_LOG_CATEGORY(ZEDSkeletonVisualizer);
#define SL_ZED_SKELETON_VISUALIZER_LOG_W(Format, ...) SL_LOG_W(ZEDSkeletonVisualizer, Format, ##__VA_ARGS__)

AZEDSkeletonVisualizer::AZEDSkeletonVisualizer()
{
	PrimaryActorTick.bCanEverTick = true;

	bStartObjectDetectionAutomatically = true;
}

void AZEDSkeletonVisualizer::BeginPlay()
{
	Super::BeginPlay();

	GSlCameraProxy->OnTrackingEnabled.AddDynamic(this, &AZEDSkeletonVisualizer::OnZEDReady);


}

void AZEDSkeletonVisualizer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AZEDSkeletonVisualizer::Tick(float DeltaSeconds)
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
void AZEDSkeletonVisualizer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool AZEDSkeletonVisualizer::CanEditChange(const FProperty* InProperty) const
{
	FName PropertyName = InProperty->GetFName();
	return Super::CanEditChange(InProperty);
}
#endif

bool AZEDSkeletonVisualizer::IsObjectDetectionEnabled()
{
	return GSlCameraProxy->bObjectDetectionEnabled;
}

bool AZEDSkeletonVisualizer::EnableObjectDetection()
{
	return GSlCameraProxy->EnableObjectDetection(ObjectDetectionParameters);
}

void AZEDSkeletonVisualizer::DisableObjectDetection()
{
	GSlCameraProxy->DisableObjectDetection();
}

void AZEDSkeletonVisualizer::OnZEDReady(bool bSuccess, ESlErrorCode ErrorCode, const FVector& Location, const FRotator& Rotation)
{
	if (bStartObjectDetectionAutomatically) {
		EnableObjectDetection();
	}
}


