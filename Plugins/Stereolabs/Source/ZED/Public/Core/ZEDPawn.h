//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Zed/Public/HUD/ZEDWidget.h"
#include "ZED/Public/Core/ZEDCamera.h"
#include "ZED/Public/Core/ZEDBaseTypes.h"

#include "CineCameraComponent.h"

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

	UFUNCTION()
	virtual void Tick(float DeltaSeconds) override;

public:
	/** Custom spring arm that offset the camera */
	UPROPERTY()
	USceneComponent* SpringArm;

	/** Main camera */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCineCameraComponent* Camera;

	/** Should enable lerp with specified alpha*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool EnableLerp;

	/** Lerp Speed value*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LerpIntensity;

	/** Transform used during Lerp smoothing*/
	FTransform LerpTransform;

	/** Boolean used as toggle to enable/disable freezing the virtual camera to reposition the real camera*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool ToggleFreeze;

	/** Save the rotation of the camera when freezing, and apply offset to the camera after unfreezing.*/
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool UseRotationOffset;

	/** Has the camera been frozen by the toggle freeze*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsFrozen;

	FVector StartOffsetLocation;

	// If there is a translation modifier different than (1,1,1), it will also apply on the translation
	// given by the boolean "bSetFloorAsOrigin" of the tracking parameters, which will move the ZEDPawn
	// accordingly to the height of the real camera.
	// This bool is to ignore the translation modifier on the first offset.
	bool SetFloorAsOriginCorrected;
	
	/** The previous location given by the slcamera (not the last frame)*/
	FVector PreviousLocation;
	
	/** From Previous to current location given by the slcamera*/
	FVector PreviousToCurrentLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TranslationMultiplier;

	/** The new virtual target location for lerp and direct movement*/
	FVector VirtualLocation;
	FVector PrevVirtualLocation;


	/** Zed loading widget */
	UPROPERTY()
	UZEDWidget* ZedLoadingWidget;

	/** Zed error widget */
	UPROPERTY()
	UZEDWidget* ZedErrorWidget;

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

	/** Transform offset used to reposition the camera, taking into account movement multipliers or offsetters*/
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform TransformOffset;

	/** Real camera position and rotation, to manipulate the camera with multiipliers or lerp or anything else.*/
	// UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FTransform RealCameraTransform;
};
