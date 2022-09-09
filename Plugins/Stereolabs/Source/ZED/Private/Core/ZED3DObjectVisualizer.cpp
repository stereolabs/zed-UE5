//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZED3DObjectVisualizer.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"


DEFINE_LOG_CATEGORY(ZED3DObjectVisualizer);
#define SL_ZED3D_VISUALIZER_LOG_W(Format, ...) SL_LOG_W(ZED3DObjectVisualizer, Format, ##__VA_ARGS__)

AZED3DObjectVisualizer::AZED3DObjectVisualizer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AZED3DObjectVisualizer::BeginPlay()
{
	Super::BeginPlay();

	GSlCameraProxy->OnTrackingEnabled.AddDynamic(this, &AZED3DObjectVisualizer::OnZEDReady);
}

void AZED3DObjectVisualizer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AZED3DObjectVisualizer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (IsObjectDetectionEnabled())
	{
		GSlCameraProxy->RetrieveObjects(Objects, ObjectDetectionRuntimeParameters);

		if (Objects.is_new) {
			Visualize3DBoundingBoxes();
		}

	}
}

#if WITH_EDITOR
void AZED3DObjectVisualizer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool AZED3DObjectVisualizer::CanEditChange(const FProperty* InProperty) const
{
	FName PropertyName = InProperty->GetFName();
	return Super::CanEditChange(InProperty);
}
#endif

bool AZED3DObjectVisualizer::IsObjectDetectionEnabled()
{
	return GSlCameraProxy->bObjectDetectionEnabled;
}

bool AZED3DObjectVisualizer::EnableObjectDetection()
{
	return GSlCameraProxy->EnableObjectDetection(ObjectDetectionParameters);
}

void AZED3DObjectVisualizer::DisableObjectDetection()
{
	GSlCameraProxy->DisableObjectDetection();
}

void AZED3DObjectVisualizer::OnZEDReady(bool bSuccess, ESlErrorCode ErrorCode, const FVector& Location, const FRotator& Rotation)
{
	if (bStartObjectDetectionAutomatically) {
		EnableObjectDetection();
	}
}

AActor* AZED3DObjectVisualizer::GetBBoxForObject(SL_ObjectData obj) {

	if (!LiveBBoxes.Contains(obj.id)) {
		FName ObjName = FName(FString::FromInt(obj.id));
		
		AActor* bbox = GetWorld()->SpawnActor<AActor>(BBox3D);

		LiveBBoxes.Emplace(obj.id, bbox);
		return bbox;
	}
	else {
		return LiveBBoxes[obj.id];
	}
}

void AZED3DObjectVisualizer::Visualize3DBoundingBoxes()
{
	//Get a list of all active IDs from last frame, and we'll remove each box that's visible this frame. 
	TArray<int> ActiveIDs;
	LiveBBoxes.GetKeys(ActiveIDs);
	for (int i = 0; i < Objects.nb_object; i++) {
		auto obj = Objects.object_list[i];

		if (obj.tracking_state == SL_OBJECT_TRACKING_STATE_OK) {
			//Remove the ID from the list we'll use to clear no-longer-visible boxes. 
			if (ActiveIDs.Contains(obj.id)) ActiveIDs.Remove(obj.id);

			AActor* BBox = GetBBoxForObject(obj);
		
			SL_PoseData SL_Pose;
			GSlCameraProxy->GetCameraPosition(&SL_Pose, SL_REFERENCE_FRAME_WORLD);

			FSlPose CameraPose = sl::unreal::ToUnrealType(SL_Pose);

			FVector LeftTopFront = sl::unreal::ToUnrealType(obj.bounding_box[0]);
			FVector RightBottomBack = sl::unreal::ToUnrealType(obj.bounding_box[6]);

			float XSize = obj.dimensions.x;
			float YSize = obj.dimensions.z;
			float ZSize = obj.dimensions.y;

			FVector BoxPosition = (RightBottomBack + LeftTopFront) / 2;
			FVector CameraPosition = CameraPose.Transform.GetLocation();

			FVector normal = CameraPose.Transform.GetRotation().RotateVector(FVector::ForwardVector);
			FRotator BoxRotation = FRotator::ZeroRotator;
			//BoxRotation = UKismetMathLibrary::FindLookAtRotation(BoxPosition, CameraPosition); // box face camera
			BoxRotation = UKismetMathLibrary::FindLookAtRotation(FVector::Zero(), normal);

			FVector rota_euler = BoxRotation.Euler();
			rota_euler.Y = 0;
			BoxRotation = FRotator::MakeFromEuler(rota_euler);

			BBox->SetActorLocation(BoxPosition);
			BBox->SetActorRotation(BoxRotation);
			BBox->SetActorScale3D(FVector(XSize, YSize, ZSize) / 100.0f);

			FVector RightTopBack = sl::unreal::ToUnrealType(obj.bounding_box[2]);

			FVector LabelPos = BoxPosition + FVector(0, 0, (ZSize / 2) + 15);

			UTextRenderComponent* Label = BBox->FindComponentByClass<UTextRenderComponent>();
			if (Label) {
				Label->SetWorldLocation(LabelPos);

				FString label = FString("ID: ");
				label.AppendInt(obj.id);
				FText text;
				text = FText::FromString(label);

				Label->SetText(text);
			}
		}
	}

	for (auto& id : ActiveIDs) {
		AActor* bbox = LiveBBoxes[id];
		bbox->Destroy();
		LiveBBoxes.Remove(id);
	}
}

