// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USlTexture;
struct FSlTimestamp;
class USlGPUTextureBatch;
class USlSimpleGPUTextureBatch;
class USlCPUTextureBatch;
#ifdef STEREOLABS_StereolabsTextureBatch_generated_h
#error "StereolabsTextureBatch.generated.h already included, missing '#pragma once' in StereolabsTextureBatch.h"
#endif
#define STEREOLABS_StereolabsTextureBatch_generated_h

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetAsyncRetrieveEnabled); \
	DECLARE_FUNCTION(execClear); \
	DECLARE_FUNCTION(execRemoveTexture); \
	DECLARE_FUNCTION(execAddTexture); \
	DECLARE_FUNCTION(execTick); \
	DECLARE_FUNCTION(execRetrieveCurrentFrame);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetAsyncRetrieveEnabled); \
	DECLARE_FUNCTION(execClear); \
	DECLARE_FUNCTION(execRemoveTexture); \
	DECLARE_FUNCTION(execAddTexture); \
	DECLARE_FUNCTION(execTick); \
	DECLARE_FUNCTION(execRetrieveCurrentFrame);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlTextureBatch(); \
	friend struct Z_Construct_UClass_USlTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlTextureBatch, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_INCLASS \
private: \
	static void StaticRegisterNativesUSlTextureBatch(); \
	friend struct Z_Construct_UClass_USlTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlTextureBatch, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlTextureBatch(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlTextureBatch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlTextureBatch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlTextureBatch(USlTextureBatch&&); \
	NO_API USlTextureBatch(const USlTextureBatch&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlTextureBatch(USlTextureBatch&&); \
	NO_API USlTextureBatch(const USlTextureBatch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlTextureBatch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_35_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlTextureBatch>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateGPUTextureBatch);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateGPUTextureBatch);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlGPUTextureBatch(); \
	friend struct Z_Construct_UClass_USlGPUTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlGPUTextureBatch, USlTextureBatch, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlGPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_INCLASS \
private: \
	static void StaticRegisterNativesUSlGPUTextureBatch(); \
	friend struct Z_Construct_UClass_USlGPUTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlGPUTextureBatch, USlTextureBatch, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlGPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlGPUTextureBatch(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlGPUTextureBatch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlGPUTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlGPUTextureBatch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlGPUTextureBatch(USlGPUTextureBatch&&); \
	NO_API USlGPUTextureBatch(const USlGPUTextureBatch&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlGPUTextureBatch() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlGPUTextureBatch(USlGPUTextureBatch&&); \
	NO_API USlGPUTextureBatch(const USlGPUTextureBatch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlGPUTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlGPUTextureBatch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlGPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_136_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_139_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlGPUTextureBatch>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateSimpleGPUTextureBatch);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateSimpleGPUTextureBatch);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlSimpleGPUTextureBatch(); \
	friend struct Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlSimpleGPUTextureBatch, USlTextureBatch, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlSimpleGPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_INCLASS \
private: \
	static void StaticRegisterNativesUSlSimpleGPUTextureBatch(); \
	friend struct Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlSimpleGPUTextureBatch, USlTextureBatch, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlSimpleGPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlSimpleGPUTextureBatch(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlSimpleGPUTextureBatch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlSimpleGPUTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlSimpleGPUTextureBatch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlSimpleGPUTextureBatch(USlSimpleGPUTextureBatch&&); \
	NO_API USlSimpleGPUTextureBatch(const USlSimpleGPUTextureBatch&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlSimpleGPUTextureBatch() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlSimpleGPUTextureBatch(USlSimpleGPUTextureBatch&&); \
	NO_API USlSimpleGPUTextureBatch(const USlSimpleGPUTextureBatch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlSimpleGPUTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlSimpleGPUTextureBatch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlSimpleGPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_192_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_195_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlSimpleGPUTextureBatch>();

#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_SPARSE_DATA
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCreateCPUTextureBatch);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCreateCPUTextureBatch);


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSlCPUTextureBatch(); \
	friend struct Z_Construct_UClass_USlCPUTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlCPUTextureBatch, USlTextureBatch, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlCPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_INCLASS \
private: \
	static void StaticRegisterNativesUSlCPUTextureBatch(); \
	friend struct Z_Construct_UClass_USlCPUTextureBatch_Statics; \
public: \
	DECLARE_CLASS(USlCPUTextureBatch, USlTextureBatch, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Stereolabs"), NO_API) \
	DECLARE_SERIALIZER(USlCPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlCPUTextureBatch(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USlCPUTextureBatch) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlCPUTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlCPUTextureBatch); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlCPUTextureBatch(USlCPUTextureBatch&&); \
	NO_API USlCPUTextureBatch(const USlCPUTextureBatch&); \
public:


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USlCPUTextureBatch() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USlCPUTextureBatch(USlCPUTextureBatch&&); \
	NO_API USlCPUTextureBatch(const USlCPUTextureBatch&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USlCPUTextureBatch); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USlCPUTextureBatch); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USlCPUTextureBatch)


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_219_PROLOG
#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_RPC_WRAPPERS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_INCLASS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_SPARSE_DATA \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_INCLASS_NO_PURE_DECLS \
	FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_222_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> STEREOLABS_API UClass* StaticClass<class USlCPUTextureBatch>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
