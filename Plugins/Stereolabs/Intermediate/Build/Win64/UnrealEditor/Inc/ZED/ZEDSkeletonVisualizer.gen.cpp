// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZEDSkeletonVisualizer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDSkeletonVisualizer() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_AZEDSkeletonVisualizer_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDSkeletonVisualizer();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ZED();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlErrorCode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectDetectionParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectDetectionRuntimeParameters();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjects();
// End Cross Module References
	DEFINE_FUNCTION(AZEDSkeletonVisualizer::execOnZEDReady)
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
	DEFINE_FUNCTION(AZEDSkeletonVisualizer::execDisableObjectDetection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisableObjectDetection();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDSkeletonVisualizer::execEnableObjectDetection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->EnableObjectDetection();
		P_NATIVE_END;
	}
	void AZEDSkeletonVisualizer::StaticRegisterNativesAZEDSkeletonVisualizer()
	{
		UClass* Class = AZEDSkeletonVisualizer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DisableObjectDetection", &AZEDSkeletonVisualizer::execDisableObjectDetection },
			{ "EnableObjectDetection", &AZEDSkeletonVisualizer::execEnableObjectDetection },
			{ "OnZEDReady", &AZEDSkeletonVisualizer::execOnZEDReady },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "Comment", "/*\n\x09 * Disable the Object Detection module.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
		{ "ToolTip", "* Disable the Object Detection module." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDSkeletonVisualizer, nullptr, "DisableObjectDetection", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics
	{
		struct ZEDSkeletonVisualizer_eventEnableObjectDetection_Parms
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
	void Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ZEDSkeletonVisualizer_eventEnableObjectDetection_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDSkeletonVisualizer_eventEnableObjectDetection_Parms), &Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Zed|ObjectDetection" },
		{ "Comment", "/*\n\x09 * Enable the Object Detection in the SDK.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
		{ "ToolTip", "* Enable the Object Detection in the SDK." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDSkeletonVisualizer, nullptr, "EnableObjectDetection", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::ZEDSkeletonVisualizer_eventEnableObjectDetection_Parms), Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics
	{
		struct ZEDSkeletonVisualizer_eventOnZEDReady_Parms
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
	void Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((ZEDSkeletonVisualizer_eventOnZEDReady_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDSkeletonVisualizer_eventOnZEDReady_Parms), &Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_ErrorCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDSkeletonVisualizer_eventOnZEDReady_Parms, ErrorCode), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDSkeletonVisualizer_eventOnZEDReady_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDSkeletonVisualizer_eventOnZEDReady_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Rotation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_ErrorCode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::NewProp_Rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDSkeletonVisualizer, nullptr, "OnZEDReady", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::ZEDSkeletonVisualizer_eventOnZEDReady_Parms), Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZEDSkeletonVisualizer);
	UClass* Z_Construct_UClass_AZEDSkeletonVisualizer_NoRegister()
	{
		return AZEDSkeletonVisualizer::StaticClass();
	}
	struct Z_Construct_UClass_AZEDSkeletonVisualizer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStartObjectDetectionAutomatically_MetaData[];
#endif
		static void NewProp_bStartObjectDetectionAutomatically_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStartObjectDetectionAutomatically;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDetectionParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDetectionParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectDetectionRuntimeParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectDetectionRuntimeParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Objects_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Objects;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZEDSkeletonVisualizer_DisableObjectDetection, "DisableObjectDetection" }, // 1684436631
		{ &Z_Construct_UFunction_AZEDSkeletonVisualizer_EnableObjectDetection, "EnableObjectDetection" }, // 602614935
		{ &Z_Construct_UFunction_AZEDSkeletonVisualizer_OnZEDReady, "OnZEDReady" }, // 2379722419
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n * Actor that manage the ZED Skeleton Visualizer\n */" },
		{ "IncludePath", "Core/ZEDSkeletonVisualizer.h" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
		{ "ToolTip", "* Actor that manage the ZED Skeleton Visualizer" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_MetaData[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
	};
#endif
	void Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_SetBit(void* Obj)
	{
		((AZEDSkeletonVisualizer*)Obj)->bStartObjectDetectionAutomatically = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically = { "bStartObjectDetectionAutomatically", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDSkeletonVisualizer), &Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionParameters_MetaData[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionParameters = { "ObjectDetectionParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDSkeletonVisualizer, ObjectDetectionParameters), Z_Construct_UScriptStruct_FSlObjectDetectionParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionParameters_MetaData)) }; // 2946743940
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData[] = {
		{ "Category", "Zed|ObjectDetection" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters = { "ObjectDetectionRuntimeParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDSkeletonVisualizer, ObjectDetectionRuntimeParameters), Z_Construct_UScriptStruct_FSlObjectDetectionRuntimeParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters_MetaData)) }; // 3422687885
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_Objects_MetaData[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZEDSkeletonVisualizer.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_Objects = { "Objects", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDSkeletonVisualizer, Objects), Z_Construct_UScriptStruct_FSlObjects, METADATA_PARAMS(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_Objects_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_Objects_MetaData)) }; // 589300517
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_bStartObjectDetectionAutomatically,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_ObjectDetectionRuntimeParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::NewProp_Objects,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZEDSkeletonVisualizer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::ClassParams = {
		&AZEDSkeletonVisualizer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZEDSkeletonVisualizer()
	{
		if (!Z_Registration_Info_UClass_AZEDSkeletonVisualizer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZEDSkeletonVisualizer.OuterSingleton, Z_Construct_UClass_AZEDSkeletonVisualizer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZEDSkeletonVisualizer.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<AZEDSkeletonVisualizer>()
	{
		return AZEDSkeletonVisualizer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZEDSkeletonVisualizer);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDSkeletonVisualizer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDSkeletonVisualizer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZEDSkeletonVisualizer, AZEDSkeletonVisualizer::StaticClass, TEXT("AZEDSkeletonVisualizer"), &Z_Registration_Info_UClass_AZEDSkeletonVisualizer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZEDSkeletonVisualizer), 4187005761U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDSkeletonVisualizer_h_749916747(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDSkeletonVisualizer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDSkeletonVisualizer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
