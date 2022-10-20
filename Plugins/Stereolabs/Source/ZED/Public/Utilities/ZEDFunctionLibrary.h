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

static TArray<FSlBone34> BodyBonesPose34 = TArray<FSlBone34>{
	FSlBone34(ESlBodyPartsPose34::PELVIS, ESlBodyPartsPose34::NAVAL_SPINE),
	FSlBone34(ESlBodyPartsPose34::NAVAL_SPINE, ESlBodyPartsPose34::CHEST_SPINE),
	FSlBone34(ESlBodyPartsPose34::CHEST_SPINE, ESlBodyPartsPose34::LEFT_CLAVICLE),
	FSlBone34(ESlBodyPartsPose34::LEFT_CLAVICLE, ESlBodyPartsPose34::LEFT_SHOULDER),
	FSlBone34(ESlBodyPartsPose34::LEFT_SHOULDER, ESlBodyPartsPose34::LEFT_ELBOW),
	FSlBone34(ESlBodyPartsPose34::LEFT_ELBOW, ESlBodyPartsPose34::LEFT_WRIST),
	FSlBone34(ESlBodyPartsPose34::LEFT_WRIST, ESlBodyPartsPose34::LEFT_HAND),
	FSlBone34(ESlBodyPartsPose34::LEFT_HAND, ESlBodyPartsPose34::LEFT_HANDTIP),
	FSlBone34(ESlBodyPartsPose34::LEFT_WRIST, ESlBodyPartsPose34::LEFT_THUMB),
	FSlBone34(ESlBodyPartsPose34::CHEST_SPINE, ESlBodyPartsPose34::RIGHT_CLAVICLE),
	FSlBone34(ESlBodyPartsPose34::RIGHT_CLAVICLE, ESlBodyPartsPose34::RIGHT_SHOULDER),
	FSlBone34(ESlBodyPartsPose34::RIGHT_SHOULDER, ESlBodyPartsPose34::RIGHT_ELBOW),
	FSlBone34(ESlBodyPartsPose34::RIGHT_ELBOW, ESlBodyPartsPose34::RIGHT_WRIST),
	FSlBone34(ESlBodyPartsPose34::RIGHT_WRIST, ESlBodyPartsPose34::RIGHT_HAND),
	FSlBone34(ESlBodyPartsPose34::RIGHT_HAND, ESlBodyPartsPose34::RIGHT_HANDTIP),
	FSlBone34(ESlBodyPartsPose34::RIGHT_WRIST, ESlBodyPartsPose34::RIGHT_THUMB),
	FSlBone34(ESlBodyPartsPose34::PELVIS, ESlBodyPartsPose34::LEFT_HIP),
	FSlBone34(ESlBodyPartsPose34::LEFT_HIP, ESlBodyPartsPose34::LEFT_KNEE),
	FSlBone34(ESlBodyPartsPose34::LEFT_KNEE, ESlBodyPartsPose34::LEFT_ANKLE),
	FSlBone34(ESlBodyPartsPose34::LEFT_ANKLE, ESlBodyPartsPose34::LEFT_FOOT),
	FSlBone34(ESlBodyPartsPose34::PELVIS, ESlBodyPartsPose34::RIGHT_HIP),
	FSlBone34(ESlBodyPartsPose34::RIGHT_HIP, ESlBodyPartsPose34::RIGHT_KNEE),
	FSlBone34(ESlBodyPartsPose34::RIGHT_KNEE, ESlBodyPartsPose34::RIGHT_ANKLE),
	FSlBone34(ESlBodyPartsPose34::RIGHT_ANKLE, ESlBodyPartsPose34::RIGHT_FOOT),
	FSlBone34(ESlBodyPartsPose34::CHEST_SPINE, ESlBodyPartsPose34::NECK),
	FSlBone34(ESlBodyPartsPose34::NECK, ESlBodyPartsPose34::HEAD),
	FSlBone34(ESlBodyPartsPose34::HEAD, ESlBodyPartsPose34::NOSE),
	FSlBone34(ESlBodyPartsPose34::NOSE, ESlBodyPartsPose34::LEFT_EYE),
	FSlBone34(ESlBodyPartsPose34::LEFT_EYE, ESlBodyPartsPose34::LEFT_EAR),
	FSlBone34(ESlBodyPartsPose34::NOSE, ESlBodyPartsPose34::RIGHT_EYE),
	FSlBone34(ESlBodyPartsPose34::RIGHT_EYE, ESlBodyPartsPose34::RIGHT_EAR),
	FSlBone34(ESlBodyPartsPose34::LEFT_ANKLE, ESlBodyPartsPose34::LEFT_HEEL),
	FSlBone34(ESlBodyPartsPose34::RIGHT_ANKLE, ESlBodyPartsPose34::RIGHT_HEEL),
	FSlBone34(ESlBodyPartsPose34::LEFT_HEEL, ESlBodyPartsPose34::LEFT_FOOT),
	FSlBone34(ESlBodyPartsPose34::RIGHT_HEEL, ESlBodyPartsPose34::RIGHT_FOOT)
};

