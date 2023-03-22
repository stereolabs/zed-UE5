//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Engine.h"
#include "kismet/BlueprintFunctionLibrary.h"

#include "ZED/Public/Core/ZEDCamera.h"
#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

#include "ProceduralMeshComponent.h"
#include "ProceduralMeshConversion.h"
#include "StaticMeshDescription.h"

#include "ZEDFunctionLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(ZEDFunctionLibrary, Log, All);

static TArray<FSlBody18Bone> Body18Bones = TArray<FSlBody18Bone>{
	FSlBody18Bone(ESlBody18Parts::NOSE, ESlBody18Parts::NECK),
	FSlBody18Bone(ESlBody18Parts::NECK, ESlBody18Parts::RIGHT_SHOULDER),
	FSlBody18Bone(ESlBody18Parts::RIGHT_SHOULDER, ESlBody18Parts::RIGHT_ELBOW),
	FSlBody18Bone(ESlBody18Parts::RIGHT_ELBOW, ESlBody18Parts::RIGHT_WRIST),
	FSlBody18Bone(ESlBody18Parts::NECK, ESlBody18Parts::LEFT_SHOULDER),
	FSlBody18Bone(ESlBody18Parts::LEFT_SHOULDER, ESlBody18Parts::LEFT_ELBOW),
	FSlBody18Bone(ESlBody18Parts::LEFT_ELBOW, ESlBody18Parts::LEFT_WRIST),
	FSlBody18Bone(ESlBody18Parts::RIGHT_SHOULDER, ESlBody18Parts::RIGHT_HIP),
	FSlBody18Bone(ESlBody18Parts::RIGHT_HIP, ESlBody18Parts::RIGHT_KNEE),
	FSlBody18Bone(ESlBody18Parts::RIGHT_KNEE, ESlBody18Parts::RIGHT_ANKLE),
	FSlBody18Bone(ESlBody18Parts::LEFT_SHOULDER, ESlBody18Parts::LEFT_HIP),
	FSlBody18Bone(ESlBody18Parts::LEFT_HIP, ESlBody18Parts::LEFT_KNEE),
	FSlBody18Bone(ESlBody18Parts::LEFT_KNEE, ESlBody18Parts::LEFT_ANKLE),
	FSlBody18Bone(ESlBody18Parts::RIGHT_SHOULDER, ESlBody18Parts::LEFT_SHOULDER),
	FSlBody18Bone(ESlBody18Parts::RIGHT_HIP, ESlBody18Parts::LEFT_HIP),
	FSlBody18Bone(ESlBody18Parts::NOSE, ESlBody18Parts::RIGHT_EYE),
	FSlBody18Bone(ESlBody18Parts::RIGHT_EYE, ESlBody18Parts::RIGHT_EAR),
	FSlBody18Bone(ESlBody18Parts::NOSE, ESlBody18Parts::LEFT_EYE),
	FSlBody18Bone(ESlBody18Parts::LEFT_EYE, ESlBody18Parts::LEFT_EAR),
};

static TArray<FSlBody34Bone> Body34Bones = TArray<FSlBody34Bone>{
	FSlBody34Bone(ESlBody34Parts::PELVIS, ESlBody34Parts::NAVAL_SPINE),
	FSlBody34Bone(ESlBody34Parts::NAVAL_SPINE, ESlBody34Parts::CHEST_SPINE),
	FSlBody34Bone(ESlBody34Parts::CHEST_SPINE, ESlBody34Parts::LEFT_CLAVICLE),
	FSlBody34Bone(ESlBody34Parts::LEFT_CLAVICLE, ESlBody34Parts::LEFT_SHOULDER),
	FSlBody34Bone(ESlBody34Parts::LEFT_SHOULDER, ESlBody34Parts::LEFT_ELBOW),
	FSlBody34Bone(ESlBody34Parts::LEFT_ELBOW, ESlBody34Parts::LEFT_WRIST),
	FSlBody34Bone(ESlBody34Parts::LEFT_WRIST, ESlBody34Parts::LEFT_HAND),
	FSlBody34Bone(ESlBody34Parts::LEFT_HAND, ESlBody34Parts::LEFT_HANDTIP),
	FSlBody34Bone(ESlBody34Parts::LEFT_WRIST, ESlBody34Parts::LEFT_THUMB),
	FSlBody34Bone(ESlBody34Parts::CHEST_SPINE, ESlBody34Parts::RIGHT_CLAVICLE),
	FSlBody34Bone(ESlBody34Parts::RIGHT_CLAVICLE, ESlBody34Parts::RIGHT_SHOULDER),
	FSlBody34Bone(ESlBody34Parts::RIGHT_SHOULDER, ESlBody34Parts::RIGHT_ELBOW),
	FSlBody34Bone(ESlBody34Parts::RIGHT_ELBOW, ESlBody34Parts::RIGHT_WRIST),
	FSlBody34Bone(ESlBody34Parts::RIGHT_WRIST, ESlBody34Parts::RIGHT_HAND),
	FSlBody34Bone(ESlBody34Parts::RIGHT_HAND, ESlBody34Parts::RIGHT_HANDTIP),
	FSlBody34Bone(ESlBody34Parts::RIGHT_WRIST, ESlBody34Parts::RIGHT_THUMB),
	FSlBody34Bone(ESlBody34Parts::PELVIS, ESlBody34Parts::LEFT_HIP),
	FSlBody34Bone(ESlBody34Parts::LEFT_HIP, ESlBody34Parts::LEFT_KNEE),
	FSlBody34Bone(ESlBody34Parts::LEFT_KNEE, ESlBody34Parts::LEFT_ANKLE),
	FSlBody34Bone(ESlBody34Parts::LEFT_ANKLE, ESlBody34Parts::LEFT_FOOT),
	FSlBody34Bone(ESlBody34Parts::PELVIS, ESlBody34Parts::RIGHT_HIP),
	FSlBody34Bone(ESlBody34Parts::RIGHT_HIP, ESlBody34Parts::RIGHT_KNEE),
	FSlBody34Bone(ESlBody34Parts::RIGHT_KNEE, ESlBody34Parts::RIGHT_ANKLE),
	FSlBody34Bone(ESlBody34Parts::RIGHT_ANKLE, ESlBody34Parts::RIGHT_FOOT),
	FSlBody34Bone(ESlBody34Parts::CHEST_SPINE, ESlBody34Parts::NECK),
	FSlBody34Bone(ESlBody34Parts::NECK, ESlBody34Parts::HEAD),
	FSlBody34Bone(ESlBody34Parts::HEAD, ESlBody34Parts::NOSE),
	FSlBody34Bone(ESlBody34Parts::NOSE, ESlBody34Parts::LEFT_EYE),
	FSlBody34Bone(ESlBody34Parts::LEFT_EYE, ESlBody34Parts::LEFT_EAR),
	FSlBody34Bone(ESlBody34Parts::NOSE, ESlBody34Parts::RIGHT_EYE),
	FSlBody34Bone(ESlBody34Parts::RIGHT_EYE, ESlBody34Parts::RIGHT_EAR),
	FSlBody34Bone(ESlBody34Parts::LEFT_ANKLE, ESlBody34Parts::LEFT_HEEL),
	FSlBody34Bone(ESlBody34Parts::RIGHT_ANKLE, ESlBody34Parts::RIGHT_HEEL),
	FSlBody34Bone(ESlBody34Parts::LEFT_HEEL, ESlBody34Parts::LEFT_FOOT),
	FSlBody34Bone(ESlBody34Parts::RIGHT_HEEL, ESlBody34Parts::RIGHT_FOOT)
};

