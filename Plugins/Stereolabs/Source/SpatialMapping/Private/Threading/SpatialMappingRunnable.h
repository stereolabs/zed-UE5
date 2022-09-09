//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Threading/StereolabsRunnable.h"
#include "Stereolabs/Public/Core/StereolabsMesh.h"

DECLARE_LOG_CATEGORY_EXTERN(SpatialMappingThread, Log, All);

class FSpatialMappingRunnable : public FSlRunnable
{
public:
	FSpatialMappingRunnable(class ASpatialMappingManager* SpatialMappingManager, USlMesh* Mesh, int CameraID);

public:
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Start(float Frequency) override;
	virtual void Stop() override;
	virtual void Exit() override;

private:
	/*
	 * Retrieve the mesh
	 * @return 0 if mesh not ready, 1 if mesh ready and retrieved, -1 if mesh ready but retrieved failed
	 */
	int RetrieveMesh();

	/*
	 * Filter the mesh
	 * @return True if filtered
	 */
	bool FilterMesh();

	/*
	 * Texture the mesh
	 * @return True if textured
	 */
	bool TextureMesh();

	/*
	 * Update the mesh data
	 * @param bGenerateNewMeshData True to create a new instance of MeshData
	 */
	void UpdateMesh();

	/*
	 * Load the mesh from a file
	 */
	bool LoadMesh();

	/*
	 * Save the mesh to a file
	 */
	bool SaveMesh();

public:
	/*
	 * Set the current step
	 * @param NewStep The new step
	 */
	void SetStep(ESpatialMappingStep NewStep);

	/*
	 * @return The current step
	 */
	ESpatialMappingStep GetStep();

	/*
	 * Set the save data
	 * @param NewMeshSavingPath The path to save the mesh
	 * @param NewMeshFileFormat the file format
	 */
	void SetSaveMeshData(FString NewMeshSavingPath, ESlMeshFileFormat NewMeshFileFormat);

	
	/*
	 * Set the load data
	 * @param NewMeshLoadingPath the path to load the mesh
	 */
	void SetLoadMeshData(FString NewMeshLoadingPath);

public:
	/** Texturing mode for texturing */
	ESpatialMappingTexturingMode TexturingMode;

	/** Mesh filter parameters */
	FSlMeshFilterParameters MeshFilterParameters;

private:
	/** Manager using this runnable */
	class ASpatialMappingManager* SpatialMappingManager;

	/** Update step section */
	FCriticalSection StepSection;

	/** Set load/save mesh data section */
	FCriticalSection MeshOperationSection;

	/** The step set by the manager */
	ESpatialMappingStep Step;

	/** The current step */
	ESpatialMappingStep CurrentStep;

	/** The current mesh */
	USlMesh* Mesh;

	int CameraID;

	/** Loading path */
	FString MeshLoadingPath;

	/** Saving path */
	FString MeshSavingPath;

	/** Mesh file format to save */
	ESlMeshFileFormat MeshFileFormat;
};

