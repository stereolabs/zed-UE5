// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Utilities/StereolabsMatFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsMatFunctionLibrary() {}
// Cross Module References
	STEREOLABS_API UClass* Z_Construct_UClass_USlMatFunctionLibrary_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlMatFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlMat();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlMatType();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlMemoryType();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlErrorCode();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlCopyType();
// End Cross Module References
	DEFINE_FUNCTION(USlMatFunctionLibrary::execClone)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Src);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::Clone(Z_Param_Out_Mat,Z_Param_Out_Src);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execIsMemoryOwner)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlMatFunctionLibrary::IsMemoryOwner(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execIsInit)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlMatFunctionLibrary::IsInit(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetInfos)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=USlMatFunctionLibrary::GetInfos(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execgetWidthBytes)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USlMatFunctionLibrary::getWidthBytes(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetPixelBytes)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USlMatFunctionLibrary::GetPixelBytes(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetStepBytes)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_ENUM(ESlMemoryType,Z_Param_MemoryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USlMatFunctionLibrary::GetStepBytes(Z_Param_Out_Mat,ESlMemoryType(Z_Param_MemoryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetMemoryType)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlMemoryType*)Z_Param__Result=USlMatFunctionLibrary::GetMemoryType(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetDataType)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlMatType*)Z_Param__Result=USlMatFunctionLibrary::GetDataType(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetChannels)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USlMatFunctionLibrary::GetChannels(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetResolution)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FIntPoint*)Z_Param__Result=USlMatFunctionLibrary::GetResolution(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetHeight)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USlMatFunctionLibrary::GetHeight(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execGetWidth)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=USlMatFunctionLibrary::GetWidth(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execWrite)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_PROPERTY(FStrProperty,Z_Param_Path);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::Write(Z_Param_Out_Mat,Z_Param_Path);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execRead)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_PROPERTY(FStrProperty,Z_Param_Path);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::Read(Z_Param_Out_Mat,Z_Param_Path);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execSetFrom)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Src);
		P_GET_ENUM(ESlCopyType,Z_Param_CopyType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::SetFrom(Z_Param_Out_Mat,Z_Param_Out_Src,ESlCopyType(Z_Param_CopyType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execCopyTo)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Dst);
		P_GET_ENUM(ESlCopyType,Z_Param_CopyType);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::CopyTo(Z_Param_Out_Mat,Z_Param_Out_Dst,ESlCopyType(Z_Param_CopyType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execUpdateGPUFromCPU)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::UpdateGPUFromCPU(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execUpdateCPUFromGPU)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=USlMatFunctionLibrary::UpdateCPUFromGPU(Z_Param_Out_Mat);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execFree)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_ENUM(ESlMemoryType,Z_Param_MemoryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlMatFunctionLibrary::Free(Z_Param_Out_Mat,ESlMemoryType(Z_Param_MemoryType));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMatFunctionLibrary::execAllocate)
	{
		P_GET_STRUCT_REF(FSlMat,Z_Param_Out_Mat);
		P_GET_STRUCT_REF(FIntPoint,Z_Param_Out_Resolution);
		P_GET_ENUM(ESlMatType,Z_Param_Type);
		P_GET_ENUM(ESlMemoryType,Z_Param_MemoryType);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlMatFunctionLibrary::Allocate(Z_Param_Out_Mat,Z_Param_Out_Resolution,ESlMatType(Z_Param_Type),ESlMemoryType(Z_Param_MemoryType));
		P_NATIVE_END;
	}
	void USlMatFunctionLibrary::StaticRegisterNativesUSlMatFunctionLibrary()
	{
		UClass* Class = USlMatFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Allocate", &USlMatFunctionLibrary::execAllocate },
			{ "Clone", &USlMatFunctionLibrary::execClone },
			{ "CopyTo", &USlMatFunctionLibrary::execCopyTo },
			{ "Free", &USlMatFunctionLibrary::execFree },
			{ "GetChannels", &USlMatFunctionLibrary::execGetChannels },
			{ "GetDataType", &USlMatFunctionLibrary::execGetDataType },
			{ "GetHeight", &USlMatFunctionLibrary::execGetHeight },
			{ "GetInfos", &USlMatFunctionLibrary::execGetInfos },
			{ "GetMemoryType", &USlMatFunctionLibrary::execGetMemoryType },
			{ "GetPixelBytes", &USlMatFunctionLibrary::execGetPixelBytes },
			{ "GetResolution", &USlMatFunctionLibrary::execGetResolution },
			{ "GetStepBytes", &USlMatFunctionLibrary::execGetStepBytes },
			{ "GetWidth", &USlMatFunctionLibrary::execGetWidth },
			{ "getWidthBytes", &USlMatFunctionLibrary::execgetWidthBytes },
			{ "IsInit", &USlMatFunctionLibrary::execIsInit },
			{ "IsMemoryOwner", &USlMatFunctionLibrary::execIsMemoryOwner },
			{ "Read", &USlMatFunctionLibrary::execRead },
			{ "SetFrom", &USlMatFunctionLibrary::execSetFrom },
			{ "UpdateCPUFromGPU", &USlMatFunctionLibrary::execUpdateCPUFromGPU },
			{ "UpdateGPUFromCPU", &USlMatFunctionLibrary::execUpdateGPUFromCPU },
			{ "Write", &USlMatFunctionLibrary::execWrite },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics
	{
		struct SlMatFunctionLibrary_eventAllocate_Parms
		{
			FSlMat Mat;
			FIntPoint Resolution;
			ESlMatType Type;
			ESlMemoryType MemoryType;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Resolution_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Resolution;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MemoryType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MemoryType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MemoryType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventAllocate_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Resolution_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Resolution = { "Resolution", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventAllocate_Parms, Resolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Resolution_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Resolution_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventAllocate_Parms, Type), Z_Construct_UEnum_Stereolabs_ESlMatType, METADATA_PARAMS(nullptr, 0) }; // 3351091038
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType_MetaData[] = {
		{ "Bitmask", "" },
		{ "BitmaskEnum", "ESlMemoryType" },
		{ "DisplayName", "MemoryType" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType = { "MemoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventAllocate_Parms, MemoryType), Z_Construct_UEnum_Stereolabs_ESlMemoryType, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType_MetaData)) }; // 650491615
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Resolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_Type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::NewProp_MemoryType,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Allocates the Mat memory\n\x09 * @param Resolution The size of the matrix in pixels\n\x09 * @param Type\x09\x09 The type of the matrix (ESlMatType::MT_32F_C1, ESlMatType::MT__8U_C4)\n\x09 * @param MemoryType Defines where the buffer will be stored (sl::MEM_CPU and/or sl::MEM_GPU)\n\x09 * @warning\x09\x09\x09 It erases previously allocated memory\n\x09 */" },
		{ "CPP_Default_MemoryType", "MT_CPU" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Allocates the Mat memory\n* @param Resolution The size of the matrix in pixels\n* @param Type           The type of the matrix (ESlMatType::MT_32F_C1, ESlMatType::MT__8U_C4)\n* @param MemoryType Defines where the buffer will be stored (sl::MEM_CPU and/or sl::MEM_GPU)\n* @warning                      It erases previously allocated memory" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "Allocate", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::SlMatFunctionLibrary_eventAllocate_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_Allocate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_Allocate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics
	{
		struct SlMatFunctionLibrary_eventClone_Parms
		{
			FSlMat Mat;
			FSlMat Src;
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Src;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventClone_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_Src = { "Src", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventClone_Parms, Src), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventClone_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_Src,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Duplicates Mat by copy (deep copy)\n\x09 * @param Src The reference to the Mat to copy\n\x09 * This function copies the data array(s), it mark the new Mat as the memory owner\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Duplicates Mat by copy (deep copy)\n* @param Src The reference to the Mat to copy\n* This function copies the data array(s), it mark the new Mat as the memory owner" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "Clone", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::SlMatFunctionLibrary_eventClone_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_Clone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_Clone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics
	{
		struct SlMatFunctionLibrary_eventCopyTo_Parms
		{
			FSlMat Mat;
			FSlMat Dst;
			ESlCopyType CopyType;
			ESlErrorCode ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Dst;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CopyType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CopyType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventCopyTo_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Dst = { "Dst", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventCopyTo_Parms, Dst), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_CopyType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_CopyType = { "CopyType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventCopyTo_Parms, CopyType), Z_Construct_UEnum_Stereolabs_ESlCopyType, METADATA_PARAMS(nullptr, 0) }; // 1751069478
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventCopyTo_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_Dst,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_CopyType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_CopyType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Copies data in other Mat (deep copy)\n\x09 * @param Dst\x09   The Mat where the data will be copied\n\x09 * @param CopyType Specify the memories that will be used for the copy\n\x09 * @return\x09\x09   EC_Success if everything went well,  EC_Failure otherwise\n\x09 * @note If the Destination is not allocated or has a not a compatible  MAT_TYPE or  Resolution,\n\x09 * current memory is freed and new memory is directly allocated\n\x09 */" },
		{ "CPP_Default_CopyType", "CT_CPUToCPU" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Copies data in other Mat (deep copy)\n* @param Dst      The Mat where the data will be copied\n* @param CopyType Specify the memories that will be used for the copy\n* @return                 EC_Success if everything went well,  EC_Failure otherwise\n* @note If the Destination is not allocated or has a not a compatible  MAT_TYPE or  Resolution,\n* current memory is freed and new memory is directly allocated" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "CopyTo", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::SlMatFunctionLibrary_eventCopyTo_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics
	{
		struct SlMatFunctionLibrary_eventFree_Parms
		{
			FSlMat Mat;
			ESlMemoryType MemoryType;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MemoryType_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MemoryType_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MemoryType;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventFree_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType_MetaData[] = {
		{ "Bitmask", "" },
		{ "BitmaskEnum", "ESlMemoryType" },
		{ "DisplayName", "MemoryType" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType = { "MemoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventFree_Parms, MemoryType), Z_Construct_UEnum_Stereolabs_ESlMemoryType, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType_MetaData)) }; // 650491615
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::NewProp_MemoryType,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Free the owned memory\n\x09 * @param MemoryType Specify whether you want to free the  MEM_CPU and/or  MEM_GPU memory\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Free the owned memory\n* @param MemoryType Specify whether you want to free the  MEM_CPU and/or  MEM_GPU memory" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "Free", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::SlMatFunctionLibrary_eventFree_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_Free()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_Free_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics
	{
		struct SlMatFunctionLibrary_eventGetChannels_Parms
		{
			FSlMat Mat;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetChannels_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetChannels_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the number of values stored in one pixel\n\x09 * @return The number of values in a pixel\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the number of values stored in one pixel\n* @return The number of values in a pixel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetChannels", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::SlMatFunctionLibrary_eventGetChannels_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics
	{
		struct SlMatFunctionLibrary_eventGetDataType_Parms
		{
			FSlMat Mat;
			ESlMatType ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetDataType_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetDataType_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlMatType, METADATA_PARAMS(nullptr, 0) }; // 3351091038
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the format of the matrix\n\x09 * @return The format of the current Mat\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the format of the matrix\n* @return The format of the current Mat" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetDataType", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::SlMatFunctionLibrary_eventGetDataType_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics
	{
		struct SlMatFunctionLibrary_eventGetHeight_Parms
		{
			FSlMat Mat;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetHeight_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetHeight_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the height of the matrix\n\x09 * @return The height of the matrix in pixels\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the height of the matrix\n* @return The height of the matrix in pixels" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetHeight", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::SlMatFunctionLibrary_eventGetHeight_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics
	{
		struct SlMatFunctionLibrary_eventGetInfos_Parms
		{
			FSlMat Mat;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetInfos_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetInfos_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the informations about the Mat into a FString\n\x09 * @return A string containing the Mat informations\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the informations about the Mat into a FString\n* @return A string containing the Mat informations" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::SlMatFunctionLibrary_eventGetInfos_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics
	{
		struct SlMatFunctionLibrary_eventGetMemoryType_Parms
		{
			FSlMat Mat;
			ESlMemoryType ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetMemoryType_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetMemoryType_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlMemoryType, METADATA_PARAMS(nullptr, 0) }; // 650491615
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the type of memory (CPU and/or GPU)\n\x09 * @return The type of allocated memory\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the type of memory (CPU and/or GPU)\n* @return The type of allocated memory" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetMemoryType", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::SlMatFunctionLibrary_eventGetMemoryType_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics
	{
		struct SlMatFunctionLibrary_eventGetPixelBytes_Parms
		{
			FSlMat Mat;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetPixelBytes_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetPixelBytes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the size in bytes of one pixel\n\x09 * @return The size in bytes of a pixel\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the size in bytes of one pixel\n* @return The size in bytes of a pixel" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetPixelBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::SlMatFunctionLibrary_eventGetPixelBytes_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics
	{
		struct SlMatFunctionLibrary_eventGetResolution_Parms
		{
			FSlMat Mat;
			FIntPoint ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetResolution_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetResolution_Parms, ReturnValue), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the height of the matrix\n\x09 * @return The height of the matrix in pixels\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the height of the matrix\n* @return The height of the matrix in pixels" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetResolution", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::SlMatFunctionLibrary_eventGetResolution_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics
	{
		struct SlMatFunctionLibrary_eventGetStepBytes_Parms
		{
			FSlMat Mat;
			ESlMemoryType MemoryType;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MemoryType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MemoryType;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetStepBytes_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_MemoryType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_MemoryType = { "MemoryType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetStepBytes_Parms, MemoryType), Z_Construct_UEnum_Stereolabs_ESlMemoryType, METADATA_PARAMS(nullptr, 0) }; // 650491615
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetStepBytes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_MemoryType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_MemoryType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the memory step in Bytes (the Bytes size of one pixel row)\n\x09 * @param MemoryTYpe Specify whether you want  MEM_CPU or  MEM_GPU step\n\x09 * @return The step in bytes of the specified memory\n\x09 */" },
		{ "CPP_Default_MemoryType", "MT_CPU" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the memory step in Bytes (the Bytes size of one pixel row)\n* @param MemoryTYpe Specify whether you want  MEM_CPU or  MEM_GPU step\n* @return The step in bytes of the specified memory" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetStepBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::SlMatFunctionLibrary_eventGetStepBytes_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics
	{
		struct SlMatFunctionLibrary_eventGetWidth_Parms
		{
			FSlMat Mat;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetWidth_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventGetWidth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the width of the matrix\n\x09 * @return The width of the matrix in pixels\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the width of the matrix\n* @return The width of the matrix in pixels" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "GetWidth", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::SlMatFunctionLibrary_eventGetWidth_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics
	{
		struct SlMatFunctionLibrary_eventgetWidthBytes_Parms
		{
			FSlMat Mat;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventgetWidthBytes_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventgetWidthBytes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns the size in bytes of a row\n\x09 * @return The size in bytes of a row\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns the size in bytes of a row\n* @return The size in bytes of a row" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "getWidthBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::SlMatFunctionLibrary_eventgetWidthBytes_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics
	{
		struct SlMatFunctionLibrary_eventIsInit_Parms
		{
			FSlMat Mat;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventIsInit_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	void Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlMatFunctionLibrary_eventIsInit_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMatFunctionLibrary_eventIsInit_Parms), &Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Defines whether the Mat is initialized or not\n\x09 * @return True if current Mat has been allocated (by the constructor or therefore)\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Defines whether the Mat is initialized or not\n* @return True if current Mat has been allocated (by the constructor or therefore)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "IsInit", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::SlMatFunctionLibrary_eventIsInit_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_IsInit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_IsInit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics
	{
		struct SlMatFunctionLibrary_eventIsMemoryOwner_Parms
		{
			FSlMat Mat;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mat_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_Mat_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventIsMemoryOwner_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_Mat_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_Mat_MetaData)) }; // 1719170131
	void Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlMatFunctionLibrary_eventIsMemoryOwner_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMatFunctionLibrary_eventIsMemoryOwner_Parms), &Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Returns whether the Mat is the owner of the memory it access\n\x09 * If not, the memory won't be freed if the Mat is destroyed\n\x09 * @return True if the Mat is owning its memory, else false\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Returns whether the Mat is the owner of the memory it access\n* If not, the memory won't be freed if the Mat is destroyed\n* @return True if the Mat is owning its memory, else false" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "IsMemoryOwner", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::SlMatFunctionLibrary_eventIsMemoryOwner_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics
	{
		struct SlMatFunctionLibrary_eventRead_Parms
		{
			FSlMat Mat;
			FString Path;
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventRead_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventRead_Parms, Path), METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Path_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Path_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventRead_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_Path,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Reads an image from a file (only if  MEM_CPU is available on the current  Mat).\n\x09 * Supported input files format are PNG and JPEG\n\x09 * @param Path File path including the name and extension\n\x09 * @return     EC_Success if everything went well,  EC_Failure otherwise\n\x09 * @note Supported ESlMatType are : MT_8U_C1,  MT_8U_C3 and  MT_8U_C4\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Reads an image from a file (only if  MEM_CPU is available on the current  Mat).\n* Supported input files format are PNG and JPEG\n* @param Path File path including the name and extension\n* @return     EC_Success if everything went well,  EC_Failure otherwise\n* @note Supported ESlMatType are : MT_8U_C1,  MT_8U_C3 and  MT_8U_C4" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "Read", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::SlMatFunctionLibrary_eventRead_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_Read()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_Read_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics
	{
		struct SlMatFunctionLibrary_eventSetFrom_Parms
		{
			FSlMat Mat;
			FSlMat Src;
			ESlCopyType CopyType;
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Src_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Src;
		static const UECodeGen_Private::FBytePropertyParams NewProp_CopyType_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_CopyType;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventSetFrom_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Src_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Src = { "Src", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventSetFrom_Parms, Src), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Src_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Src_MetaData)) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_CopyType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_CopyType = { "CopyType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventSetFrom_Parms, CopyType), Z_Construct_UEnum_Stereolabs_ESlCopyType, METADATA_PARAMS(nullptr, 0) }; // 1751069478
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventSetFrom_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_Src,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_CopyType_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_CopyType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Copies data from an other Mat (deep copy)\n\x09 * @param Src\x09   The Mat where the data will be copied from\n\x09 * @param CopyType Specify the memories that will be used for the update\n\x09 * @return\x09\x09   EC_Success if everything went well,  EC_Failure otherwise\n\x09 * @note If the current Mat is not allocated or has a not a compatible  MAT_TYPE or  Resolution with the Src,\n\x09 * current memory is freed and new memory is directly allocated\n\x09 */" },
		{ "CPP_Default_CopyType", "CT_CPUToCPU" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Copies data from an other Mat (deep copy)\n* @param Src      The Mat where the data will be copied from\n* @param CopyType Specify the memories that will be used for the update\n* @return                 EC_Success if everything went well,  EC_Failure otherwise\n* @note If the current Mat is not allocated or has a not a compatible  MAT_TYPE or  Resolution with the Src,\n* current memory is freed and new memory is directly allocated" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "SetFrom", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::SlMatFunctionLibrary_eventSetFrom_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics
	{
		struct SlMatFunctionLibrary_eventUpdateCPUFromGPU_Parms
		{
			FSlMat Mat;
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventUpdateCPUFromGPU_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventUpdateCPUFromGPU_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Downloads data from DEVICE (GPU) to HOST (CPU), if possible\n\x09 * @return  EC_Success if everything went well,  EC_Failure otherwise\n\x09 * @note If no CPU or GPU memory are available for this Mat, some are directly allocated\n\x09 * @note If verbose sets, you have informations in case of failure\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Downloads data from DEVICE (GPU) to HOST (CPU), if possible\n* @return  EC_Success if everything went well,  EC_Failure otherwise\n* @note If no CPU or GPU memory are available for this Mat, some are directly allocated\n* @note If verbose sets, you have informations in case of failure" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "UpdateCPUFromGPU", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::SlMatFunctionLibrary_eventUpdateCPUFromGPU_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics
	{
		struct SlMatFunctionLibrary_eventUpdateGPUFromCPU_Parms
		{
			FSlMat Mat;
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventUpdateGPUFromCPU_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventUpdateGPUFromCPU_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Uploads data from HOST (CPU) to DEVICE (GPU), if possible\n\x09 * @return  EC_Success if everything went well,  EC_Failure otherwise\n\x09 * @note If no CPU or GPU memory are available for this Mat, some are directly allocated\n\x09 * @note If verbose sets, you have informations in case of failure\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Uploads data from HOST (CPU) to DEVICE (GPU), if possible\n* @return  EC_Success if everything went well,  EC_Failure otherwise\n* @note If no CPU or GPU memory are available for this Mat, some are directly allocated\n* @note If verbose sets, you have informations in case of failure" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "UpdateGPUFromCPU", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::SlMatFunctionLibrary_eventUpdateGPUFromCPU_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics
	{
		struct SlMatFunctionLibrary_eventWrite_Parms
		{
			FSlMat Mat;
			FString Path;
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Mat;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Mat = { "Mat", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventWrite_Parms, Mat), Z_Construct_UScriptStruct_FSlMat, METADATA_PARAMS(nullptr, 0) }; // 1719170131
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Path_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventWrite_Parms, Path), METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Path_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Path_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMatFunctionLibrary_eventWrite_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Mat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_Path,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs|Mat" },
		{ "Comment", "/*\n\x09 * Writes the  Mat (only if  MEM_CPU is available) into a file as an image\n\x09 * Supported output files format are PNG and JPEG\n\x09 * @param Path File path including the name and extension\n\x09 * @return\x09   EC_Success if everything went well,  EC_Failure otherwise\n\x09 * @note Supported  ESlMatType are : MT_8U_C1,  MT_8U_C3 and  MT_8U_C4\n\x09 */" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ToolTip", "* Writes the  Mat (only if  MEM_CPU is available) into a file as an image\n* Supported output files format are PNG and JPEG\n* @param Path File path including the name and extension\n* @return         EC_Success if everything went well,  EC_Failure otherwise\n* @note Supported  ESlMatType are : MT_8U_C1,  MT_8U_C3 and  MT_8U_C4" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMatFunctionLibrary, nullptr, "Write", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::SlMatFunctionLibrary_eventWrite_Parms), Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMatFunctionLibrary_Write()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMatFunctionLibrary_Write_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlMatFunctionLibrary);
	UClass* Z_Construct_UClass_USlMatFunctionLibrary_NoRegister()
	{
		return USlMatFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USlMatFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlMatFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlMatFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_Allocate, "Allocate" }, // 183714748
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_Clone, "Clone" }, // 3775497804
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_CopyTo, "CopyTo" }, // 938330592
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_Free, "Free" }, // 739363844
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetChannels, "GetChannels" }, // 767633578
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetDataType, "GetDataType" }, // 2217838155
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetHeight, "GetHeight" }, // 3499451832
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetInfos, "GetInfos" }, // 1288035653
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetMemoryType, "GetMemoryType" }, // 3447552398
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetPixelBytes, "GetPixelBytes" }, // 3935776015
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetResolution, "GetResolution" }, // 1420057941
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetStepBytes, "GetStepBytes" }, // 3974955390
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_GetWidth, "GetWidth" }, // 3402835838
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_getWidthBytes, "getWidthBytes" }, // 2796826994
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_IsInit, "IsInit" }, // 147062141
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_IsMemoryOwner, "IsMemoryOwner" }, // 4193339586
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_Read, "Read" }, // 1588356750
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_SetFrom, "SetFrom" }, // 3282988135
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_UpdateCPUFromGPU, "UpdateCPUFromGPU" }, // 1260652394
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_UpdateGPUFromCPU, "UpdateGPUFromCPU" }, // 3065872134
		{ &Z_Construct_UFunction_USlMatFunctionLibrary_Write, "Write" }, // 3363718776
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlMatFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Utilities/StereolabsMatFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsMatFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlMatFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlMatFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlMatFunctionLibrary_Statics::ClassParams = {
		&USlMatFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USlMatFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlMatFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlMatFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_USlMatFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlMatFunctionLibrary.OuterSingleton, Z_Construct_UClass_USlMatFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlMatFunctionLibrary.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlMatFunctionLibrary>()
	{
		return USlMatFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlMatFunctionLibrary);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USlMatFunctionLibrary, USlMatFunctionLibrary::StaticClass, TEXT("USlMatFunctionLibrary"), &Z_Registration_Info_UClass_USlMatFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlMatFunctionLibrary), 2249419568U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_3101476674(TEXT("/Script/Stereolabs"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsMatFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
