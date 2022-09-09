// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FZEDTrackingData;
#ifdef ZED_ZEDPawn_generated_h
#error "ZEDPawn.generated.h already included, missing '#pragma once' in ZEDPawn.h"
#endif
#define ZED_ZEDPawn_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execZedCameraTrackingUpdated);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execZedCameraTrackingUpdated);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAZEDPawn(); \
	friend struct Z_Construct_UClass_AZEDPawn_Statics; \
public: \
	DECLARE_CLASS(AZEDPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZEDPawn)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAZEDPawn(); \
	friend struct Z_Construct_UClass_AZEDPawn_Statics; \
public: \
	DECLARE_CLASS(AZEDPawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(AZEDPawn)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AZEDPawn(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AZEDPawn) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZEDPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZEDPawn); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZEDPawn(AZEDPawn&&); \
	NO_API AZEDPawn(const AZEDPawn&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AZEDPawn(AZEDPawn&&); \
	NO_API AZEDPawn(const AZEDPawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AZEDPawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AZEDPawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AZEDPawn)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_15_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class AZEDPawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
