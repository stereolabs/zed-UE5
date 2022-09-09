// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
struct FSlTimestamp;
struct FSlMeshData;
struct FSlSpatialMappingParameters;
enum class ESlSpatialMappingRange : uint8;
enum class ESlSpatialMappingResolution : uint8;
enum class ESlErrorCode : uint8;
enum class ESlEye : uint8;
struct FIntPoint;
class UObject;
struct FSlCameraParameters;
struct FSlViewportHelper;
class USlCameraProxy;
#ifdef STEREOLABS_StereolabsFunctionLibrary_generated_h
#error "StereolabsFunctionLibrary.generated.h already included, missing '#pragma once' in StereolabsFunctionLibrary.h"
#endif
#define STEREOLABS_StereolabsFunctionLibrary_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetHmdFocale); \
	DECLARE_FUNCTION(execGenerateTextureFromTxtFile); \
	DECLARE_FUNCTION(execSubstract_TimestampTimestamp); \
	DECLARE_FUNCTION(execAdd_TimestampTimestamp); \
	DECLARE_FUNCTION(execGreaterEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execGreater_TimestampTimestamp); \
	DECLARE_FUNCTION(execLessEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execLess_TimestampTimestamp); \
	DECLARE_FUNCTION(execNotEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execEqualEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execConv_TimestampToString); \
	DECLARE_FUNCTION(execClearMeshData); \
	DECLARE_FUNCTION(execSetMaxRangeValue); \
	DECLARE_FUNCTION(execSetMaxRangePreset); \
	DECLARE_FUNCTION(execSetResolutionValue); \
	DECLARE_FUNCTION(execSetResolutionPreset); \
	DECLARE_FUNCTION(execErrorCodeToString); \
	DECLARE_FUNCTION(execGetSceneCaptureProjectionMatrix); \
	DECLARE_FUNCTION(execGetOffCenterProjectionOffset); \
	DECLARE_FUNCTION(execGetOpticalCentersOffsets); \
	DECLARE_FUNCTION(execGetRenderPlaneSizeWithGamma); \
	DECLARE_FUNCTION(execGetRenderPlaneSize); \
	DECLARE_FUNCTION(execConvertCustomDepthToDistance); \
	DECLARE_FUNCTION(execConvertDepthToDistance); \
	DECLARE_FUNCTION(execIsInGrabThread); \
	DECLARE_FUNCTION(execGetCameraProxy);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetHmdFocale); \
	DECLARE_FUNCTION(execGenerateTextureFromTxtFile); \
	DECLARE_FUNCTION(execSubstract_TimestampTimestamp); \
	DECLARE_FUNCTION(execAdd_TimestampTimestamp); \
	DECLARE_FUNCTION(execGreaterEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execGreater_TimestampTimestamp); \
	DECLARE_FUNCTION(execLessEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execLess_TimestampTimestamp); \
	DECLARE_FUNCTION(execNotEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execEqualEqual_TimestampTimestamp); \
	DECLARE_FUNCTION(execConv_TimestampToString); \
	DECLARE_FUNCTION(execClearMeshData); \
	DECLARE_FUNCTION(execSetMaxRangeValue); \
	DECLARE_FUNCTION(execSetMaxRangePreset); \
	DECLARE_FUNCTION(execSetResolutionValue); \
	DECLARE_FUNCTION(execSetResolutionPreset); \
	DECLARE_FUNCTION(execErrorCodeToString); \
	DECLARE_FUNCTION(execGetSceneCaptureProjectionMatrix); \
	DECLARE_FUNCTION(execGetOffCenterProjectionOffset); \
	DECLARE_FUNCTION(execGetOpticalCentersOffsets); \
	DECLARE_FUNCTION(execGetRenderPlaneSizeWithGamma); \
	DECLARE_FUNCTION(execGetRenderPlaneSize); \
	DECLARE_FUNCTION(execConvertCustomDepthToDistance); \
	DECLARE_FUNCTION(execConvertDepthToDistance); \
	DECLARE_FUNCTION(execIsInGrabThread); \
	DECLARE_FUNCTION(execGetCameraProxy);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlFunctionLibrary(); \
	friend struct Z_Construct_UClass_USlFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USlFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUSlFunctionLibrary(); \
	friend struct Z_Construct_UClass_USlFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USlFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlFunctionLibrary(USlFunctionLibrary&&); \
	NO_API USlFunctionLibrary(const USlFunctionLibrary&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlFunctionLibrary(USlFunctionLibrary&&); \
	NO_API USlFunctionLibrary(const USlFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_15_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
