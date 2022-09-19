// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDevices_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Devices;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Devices()
	{
		if (!Z_Registration_Info_UPackage__Script_Devices.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Devices",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xAECC196C,
				0x03FB32A1,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Devices.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Devices.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Devices(Z_Construct_UPackage__Script_Devices, TEXT("/Script/Devices"), Z_Registration_Info_UPackage__Script_Devices, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xAECC196C, 0x03FB32A1));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
