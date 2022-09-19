// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESlErrorCode : uint8;
struct FSlObjects;
struct FSlTimestamp;
struct FGrabDelegateHandle;
class UObject;
enum class ESlModel : uint8;
struct FSlRecordingState;
struct FSlRecordingParameters;
struct FSlObjectDetectionParameters;
struct FSlViewportHelper;
struct FIntPoint;
struct FSlMat;
enum class ESlMeasure : uint8;
enum class ESlMemoryType : uint8;
enum class ESlView : uint8;
class USlTexture;
class USlMesh;
struct FSlSpatialMappingParameters;
enum class ESlSpatialMemoryExportingState : uint8;
struct FSlIMUData;
enum class ESlTimeReference : uint8;
struct FSlPose;
enum class ESlReferenceFrame : uint8;
enum class ESlTrackingState : uint8;
struct FSlPositionalTrackingParameters;
struct FSlCameraInformation;
struct FSlRuntimeParameters;
struct FSlVideoSettings;
struct FSlDeviceProperties;
struct FSlInitParameters;
#ifdef STEREOLABS_StereolabsCameraProxy_generated_h
#error "StereolabsCameraProxy.generated.h already included, missing '#pragma once' in StereolabsCameraProxy.h"
#endif
#define STEREOLABS_StereolabsCameraProxy_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_26_DELEGATE \
struct _Script_Stereolabs_eventSlCameraProxyTwoParamsDelegate_Parms \
{ \
	bool bSuccess; \
	ESlErrorCode ErrorCode; \
}; \
static inline void FSlCameraProxyTwoParamsDelegate_DelegateWrapper(const FMulticastScriptDelegate& SlCameraProxyTwoParamsDelegate, bool bSuccess, ESlErrorCode ErrorCode) \
{ \
	_Script_Stereolabs_eventSlCameraProxyTwoParamsDelegate_Parms Parms; \
	Parms.bSuccess=bSuccess ? true : false; \
	Parms.ErrorCode=ErrorCode; \
	SlCameraProxyTwoParamsDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_31_DELEGATE \
struct _Script_Stereolabs_eventSlCameraProxyOneParamDelegate_Parms \
{ \
	bool bEnabled; \
}; \
static inline void FSlCameraProxyOneParamDelegate_DelegateWrapper(const FMulticastScriptDelegate& SlCameraProxyOneParamDelegate, bool bEnabled) \
{ \
	_Script_Stereolabs_eventSlCameraProxyOneParamDelegate_Parms Parms; \
	Parms.bEnabled=bEnabled ? true : false; \
	SlCameraProxyOneParamDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_36_DELEGATE \
static inline void FSlCameraProxyDelegate_DelegateWrapper(const FMulticastScriptDelegate& SlCameraProxyDelegate) \
{ \
	SlCameraProxyDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_41_DELEGATE \
struct _Script_Stereolabs_eventSlCameraProxyTrackingDelegate_Parms \
{ \
	bool bSuccess; \
	ESlErrorCode ErrorCode; \
	FVector Location; \
	FRotator Rotation; \
}; \
static inline void FSlCameraProxyTrackingDelegate_DelegateWrapper(const FMulticastScriptDelegate& SlCameraProxyTrackingDelegate, bool bSuccess, ESlErrorCode ErrorCode, FVector const& Location, FRotator const& Rotation) \
{ \
	_Script_Stereolabs_eventSlCameraProxyTrackingDelegate_Parms Parms; \
	Parms.bSuccess=bSuccess ? true : false; \
	Parms.ErrorCode=ErrorCode; \
	Parms.Location=Location; \
	Parms.Rotation=Rotation; \
	SlCameraProxyTrackingDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_46_DELEGATE \
struct _Script_Stereolabs_eventSlCameraProxySpatialMappingPausedDelegate_Parms \
{ \
	bool bPaused; \
}; \
static inline void FSlCameraProxySpatialMappingPausedDelegate_DelegateWrapper(const FMulticastScriptDelegate& SlCameraProxySpatialMappingPausedDelegate, bool bPaused) \
{ \
	_Script_Stereolabs_eventSlCameraProxySpatialMappingPausedDelegate_Parms Parms; \
	Parms.bPaused=bPaused ? true : false; \
	SlCameraProxySpatialMappingPausedDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_56_DELEGATE \
struct _Script_Stereolabs_eventSlCameraProxyRetrieveObjectDelegate_Parms \
{ \
	FSlObjects objects; \
}; \
static inline void FSlCameraProxyRetrieveObjectDelegate_DelegateWrapper(const FMulticastScriptDelegate& SlCameraProxyRetrieveObjectDelegate, FSlObjects const& objects) \
{ \
	_Script_Stereolabs_eventSlCameraProxyRetrieveObjectDelegate_Parms Parms; \
	Parms.objects=objects; \
	SlCameraProxyRetrieveObjectDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_74_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FGrabDelegateHandle_Statics; \
	static class UScriptStruct* StaticStruct();


template<> STEREOLABS_API UScriptStruct* StaticStruct<struct FGrabDelegateHandle>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_RPC_WRAPPERS \
	virtual void GrabCallback_Implementation(ESlErrorCode ErrorCode, FSlTimestamp const& Timestamp) {}; \
 \
	DECLARE_FUNCTION(execGrabCallback);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void GrabCallback_Implementation(ESlErrorCode ErrorCode, FSlTimestamp const& Timestamp) {}; \
 \
	DECLARE_FUNCTION(execGrabCallback);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_EVENT_PARMS \
	struct GrabCallbackInterface_eventGrabCallback_Parms \
	{ \
		ESlErrorCode ErrorCode; \
		FSlTimestamp Timestamp; \
	};


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_CALLBACK_WRAPPERS
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGrabCallbackInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGrabCallbackInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGrabCallbackInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGrabCallbackInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGrabCallbackInterface(UGrabCallbackInterface&&); \
	NO_API UGrabCallbackInterface(const UGrabCallbackInterface&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGrabCallbackInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGrabCallbackInterface(UGrabCallbackInterface&&); \
	NO_API UGrabCallbackInterface(const UGrabCallbackInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGrabCallbackInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGrabCallbackInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGrabCallbackInterface)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUGrabCallbackInterface(); \
	friend struct Z_Construct_UClass_UGrabCallbackInterface_Statics; \
public: \
	DECLARE_CLASS(UGrabCallbackInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(UGrabCallbackInterface)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_GENERATED_UINTERFACE_BODY() \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_GENERATED_UINTERFACE_BODY() \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IGrabCallbackInterface() {} \
public: \
	typedef UGrabCallbackInterface UClassType; \
	typedef IGrabCallbackInterface ThisClass; \
	static void Execute_GrabCallback(UObject* O, ESlErrorCode ErrorCode, FSlTimestamp const& Timestamp); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_INCLASS_IINTERFACE \
protected: \
	virtual ~IGrabCallbackInterface() {} \
public: \
	typedef UGrabCallbackInterface UClassType; \
	typedef IGrabCallbackInterface ThisClass; \
	static void Execute_GrabCallback(UObject* O, ESlErrorCode ErrorCode, FSlTimestamp const& Timestamp); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_98_PROLOG \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_EVENT_PARMS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_109_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_CALLBACK_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_109_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_CALLBACK_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_101_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class UGrabCallbackInterface>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnableGrabThread); \
	DECLARE_FUNCTION(execBP_RemoveFromGrabDelegate); \
	DECLARE_FUNCTION(execBP_AddToGrabDelegate); \
	DECLARE_FUNCTION(execGetCameraModel); \
	DECLARE_FUNCTION(execGetFrameDroppedCount); \
	DECLARE_FUNCTION(execGetCurrentFPS); \
	DECLARE_FUNCTION(execGetCameraFPS); \
	DECLARE_FUNCTION(execGetDepthMinRangeValue); \
	DECLARE_FUNCTION(execGetDepthMaxRangeValue); \
	DECLARE_FUNCTION(execSetConfidenceThreshold); \
	DECLARE_FUNCTION(execGetConfidenceThreshold); \
	DECLARE_FUNCTION(execPopCudaContext); \
	DECLARE_FUNCTION(execPushCudaContext); \
	DECLARE_FUNCTION(execGetSVORecordingState); \
	DECLARE_FUNCTION(execGetSVONumberOfFrames); \
	DECLARE_FUNCTION(execSetSVORecordFrames); \
	DECLARE_FUNCTION(execSetSVOPlaybackLooping); \
	DECLARE_FUNCTION(execPauseSVOplayback); \
	DECLARE_FUNCTION(execGetSVOPlaybackPosition); \
	DECLARE_FUNCTION(execSetSVOPlaybackPosition); \
	DECLARE_FUNCTION(execDisableSVORecording); \
	DECLARE_FUNCTION(execEnableSVORecording); \
	DECLARE_FUNCTION(execEnableHitTest); \
	DECLARE_FUNCTION(execSetHitTestDepthAndNormals); \
	DECLARE_FUNCTION(execGetOpenCameraErrorCode); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execIsObjectDetectionEnabled); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execGetDepthsAndNormals); \
	DECLARE_FUNCTION(execGetDepthAndNormal); \
	DECLARE_FUNCTION(execGetNormals); \
	DECLARE_FUNCTION(execGetNormal); \
	DECLARE_FUNCTION(execGetDepths); \
	DECLARE_FUNCTION(execGetDepth); \
	DECLARE_FUNCTION(execRetrieveMeasure); \
	DECLARE_FUNCTION(execRetrieveImage); \
	DECLARE_FUNCTION(execRetrieveTexture); \
	DECLARE_FUNCTION(execExtractWholeMesh); \
	DECLARE_FUNCTION(execRetrieveMeshAsync); \
	DECLARE_FUNCTION(execGetMeshIsReadyAsync); \
	DECLARE_FUNCTION(execRequestMeshAsync); \
	DECLARE_FUNCTION(execPauseSpatialMapping); \
	DECLARE_FUNCTION(execDisableSpatialMapping); \
	DECLARE_FUNCTION(execEnableSpatialMapping); \
	DECLARE_FUNCTION(execGetSpatialMemoryExportState); \
	DECLARE_FUNCTION(execSaveSpatialMemoryArea); \
	DECLARE_FUNCTION(execIsTrackingEnabled); \
	DECLARE_FUNCTION(execSetIMUPrior); \
	DECLARE_FUNCTION(execGetIMUData); \
	DECLARE_FUNCTION(execGetPosition); \
	DECLARE_FUNCTION(execResetTracking); \
	DECLARE_FUNCTION(execDisableTracking); \
	DECLARE_FUNCTION(execEnableTracking); \
	DECLARE_FUNCTION(execGetCameraInformation); \
	DECLARE_FUNCTION(execSetRuntimeParameters); \
	DECLARE_FUNCTION(execGetTimestamp); \
	DECLARE_FUNCTION(execSetCameraSettings); \
	DECLARE_FUNCTION(execGetCameraSettings); \
	DECLARE_FUNCTION(execGetCameraList); \
	DECLARE_FUNCTION(execIsCameraConnected); \
	DECLARE_FUNCTION(execIsCameraOpened); \
	DECLARE_FUNCTION(execCloseCamera); \
	DECLARE_FUNCTION(execOpenCamera); \
	DECLARE_FUNCTION(execGetSDKVersion);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnableGrabThread); \
	DECLARE_FUNCTION(execBP_RemoveFromGrabDelegate); \
	DECLARE_FUNCTION(execBP_AddToGrabDelegate); \
	DECLARE_FUNCTION(execGetCameraModel); \
	DECLARE_FUNCTION(execGetFrameDroppedCount); \
	DECLARE_FUNCTION(execGetCurrentFPS); \
	DECLARE_FUNCTION(execGetCameraFPS); \
	DECLARE_FUNCTION(execGetDepthMinRangeValue); \
	DECLARE_FUNCTION(execGetDepthMaxRangeValue); \
	DECLARE_FUNCTION(execSetConfidenceThreshold); \
	DECLARE_FUNCTION(execGetConfidenceThreshold); \
	DECLARE_FUNCTION(execPopCudaContext); \
	DECLARE_FUNCTION(execPushCudaContext); \
	DECLARE_FUNCTION(execGetSVORecordingState); \
	DECLARE_FUNCTION(execGetSVONumberOfFrames); \
	DECLARE_FUNCTION(execSetSVORecordFrames); \
	DECLARE_FUNCTION(execSetSVOPlaybackLooping); \
	DECLARE_FUNCTION(execPauseSVOplayback); \
	DECLARE_FUNCTION(execGetSVOPlaybackPosition); \
	DECLARE_FUNCTION(execSetSVOPlaybackPosition); \
	DECLARE_FUNCTION(execDisableSVORecording); \
	DECLARE_FUNCTION(execEnableSVORecording); \
	DECLARE_FUNCTION(execEnableHitTest); \
	DECLARE_FUNCTION(execSetHitTestDepthAndNormals); \
	DECLARE_FUNCTION(execGetOpenCameraErrorCode); \
	DECLARE_FUNCTION(execDisableObjectDetection); \
	DECLARE_FUNCTION(execIsObjectDetectionEnabled); \
	DECLARE_FUNCTION(execEnableObjectDetection); \
	DECLARE_FUNCTION(execGetDepthsAndNormals); \
	DECLARE_FUNCTION(execGetDepthAndNormal); \
	DECLARE_FUNCTION(execGetNormals); \
	DECLARE_FUNCTION(execGetNormal); \
	DECLARE_FUNCTION(execGetDepths); \
	DECLARE_FUNCTION(execGetDepth); \
	DECLARE_FUNCTION(execRetrieveMeasure); \
	DECLARE_FUNCTION(execRetrieveImage); \
	DECLARE_FUNCTION(execRetrieveTexture); \
	DECLARE_FUNCTION(execExtractWholeMesh); \
	DECLARE_FUNCTION(execRetrieveMeshAsync); \
	DECLARE_FUNCTION(execGetMeshIsReadyAsync); \
	DECLARE_FUNCTION(execRequestMeshAsync); \
	DECLARE_FUNCTION(execPauseSpatialMapping); \
	DECLARE_FUNCTION(execDisableSpatialMapping); \
	DECLARE_FUNCTION(execEnableSpatialMapping); \
	DECLARE_FUNCTION(execGetSpatialMemoryExportState); \
	DECLARE_FUNCTION(execSaveSpatialMemoryArea); \
	DECLARE_FUNCTION(execIsTrackingEnabled); \
	DECLARE_FUNCTION(execSetIMUPrior); \
	DECLARE_FUNCTION(execGetIMUData); \
	DECLARE_FUNCTION(execGetPosition); \
	DECLARE_FUNCTION(execResetTracking); \
	DECLARE_FUNCTION(execDisableTracking); \
	DECLARE_FUNCTION(execEnableTracking); \
	DECLARE_FUNCTION(execGetCameraInformation); \
	DECLARE_FUNCTION(execSetRuntimeParameters); \
	DECLARE_FUNCTION(execGetTimestamp); \
	DECLARE_FUNCTION(execSetCameraSettings); \
	DECLARE_FUNCTION(execGetCameraSettings); \
	DECLARE_FUNCTION(execGetCameraList); \
	DECLARE_FUNCTION(execIsCameraConnected); \
	DECLARE_FUNCTION(execIsCameraOpened); \
	DECLARE_FUNCTION(execCloseCamera); \
	DECLARE_FUNCTION(execOpenCamera); \
	DECLARE_FUNCTION(execGetSDKVersion);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlCameraProxy(); \
	friend struct Z_Construct_UClass_USlCameraProxy_Statics; \
public: \
	DECLARE_CLASS(USlCameraProxy, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlCameraProxy)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_INCLASS \
private: \
	static void StaticRegisterNativesUSlCameraProxy(); \
	friend struct Z_Construct_UClass_USlCameraProxy_Statics; \
public: \
	DECLARE_CLASS(USlCameraProxy, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlCameraProxy)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlCameraProxy(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlCameraProxy) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlCameraProxy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlCameraProxy); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlCameraProxy(USlCameraProxy&&); \
	NO_API USlCameraProxy(const USlCameraProxy&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlCameraProxy(USlCameraProxy&&); \
	NO_API USlCameraProxy(const USlCameraProxy&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlCameraProxy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlCameraProxy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlCameraProxy)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_126_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h_134_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlCameraProxy>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsCameraProxy_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
