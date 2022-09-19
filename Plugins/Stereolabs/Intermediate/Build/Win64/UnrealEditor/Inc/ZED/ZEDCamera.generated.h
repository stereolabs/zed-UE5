// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FZEDTrackingData;
enum class ESlErrorCode : uint8;
struct FSlTimestamp;
struct FSlVideoSettings;
struct FSlRuntimeParameters;
enum class ESlThreadingMode : uint8;
#ifdef ZED_ZEDCamera_generated_h
#error "ZEDCamera.generated.h already included, missing '#pragma once' in ZEDCamera.h"
#endif
#define ZED_ZEDCamera_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_18_DELEGATE \
struct _Script_ZED_eventZEDTrackingDataUpdatedDelegate_Parms \
{ \
	FZEDTrackingData NewTrackingData; \
}; \
static inline void FZEDTrackingDataUpdatedDelegate_DelegateWrapper(const FMulticastScriptDelegate& ZEDTrackingDataUpdatedDelegate, FZEDTrackingData const& NewTrackingData) \
{ \
	_Script_ZED_eventZEDTrackingDataUpdatedDelegate_Parms Parms; \
	Parms.NewTrackingData=NewTrackingData; \
	ZEDTrackingDataUpdatedDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_23_DELEGATE \
static inline void FZEDCameraActorInitializedDelegate_DelegateWrapper(const FMulticastScriptDelegate& ZEDCameraActorInitializedDelegate) \
{ \
	ZEDCameraActorInitializedDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCameraClosed); \
	DECLARE_FUNCTION(execGrabCallback); \
	DECLARE_FUNCTION(execSetSVOPlaybackLooping); \
	DECLARE_FUNCTION(execDisableSVORecording); \
	DECLARE_FUNCTION(execEnableSVORecording); \
	DECLARE_FUNCTION(execSetCameraSettings); \
	DECLARE_FUNCTION(execSetRuntimeParameters); \
	DECLARE_FUNCTION(execSetDepthClampThreshold); \
	DECLARE_FUNCTION(execSetThreadingMode); \
	DECLARE_FUNCTION(execSaveSpatialMemoryArea); \
	DECLARE_FUNCTION(execResetTrackingOrigin); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execDisableTracking); \
	DECLARE_FUNCTION(execEnableTracking);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCameraClosed); \
	DECLARE_FUNCTION(execGrabCallback); \
	DECLARE_FUNCTION(execSetSVOPlaybackLooping); \
	DECLARE_FUNCTION(execDisableSVORecording); \
	DECLARE_FUNCTION(execEnableSVORecording); \
	DECLARE_FUNCTION(execSetCameraSettings); \
	DECLARE_FUNCTION(execSetRuntimeParameters); \
	DECLARE_FUNCTION(execSetDepthClampThreshold); \
	DECLARE_FUNCTION(execSetThreadingMode); \
	DECLARE_FUNCTION(execSaveSpatialMemoryArea); \
	DECLARE_FUNCTION(execResetTrackingOrigin); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execDisableTracking); \
	DECLARE_FUNCTION(execEnableTracking);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZEDCamera(); \
	friend struct Z_Construct_UClass_AZEDCamera_Statics; \
public: \
	DECLARE_CLASS(AZEDCamera, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZEDCamera)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_INCLASS \
private: \
	static void StaticRegisterNativesAZEDCamera(); \
	friend struct Z_Construct_UClass_AZEDCamera_Statics; \
public: \
	DECLARE_CLASS(AZEDCamera, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZEDCamera)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZEDCamera(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZEDCamera) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZEDCamera); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZEDCamera); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZEDCamera(AZEDCamera&&); \
	NO_API AZEDCamera(const AZEDCamera&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZEDCamera(AZEDCamera&&); \
	NO_API AZEDCamera(const AZEDCamera&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZEDCamera); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZEDCamera); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZEDCamera)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_28_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_33_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class AZEDCamera>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
