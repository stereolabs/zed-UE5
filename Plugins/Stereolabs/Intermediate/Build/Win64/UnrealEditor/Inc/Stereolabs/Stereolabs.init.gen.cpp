// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabs_init() {}
	STEREOLABS_API UFunction* Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyDelegate__DelegateSignature();
	STEREOLABS_API UFunction* Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyOneParamDelegate__DelegateSignature();
	STEREOLABS_API UFunction* Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxySpatialMappingPausedDelegate__DelegateSignature();
	STEREOLABS_API UFunction* Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyTrackingDelegate__DelegateSignature();
	STEREOLABS_API UFunction* Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyTwoParamsDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Stereolabs;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Stereolabs()
	{
		if (!Z_Registration_Info_UPackage__Script_Stereolabs.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyOneParamDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxySpatialMappingPausedDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyTrackingDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_Stereolabs_SlCameraProxyTwoParamsDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Stereolabs",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x9951EBE2,
				0xA9CF1458,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Stereolabs.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Stereolabs.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Stereolabs(Z_Construct_UPackage__Script_Stereolabs, TEXT("/Script/Stereolabs"), Z_Registration_Info_UPackage__Script_Stereolabs, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x9951EBE2, 0xA9CF1458));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
