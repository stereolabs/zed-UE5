// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FSlMat;
enum class ESlMemoryType : uint8;
enum class ESlTextureType : uint8;
enum class ESlView : uint8;
class USlViewTexture;
enum class ESlTextureFormat : uint8;
enum class ESlMeasure : uint8;
class USlMeasureTexture;
#ifdef STEREOLABS_StereolabsTexture_generated_h
#error "StereolabsTexture.generated.h already included, missing '#pragma once' in StereolabsTexture.h"
#endif
#define STEREOLABS_StereolabsTexture_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execResize); \
	DECLARE_FUNCTION(execBP_UpdateTextureWithMat); \
	DECLARE_FUNCTION(execBP_UpdateTexture); \
	DECLARE_FUNCTION(execGetMemoryType); \
	DECLARE_FUNCTION(execIsMemoryTypeOf); \
	DECLARE_FUNCTION(execIsTypeOf);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResize); \
	DECLARE_FUNCTION(execBP_UpdateTextureWithMat); \
	DECLARE_FUNCTION(execBP_UpdateTexture); \
	DECLARE_FUNCTION(execGetMemoryType); \
	DECLARE_FUNCTION(execIsMemoryTypeOf); \
	DECLARE_FUNCTION(execIsTypeOf);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlTexture(); \
	friend struct Z_Construct_UClass_USlTexture_Statics; \
public: \
	DECLARE_CLASS(USlTexture, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUSlTexture(); \
	friend struct Z_Construct_UClass_USlTexture_Statics; \
public: \
	DECLARE_CLASS(USlTexture, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlTexture(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlTexture) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlTexture); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlTexture); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlTexture(USlTexture&&); \
	NO_API USlTexture(const USlTexture&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlTexture(USlTexture&&); \
	NO_API USlTexture(const USlTexture&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlTexture); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlTexture); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_14_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlTexture>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateCPUViewTexture); \
	DECLARE_FUNCTION(execCreateGPUViewTexture);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateCPUViewTexture); \
	DECLARE_FUNCTION(execCreateGPUViewTexture);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlViewTexture(); \
	friend struct Z_Construct_UClass_USlViewTexture_Statics; \
public: \
	DECLARE_CLASS(USlViewTexture, USlTexture, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlViewTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_INCLASS \
private: \
	static void StaticRegisterNativesUSlViewTexture(); \
	friend struct Z_Construct_UClass_USlViewTexture_Statics; \
public: \
	DECLARE_CLASS(USlViewTexture, USlTexture, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlViewTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlViewTexture(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlViewTexture) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlViewTexture); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlViewTexture); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlViewTexture(USlViewTexture&&); \
	NO_API USlViewTexture(const USlViewTexture&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlViewTexture() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlViewTexture(USlViewTexture&&); \
	NO_API USlViewTexture(const USlViewTexture&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlViewTexture); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlViewTexture); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlViewTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_139_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_142_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlViewTexture>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateCPUMeasureTexture); \
	DECLARE_FUNCTION(execCreateGPUMeasureTexture);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateCPUMeasureTexture); \
	DECLARE_FUNCTION(execCreateGPUMeasureTexture);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlMeasureTexture(); \
	friend struct Z_Construct_UClass_USlMeasureTexture_Statics; \
public: \
	DECLARE_CLASS(USlMeasureTexture, USlTexture, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlMeasureTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_INCLASS \
private: \
	static void StaticRegisterNativesUSlMeasureTexture(); \
	friend struct Z_Construct_UClass_USlMeasureTexture_Statics; \
public: \
	DECLARE_CLASS(USlMeasureTexture, USlTexture, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlMeasureTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlMeasureTexture(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlMeasureTexture) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlMeasureTexture); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlMeasureTexture); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlMeasureTexture(USlMeasureTexture&&); \
	NO_API USlMeasureTexture(const USlMeasureTexture&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlMeasureTexture() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlMeasureTexture(USlMeasureTexture&&); \
	NO_API USlMeasureTexture(const USlMeasureTexture&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlMeasureTexture); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlMeasureTexture); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlMeasureTexture)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_192_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_195_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlMeasureTexture>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
