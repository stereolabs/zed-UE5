// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Classes/ZEDGameViewportClient.h"
#include "Engine/Classes/Engine/Engine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDGameViewportClient() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_UZEDGameViewportClient_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDGameViewportClient();
	ENGINE_API UClass* Z_Construct_UClass_UGameViewportClient();
	UPackage* Z_Construct_UPackage__Script_ZED();
// End Cross Module References
	void UZEDGameViewportClient::StaticRegisterNativesUZEDGameViewportClient()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZEDGameViewportClient);
	UClass* Z_Construct_UClass_UZEDGameViewportClient_NoRegister()
	{
		return UZEDGameViewportClient::StaticClass();
	}
	struct Z_Construct_UClass_UZEDGameViewportClient_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZEDGameViewportClient_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameViewportClient,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDGameViewportClient_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ZEDGameViewportClient.h" },
		{ "ModuleRelativePath", "Classes/ZEDGameViewportClient.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZEDGameViewportClient_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZEDGameViewportClient>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZEDGameViewportClient_Statics::ClassParams = {
		&UZEDGameViewportClient::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000ACu,
		METADATA_PARAMS(Z_Construct_UClass_UZEDGameViewportClient_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDGameViewportClient_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZEDGameViewportClient()
	{
		if (!Z_Registration_Info_UClass_UZEDGameViewportClient.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZEDGameViewportClient.OuterSingleton, Z_Construct_UClass_UZEDGameViewportClient_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZEDGameViewportClient.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<UZEDGameViewportClient>()
	{
		return UZEDGameViewportClient::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZEDGameViewportClient);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameViewportClient_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameViewportClient_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZEDGameViewportClient, UZEDGameViewportClient::StaticClass, TEXT("UZEDGameViewportClient"), &Z_Registration_Info_UClass_UZEDGameViewportClient, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZEDGameViewportClient), 692580700U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameViewportClient_h_1285776888(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameViewportClient_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameViewportClient_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