static TArray<FSlBody38Bone> Body38Bones = TArray<FSlBody38Bone>{
	FSlBody38Bone(ESlBody38Parts::PELVIS,         ESlBody38Parts::SPINE_1),
	FSlBody38Bone(ESlBody38Parts::SPINE_1,        ESlBody38Parts::SPINE_2),
	FSlBody38Bone(ESlBody38Parts::SPINE_2,        ESlBody38Parts::SPINE_3),
	FSlBody38Bone(ESlBody38Parts::SPINE_3,        ESlBody38Parts::NECK),
	// neck
	FSlBody38Bone(ESlBody38Parts::NECK,           ESlBody38Parts::NOSE),
	FSlBody38Bone(ESlBody38Parts::NOSE,           ESlBody38Parts::LEFT_EYE),
	FSlBody38Bone(ESlBody38Parts::LEFT_EYE,       ESlBody38Parts::LEFT_EAR),
	FSlBody38Bone(ESlBody38Parts::NOSE,           ESlBody38Parts::RIGHT_EYE),
	FSlBody38Bone(ESlBody38Parts::RIGHT_EYE,      ESlBody38Parts::RIGHT_EAR),
	// Left arm
	FSlBody38Bone(ESlBody38Parts::SPINE_3,        ESlBody38Parts::LEFT_CLAVICLE),
	FSlBody38Bone(ESlBody38Parts::LEFT_CLAVICLE,  ESlBody38Parts::LEFT_SHOULDER),
	FSlBody38Bone(ESlBody38Parts::LEFT_SHOULDER,  ESlBody38Parts::LEFT_ELBOW),
	FSlBody38Bone(ESlBody38Parts::LEFT_ELBOW,     ESlBody38Parts::LEFT_WRIST),
	FSlBody38Bone(ESlBody38Parts::LEFT_WRIST,     ESlBody38Parts::LEFT_HAND_THUMB_4),
	FSlBody38Bone(ESlBody38Parts::LEFT_WRIST,     ESlBody38Parts::LEFT_HAND_INDEX_1),
	FSlBody38Bone(ESlBody38Parts::LEFT_WRIST,     ESlBody38Parts::LEFT_HAND_MIDDLE_4),
	FSlBody38Bone(ESlBody38Parts::LEFT_WRIST,     ESlBody38Parts::LEFT_HAND_PINKY_1),
	// Right Arm
	FSlBody38Bone(ESlBody38Parts::SPINE_3,        ESlBody38Parts::LEFT_CLAVICLE),
	FSlBody38Bone(ESlBody38Parts::RIGHT_CLAVICLE, ESlBody38Parts::RIGHT_SHOULDER),
	FSlBody38Bone(ESlBody38Parts::RIGHT_SHOULDER, ESlBody38Parts::RIGHT_ELBOW),
	FSlBody38Bone(ESlBody38Parts::RIGHT_ELBOW,    ESlBody38Parts::RIGHT_WRIST),
	FSlBody38Bone(ESlBody38Parts::RIGHT_WRIST,    ESlBody38Parts::RIGHT_HAND_THUMB_4),
	FSlBody38Bone(ESlBody38Parts::RIGHT_WRIST,    ESlBody38Parts::RIGHT_HAND_INDEX_1),
	FSlBody38Bone(ESlBody38Parts::RIGHT_WRIST,    ESlBody38Parts::RIGHT_HAND_MIDDLE_4),
	FSlBody38Bone(ESlBody38Parts::RIGHT_WRIST,    ESlBody38Parts::RIGHT_HAND_PINKY_1),
	// Left Leg
	FSlBody38Bone(ESlBody38Parts::PELVIS,         ESlBody38Parts::LEFT_HIP),
	FSlBody38Bone(ESlBody38Parts::LEFT_HIP,       ESlBody38Parts::LEFT_KNEE),
	FSlBody38Bone(ESlBody38Parts::LEFT_KNEE,      ESlBody38Parts::LEFT_ANKLE),
	FSlBody38Bone(ESlBody38Parts::LEFT_ANKLE,     ESlBody38Parts::LEFT_HEEL),
	FSlBody38Bone(ESlBody38Parts::LEFT_ANKLE,     ESlBody38Parts::LEFT_BIG_TOE),
	FSlBody38Bone(ESlBody38Parts::LEFT_ANKLE,     ESlBody38Parts::LEFT_SMALL_TOE),
	//Right Leg 
	FSlBody38Bone(ESlBody38Parts::PELVIS,         ESlBody38Parts::RIGHT_HIP),
	FSlBody38Bone(ESlBody38Parts::RIGHT_HIP,      ESlBody38Parts::RIGHT_KNEE),
	FSlBody38Bone(ESlBody38Parts::RIGHT_KNEE,     ESlBody38Parts::RIGHT_ANKLE),
	FSlBody38Bone(ESlBody38Parts::RIGHT_ANKLE,    ESlBody38Parts::RIGHT_HEEL),
	FSlBody38Bone(ESlBody38Parts::RIGHT_ANKLE,    ESlBody38Parts::RIGHT_BIG_TOE),
	FSlBody38Bone(ESlBody38Parts::RIGHT_ANKLE,    ESlBody38Parts::RIGHT_SMALL_TOE)
};

