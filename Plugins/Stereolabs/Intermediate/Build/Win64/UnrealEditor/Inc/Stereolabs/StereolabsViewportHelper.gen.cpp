// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Utilities/StereolabsViewportHelper.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsViewportHelper() {}
// Cross Module References
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlViewportHelper();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SlViewportHelper;
class UScriptStruct* FSlViewportHelper::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SlViewportHelper.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SlViewportHelper.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSlViewportHelper, Z_Construct_UPackage__Script_Stereolabs(), TEXT("SlViewportHelper"));
	}
	return Z_Registration_Info_UScriptStruct_SlViewportHelper.OuterSingleton;
}
template<> STEREOLABS_API UScriptStruct* StaticStruct<FSlViewportHelper>()
{
	return FSlViewportHelper::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSlViewportHelper_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSlViewportHelper_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/*\n * Helper class to cache viewport data\n *\n * Example :\n *\n * UGameViewportClient* GameViewport = GetLocalPlayer()->ViewportClient;\n * check(GameViewport);\n *\n *\x09if (!UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())\n *  {\n *\x09\x09ViewportHelper.AddToViewportResizeEvent(GameViewport);\n *\x09}\n *\n *\x09ViewportHelper.Update(GameViewport->Viewport->GetSizeXY());\n *\n */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsViewportHelper.h" },
		{ "ToolTip", "* Helper class to cache viewport data\n*\n* Example :\n*\n* UGameViewportClient* GameViewport = GetLocalPlayer()->ViewportClient;\n* check(GameViewport);\n*\n*     if (!UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())\n*  {\n*             ViewportHelper.AddToViewportResizeEvent(GameViewport);\n*     }\n*\n*     ViewportHelper.Update(GameViewport->Viewport->GetSizeXY());" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSlViewportHelper_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSlViewportHelper>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSlViewportHelper_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
		nullptr,
		&NewStructOps,
		"SlViewportHelper",
		sizeof(FSlViewportHelper),
		alignof(FSlViewportHelper),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSlViewportHelper_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSlViewportHelper_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSlViewportHelper()
	{
		if (!Z_Registration_Info_UScriptStruct_SlViewportHelper.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SlViewportHelper.InnerSingleton, Z_Construct_UScriptStruct_FSlViewportHelper_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SlViewportHelper.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsViewportHelper_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsViewportHelper_h_Statics::ScriptStructInfo[] = {
		{ FSlViewportHelper::StaticStruct, Z_Construct_UScriptStruct_FSlViewportHelper_Statics::NewStructOps, TEXT("SlViewportHelper"), &Z_Registration_Info_UScriptStruct_SlViewportHelper, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSlViewportHelper), 3743845575U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsViewportHelper_h_3622405464(TEXT("/Script/Stereolabs"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsViewportHelper_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsViewportHelper_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
