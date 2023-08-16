//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "SpatialMapping/Public/Core/SpatialMappingManager.h"
#include "SpatialMappingPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"

ASpatialMappingManager::ASpatialMappingManager()
	:
	MeshFileFormat( ESlMeshFileFormat::MFF_OBJ ),
	bShowMesh( true ),
	bStepFailed( false ),
	SpatialMappingWorker( nullptr ),
	UpdateTime( 0.0f ),
	bSpatialMappingPaused( false )
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;
}

void ASpatialMappingManager::BeginPlay()
{
	Super::BeginPlay();

	Mesh = NewObject<USlMesh>();
}

void ASpatialMappingManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	DisableSpatialMapping();

	if (Mesh && Mesh->IsValidLowLevel())
	{
		Mesh->ConditionalBeginDestroy();
	}
}

void ASpatialMappingManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	GSlCameraProxy->GetWorld();
	if (bStepFailed)
	{
		bStepFailed = false;
		OnStepFailed.Broadcast(FailedStep);
	}

	UpdateTime += DeltaSeconds;
	if (UpdateTime >= 0.2f)
	{
		UpdateTime = 0.0f;

		// Try to access the mesh data if not updating
		SL_SCOPE_TRY_LOCK(Lock, MeshDataUpdateSection)
			SL_SCOPE_LOCK(SubLock, MeshDataAccessSection)
				// Update if mesh data available
				if (Step != ESpatialMappingStep::SS_None)
				{
					switch (Step)
					{
						case ESpatialMappingStep::SS_Scan:
							OnMeshUpdated.Broadcast(Mesh->MeshData);
							break;
						case ESpatialMappingStep::SS_Filter:
							OnMeshFiltered.Broadcast(Mesh->MeshData);
							break;
						case  ESpatialMappingStep::SS_Texture:
							{
								if (Mesh->Texture.GetData()) {
									Mesh->MeshData.Texture->UpdateResource();
									//sl_mat_free(Mesh->Texture.GetData(), (SL_MEM)sl_mat_get_memory_type(Mesh->Texture.GetData()));
								}
								switch (SpatialMappingWorker->TexturingMode)
								{
									case ESpatialMappingTexturingMode::TM_Render:
										OnMeshTexturedForRendering.Broadcast(Mesh->MeshData);
										break;
									case ESpatialMappingTexturingMode::TM_Cubemap:
										OnMeshTexturedForCubemap.Broadcast(Mesh->MeshData);
										break;
								}
							}
							break;
						case ESpatialMappingStep::SS_Save:
							OnMeshSaved.Broadcast();
							break;
						case ESpatialMappingStep::SS_Load:
							OnMeshLoaded.Broadcast(Mesh->MeshData);
							break;
					}

					// Reset mesh data
					Step = ESpatialMappingStep::SS_None;
				}
			SL_SCOPE_UNLOCK
		SL_SCOPE_TRY_UNLOCK
	}
}

