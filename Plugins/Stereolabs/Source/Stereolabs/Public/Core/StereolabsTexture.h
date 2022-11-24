//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"

#include "StereolabsTexture.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(SlTexture, Log, All);

/*
 * Texture used for rendering or holding mat
 */
UCLASS(Category = "Stereolabs|Texture")
class STEREOLABS_API USlTexture : public UObject
{
	GENERATED_BODY()

public:
	USlTexture();

	virtual void BeginDestroy() override;

public:
	/*
	 * @Param TestTextureType The texture type to test against
	 * @Return true if the texture has the right type
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	FORCEINLINE bool IsTypeOf(ESlTextureType TestTextureType)
	{
		return (TextureType == TestTextureType);
	}

	/*
	 * @Param TestMemoryType The memory type to test against
	 * @Return true if the memory has the right type
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	FORCEINLINE bool IsMemoryTypeOf(ESlMemoryType TestMemoryType)
	{
		return (MemoryType == TestMemoryType);
	}

	/* 
	 * @Return The memory type of the texture
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	FORCEINLINE ESlMemoryType GetMemoryType()
	{
		return MemoryType;
	}

	/*
	 * Update the UE texture. Only for GPU texture.
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "UpdateTexture", Category = "Stereolabs|Texture")
	void BP_UpdateTexture();

	/*
	 * Update the UE texture. Only for GPU texture.
	 * @param NewMat The mat used to update
	 */
	UFUNCTION(BlueprintCallable, DisplayName = "UpdateTextureWithMat", Category = "Stereolabs|Texture")
	void BP_UpdateTextureWithMat(const FSlMat& NewMat);

	/*
	 * Update the UE texture. Must be called from rendering thread, only for GPU texture.
	 */
	void UpdateTexture();

	/*
	 * Update the UE texture. Must be called from rendering thread, only for GPU texture.
	 * @param NewMat The mat used to update
	 */
	void UpdateTexture(const FSlMat& NewMat);

	/*
	 * Update the UE texture. Must be called from rendering thread, only for GPU texture.
	 * @param NewMat The mat used to update if different from that owning by the texture
	 */
	void UpdateTexture(void* NewMat);

	/*
	 * Resize the texture
	 * @param Width The new width
	 * @param Height The new height
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	bool Resize(int32 NewWidth, int32 NewHeight);

protected:
	/*
	 * Init the texture
	 * @param Format	  The format of the texture
	 * @param Compression The compression of the texture
	 */
	void InitResources(ESlTextureFormat Format, TextureCompressionSettings Compression);

public:
	/** Unreal texture if GPU */
	UPROPERTY(BlueprintReadOnly)
	UTexture2D* Texture;

	/** Width of the texture */
	UPROPERTY(BlueprintReadOnly)
	int32 Width;

	/** Height of the texture */
	UPROPERTY(BlueprintReadOnly)
	int32 Height;

	/** Mat holding resources from SDK */
	UPROPERTY(BlueprintReadWrite)
	FSlMat Mat;

	/** Name of the texture */
	UPROPERTY(BlueprintReadOnly)
	FName Name;

public:
	/** Cuda resource used for copying from SDK to render API */
	cudaGraphicsResource_t CudaResource;

	cudaSurfaceObject_t cuSurface{};
	cudaExternalMemoryHandleType m_externalMemoryHandleType;
	cudaExternalMemory_t m_externalMemory;

	void* MatPtr;

protected:
	/** Type of memory used to access the texture */
	ESlMemoryType MemoryType;

	/** Internal use only to determine texture type */
	ESlTextureType TextureType;

	/** Texture format */
	ESlTextureFormat TextureFormat;
};

/*
 * A view texture to retrieve images
 */
