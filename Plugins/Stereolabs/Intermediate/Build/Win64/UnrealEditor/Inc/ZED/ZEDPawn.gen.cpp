// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZEDPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDPawn() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_AZEDPawn_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_ZED();
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDTrackingData();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDWidget_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AZEDPawn::execZedCameraTrackingUpdated)
	{
		P_GET_STRUCT_REF(FZEDTrackingData,Z_Param_Out_NewTrackingData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZedCameraTrackingUpdated(Z_Param_Out_NewTrackingData);
		P_NATIVE_END;
	}
	void AZEDPawn::StaticRegisterNativesAZEDPawn()
	{
		UClass* Class = AZEDPawn::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ZedCameraTrackingUpdated", &AZEDPawn::execZedCameraTrackingUpdated },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics
	{
		struct ZEDPawn_eventZedCameraTrackingUpdated_Parms
		{
			FZEDTrackingData NewTrackingData;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewTrackingData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewTrackingData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::NewProp_NewTrackingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::NewProp_NewTrackingData = { "NewTrackingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPawn_eventZedCameraTrackingUpdated_Parms, NewTrackingData), Z_Construct_UScriptStruct_FZEDTrackingData, METADATA_PARAMS(Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::NewProp_NewTrackingData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::NewProp_NewTrackingData_MetaData)) }; // 2053750691
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::NewProp_NewTrackingData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Event binded to OnTrackingDataUpdated\n\x09 * @param NewTrackingData The new tracking data\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "* Event binded to OnTrackingDataUpdated\n* @param NewTrackingData The new tracking data" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPawn, nullptr, "ZedCameraTrackingUpdated", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::ZEDPawn_eventZedCameraTrackingUpdated_Parms), Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZEDPawn);
	UClass* Z_Construct_UClass_AZEDPawn_NoRegister()
	{
		return AZEDPawn::StaticClass();
	}
	struct Z_Construct_UClass_AZEDPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedLoadingWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedLoadingWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedErrorWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedErrorWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RemapSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RemapSourceMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RemapMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RemapMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RemapMx_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RemapMx;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RemapMy_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RemapMy;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedLoadingSourceWidget_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ZedLoadingSourceWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedErrorSourceWidget_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ZedErrorSourceWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedWidgetSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedWidgetSourceMaterial;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZEDPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZEDPawn_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZEDPawn_ZedCameraTrackingUpdated, "ZedCameraTrackingUpdated" }, // 2852957178
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n * Base class for pawn using the Zed.\n * Inherit from this class and set the PawnClassType variable in the controller to spawn a pawn of your type.\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Core/ZEDPawn.h" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "* Base class for pawn using the Zed.\n* Inherit from this class and set the PawnClassType variable in the controller to spawn a pawn of your type." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_SpringArm_MetaData[] = {
		{ "Comment", "/** Custom spring arm that offset the camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Custom spring arm that offset the camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, SpringArm), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_SpringArm_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_SpringArm_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_Camera_MetaData[] = {
		{ "Category", "ZEDPawn" },
		{ "Comment", "/** Main camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Main camera" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_Camera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_Camera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingWidget_MetaData[] = {
		{ "Comment", "/** Zed loading widget */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Zed loading widget" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingWidget = { "ZedLoadingWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, ZedLoadingWidget), Z_Construct_UClass_UZEDWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorWidget_MetaData[] = {
		{ "Comment", "/** Zed error widget */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Zed error widget" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorWidget = { "ZedErrorWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, ZedErrorWidget), Z_Construct_UClass_UZEDWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapSourceMaterial_MetaData[] = {
		{ "Comment", "/** Remap material resource */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Remap material resource" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapSourceMaterial = { "RemapSourceMaterial", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, RemapSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapSourceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMaterialInstanceDynamic_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Remap material*/" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Remap material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMaterialInstanceDynamic = { "RemapMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, RemapMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMx_MetaData[] = {
		{ "Comment", "/** Remap Mx */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Remap Mx" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMx = { "RemapMx", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, RemapMx), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMx_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMx_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMy_MetaData[] = {
		{ "Comment", "/** Remap My */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Remap My" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMy = { "RemapMy", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, RemapMy), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMy_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMy_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingSourceWidget_MetaData[] = {
		{ "Comment", "/** Zed loading source widget */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Zed loading source widget" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingSourceWidget = { "ZedLoadingSourceWidget", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, ZedLoadingSourceWidget), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingSourceWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingSourceWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorSourceWidget_MetaData[] = {
		{ "Comment", "/** Zed error source widget */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Zed error source widget" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorSourceWidget = { "ZedErrorSourceWidget", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, ZedErrorSourceWidget), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorSourceWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorSourceWidget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedWidgetSourceMaterial_MetaData[] = {
		{ "Comment", "/** Zed widget material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPawn.h" },
		{ "ToolTip", "Zed widget material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedWidgetSourceMaterial = { "ZedWidgetSourceMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPawn, ZedWidgetSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedWidgetSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedWidgetSourceMaterial_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZEDPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_SpringArm,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_Camera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapSourceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMx,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_RemapMy,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedLoadingSourceWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedErrorSourceWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPawn_Statics::NewProp_ZedWidgetSourceMaterial,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZEDPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZEDPawn>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZEDPawn_Statics::ClassParams = {
		&AZEDPawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZEDPawn_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZEDPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZEDPawn()
	{
		if (!Z_Registration_Info_UClass_AZEDPawn.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZEDPawn.OuterSingleton, Z_Construct_UClass_AZEDPawn_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZEDPawn.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<AZEDPawn>()
	{
		return AZEDPawn::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZEDPawn);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZEDPawn, AZEDPawn::StaticClass, TEXT("AZEDPawn"), &Z_Registration_Info_UClass_AZEDPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZEDPawn), 2109890107U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_1031982807(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPawn_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
