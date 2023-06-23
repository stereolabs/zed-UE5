//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsMesh.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"

USlMesh::USlMesh()
{
}

void USlMesh::UpdateMeshData()
{
	int VerticesNum = NbVertices * 3;
	int IndicesNum = NbTriangles * 3;

	int UVNum = 0;

	MeshData.Vertices.Reset(VerticesNum);
	MeshData.Indices.Reset(IndicesNum);

	if (MeshData.Texture)
	{
		UVNum = NbVertices * 2;

		MeshData.UV0.Reset(UVNum);
	}

	for (int i = 0; i < VerticesNum - 2; i += 3) {
		MeshData.Vertices.Add(FVector(
			Vertices[i],
			Vertices[i + 1],
			Vertices[i + 2]));
	}

	for (int i = 0; i < IndicesNum; ++i) {
		MeshData.Indices.Add(Triangles[i]);
	}

	for (int i = 0; i < UVNum - 1; i += 2) {
		MeshData.UV0.Add(FVector2D(UVs[i], UVs[i + 1]));
	}
}


bool USlMesh::Filter(const FSlMeshFilterParameters& MeshFilterParameters/* = FSlMeshFilterParameters()*/)
{
	bool bFiltered = sl_filter_whole_mesh(GSlCameraProxy->GetCameraID(), (SL_MESH_FILTER)MeshFilterParameters.FilterIntensity, &NbVertices, &NbTriangles);

	Vertices.SetNum(NbVertices * 3);
	UVs.SetNum(NbVertices * 2);
	Triangles.SetNum(NbTriangles * 3);
	Colors.SetNum(NbVertices * 3);

	(SL_ERROR_CODE)sl_retrieve_whole_mesh(GSlCameraProxy->GetCameraID(), Vertices.GetData(), Triangles.GetData(), Colors.GetData(), UVs.GetData(), Texture.GetData());

	return bFiltered;
}

bool USlMesh::ApplyTexture(bool bSRGB/* = false*/)
{
	bool bIsMeshTextured = false;

	if (Texture.Num()) bIsMeshTextured = true;

	if (!bIsMeshTextured)
	{
		bIsMeshTextured = sl_apply_whole_texture(GSlCameraProxy->GetCameraID(),	&NbVertices, &NbTriangles, TextureSize);

		Vertices.SetNum(NbVertices * 3);
		UVs.SetNum(NbVertices * 2);
		Triangles.SetNum(NbTriangles * 3);
		Colors.SetNum(NbVertices * 3);

		Texture.SetNum(TextureSize[0] * TextureSize[1] * 4);
		SL_ERROR_CODE err = (SL_ERROR_CODE)sl_retrieve_whole_mesh(GSlCameraProxy->GetCameraID(), Vertices.GetData(), Triangles.GetData(), Colors.GetData(), UVs.GetData(), Texture.GetData());

	}

	if (!bIsMeshTextured)
	{
		return false;
	}

	// Create texture
	UTexture2D* UTexture = UTexture2D::CreateTransient(TextureSize[0], TextureSize[1], EPixelFormat::PF_B8G8R8A8, "MeshTexture");
 
	// Populate texture
	FTexture2DMipMap& Mip = UTexture->GetPlatformData()->Mips[0];
	Mip.BulkData.Lock(LOCK_READ_WRITE);
	void* Data = Mip.BulkData.Realloc(TextureSize[0] * TextureSize[1] * 4);
	FMemory::Memcpy(Data, Texture.GetData(), TextureSize[0] * TextureSize[1] * 4);
	Mip.BulkData.Unlock();

	// Set texture settings
#if WITH_EDITORONLY_DATA
	UTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
	UTexture->CompressionNone = true;
	UTexture->CompressionNoAlpha = true;
	UTexture->DeferCompression = false;
#endif	
	UTexture->SRGB = bSRGB;
	UTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	UTexture->bNoTiling = true;
	UTexture->Filter = TextureFilter::TF_Bilinear;
	UTexture->AddressX = TextureAddress::TA_Clamp;
	UTexture->AddressY = TextureAddress::TA_Clamp;
	UTexture->LODGroup = TextureGroup::TEXTUREGROUP_World;

	if (IsInRenderingThread())
	{	
		//UTexture->UpdateResource();
	}

	MeshData.Texture = UTexture;

	return true;
}

bool USlMesh::Save(const FString& FilePath, const TArray<int32>& ChunksIDs, ESlMeshFileFormat FileFormat/* = ESlMeshFileFormat::MFF_OBJ*/)
{
	if (FilePath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Error SaveMesh : filepath is empty"));
		return false;
	}

	bool bSaved = sl_save_mesh(GSlCameraProxy->GetCameraID(), TCHAR_TO_UTF8(*FilePath), sl::unreal::ToSlType(FileFormat));

	return bSaved;
}

bool USlMesh::Load(const FString& FilePath, bool bUpdateChunksOnly/* = false*/)
{
	if (FilePath.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("Error LoadMesh : filepath is empty"));
		return false;
	}
	
	bool bIsLoaded = sl_load_whole_mesh(GSlCameraProxy->GetCameraID(), TCHAR_TO_UTF8(*FilePath), &NbVertices, &NbTriangles, TextureSize);

	Vertices.SetNum(NbVertices * 3);
	UVs.SetNum(NbVertices * 2);
	Triangles.SetNum(NbTriangles * 3);
	Colors.SetNum(NbVertices * 3);

	(SL_ERROR_CODE)sl_retrieve_whole_mesh(GSlCameraProxy->GetCameraID(), Vertices.GetData(), Triangles.GetData(), Colors.GetData(), UVs.GetData(), Texture.GetData());

	return bIsLoaded;
}

void USlMesh::Clear()
{
	MeshData.Clear();
}