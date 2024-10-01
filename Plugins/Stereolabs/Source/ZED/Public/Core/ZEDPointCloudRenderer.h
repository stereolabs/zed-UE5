#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "NiagaraComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraDataInterfaceTexture.h"
#include "Engine/Texture2D.h"

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"

#include <chrono>

#include "ZEDPointCloudRenderer.generated.h"

UCLASS(Category = "Stereolabs|Zed")
class ZED_API AZEDPointCloudRenderer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZEDPointCloudRenderer();
	~AZEDPointCloudRenderer();

	// The niagara system which should be used for rendering:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	UNiagaraSystem* PointCloudRenderer;

	// Transform applied to the point cloud data before rendering. Can be used to adjust the point cloud position and orientation in space.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	FTransform PointCloudOffset;

private:
	// The instance of the niagara system:
	UNiagaraComponent* RendererInstance;

	// Textures to transfer the data to the niagara system:
	UTexture2D* VerticeTexture;
	UTexture2D* ColorTexture;

	uint32_t PointCount;

	/** The grab delegate handle */
	FDelegateHandle GrabDelegateHandle;

	float* Vertices;
	unsigned char* Colors;
	unsigned char* SignedColors;
	// Runtime of the game:
	float Runtime = -1;

	// Definition of the region which should be updated:
	FUpdateTextureRegion2D Region;

	//Point Cloud resolution
	FIntPoint Resolution;

	float Fps;
	std::chrono::milliseconds PreviousTS;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private :
	UFUNCTION(BlueprintCallable, Category = "Zed|PointCloud")
	void Init();

	UFUNCTION(BlueprintCallable, Category = "Zed|PointCloud")
	void UpdateTextures(ESlErrorCode ErrorCode, FSlTimestamp Timestamp);
};
