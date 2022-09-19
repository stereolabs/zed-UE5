// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Devices/Public/Core/DevicesMotionController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDevicesMotionController() {}
// Cross Module References
	DEVICES_API UClass* Z_Construct_UClass_ADevicesMotionController_NoRegister();
	DEVICES_API UClass* Z_Construct_UClass_ADevicesMotionController();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Devices();
	HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ADevicesMotionController::execGetModifiedLatencyTime)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetModifiedLatencyTime();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADevicesMotionController::execModifyLatencyTime)
	{
		P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_NewLatencyInMs);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ModifyLatencyTime(Z_Param_Out_NewLatencyInMs);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADevicesMotionController::execStop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Stop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADevicesMotionController::execStart)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Start();
		P_NATIVE_END;
	}
	void ADevicesMotionController::StaticRegisterNativesADevicesMotionController()
	{
		UClass* Class = ADevicesMotionController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetModifiedLatencyTime", &ADevicesMotionController::execGetModifiedLatencyTime },
			{ "ModifyLatencyTime", &ADevicesMotionController::execModifyLatencyTime },
			{ "Start", &ADevicesMotionController::execStart },
			{ "Stop", &ADevicesMotionController::execStop },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics
	{
		struct DevicesMotionController_eventGetModifiedLatencyTime_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DevicesMotionController_eventGetModifiedLatencyTime_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/DevicesMotionController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADevicesMotionController, nullptr, "GetModifiedLatencyTime", nullptr, nullptr, sizeof(Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::DevicesMotionController_eventGetModifiedLatencyTime_Parms), Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics
	{
		struct DevicesMotionController_eventModifyLatencyTime_Parms
		{
			int32 NewLatencyInMs;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewLatencyInMs_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_NewLatencyInMs;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::NewProp_NewLatencyInMs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::NewProp_NewLatencyInMs = { "NewLatencyInMs", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(DevicesMotionController_eventModifyLatencyTime_Parms, NewLatencyInMs), METADATA_PARAMS(Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::NewProp_NewLatencyInMs_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::NewProp_NewLatencyInMs_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::NewProp_NewLatencyInMs,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/DevicesMotionController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADevicesMotionController, nullptr, "ModifyLatencyTime", nullptr, nullptr, sizeof(Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::DevicesMotionController_eventModifyLatencyTime_Parms), Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADevicesMotionController_Start_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADevicesMotionController_Start_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/DevicesMotionController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADevicesMotionController_Start_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADevicesMotionController, nullptr, "Start", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADevicesMotionController_Start_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_Start_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADevicesMotionController_Start()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADevicesMotionController_Start_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADevicesMotionController_Stop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADevicesMotionController_Stop_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Core/DevicesMotionController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADevicesMotionController_Stop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADevicesMotionController, nullptr, "Stop", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADevicesMotionController_Stop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADevicesMotionController_Stop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADevicesMotionController_Stop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADevicesMotionController_Stop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADevicesMotionController);
	UClass* Z_Construct_UClass_ADevicesMotionController_NoRegister()
	{
		return ADevicesMotionController::StaticClass();
	}
	struct Z_Construct_UClass_ADevicesMotionController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MotionController_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MotionController;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADevicesMotionController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Devices,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ADevicesMotionController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ADevicesMotionController_GetModifiedLatencyTime, "GetModifiedLatencyTime" }, // 815620036
		{ &Z_Construct_UFunction_ADevicesMotionController_ModifyLatencyTime, "ModifyLatencyTime" }, // 1483182586
		{ &Z_Construct_UFunction_ADevicesMotionController_Start, "Start" }, // 1684060810
		{ &Z_Construct_UFunction_ADevicesMotionController_Stop, "Stop" }, // 96732217
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADevicesMotionController_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Controllers" },
		{ "Comment", "/*\n *\x09""Actor which can provide a MotionController transform with a delay in millisecond. AActor is needed for timer.\n */" },
		{ "IncludePath", "Core/DevicesMotionController.h" },
		{ "ModuleRelativePath", "Public/Core/DevicesMotionController.h" },
		{ "ToolTip", "*     Actor which can provide a MotionController transform with a delay in millisecond. AActor is needed for timer." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADevicesMotionController_Statics::NewProp_MotionController_MetaData[] = {
		{ "Category", "DevicesMotionController" },
		{ "Comment", "/** MotionController */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/DevicesMotionController.h" },
		{ "ToolTip", "MotionController" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADevicesMotionController_Statics::NewProp_MotionController = { "MotionController", nullptr, (EPropertyFlags)0x001200000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ADevicesMotionController, MotionController), Z_Construct_UClass_UMotionControllerComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADevicesMotionController_Statics::NewProp_MotionController_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADevicesMotionController_Statics::NewProp_MotionController_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADevicesMotionController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADevicesMotionController_Statics::NewProp_MotionController,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADevicesMotionController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADevicesMotionController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADevicesMotionController_Statics::ClassParams = {
		&ADevicesMotionController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ADevicesMotionController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ADevicesMotionController_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADevicesMotionController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADevicesMotionController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADevicesMotionController()
	{
		if (!Z_Registration_Info_UClass_ADevicesMotionController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADevicesMotionController.OuterSingleton, Z_Construct_UClass_ADevicesMotionController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADevicesMotionController.OuterSingleton;
	}
	template<> DEVICES_API UClass* StaticClass<ADevicesMotionController>()
	{
		return ADevicesMotionController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADevicesMotionController);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Devices_Public_Core_DevicesMotionController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Devices_Public_Core_DevicesMotionController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADevicesMotionController, ADevicesMotionController::StaticClass, TEXT("ADevicesMotionController"), &Z_Registration_Info_UClass_ADevicesMotionController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADevicesMotionController), 2852654742U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Devices_Public_Core_DevicesMotionController_h_3929632464(TEXT("/Script/Devices"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Devices_Public_Core_DevicesMotionController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Devices_Public_Core_DevicesMotionController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
