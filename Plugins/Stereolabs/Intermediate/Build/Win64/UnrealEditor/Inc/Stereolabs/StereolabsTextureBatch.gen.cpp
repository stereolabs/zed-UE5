// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Core/StereolabsTextureBatch.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsTextureBatch() {}
// Cross Module References
	STEREOLABS_API UClass* Z_Construct_UClass_USlTextureBatch_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlTextureBatch();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
	STEREOLABS_API UClass* Z_Construct_UClass_USlTexture_NoRegister();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlTimestamp();
	STEREOLABS_API UClass* Z_Construct_UClass_USlGPUTextureBatch_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlGPUTextureBatch();
	STEREOLABS_API UClass* Z_Construct_UClass_USlSimpleGPUTextureBatch_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlSimpleGPUTextureBatch();
	STEREOLABS_API UClass* Z_Construct_UClass_USlCPUTextureBatch_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlCPUTextureBatch();
// End Cross Module References
	DEFINE_FUNCTION(USlTextureBatch::execSetAsyncRetrieveEnabled)
	{
		P_GET_UBOOL(Z_Param_bEnabled);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAsyncRetrieveEnabled(Z_Param_bEnabled);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTextureBatch::execClear)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Clear();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTextureBatch::execRemoveTexture)
	{
		P_GET_OBJECT(USlTexture,Z_Param_Texture);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTexture(Z_Param_Texture);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTextureBatch::execAddTexture)
	{
		P_GET_OBJECT(USlTexture,Z_Param_Texture);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTexture(Z_Param_Texture);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTextureBatch::execTick)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Tick();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTextureBatch::execRetrieveCurrentFrame)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_ImageTimestamp);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RetrieveCurrentFrame(Z_Param_Out_ImageTimestamp);
		P_NATIVE_END;
	}
	void USlTextureBatch::StaticRegisterNativesUSlTextureBatch()
	{
		UClass* Class = USlTextureBatch::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddTexture", &USlTextureBatch::execAddTexture },
			{ "Clear", &USlTextureBatch::execClear },
			{ "RemoveTexture", &USlTextureBatch::execRemoveTexture },
			{ "RetrieveCurrentFrame", &USlTextureBatch::execRetrieveCurrentFrame },
			{ "SetAsyncRetrieveEnabled", &USlTextureBatch::execSetAsyncRetrieveEnabled },
			{ "Tick", &USlTextureBatch::execTick },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics
	{
		struct SlTextureBatch_eventAddTexture_Parms
		{
			USlTexture* Texture;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTextureBatch_eventAddTexture_Parms, Texture), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::NewProp_Texture,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Add a texture\n\x09 * @param Texture The texture to add\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Add a texture\n* @param Texture The texture to add" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTextureBatch, nullptr, "AddTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::SlTextureBatch_eventAddTexture_Parms), Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTextureBatch_AddTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTextureBatch_AddTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTextureBatch_Clear_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_Clear_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Remove all textures\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Remove all textures" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTextureBatch_Clear_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTextureBatch, nullptr, "Clear", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_Clear_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_Clear_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTextureBatch_Clear()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTextureBatch_Clear_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics
	{
		struct SlTextureBatch_eventRemoveTexture_Parms
		{
			USlTexture* Texture;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTextureBatch_eventRemoveTexture_Parms, Texture), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::NewProp_Texture,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Remove a texture\n\x09 * @param Texture The texture to remove\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Remove a texture\n* @param Texture The texture to remove" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTextureBatch, nullptr, "RemoveTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::SlTextureBatch_eventRemoveTexture_Parms), Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTextureBatch_RemoveTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTextureBatch_RemoveTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics
	{
		struct SlTextureBatch_eventRetrieveCurrentFrame_Parms
		{
			FSlTimestamp ImageTimestamp;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageTimestamp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImageTimestamp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::NewProp_ImageTimestamp_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::NewProp_ImageTimestamp = { "ImageTimestamp", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTextureBatch_eventRetrieveCurrentFrame_Parms, ImageTimestamp), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::NewProp_ImageTimestamp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::NewProp_ImageTimestamp_MetaData)) }; // 2964665703
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::NewProp_ImageTimestamp,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Retrieve the textures. Called inside the grab thread.\n\x09 * @param ImageTimestamp The Zed image timestamp\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Retrieve the textures. Called inside the grab thread.\n* @param ImageTimestamp The Zed image timestamp" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTextureBatch, nullptr, "RetrieveCurrentFrame", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::SlTextureBatch_eventRetrieveCurrentFrame_Parms), Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics
	{
		struct SlTextureBatch_eventSetAsyncRetrieveEnabled_Parms
		{
			bool bEnabled;
		};
		static void NewProp_bEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
	{
		((SlTextureBatch_eventSetAsyncRetrieveEnabled_Parms*)Obj)->bEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlTextureBatch_eventSetAsyncRetrieveEnabled_Parms), &Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::NewProp_bEnabled,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Enable/Disable async retrieve\n\x09 * @param bEnabled True to enable\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Enable/Disable async retrieve\n* @param bEnabled True to enable" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTextureBatch, nullptr, "SetAsyncRetrieveEnabled", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::SlTextureBatch_eventSetAsyncRetrieveEnabled_Parms), Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTextureBatch_Tick_Statics
	{
		struct SlTextureBatch_eventTick_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USlTextureBatch_Tick_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlTextureBatch_eventTick_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlTextureBatch_Tick_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlTextureBatch_eventTick_Parms), &Z_Construct_UFunction_USlTextureBatch_Tick_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTextureBatch_Tick_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTextureBatch_Tick_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTextureBatch_Tick_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Tick the batch. Update the textures.\n\x09 * @return Single thread : Always return true.\n\x09 *\x09\x09   Multi thread  : True if textures updated.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Tick the batch. Update the textures.\n* @return Single thread : Always return true.\n*                 Multi thread  : True if textures updated." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTextureBatch_Tick_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTextureBatch, nullptr, "Tick", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTextureBatch_Tick_Statics::SlTextureBatch_eventTick_Parms), Z_Construct_UFunction_USlTextureBatch_Tick_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_Tick_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTextureBatch_Tick_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTextureBatch_Tick_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTextureBatch_Tick()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTextureBatch_Tick_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlTextureBatch);
	UClass* Z_Construct_UClass_USlTextureBatch_NoRegister()
	{
		return USlTextureBatch::StaticClass();
	}
	struct Z_Construct_UClass_USlTextureBatch_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlTextureBatch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlTextureBatch_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlTextureBatch_AddTexture, "AddTexture" }, // 738184814
		{ &Z_Construct_UFunction_USlTextureBatch_Clear, "Clear" }, // 2219817265
		{ &Z_Construct_UFunction_USlTextureBatch_RemoveTexture, "RemoveTexture" }, // 2768332475
		{ &Z_Construct_UFunction_USlTextureBatch_RetrieveCurrentFrame, "RetrieveCurrentFrame" }, // 2248981300
		{ &Z_Construct_UFunction_USlTextureBatch_SetAsyncRetrieveEnabled, "SetAsyncRetrieveEnabled" }, // 666456734
		{ &Z_Construct_UFunction_USlTextureBatch_Tick, "Tick" }, // 1657041322
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTextureBatch_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n * A batch that retrieve and update textures.\n */" },
		{ "IncludePath", "Core/StereolabsTextureBatch.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* A batch that retrieve and update textures." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlTextureBatch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlTextureBatch>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlTextureBatch_Statics::ClassParams = {
		&USlTextureBatch::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlTextureBatch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlTextureBatch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlTextureBatch()
	{
		if (!Z_Registration_Info_UClass_USlTextureBatch.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlTextureBatch.OuterSingleton, Z_Construct_UClass_USlTextureBatch_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlTextureBatch.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlTextureBatch>()
	{
		return USlTextureBatch::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlTextureBatch);
	DEFINE_FUNCTION(USlGPUTextureBatch::execCreateGPUTextureBatch)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlGPUTextureBatch**)Z_Param__Result=USlGPUTextureBatch::CreateGPUTextureBatch(Z_Param_Out_Name);
		P_NATIVE_END;
	}
	void USlGPUTextureBatch::StaticRegisterNativesUSlGPUTextureBatch()
	{
		UClass* Class = USlGPUTextureBatch::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateGPUTextureBatch", &USlGPUTextureBatch::execCreateGPUTextureBatch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics
	{
		struct SlGPUTextureBatch_eventCreateGPUTextureBatch_Parms
		{
			FName Name;
			USlGPUTextureBatch* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlGPUTextureBatch_eventCreateGPUTextureBatch_Parms, Name), METADATA_PARAMS(Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_Name_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlGPUTextureBatch_eventCreateGPUTextureBatch_Parms, ReturnValue), Z_Construct_UClass_USlGPUTextureBatch_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a GPU batch\n\x09 * @param Name\x09  The new name of the batch\n\x09 * @return\x09\x09  The batch\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Create a GPU batch\n* @param Name    The new name of the batch\n* @return                The batch" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlGPUTextureBatch, nullptr, "CreateGPUTextureBatch", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::SlGPUTextureBatch_eventCreateGPUTextureBatch_Parms), Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlGPUTextureBatch);
	UClass* Z_Construct_UClass_USlGPUTextureBatch_NoRegister()
	{
		return USlGPUTextureBatch::StaticClass();
	}
	struct Z_Construct_UClass_USlGPUTextureBatch_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlGPUTextureBatch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlTextureBatch,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlGPUTextureBatch_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlGPUTextureBatch_CreateGPUTextureBatch, "CreateGPUTextureBatch" }, // 2120027644
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlGPUTextureBatch_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n * Batch for GPU textures with Texture2D\n */" },
		{ "IncludePath", "Core/StereolabsTextureBatch.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Batch for GPU textures with Texture2D" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlGPUTextureBatch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlGPUTextureBatch>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlGPUTextureBatch_Statics::ClassParams = {
		&USlGPUTextureBatch::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlGPUTextureBatch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlGPUTextureBatch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlGPUTextureBatch()
	{
		if (!Z_Registration_Info_UClass_USlGPUTextureBatch.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlGPUTextureBatch.OuterSingleton, Z_Construct_UClass_USlGPUTextureBatch_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlGPUTextureBatch.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlGPUTextureBatch>()
	{
		return USlGPUTextureBatch::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlGPUTextureBatch);
	DEFINE_FUNCTION(USlSimpleGPUTextureBatch::execCreateSimpleGPUTextureBatch)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlSimpleGPUTextureBatch**)Z_Param__Result=USlSimpleGPUTextureBatch::CreateSimpleGPUTextureBatch(Z_Param_Out_Name);
		P_NATIVE_END;
	}
	void USlSimpleGPUTextureBatch::StaticRegisterNativesUSlSimpleGPUTextureBatch()
	{
		UClass* Class = USlSimpleGPUTextureBatch::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateSimpleGPUTextureBatch", &USlSimpleGPUTextureBatch::execCreateSimpleGPUTextureBatch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics
	{
		struct SlSimpleGPUTextureBatch_eventCreateSimpleGPUTextureBatch_Parms
		{
			FName Name;
			USlSimpleGPUTextureBatch* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlSimpleGPUTextureBatch_eventCreateSimpleGPUTextureBatch_Parms, Name), METADATA_PARAMS(Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_Name_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlSimpleGPUTextureBatch_eventCreateSimpleGPUTextureBatch_Parms, ReturnValue), Z_Construct_UClass_USlSimpleGPUTextureBatch_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a GPU batch\n\x09 * @param Name\x09  The new name of the batch\n\x09 * @return\x09\x09  The batch\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Create a GPU batch\n* @param Name    The new name of the batch\n* @return                The batch" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlSimpleGPUTextureBatch, nullptr, "CreateSimpleGPUTextureBatch", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::SlSimpleGPUTextureBatch_eventCreateSimpleGPUTextureBatch_Parms), Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlSimpleGPUTextureBatch);
	UClass* Z_Construct_UClass_USlSimpleGPUTextureBatch_NoRegister()
	{
		return USlSimpleGPUTextureBatch::StaticClass();
	}
	struct Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlTextureBatch,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlSimpleGPUTextureBatch_CreateSimpleGPUTextureBatch, "CreateSimpleGPUTextureBatch" }, // 1573995754
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n * Batch for GPU textures without Texture2D\n */" },
		{ "IncludePath", "Core/StereolabsTextureBatch.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Batch for GPU textures without Texture2D" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlSimpleGPUTextureBatch>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::ClassParams = {
		&USlSimpleGPUTextureBatch::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlSimpleGPUTextureBatch()
	{
		if (!Z_Registration_Info_UClass_USlSimpleGPUTextureBatch.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlSimpleGPUTextureBatch.OuterSingleton, Z_Construct_UClass_USlSimpleGPUTextureBatch_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlSimpleGPUTextureBatch.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlSimpleGPUTextureBatch>()
	{
		return USlSimpleGPUTextureBatch::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlSimpleGPUTextureBatch);
	DEFINE_FUNCTION(USlCPUTextureBatch::execCreateCPUTextureBatch)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlCPUTextureBatch**)Z_Param__Result=USlCPUTextureBatch::CreateCPUTextureBatch(Z_Param_Out_Name);
		P_NATIVE_END;
	}
	void USlCPUTextureBatch::StaticRegisterNativesUSlCPUTextureBatch()
	{
		UClass* Class = USlCPUTextureBatch::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateCPUTextureBatch", &USlCPUTextureBatch::execCreateCPUTextureBatch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics
	{
		struct SlCPUTextureBatch_eventCreateCPUTextureBatch_Parms
		{
			FName Name;
			USlCPUTextureBatch* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlCPUTextureBatch_eventCreateCPUTextureBatch_Parms, Name), METADATA_PARAMS(Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_Name_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlCPUTextureBatch_eventCreateCPUTextureBatch_Parms, ReturnValue), Z_Construct_UClass_USlCPUTextureBatch_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a CPU batch\n\x09 * @param Name\x09  The new name of the batch\n\x09 * @return\x09\x09  The batch\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Create a CPU batch\n* @param Name    The new name of the batch\n* @return                The batch" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlCPUTextureBatch, nullptr, "CreateCPUTextureBatch", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::SlCPUTextureBatch_eventCreateCPUTextureBatch_Parms), Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlCPUTextureBatch);
	UClass* Z_Construct_UClass_USlCPUTextureBatch_NoRegister()
	{
		return USlCPUTextureBatch::StaticClass();
	}
	struct Z_Construct_UClass_USlCPUTextureBatch_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlCPUTextureBatch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlTextureBatch,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlCPUTextureBatch_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlCPUTextureBatch_CreateCPUTextureBatch, "CreateCPUTextureBatch" }, // 3325035512
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlCPUTextureBatch_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n * Batch for CPU textures\n */" },
		{ "IncludePath", "Core/StereolabsTextureBatch.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTextureBatch.h" },
		{ "ToolTip", "* Batch for CPU textures" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlCPUTextureBatch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlCPUTextureBatch>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlCPUTextureBatch_Statics::ClassParams = {
		&USlCPUTextureBatch::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlCPUTextureBatch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlCPUTextureBatch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlCPUTextureBatch()
	{
		if (!Z_Registration_Info_UClass_USlCPUTextureBatch.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlCPUTextureBatch.OuterSingleton, Z_Construct_UClass_USlCPUTextureBatch_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlCPUTextureBatch.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlCPUTextureBatch>()
	{
		return USlCPUTextureBatch::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlCPUTextureBatch);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USlTextureBatch, USlTextureBatch::StaticClass, TEXT("USlTextureBatch"), &Z_Registration_Info_UClass_USlTextureBatch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlTextureBatch), 3935725716U) },
		{ Z_Construct_UClass_USlGPUTextureBatch, USlGPUTextureBatch::StaticClass, TEXT("USlGPUTextureBatch"), &Z_Registration_Info_UClass_USlGPUTextureBatch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlGPUTextureBatch), 1605912388U) },
		{ Z_Construct_UClass_USlSimpleGPUTextureBatch, USlSimpleGPUTextureBatch::StaticClass, TEXT("USlSimpleGPUTextureBatch"), &Z_Registration_Info_UClass_USlSimpleGPUTextureBatch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlSimpleGPUTextureBatch), 4151435135U) },
		{ Z_Construct_UClass_USlCPUTextureBatch, USlCPUTextureBatch::StaticClass, TEXT("USlCPUTextureBatch"), &Z_Registration_Info_UClass_USlCPUTextureBatch, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlCPUTextureBatch), 2577302174U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_4209577859(TEXT("/Script/Stereolabs"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTextureBatch_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
