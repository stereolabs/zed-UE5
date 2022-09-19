// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Utilities/StereolabsCriticalSection.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsCriticalSection() {}
// Cross Module References
	STEREOLABS_API UClass* Z_Construct_UClass_USlCriticalSection_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlCriticalSection();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
// End Cross Module References
	DEFINE_FUNCTION(USlCriticalSection::execIsLocked)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsLocked();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlCriticalSection::execUnlock)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Unlock();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlCriticalSection::execTryLock)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->TryLock();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlCriticalSection::execLock)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Lock();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlCriticalSection::execCreateCriticalSection)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlCriticalSection**)Z_Param__Result=USlCriticalSection::CreateCriticalSection();
		P_NATIVE_END;
	}
	void USlCriticalSection::StaticRegisterNativesUSlCriticalSection()
	{
		UClass* Class = USlCriticalSection::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateCriticalSection", &USlCriticalSection::execCreateCriticalSection },
			{ "IsLocked", &USlCriticalSection::execIsLocked },
			{ "Lock", &USlCriticalSection::execLock },
			{ "TryLock", &USlCriticalSection::execTryLock },
			{ "Unlock", &USlCriticalSection::execUnlock },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics
	{
		struct SlCriticalSection_eventCreateCriticalSection_Parms
		{
			USlCriticalSection* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlCriticalSection_eventCreateCriticalSection_Parms, ReturnValue), Z_Construct_UClass_USlCriticalSection_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Critical Section" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsCriticalSection.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlCriticalSection, nullptr, "CreateCriticalSection", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::SlCriticalSection_eventCreateCriticalSection_Parms), Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics
	{
		struct SlCriticalSection_eventIsLocked_Parms
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
	void Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlCriticalSection_eventIsLocked_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlCriticalSection_eventIsLocked_Parms), &Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * @return True if locked\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsCriticalSection.h" },
		{ "ToolTip", "* @return True if locked" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlCriticalSection, nullptr, "IsLocked", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::SlCriticalSection_eventIsLocked_Parms), Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlCriticalSection_IsLocked()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlCriticalSection_IsLocked_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlCriticalSection_Lock_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCriticalSection_Lock_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Lock the section\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsCriticalSection.h" },
		{ "ToolTip", "* Lock the section" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlCriticalSection_Lock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlCriticalSection, nullptr, "Lock", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlCriticalSection_Lock_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_Lock_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlCriticalSection_Lock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlCriticalSection_Lock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlCriticalSection_TryLock_Statics
	{
		struct SlCriticalSection_eventTryLock_Parms
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
	void Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlCriticalSection_eventTryLock_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlCriticalSection_eventTryLock_Parms), &Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Try to lock the section\n\x09 * @return True if locked\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsCriticalSection.h" },
		{ "ToolTip", "* Try to lock the section\n* @return True if locked" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlCriticalSection, nullptr, "TryLock", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::SlCriticalSection_eventTryLock_Parms), Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlCriticalSection_TryLock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlCriticalSection_TryLock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlCriticalSection_Unlock_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlCriticalSection_Unlock_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Unlock the section\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsCriticalSection.h" },
		{ "ToolTip", "* Unlock the section" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlCriticalSection_Unlock_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlCriticalSection, nullptr, "Unlock", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlCriticalSection_Unlock_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlCriticalSection_Unlock_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlCriticalSection_Unlock()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlCriticalSection_Unlock_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlCriticalSection);
	UClass* Z_Construct_UClass_USlCriticalSection_NoRegister()
	{
		return USlCriticalSection::StaticClass();
	}
	struct Z_Construct_UClass_USlCriticalSection_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlCriticalSection_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlCriticalSection_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlCriticalSection_CreateCriticalSection, "CreateCriticalSection" }, // 1168072020
		{ &Z_Construct_UFunction_USlCriticalSection_IsLocked, "IsLocked" }, // 3348609488
		{ &Z_Construct_UFunction_USlCriticalSection_Lock, "Lock" }, // 264160500
		{ &Z_Construct_UFunction_USlCriticalSection_TryLock, "TryLock" }, // 2573656315
		{ &Z_Construct_UFunction_USlCriticalSection_Unlock, "Unlock" }, // 868883580
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlCriticalSection_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n * Critical section in blueprint\n */" },
		{ "IncludePath", "Utilities/StereolabsCriticalSection.h" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsCriticalSection.h" },
		{ "ToolTip", "* Critical section in blueprint" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlCriticalSection_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlCriticalSection>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlCriticalSection_Statics::ClassParams = {
		&USlCriticalSection::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlCriticalSection_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlCriticalSection_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlCriticalSection()
	{
		if (!Z_Registration_Info_UClass_USlCriticalSection.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlCriticalSection.OuterSingleton, Z_Construct_UClass_USlCriticalSection_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlCriticalSection.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlCriticalSection>()
	{
		return USlCriticalSection::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlCriticalSection);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USlCriticalSection, USlCriticalSection::StaticClass, TEXT("USlCriticalSection"), &Z_Registration_Info_UClass_USlCriticalSection, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlCriticalSection), 3728146758U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_3134194310(TEXT("/Script/Stereolabs"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsCriticalSection_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