#if WITH_EDITOR
void ASpatialMappingManager::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlSpatialMappingParameters, PresetResolution))
	{
		SpatialMappingParameters.SetResolution(SpatialMappingParameters.PresetResolution);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlSpatialMappingParameters, PresetRange))
	{
		SpatialMappingParameters.SetMaxRange(SpatialMappingParameters.PresetRange);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlSpatialMappingParameters, Resolution))
	{
		SpatialMappingParameters.SetResolution(SpatialMappingParameters.Resolution);
	}
	

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlSpatialMappingParameters, MaxRange))
	{
		SpatialMappingParameters.SetMaxRange(SpatialMappingParameters.MaxRange);
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool ASpatialMappingManager::CanEditChange(const FProperty* InProperty) const
{
	FName PropertyName = InProperty->GetFName();
	return Super::CanEditChange(InProperty);
}
#endif

bool ASpatialMappingManager::IsSpatialMappingEnabled()
{
	return SpatialMappingWorker != nullptr;
}

bool ASpatialMappingManager::IsSpatialMappingPaused()
{
	return IsSpatialMappingEnabled() && bSpatialMappingPaused;
}

void ASpatialMappingManager::EnableSpatialMapping()
{
	if (IsSpatialMappingEnabled())
	{
		return;
	}

	if (GSlCameraProxy->IsTrackingEnabled()) {
		SpatialMappingWorker = new FSpatialMappingRunnable(this, Mesh, GSlCameraProxy->GetCameraID());
			SpatialMappingWorker->Start(15.0f);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ZED Tracking is not enabled yet. Make sure it is activated and the camera can see the scene"));
	}

	OnScaningEnabled.Broadcast();
}

void ASpatialMappingManager::DisableSpatialMapping()
{
	if (!IsSpatialMappingEnabled())
	{
		return;
	}

	SpatialMappingWorker->EnsureCompletion();
	delete SpatialMappingWorker;
	SpatialMappingWorker = nullptr;

	GSlCameraProxy->DisableSpatialMapping();

	Mesh->Clear();

	bSpatialMappingPaused = false;

	OnSpatialMappingDisabled.Broadcast();
}

void ASpatialMappingManager::ResetSpatialMapping()
{
	DisableSpatialMapping();
	EnableSpatialMapping();

	OnSpatialMappingReset.Broadcast();
}

bool ASpatialMappingManager::StartSpatialMapping()
{
	if (!IsSpatialMappingEnabled())
	{
		return false;
	}

	if (GSlCameraProxy->EnableSpatialMapping(SpatialMappingParameters))
	{
		SetStep(ESpatialMappingStep::SS_Scan);

		return true;
	}

	return false;
}

void ASpatialMappingManager::PauseSpatialMapping(bool bPaused)
{
	if (!IsSpatialMappingEnabled())
	{
		return;
	}

	GSlCameraProxy->PauseSpatialMapping(bPaused);

	if (bPaused)
	{
		SetStep(ESpatialMappingStep::SS_None);
	}
	else
	{
		SetStep(ESpatialMappingStep::SS_Scan);
	}

	bSpatialMappingPaused = bPaused;
}

void ASpatialMappingManager::StopSpatialMapping()
{
	if (!IsSpatialMappingEnabled())
	{
		return;
	}

	SetStep(ESpatialMappingStep::SS_None);

	GSlCameraProxy->DisableSpatialMapping();

	bSpatialMappingPaused = false;
}

void ASpatialMappingManager::LoadMesh()
{
	if (!IsSpatialMappingEnabled())
	{
		return;
	}

	StopSpatialMapping();

	SpatialMappingWorker->SetLoadMeshData(MeshLoadingPath);
	SetStep(ESpatialMappingStep::SS_Load);
}

void ASpatialMappingManager::SaveMesh()
{
	if (!IsSpatialMappingEnabled())
	{
		return;
	}

	PauseSpatialMapping(true);

	SpatialMappingWorker->SetSaveMeshData(MeshSavingPath, MeshFileFormat);
	SetStep(ESpatialMappingStep::SS_Save);
}

void ASpatialMappingManager::FilterMesh()
{
	if (!IsSpatialMappingEnabled())
	{
		return;
	}

	PauseSpatialMapping(true);

	SpatialMappingWorker->MeshFilterParameters = MeshFilterParameters;
	SetStep(ESpatialMappingStep::SS_Filter);
}

bool ASpatialMappingManager::TextureMesh(ESpatialMappingTexturingMode TexturingMode)
{
	if (!IsSpatialMappingEnabled())
	{
		return false;
	}
	else if (SpatialMappingWorker->GetStep() == ESpatialMappingStep::SS_Texture)
	{
		return true;
	}

	PauseSpatialMapping(true);

	SpatialMappingWorker->TexturingMode = TexturingMode;
	SetStep(ESpatialMappingStep::SS_Texture);

	return true;
}

void ASpatialMappingManager::SetStep(ESpatialMappingStep NewStep)
{
	SpatialMappingWorker->SetStep(NewStep);
}

void ASpatialMappingManager::StepFailed(ESpatialMappingStep NewFailedStep)
{
	FailedStep = NewFailedStep;
	bStepFailed = true;
}

int ASpatialMappingManager::GetMeshVerticesNumber()
{
	SL_SCOPE_LOCK(Lock, MeshDataAccessSection)
		return Mesh->MeshData.Vertices.Num();
	SL_SCOPE_UNLOCK
}