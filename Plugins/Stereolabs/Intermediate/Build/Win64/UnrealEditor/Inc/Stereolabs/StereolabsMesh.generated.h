// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESlMeshFileFormat : uint8;
struct FSlMeshFilterParameters;
#ifdef STEREOLABS_StereolabsMesh_generated_h
#error "StereolabsMesh.generated.h already included, missing '#pragma once' in StereolabsMesh.h"
#endif
#define STEREOLABS_StereolabsMesh_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execClear); \
	DECLARE_FUNCTION(execLoad); \
	DECLARE_FUNCTION(execSave); \
	DECLARE_FUNCTION(execApplyTexture); \
	DECLARE_FUNCTION(execFilter); \
	DECLARE_FUNCTION(execUpdateMeshData);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClear); \
	DECLARE_FUNCTION(execLoad); \
	DECLARE_FUNCTION(execSave); \
	DECLARE_FUNCTION(execApplyTexture); \
	DECLARE_FUNCTION(execFilter); \
	DECLARE_FUNCTION(execUpdateMeshData);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlMesh(); \
	friend struct Z_Construct_UClass_USlMesh_Statics; \
public: \
	DECLARE_CLASS(USlMesh, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlMesh)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUSlMesh(); \
	friend struct Z_Construct_UClass_USlMesh_Statics; \
public: \
	DECLARE_CLASS(USlMesh, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlMesh)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlMesh(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlMesh) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlMesh); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlMesh); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlMesh(USlMesh&&); \
	NO_API USlMesh(const USlMesh&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlMesh(USlMesh&&); \
	NO_API USlMesh(const USlMesh&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlMesh); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlMesh); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlMesh)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_17_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlMesh>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
