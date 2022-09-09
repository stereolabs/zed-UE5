// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Classes/ZEDGameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDGameInstance() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_UZEDGameInstance_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_ZED();
// End Cross Module References
	void UZEDGameInstance::StaticRegisterNativesUZEDGameInstance()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZEDGameInstance);
	UClass* Z_Construct_UClass_UZEDGameInstance_NoRegister()
	{
		return UZEDGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UZEDGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZEDGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDGameInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ZEDGameInstance.h" },
		{ "ModuleRelativePath", "Classes/ZEDGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZEDGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZEDGameInstance>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZEDGameInstance_Statics::ClassParams = {
		&UZEDGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UZEDGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZEDGameInstance()
	{
		if (!Z_Registration_Info_UClass_UZEDGameInstance.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZEDGameInstance.OuterSingleton, Z_Construct_UClass_UZEDGameInstance_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZEDGameInstance.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<UZEDGameInstance>()
	{
		return UZEDGameInstance::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZEDGameInstance);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameInstance_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameInstance_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZEDGameInstance, UZEDGameInstance::StaticClass, TEXT("UZEDGameInstance"), &Z_Registration_Info_UClass_UZEDGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZEDGameInstance), 1025595401U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameInstance_h_2375113538(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDGameInstance_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