static TArray<FSlBody70Bone> Body70Bones = TArray<FSlBody70Bone>{
	FSlBody70Bone(ESlBody70Parts::PELVIS,         ESlBody70Parts::SPINE_1),
	FSlBody70Bone(ESlBody70Parts::SPINE_1,        ESlBody70Parts::SPINE_2),
	FSlBody70Bone(ESlBody70Parts::SPINE_2,        ESlBody70Parts::SPINE_3),
	FSlBody70Bone(ESlBody70Parts::SPINE_3,        ESlBody70Parts::NECK),
	// neck
	FSlBody70Bone(ESlBody70Parts::NECK,           ESlBody70Parts::NOSE),
	FSlBody70Bone(ESlBody70Parts::NOSE,           ESlBody70Parts::LEFT_EYE),
	FSlBody70Bone(ESlBody70Parts::LEFT_EYE,       ESlBody70Parts::LEFT_EAR),
	FSlBody70Bone(ESlBody70Parts::NOSE,           ESlBody70Parts::RIGHT_EYE),
	FSlBody70Bone(ESlBody70Parts::RIGHT_EYE,      ESlBody70Parts::RIGHT_EAR),
	// Left arm
	FSlBody70Bone(ESlBody70Parts::SPINE_3,        ESlBody70Parts::LEFT_CLAVICLE),
	FSlBody70Bone(ESlBody70Parts::LEFT_CLAVICLE,  ESlBody70Parts::LEFT_SHOULDER),
	FSlBody70Bone(ESlBody70Parts::LEFT_SHOULDER,  ESlBody70Parts::LEFT_ELBOW),
	FSlBody70Bone(ESlBody70Parts::LEFT_ELBOW,     ESlBody70Parts::LEFT_WRIST),
	// Left hand
	FSlBody70Bone(ESlBody70Parts::LEFT_WRIST,            ESlBody70Parts::LEFT_HAND_THUMB_1),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_THUMB_1,     ESlBody70Parts::LEFT_HAND_THUMB_2),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_THUMB_2,     ESlBody70Parts::LEFT_HAND_THUMB_3),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_THUMB_3,     ESlBody70Parts::LEFT_HAND_THUMB_4),
	FSlBody70Bone(ESlBody70Parts::LEFT_WRIST,            ESlBody70Parts::LEFT_HAND_INDEX_1),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_INDEX_1,     ESlBody70Parts::LEFT_HAND_INDEX_2),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_INDEX_2,     ESlBody70Parts::LEFT_HAND_INDEX_3),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_INDEX_3,     ESlBody70Parts::LEFT_HAND_INDEX_4),
	FSlBody70Bone(ESlBody70Parts::LEFT_WRIST,            ESlBody70Parts::LEFT_HAND_MIDDLE_1),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_MIDDLE_1,    ESlBody70Parts::LEFT_HAND_MIDDLE_2),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_MIDDLE_2,    ESlBody70Parts::LEFT_HAND_MIDDLE_3),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_MIDDLE_3,    ESlBody70Parts::LEFT_HAND_MIDDLE_4),
	FSlBody70Bone(ESlBody70Parts::LEFT_WRIST,            ESlBody70Parts::LEFT_HAND_PINKY_1),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_PINKY_1,     ESlBody70Parts::LEFT_HAND_PINKY_2),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_PINKY_2,     ESlBody70Parts::LEFT_HAND_PINKY_3),
	FSlBody70Bone(ESlBody70Parts::LEFT_HAND_PINKY_3,     ESlBody70Parts::LEFT_HAND_PINKY_4),

	// Right Arm
	FSlBody70Bone(ESlBody70Parts::SPINE_3,        ESlBody70Parts::RIGHT_CLAVICLE),
	FSlBody70Bone(ESlBody70Parts::RIGHT_CLAVICLE, ESlBody70Parts::RIGHT_SHOULDER),
	FSlBody70Bone(ESlBody70Parts::RIGHT_SHOULDER, ESlBody70Parts::RIGHT_ELBOW),
	FSlBody70Bone(ESlBody70Parts::RIGHT_ELBOW,    ESlBody70Parts::RIGHT_WRIST),
	// Right hand
	FSlBody70Bone(ESlBody70Parts::RIGHT_WRIST,            ESlBody70Parts::RIGHT_HAND_THUMB_1),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_THUMB_1,     ESlBody70Parts::RIGHT_HAND_THUMB_2),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_THUMB_2,     ESlBody70Parts::RIGHT_HAND_THUMB_3),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_THUMB_3,     ESlBody70Parts::RIGHT_HAND_THUMB_4),
	FSlBody70Bone(ESlBody70Parts::RIGHT_WRIST,            ESlBody70Parts::RIGHT_HAND_INDEX_1),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_INDEX_1,     ESlBody70Parts::RIGHT_HAND_INDEX_2),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_INDEX_2,     ESlBody70Parts::RIGHT_HAND_INDEX_3),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_INDEX_3,     ESlBody70Parts::RIGHT_HAND_INDEX_4),
	FSlBody70Bone(ESlBody70Parts::RIGHT_WRIST,            ESlBody70Parts::RIGHT_HAND_MIDDLE_1),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_MIDDLE_1,    ESlBody70Parts::RIGHT_HAND_MIDDLE_2),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_MIDDLE_2,    ESlBody70Parts::RIGHT_HAND_MIDDLE_3),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_MIDDLE_3,    ESlBody70Parts::RIGHT_HAND_MIDDLE_4),
	FSlBody70Bone(ESlBody70Parts::RIGHT_WRIST,            ESlBody70Parts::RIGHT_HAND_PINKY_1),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_PINKY_1,     ESlBody70Parts::RIGHT_HAND_PINKY_2),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_PINKY_2,     ESlBody70Parts::RIGHT_HAND_PINKY_3),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HAND_PINKY_3,     ESlBody70Parts::RIGHT_HAND_PINKY_4),
	// Left Leg
	FSlBody70Bone(ESlBody70Parts::PELVIS,         ESlBody70Parts::LEFT_HIP),
	FSlBody70Bone(ESlBody70Parts::SPINE_3,        ESlBody70Parts::LEFT_CLAVICLE),
	FSlBody70Bone(ESlBody70Parts::LEFT_HIP,       ESlBody70Parts::LEFT_KNEE),
	FSlBody70Bone(ESlBody70Parts::LEFT_KNEE,      ESlBody70Parts::LEFT_ANKLE),
	FSlBody70Bone(ESlBody70Parts::LEFT_ANKLE,     ESlBody70Parts::LEFT_HEEL),
	FSlBody70Bone(ESlBody70Parts::LEFT_ANKLE,     ESlBody70Parts::LEFT_BIG_TOE),
	FSlBody70Bone(ESlBody70Parts::LEFT_ANKLE,     ESlBody70Parts::LEFT_SMALL_TOE),
	//Right Leg 
	FSlBody70Bone(ESlBody70Parts::PELVIS,         ESlBody70Parts::RIGHT_HIP),
	FSlBody70Bone(ESlBody70Parts::RIGHT_HIP,      ESlBody70Parts::RIGHT_KNEE),
	FSlBody70Bone(ESlBody70Parts::RIGHT_KNEE,     ESlBody70Parts::RIGHT_ANKLE),
	FSlBody70Bone(ESlBody70Parts::RIGHT_ANKLE,    ESlBody70Parts::RIGHT_HEEL),
	FSlBody70Bone(ESlBody70Parts::RIGHT_ANKLE,    ESlBody70Parts::RIGHT_BIG_TOE),
	FSlBody70Bone(ESlBody70Parts::RIGHT_ANKLE,    ESlBody70Parts::RIGHT_SMALL_TOE)
};

