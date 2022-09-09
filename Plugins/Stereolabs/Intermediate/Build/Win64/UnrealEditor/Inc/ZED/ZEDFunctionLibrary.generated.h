// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSlMeshData;
class AZEDPlayerController;
struct FIntPoint;
struct FZEDHitResult;
enum class ESlRetrieveResult : uint8;
class UObject;
class AZEDCamera;
struct FZEDTrackingData;
#ifdef ZED_ZEDFunctionLibrary_generated_h
#error "ZEDFunctionLibrary.generated.h already included, missing '#pragma once' in ZEDFunctionLibrary.h"
#endif
#define ZED_ZEDFunctionLibrary_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLatencyCorrectorAddOffset); \
	DECLARE_FUNCTION(execCreateMeshFromFloorPlane); \
	DECLARE_FUNCTION(execCreateMeshFromFloorHit); \
	DECLARE_FUNCTION(execGetFloorPlaneAtWorldLocation); \
	DECLARE_FUNCTION(execGetFloorPlaneAtScreenPosition); \
	DECLARE_FUNCTION(execMultipleHitTestsRealOneResult); \
	DECLARE_FUNCTION(execMultipleHitTestsReal); \
	DECLARE_FUNCTION(execHitTestReal); \
	DECLARE_FUNCTION(execGetPixelsLocationAndNormalAtWorldLocations); \
	DECLARE_FUNCTION(execGetPixelsLocationAndNormalAtScreenPositions); \
	DECLARE_FUNCTION(execGetPixelsLocationAtWorldLocations); \
	DECLARE_FUNCTION(execGetPixelsLocationAtScreenPositions); \
	DECLARE_FUNCTION(execGetPixelLocationAndNormalAtWorldLocation); \
	DECLARE_FUNCTION(execGetPixelLocationAndNormalAtScreenPosition); \
	DECLARE_FUNCTION(execGetPixelLocationAtWorldLocation); \
	DECLARE_FUNCTION(execGetPixelLocationAtScreenPosition); \
	DECLARE_FUNCTION(execGetDepthsAndNormalsAtWorldLocations); \
	DECLARE_FUNCTION(execGetDepthsAndNormalsAtScreenPositions); \
	DECLARE_FUNCTION(execGetNormalsAtWorldLocations); \
	DECLARE_FUNCTION(execGetNormalsAtScreenPositions); \
	DECLARE_FUNCTION(execGetDepthsAtWorldLocations); \
	DECLARE_FUNCTION(execGetDepthsAtScreenPositions); \
	DECLARE_FUNCTION(execGetDepthAndNormalAtWorldLocation); \
	DECLARE_FUNCTION(execGetDepthAndNormalAtScreenPosition); \
	DECLARE_FUNCTION(execGetNormalAtWorldLocation); \
	DECLARE_FUNCTION(execGetNormalAtScreenPosition); \
	DECLARE_FUNCTION(execGetDepthAtWorldLocation); \
	DECLARE_FUNCTION(execGetDepthAtScreenPosition); \
	DECLARE_FUNCTION(execIsVisible); \
	DECLARE_FUNCTION(execIsLocationVisible); \
	DECLARE_FUNCTION(execIsLocationInScreenBounds); \
	DECLARE_FUNCTION(execGetCustomLocationInFrontOfPlayer); \
	DECLARE_FUNCTION(execGetCenteredLocationInFrontOfPlayer); \
	DECLARE_FUNCTION(execGetCameraActor); \
	DECLARE_FUNCTION(execGetPlayerController); \
	DECLARE_FUNCTION(execSetViewPointOrientationAndLocation); \
	DECLARE_FUNCTION(execSetRawOrientationAndLocation); \
	DECLARE_FUNCTION(execGetViewPointOrientationAndLocation); \
	DECLARE_FUNCTION(execGetRawOrientationAndLocation); \
	DECLARE_FUNCTION(execGetTrackingData);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLatencyCorrectorAddOffset); \
	DECLARE_FUNCTION(execCreateMeshFromFloorPlane); \
	DECLARE_FUNCTION(execCreateMeshFromFloorHit); \
	DECLARE_FUNCTION(execGetFloorPlaneAtWorldLocation); \
	DECLARE_FUNCTION(execGetFloorPlaneAtScreenPosition); \
	DECLARE_FUNCTION(execMultipleHitTestsRealOneResult); \
	DECLARE_FUNCTION(execMultipleHitTestsReal); \
	DECLARE_FUNCTION(execHitTestReal); \
	DECLARE_FUNCTION(execGetPixelsLocationAndNormalAtWorldLocations); \
	DECLARE_FUNCTION(execGetPixelsLocationAndNormalAtScreenPositions); \
	DECLARE_FUNCTION(execGetPixelsLocationAtWorldLocations); \
	DECLARE_FUNCTION(execGetPixelsLocationAtScreenPositions); \
	DECLARE_FUNCTION(execGetPixelLocationAndNormalAtWorldLocation); \
	DECLARE_FUNCTION(execGetPixelLocationAndNormalAtScreenPosition); \
	DECLARE_FUNCTION(execGetPixelLocationAtWorldLocation); \
	DECLARE_FUNCTION(execGetPixelLocationAtScreenPosition); \
	DECLARE_FUNCTION(execGetDepthsAndNormalsAtWorldLocations); \
	DECLARE_FUNCTION(execGetDepthsAndNormalsAtScreenPositions); \
	DECLARE_FUNCTION(execGetNormalsAtWorldLocations); \
	DECLARE_FUNCTION(execGetNormalsAtScreenPositions); \
	DECLARE_FUNCTION(execGetDepthsAtWorldLocations); \
	DECLARE_FUNCTION(execGetDepthsAtScreenPositions); \
	DECLARE_FUNCTION(execGetDepthAndNormalAtWorldLocation); \
	DECLARE_FUNCTION(execGetDepthAndNormalAtScreenPosition); \
	DECLARE_FUNCTION(execGetNormalAtWorldLocation); \
	DECLARE_FUNCTION(execGetNormalAtScreenPosition); \
	DECLARE_FUNCTION(execGetDepthAtWorldLocation); \
	DECLARE_FUNCTION(execGetDepthAtScreenPosition); \
	DECLARE_FUNCTION(execIsVisible); \
	DECLARE_FUNCTION(execIsLocationVisible); \
	DECLARE_FUNCTION(execIsLocationInScreenBounds); \
	DECLARE_FUNCTION(execGetCustomLocationInFrontOfPlayer); \
	DECLARE_FUNCTION(execGetCenteredLocationInFrontOfPlayer); \
	DECLARE_FUNCTION(execGetCameraActor); \
	DECLARE_FUNCTION(execGetPlayerController); \
	DECLARE_FUNCTION(execSetViewPointOrientationAndLocation); \
	DECLARE_FUNCTION(execSetRawOrientationAndLocation); \
	DECLARE_FUNCTION(execGetViewPointOrientationAndLocation); \
	DECLARE_FUNCTION(execGetRawOrientationAndLocation); \
	DECLARE_FUNCTION(execGetTrackingData);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUZEDFunctionLibrary(); \
	friend struct Z_Construct_UClass_UZEDFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UZEDFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(UZEDFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUZEDFunctionLibrary(); \
	friend struct Z_Construct_UClass_UZEDFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(UZEDFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(UZEDFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UZEDFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UZEDFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZEDFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZEDFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UZEDFunctionLibrary(UZEDFunctionLibrary&&); \
	NO_API UZEDFunctionLibrary(const UZEDFunctionLibrary&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UZEDFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UZEDFunctionLibrary(UZEDFunctionLibrary&&); \
	NO_API UZEDFunctionLibrary(const UZEDFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZEDFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZEDFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UZEDFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_17_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class UZEDFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Utilities_ZEDFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
