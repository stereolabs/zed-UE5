//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include <sl/Camera.hpp>
#include "Windows/HideWindowsPlatformTypes.h"

THIRD_PARTY_INCLUDES_START
#include "../../../ThirdParty/sl_zed_c/include/sl/c_api/zed_interface.h"
THIRD_PARTY_INCLUDES_END

#include "StereolabsMesh.generated.h"

UCLASS(Category = "Stereolabs|Texture")
class STEREOLABS_API USlMesh : public UObject
{
	GENERATED_BODY()

public:
	USlMesh();

	/*
	 * Updates the mesh data from underlying mesh.
	 * Call this function after UpdateMeshFromChunks, Load, Filter, ApplyTexture
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs")
	void UpdateMeshData();

	/*
 	 * Filters the mesh.
	 *
	 * The resulting mesh in smoothed, small holes are filled and small blobs of non connected triangles are deleted.
     * 
	 * @param MeshFilterParameters The filtering parameters
     * @return True if the filtering was successful, false otherwise.
     *
	 * The filtering is a costly operation, its not recommended to call it every time you retrieve a mesh but at the end of your spatial mapping process.
	 */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "MeshFilterParameters"), Category = "Stereolabs")
	bool Filter(const FSlMeshFilterParameters& MeshFilterParameters);

	/*
     * Applies texture to the mesh.
	 *
	 * By using this function you will get access to UV0 and Texture.
	 * The number of triangles in the mesh may slightly differ before and after calling this functions due to missing texture informations.
	 * There is only one texture for the mesh, the uv of each chunks are expressed for it in its globality.
	 * Vectors of vertices/normals and uv have now the same size.
	 *
	 * @param bSRGB         True if texture must be SRGB, usefull if you want to create a cubemap from the mesh
	 * @return				True if the texturing was successful, false otherwise.
     *
	 * This function can be call as long as you do not start a new spatial mapping process, due to shared memory.
	 * This function can require a lot of computation time depending on the number of triangles in the mesh. Its recommended to call it once a the end of your spatial mapping process.
	 *  
	 * The bSaveTexture parameter in FSlSpatialMappingParameters must be set as true when enabling the spatial mapping to be able to apply the textures.
	 * The mesh should be filtered before calling this function since filter will erased the textures, the texturing is also significantly slower on non-filtered meshes.
	 *
	 * If not called in the render thread you must call MeshData.Texture->UpdateResource()
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs")
	bool ApplyTexture(bool bSRGB = false);
	/*
	 * Saves the current Mesh into a file.
	 * @param FilePath   the path and filename of the mesh
	 * @param ChunksIDs  Specify a set of chunks to be saved, if none provided alls chunks are saved
	 * @param FileFormat The file type (extension). default : MESH_FILE_OBJ.
	 * @return			 True if the file was successfully saved, false otherwise.
	 *
	 * Only ESlMeshFileFormat::MFF_OBJ support textures data.
	 * This function operate on the Mesh not on the chunks. This way you can save different parts of your Mesh (update your Mesh with UpdateMeshFromChunks).
	 */
	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "ChunksIDs"), Category = "Stereolabs")
	bool Save(const FString& FilePath, const TArray<int32>& ChunksIDs, ESlMeshFileFormat FileFormat = ESlMeshFileFormat::MFF_OBJ);

	/*
	 * Loads the mesh from a file.
     * @param FilePath		    The path and filename of the mesh (do not forget the extension).
	 * @param bUpdateChunksOnly If set to false the mesh data (vertices/normals/triangles) are updated otherwise only the chunks data are updated. default : false.
	 * @return				    True if the loading was successful, false otherwise.
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs")
	bool Load(const FString& FilePath, bool bUpdateChunksOnly = false);

	/*
     * Clears all the data.
	 */
	UFUNCTION(BlueprintCallable, Category="Stereolabs")
	void Clear();

public:
	/** Mesh data (indices, vertices, normals, UV0, texture) */
	FSlMeshData MeshData;

	int NbVertices;

	int NbTriangles;

	TArray<float> Vertices;

	TArray<int> Triangles;

	TArray<unsigned char> Colors;

	TArray<float> UVs;

	TArray<unsigned char> Texture;

	int TextureSize[2];
};