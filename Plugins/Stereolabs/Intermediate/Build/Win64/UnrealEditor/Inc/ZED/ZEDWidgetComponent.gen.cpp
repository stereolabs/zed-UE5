// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/HUD/ZEDWidgetComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDWidgetComponent() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_UZEDWidgetComponent_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDWidgetComponent();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent();
	UPackage* Z_Construct_UPackage__Script_ZED();
	ENGINE_API UClass* Z_Construct_UClass_UTimelineComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UZEDWidgetComponent::execFading)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_FadingFactor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Fading(Z_Param_FadingFactor);
		P_NATIVE_END;
	}
	void UZEDWidgetComponent::StaticRegisterNativesUZEDWidgetComponent()
	{
		UClass* Class = UZEDWidgetComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Fading", &UZEDWidgetComponent::execFading },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics
	{
		struct ZEDWidgetComponent_eventFading_Parms
		{
			float FadingFactor;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_FadingFactor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::NewProp_FadingFactor = { "FadingFactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDWidgetComponent_eventFading_Parms, FadingFactor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::NewProp_FadingFactor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Timeline fade function\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidgetComponent.h" },
		{ "ToolTip", "* Timeline fade function" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidgetComponent, nullptr, "Fading", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::ZEDWidgetComponent_eventFading_Parms), Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidgetComponent_Fading()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidgetComponent_Fading_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZEDWidgetComponent);
	UClass* Z_Construct_UClass_UZEDWidgetComponent_NoRegister()
	{
		return UZEDWidgetComponent::StaticClass();
	}
	struct Z_Construct_UClass_UZEDWidgetComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FadeTimeline_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FadeTimeline;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FadeTimelineCurve_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FadeTimelineCurve;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZEDWidgetComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UWidgetComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UZEDWidgetComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UZEDWidgetComponent_Fading, "Fading" }, // 2515751203
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDWidgetComponent_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object Activation Components|Activation Sockets Base Lighting LOD Mesh Mobility Trigger" },
		{ "IncludePath", "HUD/ZEDWidgetComponent.h" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidgetComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimeline_MetaData[] = {
		{ "Category", "ZEDWidgetComponent" },
		{ "Comment", "/** Fade timeline */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidgetComponent.h" },
		{ "ToolTip", "Fade timeline" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimeline = { "FadeTimeline", nullptr, (EPropertyFlags)0x001000000008000c, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UZEDWidgetComponent, FadeTimeline), Z_Construct_UClass_UTimelineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimeline_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimeline_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimelineCurve_MetaData[] = {
		{ "Category", "ZEDWidgetComponent" },
		{ "Comment", "/** Fade timeline curve */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidgetComponent.h" },
		{ "ToolTip", "Fade timeline curve" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimelineCurve = { "FadeTimelineCurve", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UZEDWidgetComponent, FadeTimelineCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimelineCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimelineCurve_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UZEDWidgetComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimeline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UZEDWidgetComponent_Statics::NewProp_FadeTimelineCurve,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZEDWidgetComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZEDWidgetComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZEDWidgetComponent_Statics::ClassParams = {
		&UZEDWidgetComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UZEDWidgetComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UZEDWidgetComponent_Statics::PropPointers),
		0,
		0x00B010A4u,
		METADATA_PARAMS(Z_Construct_UClass_UZEDWidgetComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDWidgetComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZEDWidgetComponent()
	{
		if (!Z_Registration_Info_UClass_UZEDWidgetComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZEDWidgetComponent.OuterSingleton, Z_Construct_UClass_UZEDWidgetComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZEDWidgetComponent.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<UZEDWidgetComponent>()
	{
		return UZEDWidgetComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZEDWidgetComponent);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidgetComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidgetComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZEDWidgetComponent, UZEDWidgetComponent::StaticClass, TEXT("UZEDWidgetComponent"), &Z_Registration_Info_UClass_UZEDWidgetComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZEDWidgetComponent), 1198755243U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidgetComponent_h_223780205(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidgetComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidgetComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
