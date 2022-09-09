// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZED3DObjectVisualizer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZED3DObjectVisualizer() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_AZED3DObjectVisualizer_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZED3DObjectVisualizer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ZED();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlErrorCode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectDetectionParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectDetectionRuntimeParameters();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AZED3DObjectVisualizer::execOnZEDReady)
	{
		P_GET_UBOOL(Z_Param_bSuccess);
		P_GET_ENUM(ESlErrorCode,Z_Param_ErrorCode);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnZEDReady(Z_Param_bSuccess,ESlErrorCode(Z_Param_ErrorCode),Z_Param_Out_Location,Z_Param_Out_Rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZED3DObjectVisualizer::execDisableObjectDetection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisableObjectDetection();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZED3DObjectVisualizer::execEnableObjectDetection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->EnableObjectDetection();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZED3DObjectVisualizer::execIsObjectDetectionEnabled)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsObjectDetectionEnabled();
		P_NATIVE_END;
	}
	void AZED3DObjectVisualizer::StaticRegisterNativesAZED3DObjectVisualizer()
	{
		UClass* Class = AZED3DObjectVisualizer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DisableObjectDetection", &AZED3DObjectVisualizer::execDisableObjectDetection },
			{ "EnableObjectDetection", &AZED3DObjectVisualizer::execEnableObjectDetection },
			{ "IsObjectDetectionEnabled", &AZED3DObjectVisualizer::execIsObjectDetectionEnabled },
			{ "OnZEDReady", &AZED3DObjectVisualizer::execOnZEDReady },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "Comment", "/*\n\x09 * Disable the Object Detection module.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
		{ "ToolTip", "* Disable the Object Detection module." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZED3DObjectVisualizer, nullptr, "DisableObjectDetection", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics
	{
		struct ZED3DObjectVisualizer_eventEnableObjectDetection_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZED3DObjectVisualizer_eventEnableObjectDetection_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZED3DObjectVisualizer_eventEnableObjectDetection_Parms), &Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Zed|ObjectDetection" },
		{ "Comment", "/*\n\x09 * Enable the Object Detection in the SDK.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
		{ "ToolTip", "* Enable the Object Detection in the SDK." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZED3DObjectVisualizer, nullptr, "EnableObjectDetection", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::ZED3DObjectVisualizer_eventEnableObjectDetection_Parms), Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics
	{
		struct ZED3DObjectVisualizer_eventIsObjectDetectionEnabled_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZED3DObjectVisualizer_eventIsObjectDetectionEnabled_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZED3DObjectVisualizer_eventIsObjectDetectionEnabled_Parms), &Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "Comment", "/*\n\x09 * @return True if the Object Detection module is enabled\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
		{ "ToolTip", "* @return True if the Object Detection module is enabled" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZED3DObjectVisualizer, nullptr, "IsObjectDetectionEnabled", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::ZED3DObjectVisualizer_eventIsObjectDetectionEnabled_Parms), Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics
	{
		struct ZED3DObjectVisualizer_eventOnZEDReady_Parms
		{
			bool bSuccess;
			ESlErrorCode ErrorCode;
			FVector Location;
			FRotator Rotation;
		};
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ErrorCode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ErrorCode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((ZED3DObjectVisualizer_eventOnZEDReady_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZED3DObjectVisualizer_eventOnZEDReady_Parms), &Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_ErrorCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZED3DObjectVisualizer_eventOnZEDReady_Parms, ErrorCode), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZED3DObjectVisualizer_eventOnZEDReady_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZED3DObjectVisualizer_eventOnZEDReady_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Rotation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_ErrorCode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::NewProp_Rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZED3DObjectVisualizer, nullptr, "OnZEDReady", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::ZED3DObjectVisualizer_eventOnZEDReady_Parms), Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZED3DObjectVisualizer);
	UClass* Z_Construct_UClass_AZED3DObjectVisualizer_NoRegister()
	{
		return AZED3DObjectVisualizer::StaticClass();
	}
	struct Z_Construct_UClass_AZED3DObjectVisualizer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDetectionParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDetectionParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDetectionRuntimeParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDetectionRuntimeParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BBox3D_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_BBox3D;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStartObjectDetectionAutomatically_MetaData[];
#endif
		static void NewProp_bStartObjectDetectionAutomatically_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartObjectDetectionAutomatically;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZED3DObjectVisualizer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZED3DObjectVisualizer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZED3DObjectVisualizer_DisableObjectDetection, "DisableObjectDetection" }, // 72147011
		{ &Z_Construct_UFunction_AZED3DObjectVisualizer_EnableObjectDetection, "EnableObjectDetection" }, // 2868281417
		{ &Z_Construct_UFunction_AZED3DObjectVisualizer_IsObjectDetectionEnabled, "IsObjectDetectionEnabled" }, // 1034068812
		{ &Z_Construct_UFunction_AZED3DObjectVisualizer_OnZEDReady, "OnZEDReady" }, // 1122786432
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZED3DObjectVisualizer_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n * Actor that manage the ZED 3D Object Visualizer\n */" },
		{ "IncludePath", "Core/ZED3DObjectVisualizer.h" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
		{ "ToolTip", "* Actor that manage the ZED 3D Object Visualizer" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionParameters = { "ObjectDetectionParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZED3DObjectVisualizer, ObjectDetectionParameters), Z_Construct_UScriptStruct_FSlObjectDetectionParameters, METADATA_PARAMS(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionParameters_MetaData)) }; // 2946743940
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters = { "ObjectDetectionRuntimeParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZED3DObjectVisualizer, ObjectDetectionRuntimeParameters), Z_Construct_UScriptStruct_FSlObjectDetectionRuntimeParameters, METADATA_PARAMS(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData)) }; // 3422687885
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_BBox3D_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_BBox3D = { "BBox3D", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZED3DObjectVisualizer, BBox3D), Z_Construct_UClass_AActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_BBox3D_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_BBox3D_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/Core/ZED3DObjectVisualizer.h" },
	};
#endif
	void Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_SetBit(void* Obj)
	{
		((AZED3DObjectVisualizer*)Obj)->bStartObjectDetectionAutomatically = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically = { "bStartObjectDetectionAutomatically", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZED3DObjectVisualizer), &Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZED3DObjectVisualizer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_BBox3D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZED3DObjectVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZED3DObjectVisualizer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZED3DObjectVisualizer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZED3DObjectVisualizer_Statics::ClassParams = {
		&AZED3DObjectVisualizer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZED3DObjectVisualizer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZED3DObjectVisualizer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZED3DObjectVisualizer()
	{
		if (!Z_Registration_Info_UClass_AZED3DObjectVisualizer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZED3DObjectVisualizer.OuterSingleton, Z_Construct_UClass_AZED3DObjectVisualizer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZED3DObjectVisualizer.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<AZED3DObjectVisualizer>()
	{
		return AZED3DObjectVisualizer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZED3DObjectVisualizer);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZED3DObjectVisualizer, AZED3DObjectVisualizer::StaticClass, TEXT("AZED3DObjectVisualizer"), &Z_Registration_Info_UClass_AZED3DObjectVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZED3DObjectVisualizer), 2077596725U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_3762907761(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZED3DObjectVisualizer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
