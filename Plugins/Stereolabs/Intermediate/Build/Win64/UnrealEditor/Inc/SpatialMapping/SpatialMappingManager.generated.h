// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSlMeshData;
enum class ESpatialMappingStep : uint8;
enum class ESpatialMappingTexturingMode : uint8;
#ifdef SPATIALMAPPING_SpatialMappingManager_generated_h
#error "SpatialMappingManager.generated.h already included, missing '#pragma once' in SpatialMappingManager.h"
#endif
#define SPATIALMAPPING_SpatialMappingManager_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_19_DELEGATE \
struct _Script_SpatialMapping_eventSpatialMappingManagerMeshDelegate_Parms \
{ \
	FSlMeshData MeshData; \
}; \
static inline void FSpatialMappingManagerMeshDelegate_DelegateWrapper(const FMulticastScriptDelegate& SpatialMappingManagerMeshDelegate, FSlMeshData const& MeshData) \
{ \
	_Script_SpatialMapping_eventSpatialMappingManagerMeshDelegate_Parms Parms; \
	Parms.MeshData=MeshData; \
	SpatialMappingManagerMeshDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_24_DELEGATE \
static inline void FSpatialMappingManagerDelegate_DelegateWrapper(const FMulticastScriptDelegate& SpatialMappingManagerDelegate) \
{ \
	SpatialMappingManagerDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_29_DELEGATE \
struct _Script_SpatialMapping_eventSpatialMappingStepFailedDelegate_Parms \
{ \
	ESpatialMappingStep Step; \
}; \
static inline void FSpatialMappingStepFailedDelegate_DelegateWrapper(const FMulticastScriptDelegate& SpatialMappingStepFailedDelegate, ESpatialMappingStep Step) \
{ \
	_Script_SpatialMapping_eventSpatialMappingStepFailedDelegate_Parms Parms; \
	Parms.Step=Step; \
	SpatialMappingStepFailedDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetMeshVerticesNumber); \
	DECLARE_FUNCTION(execSaveMesh); \
	DECLARE_FUNCTION(execLoadMesh); \
	DECLARE_FUNCTION(execTextureMesh); \
	DECLARE_FUNCTION(execFilterMesh); \
	DECLARE_FUNCTION(execStopSpatialMapping); \
	DECLARE_FUNCTION(execPauseSpatialMapping); \
	DECLARE_FUNCTION(execStartSpatialMapping); \
	DECLARE_FUNCTION(execResetSpatialMapping); \
	DECLARE_FUNCTION(execDisableSpatialMapping); \
	DECLARE_FUNCTION(execEnableSpatialMapping); \
	DECLARE_FUNCTION(execIsSpatialMappingPaused); \
	DECLARE_FUNCTION(execIsSpatialMappingEnabled);


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetMeshVerticesNumber); \
	DECLARE_FUNCTION(execSaveMesh); \
	DECLARE_FUNCTION(execLoadMesh); \
	DECLARE_FUNCTION(execTextureMesh); \
	DECLARE_FUNCTION(execFilterMesh); \
	DECLARE_FUNCTION(execStopSpatialMapping); \
	DECLARE_FUNCTION(execPauseSpatialMapping); \
	DECLARE_FUNCTION(execStartSpatialMapping); \
	DECLARE_FUNCTION(execResetSpatialMapping); \
	DECLARE_FUNCTION(execDisableSpatialMapping); \
	DECLARE_FUNCTION(execEnableSpatialMapping); \
	DECLARE_FUNCTION(execIsSpatialMappingPaused); \
	DECLARE_FUNCTION(execIsSpatialMappingEnabled);


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpatialMappingManager(); \
	friend struct Z_Construct_UClass_ASpatialMappingManager_Statics; \
public: \
	DECLARE_CLASS(ASpatialMappingManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpatialMapping"), NO_API) \
	DECLARE_SERIALIZER(ASpatialMappingManager)


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_INCLASS \
private: \
	static void StaticRegisterNativesASpatialMappingManager(); \
	friend struct Z_Construct_UClass_ASpatialMappingManager_Statics; \
public: \
	DECLARE_CLASS(ASpatialMappingManager, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SpatialMapping"), NO_API) \
	DECLARE_SERIALIZER(ASpatialMappingManager)


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpatialMappingManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpatialMappingManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpatialMappingManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpatialMappingManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpatialMappingManager(ASpatialMappingManager&&); \
	NO_API ASpatialMappingManager(const ASpatialMappingManager&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpatialMappingManager(ASpatialMappingManager&&); \
	NO_API ASpatialMappingManager(const ASpatialMappingManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpatialMappingManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpatialMappingManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpatialMappingManager)


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_34_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPATIALMAPPING_API UClass* StaticClass<class ASpatialMappingManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
