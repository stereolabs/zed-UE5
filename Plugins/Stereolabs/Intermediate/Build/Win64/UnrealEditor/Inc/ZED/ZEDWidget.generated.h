// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLinearColor;
enum class EWidgetSpace : uint8;
#ifdef ZED_ZEDWidget_generated_h
#error "ZEDWidget.generated.h already included, missing '#pragma once' in ZEDWidget.h"
#endif
#define ZED_ZEDWidget_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execFadeOut); \
	DECLARE_FUNCTION(execFadeIn); \
	DECLARE_FUNCTION(execSetTextColorAndOpacity); \
	DECLARE_FUNCTION(execSetFontSize); \
	DECLARE_FUNCTION(execSetText); \
	DECLARE_FUNCTION(execSetWidgetSpace); \
	DECLARE_FUNCTION(execGetWidgetSpace);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFadeOut); \
	DECLARE_FUNCTION(execFadeIn); \
	DECLARE_FUNCTION(execSetTextColorAndOpacity); \
	DECLARE_FUNCTION(execSetFontSize); \
	DECLARE_FUNCTION(execSetText); \
	DECLARE_FUNCTION(execSetWidgetSpace); \
	DECLARE_FUNCTION(execGetWidgetSpace);


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUZEDWidget(); \
	friend struct Z_Construct_UClass_UZEDWidget_Statics; \
public: \
	DECLARE_CLASS(UZEDWidget, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(UZEDWidget)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_INCLASS \
private: \
	static void StaticRegisterNativesUZEDWidget(); \
	friend struct Z_Construct_UClass_UZEDWidget_Statics; \
public: \
	DECLARE_CLASS(UZEDWidget, USceneComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ZED"), NO_API) \
	DECLARE_SERIALIZER(UZEDWidget)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UZEDWidget(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UZEDWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZEDWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZEDWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UZEDWidget(UZEDWidget&&); \
	NO_API UZEDWidget(const UZEDWidget&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UZEDWidget(UZEDWidget&&); \
	NO_API UZEDWidget(const UZEDWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UZEDWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UZEDWidget); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UZEDWidget)


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_9_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ZED_API UClass* StaticClass<class UZEDWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
