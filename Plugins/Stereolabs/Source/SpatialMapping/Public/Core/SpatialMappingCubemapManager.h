//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once
#include "../../Private/Threading/SpatialMappingCubemapRunnable.h"

#include "GameFramework/Actor.h"
#include "Components/SceneCaptureComponentCube.h"
#include "SpatialMappingCubemapManager.generated.h"

struct FSpatialMappingCubemapProxy
{
	UTextureRenderTargetCube* TextureTarget = nullptr;

	UTextureCube* Cubemap = nullptr;

	FThreadSafeBool bComplete = false;
};

/*
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpatialMappingCubemapDelegate, UTextureCube*, Cubemap);

/*
 * Asynchronously build a cubemap
 */
UCLASS(Category = "Stereolabs|SpatialMapping")
class SPATIALMAPPING_API ASpatialMappingCubemapManager : public AActor
{
	GENERATED_BODY()

public:
	ASpatialMappingCubemapManager();

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaSeconds) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

	/*
	 * Build the cubemap asynchronously
	 * @param Name The name of the texture
	 * @return False if the build can't be done because previous build is not finished
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Cubemap")
	bool BuildCubemap(const FName& Name);

	/*
	 * Capture the scene at the current actor location and orientation
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Cubemap")
	void CaptureScene();

	/*
	 * Set the new texture target
	 * @param NewTextureTarget The new texture target to render the scene to
	 * @return True if the texture is set
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed|Cubemap")
	bool SetTextureTarget(UTextureRenderTargetCube* NewTextureTarget);

public:
	/** Cubemap build complete dispatcher  */
	UPROPERTY(BlueprintAssignable, Category = "Zed|Cubemap")
	FSpatialMappingCubemapDelegate OnCubemapBuildComplete;

public:
	/** Camera render target */
	UPROPERTY(EditAnywhere, Category = "Zed|Cubemap")
	UTextureRenderTargetCube* TextureTarget;

	/** Camera used to capture the cubemap */
	UPROPERTY(BlueprintReadOnly)
	USceneCaptureComponentCube* Camera;

private:
	/** Cubemap being updated */
	UPROPERTY()
	UTextureCube* Cubemap;

	/** The thread doing the update */
	FSpatialMappingCubemapRunnable* CubemapWorker;

	/** True if the target texture can be updated */
	bool bCanUpdateTextureTarget;

	/** Proxy */
	FSpatialMappingCubemapProxy CubemapProxy;
};
