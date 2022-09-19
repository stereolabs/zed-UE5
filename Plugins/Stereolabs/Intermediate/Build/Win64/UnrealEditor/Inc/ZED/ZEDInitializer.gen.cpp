// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZEDInitializer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDInitializer() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_AZEDInitializer_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDInitializer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ZED();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlInitParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlPositionalTrackingParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlRecordingParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlRuntimeParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlRenderingParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectDetectionParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectDetectionRuntimeParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlVideoSettings();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AZEDInitializer::execResetSettings)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetSettings();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDInitializer::execResetParameters)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetParameters();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDInitializer::execSaveCameraSettings)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveCameraSettings();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDInitializer::execSaveParameters)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveParameters();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDInitializer::execLoadCameraSettings)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadCameraSettings();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDInitializer::execLoadParameters)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadParameters();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDInitializer::execLoadParametersAndSettings)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LoadParametersAndSettings();
		P_NATIVE_END;
	}
	void AZEDInitializer::StaticRegisterNativesAZEDInitializer()
	{
		UClass* Class = AZEDInitializer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "LoadCameraSettings", &AZEDInitializer::execLoadCameraSettings },
			{ "LoadParameters", &AZEDInitializer::execLoadParameters },
			{ "LoadParametersAndSettings", &AZEDInitializer::execLoadParametersAndSettings },
			{ "ResetParameters", &AZEDInitializer::execResetParameters },
			{ "ResetSettings", &AZEDInitializer::execResetSettings },
			{ "SaveCameraSettings", &AZEDInitializer::execSaveCameraSettings },
			{ "SaveParameters", &AZEDInitializer::execSaveParameters },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/* \n\x09 * Load camera settings \n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Load camera settings" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "LoadCameraSettings", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDInitializer_LoadParameters_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_LoadParameters_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Load config parameters \n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Load config parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_LoadParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "LoadParameters", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_LoadParameters_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_LoadParameters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_LoadParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_LoadParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/* \n\x09 * Load all parameters and settings\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Load all parameters and settings" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "LoadParametersAndSettings", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDInitializer_ResetParameters_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_ResetParameters_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Reset parameters\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Reset parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_ResetParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "ResetParameters", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_ResetParameters_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_ResetParameters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_ResetParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_ResetParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDInitializer_ResetSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_ResetSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Reset camera settings\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Reset camera settings" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_ResetSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "ResetSettings", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_ResetSettings_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_ResetSettings_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_ResetSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_ResetSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Load camera settings \n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Load camera settings" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "SaveCameraSettings", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDInitializer_SaveParameters_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDInitializer_SaveParameters_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/* \n\x09 * Load config parameters \n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Load config parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDInitializer_SaveParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDInitializer, nullptr, "SaveParameters", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDInitializer_SaveParameters_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDInitializer_SaveParameters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDInitializer_SaveParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDInitializer_SaveParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZEDInitializer);
	UClass* Z_Construct_UClass_AZEDInitializer_NoRegister()
	{
		return AZEDInitializer::StaticClass();
	}
	struct Z_Construct_UClass_AZEDInitializer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InitParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InitParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackingParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TrackingParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RecordingParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RecordingParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderingParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RenderingParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDetectionParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDetectionParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDetectionRuntimeParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDetectionRuntimeParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CameraSettings;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ChildActors_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChildActors_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ChildActors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLoadParametersFromConfigFile_MetaData[];
#endif
		static void NewProp_bLoadParametersFromConfigFile_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoadParametersFromConfigFile;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLoadCameraSettingsFromConfigFile_MetaData[];
#endif
		static void NewProp_bLoadCameraSettingsFromConfigFile_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoadCameraSettingsFromConfigFile;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDepthOcclusion_MetaData[];
#endif
		static void NewProp_bDepthOcclusion_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDepthOcclusion;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShowZedImage_MetaData[];
#endif
		static void NewProp_bShowZedImage_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowZedImage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepthClampThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthClampThreshold;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZEDInitializer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZEDInitializer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZEDInitializer_LoadCameraSettings, "LoadCameraSettings" }, // 1076762710
		{ &Z_Construct_UFunction_AZEDInitializer_LoadParameters, "LoadParameters" }, // 675099809
		{ &Z_Construct_UFunction_AZEDInitializer_LoadParametersAndSettings, "LoadParametersAndSettings" }, // 1035836008
		{ &Z_Construct_UFunction_AZEDInitializer_ResetParameters, "ResetParameters" }, // 981243596
		{ &Z_Construct_UFunction_AZEDInitializer_ResetSettings, "ResetSettings" }, // 2738069673
		{ &Z_Construct_UFunction_AZEDInitializer_SaveCameraSettings, "SaveCameraSettings" }, // 2085162453
		{ &Z_Construct_UFunction_AZEDInitializer_SaveParameters, "SaveParameters" }, // 3132326822
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n * Actor used to initialize Zed camera using configuration file\n */" },
		{ "IncludePath", "Core/ZEDInitializer.h" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Actor used to initialize Zed camera using configuration file" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_InitParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Init parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Init parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_InitParameters = { "InitParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, InitParameters), Z_Construct_UScriptStruct_FSlInitParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_InitParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_InitParameters_MetaData)) }; // 4138552183
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_TrackingParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Tracking parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Tracking parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_TrackingParameters = { "TrackingParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, TrackingParameters), Z_Construct_UScriptStruct_FSlPositionalTrackingParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_TrackingParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_TrackingParameters_MetaData)) }; // 3003434810
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RecordingParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Recording parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Recording parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RecordingParameters = { "RecordingParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, RecordingParameters), Z_Construct_UScriptStruct_FSlRecordingParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RecordingParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RecordingParameters_MetaData)) }; // 2111381437
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RuntimeParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Runtime parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Runtime parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RuntimeParameters = { "RuntimeParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, RuntimeParameters), Z_Construct_UScriptStruct_FSlRuntimeParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RuntimeParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RuntimeParameters_MetaData)) }; // 1216080694
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RenderingParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Rendering parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Rendering parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RenderingParameters = { "RenderingParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, RenderingParameters), Z_Construct_UScriptStruct_FSlRenderingParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RenderingParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RenderingParameters_MetaData)) }; // 3401118034
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/* Object Detection parameters*/" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Object Detection parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionParameters = { "ObjectDetectionParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, ObjectDetectionParameters), Z_Construct_UScriptStruct_FSlObjectDetectionParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionParameters_MetaData)) }; // 2617711556
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/* Object Detection runtime parameters*/" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Object Detection runtime parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionRuntimeParameters = { "ObjectDetectionRuntimeParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, ObjectDetectionRuntimeParameters), Z_Construct_UScriptStruct_FSlObjectDetectionRuntimeParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData)) }; // 3422687885
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_CameraSettings_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Camera settings */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Camera settings" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_CameraSettings = { "CameraSettings", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, CameraSettings), Z_Construct_UScriptStruct_FSlVideoSettings, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_CameraSettings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_CameraSettings_MetaData)) }; // 3695001135
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors_Inner = { "ChildActors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Actors that will be attached to the pawn at startup. Actor's Transform will be local, and body weld. */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Actors that will be attached to the pawn at startup. Actor's Transform will be local, and body weld." },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors = { "ChildActors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, ChildActors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Load parameters at runtime from config file and override preset */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Load parameters at runtime from config file and override preset" },
	};
