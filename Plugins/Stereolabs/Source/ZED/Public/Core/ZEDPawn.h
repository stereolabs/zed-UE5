//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Zed/Public/HUD/ZEDWidget.h"
#include "ZED/Public/Core/ZEDCamera.h"
#include "ZED/Public/Core/ZEDBaseTypes.h"

#include "CineCameraComponent.h"
#include "VCamComponent.h"

#include "ZEDPawn.generated.h"

/*
 * Base class for pawn using the Zed.
 * Inherit from this class and set the PawnClassType variable in the controller to spawn a pawn of your type.
 */
UCLASS(Category = "Stereolabs|Zed")
class ZED_API AZEDPawn : public APawn
{
	friend class AZEDPlayerController;

	GENERATED_BODY()

public:
	AZEDPawn();

private:
	/*
	 * Event binded to OnTrackingDataUpdated
	 * @param NewTrackingData The new tracking data
	 */
	UFUNCTION()
	void ZedCameraTrackingUpdated(const FZEDTrackingData& NewTrackingData);

	UFUNCTION()
	virtual void Tick(float DeltaSeconds) override;

	/*
	* Initialisation
	*/
	void InitRemap(FName HMDname, sl::RESOLUTION camRes, float dp);

public:
	/** Custom spring arm that offset the camera */
	UPROPERTY()
	USceneComponent* SpringArm;

	/** Main camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCineCameraComponent* Camera;

	/** Virtual camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UVCamComponent* VirtualCamera;

	/** Should update virtual camera transform according to real camera tracking*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool VirtualCamFollowsRealCam;

	/** Should enable lerp with specified alpha*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableLerp;

	/** Lerp Speed value*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LerpIntensity;

	FTransform LerpTransform;

	/** Real camera position and rotation, to manipulate the camera with multiipliers or lerp or anything else.*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransform RealCameraTransform;

	/** Zed loading widget */
	UPROPERTY()
	UZEDWidget* ZedLoadingWidget;

	/** Zed error widget */
	UPROPERTY()
	UZEDWidget* ZedErrorWidget;

	/** Remap material resource */
	UPROPERTY()
	UMaterial* RemapSourceMaterial;

	/** Remap material*/
	UPROPERTY(BlueprintReadWrite, Category = "Zed|Rendering")
	UMaterialInstanceDynamic* RemapMaterialInstanceDynamic;

	/** Remap Mx */
	UPROPERTY()
	UTexture2D* RemapMx;

	/** Remap My */
	UPROPERTY()
	UTexture2D* RemapMy;

private:
	/** Zed loading source widget */
	UPROPERTY()
	UClass* ZedLoadingSourceWidget;

	/** Zed error source widget */
	UPROPERTY()
	UClass* ZedErrorSourceWidget;

	/** Zed widget material */
	UPROPERTY()
	UMaterial* ZedWidgetSourceMaterial;
};
