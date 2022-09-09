// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESlErrorCode : uint8;
#ifdef ZED_ZED3DObjectVisualizer_generated_h
#error "ZED3DObjectVisualizer.generated.h already included, missing '#pragma once' in ZED3DObjectVisualizer.h"
#endif
#define ZED_ZED3DObjectVisualizer_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnZEDReady); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execIsObjectDetectionEnabled);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnZEDReady); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execIsObjectDetectionEnabled);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZED3DObjectVisualizer(); \
	friend struct Z_Construct_UClass_AZED3DObjectVisualizer_Statics; \
public: \
	DECLARE_CLASS(AZED3DObjectVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZED3DObjectVisualizer)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAZED3DObjectVisualizer(); \
	friend struct Z_Construct_UClass_AZED3DObjectVisualizer_Statics; \
public: \
	DECLARE_CLASS(AZED3DObjectVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZED3DObjectVisualizer)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZED3DObjectVisualizer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZED3DObjectVisualizer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZED3DObjectVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZED3DObjectVisualizer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZED3DObjectVisualizer(AZED3DObjectVisualizer&&); \
	NO_API AZED3DObjectVisualizer(const AZED3DObjectVisualizer&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZED3DObjectVisualizer(AZED3DObjectVisualizer&&); \
	NO_API AZED3DObjectVisualizer(const AZED3DObjectVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZED3DObjectVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZED3DObjectVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZED3DObjectVisualizer)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_16_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class AZED3DObjectVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
