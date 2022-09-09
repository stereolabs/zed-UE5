// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USlCriticalSection;
#ifdef STEREOLABS_StereolabsCriticalSection_generated_h
#error "StereolabsCriticalSection.generated.h already included, missing '#pragma once' in StereolabsCriticalSection.h"
#endif
#define STEREOLABS_StereolabsCriticalSection_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsLocked); \
	DECLARE_FUNCTION(execUnlock); \
	DECLARE_FUNCTION(execTryLock); \
	DECLARE_FUNCTION(execLock); \
	DECLARE_FUNCTION(execCreateCriticalSection);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsLocked); \
	DECLARE_FUNCTION(execUnlock); \
	DECLARE_FUNCTION(execTryLock); \
	DECLARE_FUNCTION(execLock); \
	DECLARE_FUNCTION(execCreateCriticalSection);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlCriticalSection(); \
	friend struct Z_Construct_UClass_USlCriticalSection_Statics; \
public: \
	DECLARE_CLASS(USlCriticalSection, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlCriticalSection)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUSlCriticalSection(); \
	friend struct Z_Construct_UClass_USlCriticalSection_Statics; \
public: \
	DECLARE_CLASS(USlCriticalSection, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlCriticalSection)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlCriticalSection(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlCriticalSection) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlCriticalSection); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlCriticalSection); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlCriticalSection(USlCriticalSection&&); \
	NO_API USlCriticalSection(const USlCriticalSection&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlCriticalSection(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlCriticalSection(USlCriticalSection&&); \
	NO_API USlCriticalSection(const USlCriticalSection&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlCriticalSection); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlCriticalSection); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlCriticalSection)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_14_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlCriticalSection>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