static TArray<FSlBone18> BodyBonesPose18 = TArray<FSlBone18>{
	FSlBone18(ESlBodyParts::NOSE, ESlBodyParts::NECK),
	FSlBone18(ESlBodyParts::NECK, ESlBodyParts::RIGHT_SHOULDER),
	FSlBone18(ESlBodyParts::RIGHT_SHOULDER, ESlBodyParts::RIGHT_ELBOW),
	FSlBone18(ESlBodyParts::RIGHT_ELBOW, ESlBodyParts::RIGHT_WRIST),
	FSlBone18(ESlBodyParts::NECK, ESlBodyParts::LEFT_SHOULDER),
	FSlBone18(ESlBodyParts::LEFT_SHOULDER, ESlBodyParts::LEFT_ELBOW),
	FSlBone18(ESlBodyParts::LEFT_ELBOW, ESlBodyParts::LEFT_WRIST),
	FSlBone18(ESlBodyParts::RIGHT_SHOULDER, ESlBodyParts::RIGHT_HIP),
	FSlBone18(ESlBodyParts::RIGHT_HIP, ESlBodyParts::RIGHT_KNEE),
	FSlBone18(ESlBodyParts::RIGHT_KNEE, ESlBodyParts::RIGHT_ANKLE),
	FSlBone18(ESlBodyParts::LEFT_SHOULDER, ESlBodyParts::LEFT_HIP),
	FSlBone18(ESlBodyParts::LEFT_HIP, ESlBodyParts::LEFT_KNEE),
	FSlBone18(ESlBodyParts::LEFT_KNEE, ESlBodyParts::LEFT_ANKLE),
	FSlBone18(ESlBodyParts::RIGHT_SHOULDER, ESlBodyParts::LEFT_SHOULDER),
	FSlBone18(ESlBodyParts::RIGHT_HIP, ESlBodyParts::LEFT_HIP),
	FSlBone18(ESlBodyParts::NOSE, ESlBodyParts::RIGHT_EYE),
	FSlBone18(ESlBodyParts::RIGHT_EYE, ESlBodyParts::RIGHT_EAR),
	FSlBone18(ESlBodyParts::NOSE, ESlBodyParts::LEFT_EYE),
	FSlBone18(ESlBodyParts::LEFT_EYE, ESlBodyParts::LEFT_EAR),
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
	 * @param ESlBodyPartsPose34Val The body part value
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetIndexFromValue", Keywords = "get index enum from value"), Category = "Stereolabs|Zed")
	static uint8 GetIndexFromValuePose34(ESlBodyPartsPose34 ESlBodyPartsPose34Val)
	{
		return (uint8)ESlBodyPartsPose34Val;
	}

	/*
	 * Get the index corresponding to the enum value
	 * @param ESlBodyPartsVal The body part value
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetIndexFromValue", Keywords = "get index enum from value"), Category = "Stereolabs|Zed")
	static uint8 GetIndexFromValue(ESlBodyParts ESlBodyPartsVal)
	{
		return (uint8)ESlBodyPartsVal;
	}

	/*
	 * Get the index corresponding to the enum value
	* @param ESlBodyPartsVal The body part value
	*/
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetBodyBonesPose34", Keywords = "GetBodyBonesPose34"), Category = "Stereolabs|Zed")
	static const TArray<FSlBone34> GetBodyBonesPose34()
	{
		return BodyBonesPose34;
	}

	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetBodyBonesPose18", Keywords = "GetBodyBonesPose18"), Category = "Stereolabs|Zed")
	static const TArray<FSlBone18> GetBodyBonesPose18()
	{
		return BodyBonesPose18;
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

};