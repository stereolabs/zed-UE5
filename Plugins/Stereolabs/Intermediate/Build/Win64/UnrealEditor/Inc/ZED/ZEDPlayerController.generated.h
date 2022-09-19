// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class ESlErrorCode : uint8;
class UObject;
class UPrimitiveComponent;
#ifdef ZED_ZEDPlayerController_generated_h
#error "ZEDPlayerController.generated.h already included, missing '#pragma once' in ZEDPlayerController.h"
#endif
#define ZED_ZEDPlayerController_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_20_DELEGATE \
static inline void FZEDPlayerControllerDelegate_DelegateWrapper(const FMulticastScriptDelegate& ZEDPlayerControllerDelegate) \
{ \
	ZEDPlayerControllerDelegate.ProcessMulticastDelegate<UObject>(NULL); \
}


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_RPC_WRAPPERS \
	virtual void UpdateHUDZedDisconnected_Implementation(); \
	virtual void UpdateHUDZedTrackingEnabled_Implementation(bool bSuccess, ESlErrorCode ErrorCode); \
	virtual void UpdateHUDEnablingZedTracking_Implementation(); \
	virtual void UpdateHUDZedOpened_Implementation(); \
	virtual void UpdateHUDCheckOpeningZed_Implementation(); \
	virtual void UpdateHUDOpeningZed_Implementation(); \
 \
	DECLARE_FUNCTION(execInternal_OpenZedCamera); \
	DECLARE_FUNCTION(execOnRep_ZedPawn); \
	DECLARE_FUNCTION(execResetHMDTrackingOrigin); \
	DECLARE_FUNCTION(execZedCameraActorInitialized); \
	DECLARE_FUNCTION(execFading); \
	DECLARE_FUNCTION(execZedCameraTrackingEnabled); \
	DECLARE_FUNCTION(execZedCameraDisconnected); \
	DECLARE_FUNCTION(execZedCameraClosed); \
	DECLARE_FUNCTION(execZedCameraOpened); \
	DECLARE_FUNCTION(execUpdateHUDZedDisconnected); \
	DECLARE_FUNCTION(execUpdateHUDZedTrackingEnabled); \
	DECLARE_FUNCTION(execUpdateHUDEnablingZedTracking); \
	DECLARE_FUNCTION(execUpdateHUDZedOpened); \
	DECLARE_FUNCTION(execUpdateHUDCheckOpeningZed); \
	DECLARE_FUNCTION(execUpdateHUDOpeningZed); \
	DECLARE_FUNCTION(execInit); \
	DECLARE_FUNCTION(execFadeOut); \
	DECLARE_FUNCTION(execFadeIn); \
	DECLARE_FUNCTION(execSpawnZedCameraActor); \
	DECLARE_FUNCTION(execSpawnPawn); \
	DECLARE_FUNCTION(execMakeDefaultInit); \
	DECLARE_FUNCTION(execCloseZedCamera); \
	DECLARE_FUNCTION(execOpenZedCamera); \
	DECLARE_FUNCTION(execEmptyShowOnlyComponentList); \
	DECLARE_FUNCTION(execAddShowOnlyComponent);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execInternal_OpenZedCamera); \
	DECLARE_FUNCTION(execOnRep_ZedPawn); \
	DECLARE_FUNCTION(execResetHMDTrackingOrigin); \
	DECLARE_FUNCTION(execZedCameraActorInitialized); \
	DECLARE_FUNCTION(execFading); \
	DECLARE_FUNCTION(execZedCameraTrackingEnabled); \
	DECLARE_FUNCTION(execZedCameraDisconnected); \
	DECLARE_FUNCTION(execZedCameraClosed); \
	DECLARE_FUNCTION(execZedCameraOpened); \
	DECLARE_FUNCTION(execUpdateHUDZedDisconnected); \
	DECLARE_FUNCTION(execUpdateHUDZedTrackingEnabled); \
	DECLARE_FUNCTION(execUpdateHUDEnablingZedTracking); \
	DECLARE_FUNCTION(execUpdateHUDZedOpened); \
	DECLARE_FUNCTION(execUpdateHUDCheckOpeningZed); \
	DECLARE_FUNCTION(execUpdateHUDOpeningZed); \
	DECLARE_FUNCTION(execInit); \
	DECLARE_FUNCTION(execFadeOut); \
	DECLARE_FUNCTION(execFadeIn); \
	DECLARE_FUNCTION(execSpawnZedCameraActor); \
	DECLARE_FUNCTION(execSpawnPawn); \
	DECLARE_FUNCTION(execMakeDefaultInit); \
	DECLARE_FUNCTION(execCloseZedCamera); \
	DECLARE_FUNCTION(execOpenZedCamera); \
	DECLARE_FUNCTION(execEmptyShowOnlyComponentList); \
	DECLARE_FUNCTION(execAddShowOnlyComponent);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_EVENT_PARMS \
	struct ZEDPlayerController_eventUpdateHUDZedTrackingEnabled_Parms \
	{ \
		bool bSuccess; \
		ESlErrorCode ErrorCode; \
	};


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_CALLBACK_WRAPPERS
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZEDPlayerController(); \
	friend struct Z_Construct_UClass_AZEDPlayerController_Statics; \
public: \
	DECLARE_CLASS(AZEDPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZEDPlayerController) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ZedPawn=NETFIELD_REP_START, \
		NETFIELD_REP_END=ZedPawn	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_INCLASS \
private: \
	static void StaticRegisterNativesAZEDPlayerController(); \
	friend struct Z_Construct_UClass_AZEDPlayerController_Statics; \
public: \
	DECLARE_CLASS(AZEDPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZEDPlayerController) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ZedPawn=NETFIELD_REP_START, \
		NETFIELD_REP_END=ZedPawn	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZEDPlayerController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZEDPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZEDPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZEDPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZEDPlayerController(AZEDPlayerController&&); \
	NO_API AZEDPlayerController(const AZEDPlayerController&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZEDPlayerController(AZEDPlayerController&&); \
	NO_API AZEDPlayerController(const AZEDPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZEDPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZEDPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZEDPlayerController)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_25_PROLOG \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_EVENT_PARMS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_CALLBACK_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_CALLBACK_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class AZEDPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
