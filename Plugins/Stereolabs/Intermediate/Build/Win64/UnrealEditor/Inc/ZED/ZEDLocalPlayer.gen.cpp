// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Classes/ZEDLocalPlayer.h"
#include "Engine/Classes/Engine/Engine.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDLocalPlayer() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_UZEDLocalPlayer_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDLocalPlayer();
	ENGINE_API UClass* Z_Construct_UClass_ULocalPlayer();
	UPackage* Z_Construct_UPackage__Script_ZED();
// End Cross Module References
	void UZEDLocalPlayer::StaticRegisterNativesUZEDLocalPlayer()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZEDLocalPlayer);
	UClass* Z_Construct_UClass_UZEDLocalPlayer_NoRegister()
	{
		return UZEDLocalPlayer::StaticClass();
	}
	struct Z_Construct_UClass_UZEDLocalPlayer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZEDLocalPlayer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ULocalPlayer,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDLocalPlayer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ZEDLocalPlayer.h" },
		{ "ModuleRelativePath", "Classes/ZEDLocalPlayer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZEDLocalPlayer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZEDLocalPlayer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZEDLocalPlayer_Statics::ClassParams = {
		&UZEDLocalPlayer::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UZEDLocalPlayer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDLocalPlayer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZEDLocalPlayer()
	{
		if (!Z_Registration_Info_UClass_UZEDLocalPlayer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZEDLocalPlayer.OuterSingleton, Z_Construct_UClass_UZEDLocalPlayer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZEDLocalPlayer.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<UZEDLocalPlayer>()
	{
		return UZEDLocalPlayer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZEDLocalPlayer);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDLocalPlayer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDLocalPlayer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZEDLocalPlayer, UZEDLocalPlayer::StaticClass, TEXT("UZEDLocalPlayer"), &Z_Registration_Info_UClass_UZEDLocalPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZEDLocalPlayer), 2995754366U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDLocalPlayer_h_1084486215(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDLocalPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Classes_ZEDLocalPlayer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
