// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDFunctionLibrary() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_UZEDFunctionLibrary_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_ZED();
	ZED_API UClass* Z_Construct_UClass_AZEDPlayerController_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlMeshData();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDCamera_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlRetrieveResult();
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDTrackingData();
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDHitResult();
// End Cross Module References
	DEFINE_FUNCTION(UZEDFunctionLibrary::execLatencyCorrectorAddOffset)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_offset);
		P_FINISH;
		P_NATIVE_BEGIN;
		UZEDFunctionLibrary::LatencyCorrectorAddOffset(Z_Param_offset);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execCreateMeshFromFloorPlane)
	{
		P_GET_STRUCT_REF(FSlMeshData,Z_Param_Out_MeshData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::CreateMeshFromFloorPlane(Z_Param_Out_MeshData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execCreateMeshFromFloorHit)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT(FIntPoint,Z_Param_ScreenPosition);
		P_GET_STRUCT_REF(FSlMeshData,Z_Param_Out_MeshData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::CreateMeshFromFloorHit(Z_Param_PlayerController,Z_Param_ScreenPosition,Z_Param_Out_MeshData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetFloorPlaneAtWorldLocation)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PlaneLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::GetFloorPlaneAtWorldLocation(Z_Param_PlayerController,Z_Param_Out_WorldLocation,Z_Param_Out_PlaneLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetFloorPlaneAtScreenPosition)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PlaneLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::GetFloorPlaneAtScreenPosition(Z_Param_PlayerController,Z_Param_Out_ScreenPosition,Z_Param_Out_PlaneLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execMultipleHitTestsRealOneResult)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(float,Z_Param_Out_HitThresholds);
		P_GET_UBOOL(Z_Param_bGetNormal);
		P_GET_UBOOL(Z_Param_bHitIfBehind);
		P_GET_STRUCT_REF(FZEDHitResult,Z_Param_Out_HitResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::MultipleHitTestsRealOneResult(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_HitThresholds,Z_Param_bGetNormal,Z_Param_bHitIfBehind,Z_Param_Out_HitResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execMultipleHitTestsReal)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(float,Z_Param_Out_HitThresholds);
		P_GET_UBOOL(Z_Param_bGetNormal);
		P_GET_UBOOL(Z_Param_bHitIfBehind);
		P_GET_TARRAY_REF(FZEDHitResult,Z_Param_Out_HitResults);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::MultipleHitTestsReal(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_HitThresholds,Z_Param_bGetNormal,Z_Param_bHitIfBehind,Z_Param_Out_HitResults);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execHitTestReal)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HitThreshold);
		P_GET_UBOOL(Z_Param_bGetNormal);
		P_GET_UBOOL(Z_Param_bHitIfBehind);
		P_GET_STRUCT_REF(FZEDHitResult,Z_Param_Out_HitResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::HitTestReal(Z_Param_PlayerController,Z_Param_Out_Location,Z_Param_HitThreshold,Z_Param_bGetNormal,Z_Param_bHitIfBehind,Z_Param_Out_HitResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelsLocationAndNormalAtWorldLocations)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_PixelsWorldLocations);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetPixelsLocationAndNormalAtWorldLocations(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_PixelsWorldLocations,Z_Param_Out_Depths,Z_Param_Out_Distances,Z_Param_Out_Normals);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelsLocationAndNormalAtScreenPositions)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_ScreenPositions);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_PixelsWorldLocations);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetPixelsLocationAndNormalAtScreenPositions(Z_Param_PlayerController,Z_Param_Out_ScreenPositions,Z_Param_Out_PixelsWorldLocations,Z_Param_Out_Depths,Z_Param_Out_Distances,Z_Param_Out_Normals);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelsLocationAtWorldLocations)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_PixelsWorldLocations);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetPixelsLocationAtWorldLocations(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_PixelsWorldLocations,Z_Param_Out_Depths,Z_Param_Out_Distances);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelsLocationAtScreenPositions)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_ScreenPositions);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_PixelWorldLocations);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetPixelsLocationAtScreenPositions(Z_Param_PlayerController,Z_Param_Out_ScreenPositions,Z_Param_Out_PixelWorldLocations,Z_Param_Out_Depths,Z_Param_Out_Distances);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelLocationAndNormalAtWorldLocation)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PixelWorldLocation);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetPixelLocationAndNormalAtWorldLocation(Z_Param_PlayerController,Z_Param_Out_Location,Z_Param_Out_PixelWorldLocation,Z_Param_Out_Depth,Z_Param_Out_Distance,Z_Param_Out_Normal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelLocationAndNormalAtScreenPosition)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PixelWorldLocation);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetPixelLocationAndNormalAtScreenPosition(Z_Param_PlayerController,Z_Param_Out_ScreenPosition,Z_Param_Out_PixelWorldLocation,Z_Param_Out_Depth,Z_Param_Out_Distance,Z_Param_Out_Normal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelLocationAtWorldLocation)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PixelWorldLocation);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetPixelLocationAtWorldLocation(Z_Param_PlayerController,Z_Param_Out_Location,Z_Param_Out_PixelWorldLocation,Z_Param_Out_Depth,Z_Param_Out_Distance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPixelLocationAtScreenPosition)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_PixelWorldLocation);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetPixelLocationAtScreenPosition(Z_Param_PlayerController,Z_Param_Out_ScreenPosition,Z_Param_Out_PixelWorldLocation,Z_Param_Out_Depth,Z_Param_Out_Distance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthsAndNormalsAtWorldLocations)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetDepthsAndNormalsAtWorldLocations(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_Depths,Z_Param_Out_Distances,Z_Param_Out_Normals);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthsAndNormalsAtScreenPositions)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_ScreenPositions);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_WorldDirections);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetDepthsAndNormalsAtScreenPositions(Z_Param_PlayerController,Z_Param_Out_ScreenPositions,Z_Param_Out_Depths,Z_Param_Out_Distances,Z_Param_Out_Normals,Z_Param_Out_WorldDirections);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetNormalsAtWorldLocations)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetNormalsAtWorldLocations(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_Normals);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetNormalsAtScreenPositions)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_ScreenPositions);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Normals);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetNormalsAtScreenPositions(Z_Param_PlayerController,Z_Param_Out_ScreenPositions,Z_Param_Out_Normals);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthsAtWorldLocations)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_Locations);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetDepthsAtWorldLocations(Z_Param_PlayerController,Z_Param_Out_Locations,Z_Param_Out_Depths,Z_Param_Out_Distances);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthsAtScreenPositions)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_ScreenPositions);
		P_GET_TARRAY_REF(float,Z_Param_Out_Depths);
		P_GET_TARRAY_REF(float,Z_Param_Out_Distances);
		P_GET_TARRAY_REF(FVector,Z_Param_Out_WorldDirections);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<ESlRetrieveResult>*)Z_Param__Result=UZEDFunctionLibrary::GetDepthsAtScreenPositions(Z_Param_PlayerController,Z_Param_Out_ScreenPositions,Z_Param_Out_Depths,Z_Param_Out_Distances,Z_Param_Out_WorldDirections);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthAndNormalAtWorldLocation)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetDepthAndNormalAtWorldLocation(Z_Param_PlayerController,Z_Param_Out_Location,Z_Param_Out_Depth,Z_Param_Out_Distance,Z_Param_Out_Normal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthAndNormalAtScreenPosition)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldDirection);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetDepthAndNormalAtScreenPosition(Z_Param_PlayerController,Z_Param_Out_ScreenPosition,Z_Param_Out_Depth,Z_Param_Out_Distance,Z_Param_Out_Normal,Z_Param_Out_WorldDirection);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetNormalAtWorldLocation)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetNormalAtWorldLocation(Z_Param_PlayerController,Z_Param_Out_Location,Z_Param_Out_Normal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetNormalAtScreenPosition)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Normal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetNormalAtScreenPosition(Z_Param_PlayerController,Z_Param_Out_ScreenPosition,Z_Param_Out_Normal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthAtWorldLocation)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetDepthAtWorldLocation(Z_Param_PlayerController,Z_Param_Out_Location,Z_Param_Out_Depth,Z_Param_Out_Distance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetDepthAtScreenPosition)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Depth);
		P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Distance);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldDirection);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlRetrieveResult*)Z_Param__Result=UZEDFunctionLibrary::GetDepthAtScreenPosition(Z_Param_PlayerController,Z_Param_Out_ScreenPosition,Z_Param_Out_Depth,Z_Param_Out_Distance,Z_Param_Out_WorldDirection);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execIsVisible)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::IsVisible(Z_Param_PlayerController,Z_Param_Out_WorldLocation,Z_Param_Out_ScreenPosition);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execIsLocationVisible)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::IsLocationVisible(Z_Param_PlayerController,Z_Param_Out_WorldLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execIsLocationInScreenBounds)
	{
		P_GET_OBJECT(AZEDPlayerController,Z_Param_PlayerController);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_WorldLocation);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UZEDFunctionLibrary::IsLocationInScreenBounds(Z_Param_PlayerController,Z_Param_Out_WorldLocation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetCustomLocationInFrontOfPlayer)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OriginLocation);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_OriginRotation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UZEDFunctionLibrary::GetCustomLocationInFrontOfPlayer(Z_Param_Out_OriginLocation,Z_Param_Out_OriginRotation,Z_Param_Distance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetCenteredLocationInFrontOfPlayer)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=UZEDFunctionLibrary::GetCenteredLocationInFrontOfPlayer(Z_Param_Distance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetCameraActor)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AZEDCamera**)Z_Param__Result=UZEDFunctionLibrary::GetCameraActor(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetPlayerController)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AZEDPlayerController**)Z_Param__Result=UZEDFunctionLibrary::GetPlayerController(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execSetViewPointOrientationAndLocation)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Orientation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_FINISH;
		P_NATIVE_BEGIN;
		UZEDFunctionLibrary::SetViewPointOrientationAndLocation(Z_Param_Out_Orientation,Z_Param_Out_Location);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execSetRawOrientationAndLocation)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Orientation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_FINISH;
		P_NATIVE_BEGIN;
		UZEDFunctionLibrary::SetRawOrientationAndLocation(Z_Param_Out_Orientation,Z_Param_Out_Location);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetViewPointOrientationAndLocation)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Orientation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_FINISH;
		P_NATIVE_BEGIN;
		UZEDFunctionLibrary::GetViewPointOrientationAndLocation(Z_Param_Out_Orientation,Z_Param_Out_Location);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetRawOrientationAndLocation)
	{
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Orientation);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_FINISH;
		P_NATIVE_BEGIN;
		UZEDFunctionLibrary::GetRawOrientationAndLocation(Z_Param_Out_Orientation,Z_Param_Out_Location);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDFunctionLibrary::execGetTrackingData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FZEDTrackingData*)Z_Param__Result=UZEDFunctionLibrary::GetTrackingData();
		P_NATIVE_END;
	}
	void UZEDFunctionLibrary::StaticRegisterNativesUZEDFunctionLibrary()
	{
		UClass* Class = UZEDFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateMeshFromFloorHit", &UZEDFunctionLibrary::execCreateMeshFromFloorHit },
			{ "CreateMeshFromFloorPlane", &UZEDFunctionLibrary::execCreateMeshFromFloorPlane },
			{ "GetCameraActor", &UZEDFunctionLibrary::execGetCameraActor },
			{ "GetCenteredLocationInFrontOfPlayer", &UZEDFunctionLibrary::execGetCenteredLocationInFrontOfPlayer },
			{ "GetCustomLocationInFrontOfPlayer", &UZEDFunctionLibrary::execGetCustomLocationInFrontOfPlayer },
			{ "GetDepthAndNormalAtScreenPosition", &UZEDFunctionLibrary::execGetDepthAndNormalAtScreenPosition },
			{ "GetDepthAndNormalAtWorldLocation", &UZEDFunctionLibrary::execGetDepthAndNormalAtWorldLocation },
			{ "GetDepthAtScreenPosition", &UZEDFunctionLibrary::execGetDepthAtScreenPosition },
			{ "GetDepthAtWorldLocation", &UZEDFunctionLibrary::execGetDepthAtWorldLocation },
			{ "GetDepthsAndNormalsAtScreenPositions", &UZEDFunctionLibrary::execGetDepthsAndNormalsAtScreenPositions },
			{ "GetDepthsAndNormalsAtWorldLocations", &UZEDFunctionLibrary::execGetDepthsAndNormalsAtWorldLocations },
			{ "GetDepthsAtScreenPositions", &UZEDFunctionLibrary::execGetDepthsAtScreenPositions },
			{ "GetDepthsAtWorldLocations", &UZEDFunctionLibrary::execGetDepthsAtWorldLocations },
			{ "GetFloorPlaneAtScreenPosition", &UZEDFunctionLibrary::execGetFloorPlaneAtScreenPosition },
			{ "GetFloorPlaneAtWorldLocation", &UZEDFunctionLibrary::execGetFloorPlaneAtWorldLocation },
			{ "GetNormalAtScreenPosition", &UZEDFunctionLibrary::execGetNormalAtScreenPosition },
			{ "GetNormalAtWorldLocation", &UZEDFunctionLibrary::execGetNormalAtWorldLocation },
			{ "GetNormalsAtScreenPositions", &UZEDFunctionLibrary::execGetNormalsAtScreenPositions },
			{ "GetNormalsAtWorldLocations", &UZEDFunctionLibrary::execGetNormalsAtWorldLocations },
			{ "GetPixelLocationAndNormalAtScreenPosition", &UZEDFunctionLibrary::execGetPixelLocationAndNormalAtScreenPosition },
			{ "GetPixelLocationAndNormalAtWorldLocation", &UZEDFunctionLibrary::execGetPixelLocationAndNormalAtWorldLocation },
			{ "GetPixelLocationAtScreenPosition", &UZEDFunctionLibrary::execGetPixelLocationAtScreenPosition },
			{ "GetPixelLocationAtWorldLocation", &UZEDFunctionLibrary::execGetPixelLocationAtWorldLocation },
			{ "GetPixelsLocationAndNormalAtScreenPositions", &UZEDFunctionLibrary::execGetPixelsLocationAndNormalAtScreenPositions },
			{ "GetPixelsLocationAndNormalAtWorldLocations", &UZEDFunctionLibrary::execGetPixelsLocationAndNormalAtWorldLocations },
			{ "GetPixelsLocationAtScreenPositions", &UZEDFunctionLibrary::execGetPixelsLocationAtScreenPositions },
			{ "GetPixelsLocationAtWorldLocations", &UZEDFunctionLibrary::execGetPixelsLocationAtWorldLocations },
			{ "GetPlayerController", &UZEDFunctionLibrary::execGetPlayerController },
			{ "GetRawOrientationAndLocation", &UZEDFunctionLibrary::execGetRawOrientationAndLocation },
			{ "GetTrackingData", &UZEDFunctionLibrary::execGetTrackingData },
			{ "GetViewPointOrientationAndLocation", &UZEDFunctionLibrary::execGetViewPointOrientationAndLocation },
			{ "HitTestReal", &UZEDFunctionLibrary::execHitTestReal },
			{ "IsLocationInScreenBounds", &UZEDFunctionLibrary::execIsLocationInScreenBounds },
			{ "IsLocationVisible", &UZEDFunctionLibrary::execIsLocationVisible },
			{ "IsVisible", &UZEDFunctionLibrary::execIsVisible },
			{ "LatencyCorrectorAddOffset", &UZEDFunctionLibrary::execLatencyCorrectorAddOffset },
			{ "MultipleHitTestsReal", &UZEDFunctionLibrary::execMultipleHitTestsReal },
			{ "MultipleHitTestsRealOneResult", &UZEDFunctionLibrary::execMultipleHitTestsRealOneResult },
			{ "SetRawOrientationAndLocation", &UZEDFunctionLibrary::execSetRawOrientationAndLocation },
			{ "SetViewPointOrientationAndLocation", &UZEDFunctionLibrary::execSetViewPointOrientationAndLocation },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics
	{
		struct ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms
		{
			AZEDPlayerController* PlayerController;
			FIntPoint ScreenPosition;
			FSlMeshData MeshData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms, ScreenPosition), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_MeshData = { "MeshData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms, MeshData), Z_Construct_UScriptStruct_FSlMeshData, METADATA_PARAMS(nullptr, 0) }; // 1900805824
	void Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_MeshData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Find floor plane at hit and convert it to mesh\n\x09 * @param ScreenPosition   The position in the image \n\x09 * @param MeshData         The Mesh data\n\x09 */" },
		{ "DisplayName", "CreateMeshFromFloorHit" },
		{ "Keywords", "Find floor plane at hit and convert it to mesh" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Find floor plane at hit and convert it to mesh\n* @param ScreenPosition   The position in the image\n* @param MeshData         The Mesh data" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "CreateMeshFromFloorHit", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::ZEDFunctionLibrary_eventCreateMeshFromFloorHit_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics
	{
		struct ZEDFunctionLibrary_eventCreateMeshFromFloorPlane_Parms
		{
			FSlMeshData MeshData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::NewProp_MeshData = { "MeshData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventCreateMeshFromFloorPlane_Parms, MeshData), Z_Construct_UScriptStruct_FSlMeshData, METADATA_PARAMS(nullptr, 0) }; // 1900805824
	void Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventCreateMeshFromFloorPlane_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventCreateMeshFromFloorPlane_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::NewProp_MeshData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "DisplayName", "CreateMeshFromFloorPlane" },
		{ "Keywords", "Find floor plane and convert it to mesh" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "CreateMeshFromFloorPlane", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::ZEDFunctionLibrary_eventCreateMeshFromFloorPlane_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics
	{
		struct ZEDFunctionLibrary_eventGetCameraActor_Parms
		{
			UObject* WorldContextObject;
			AZEDCamera* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCameraActor_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCameraActor_Parms, ReturnValue), Z_Construct_UClass_AZEDCamera_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the Zed camera actor. Can be null.\n\x09 * @return The Zed camera actor\n\x09 */" },
		{ "DisplayName", "GetCameraActor" },
		{ "Keywords", "get zed camera actor" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the Zed camera actor. Can be null.\n* @return The Zed camera actor" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetCameraActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::ZEDFunctionLibrary_eventGetCameraActor_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics
	{
		struct ZEDFunctionLibrary_eventGetCenteredLocationInFrontOfPlayer_Parms
		{
			float Distance;
			FVector ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCenteredLocationInFrontOfPlayer_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCenteredLocationInFrontOfPlayer_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Calculate the location of an actor centered in front of the player at desired distance using optical center offsets\n\x09 * @param Distance The distance from the player\n\x09 * @return\x09\x09   The world location\n\x09 */" },
		{ "DisplayName", "GetCenteredLocationInFrontOfPlayer" },
		{ "Keywords", "get zed centered location front player" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Calculate the location of an actor centered in front of the player at desired distance using optical center offsets\n* @param Distance The distance from the player\n* @return                 The world location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetCenteredLocationInFrontOfPlayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::ZEDFunctionLibrary_eventGetCenteredLocationInFrontOfPlayer_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics
	{
		struct ZEDFunctionLibrary_eventGetCustomLocationInFrontOfPlayer_Parms
		{
			FVector OriginLocation;
			FRotator OriginRotation;
			float Distance;
			FVector ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OriginLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OriginLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OriginRotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OriginRotation;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginLocation = { "OriginLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCustomLocationInFrontOfPlayer_Parms, OriginLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginRotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginRotation = { "OriginRotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCustomLocationInFrontOfPlayer_Parms, OriginRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginRotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginRotation_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCustomLocationInFrontOfPlayer_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetCustomLocationInFrontOfPlayer_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_OriginRotation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Calculate the location of an actor in front of the player at desired distance using optical center offsets\n\x09 * @param OriginLocation The location origin to place the object\n\x09 * @param OriginRotation The rotation origin to calculate forward, right and up vectors\n\x09 * @return\x09\x09\x09     The world location\n\x09 */" },
		{ "DisplayName", "GetCustomLocationInFrontOfPlayer" },
		{ "Keywords", "get zed custom location front player" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Calculate the location of an actor in front of the player at desired distance using optical center offsets\n* @param OriginLocation The location origin to place the object\n* @param OriginRotation The rotation origin to calculate forward, right and up vectors\n* @return                           The world location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetCustomLocationInFrontOfPlayer", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::ZEDFunctionLibrary_eventGetCustomLocationInFrontOfPlayer_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector2D ScreenPosition;
			float Depth;
			float Distance;
			FVector Normal;
			FVector WorldDirection;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldDirection;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_WorldDirection = { "WorldDirection", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, WorldDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_WorldDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depth and normal at screen position\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPosition   The screen position\n\x09 * @param Depth\x09\x09\x09   The out depth at the screen position\n\x09 * @param Distance\x09\x09   The out distance from the camera\n\x09 * @param Normal\x09\x09   The out normal\n\x09 * @param WorldDirection   The direction vector from the camera\n\x09 * @return\x09\x09\x09\x09   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetDepthAndNormalAtScreenPosition" },
		{ "Keywords", "get zed depth normal screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depth and normal at screen position\n* @param PlayerController The Zed player controller\n* @param ScreenPosition   The screen position\n* @param Depth                    The out depth at the screen position\n* @param Distance                 The out distance from the camera\n* @param Normal                   The out normal\n* @param WorldDirection   The direction vector from the camera\n* @return                                 The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthAndNormalAtScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::ZEDFunctionLibrary_eventGetDepthAndNormalAtScreenPosition_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector Location;
			float Depth;
			float Distance;
			FVector Normal;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depth and normal at world location\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Location\x09\x09   The world location\n\x09 * @param Depth\x09\x09\x09   The out depth\n\x09 * @param Distance\x09\x09   The out distance from the camera\n\x09 * @param Normal\x09\x09   The out normal\n\x09 * @return\x09\x09\x09\x09   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetDepthAndNormalAtWorldLocation" },
		{ "Keywords", "get zed depth normal world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depth and normal at world location\n* @param PlayerController The Zed player controller\n* @param Location                 The world location\n* @param Depth                    The out depth\n* @param Distance                 The out distance from the camera\n* @param Normal                   The out normal\n* @return                                 The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthAndNormalAtWorldLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::ZEDFunctionLibrary_eventGetDepthAndNormalAtWorldLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector2D ScreenPosition;
			float Depth;
			float Distance;
			FVector WorldDirection;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldDirection;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_WorldDirection = { "WorldDirection", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms, WorldDirection), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_WorldDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depth at screen position\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPosition   The screen position\n\x09 * @param Depth\x09\x09\x09   The out depth at the screen position\n\x09 * @param Distance\x09\x09   The distance from the camera\n\x09 * @param WorldDirection   The out direction vector from the camera\n\x09 * @return\x09\x09\x09\x09   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetDepthAtScreenPosition" },
		{ "Keywords", "get zed depth screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depth at screen position\n* @param PlayerController The Zed player controller\n* @param ScreenPosition   The screen position\n* @param Depth                    The out depth at the screen position\n* @param Distance                 The distance from the camera\n* @param WorldDirection   The out direction vector from the camera\n* @return                                 The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthAtScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::ZEDFunctionLibrary_eventGetDepthAtScreenPosition_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector Location;
			float Depth;
			float Distance;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depth at world location\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Location\x09\x09   The world location\n\x09 * @param Depth\x09\x09\x09   The out depth at the screen position\n\x09 * @param Distance\x09\x09   The out distance from the camera\n\x09 * @return\x09\x09\x09\x09   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetDepthAtWorldLocation" },
		{ "Keywords", "get zed depth world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depth at world location\n* @param PlayerController The Zed player controller\n* @param Location                 The world location\n* @param Depth                    The out depth at the screen position\n* @param Distance                 The out distance from the camera\n* @return                                 The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthAtWorldLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::ZEDFunctionLibrary_eventGetDepthAtWorldLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector2D> ScreenPositions;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<FVector> Normals;
			TArray<FVector> WorldDirections;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPositions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPositions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ScreenPositions;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldDirections_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_WorldDirections;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_Inner = { "ScreenPositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions = { "ScreenPositions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, ScreenPositions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_WorldDirections_Inner = { "WorldDirections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_WorldDirections = { "WorldDirections", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, WorldDirections), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ScreenPositions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_WorldDirections_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_WorldDirections,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depths and normals at screen positions\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPositions  The screen positions\n\x09 * @param Depths\x09\x09   The out depths\n\x09 * @param Distances\x09\x09   The out distances from the camera\n\x09 * @param Normals\x09\x09   The out Normals\n\x09 * @param WorldDirections  The direction vectors from the camera\n\x09 * @return\x09\x09\x09\x09   The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetDepthsAndNormalsAtScreenPositions" },
		{ "Keywords", "get zed depths normals screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depths and normals at screen positions\n* @param PlayerController The Zed player controller\n* @param ScreenPositions  The screen positions\n* @param Depths                   The out depths\n* @param Distances                The out distances from the camera\n* @param Normals                  The out Normals\n* @param WorldDirections  The direction vectors from the camera\n* @return                                 The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthsAndNormalsAtScreenPositions", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::ZEDFunctionLibrary_eventGetDepthsAndNormalsAtScreenPositions_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<FVector> Normals;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depths and normals at world locations\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Locations\x09\x09   The world locations\n\x09 * @param Depths\x09\x09   The out depths\n\x09 * @param Distances\x09\x09   The out distances from the camera\n\x09 * @param Normals\x09\x09   The out Normals\n\x09 * @return\x09\x09\x09\x09   The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetDepthsAndNormalsAtWorldLocations" },
		{ "Keywords", "get zed depths normals world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depths and normals at world locations\n* @param PlayerController The Zed player controller\n* @param Locations                The world locations\n* @param Depths                   The out depths\n* @param Distances                The out distances from the camera\n* @param Normals                  The out Normals\n* @return                                 The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthsAndNormalsAtWorldLocations", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::ZEDFunctionLibrary_eventGetDepthsAndNormalsAtWorldLocations_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector2D> ScreenPositions;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<FVector> WorldDirections;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPositions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPositions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ScreenPositions;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldDirections_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_WorldDirections;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions_Inner = { "ScreenPositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions = { "ScreenPositions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms, ScreenPositions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_WorldDirections_Inner = { "WorldDirections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_WorldDirections = { "WorldDirections", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms, WorldDirections), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ScreenPositions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_WorldDirections_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_WorldDirections,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depths at screen positions\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPositions  The screen positions\n\x09 * @param Depths\x09\x09   The out depths at the screen position\n\x09 * @param Distances\x09\x09   The out distances from the camera\n\x09 * @param WorldDirections  The direction vectors from the camera\n\x09 * @return\x09\x09\x09\x09   The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetDepthsAtScreenPositions" },
		{ "Keywords", "get zed depths screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depths at screen positions\n* @param PlayerController The Zed player controller\n* @param ScreenPositions  The screen positions\n* @param Depths                   The out depths at the screen position\n* @param Distances                The out distances from the camera\n* @param WorldDirections  The direction vectors from the camera\n* @return                                 The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthsAtScreenPositions", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::ZEDFunctionLibrary_eventGetDepthsAtScreenPositions_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics
	{
		struct ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the depths at world locations\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Locations\x09\x09   The world locations\n\x09 * @param Depths\x09\x09   The out depths\n\x09 * @param Distances\x09\x09   The out distances from the camera\n\x09 * @return\x09\x09\x09\x09   The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetDepthsAtWorldLocations" },
		{ "Keywords", "get zed depths world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the depths at world locations\n* @param PlayerController The Zed player controller\n* @param Locations                The world locations\n* @param Depths                   The out depths\n* @param Distances                The out distances from the camera\n* @return                                 The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetDepthsAtWorldLocations", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::ZEDFunctionLibrary_eventGetDepthsAtWorldLocations_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics
	{
		struct ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector2D ScreenPosition;
			FVector PlaneLocation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneLocation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_PlaneLocation = { "PlaneLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms, PlaneLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_PlaneLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Return the world location of a plane if it exist\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPosition   The screen position\n\x09 * @param PlaneLocation\x09   The out plane world location\n\x09 */" },
		{ "DisplayName", "GetFloorPlaneAtScreenPosition" },
		{ "Keywords", "Find floor plane at screen position" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Return the world location of a plane if it exist\n* @param PlayerController The Zed player controller\n* @param ScreenPosition   The screen position\n* @param PlaneLocation    The out plane world location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetFloorPlaneAtScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::ZEDFunctionLibrary_eventGetFloorPlaneAtScreenPosition_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector WorldLocation;
			FVector PlaneLocation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PlaneLocation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_WorldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_WorldLocation_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_PlaneLocation = { "PlaneLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms, PlaneLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_WorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_PlaneLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Return the world location of a plane if it exist\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param WorldLocation    The world location\n\x09 * @param PlaneLocation\x09   The out plane world location\n\x09 */" },
		{ "DisplayName", "GetFloorPlaneAtWorldLocation" },
		{ "Keywords", "Find floor plane at world location" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Return the world location of a plane if it exist\n* @param PlayerController The Zed player controller\n* @param WorldLocation    The world location\n* @param PlaneLocation    The out plane world location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetFloorPlaneAtWorldLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::ZEDFunctionLibrary_eventGetFloorPlaneAtWorldLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics
	{
		struct ZEDFunctionLibrary_eventGetNormalAtScreenPosition_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector2D ScreenPosition;
			FVector Normal;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtScreenPosition_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtScreenPosition_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtScreenPosition_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtScreenPosition_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the normal at screen position\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPosition   The screen position\n\x09 * @param Normal\x09\x09   The out normal\n\x09 * @return                 The retrieve result\n\x09 */" },
		{ "DisplayName", "GetNormalAtScreenPosition" },
		{ "Keywords", "get zed normal screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the normal at screen position\n* @param PlayerController The Zed player controller\n* @param ScreenPosition   The screen position\n* @param Normal                   The out normal\n* @return                 The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetNormalAtScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::ZEDFunctionLibrary_eventGetNormalAtScreenPosition_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetNormalAtWorldLocation_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector Location;
			FVector Normal;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtWorldLocation_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtWorldLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtWorldLocation_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalAtWorldLocation_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the normal at world location\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Location\x09\x09   The world location\n\x09 * @param Normal\x09\x09   The out normal\n\x09 * @return                 The retrieve result\n\x09 */" },
		{ "DisplayName", "GetNormalAtWorldLocation" },
		{ "Keywords", "get zed normal world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the normal at world location\n* @param PlayerController The Zed player controller\n* @param Location                 The world location\n* @param Normal                   The out normal\n* @return                 The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetNormalAtWorldLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::ZEDFunctionLibrary_eventGetNormalAtWorldLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics
	{
		struct ZEDFunctionLibrary_eventGetNormalsAtScreenPositions_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector2D> ScreenPositions;
			TArray<FVector> Normals;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPositions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPositions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ScreenPositions;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtScreenPositions_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_Inner = { "ScreenPositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions = { "ScreenPositions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtScreenPositions_Parms, ScreenPositions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtScreenPositions_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtScreenPositions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ScreenPositions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the normals at screen positions\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param ScreenPositions  The screen positions\n\x09 * @param Normals\x09\x09   The out normals at the screen position\n\x09 * @return\x09\x09\x09\x09   The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetNormalsAtScreenPositions" },
		{ "Keywords", "get zed normals screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the normals at screen positions\n* @param PlayerController The Zed player controller\n* @param ScreenPositions  The screen positions\n* @param Normals                  The out normals at the screen position\n* @return                                 The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetNormalsAtScreenPositions", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::ZEDFunctionLibrary_eventGetNormalsAtScreenPositions_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics
	{
		struct ZEDFunctionLibrary_eventGetNormalsAtWorldLocations_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<FVector> Normals;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtWorldLocations_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtWorldLocations_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtWorldLocations_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetNormalsAtWorldLocations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the normals at world locations\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Locations\x09\x09   The world locations\n\x09 * @param Normals\x09\x09   The out depths\n\x09 * @return\x09\x09\x09\x09   The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetNormalsAtWorldLocations" },
		{ "Keywords", "get zed normals world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the normals at world locations\n* @param PlayerController The Zed player controller\n* @param Locations                The world locations\n* @param Normals                  The out depths\n* @return                                 The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetNormalsAtWorldLocations", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::ZEDFunctionLibrary_eventGetNormalsAtWorldLocations_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector2D ScreenPosition;
			FVector PixelWorldLocation;
			float Depth;
			float Distance;
			FVector Normal;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelWorldLocation;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_PixelWorldLocation = { "PixelWorldLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, PixelWorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_PixelWorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location and normal of a pixel\n\x09 * @param PlayerController   The Zed player controller\n\x09 * @param ScreenPosition     The screen position\n\x09 * @param PixelWorldLocation The out world location\n\x09 * @param Depth\x09\x09\x09\x09 The out depth\n\x09 * @param Distance\x09\x09\x09 The out distance from the camera\n\x09 * @param Normal\x09\x09\x09 The out normal\n\x09 * @return                   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetPixelLocationAndNormalAtScreenPosition" },
		{ "Keywords", "get zed pixel location normal screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location and normal of a pixel\n* @param PlayerController   The Zed player controller\n* @param ScreenPosition     The screen position\n* @param PixelWorldLocation The out world location\n* @param Depth                          The out depth\n* @param Distance                       The out distance from the camera\n* @param Normal                         The out normal\n* @return                   The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelLocationAndNormalAtScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtScreenPosition_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector Location;
			FVector PixelWorldLocation;
			float Depth;
			float Distance;
			FVector Normal;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelWorldLocation;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_PixelWorldLocation = { "PixelWorldLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, PixelWorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_PixelWorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location and normal of a pixel\n\x09 * @param PlayerController   The Zed player controller\n\x09 * @param Location           The world location\n\x09 * @param PixelWorldLocation The out world location\n\x09 * @param Depth\x09\x09\x09\x09 The out depth\n\x09 * @param Distance\x09\x09\x09 The out distance from the camera\n\x09 * @param Normal\x09\x09\x09 The out normal\n\x09 * @return                   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetPixelLocationAndNormalAtWorldLocation" },
		{ "Keywords", "get zed pixel location normal world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location and normal of a pixel\n* @param PlayerController   The Zed player controller\n* @param Location           The world location\n* @param PixelWorldLocation The out world location\n* @param Depth                          The out depth\n* @param Distance                       The out distance from the camera\n* @param Normal                         The out normal\n* @return                   The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelLocationAndNormalAtWorldLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::ZEDFunctionLibrary_eventGetPixelLocationAndNormalAtWorldLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector2D ScreenPosition;
			FVector PixelWorldLocation;
			float Depth;
			float Distance;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelWorldLocation;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_PixelWorldLocation = { "PixelWorldLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms, PixelWorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_PixelWorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location of a pixel\n\x09 * @param PlayerController   The Zed player controller\n\x09 * @param ScreenPosition     The screen position\n\x09 * @param PixelWorldLocation The out world location\n\x09 * @param Depth\x09\x09\x09\x09 The out depth\n\x09 * @param Distance\x09\x09\x09 The out distance from the camera\n\x09 * @return                   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetPixelLocationAtScreenPosition" },
		{ "Keywords", "get zed pixel location screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location of a pixel\n* @param PlayerController   The Zed player controller\n* @param ScreenPosition     The screen position\n* @param PixelWorldLocation The out world location\n* @param Depth                          The out depth\n* @param Distance                       The out distance from the camera\n* @return                   The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelLocationAtScreenPosition", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::ZEDFunctionLibrary_eventGetPixelLocationAtScreenPosition_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector Location;
			FVector PixelWorldLocation;
			float Depth;
			float Distance;
			ESlRetrieveResult ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelWorldLocation;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_PixelWorldLocation = { "PixelWorldLocation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms, PixelWorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_PixelWorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location of a pixel\n\x09 * @param PlayerController   The Zed player controller\n\x09 * @param Location           The world location\n\x09 * @param PixelWorldLocation The out world location\n\x09 * @param Depth\x09\x09\x09\x09 The out depth\n\x09 * @param Distance\x09\x09\x09 The out distance from the camera\n\x09 * @return                   The retrieve result\n\x09 */" },
		{ "DisplayName", "GetPixelLocationAtWorldLocation" },
		{ "Keywords", "get zed pixel location world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location of a pixel\n* @param PlayerController   The Zed player controller\n* @param Location           The world location\n* @param PixelWorldLocation The out world location\n* @param Depth                          The out depth\n* @param Distance                       The out distance from the camera\n* @return                   The retrieve result" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelLocationAtWorldLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::ZEDFunctionLibrary_eventGetPixelLocationAtWorldLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector2D> ScreenPositions;
			TArray<FVector> PixelsWorldLocations;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<FVector> Normals;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPositions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPositions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ScreenPositions;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelsWorldLocations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PixelsWorldLocations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions_Inner = { "ScreenPositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions = { "ScreenPositions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, ScreenPositions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_PixelsWorldLocations_Inner = { "PixelsWorldLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_PixelsWorldLocations = { "PixelsWorldLocations", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, PixelsWorldLocations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ScreenPositions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_PixelsWorldLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_PixelsWorldLocations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location and normal of pixels\n\x09 * @param PlayerController    The Zed player controller\n\x09 * @param ScreenPositions      The screen positions\n\x09 * @param PixelsWorldLocations The out world locations\n\x09 * @param Depths\x09\x09\x09   The out depths\n\x09 * @param Distances\x09\x09\x09   The out distances\n\x09 * @param Normals\x09\x09\x09   The out normals\n\x09 * @return                     The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetPixelsLocationAndNormalAtScreenPositions" },
		{ "Keywords", "get zed pixels location normal screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location and normal of pixels\n* @param PlayerController    The Zed player controller\n* @param ScreenPositions      The screen positions\n* @param PixelsWorldLocations The out world locations\n* @param Depths                           The out depths\n* @param Distances                        The out distances\n* @param Normals                          The out normals\n* @return                     The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelsLocationAndNormalAtScreenPositions", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtScreenPositions_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<FVector> PixelsWorldLocations;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<FVector> Normals;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelsWorldLocations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PixelsWorldLocations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normals_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Normals;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_PixelsWorldLocations_Inner = { "PixelsWorldLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_PixelsWorldLocations = { "PixelsWorldLocations", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, PixelsWorldLocations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Normals_Inner = { "Normals", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Normals = { "Normals", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, Normals), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_PixelsWorldLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_PixelsWorldLocations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Normals_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_Normals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location and normal of pixels\n\x09 * @param PlayerController    The Zed player controller\n\x09 * @param Locations           The world locations\n\x09 * @param PixelsWorldLocation The out world locations\n\x09 * @param Depths\x09\x09\x09  The out depths\n\x09 * @param Distances\x09\x09\x09  The out distances\n\x09 * @param Normals\x09\x09\x09  The out normals\n\x09 * @return                    The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetPixelsLocationAndNormalAtWorldLocations" },
		{ "Keywords", "get zed pixels location normal world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location and normal of pixels\n* @param PlayerController    The Zed player controller\n* @param Locations           The world locations\n* @param PixelsWorldLocation The out world locations\n* @param Depths                          The out depths\n* @param Distances                       The out distances\n* @param Normals                         The out normals\n* @return                    The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelsLocationAndNormalAtWorldLocations", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::ZEDFunctionLibrary_eventGetPixelsLocationAndNormalAtWorldLocations_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector2D> ScreenPositions;
			TArray<FVector> PixelWorldLocations;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPositions_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPositions_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ScreenPositions;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelWorldLocations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PixelWorldLocations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions_Inner = { "ScreenPositions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions = { "ScreenPositions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms, ScreenPositions), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_PixelWorldLocations_Inner = { "PixelWorldLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_PixelWorldLocations = { "PixelWorldLocations", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms, PixelWorldLocations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ScreenPositions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_PixelWorldLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_PixelWorldLocations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location of pixels\n\x09 * @param PlayerController     The Zed player controller\n\x09 * @param ScreenPositions      The screen positions\n\x09 * @param PixelsWorldLocations The out world locations\n\x09 * @param Depths\x09\x09\x09   The out depths\n\x09 * @param Distances\x09\x09\x09   The out distances from camera\n\x09 * @return                     The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetPixelsLocationAtScreenPositions" },
		{ "Keywords", "get zed pixels location screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location of pixels\n* @param PlayerController     The Zed player controller\n* @param ScreenPositions      The screen positions\n* @param PixelsWorldLocations The out world locations\n* @param Depths                           The out depths\n* @param Distances                        The out distances from camera\n* @return                     The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelsLocationAtScreenPositions", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::ZEDFunctionLibrary_eventGetPixelsLocationAtScreenPositions_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics
	{
		struct ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<FVector> PixelsWorldLocations;
			TArray<float> Depths;
			TArray<float> Distances;
			TArray<ESlRetrieveResult> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PixelsWorldLocations_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PixelsWorldLocations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Depths;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distances_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Distances;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_PixelsWorldLocations_Inner = { "PixelsWorldLocations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_PixelsWorldLocations = { "PixelsWorldLocations", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms, PixelsWorldLocations), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Depths_Inner = { "Depths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Depths = { "Depths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms, Depths), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Distances_Inner = { "Distances", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Distances = { "Distances", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms, Distances), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UEnum_Stereolabs_ESlRetrieveResult, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 562540014
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_PixelsWorldLocations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_PixelsWorldLocations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Depths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Depths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Distances_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_Distances,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_ReturnValue_Inner_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Retrieve the 3D location of pixels\n\x09 * @param PlayerController     The Zed player controller\n\x09 * @param Locations            The out world locations\n\x09 * @param PixelsWorldLocations The out world location\n\x09 * @param Depths\x09\x09\x09   The out depths\n\x09 * @param Distances\x09\x09\x09   The out distances from camera\n\x09 * @return                     The array of retrieve results\n\x09 */" },
		{ "DisplayName", "GetPixelsLocationAtWorldLocations" },
		{ "Keywords", "get zed pixels location world" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the 3D location of pixels\n* @param PlayerController     The Zed player controller\n* @param Locations            The out world locations\n* @param PixelsWorldLocations The out world location\n* @param Depths                           The out depths\n* @param Distances                        The out distances from camera\n* @return                     The array of retrieve results" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPixelsLocationAtWorldLocations", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::ZEDFunctionLibrary_eventGetPixelsLocationAtWorldLocations_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics
	{
		struct ZEDFunctionLibrary_eventGetPlayerController_Parms
		{
			UObject* WorldContextObject;
			AZEDPlayerController* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPlayerController_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetPlayerController_Parms, ReturnValue), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Get Zed player controller. Can be null\n\x09 * @return The Zed player controller\n\x09 */" },
		{ "DisplayName", "GetPlayerController" },
		{ "Keywords", "get zed player controller" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Get Zed player controller. Can be null\n* @return The Zed player controller" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetPlayerController", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::ZEDFunctionLibrary_eventGetPlayerController_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetRawOrientationAndLocation_Parms
		{
			FRotator Orientation;
			FVector Location;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetRawOrientationAndLocation_Parms, Orientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetRawOrientationAndLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Get the current frame Zed rotation and location\n\x09 * @param Orientation The camera rotation\n\x09 * @param Location    The camera location\n\x09 */" },
		{ "DisplayName", "GetRawOrientationAndLocation" },
		{ "Keywords", "get zed camera orientation and location" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Get the current frame Zed rotation and location\n* @param Orientation The camera rotation\n* @param Location    The camera location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetRawOrientationAndLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::ZEDFunctionLibrary_eventGetRawOrientationAndLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics
	{
		struct ZEDFunctionLibrary_eventGetTrackingData_Parms
		{
			FZEDTrackingData ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetTrackingData_Parms, ReturnValue), Z_Construct_UScriptStruct_FZEDTrackingData, METADATA_PARAMS(nullptr, 0) }; // 2053750691
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Get the current frame tracking data\n\x09 * @param TrackingData The current Zed tracking data\n\x09 */" },
		{ "DisplayName", "GetTrackingData" },
		{ "Keywords", "get zed camera tracking data" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Get the current frame tracking data\n* @param TrackingData The current Zed tracking data" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetTrackingData", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::ZEDFunctionLibrary_eventGetTrackingData_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics
	{
		struct ZEDFunctionLibrary_eventGetViewPointOrientationAndLocation_Parms
		{
			FRotator Orientation;
			FVector Location;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetViewPointOrientationAndLocation_Parms, Orientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventGetViewPointOrientationAndLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Get the current frame view point rotation and location, head(stereo)/camera(mono)\n\x09 * @param Orientation The camera rotation\n\x09 * @param Location    The camera location\n\x09 */" },
		{ "DisplayName", "GetViewPointOrientationAndLocation" },
		{ "Keywords", "get zed camera orientation and location" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Get the current frame view point rotation and location, head(stereo)/camera(mono)\n* @param Orientation The camera rotation\n* @param Location    The camera location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "GetViewPointOrientationAndLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::ZEDFunctionLibrary_eventGetViewPointOrientationAndLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics
	{
		struct ZEDFunctionLibrary_eventHitTestReal_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector Location;
			float HitThreshold;
			bool bGetNormal;
			bool bHitIfBehind;
			FZEDHitResult HitResult;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HitThreshold;
		static void NewProp_bGetNormal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGetNormal;
		static void NewProp_bHitIfBehind_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHitIfBehind;
		static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventHitTestReal_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventHitTestReal_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_HitThreshold = { "HitThreshold", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventHitTestReal_Parms, HitThreshold), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bGetNormal_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventHitTestReal_Parms*)Obj)->bGetNormal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bGetNormal = { "bGetNormal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventHitTestReal_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bGetNormal_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bHitIfBehind_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventHitTestReal_Parms*)Obj)->bHitIfBehind = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bHitIfBehind = { "bHitIfBehind", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventHitTestReal_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bHitIfBehind_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventHitTestReal_Parms, HitResult), Z_Construct_UScriptStruct_FZEDHitResult, METADATA_PARAMS(nullptr, 0) }; // 1875529980
	void Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventHitTestReal_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventHitTestReal_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_HitThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bGetNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_bHitIfBehind,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_HitResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Test if a 3D point hit the real\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Location\x09       The 3D point location\n\x09 * @param HitThreshold     The threshold in cm to determine if a hit occurred\n\x09 * @param HitResult        The result if hit\n\x09 * @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold\n\x09 * @return\x09\x09\x09       True if the 3D point has hit, false otherwise\n\x09 */" },
		{ "DisplayName", "HitTestReal" },
		{ "Keywords", "hit test zed real" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Test if a 3D point hit the real\n* @param PlayerController The Zed player controller\n* @param Location             The 3D point location\n* @param HitThreshold     The threshold in cm to determine if a hit occurred\n* @param HitResult        The result if hit\n* @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold\n* @return                             True if the 3D point has hit, false otherwise" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "HitTestReal", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::ZEDFunctionLibrary_eventHitTestReal_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics
	{
		struct ZEDFunctionLibrary_eventIsLocationInScreenBounds_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector WorldLocation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsLocationInScreenBounds_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsLocationInScreenBounds_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_WorldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_WorldLocation_MetaData)) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventIsLocationInScreenBounds_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventIsLocationInScreenBounds_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_WorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Test if a 3D location is in screen bounds\n\x09 * @param PlayerController The player controller\n\x09 * @param WorldLocation    The 3D location\n\x09 * @return                 True if the location is in screen bounds, false otherwise\n\x09 */" },
		{ "DisplayName", "IsLocationInScreenBounds" },
		{ "Keywords", "is location on zed screen" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Test if a 3D location is in screen bounds\n* @param PlayerController The player controller\n* @param WorldLocation    The 3D location\n* @return                 True if the location is in screen bounds, false otherwise" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "IsLocationInScreenBounds", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::ZEDFunctionLibrary_eventIsLocationInScreenBounds_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics
	{
		struct ZEDFunctionLibrary_eventIsLocationVisible_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector WorldLocation;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsLocationVisible_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsLocationVisible_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_WorldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_WorldLocation_MetaData)) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventIsLocationVisible_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventIsLocationVisible_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_WorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Test if a 3D location is visible\n\x09 * @param PlayerController The Eed player controller\n\x09 * @param WorldLocation    The 3D location\n\x09 * @return                 True if the location is visible, false otherwise\n\x09 */" },
		{ "DisplayName", "IsLocationVisible" },
		{ "Keywords", "is location visible by zed" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Test if a 3D location is visible\n* @param PlayerController The Eed player controller\n* @param WorldLocation    The 3D location\n* @return                 True if the location is visible, false otherwise" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "IsLocationVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::ZEDFunctionLibrary_eventIsLocationVisible_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics
	{
		struct ZEDFunctionLibrary_eventIsVisible_Parms
		{
			AZEDPlayerController* PlayerController;
			FVector WorldLocation;
			FVector2D ScreenPosition;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_WorldLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsVisible_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_WorldLocation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_WorldLocation = { "WorldLocation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsVisible_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_WorldLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_WorldLocation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventIsVisible_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ScreenPosition_MetaData)) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventIsVisible_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventIsVisible_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_WorldLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Test if a 3D location and associated 2D screen position is visible\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param WorldLocation    The 3D location\n\x09 * @param ScreenPosition   The 2D screen position\n\x09 * @return                 True if the location is visible, false otherwise\n\x09 */" },
		{ "DisplayName", "IsVisible" },
		{ "Keywords", "is visible zed" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Test if a 3D location and associated 2D screen position is visible\n* @param PlayerController The Zed player controller\n* @param WorldLocation    The 3D location\n* @param ScreenPosition   The 2D screen position\n* @return                 True if the location is visible, false otherwise" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "IsVisible", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::ZEDFunctionLibrary_eventIsVisible_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics
	{
		struct ZEDFunctionLibrary_eventLatencyCorrectorAddOffset_Parms
		{
			int32 offset;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_offset_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_offset;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::NewProp_offset_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::NewProp_offset = { "offset", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventLatencyCorrectorAddOffset_Parms, offset), METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::NewProp_offset_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::NewProp_offset_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::NewProp_offset,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Latency" },
		{ "Comment", "/*\n\x09* Add latency corrector offset\n\x09*/" },
		{ "DisplayName", "AddLatencyOffset" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Add latency corrector offset" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "LatencyCorrectorAddOffset", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::ZEDFunctionLibrary_eventLatencyCorrectorAddOffset_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics
	{
		struct ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<float> HitThresholds;
			bool bGetNormal;
			bool bHitIfBehind;
			TArray<FZEDHitResult> HitResults;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HitThresholds_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitThresholds_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_HitThresholds;
		static void NewProp_bGetNormal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGetNormal;
		static void NewProp_bHitIfBehind_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHitIfBehind;
		static const UECodeGen_Private::FStructPropertyParams NewProp_HitResults_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_HitResults;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds_Inner = { "HitThresholds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds = { "HitThresholds", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms, HitThresholds), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds_MetaData)) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bGetNormal_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms*)Obj)->bGetNormal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bGetNormal = { "bGetNormal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bGetNormal_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bHitIfBehind_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms*)Obj)->bHitIfBehind = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bHitIfBehind = { "bHitIfBehind", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bHitIfBehind_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitResults_Inner = { "HitResults", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FZEDHitResult, METADATA_PARAMS(nullptr, 0) }; // 1875529980
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitResults = { "HitResults", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms, HitResults), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) }; // 1875529980
	void Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitThresholds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bGetNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_bHitIfBehind,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitResults_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_HitResults,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Test if multiple 3D points hit the real\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Location\x09       The 3D point location\n\x09 * @param HitThresholds    The thresholds in cm to determine if a hit occurred\n\x09 * @param HitResults\x09   The result of all hits\n\x09 * @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold\n\x09 * @return\x09\x09\x09       True if at least one 3D point has hit, false otherwise\n\x09 */" },
		{ "DisplayName", "MultipleHitTestsReal" },
		{ "Keywords", "has hit zed depths" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Test if multiple 3D points hit the real\n* @param PlayerController The Zed player controller\n* @param Location             The 3D point location\n* @param HitThresholds    The thresholds in cm to determine if a hit occurred\n* @param HitResults       The result of all hits\n* @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold\n* @return                             True if at least one 3D point has hit, false otherwise" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "MultipleHitTestsReal", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::ZEDFunctionLibrary_eventMultipleHitTestsReal_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics
	{
		struct ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms
		{
			AZEDPlayerController* PlayerController;
			TArray<FVector> Locations;
			TArray<float> HitThresholds;
			bool bGetNormal;
			bool bHitIfBehind;
			FZEDHitResult HitResult;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Locations_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Locations_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Locations;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HitThresholds_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HitThresholds_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_HitThresholds;
		static void NewProp_bGetNormal_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bGetNormal;
		static void NewProp_bHitIfBehind_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHitIfBehind;
		static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_PlayerController = { "PlayerController", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms, PlayerController), Z_Construct_UClass_AZEDPlayerController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations_Inner = { "Locations", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations = { "Locations", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms, Locations), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds_Inner = { "HitThresholds", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds = { "HitThresholds", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms, HitThresholds), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds_MetaData)) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bGetNormal_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms*)Obj)->bGetNormal = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bGetNormal = { "bGetNormal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bGetNormal_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bHitIfBehind_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms*)Obj)->bHitIfBehind = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bHitIfBehind = { "bHitIfBehind", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bHitIfBehind_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms, HitResult), Z_Construct_UScriptStruct_FZEDHitResult, METADATA_PARAMS(nullptr, 0) }; // 1875529980
	void Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms), &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_PlayerController,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_Locations,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitThresholds,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bGetNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_bHitIfBehind,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_HitResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09 * Test if multiple 3D points hit the real, exit on first hit\n\x09 * @param PlayerController The Zed player controller\n\x09 * @param Location\x09       The 3D point location\n\x09 * @param HitThreshold     The threshold in cm to determine if a hit occurred\n\x09 * @param HitResult\x09       The result of the first hit\n\x09 * @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold\n\x09 * @return\x09\x09\x09       True if one 3D point has hit, false otherwise\n\x09 */" },
		{ "DisplayName", "MultipleHitTestsRealOneResult" },
		{ "Keywords", "has hit zed depths" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Test if multiple 3D points hit the real, exit on first hit\n* @param PlayerController The Zed player controller\n* @param Location             The 3D point location\n* @param HitThreshold     The threshold in cm to determine if a hit occurred\n* @param HitResult            The result of the first hit\n* @param HitIfBehind      True if 3D point hit if behind the real even if distance is greater than the threshold\n* @return                             True if one 3D point has hit, false otherwise" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "MultipleHitTestsRealOneResult", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::ZEDFunctionLibrary_eventMultipleHitTestsRealOneResult_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics
	{
		struct ZEDFunctionLibrary_eventSetRawOrientationAndLocation_Parms
		{
			FRotator Orientation;
			FVector Location;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Orientation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventSetRawOrientationAndLocation_Parms, Orientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Orientation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Orientation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventSetRawOrientationAndLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09* Get the current frame Zed rotation and location\n\x09* @param Orientation The camera rotation\n\x09* @param Location    The camera location\n\x09*/" },
		{ "DisplayName", "SetRawOrientationAndLocation" },
		{ "Keywords", "set zed camera orientation and location" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Get the current frame Zed rotation and location\n* @param Orientation The camera rotation\n* @param Location    The camera location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "SetRawOrientationAndLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::ZEDFunctionLibrary_eventSetRawOrientationAndLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics
	{
		struct ZEDFunctionLibrary_eventSetViewPointOrientationAndLocation_Parms
		{
			FRotator Orientation;
			FVector Location;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Orientation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Orientation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventSetViewPointOrientationAndLocation_Parms, Orientation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Orientation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Orientation_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDFunctionLibrary_eventSetViewPointOrientationAndLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Location_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Orientation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n\x09* Get the current frame view point rotation and location, head(stereo)/camera(mono)\n\x09* @param Orientation The camera rotation\n\x09* @param Location    The camera location\n\x09*/" },
		{ "DisplayName", "SetViewPointOrientationAndLocation" },
		{ "Keywords", "set zed camera orientation and location" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
		{ "ToolTip", "* Get the current frame view point rotation and location, head(stereo)/camera(mono)\n* @param Orientation The camera rotation\n* @param Location    The camera location" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDFunctionLibrary, nullptr, "SetViewPointOrientationAndLocation", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::ZEDFunctionLibrary_eventSetViewPointOrientationAndLocation_Parms), Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZEDFunctionLibrary);
	UClass* Z_Construct_UClass_UZEDFunctionLibrary_NoRegister()
	{
		return UZEDFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UZEDFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZEDFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UZEDFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorHit, "CreateMeshFromFloorHit" }, // 2471238454
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_CreateMeshFromFloorPlane, "CreateMeshFromFloorPlane" }, // 501961947
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetCameraActor, "GetCameraActor" }, // 2722230439
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetCenteredLocationInFrontOfPlayer, "GetCenteredLocationInFrontOfPlayer" }, // 2431208493
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetCustomLocationInFrontOfPlayer, "GetCustomLocationInFrontOfPlayer" }, // 2457365712
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtScreenPosition, "GetDepthAndNormalAtScreenPosition" }, // 656397831
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAndNormalAtWorldLocation, "GetDepthAndNormalAtWorldLocation" }, // 3049541310
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtScreenPosition, "GetDepthAtScreenPosition" }, // 43537075
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthAtWorldLocation, "GetDepthAtWorldLocation" }, // 1236412092
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtScreenPositions, "GetDepthsAndNormalsAtScreenPositions" }, // 624868020
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAndNormalsAtWorldLocations, "GetDepthsAndNormalsAtWorldLocations" }, // 2663721732
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtScreenPositions, "GetDepthsAtScreenPositions" }, // 3315222885
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetDepthsAtWorldLocations, "GetDepthsAtWorldLocations" }, // 1172630078
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtScreenPosition, "GetFloorPlaneAtScreenPosition" }, // 1111639840
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetFloorPlaneAtWorldLocation, "GetFloorPlaneAtWorldLocation" }, // 3587829379
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtScreenPosition, "GetNormalAtScreenPosition" }, // 1568554570
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalAtWorldLocation, "GetNormalAtWorldLocation" }, // 3355140194
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtScreenPositions, "GetNormalsAtScreenPositions" }, // 2782068808
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetNormalsAtWorldLocations, "GetNormalsAtWorldLocations" }, // 3270974690
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtScreenPosition, "GetPixelLocationAndNormalAtScreenPosition" }, // 1930176762
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAndNormalAtWorldLocation, "GetPixelLocationAndNormalAtWorldLocation" }, // 2429918069
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtScreenPosition, "GetPixelLocationAtScreenPosition" }, // 342917642
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelLocationAtWorldLocation, "GetPixelLocationAtWorldLocation" }, // 220595122
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtScreenPositions, "GetPixelsLocationAndNormalAtScreenPositions" }, // 777174071
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAndNormalAtWorldLocations, "GetPixelsLocationAndNormalAtWorldLocations" }, // 3347712339
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtScreenPositions, "GetPixelsLocationAtScreenPositions" }, // 3615791326
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPixelsLocationAtWorldLocations, "GetPixelsLocationAtWorldLocations" }, // 1896952435
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetPlayerController, "GetPlayerController" }, // 869497148
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetRawOrientationAndLocation, "GetRawOrientationAndLocation" }, // 1764253329
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetTrackingData, "GetTrackingData" }, // 1685104304
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_GetViewPointOrientationAndLocation, "GetViewPointOrientationAndLocation" }, // 341707120
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_HitTestReal, "HitTestReal" }, // 3170535127
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationInScreenBounds, "IsLocationInScreenBounds" }, // 3092674979
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_IsLocationVisible, "IsLocationVisible" }, // 599542274
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_IsVisible, "IsVisible" }, // 2500495875
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_LatencyCorrectorAddOffset, "LatencyCorrectorAddOffset" }, // 1982276240
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsReal, "MultipleHitTestsReal" }, // 3886335945
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_MultipleHitTestsRealOneResult, "MultipleHitTestsRealOneResult" }, // 1517879717
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_SetRawOrientationAndLocation, "SetRawOrientationAndLocation" }, // 644005896
		{ &Z_Construct_UFunction_UZEDFunctionLibrary_SetViewPointOrientationAndLocation, "SetViewPointOrientationAndLocation" }, // 230210232
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Utilities/ZEDFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/Utilities/ZEDFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZEDFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZEDFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZEDFunctionLibrary_Statics::ClassParams = {
		&UZEDFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UZEDFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZEDFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UZEDFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZEDFunctionLibrary.OuterSingleton, Z_Construct_UClass_UZEDFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZEDFunctionLibrary.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<UZEDFunctionLibrary>()
	{
		return UZEDFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZEDFunctionLibrary);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZEDFunctionLibrary, UZEDFunctionLibrary::StaticClass, TEXT("UZEDFunctionLibrary"), &Z_Registration_Info_UClass_UZEDFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZEDFunctionLibrary), 72636018U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_1375393252(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
