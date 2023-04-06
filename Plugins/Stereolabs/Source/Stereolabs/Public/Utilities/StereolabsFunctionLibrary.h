//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Engine.h"
#include "kismet/BlueprintFunctionLibrary.h"

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

#include "StereolabsFunctionLibrary.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(SLFunctionLibrary, Log, All);

UCLASS()
class STEREOLABS_API USlFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	 * Retrieve the camera proxy instance. Can be null.
	 * @return The camera proxy instance
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetCameraProxy", Keywords = "get zed camera proxy"), Category = "Stereolabs")
	static USlCameraProxy* GetCameraProxy()
	{
		return GSlCameraProxy;
	}

	/*
	 * @return True if in grab thread
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "IsInGrabThread", Keywords = "get zed in grab thread"), Category = "Stereolabs")
	static bool IsInGrabThread()
	{
		return IsInSlGrabThread();
	}
	
	/*
	 * Convert a depth retrieved using GetDepth to the distance from camera
	 * @param ViewportHelper    The viewport helper of the current view
	 * @param ScreenPosition    The screen position of the depth
	 * @param Depth				The depth
	 * @return					The distance from the camera
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ConvertDepthToDistance", Keywords = "get zed depth to distance"), Category = "Stereolabs")
	static float ConvertDepthToDistance(const FSlViewportHelper& ViewportHelper, const FVector2D& ScreenPosition, float Depth);

	/*
	 * Convert a depth to the distance from camera
	 * @param CameraParameters  The camera parameters used to retrieve the depth
	 * @param Position			The position of the depth in the depth mat
	 * @param Depth				The depth
	 * @return					The distance from the camera
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ConvertCustomDepthToDistance", Keywords = "get zed depth to distance"), Category = "Stereolabs")
	static float ConvertCustomDepthToDistance(const FSlCameraParameters& CameraParameters, const FVector2D& Position, float Depth);

	/*
	 * Compute rendering plane size
	 * @param VerticalFOV		Zed vertical FOV
	 * @param PlaneDistance	    Plane rendering distance from camera
	 * @param ImageResolution   Zed image resolution
	 * @return size width/height of the plane
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetRenderPlaneSize", Keywords = "get zed render plane size"), Category = "Stereolabs")
	static FVector2D GetRenderPlaneSize(const FIntPoint& ImageResolution, float VerticalFOV, float PlaneDistance);

	/*
	 * Compute rendering plane size using gamma
	 * @param PerceptionDistance The distance at which objects will have their correct size
	 * @param ImageResolution    Zed image resolution
	 * @param PerceptionDistance Distance at which object match their real size
	 * @param ZedFocal	         Zed focal
	 * @param PlaneDistance	     Plane rendering distance from camera
	 * @return size width/height of the plane
	 */
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", DisplayName = "GetRenderPlaneSizeWithGamma", Keywords = "get zed render plane size with gamma"), Category = "Stereolabs")
	static FVector2D GetRenderPlaneSizeWithGamma(UObject* WorldContextObject, const FIntPoint& ImageResolution, float PerceptionDistance, float ZedFocal, float PlaneDistance);

	/*
	 * Compute optical center offsets for left/right images
	 * @paramI mageResolution  Zed image resolution
	 * @param Distance         Distance from camera
	 * @return the x/y offset for each eye
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetOpticalCentersOffsets", Keywords = "get zed optical centers offsets"), Category = "Stereolabs")
	static FVector4 GetOpticalCentersOffsets(const FIntPoint& ImageResolution, float Distance);

	/*
	 * Get the optical center offset for the selected eye
	 * @param Eye The eye
	 * @return	  The offsets
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetOffCenterProjectionOffset", Keywords = "get zed off center projection offset"), Category = "Stereolabs")
	static FVector2D GetOffCenterProjectionOffset(ESlEye Eye = ESlEye::E_Left);

	/*
	 * Get the projection matrix for a scene capture
	 * @param ProjectionMatrix The projection matrix
	 * @param Eye			   The eye
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "GetSceneCaptureProjectionMatrix", Keywords = "get zed projection matrix"), Category = "Stereolabs")
	static void GetSceneCaptureProjectionMatrix(FMatrix& ProjectionMatrix, ESlEye Eye = ESlEye::E_Left);

	/*
	 * Convert sl::ERROR_CODE to string
	 * @param ErrorCode The sl:ERROR_CODE to convert
	 * @return			The converted string
	 */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ErrorCodeToString", Keywords = "zed error code to string"), Category = "Stereolabs")
	static FString ErrorCodeToString(ESlErrorCode ErrorCode);

	/*
	 * Set the resolution of a FZEDSpatialMappingParameters struct
	 * @param NewResolution	The new resolution
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetResolution", Keywords = "set resolution"), Category = "Stereolabs")
	static void SetResolutionPreset(UPARAM(ref) FSlSpatialMappingParameters& SpatialMappingParameters, ESlSpatialMappingResolution NewResolution)
	{
		SpatialMappingParameters.SetResolution(NewResolution);
	}

	/*
	 * Set the resolution of a FSlSpatialMappingParameters struct
	 * @param NewResolution	The new resolution
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetResolution", Keywords = "set resolution"), Category = "Stereolabs")
	static void SetResolutionValue(UPARAM(ref) FSlSpatialMappingParameters& SpatialMappingParameters, float NewResolution)
	{
		SpatialMappingParameters.SetResolution(NewResolution);
	}

	/*
	 * Set the max range of a FSlSpatialMappingParameters struct
	 * @param NewMaxRange The new max range
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetMaxRange", Keywords = "set max range"), Category = "Stereolabs")
	static void SetMaxRangePreset(UPARAM(ref) FSlSpatialMappingParameters& SpatialMappingParameters, ESlSpatialMappingRange NewMaxRange)
	{
		SpatialMappingParameters.SetMaxRange(NewMaxRange);
	}

	/*
	 * Set the max range of a FSlSpatialMappingParameters struct
	 * @param NewMaxRange The new max range
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetMaxRange", Keywords = "set max range"), Category = "Stereolabs")
	static void SetMaxRangeValue(UPARAM(ref) FSlSpatialMappingParameters& SpatialMappingParameters, float NewMaxRange)
	{
		SpatialMappingParameters.SetMaxRange(NewMaxRange);
	}

	/*
	 * Set the min range of a FSlSpatialMappingParameters struct
	 * @param SpatialMappingParameters The struct
	 * @param NewMinRange			   The new min range
	 */
	/*UFUNCTION(BlueprintCallable, meta = (DisplayName = "SetMinRange", Keywords = "set min range"), Category = "Stereolabs")
	static void SetMinRangeValue(FSlSpatialMappingParameters& SpatialMappingParameters, float NewMinRange)
	{
		SpatialMappingParameters.SetMinRange(NewMinRange);
	}*/

	/*
 	 * Clear mesh data
	 */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ClearMeshData", Keywords = "clear mesh data"), Category = "Stereolabs")
	static void ClearMeshData(UPARAM(ref) FSlMeshData& MeshData)
	{
		MeshData.Clear();
	}

	/** Converts a FSlTimestamp into a string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (SlTimestamp)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Stereolabs")
	static FString Conv_TimestampToString(const FSlTimestamp& InTimestamp)
	{
		return InTimestamp.ToString();
	}

	/** return true if A is equal to B (A == B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "== (timestamp)", CompactNodeTitle = "==", Keywords = "=="), Category = "Stereolabs")
	static bool EqualEqual_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return A.timestamp.data_ns == B.timestamp.data_ns;
	}

	/** return true if A is not equal to B (A != B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "!= (timestamp)", CompactNodeTitle = "!=", Keywords = "!="), Category = "Stereolabs")
	static bool NotEqual_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return A.timestamp.data_ns != B.timestamp.data_ns;
	}

	/** return true if A is less than B (A < B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "< (timestamp)", CompactNodeTitle = "<", Keywords = "<"), Category = "Stereolabs")
	static bool Less_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return A.timestamp.data_ns < B.timestamp.data_ns;
	}

	/** return true if A is less than or equal to B (A <= B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "<= (timestamp)", CompactNodeTitle = "<=", Keywords = "<="), Category = "Stereolabs")
	static bool LessEqual_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return A.timestamp.data_ns <= B.timestamp.data_ns;
	}

	/** return true if A is greater than B (A > B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "> (timestamp)", CompactNodeTitle = ">", Keywords = ">"), Category = "Stereolabs")
	static bool Greater_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return A.timestamp.data_ns > B.timestamp.data_ns;
	}

	/** return true if A is greater than or equal to B (A >= B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = ">= (timestamp)", CompactNodeTitle = ">=", Keywords = ">="), Category = "Stereolabs")
	static bool GreaterEqual_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return A.timestamp.data_ns >= B.timestamp.data_ns;
	}

	/** Addition (A + B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "timestamp + timestamp", CompactNodeTitle = "+", Keywords = "+ add plus"), Category = "Stereolabs")
	static FSlTimestamp Add_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return FSlTimestamp(A.timestamp + B.timestamp);
	}

	/** Subtraction (A - B) */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "timestamp - timestamp", CompactNodeTitle = "-", Keywords = "- substract minus"), Category = "Stereolabs")
	static FSlTimestamp Substract_TimestampTimestamp(const FSlTimestamp& A, const FSlTimestamp& B)
	{
		return FSlTimestamp(A.timestamp - B.timestamp);
	}

	/** Generate texture from txt file */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GenerateTextureFromTxtFile", Keywords = "texture"), Category = "Stereolabs")
	static UTexture2D* GenerateTextureFromTxtFile(const FString filepath);

	static UTexture2D* GenerateTextureFromSlMat(const sl::Mat* mat);

	/* Compute 3d box position, orientation and scale based on Objectdata informations*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Set3DBoxTransform"), Category = "Stereolabs")
	static void Set3DBoxTransform(UPARAM(ref) AActor*& BBox, const FSlObjectData ObjectData);

	/* return the height of a Skeletal bone*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "GetSkeletonBoneHeight"), Category = "Stereolabs")
	static float GetSkeletonBoneHeight(const USkeletalMeshComponent* SkeletalMesh, const FName BoneName);
};