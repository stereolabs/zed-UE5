// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTextureCube;
class UTextureRenderTargetCube;
#ifdef SPATIALMAPPING_SpatialMappingCubemapManager_generated_h
#error "SpatialMappingCubemapManager.generated.h already included, missing '#pragma once' in SpatialMappingCubemapManager.h"
#endif
#define SPATIALMAPPING_SpatialMappingCubemapManager_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_22_DELEGATE \
struct _Script_SpatialMapping_eventSpatialMappingCubemapDelegate_Parms \
{ \
	UTextureCube* Cubemap; \
}; \
static inline void FSpatialMappingCubemapDelegate_DelegateWrapper(const FMulticastScriptDelegate& SpatialMappingCubemapDelegate, UTextureCube* Cubemap) \
{ \
	_Script_SpatialMapping_eventSpatialMappingCubemapDelegate_Parms Parms; \
	Parms.Cubemap=Cubemap; \
	SpatialMappingCubemapDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetTextureTarget); \
	DECLARE_FUNCTION(execCaptureScene); \
	DECLARE_FUNCTION(execBuildCubemap);


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetTextureTarget); \
	DECLARE_FUNCTION(execCaptureScene); \
	DECLARE_FUNCTION(execBuildCubemap);


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpatialMappingCubemapManager(); \
	friend struct Z_Construct_UClass_ASpatialMappingCubemapManager_Statics; \
public: \
	DECLARE_CLASS(ASpatialMappingCubemapManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpatialMapping"), NO_API) \
	DECLARE_SERIALIZER(ASpatialMappingCubemapManager)


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_INCLASS \
private: \
	static void StaticRegisterNativesASpatialMappingCubemapManager(); \
	friend struct Z_Construct_UClass_ASpatialMappingCubemapManager_Statics; \
public: \
	DECLARE_CLASS(ASpatialMappingCubemapManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpatialMapping"), NO_API) \
	DECLARE_SERIALIZER(ASpatialMappingCubemapManager)


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpatialMappingCubemapManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpatialMappingCubemapManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpatialMappingCubemapManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpatialMappingCubemapManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpatialMappingCubemapManager(ASpatialMappingCubemapManager&&); \
	NO_API ASpatialMappingCubemapManager(const ASpatialMappingCubemapManager&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpatialMappingCubemapManager(ASpatialMappingCubemapManager&&); \
	NO_API ASpatialMappingCubemapManager(const ASpatialMappingCubemapManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpatialMappingCubemapManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpatialMappingCubemapManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpatialMappingCubemapManager)


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_27_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPATIALMAPPING_API UClass* StaticClass<class ASpatialMappingCubemapManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
