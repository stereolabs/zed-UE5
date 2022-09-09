// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSlMat;
enum class ESlErrorCode : uint8;
enum class ESlMemoryType : uint8;
enum class ESlMatType : uint8;
struct FIntPoint;
enum class ESlCopyType : uint8;
#ifdef STEREOLABS_StereolabsMatFunctionLibrary_generated_h
#error "StereolabsMatFunctionLibrary.generated.h already included, missing '#pragma once' in StereolabsMatFunctionLibrary.h"
#endif
#define STEREOLABS_StereolabsMatFunctionLibrary_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClone); \
	DECLARE_FUNCTION(execIsMemoryOwner); \
	DECLARE_FUNCTION(execIsInit); \
	DECLARE_FUNCTION(execGetInfos); \
	DECLARE_FUNCTION(execgetWidthBytes); \
	DECLARE_FUNCTION(execGetPixelBytes); \
	DECLARE_FUNCTION(execGetStepBytes); \
	DECLARE_FUNCTION(execGetMemoryType); \
	DECLARE_FUNCTION(execGetDataType); \
	DECLARE_FUNCTION(execGetChannels); \
	DECLARE_FUNCTION(execGetResolution); \
	DECLARE_FUNCTION(execGetHeight); \
	DECLARE_FUNCTION(execGetWidth); \
	DECLARE_FUNCTION(execWrite); \
	DECLARE_FUNCTION(execRead); \
	DECLARE_FUNCTION(execSetFrom); \
	DECLARE_FUNCTION(execCopyTo); \
	DECLARE_FUNCTION(execUpdateGPUFromCPU); \
	DECLARE_FUNCTION(execUpdateCPUFromGPU); \
	DECLARE_FUNCTION(execFree); \
	DECLARE_FUNCTION(execAllocate);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClone); \
	DECLARE_FUNCTION(execIsMemoryOwner); \
	DECLARE_FUNCTION(execIsInit); \
	DECLARE_FUNCTION(execGetInfos); \
	DECLARE_FUNCTION(execgetWidthBytes); \
	DECLARE_FUNCTION(execGetPixelBytes); \
	DECLARE_FUNCTION(execGetStepBytes); \
	DECLARE_FUNCTION(execGetMemoryType); \
	DECLARE_FUNCTION(execGetDataType); \
	DECLARE_FUNCTION(execGetChannels); \
	DECLARE_FUNCTION(execGetResolution); \
	DECLARE_FUNCTION(execGetHeight); \
	DECLARE_FUNCTION(execGetWidth); \
	DECLARE_FUNCTION(execWrite); \
	DECLARE_FUNCTION(execRead); \
	DECLARE_FUNCTION(execSetFrom); \
	DECLARE_FUNCTION(execCopyTo); \
	DECLARE_FUNCTION(execUpdateGPUFromCPU); \
	DECLARE_FUNCTION(execUpdateCPUFromGPU); \
	DECLARE_FUNCTION(execFree); \
	DECLARE_FUNCTION(execAllocate);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlMatFunctionLibrary(); \
	friend struct Z_Construct_UClass_USlMatFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USlMatFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlMatFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUSlMatFunctionLibrary(); \
	friend struct Z_Construct_UClass_USlMatFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USlMatFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlMatFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlMatFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlMatFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlMatFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlMatFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlMatFunctionLibrary(USlMatFunctionLibrary&&); \
	NO_API USlMatFunctionLibrary(const USlMatFunctionLibrary&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlMatFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlMatFunctionLibrary(USlMatFunctionLibrary&&); \
	NO_API USlMatFunctionLibrary(const USlMatFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlMatFunctionLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlMatFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlMatFunctionLibrary)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_17_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlMatFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
