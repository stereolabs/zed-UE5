// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZED_init() {}
	ZED_API UFunction* Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature();
	ZED_API UFunction* Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature();
	ZED_API UFunction* Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ZED;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ZED()
	{
		if (!Z_Registration_Info_UPackage__Script_ZED.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ZED",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xB77D3B88,
				0xF01AF69A,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ZED.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ZED.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ZED(Z_Construct_UPackage__Script_ZED, TEXT("/Script/ZED"), Z_Registration_Info_UPackage__Script_ZED, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xB77D3B88, 0xF01AF69A));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
