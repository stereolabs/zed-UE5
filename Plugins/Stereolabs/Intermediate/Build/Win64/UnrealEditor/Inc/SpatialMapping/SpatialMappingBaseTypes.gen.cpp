// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SpatialMapping/Public/Core/SpatialMappingBaseTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpatialMappingBaseTypes() {}
// Cross Module References
	SPATIALMAPPING_API UEnum* Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep();
	UPackage* Z_Construct_UPackage__Script_SpatialMapping();
	SPATIALMAPPING_API UEnum* Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESpatialMappingStep;
	static UEnum* ESpatialMappingStep_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESpatialMappingStep.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESpatialMappingStep.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep, Z_Construct_UPackage__Script_SpatialMapping(), TEXT("ESpatialMappingStep"));
		}
		return Z_Registration_Info_UEnum_ESpatialMappingStep.OuterSingleton;
	}
	template<> SPATIALMAPPING_API UEnum* StaticEnum<ESpatialMappingStep>()
	{
		return ESpatialMappingStep_StaticEnum();
	}
	struct Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::Enumerators[] = {
		{ "ESpatialMappingStep::SS_Scan", (int64)ESpatialMappingStep::SS_Scan },
		{ "ESpatialMappingStep::SS_Filter", (int64)ESpatialMappingStep::SS_Filter },
		{ "ESpatialMappingStep::SS_Texture", (int64)ESpatialMappingStep::SS_Texture },
		{ "ESpatialMappingStep::SS_Load", (int64)ESpatialMappingStep::SS_Load },
		{ "ESpatialMappingStep::SS_Save", (int64)ESpatialMappingStep::SS_Save },
		{ "ESpatialMappingStep::SS_Pause", (int64)ESpatialMappingStep::SS_Pause },
		{ "ESpatialMappingStep::SS_None", (int64)ESpatialMappingStep::SS_None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::Enum_MetaDataParams[] = {
		{ "Comment", "/*\n * Current step of SpatialMapping\n */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingBaseTypes.h" },
		{ "SS_Filter.DisplayName", "Filtering" },
		{ "SS_Filter.Name", "ESpatialMappingStep::SS_Filter" },
		{ "SS_Load.DisplayName", "Loading" },
		{ "SS_Load.Name", "ESpatialMappingStep::SS_Load" },
		{ "SS_None.DisplayName", "None" },
		{ "SS_None.Hidden", "" },
		{ "SS_None.Name", "ESpatialMappingStep::SS_None" },
		{ "SS_Pause.DisplayName", "Pause" },
		{ "SS_Pause.Name", "ESpatialMappingStep::SS_Pause" },
		{ "SS_Save.DisplayName", "Saving" },
		{ "SS_Save.Name", "ESpatialMappingStep::SS_Save" },
		{ "SS_Scan.DisplayName", "SpatialMapping" },
		{ "SS_Scan.Name", "ESpatialMappingStep::SS_Scan" },
		{ "SS_Texture.DisplayName", "Texturing" },
		{ "SS_Texture.Name", "ESpatialMappingStep::SS_Texture" },
		{ "ToolTip", "* Current step of SpatialMapping" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SpatialMapping,
		nullptr,
		"ESpatialMappingStep",
		"ESpatialMappingStep",
		Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep()
	{
		if (!Z_Registration_Info_UEnum_ESpatialMappingStep.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESpatialMappingStep.InnerSingleton, Z_Construct_UEnum_SpatialMapping_ESpatialMappingStep_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESpatialMappingStep.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESpatialMappingTexturingMode;
	static UEnum* ESpatialMappingTexturingMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESpatialMappingTexturingMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESpatialMappingTexturingMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode, Z_Construct_UPackage__Script_SpatialMapping(), TEXT("ESpatialMappingTexturingMode"));
		}
		return Z_Registration_Info_UEnum_ESpatialMappingTexturingMode.OuterSingleton;
	}
	template<> SPATIALMAPPING_API UEnum* StaticEnum<ESpatialMappingTexturingMode>()
	{
		return ESpatialMappingTexturingMode_StaticEnum();
	}
	struct Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::Enumerators[] = {
		{ "ESpatialMappingTexturingMode::TM_Cubemap", (int64)ESpatialMappingTexturingMode::TM_Cubemap },
		{ "ESpatialMappingTexturingMode::TM_Render", (int64)ESpatialMappingTexturingMode::TM_Render },
		{ "ESpatialMappingTexturingMode::TM_None", (int64)ESpatialMappingTexturingMode::TM_None },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Stereolabs|SpatialMapping|Enum" },
		{ "Comment", "/*\n *\n */" },
		{ "ModuleRelativePath", "Public/Core/SpatialMappingBaseTypes.h" },
		{ "TM_Cubemap.Comment", "/*\n *\n */" },
		{ "TM_Cubemap.DisplayName", "Cubemap" },
		{ "TM_Cubemap.Name", "ESpatialMappingTexturingMode::TM_Cubemap" },
		{ "TM_None.Comment", "/*\n *\n */" },
		{ "TM_None.DisplayName", "None" },
		{ "TM_None.Hidden", "" },
		{ "TM_None.Name", "ESpatialMappingTexturingMode::TM_None" },
		{ "TM_Render.Comment", "/*\n *\n */" },
		{ "TM_Render.DisplayName", "Render" },
		{ "TM_Render.Name", "ESpatialMappingTexturingMode::TM_Render" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SpatialMapping,
		nullptr,
		"ESpatialMappingTexturingMode",
		"ESpatialMappingTexturingMode",
		Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode()
	{
		if (!Z_Registration_Info_UEnum_ESpatialMappingTexturingMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESpatialMappingTexturingMode.InnerSingleton, Z_Construct_UEnum_SpatialMapping_ESpatialMappingTexturingMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESpatialMappingTexturingMode.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingBaseTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingBaseTypes_h_Statics::EnumInfo[] = {
		{ ESpatialMappingStep_StaticEnum, TEXT("ESpatialMappingStep"), &Z_Registration_Info_UEnum_ESpatialMappingStep, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2991485157U) },
		{ ESpatialMappingTexturingMode_StaticEnum, TEXT("ESpatialMappingTexturingMode"), &Z_Registration_Info_UEnum_ESpatialMappingTexturingMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2595257810U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingBaseTypes_h_3820099663(TEXT("/Script/SpatialMapping"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingBaseTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingBaseTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