#endif
	void Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile_SetBit(void* Obj)
	{
		((AZEDInitializer*)Obj)->bLoadParametersFromConfigFile = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile = { "bLoadParametersFromConfigFile", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AZEDInitializer), &Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Load camera settings at runtime from config file and override preset  */" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "Load camera settings at runtime from config file and override preset" },
	};
#endif
	void Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile_SetBit(void* Obj)
	{
		((AZEDInitializer*)Obj)->bLoadCameraSettingsFromConfigFile = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile = { "bLoadCameraSettingsFromConfigFile", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AZEDInitializer), &Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion_MetaData[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
	};
#endif
	void Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion_SetBit(void* Obj)
	{
		((AZEDInitializer*)Obj)->bDepthOcclusion = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion = { "bDepthOcclusion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AZEDInitializer), &Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage_MetaData[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
	};
#endif
	void Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage_SetBit(void* Obj)
	{
		((AZEDInitializer*)Obj)->bShowZedImage = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage = { "bShowZedImage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AZEDInitializer), &Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDInitializer_Statics::NewProp_DepthClampThreshold_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09* Can be used for Background substaction application.\n\x09* If the depth of the image is greater than this threshold, shows the virtual scene instead\n\x09*/" },
		{ "ModuleRelativePath", "Public/Core/ZEDInitializer.h" },
		{ "ToolTip", "* Can be used for Background substaction application.\n* If the depth of the image is greater than this threshold, shows the virtual scene instead" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZEDInitializer_Statics::NewProp_DepthClampThreshold = { "DepthClampThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDInitializer, DepthClampThreshold), METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_DepthClampThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::NewProp_DepthClampThreshold_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZEDInitializer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_InitParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_TrackingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RecordingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RuntimeParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_RenderingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ObjectDetectionRuntimeParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_CameraSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_ChildActors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadParametersFromConfigFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bLoadCameraSettingsFromConfigFile,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bDepthOcclusion,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_bShowZedImage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDInitializer_Statics::NewProp_DepthClampThreshold,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZEDInitializer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZEDInitializer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZEDInitializer_Statics::ClassParams = {
		&AZEDInitializer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZEDInitializer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZEDInitializer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDInitializer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZEDInitializer()
	{
		if (!Z_Registration_Info_UClass_AZEDInitializer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZEDInitializer.OuterSingleton, Z_Construct_UClass_AZEDInitializer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZEDInitializer.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<AZEDInitializer>()
	{
		return AZEDInitializer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZEDInitializer);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDInitializer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDInitializer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZEDInitializer, AZEDInitializer::StaticClass, TEXT("AZEDInitializer"), &Z_Registration_Info_UClass_AZEDInitializer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZEDInitializer), 2011189337U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDInitializer_h_3046144828(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDInitializer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDInitializer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