UCLASS()
class ZED_API UZEDFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	 * Get the current frame tracking data
	 * @param TrackingData The current Zed tracking data
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetTrackingData", Keywords = "get zed camera tracking data"), Category = "Stereolabs|Zed")
	static FZEDTrackingData GetTrackingData()
	{
		return GZedTrackingData;
	}

	/*
	 * Get the current frame Zed rotation and location
	 * @param Orientation The camera rotation
	 * @param Location    The camera location
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetRawOrientationAndLocation", Keywords = "get zed camera orientation and location"), Category = "Stereolabs|Zed")
	static void GetRawOrientationAndLocation(FRotator& Orientation, FVector& Location)
	{
		Orientation = GZedRawRotation;
		Location = GZedRawLocation;
	}

	/*
	 * Get the current frame view point rotation and location, head(stereo)/camera(mono)
	 * @param Orientation The camera rotation
	 * @param Location    The camera location
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetViewPointOrientationAndLocation", Keywords = "get zed camera orientation and location"), Category = "Stereolabs|Zed")
	static void GetViewPointOrientationAndLocation(FRotator& Orientation, FVector& Location)
	{
		Orientation = GZedViewPointRotation;
		Location = GZedViewPointLocation;
	}

	/*
	* Get the current frame Zed rotation and location
	* @param Orientation The camera rotation
	* @param Location    The camera location
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetRawOrientationAndLocation", Keywords = "set zed camera orientation and location"), Category = "Stereolabs|Zed")
		static void SetRawOrientationAndLocation(const FRotator& Orientation, const FVector& Location)
	{
		GZedRawRotation = Orientation;
		GZedRawLocation = Location;
	}

	/*
	* Get the current frame view point rotation and location, head(stereo)/camera(mono)
	* @param Orientation The camera rotation
	* @param Location    The camera location
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetViewPointOrientationAndLocation", Keywords = "set zed camera orientation and location"), Category = "Stereolabs|Zed")
		static void SetViewPointOrientationAndLocation(const FRotator& Orientation, const FVector& Location)
	{
		GZedViewPointRotation = Orientation;
		GZedViewPointLocation = Location;
	}

	/*
	 * Get Zed player controller. Can be null
	 * @return The Zed player controller
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "GetPlayerController", Keywords = "get zed player controller"), Category = "Stereolabs|Zed")
	static AZEDPlayerController* GetPlayerController(UObject* WorldContextObject);

	/*
	 * Retrieve the Zed camera actor. Can be null.
	 * @return The Zed camera actor
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "GetCameraActor", Keywords = "get zed camera actor"), Category = "Stereolabs|Zed")
	static AZEDCamera* GetCameraActor(UObject* WorldContextObject);

	/*
	 * Calculate the location of an actor centered in front of the player at desired distance using optical center offsets
	 * @param Distance The distance from the player
	 * @return		   The world location
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetCenteredLocationInFrontOfPlayer", Keywords = "get zed centered location front player"), Category = "Stereolabs|Zed")
	static FVector GetCenteredLocationInFrontOfPlayer(float Distance);

	/*
	 * Calculate the location of an actor in front of the player at desired distance using optical center offsets
	 * @param OriginLocation The location origin to place the object
	 * @param OriginRotation The rotation origin to calculate forward, right and up vectors
	 * @return			     The world location
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetCustomLocationInFrontOfPlayer", Keywords = "get zed custom location front player"), Category = "Stereolabs|Zed")
	static FVector GetCustomLocationInFrontOfPlayer(const FVector& OriginLocation, const FRotator& OriginRotation, float Distance);

public:
	/*
	 * Test if a 3D location is in screen bounds
	 * @param PlayerController The player controller
	 * @param WorldLocation    The 3D location
	 * @return                 True if the location is in screen bounds, false otherwise
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsLocationInScreenBounds", Keywords = "is location on zed screen"), Category = "Stereolabs|Zed")
	static bool IsLocationInScreenBounds(AZEDPlayerController* PlayerController, const FVector& WorldLocation);

	/*
	 * Test if a 3D location is visible
	 * @param PlayerController The Eed player controller
	 * @param WorldLocation    The 3D location
	 * @return                 True if the location is visible, false otherwise
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsLocationVisible", Keywords = "is location visible by zed"), Category = "Stereolabs|Zed")
	static bool IsLocationVisible(AZEDPlayerController* PlayerController, const FVector& WorldLocation);

	/*
	 * Test if a 3D location and associated 2D screen position is visible
	 * @param PlayerController The Zed player controller
	 * @param WorldLocation    The 3D location
	 * @param ScreenPosition   The 2D screen position
	 * @return                 True if the location is visible, false otherwise
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsVisible", Keywords = "is visible zed"), Category = "Stereolabs|Zed")
	static bool IsVisible(AZEDPlayerController* PlayerController, const FVector& WorldLocation, const FVector2D& ScreenPosition);

public:
	/*
	 * Retrieve the depth at screen position
	 * @param PlayerController The Zed player controller
	 * @param ScreenPosition   The screen position
	 * @param Depth			   The out depth at the screen position
	 * @param Distance		   The distance from the camera
	 * @param WorldDirection   The out direction vector from the camera
	 * @return				   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthAtScreenPosition", Keywords = "get zed depth screen"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetDepthAtScreenPosition(AZEDPlayerController* PlayerController, const FVector2D& ScreenPosition, float& Depth, float& Distance, FVector& WorldDirection);

	/*
	 * Retrieve the depth at world location
	 * @param PlayerController The Zed player controller
	 * @param Location		   The world location
	 * @param Depth			   The out depth at the screen position
	 * @param Distance		   The out distance from the camera
	 * @return				   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthAtWorldLocation", Keywords = "get zed depth world"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetDepthAtWorldLocation(AZEDPlayerController* PlayerController, const FVector& Location, float& Depth, float& Distance);

	/*
	 * Retrieve the normal at screen position
	 * @param PlayerController The Zed player controller
	 * @param ScreenPosition   The screen position
	 * @param Normal		   The out normal
	 * @return                 The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetNormalAtScreenPosition", Keywords = "get zed normal screen"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetNormalAtScreenPosition(AZEDPlayerController* PlayerController, const FVector2D& ScreenPosition, FVector& Normal);

	/*
	 * Retrieve the normal at world location
	 * @param PlayerController The Zed player controller
	 * @param Location		   The world location
	 * @param Normal		   The out normal
	 * @return                 The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetNormalAtWorldLocation", Keywords = "get zed normal world"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetNormalAtWorldLocation(AZEDPlayerController* PlayerController, const FVector& Location, FVector& Normal);

	/*
	 * Retrieve the depth and normal at screen position
	 * @param PlayerController The Zed player controller
	 * @param ScreenPosition   The screen position
	 * @param Depth			   The out depth at the screen position
	 * @param Distance		   The out distance from the camera
	 * @param Normal		   The out normal
	 * @param WorldDirection   The direction vector from the camera
	 * @return				   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthAndNormalAtScreenPosition", Keywords = "get zed depth normal screen"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetDepthAndNormalAtScreenPosition(AZEDPlayerController* PlayerController, const FVector2D& ScreenPosition, float& Depth, float& Distance, FVector& Normal, FVector& WorldDirection);

	/*
	 * Retrieve the depth and normal at world location
	 * @param PlayerController The Zed player controller
	 * @param Location		   The world location
	 * @param Depth			   The out depth
	 * @param Distance		   The out distance from the camera
	 * @param Normal		   The out normal
	 * @return				   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthAndNormalAtWorldLocation", Keywords = "get zed depth normal world"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetDepthAndNormalAtWorldLocation(AZEDPlayerController* PlayerController, const FVector& Location, float& Depth, float& Distance, FVector& Normal);

public:
	/*
	 * Retrieve the depths at screen positions
	 * @param PlayerController The Zed player controller
	 * @param ScreenPositions  The screen positions
	 * @param Depths		   The out depths at the screen position
	 * @param Distances		   The out distances from the camera
	 * @param WorldDirections  The direction vectors from the camera
	 * @return				   The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthsAtScreenPositions", Keywords = "get zed depths screen"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetDepthsAtScreenPositions(AZEDPlayerController* PlayerController, const TArray<FVector2D>& ScreenPositions, TArray<float>& Depths, TArray<float>& Distances, TArray<FVector>& WorldDirections);

	/*
	 * Retrieve the depths at world locations
	 * @param PlayerController The Zed player controller
	 * @param Locations		   The world locations
	 * @param Depths		   The out depths
	 * @param Distances		   The out distances from the camera
	 * @return				   The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthsAtWorldLocations", Keywords = "get zed depths world"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetDepthsAtWorldLocations(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, TArray<float>& Depths, TArray<float>& Distances);

	/*
	 * Retrieve the normals at screen positions
	 * @param PlayerController The Zed player controller
	 * @param ScreenPositions  The screen positions
	 * @param Normals		   The out normals at the screen position
	 * @return				   The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetNormalsAtScreenPositions", Keywords = "get zed normals screen"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetNormalsAtScreenPositions(AZEDPlayerController* PlayerController, const TArray<FVector2D>& ScreenPositions, TArray<FVector>& Normals);

	/*
	 * Retrieve the normals at world locations
	 * @param PlayerController The Zed player controller
	 * @param Locations		   The world locations
	 * @param Normals		   The out depths
	 * @return				   The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetNormalsAtWorldLocations", Keywords = "get zed normals world"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetNormalsAtWorldLocations(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, TArray<FVector>& Normals);

	/*
	 * Retrieve the depths and normals at screen positions
	 * @param PlayerController The Zed player controller
	 * @param ScreenPositions  The screen positions
	 * @param Depths		   The out depths
	 * @param Distances		   The out distances from the camera
	 * @param Normals		   The out Normals
	 * @param WorldDirections  The direction vectors from the camera
	 * @return				   The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthsAndNormalsAtScreenPositions", Keywords = "get zed depths normals screen"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetDepthsAndNormalsAtScreenPositions(AZEDPlayerController* PlayerController, const TArray<FVector2D>& ScreenPositions, TArray<float>& Depths, TArray<float>& Distances, TArray<FVector>& Normals, TArray<FVector>& WorldDirections);

	/*
	 * Retrieve the depths and normals at world locations
	 * @param PlayerController The Zed player controller
	 * @param Locations		   The world locations
	 * @param Depths		   The out depths
	 * @param Distances		   The out distances from the camera
	 * @param Normals		   The out Normals
	 * @return				   The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetDepthsAndNormalsAtWorldLocations", Keywords = "get zed depths normals world"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetDepthsAndNormalsAtWorldLocations(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, TArray<float>& Depths, TArray<float>& Distances, TArray<FVector>& Normals);

public:
	/*
	 * Retrieve the 3D location of a pixel
	 * @param PlayerController   The Zed player controller
	 * @param ScreenPosition     The screen position
	 * @param PixelWorldLocation The out world location
	 * @param Depth				 The out depth
	 * @param Distance			 The out distance from the camera
	 * @return                   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelLocationAtScreenPosition", Keywords = "get zed pixel location screen"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetPixelLocationAtScreenPosition(AZEDPlayerController* PlayerController, const FVector2D& ScreenPosition, FVector& PixelWorldLocation, float& Depth, float& Distance);
	
	/*
	 * Retrieve the 3D location of a pixel
	 * @param PlayerController   The Zed player controller
	 * @param Location           The world location
	 * @param PixelWorldLocation The out world location
	 * @param Depth				 The out depth
	 * @param Distance			 The out distance from the camera
	 * @return                   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelLocationAtWorldLocation", Keywords = "get zed pixel location world"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetPixelLocationAtWorldLocation(AZEDPlayerController* PlayerController, const FVector& Location, FVector& PixelWorldLocation, float& Depth, float& Distance);

	/*
	 * Retrieve the 3D location and normal of a pixel
	 * @param PlayerController   The Zed player controller
	 * @param ScreenPosition     The screen position
	 * @param PixelWorldLocation The out world location
	 * @param Depth				 The out depth
	 * @param Distance			 The out distance from the camera
	 * @param Normal			 The out normal
	 * @return                   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelLocationAndNormalAtScreenPosition", Keywords = "get zed pixel location normal screen"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetPixelLocationAndNormalAtScreenPosition(AZEDPlayerController* PlayerController, const FVector2D& ScreenPosition, FVector& PixelWorldLocation, float& Depth, float& Distance, FVector& Normal);

	/*
	 * Retrieve the 3D location and normal of a pixel
	 * @param PlayerController   The Zed player controller
	 * @param Location           The world location
	 * @param PixelWorldLocation The out world location
	 * @param Depth				 The out depth
	 * @param Distance			 The out distance from the camera
	 * @param Normal			 The out normal
	 * @return                   The retrieve result
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelLocationAndNormalAtWorldLocation", Keywords = "get zed pixel location normal world"), Category = "Stereolabs|Zed")
	static ESlRetrieveResult GetPixelLocationAndNormalAtWorldLocation(AZEDPlayerController* PlayerController, const FVector& Location, FVector& PixelWorldLocation, float& Depth, float& Distance, FVector& Normal);

	/*
	 * Retrieve the 3D location of pixels
	 * @param PlayerController     The Zed player controller
	 * @param ScreenPositions      The screen positions
	 * @param PixelsWorldLocations The out world locations
	 * @param Depths			   The out depths
	 * @param Distances			   The out distances from camera
	 * @return                     The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelsLocationAtScreenPositions", Keywords = "get zed pixels location screen"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetPixelsLocationAtScreenPositions(AZEDPlayerController* PlayerController, const TArray<FVector2D>& ScreenPositions, TArray<FVector>& PixelWorldLocations, TArray<float>& Depths, TArray<float>& Distances);
	
	/*
	 * Retrieve the 3D location of pixels
	 * @param PlayerController     The Zed player controller
	 * @param Locations            The out world locations
	 * @param PixelsWorldLocations The out world location
	 * @param Depths			   The out depths
	 * @param Distances			   The out distances from camera
	 * @return                     The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelsLocationAtWorldLocations", Keywords = "get zed pixels location world"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetPixelsLocationAtWorldLocations(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, TArray<FVector>& PixelsWorldLocations, TArray<float>& Depths, TArray<float>& Distances);

	/*
	 * Retrieve the 3D location and normal of pixels
	 * @param PlayerController    The Zed player controller
	 * @param ScreenPositions      The screen positions
	 * @param PixelsWorldLocations The out world locations
	 * @param Depths			   The out depths
	 * @param Distances			   The out distances
	 * @param Normals			   The out normals
	 * @return                     The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelsLocationAndNormalAtScreenPositions", Keywords = "get zed pixels location normal screen"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetPixelsLocationAndNormalAtScreenPositions(AZEDPlayerController* PlayerController, const TArray<FVector2D>& ScreenPositions, TArray<FVector>& PixelsWorldLocations, TArray<float>& Depths, TArray<float>& Distances, TArray<FVector>& Normals);

	/*
	 * Retrieve the 3D location and normal of pixels
	 * @param PlayerController    The Zed player controller
	 * @param Locations           The world locations
	 * @param PixelsWorldLocation The out world locations
	 * @param Depths			  The out depths
	 * @param Distances			  The out distances
	 * @param Normals			  The out normals
	 * @return                    The array of retrieve results
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetPixelsLocationAndNormalAtWorldLocations", Keywords = "get zed pixels location normal world"), Category = "Stereolabs|Zed")
	static TArray<ESlRetrieveResult> GetPixelsLocationAndNormalAtWorldLocations(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, TArray<FVector>& PixelsWorldLocations, TArray<float>& Depths, TArray<float>& Distances, TArray<FVector>& Normals);

public:
	/*
	 * Test if a 3D point hit the real
	 * @param PlayerController The Zed player controller
	 * @param Location	       The 3D point location
	 * @param HitThreshold     The threshold in cm to determine if a hit occurred
	 * @param HitResult        The result if hit
	 * @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold
	 * @return			       True if the 3D point has hit, false otherwise
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "HitTestReal", Keywords = "hit test zed real"), Category = "Stereolabs|Zed")
	static bool HitTestReal(AZEDPlayerController* PlayerController, const FVector& Location, float HitThreshold, bool bGetNormal, bool bHitIfBehind, FZEDHitResult& HitResult);
	
	/*
	 * Test if multiple 3D points hit the real
	 * @param PlayerController The Zed player controller
	 * @param Location	       The 3D point location
	 * @param HitThresholds    The thresholds in cm to determine if a hit occurred
	 * @param HitResults	   The result of all hits
	 * @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold
	 * @return			       True if at least one 3D point has hit, false otherwise
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "MultipleHitTestsReal", Keywords = "has hit zed depths"), Category = "Stereolabs|Zed")
	static bool MultipleHitTestsReal(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, const TArray<float>& HitThresholds, bool bGetNormal, bool bHitIfBehind, TArray<FZEDHitResult>& HitResults);

	/*
	 * Test if multiple 3D points hit the real, exit on first hit
	 * @param PlayerController The Zed player controller
	 * @param Location	       The 3D point location
	 * @param HitThreshold     The threshold in cm to determine if a hit occurred
	 * @param HitResult	       The result of the first hit
	 * @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold
	 * @return			       True if one 3D point has hit, false otherwise
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "MultipleHitTestsRealOneResult", Keywords = "has hit zed depths"), Category = "Stereolabs|Zed")
	static bool MultipleHitTestsRealOneResult(AZEDPlayerController* PlayerController, const TArray<FVector>& Locations, const TArray<float>& HitThresholds, bool bGetNormal, bool bHitIfBehind, FZEDHitResult& HitResult);

	/*
	 * Return the world location of a plane if it exists.
	 * Returns the position of the hit point, and a boolean set to true if its normal is horizontal enough.
	 * @param PlayerController The Zed player controller
	 * @param ScreenPosition   The screen position
	 * @param PlaneLocation	   The out plane world location
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetFloorPlaneAtScreenPosition", Keywords = "Find floor plane at screen position"), Category = "Stereolabs|Zed")
	static bool GetFloorPlaneAtScreenPosition(AZEDPlayerController* PlayerController, const FVector2D& ScreenPosition, FVector& PlaneLocation);

	/*
	 * Return the world location of a plane if it exist
	 * @param PlayerController The Zed player controller
	 * @param WorldLocation    The world location
	 * @param PlaneLocation	   The out plane world location
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetFloorPlaneAtWorldLocation", Keywords = "Find floor plane at world location"), Category = "Stereolabs|Zed")
	static bool GetFloorPlaneAtWorldLocation(AZEDPlayerController* PlayerController, const FVector& WorldLocation, FVector& PlaneLocation);

	/*
	 * Find floor plane at hit and convert it to mesh
	 * @param ScreenPosition   The position in the image 
	 * @param MeshData         The Mesh data
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "CreateMeshFromFloorHit", Keywords = "Find floor plane at hit and convert it to mesh"), Category = "Stereolabs|Zed")
	static bool CreateMeshFromFloorHit(AZEDPlayerController* PlayerController, const FIntPoint ScreenPosition, FSlMeshData& MeshData);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "CreateMeshFromFloorPlane", Keywords = "Find floor plane and convert it to mesh"), Category = "Stereolabs|Zed")
	static bool CreateMeshFromFloorPlane(FSlMeshData& MeshData);

	/*
	 * Deproject a screen position to a world location
	 * @param PlayerController The Zed player controller
	 * @param ScreenPosition   The screen position
	 * @param WorldPosition	   The world position
	 * @param WorldDirection   The direction from the camera to the world position
	 * @return True if deprojected
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ZEDDeprojectScreenToWorld"), Category = "Stereolabs|Zed")
	static bool DeprojectScreenToWorld(AZEDPlayerController const* Player, const FVector2D& ScreenPosition, FVector& WorldPosition, FVector& WorldDirection);

	/*
	 * Project world location to a screen position
	 * @param PlayerController		  The Zed player controller
	 * @param WorldPosition			  The world position
	 * @param ScreenPosition		  The screen position
	 * @return True if projected
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ZEDProjectWorldToScreen"), Category = "Stereolabs|Zed")
	static bool ProjectWorldToScreen(AZEDPlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition);

	/*
	* Add latency corrector offset
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "AddLatencyOffset"), Category = "Stereolabs|Latency")
	static void LatencyCorrectorAddOffset(const int offset);

	/*
	 * Get the index corresponding to the enum value
	* @param ESlBodyPartsVal The body part value
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetBody38Bones", Keywords = "GetBody38Bones"), Category = "Stereolabs|Zed")
	static const TArray<FSlBody38Bone> GetBody38Bones()
	{
		return Body38Bones;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetBody70Bones", Keywords = "GetBody70Bones"), Category = "Stereolabs|Zed")
	static const TArray<FSlBody70Bone> GetBody70Bones()
	{
		return Body70Bones;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetBody34Bones", Keywords = "GetBody34Bones"), Category = "Stereolabs|Zed")
		static const TArray<FSlBody34Bone> GetBody34Bones()
	{
		return Body34Bones;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetBody18Bones", Keywords = "GetBody18Bones"), Category = "Stereolabs|Zed")
		static const TArray<FSlBody18Bone> GetBody18Bones()
	{
		return Body18Bones;
	}


	// -------------------------------------------------------------
	// -------------------------------------------------------------
	//  Tests conversion procedural mesh to static mesh
	// -------------------------------------------------------------
	// -------------------------------------------------------------
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Convert Procedural Mesh to Static Mesh", Keywords = "Convert Proc Procedural Mesh 2 Stat Static Mesh ProcMesh2StatMesh"), Category = "Stereolabs|Zed")
	static UStaticMesh* ProcMesh2StatMesh(UProceduralMeshComponent* ProcMesh)
	{
		if (!ProcMesh)
			return nullptr;

		FMeshDescription MeshDescription = BuildMeshDescription(ProcMesh);

		// If we got some valid data.
		if (MeshDescription.Polygons().Num() > 0)
		{
			// Create StaticMesh object
			UStaticMesh* StaticMesh = NewObject<UStaticMesh>(ProcMesh/*Package, MeshName, RF_Public | RF_Standalone*/);
			StaticMesh->InitResources();

			StaticMesh->SetLightingGuid();

			// Add source to new StaticMesh
			auto Desc = StaticMesh->CreateStaticMeshDescription();
			Desc->SetMeshDescription(MeshDescription);
			// buildSimpleCol = false, cause it creates box collision based on mesh bounds or whatever :(
			StaticMesh->BuildFromStaticMeshDescriptions({ Desc }, false);
			//StaticMesh->BuildFromStaticMeshDescriptions({ Desc }, true);

			//// SIMPLE COLLISION
			if (!ProcMesh->bUseComplexAsSimpleCollision)
			{
				StaticMesh->CreateBodySetup();
				UBodySetup* NewBodySetup = StaticMesh->GetBodySetup();
				NewBodySetup->BodySetupGuid = FGuid::NewGuid();
				NewBodySetup->AggGeom.ConvexElems = ProcMesh->ProcMeshBodySetup->AggGeom.ConvexElems;

				UE_LOG(LogTemp, Warning, TEXT("[ZEDFunctionLibrary.h]ConvexElems : %d"), ProcMesh->ProcMeshBodySetup->AggGeom.ConvexElems.Num());

				NewBodySetup->bGenerateMirroredCollision = false;
				NewBodySetup->bDoubleSidedGeometry = true;
				// Play around with the flag below if you struggle with collision not working
				// NewBodySetup->CollisionTraceFlag = CTF_UseDefault;
				NewBodySetup->CollisionTraceFlag = CTF_UseSimpleAndComplex;
				NewBodySetup->CreatePhysicsMeshes();
			}

			/* Commented out cause I don't need it
			//// MATERIALS
			TSet<UMaterialInterface*> UniqueMaterials;
			const int32 NumSections = ProcMesh->GetNumSections();
			for (int32 SectionIdx = 0; SectionIdx < NumSections; SectionIdx++)
			{
				FProcMeshSection *ProcSection =
					ProcMesh->GetProcMeshSection(SectionIdx);
				UMaterialInterface *Material = ProcMesh->GetMaterial(SectionIdx);
				UniqueMaterials.Add(Material);
			}
			// Copy materials to new mesh
			for (auto* Material : UniqueMaterials)
			{
				StaticMesh->GetStaticMaterials().Add(FStaticMaterial(Material));
			}
			*/

			// Uncallable in game runtime
			// StaticMesh->Build(false);

			return StaticMesh;
		}

		return nullptr;
	}

	/*UFUNCTION(BlueprintPure, meta = (DisplayName = "[B34] Get Joint Name From Enum", Keywords = "Joint Name Body34 Body parts pose"), Category = "Stereolabs|Zed")
	static FString GetJointNameFromEnum(const ESlBodyPartsBody38& bodypart) {
		FString ret = "NotFound";
		switch (bodypart) {
		case ESlBodyPartsBody38::PELVIS:
			ret = "Pelvis";
			break;
		case ESlBodyPartsBody38::NAVAL_SPINE:
			ret = "NavalSpine";
			break;
		case ESlBodyPartsPose34::CHEST_SPINE:
			ret = "ChestSpine";
			break;
		case ESlBodyPartsPose34::NECK:
			ret = "Neck";
			break;
		case ESlBodyPartsPose34::LEFT_CLAVICLE:
			ret = "L_Clavicle";
			break;
		case ESlBodyPartsPose34::LEFT_SHOULDER:
			ret = "L_Shoulder";
			break;
		case ESlBodyPartsPose34::LEFT_ELBOW:
			ret = "L_Elbow";
			break;
		case ESlBodyPartsPose34::LEFT_WRIST:
			ret = "L_Wrist";
			break;
		case ESlBodyPartsPose34::LEFT_HAND:
			ret = "L_Hand";
			break;
		case ESlBodyPartsPose34::LEFT_HANDTIP:
			ret = "L_HandTip";
			break;
		case ESlBodyPartsPose34::LEFT_THUMB:
			ret = "L_Thumb";
			break;
		case ESlBodyPartsPose34::RIGHT_CLAVICLE:
			ret = "R_Clavicle";
			break;
		case ESlBodyPartsPose34::RIGHT_SHOULDER:
			ret = "R_Shoulder";
			break;
		case ESlBodyPartsPose34::RIGHT_ELBOW:
			ret = "R_Elbow";
			break;
		case ESlBodyPartsPose34::RIGHT_WRIST:
			ret = "R_Wrist";
			break;
		case ESlBodyPartsPose34::RIGHT_HAND:
			ret = "R_Hand";
			break;
		case ESlBodyPartsPose34::RIGHT_HANDTIP:
			ret = "R_HandTip";
			break;
		case ESlBodyPartsPose34::RIGHT_THUMB:
			ret = "R_Thumb";
			break;
		case ESlBodyPartsPose34::LEFT_HIP:
			ret = "L_Hip";
			break;
		case ESlBodyPartsPose34::LEFT_KNEE:
			ret = "L_Knee";
			break;
		case ESlBodyPartsPose34::LEFT_ANKLE:
			ret = "L_Ankle";
			break;
		case ESlBodyPartsPose34::LEFT_FOOT:
			ret = "L_Foot";
			break;
		case ESlBodyPartsPose34::RIGHT_HIP:
			ret = "R_Hip";
			break;
		case ESlBodyPartsPose34::RIGHT_KNEE:
			ret = "R_Knee";
			break;
		case ESlBodyPartsPose34::RIGHT_ANKLE:
			ret = "R_Ankle";
			break;
		case ESlBodyPartsPose34::RIGHT_FOOT:
			ret = "R_Foot";
			break;
		case ESlBodyPartsPose34::HEAD:
			ret = "Head";
			break;
		case ESlBodyPartsPose34::NOSE:
			ret = "Nose";
			break;
		case ESlBodyPartsPose34::LEFT_EYE:
			ret = "L_Eye";
			break;
		case ESlBodyPartsPose34::LEFT_EAR:
			ret = "L_Ear";
			break;
		case ESlBodyPartsPose34::RIGHT_EYE:
			ret = "R_Eye";
			break;
		case ESlBodyPartsPose34::RIGHT_EAR:
			ret = "R_Ear";
			break;
		case ESlBodyPartsPose34::LEFT_HEEL:
			ret = "L_Heel";
			break;
		case ESlBodyPartsPose34::RIGHT_HEEL:
			ret = "R_Heel";
			break;
		}
		return ret;
	}*/
	
};