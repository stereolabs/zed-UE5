// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Core/StereolabsTexture.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsTexture() {}
// Cross Module References
	STEREOLABS_API UClass* Z_Construct_UClass_USlTexture_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlTexture();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlMat();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlMemoryType();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlTextureType();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlViewTexture_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlViewTexture();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlView();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlTextureFormat();
	STEREOLABS_API UClass* Z_Construct_UClass_USlMeasureTexture_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlMeasureTexture();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlMeasure();
// End Cross Module References
	DEFINE_FUNCTION(USlTexture::execResize)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_NewWidth);
		P_GET_PROPERTY(FIntProperty,Z_Param_NewHeight);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Resize(Z_Param_NewWidth,Z_Param_NewHeight);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTexture::execBP_UpdateTextureWithMat)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_NewMat);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BP_UpdateTextureWithMat(Z_Param_Out_NewMat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTexture::execBP_UpdateTexture)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BP_UpdateTexture();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTexture::execGetMemoryType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlMemoryType*)Z_Param__Result=P_THIS->GetMemoryType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTexture::execIsMemoryTypeOf)
	{
		P_GET_ENUM(ESlMemoryType,Z_Param_TestMemoryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsMemoryTypeOf(ESlMemoryType(Z_Param_TestMemoryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlTexture::execIsTypeOf)
	{
		P_GET_ENUM(ESlTextureType,Z_Param_TestTextureType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsTypeOf(ESlTextureType(Z_Param_TestTextureType));
		P_NATIVE_END;
	}
	void USlTexture::StaticRegisterNativesUSlTexture()
	{
		UClass* Class = USlTexture::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BP_UpdateTexture", &USlTexture::execBP_UpdateTexture },
			{ "BP_UpdateTextureWithMat", &USlTexture::execBP_UpdateTextureWithMat },
			{ "GetMemoryType", &USlTexture::execGetMemoryType },
			{ "IsMemoryTypeOf", &USlTexture::execIsMemoryTypeOf },
			{ "IsTypeOf", &USlTexture::execIsTypeOf },
			{ "Resize", &USlTexture::execResize },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlTexture_BP_UpdateTexture_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_BP_UpdateTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Update the UE texture. Only for GPU texture.\n\x09 */" },
		{ "DisplayName", "UpdateTexture" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Update the UE texture. Only for GPU texture." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTexture_BP_UpdateTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTexture, nullptr, "BP_UpdateTexture", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_BP_UpdateTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_BP_UpdateTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTexture_BP_UpdateTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTexture_BP_UpdateTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics
	{
		struct SlTexture_eventBP_UpdateTextureWithMat_Parms
		{
			FSlMat NewMat;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewMat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewMat;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::NewProp_NewMat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::NewProp_NewMat = { "NewMat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTexture_eventBP_UpdateTextureWithMat_Parms, NewMat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::NewProp_NewMat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::NewProp_NewMat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::NewProp_NewMat,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Update the UE texture. Only for GPU texture.\n\x09 * @param NewMat The mat used to update\n\x09 */" },
		{ "DisplayName", "UpdateTextureWithMat" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Update the UE texture. Only for GPU texture.\n* @param NewMat The mat used to update" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTexture, nullptr, "BP_UpdateTextureWithMat", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::SlTexture_eventBP_UpdateTextureWithMat_Parms), Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTexture_GetMemoryType_Statics
	{
		struct SlTexture_eventGetMemoryType_Parms
		{
			ESlMemoryType ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTexture_eventGetMemoryType_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlMemoryType, METADATA_PARAMS(nullptr, 0) }; // 650491615
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/* \n\x09 * @Return The memory type of the texture\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* @Return The memory type of the texture" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTexture, nullptr, "GetMemoryType", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::SlTexture_eventGetMemoryType_Parms), Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTexture_GetMemoryType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTexture_GetMemoryType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics
	{
		struct SlTexture_eventIsMemoryTypeOf_Parms
		{
			ESlMemoryType TestMemoryType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_TestMemoryType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TestMemoryType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_TestMemoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_TestMemoryType = { "TestMemoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTexture_eventIsMemoryTypeOf_Parms, TestMemoryType), Z_Construct_UEnum_Stereolabs_ESlMemoryType, METADATA_PARAMS(nullptr, 0) }; // 650491615
	void Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlTexture_eventIsMemoryTypeOf_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlTexture_eventIsMemoryTypeOf_Parms), &Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_TestMemoryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_TestMemoryType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * @Param TestMemoryType The memory type to test against\n\x09 * @Return true if the memory has the right type\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* @Param TestMemoryType The memory type to test against\n* @Return true if the memory has the right type" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTexture, nullptr, "IsMemoryTypeOf", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::SlTexture_eventIsMemoryTypeOf_Parms), Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTexture_IsMemoryTypeOf()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTexture_IsMemoryTypeOf_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTexture_IsTypeOf_Statics
	{
		struct SlTexture_eventIsTypeOf_Parms
		{
			ESlTextureType TestTextureType;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_TestTextureType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TestTextureType;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_TestTextureType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_TestTextureType = { "TestTextureType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTexture_eventIsTypeOf_Parms, TestTextureType), Z_Construct_UEnum_Stereolabs_ESlTextureType, METADATA_PARAMS(nullptr, 0) }; // 2823830806
	void Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlTexture_eventIsTypeOf_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlTexture_eventIsTypeOf_Parms), &Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_TestTextureType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_TestTextureType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * @Param TestTextureType The texture type to test against\n\x09 * @Return true if the texture has the right type\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* @Param TestTextureType The texture type to test against\n* @Return true if the texture has the right type" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTexture, nullptr, "IsTypeOf", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::SlTexture_eventIsTypeOf_Parms), Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTexture_IsTypeOf()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTexture_IsTypeOf_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlTexture_Resize_Statics
	{
		struct SlTexture_eventResize_Parms
		{
			int32 NewWidth;
			int32 NewHeight;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_NewWidth;
		static const UECodeGen_Private::FIntPropertyParams NewProp_NewHeight;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_NewWidth = { "NewWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTexture_eventResize_Parms, NewWidth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_NewHeight = { "NewHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlTexture_eventResize_Parms, NewHeight), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlTexture_eventResize_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlTexture_eventResize_Parms), &Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlTexture_Resize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_NewWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_NewHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlTexture_Resize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlTexture_Resize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Resize the texture\n\x09 * @param Width The new width\n\x09 * @param Height The new height\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Resize the texture\n* @param Width The new width\n* @param Height The new height" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlTexture_Resize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlTexture, nullptr, "Resize", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlTexture_Resize_Statics::SlTexture_eventResize_Parms), Z_Construct_UFunction_USlTexture_Resize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_Resize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlTexture_Resize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlTexture_Resize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlTexture_Resize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlTexture_Resize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlTexture);
	UClass* Z_Construct_UClass_USlTexture_NoRegister()
	{
		return USlTexture::StaticClass();
	}
	struct Z_Construct_UClass_USlTexture_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Texture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlTexture_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlTexture_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlTexture_BP_UpdateTexture, "BP_UpdateTexture" }, // 842225290
		{ &Z_Construct_UFunction_USlTexture_BP_UpdateTextureWithMat, "BP_UpdateTextureWithMat" }, // 862129480
		{ &Z_Construct_UFunction_USlTexture_GetMemoryType, "GetMemoryType" }, // 3395819128
		{ &Z_Construct_UFunction_USlTexture_IsMemoryTypeOf, "IsMemoryTypeOf" }, // 1414586131
		{ &Z_Construct_UFunction_USlTexture_IsTypeOf, "IsTypeOf" }, // 1588116570
		{ &Z_Construct_UFunction_USlTexture_Resize, "Resize" }, // 465881750
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTexture_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n * Texture used for rendering or holding mat\n */" },
		{ "IncludePath", "Core/StereolabsTexture.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Texture used for rendering or holding mat" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTexture_Statics::NewProp_Texture_MetaData[] = {
		{ "Category", "SlTexture" },
		{ "Comment", "/** Unreal texture if GPU */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Unreal texture if GPU" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USlTexture_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlTexture, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USlTexture_Statics::NewProp_Texture_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::NewProp_Texture_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTexture_Statics::NewProp_Width_MetaData[] = {
		{ "Category", "SlTexture" },
		{ "Comment", "/** Width of the texture */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Width of the texture" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USlTexture_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlTexture, Width), METADATA_PARAMS(Z_Construct_UClass_USlTexture_Statics::NewProp_Width_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::NewProp_Width_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTexture_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "SlTexture" },
		{ "Comment", "/** Height of the texture */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Height of the texture" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USlTexture_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlTexture, Height), METADATA_PARAMS(Z_Construct_UClass_USlTexture_Statics::NewProp_Height_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::NewProp_Height_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTexture_Statics::NewProp_Mat_MetaData[] = {
		{ "Category", "SlTexture" },
		{ "Comment", "/** Mat holding resources from SDK */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Mat holding resources from SDK" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USlTexture_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlTexture, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UClass_USlTexture_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::NewProp_Mat_MetaData)) }; // 1719170131
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlTexture_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "SlTexture" },
		{ "Comment", "/** Name of the texture */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Name of the texture" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_USlTexture_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlTexture, Name), METADATA_PARAMS(Z_Construct_UClass_USlTexture_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::NewProp_Name_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USlTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlTexture_Statics::NewProp_Texture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlTexture_Statics::NewProp_Width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlTexture_Statics::NewProp_Height,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlTexture_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlTexture_Statics::NewProp_Name,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlTexture_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlTexture>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlTexture_Statics::ClassParams = {
		&USlTexture::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USlTexture_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlTexture_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlTexture_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlTexture()
	{
		if (!Z_Registration_Info_UClass_USlTexture.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlTexture.OuterSingleton, Z_Construct_UClass_USlTexture_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlTexture.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlTexture>()
	{
		return USlTexture::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlTexture);
	DEFINE_FUNCTION(USlViewTexture::execCreateCPUViewTexture)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_TextureName);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureWidth);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureHeight);
		P_GET_ENUM(ESlView,Z_Param_TextureViewType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlViewTexture**)Z_Param__Result=USlViewTexture::CreateCPUViewTexture(Z_Param_Out_TextureName,Z_Param_TextureWidth,Z_Param_TextureHeight,ESlView(Z_Param_TextureViewType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlViewTexture::execCreateGPUViewTexture)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_TextureName);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureWidth);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureHeight);
		P_GET_ENUM(ESlView,Z_Param_TextureViewType);
		P_GET_UBOOL(Z_Param_bCreateTexture2D);
		P_GET_ENUM(ESlTextureFormat,Z_Param_TextureFormat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlViewTexture**)Z_Param__Result=USlViewTexture::CreateGPUViewTexture(Z_Param_Out_TextureName,Z_Param_TextureWidth,Z_Param_TextureHeight,ESlView(Z_Param_TextureViewType),Z_Param_bCreateTexture2D,ESlTextureFormat(Z_Param_TextureFormat));
		P_NATIVE_END;
	}
	void USlViewTexture::StaticRegisterNativesUSlViewTexture()
	{
		UClass* Class = USlViewTexture::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateCPUViewTexture", &USlViewTexture::execCreateCPUViewTexture },
			{ "CreateGPUViewTexture", &USlViewTexture::execCreateGPUViewTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics
	{
		struct SlViewTexture_eventCreateCPUViewTexture_Parms
		{
			FName TextureName;
			int32 TextureWidth;
			int32 TextureHeight;
			ESlView TextureViewType;
			USlViewTexture* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextureName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_TextureName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureWidth;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureHeight;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TextureViewType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TextureViewType;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureName = { "TextureName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateCPUViewTexture_Parms, TextureName), METADATA_PARAMS(Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureName_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureWidth = { "TextureWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateCPUViewTexture_Parms, TextureWidth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureHeight = { "TextureHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateCPUViewTexture_Parms, TextureHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureViewType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureViewType = { "TextureViewType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateCPUViewTexture_Parms, TextureViewType), Z_Construct_UEnum_Stereolabs_ESlView, METADATA_PARAMS(nullptr, 0) }; // 2649944809
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateCPUViewTexture_Parms, ReturnValue), Z_Construct_UClass_USlViewTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureViewType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_TextureViewType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a CPU view texture\n\x09 * @param TextureName       The name of the texture\n\x09 * @param TextureWidth\x09\x09The width of the texture\n\x09 * @param TextureHeight\x09    The height of the texture\n\x09 * @param TextureViewType   The view type of the texture\n\x09 * @return\x09\x09\x09\x09    The view texture\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Create a CPU view texture\n* @param TextureName       The name of the texture\n* @param TextureWidth          The width of the texture\n* @param TextureHeight     The height of the texture\n* @param TextureViewType   The view type of the texture\n* @return                                  The view texture" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlViewTexture, nullptr, "CreateCPUViewTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::SlViewTexture_eventCreateCPUViewTexture_Parms), Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics
	{
		struct SlViewTexture_eventCreateGPUViewTexture_Parms
		{
			FName TextureName;
			int32 TextureWidth;
			int32 TextureHeight;
			ESlView TextureViewType;
			bool bCreateTexture2D;
			ESlTextureFormat TextureFormat;
			USlViewTexture* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextureName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_TextureName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureWidth;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureHeight;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TextureViewType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TextureViewType;
		static void NewProp_bCreateTexture2D_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateTexture2D;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TextureFormat_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TextureFormat;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureName = { "TextureName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateGPUViewTexture_Parms, TextureName), METADATA_PARAMS(Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureName_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureWidth = { "TextureWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateGPUViewTexture_Parms, TextureWidth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureHeight = { "TextureHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateGPUViewTexture_Parms, TextureHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureViewType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureViewType = { "TextureViewType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateGPUViewTexture_Parms, TextureViewType), Z_Construct_UEnum_Stereolabs_ESlView, METADATA_PARAMS(nullptr, 0) }; // 2649944809
	void Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_bCreateTexture2D_SetBit(void* Obj)
	{
		((SlViewTexture_eventCreateGPUViewTexture_Parms*)Obj)->bCreateTexture2D = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_bCreateTexture2D = { "bCreateTexture2D", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlViewTexture_eventCreateGPUViewTexture_Parms), &Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_bCreateTexture2D_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureFormat = { "TextureFormat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateGPUViewTexture_Parms, TextureFormat), Z_Construct_UEnum_Stereolabs_ESlTextureFormat, METADATA_PARAMS(nullptr, 0) }; // 379800331
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlViewTexture_eventCreateGPUViewTexture_Parms, ReturnValue), Z_Construct_UClass_USlViewTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureViewType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureViewType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_bCreateTexture2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureFormat_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_TextureFormat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a GPU view texture\n\x09 * @param TextureName       The name of the texture\n\x09 * @param TextureWidth\x09\x09The width of the texture\n\x09 * @param TextureHeight\x09    The height of the texture\n\x09 * @param TextureViewType   The view type of the texture\n\x09 * @param bCreateTexture2D  True to create a texture 2D for rendering\n\x09 * @param TextureFormat\x09    The format of the texture\n\x09 * @return\x09\x09\x09\x09    The view texture\n\x09 */" },
		{ "CPP_Default_bCreateTexture2D", "true" },
		{ "CPP_Default_TextureFormat", "TF_R8G8B8A8_SNORM" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Create a GPU view texture\n* @param TextureName       The name of the texture\n* @param TextureWidth          The width of the texture\n* @param TextureHeight     The height of the texture\n* @param TextureViewType   The view type of the texture\n* @param bCreateTexture2D  True to create a texture 2D for rendering\n* @param TextureFormat     The format of the texture\n* @return                                  The view texture" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlViewTexture, nullptr, "CreateGPUViewTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::SlViewTexture_eventCreateGPUViewTexture_Parms), Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlViewTexture);
	UClass* Z_Construct_UClass_USlViewTexture_NoRegister()
	{
		return USlViewTexture::StaticClass();
	}
	struct Z_Construct_UClass_USlViewTexture_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_ViewType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ViewType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ViewType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlViewTexture_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlTexture,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlViewTexture_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlViewTexture_CreateCPUViewTexture, "CreateCPUViewTexture" }, // 4230988436
		{ &Z_Construct_UFunction_USlViewTexture_CreateGPUViewTexture, "CreateGPUViewTexture" }, // 4251503413
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlViewTexture_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Zed|Types" },
		{ "Comment", "/*\n * A view texture to retrieve images\n */" },
		{ "IncludePath", "Core/StereolabsTexture.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* A view texture to retrieve images" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType_MetaData[] = {
		{ "Category", "SlViewTexture" },
		{ "Comment", "/** Texture view type */" },
		{ "DisplayName", "ViewType" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Texture view type" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType = { "ViewType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlViewTexture, ViewType), Z_Construct_UEnum_Stereolabs_ESlView, METADATA_PARAMS(Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType_MetaData)) }; // 2649944809
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USlViewTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlViewTexture_Statics::NewProp_ViewType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlViewTexture_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlViewTexture>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlViewTexture_Statics::ClassParams = {
		&USlViewTexture::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USlViewTexture_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USlViewTexture_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlViewTexture_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlViewTexture_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlViewTexture()
	{
		if (!Z_Registration_Info_UClass_USlViewTexture.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlViewTexture.OuterSingleton, Z_Construct_UClass_USlViewTexture_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlViewTexture.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlViewTexture>()
	{
		return USlViewTexture::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlViewTexture);
	DEFINE_FUNCTION(USlMeasureTexture::execCreateCPUMeasureTexture)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_TextureName);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureWidth);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureHeight);
		P_GET_ENUM(ESlMeasure,Z_Param_TextureMeasureType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlMeasureTexture**)Z_Param__Result=USlMeasureTexture::CreateCPUMeasureTexture(Z_Param_Out_TextureName,Z_Param_TextureWidth,Z_Param_TextureHeight,ESlMeasure(Z_Param_TextureMeasureType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMeasureTexture::execCreateGPUMeasureTexture)
	{
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_TextureName);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureWidth);
		P_GET_PROPERTY(FIntProperty,Z_Param_TextureHeight);
		P_GET_ENUM(ESlMeasure,Z_Param_TextureMeasureType);
		P_GET_UBOOL(Z_Param_bCreateTexture2D);
		P_GET_ENUM(ESlTextureFormat,Z_Param_TextureFormat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlMeasureTexture**)Z_Param__Result=USlMeasureTexture::CreateGPUMeasureTexture(Z_Param_Out_TextureName,Z_Param_TextureWidth,Z_Param_TextureHeight,ESlMeasure(Z_Param_TextureMeasureType),Z_Param_bCreateTexture2D,ESlTextureFormat(Z_Param_TextureFormat));
		P_NATIVE_END;
	}
	void USlMeasureTexture::StaticRegisterNativesUSlMeasureTexture()
	{
		UClass* Class = USlMeasureTexture::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateCPUMeasureTexture", &USlMeasureTexture::execCreateCPUMeasureTexture },
			{ "CreateGPUMeasureTexture", &USlMeasureTexture::execCreateGPUMeasureTexture },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics
	{
		struct SlMeasureTexture_eventCreateCPUMeasureTexture_Parms
		{
			FName TextureName;
			int32 TextureWidth;
			int32 TextureHeight;
			ESlMeasure TextureMeasureType;
			USlMeasureTexture* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextureName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_TextureName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureWidth;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureHeight;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TextureMeasureType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TextureMeasureType;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureName = { "TextureName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateCPUMeasureTexture_Parms, TextureName), METADATA_PARAMS(Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureName_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureWidth = { "TextureWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateCPUMeasureTexture_Parms, TextureWidth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureHeight = { "TextureHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateCPUMeasureTexture_Parms, TextureHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureMeasureType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureMeasureType = { "TextureMeasureType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateCPUMeasureTexture_Parms, TextureMeasureType), Z_Construct_UEnum_Stereolabs_ESlMeasure, METADATA_PARAMS(nullptr, 0) }; // 2873616250
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateCPUMeasureTexture_Parms, ReturnValue), Z_Construct_UClass_USlMeasureTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureMeasureType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_TextureMeasureType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a CPU measure texture\n\x09 * @param TextureName        The name of the texture\n\x09 * @param TextureWidth\x09\x09 The width of the texture\n\x09 * @param TextureHeight\x09     The height of the texture\n\x09 * @param TextureMeasureType The measure type of the texture\n\x09 * @return\x09\x09\x09\x09     The measure texture\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Create a CPU measure texture\n* @param TextureName        The name of the texture\n* @param TextureWidth           The width of the texture\n* @param TextureHeight      The height of the texture\n* @param TextureMeasureType The measure type of the texture\n* @return                                   The measure texture" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMeasureTexture, nullptr, "CreateCPUMeasureTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::SlMeasureTexture_eventCreateCPUMeasureTexture_Parms), Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics
	{
		struct SlMeasureTexture_eventCreateGPUMeasureTexture_Parms
		{
			FName TextureName;
			int32 TextureWidth;
			int32 TextureHeight;
			ESlMeasure TextureMeasureType;
			bool bCreateTexture2D;
			ESlTextureFormat TextureFormat;
			USlMeasureTexture* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextureName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_TextureName;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureWidth;
		static const UECodeGen_Private::FIntPropertyParams NewProp_TextureHeight;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TextureMeasureType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TextureMeasureType;
		static void NewProp_bCreateTexture2D_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCreateTexture2D;
		static const UECodeGen_Private::FBytePropertyParams NewProp_TextureFormat_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TextureFormat;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureName = { "TextureName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms, TextureName), METADATA_PARAMS(Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureName_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureWidth = { "TextureWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms, TextureWidth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureHeight = { "TextureHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms, TextureHeight), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureMeasureType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureMeasureType = { "TextureMeasureType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms, TextureMeasureType), Z_Construct_UEnum_Stereolabs_ESlMeasure, METADATA_PARAMS(nullptr, 0) }; // 2873616250
	void Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_bCreateTexture2D_SetBit(void* Obj)
	{
		((SlMeasureTexture_eventCreateGPUMeasureTexture_Parms*)Obj)->bCreateTexture2D = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_bCreateTexture2D = { "bCreateTexture2D", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms), &Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_bCreateTexture2D_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureFormat = { "TextureFormat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms, TextureFormat), Z_Construct_UEnum_Stereolabs_ESlTextureFormat, METADATA_PARAMS(nullptr, 0) }; // 379800331
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMeasureTexture_eventCreateGPUMeasureTexture_Parms, ReturnValue), Z_Construct_UClass_USlMeasureTexture_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureMeasureType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureMeasureType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_bCreateTexture2D,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureFormat_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_TextureFormat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "Comment", "/*\n\x09 * Create a GPU measure texture\n\x09 * @param TextureName        The name of the texture\n\x09 * @param TextureWidth\x09\x09 The width of the texture\n\x09 * @param TextureHeight\x09     The height of the texture\n\x09 * @param TextureMeasureType The measure type of the texture\n\x09 * @param bCreateTexture2D   True to create a texture 2D for rendering\n\x09 * @param TextureFormat\x09     The format of the texture\n\x09 * @return\x09\x09\x09\x09     The measure texture\n\x09 */" },
		{ "CPP_Default_bCreateTexture2D", "true" },
		{ "CPP_Default_TextureFormat", "TF_R32_FLOAT" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* Create a GPU measure texture\n* @param TextureName        The name of the texture\n* @param TextureWidth           The width of the texture\n* @param TextureHeight      The height of the texture\n* @param TextureMeasureType The measure type of the texture\n* @param bCreateTexture2D   True to create a texture 2D for rendering\n* @param TextureFormat      The format of the texture\n* @return                                   The measure texture" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMeasureTexture, nullptr, "CreateGPUMeasureTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::SlMeasureTexture_eventCreateGPUMeasureTexture_Parms), Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlMeasureTexture);
	UClass* Z_Construct_UClass_USlMeasureTexture_NoRegister()
	{
		return USlMeasureTexture::StaticClass();
	}
	struct Z_Construct_UClass_USlMeasureTexture_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_MeasureType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeasureType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MeasureType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlMeasureTexture_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlTexture,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlMeasureTexture_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlMeasureTexture_CreateCPUMeasureTexture, "CreateCPUMeasureTexture" }, // 611096473
		{ &Z_Construct_UFunction_USlMeasureTexture_CreateGPUMeasureTexture, "CreateGPUMeasureTexture" }, // 3942575284
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlMeasureTexture_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "Zed|Types" },
		{ "Comment", "/*\n * A measure texture to retrieve measures\n */" },
		{ "IncludePath", "Core/StereolabsTexture.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "* A measure texture to retrieve measures" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType_MetaData[] = {
		{ "Category", "SlMeasureTexture" },
		{ "Comment", "/** Texture measure type */" },
		{ "DisplayName", "MeasureType" },
		{ "ModuleRelativePath", "Public/Core/StereolabsTexture.h" },
		{ "ToolTip", "Texture measure type" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType = { "MeasureType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USlMeasureTexture, MeasureType), Z_Construct_UEnum_Stereolabs_ESlMeasure, METADATA_PARAMS(Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType_MetaData)) }; // 2873616250
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USlMeasureTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USlMeasureTexture_Statics::NewProp_MeasureType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlMeasureTexture_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlMeasureTexture>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlMeasureTexture_Statics::ClassParams = {
		&USlMeasureTexture::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USlMeasureTexture_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USlMeasureTexture_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USlMeasureTexture_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlMeasureTexture_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlMeasureTexture()
	{
		if (!Z_Registration_Info_UClass_USlMeasureTexture.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlMeasureTexture.OuterSingleton, Z_Construct_UClass_USlMeasureTexture_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlMeasureTexture.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlMeasureTexture>()
	{
		return USlMeasureTexture::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlMeasureTexture);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USlTexture, USlTexture::StaticClass, TEXT("USlTexture"), &Z_Registration_Info_UClass_USlTexture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlTexture), 1579831500U) },
		{ Z_Construct_UClass_USlViewTexture, USlViewTexture::StaticClass, TEXT("USlViewTexture"), &Z_Registration_Info_UClass_USlViewTexture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlViewTexture), 1631016948U) },
		{ Z_Construct_UClass_USlMeasureTexture, USlMeasureTexture::StaticClass, TEXT("USlMeasureTexture"), &Z_Registration_Info_UClass_USlMeasureTexture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlMeasureTexture), 2758273432U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_2974650831(TEXT("/Script/Stereolabs"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsTexture_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
