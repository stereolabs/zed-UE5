// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FIntPoint;
enum class ESlErrorCode : uint8;
#ifdef ZED_ZED2DObjectVisualizer_generated_h
#error "ZED2DObjectVisualizer.generated.h already included, missing '#pragma once' in ZED2DObjectVisualizer.h"
#endif
#define ZED_ZED2DObjectVisualizer_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCameraResolution); \
	DECLARE_FUNCTION(execOnZEDReady); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execIsObjectDetectionEnabled);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCameraResolution); \
	DECLARE_FUNCTION(execOnZEDReady); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execIsObjectDetectionEnabled);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZED2DObjectVisualizer(); \
	friend struct Z_Construct_UClass_AZED2DObjectVisualizer_Statics; \
public: \
	DECLARE_CLASS(AZED2DObjectVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZED2DObjectVisualizer)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAZED2DObjectVisualizer(); \
	friend struct Z_Construct_UClass_AZED2DObjectVisualizer_Statics; \
public: \
	DECLARE_CLASS(AZED2DObjectVisualizer, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZED2DObjectVisualizer)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZED2DObjectVisualizer(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZED2DObjectVisualizer) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZED2DObjectVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZED2DObjectVisualizer); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZED2DObjectVisualizer(AZED2DObjectVisualizer&&); \
	NO_API AZED2DObjectVisualizer(const AZED2DObjectVisualizer&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZED2DObjectVisualizer(AZED2DObjectVisualizer&&); \
	NO_API AZED2DObjectVisualizer(const AZED2DObjectVisualizer&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZED2DObjectVisualizer); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZED2DObjectVisualizer); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZED2DObjectVisualizer)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_16_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class AZED2DObjectVisualizer>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED2DObjectVisualizer_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