UCLASS(BlueprintType, Category = "Zed|Types")
class STEREOLABS_API USlViewTexture : public USlTexture
{
	GENERATED_BODY()

public:
	/*
	 * Create a GPU view texture
	 * @param TextureName       The name of the texture
	 * @param TextureWidth		The width of the texture
	 * @param TextureHeight	    The height of the texture
	 * @param TextureViewType   The view type of the texture
	 * @param bCreateTexture2D  True to create a texture 2D for rendering
	 * @param TextureFormat	    The format of the texture
	 * @return				    The view texture
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	static USlViewTexture* CreateGPUViewTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlView TextureViewType, bool bCreateTexture2D = true, ESlTextureFormat TextureFormat = ESlTextureFormat::TF_R8G8B8A8_SNORM, ESlViewFormat ViewFormat = ESlViewFormat::VF_Signed);

	/*
	 * Create a CPU view texture
	 * @param TextureName       The name of the texture
	 * @param TextureWidth		The width of the texture
	 * @param TextureHeight	    The height of the texture
	 * @param TextureViewType   The view type of the texture
	 * @return				    The view texture
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	static USlViewTexture* CreateCPUViewTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlView TextureViewType, ESlViewFormat ViewFormat = ESlViewFormat::VF_Signed);

private:
	/* 
	 * Create a View texture
	 * @param TextureName       The name of the texture
	 * @param TextureWidth		The width of the texture
	 * @param TextureHeight	    The height of the texture
	 * @param TextureViewType   The view type of the texture
	 * @param TextureMemoryType The memory type of the mat holding the data
	 * @param bCreateTexture2D  True to create a texture 2D for rendering
	 * @param TextureFormat	    The format of the texture
	 * @return				    The view texture
	 */
	static USlViewTexture* CreateViewTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlView TextureViewType, ESlMemoryType TextureMemoryType, bool bCreateTexture2D, ESlTextureFormat TextureFormat, ESlViewFormat ViewFormat = ESlViewFormat::VF_Signed);

public:
	/** Texture view type */
	UPROPERTY(BlueprintReadOnly, DisplayName = "ViewType")
	ESlView ViewType;

	/** Texture view type */
	UPROPERTY(BlueprintReadOnly, DisplayName = "ViewType")
	ESlViewFormat ViewFormat;
};

/*
 * A measure texture to retrieve measures
 */
UCLASS(BlueprintType, Category = "Zed|Types")
class STEREOLABS_API USlMeasureTexture : public USlTexture
{
	GENERATED_BODY()

public:
	/*
	 * Create a GPU measure texture
	 * @param TextureName        The name of the texture
	 * @param TextureWidth		 The width of the texture
	 * @param TextureHeight	     The height of the texture
	 * @param TextureMeasureType The measure type of the texture
	 * @param bCreateTexture2D   True to create a texture 2D for rendering
	 * @param TextureFormat	     The format of the texture
	 * @return				     The measure texture
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	static USlMeasureTexture* CreateGPUMeasureTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlMeasure TextureMeasureType, bool bCreateTexture2D = true, ESlTextureFormat TextureFormat = ESlTextureFormat::TF_R32_FLOAT);

	/*
	 * Create a CPU measure texture
	 * @param TextureName        The name of the texture
	 * @param TextureWidth		 The width of the texture
	 * @param TextureHeight	     The height of the texture
	 * @param TextureMeasureType The measure type of the texture
	 * @return				     The measure texture
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Texture")
	static USlMeasureTexture* CreateCPUMeasureTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlMeasure TextureMeasureType);

private:
	/*
	 * Create a Measure texture
	 * @param TextureName       The name of the texture
	 * @param TextureWidth		The width of the texture
	 * @param TextureHeight	    The height of the texture
	 * @param TextureViewType   The view type of the texture
	 * @param TextureMemoryType The memory type of the mat holding the data
	 * @param bCreateTexture2D  True to create a texture 2D for rendering
	 * @param TextureFormat	    The format of the texture
	 * @return					The measure texture
	 */
	static USlMeasureTexture* CreateMeasureTexture(const FName& TextureName, int32 TextureWidth, int32 TextureHeight, ESlMeasure TextureMeasureType, ESlMemoryType TextureMemoryType, bool bCreateTexture2D, ESlTextureFormat TextureFormat);

public:
	/** Texture measure type */
	UPROPERTY(BlueprintReadOnly, DisplayName = "MeasureType")
	ESlMeasure MeasureType;
};