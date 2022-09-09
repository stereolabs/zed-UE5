// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpatialMapping/Public/Core/SpatialMappingCubemapManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpatialMappingCubemapManager() {}
// Cross Module References
	SPATIALMAPPING_API UFunction* Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SpatialMapping();
	ENGINE_API UClass* Z_Construct_UClass_UTextureCube_NoRegister();
	SPATIALMAPPING_API UClass* Z_Construct_UClass_ASpatialMappingCubemapManager_NoRegister();
	SPATIALMAPPING_API UClass* Z_Construct_UClass_ASpatialMappingCubemapManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTargetCube_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponentCube_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics
	{
		struct _Script_SpatialMapping_eventSpatialMappingCubemapDelegate_Parms
		{
			UTextureCube* Cubemap;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Cubemap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::NewProp_Cubemap = { "Cubemap", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SpatialMapping_eventSpatialMappingCubemapDelegate_Parms, Cubemap), Z_Construct_UClass_UTextureCube_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::NewProp_Cubemap,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n * \n */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SpatialMapping, nullptr, "SpatialMappingCubemapDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::_Script_SpatialMapping_eventSpatialMappingCubemapDelegate_Parms), Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ASpatialMappingCubemapManager::execSetTextureTarget)
	{
		P_GET_OBJECT(UTextureRenderTargetCube,Z_Param_NewTextureTarget);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->SetTextureTarget(Z_Param_NewTextureTarget);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASpatialMappingCubemapManager::execCaptureScene)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CaptureScene();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASpatialMappingCubemapManager::execBuildCubemap)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->BuildCubemap(Z_Param_Out_Name);
		P_NATIVE_END;
	}
	void ASpatialMappingCubemapManager::StaticRegisterNativesASpatialMappingCubemapManager()
	{
		UClass* Class = ASpatialMappingCubemapManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BuildCubemap", &ASpatialMappingCubemapManager::execBuildCubemap },
			{ "CaptureScene", &ASpatialMappingCubemapManager::execCaptureScene },
			{ "SetTextureTarget", &ASpatialMappingCubemapManager::execSetTextureTarget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics
	{
		struct SpatialMappingCubemapManager_eventBuildCubemap_Parms
		{
			FName Name;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SpatialMappingCubemapManager_eventBuildCubemap_Parms, Name), METADATA_PARAMS(Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_Name_MetaData)) };
	void Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SpatialMappingCubemapManager_eventBuildCubemap_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SpatialMappingCubemapManager_eventBuildCubemap_Parms), &Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Cubemap" },
		{ "Comment", "/*\n\x09 * Build the cubemap asynchronously\n\x09 * @param Name The name of the texture\n\x09 * @return False if the build can't be done because previous build is not finished\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "* Build the cubemap asynchronously\n* @param Name The name of the texture\n* @return False if the build can't be done because previous build is not finished" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpatialMappingCubemapManager, nullptr, "BuildCubemap", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::SpatialMappingCubemapManager_eventBuildCubemap_Parms), Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Cubemap" },
		{ "Comment", "/*\n\x09 * Capture the scene at the current actor location and orientation\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "* Capture the scene at the current actor location and orientation" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpatialMappingCubemapManager, nullptr, "CaptureScene", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics
	{
		struct SpatialMappingCubemapManager_eventSetTextureTarget_Parms
		{
			UTextureRenderTargetCube* NewTextureTarget;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTextureTarget;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::NewProp_NewTextureTarget = { "NewTextureTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SpatialMappingCubemapManager_eventSetTextureTarget_Parms, NewTextureTarget), Z_Construct_UClass_UTextureRenderTargetCube_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SpatialMappingCubemapManager_eventSetTextureTarget_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SpatialMappingCubemapManager_eventSetTextureTarget_Parms), &Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::NewProp_NewTextureTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Cubemap" },
		{ "Comment", "/*\n\x09 * Set the new texture target\n\x09 * @param NewTextureTarget The new texture target to render the scene to\n\x09 * @return True if the texture is set\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "* Set the new texture target\n* @param NewTextureTarget The new texture target to render the scene to\n* @return True if the texture is set" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASpatialMappingCubemapManager, nullptr, "SetTextureTarget", nullptr, nullptr, sizeof(Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::SpatialMappingCubemapManager_eventSetTextureTarget_Parms), Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpatialMappingCubemapManager);
	UClass* Z_Construct_UClass_ASpatialMappingCubemapManager_NoRegister()
	{
		return ASpatialMappingCubemapManager::StaticClass();
	}
	struct Z_Construct_UClass_ASpatialMappingCubemapManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnCubemapBuildComplete_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCubemapBuildComplete;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextureTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TextureTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Cubemap_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Cubemap;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SpatialMapping,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASpatialMappingCubemapManager_BuildCubemap, "BuildCubemap" }, // 3690948769
		{ &Z_Construct_UFunction_ASpatialMappingCubemapManager_CaptureScene, "CaptureScene" }, // 4053319860
		{ &Z_Construct_UFunction_ASpatialMappingCubemapManager_SetTextureTarget, "SetTextureTarget" }, // 477380788
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|SpatialMapping" },
		{ "Comment", "/*\n * Asynchronously build a cubemap\n */" },
		{ "IncludePath", "Core/SpatialMappingCubemapManager.h" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "* Asynchronously build a cubemap" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_OnCubemapBuildComplete_MetaData[] = {
		{ "Category", "Zed|Cubemap" },
		{ "Comment", "/** Cubemap build complete dispatcher  */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "Cubemap build complete dispatcher" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_OnCubemapBuildComplete = { "OnCubemapBuildComplete", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpatialMappingCubemapManager, OnCubemapBuildComplete), Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_OnCubemapBuildComplete_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_OnCubemapBuildComplete_MetaData)) }; // 3101279769
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_TextureTarget_MetaData[] = {
		{ "Category", "Zed|Cubemap" },
		{ "Comment", "/** Camera render target */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "Camera render target" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_TextureTarget = { "TextureTarget", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpatialMappingCubemapManager, TextureTarget), Z_Construct_UClass_UTextureRenderTargetCube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_TextureTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_TextureTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "SpatialMappingCubemapManager" },
		{ "Comment", "/** Camera used to capture the cubemap */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "Camera used to capture the cubemap" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x001000000008001c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpatialMappingCubemapManager, Camera), Z_Construct_UClass_USceneCaptureComponentCube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Cubemap_MetaData[] = {
		{ "Comment", "/** Cubemap being updated */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingCubemapManager.h" },
		{ "ToolTip", "Cubemap being updated" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Cubemap = { "Cubemap", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASpatialMappingCubemapManager, Cubemap), Z_Construct_UClass_UTextureCube_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Cubemap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Cubemap_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_OnCubemapBuildComplete,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_TextureTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Camera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::NewProp_Cubemap,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpatialMappingCubemapManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::ClassParams = {
		&ASpatialMappingCubemapManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASpatialMappingCubemapManager()
	{
		if (!Z_Registration_Info_UClass_ASpatialMappingCubemapManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpatialMappingCubemapManager.OuterSingleton, Z_Construct_UClass_ASpatialMappingCubemapManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASpatialMappingCubemapManager.OuterSingleton;
	}
	template<> SPATIALMAPPING_API UClass* StaticClass<ASpatialMappingCubemapManager>()
	{
		return ASpatialMappingCubemapManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpatialMappingCubemapManager);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASpatialMappingCubemapManager, ASpatialMappingCubemapManager::StaticClass, TEXT("ASpatialMappingCubemapManager"), &Z_Registration_Info_UClass_ASpatialMappingCubemapManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpatialMappingCubemapManager), 2898437131U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_844668938(TEXT("/Script/SpatialMapping"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingCubemapManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
