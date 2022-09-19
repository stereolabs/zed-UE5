// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpatialMapping_init() {}
	SPATIALMAPPING_API UFunction* Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature();
	SPATIALMAPPING_API UFunction* Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingManagerDelegate__DelegateSignature();
	SPATIALMAPPING_API UFunction* Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingManagerMeshDelegate__DelegateSignature();
	SPATIALMAPPING_API UFunction* Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingStepFailedDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SpatialMapping;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SpatialMapping()
	{
		if (!Z_Registration_Info_UPackage__Script_SpatialMapping.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingCubemapDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingManagerDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingManagerMeshDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SpatialMapping_SpatialMappingStepFailedDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SpatialMapping",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x294D361E,
				0x2C151F95,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SpatialMapping.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SpatialMapping.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SpatialMapping(Z_Construct_UPackage__Script_SpatialMapping, TEXT("/Script/SpatialMapping"), Z_Registration_Info_UPackage__Script_SpatialMapping, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x294D361E, 0x2C151F95));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
