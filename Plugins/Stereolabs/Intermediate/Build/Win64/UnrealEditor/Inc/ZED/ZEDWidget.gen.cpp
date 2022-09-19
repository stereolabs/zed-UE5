// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/HUD/ZEDWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDWidget() {}
// Cross Module References
	ZED_API UClass* Z_Construct_UClass_UZEDWidget_NoRegister();
	ZED_API UClass* Z_Construct_UClass_UZEDWidget();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	UPackage* Z_Construct_UPackage__Script_ZED();
	UMG_API UEnum* Z_Construct_UEnum_UMG_EWidgetSpace();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
// End Cross Module References
	DEFINE_FUNCTION(UZEDWidget::execFadeOut)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FadeOut();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDWidget::execFadeIn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FadeIn();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDWidget::execSetTextColorAndOpacity)
	{
		P_GET_STRUCT_REF(FLinearColor,Z_Param_Out_NewColor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTextColorAndOpacity(Z_Param_Out_NewColor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDWidget::execSetFontSize)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NewSize);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFontSize(Z_Param_NewSize);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDWidget::execSetText)
	{
		P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_NewText);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetText(Z_Param_Out_NewText);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDWidget::execSetWidgetSpace)
	{
		P_GET_ENUM(EWidgetSpace,Z_Param_NewWidgetSpace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetWidgetSpace(EWidgetSpace(Z_Param_NewWidgetSpace));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UZEDWidget::execGetWidgetSpace)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(EWidgetSpace*)Z_Param__Result=P_THIS->GetWidgetSpace();
		P_NATIVE_END;
	}
	void UZEDWidget::StaticRegisterNativesUZEDWidget()
	{
		UClass* Class = UZEDWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FadeIn", &UZEDWidget::execFadeIn },
			{ "FadeOut", &UZEDWidget::execFadeOut },
			{ "GetWidgetSpace", &UZEDWidget::execGetWidgetSpace },
			{ "SetFontSize", &UZEDWidget::execSetFontSize },
			{ "SetText", &UZEDWidget::execSetText },
			{ "SetTextColorAndOpacity", &UZEDWidget::execSetTextColorAndOpacity },
			{ "SetWidgetSpace", &UZEDWidget::execSetWidgetSpace },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UZEDWidget_FadeIn_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_FadeIn_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Fade in the widget\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* Fade in the widget" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_FadeIn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "FadeIn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_FadeIn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_FadeIn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_FadeIn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_FadeIn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDWidget_FadeOut_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_FadeOut_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Fade out the widget \n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* Fade out the widget" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_FadeOut_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "FadeOut", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_FadeOut_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_FadeOut_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_FadeOut()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_FadeOut_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics
	{
		struct ZEDWidget_eventGetWidgetSpace_Parms
		{
			EWidgetSpace ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDWidget_eventGetWidgetSpace_Parms, ReturnValue), Z_Construct_UEnum_UMG_EWidgetSpace, METADATA_PARAMS(nullptr, 0) }; // 253691217
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * @return The current widget space\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* @return The current widget space" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "GetWidgetSpace", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::ZEDWidget_eventGetWidgetSpace_Parms), Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_GetWidgetSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_GetWidgetSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics
	{
		struct ZEDWidget_eventSetFontSize_Parms
		{
			int32 NewSize;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NewSize;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::NewProp_NewSize = { "NewSize", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDWidget_eventSetFontSize_Parms, NewSize), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::NewProp_NewSize,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Set the widget size\n\x09 * @param NewSize The new size\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* Set the widget size\n* @param NewSize The new size" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "SetFontSize", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::ZEDWidget_eventSetFontSize_Parms), Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_SetFontSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_SetFontSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDWidget_SetText_Statics
	{
		struct ZEDWidget_eventSetText_Parms
		{
			FText NewText;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewText_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_NewText;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_SetText_Statics::NewProp_NewText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UZEDWidget_SetText_Statics::NewProp_NewText = { "NewText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDWidget_eventSetText_Parms, NewText), METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_SetText_Statics::NewProp_NewText_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetText_Statics::NewProp_NewText_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDWidget_SetText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_SetText_Statics::NewProp_NewText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_SetText_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Set the widget text\n\x09 * @param NewText The new text\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* Set the widget text\n* @param NewText The new text" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_SetText_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "SetText", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDWidget_SetText_Statics::ZEDWidget_eventSetText_Parms), Z_Construct_UFunction_UZEDWidget_SetText_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetText_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_SetText_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetText_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_SetText()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_SetText_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics
	{
		struct ZEDWidget_eventSetTextColorAndOpacity_Parms
		{
			FLinearColor NewColor;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewColor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::NewProp_NewColor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::NewProp_NewColor = { "NewColor", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDWidget_eventSetTextColorAndOpacity_Parms, NewColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::NewProp_NewColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::NewProp_NewColor_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::NewProp_NewColor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Set the color and opacity\n\x09 * @param NewColor The new color and opacity\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* Set the color and opacity\n* @param NewColor The new color and opacity" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "SetTextColorAndOpacity", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::ZEDWidget_eventSetTextColorAndOpacity_Parms), Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics
	{
		struct ZEDWidget_eventSetWidgetSpace_Parms
		{
			EWidgetSpace NewWidgetSpace;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewWidgetSpace_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewWidgetSpace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::NewProp_NewWidgetSpace_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::NewProp_NewWidgetSpace = { "NewWidgetSpace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDWidget_eventSetWidgetSpace_Parms, NewWidgetSpace), Z_Construct_UEnum_UMG_EWidgetSpace, METADATA_PARAMS(nullptr, 0) }; // 253691217
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::NewProp_NewWidgetSpace_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::NewProp_NewWidgetSpace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Set the widget space\n\x09 * @param NewWidgetSpace The new widget space\n\x09 */" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
		{ "ToolTip", "* Set the widget space\n* @param NewWidgetSpace The new widget space" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UZEDWidget, nullptr, "SetWidgetSpace", nullptr, nullptr, sizeof(Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::ZEDWidget_eventSetWidgetSpace_Parms), Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UZEDWidget_SetWidgetSpace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UZEDWidget_SetWidgetSpace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UZEDWidget);
	UClass* Z_Construct_UClass_UZEDWidget_NoRegister()
	{
		return UZEDWidget::StaticClass();
	}
	struct Z_Construct_UClass_UZEDWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UZEDWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UZEDWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UZEDWidget_FadeIn, "FadeIn" }, // 4123102538
		{ &Z_Construct_UFunction_UZEDWidget_FadeOut, "FadeOut" }, // 3541605695
		{ &Z_Construct_UFunction_UZEDWidget_GetWidgetSpace, "GetWidgetSpace" }, // 2188373
		{ &Z_Construct_UFunction_UZEDWidget_SetFontSize, "SetFontSize" }, // 3709531002
		{ &Z_Construct_UFunction_UZEDWidget_SetText, "SetText" }, // 3885086706
		{ &Z_Construct_UFunction_UZEDWidget_SetTextColorAndOpacity, "SetTextColorAndOpacity" }, // 4192265900
		{ &Z_Construct_UFunction_UZEDWidget_SetWidgetSpace, "SetWidgetSpace" }, // 3931547329
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UZEDWidget_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "HUD/ZEDWidget.h" },
		{ "ModuleRelativePath", "Public/HUD/ZEDWidget.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UZEDWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UZEDWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UZEDWidget_Statics::ClassParams = {
		&UZEDWidget::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UZEDWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UZEDWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UZEDWidget()
	{
		if (!Z_Registration_Info_UClass_UZEDWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UZEDWidget.OuterSingleton, Z_Construct_UClass_UZEDWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UZEDWidget.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<UZEDWidget>()
	{
		return UZEDWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UZEDWidget);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UZEDWidget, UZEDWidget::StaticClass, TEXT("UZEDWidget"), &Z_Registration_Info_UClass_UZEDWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UZEDWidget), 131304381U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_4172083838(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_HUD_ZEDWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
