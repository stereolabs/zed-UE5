//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "SpatialMapping/Public/Core/SpatialMappingBaseTypes.h"
#include "SpatialMapping/Private/Threading/SpatialMappingRunnable.h"
#include "Stereolabs/Public/Core/StereolabsMesh.h"

THIRD_PARTY_INCLUDES_START
#include "../../../ThirdParty/sl_zed_c/include/sl/c_api/zed_interface.h"
THIRD_PARTY_INCLUDES_END

#include "SpatialMappingManager.generated.h"

/*
 * Mesh related delegate
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpatialMappingManagerMeshDelegate, const FSlMeshData&, MeshData);

/*
 * Simple dynamic multicast delegate
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSpatialMappingManagerDelegate);

/*
 * Notify that a step a failed to complete
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpatialMappingStepFailedDelegate, ESpatialMappingStep, Step);

/*
 * Actor that manage the spatial mapping
 */
UCLASS(Category = "Stereolabs|SpatialMapping")
class SPATIALMAPPING_API ASpatialMappingManager : public AActor
{
	GENERATED_BODY()

public:
	ASpatialMappingManager();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaSeconds) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

	/*
	 * @return True if the SpatialMapping is enabled
	 */
	UFUNCTION(BlueprintPure, Category = "Zed|SpatialMapping")
	bool IsSpatialMappingEnabled();

	/*
	 * @return True if the SpatialMapping is paused
	 */
	UFUNCTION(BlueprintPure, Category = "Zed|SpatialMapping")
	bool IsSpatialMappingPaused();

	/*
	 * Enable the SpatialMapping in the SDK and start the SpatialMapping thread
	 * @param bEnableZedSpatialMapping True to enable Zed spatial mapping with the SpatialMapping thread
	 * @return True if bEnableZedSpatialMapping = false, else return true if Zed spatial mapping is enabled
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void EnableSpatialMapping();
	
	/*
	 * Stop the SpatialMapping thread and Zed spatial mapping
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void DisableSpatialMapping();

	/*
	 * Stop SpatialMapping thread and Zed spatial mapping, clear the mesh and restart the SpatialMapping thread
	 * @return see EnableSpatialMapping
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void ResetSpatialMapping();

	/*
	 * Start the spatial mapping
	 * @return True if spatial mapping is enabled, false otherwise
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	bool StartSpatialMapping();

	/*
	 * Pause the SpatialMapping
	 * @param bPaused True to pause, false to resume
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void PauseSpatialMapping(bool bPaused);

	/*
	 * Stop the spatial mapping but not the thread
	 * Filtering mesh and texture mesh are still possible.
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void StopSpatialMapping();

	/*
	 * Pause SpatialMapping and filter the mesh
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void FilterMesh();

	/*
	 *  Pause SpatialMapping and texture the mesh
	 * @param TexturingMode The texturing mode selected
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	bool TextureMesh(ESpatialMappingTexturingMode TexturingMode);
	
	/*
	 * Stop SpatialMapping and load the mesh
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void LoadMesh();

	/*
	 *  Pause SpatialMapping and save the mesh
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|SpatialMapping")
	void SaveMesh();

	/*
	 * @return the number of vertices in the mesh
	 */
	UFUNCTION(BlueprintPure, Category = "Zed|SpatialMapping")
	int GetMeshVerticesNumber();

public:
	/*
	 * Notify that the step failed to complete
	 */
	void StepFailed(ESpatialMappingStep NewFailedStep);

private:
	/*
	 * Set the step in the SpatialMapping thread
	 */
	void SetStep(ESpatialMappingStep NewStep);

public:
	/** SpatialMapping enabled dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerDelegate OnScaningEnabled;

	/** SpatialMapping disabled dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerDelegate OnSpatialMappingDisabled;

	/** Step fail dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingStepFailedDelegate OnStepFailed;

	/** Mesh update dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerMeshDelegate OnMeshUpdated;

	/** Mesh filtered dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerMeshDelegate OnMeshFiltered;

	/** Mesh textured for cubemap dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerMeshDelegate OnMeshTexturedForCubemap;

	/** Mesh textured for rendering dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerMeshDelegate OnMeshTexturedForRendering;

	/** Mesh loaded dispatcher */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerMeshDelegate OnMeshLoaded;

	/** Mesh saved dispatcher */
	UPROPERTY(BlueprintAssignable , Category = "Zed|SpatialMapping")
	FSpatialMappingManagerDelegate OnMeshSaved;

	/** SpatialMapping reset */
	UPROPERTY(BlueprintAssignable, Category = "Zed|SpatialMapping")
	FSpatialMappingManagerDelegate OnSpatialMappingReset;

public:
	/** Spatial mapping settings */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlSpatialMappingParameters SpatialMappingParameters;

	/** Filtering settings */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FSlMeshFilterParameters MeshFilterParameters;

	/** Mesh file format to save */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	ESlMeshFileFormat MeshFileFormat;

	/** Absolute mesh loading path */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FString MeshLoadingPath;

	/** Absolute mesh saving path */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Zed")
	FString MeshSavingPath;

	/** The mesh being used for spatial memory. Not thread safe to access if SpatialMapping enable, use delegate instead. */
	UPROPERTY(BlueprintReadOnly, Category = "Zed|SpatialMapping")
	USlMesh* Mesh;

	/** Mesh data update section */
	FCriticalSection MeshDataUpdateSection;

	/** Mesh data update section */
	FCriticalSection MeshDataAccessSection;

	/** Step associated with the mesh data */
	ESpatialMappingStep Step;

private:
	/** True if a step failed */
	FThreadSafeBool bStepFailed;

	/** Step that has failed */
	ESpatialMappingStep FailedStep;

	/** A worker to thread the SpatialMapping */
	class FSpatialMappingRunnable* SpatialMappingWorker;

	/** Timer to check if new mesh data are available */
	float UpdateTime;	

	/** True if SpatialMapping is paused */
	bool bSpatialMappingPaused;
};

