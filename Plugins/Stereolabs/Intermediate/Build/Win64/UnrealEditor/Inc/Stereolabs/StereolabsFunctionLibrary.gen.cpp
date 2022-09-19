// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Utilities/StereolabsFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsFunctionLibrary() {}
// Cross Module References
	STEREOLABS_API UClass* Z_Construct_UClass_USlFunctionLibrary_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlTimestamp();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlMeshData();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlCameraParameters();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlViewportHelper();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlErrorCode();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlCameraProxy_NoRegister();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlEye();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FIntPoint();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector4();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMatrix();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlObjectData();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlSpatialMappingParameters();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlSpatialMappingRange();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlSpatialMappingResolution();
// End Cross Module References
	DEFINE_FUNCTION(USlFunctionLibrary::execSet3DBoxTransform)
	{
		P_GET_OBJECT_REF(AActor,Z_Param_Out_BBox);
		P_GET_STRUCT(FSlObjectData,Z_Param_ObjectData);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::Set3DBoxTransform(Z_Param_Out_BBox,Z_Param_ObjectData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetHmdFocale)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=USlFunctionLibrary::GetHmdFocale();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGenerateTextureFromTxtFile)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_filepath);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=USlFunctionLibrary::GenerateTextureFromTxtFile(Z_Param_filepath);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execSubstract_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FSlTimestamp*)Z_Param__Result=USlFunctionLibrary::Substract_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execAdd_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FSlTimestamp*)Z_Param__Result=USlFunctionLibrary::Add_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGreaterEqual_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::GreaterEqual_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGreater_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::Greater_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execLessEqual_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::LessEqual_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execLess_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::Less_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execNotEqual_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::NotEqual_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execEqualEqual_TimestampTimestamp)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_A);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::EqualEqual_TimestampTimestamp(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execConv_TimestampToString)
	{
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_InTimestamp);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=USlFunctionLibrary::Conv_TimestampToString(Z_Param_Out_InTimestamp);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execClearMeshData)
	{
		P_GET_STRUCT_REF(FSlMeshData,Z_Param_Out_MeshData);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::ClearMeshData(Z_Param_Out_MeshData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execSetMaxRangeValue)
	{
		P_GET_STRUCT_REF(FSlSpatialMappingParameters,Z_Param_Out_SpatialMappingParameters);
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewMaxRange);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::SetMaxRangeValue(Z_Param_Out_SpatialMappingParameters,Z_Param_NewMaxRange);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execSetMaxRangePreset)
	{
		P_GET_STRUCT_REF(FSlSpatialMappingParameters,Z_Param_Out_SpatialMappingParameters);
		P_GET_ENUM(ESlSpatialMappingRange,Z_Param_NewMaxRange);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::SetMaxRangePreset(Z_Param_Out_SpatialMappingParameters,ESlSpatialMappingRange(Z_Param_NewMaxRange));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execSetResolutionValue)
	{
		P_GET_STRUCT_REF(FSlSpatialMappingParameters,Z_Param_Out_SpatialMappingParameters);
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewResolution);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::SetResolutionValue(Z_Param_Out_SpatialMappingParameters,Z_Param_NewResolution);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execSetResolutionPreset)
	{
		P_GET_STRUCT_REF(FSlSpatialMappingParameters,Z_Param_Out_SpatialMappingParameters);
		P_GET_ENUM(ESlSpatialMappingResolution,Z_Param_NewResolution);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::SetResolutionPreset(Z_Param_Out_SpatialMappingParameters,ESlSpatialMappingResolution(Z_Param_NewResolution));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execErrorCodeToString)
	{
		P_GET_ENUM(ESlErrorCode,Z_Param_ErrorCode);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=USlFunctionLibrary::ErrorCodeToString(ESlErrorCode(Z_Param_ErrorCode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetSceneCaptureProjectionMatrix)
	{
		P_GET_STRUCT_REF(FMatrix,Z_Param_Out_ProjectionMatrix);
		P_GET_ENUM(ESlEye,Z_Param_Eye);
		P_FINISH;
		P_NATIVE_BEGIN;
		USlFunctionLibrary::GetSceneCaptureProjectionMatrix(Z_Param_Out_ProjectionMatrix,ESlEye(Z_Param_Eye));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetOffCenterProjectionOffset)
	{
		P_GET_ENUM(ESlEye,Z_Param_Eye);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=USlFunctionLibrary::GetOffCenterProjectionOffset(ESlEye(Z_Param_Eye));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetOpticalCentersOffsets)
	{
		P_GET_STRUCT_REF(FIntPoint,Z_Param_Out_ImageResolution);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Distance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector4*)Z_Param__Result=USlFunctionLibrary::GetOpticalCentersOffsets(Z_Param_Out_ImageResolution,Z_Param_Distance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetRenderPlaneSizeWithGamma)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_STRUCT_REF(FIntPoint,Z_Param_Out_ImageResolution);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PerceptionDistance);
		P_GET_PROPERTY(FFloatProperty,Z_Param_ZedFocal);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PlaneDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=USlFunctionLibrary::GetRenderPlaneSizeWithGamma(Z_Param_WorldContextObject,Z_Param_Out_ImageResolution,Z_Param_PerceptionDistance,Z_Param_ZedFocal,Z_Param_PlaneDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetRenderPlaneSize)
	{
		P_GET_STRUCT_REF(FIntPoint,Z_Param_Out_ImageResolution);
		P_GET_PROPERTY(FFloatProperty,Z_Param_VerticalFOV);
		P_GET_PROPERTY(FFloatProperty,Z_Param_PlaneDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector2D*)Z_Param__Result=USlFunctionLibrary::GetRenderPlaneSize(Z_Param_Out_ImageResolution,Z_Param_VerticalFOV,Z_Param_PlaneDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execConvertCustomDepthToDistance)
	{
		P_GET_STRUCT_REF(FSlCameraParameters,Z_Param_Out_CameraParameters);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_Position);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Depth);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=USlFunctionLibrary::ConvertCustomDepthToDistance(Z_Param_Out_CameraParameters,Z_Param_Out_Position,Z_Param_Depth);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execConvertDepthToDistance)
	{
		P_GET_STRUCT_REF(FSlViewportHelper,Z_Param_Out_ViewportHelper);
		P_GET_STRUCT_REF(FVector2D,Z_Param_Out_ScreenPosition);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Depth);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=USlFunctionLibrary::ConvertDepthToDistance(Z_Param_Out_ViewportHelper,Z_Param_Out_ScreenPosition,Z_Param_Depth);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execIsInGrabThread)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USlFunctionLibrary::IsInGrabThread();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlFunctionLibrary::execGetCameraProxy)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USlCameraProxy**)Z_Param__Result=USlFunctionLibrary::GetCameraProxy();
		P_NATIVE_END;
	}
	void USlFunctionLibrary::StaticRegisterNativesUSlFunctionLibrary()
	{
		UClass* Class = USlFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Add_TimestampTimestamp", &USlFunctionLibrary::execAdd_TimestampTimestamp },
			{ "ClearMeshData", &USlFunctionLibrary::execClearMeshData },
			{ "Conv_TimestampToString", &USlFunctionLibrary::execConv_TimestampToString },
			{ "ConvertCustomDepthToDistance", &USlFunctionLibrary::execConvertCustomDepthToDistance },
			{ "ConvertDepthToDistance", &USlFunctionLibrary::execConvertDepthToDistance },
			{ "EqualEqual_TimestampTimestamp", &USlFunctionLibrary::execEqualEqual_TimestampTimestamp },
			{ "ErrorCodeToString", &USlFunctionLibrary::execErrorCodeToString },
			{ "GenerateTextureFromTxtFile", &USlFunctionLibrary::execGenerateTextureFromTxtFile },
			{ "GetCameraProxy", &USlFunctionLibrary::execGetCameraProxy },
			{ "GetHmdFocale", &USlFunctionLibrary::execGetHmdFocale },
			{ "GetOffCenterProjectionOffset", &USlFunctionLibrary::execGetOffCenterProjectionOffset },
			{ "GetOpticalCentersOffsets", &USlFunctionLibrary::execGetOpticalCentersOffsets },
			{ "GetRenderPlaneSize", &USlFunctionLibrary::execGetRenderPlaneSize },
			{ "GetRenderPlaneSizeWithGamma", &USlFunctionLibrary::execGetRenderPlaneSizeWithGamma },
			{ "GetSceneCaptureProjectionMatrix", &USlFunctionLibrary::execGetSceneCaptureProjectionMatrix },
			{ "Greater_TimestampTimestamp", &USlFunctionLibrary::execGreater_TimestampTimestamp },
			{ "GreaterEqual_TimestampTimestamp", &USlFunctionLibrary::execGreaterEqual_TimestampTimestamp },
			{ "IsInGrabThread", &USlFunctionLibrary::execIsInGrabThread },
			{ "Less_TimestampTimestamp", &USlFunctionLibrary::execLess_TimestampTimestamp },
			{ "LessEqual_TimestampTimestamp", &USlFunctionLibrary::execLessEqual_TimestampTimestamp },
			{ "NotEqual_TimestampTimestamp", &USlFunctionLibrary::execNotEqual_TimestampTimestamp },
			{ "Set3DBoxTransform", &USlFunctionLibrary::execSet3DBoxTransform },
			{ "SetMaxRangePreset", &USlFunctionLibrary::execSetMaxRangePreset },
			{ "SetMaxRangeValue", &USlFunctionLibrary::execSetMaxRangeValue },
			{ "SetResolutionPreset", &USlFunctionLibrary::execSetResolutionPreset },
			{ "SetResolutionValue", &USlFunctionLibrary::execSetResolutionValue },
			{ "Substract_TimestampTimestamp", &USlFunctionLibrary::execSubstract_TimestampTimestamp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventAdd_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			FSlTimestamp ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventAdd_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventAdd_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventAdd_TimestampTimestamp_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(nullptr, 0) }; // 2964665703
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** Addition (A + B) */" },
		{ "CompactNodeTitle", "+" },
		{ "DisplayName", "timestamp + timestamp" },
		{ "Keywords", "+ add plus" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "Addition (A + B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "Add_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::SlFunctionLibrary_eventAdd_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics
	{
		struct SlFunctionLibrary_eventClearMeshData_Parms
		{
			FSlMeshData MeshData;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::NewProp_MeshData = { "MeshData", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventClearMeshData_Parms, MeshData), Z_Construct_UScriptStruct_FSlMeshData, METADATA_PARAMS(nullptr, 0) }; // 1900805824
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::NewProp_MeshData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n \x09 * Clear mesh data\n\x09 */" },
		{ "DisplayName", "ClearMeshData" },
		{ "Keywords", "clear mesh data" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Clear mesh data" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "ClearMeshData", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::SlFunctionLibrary_eventClearMeshData_Parms), Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics
	{
		struct SlFunctionLibrary_eventConv_TimestampToString_Parms
		{
			FSlTimestamp InTimestamp;
			FString ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InTimestamp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InTimestamp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_InTimestamp_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_InTimestamp = { "InTimestamp", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConv_TimestampToString_Parms, InTimestamp), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_InTimestamp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_InTimestamp_MetaData)) }; // 2964665703
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConv_TimestampToString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_InTimestamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "Stereolabs" },
		{ "Comment", "/** Converts a FSlTimestamp into a string */" },
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "ToString (SlTimestamp)" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "Converts a FSlTimestamp into a string" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "Conv_TimestampToString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::SlFunctionLibrary_eventConv_TimestampToString_Parms), Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics
	{
		struct SlFunctionLibrary_eventConvertCustomDepthToDistance_Parms
		{
			FSlCameraParameters CameraParameters;
			FVector2D Position;
			float Depth;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CameraParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_CameraParameters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_CameraParameters = { "CameraParameters", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertCustomDepthToDistance_Parms, CameraParameters), Z_Construct_UScriptStruct_FSlCameraParameters, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_CameraParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_CameraParameters_MetaData)) }; // 2774105662
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Position_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertCustomDepthToDistance_Parms, Position), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Position_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Position_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertCustomDepthToDistance_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertCustomDepthToDistance_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_CameraParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Convert a depth to the distance from camera\n\x09 * @param CameraParameters  The camera parameters used to retrieve the depth\n\x09 * @param Position\x09\x09\x09The position of the depth in the depth mat\n\x09 * @param Depth\x09\x09\x09\x09The depth\n\x09 * @return\x09\x09\x09\x09\x09The distance from the camera\n\x09 */" },
		{ "DisplayName", "ConvertCustomDepthToDistance" },
		{ "Keywords", "get zed depth to distance" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Convert a depth to the distance from camera\n* @param CameraParameters  The camera parameters used to retrieve the depth\n* @param Position                      The position of the depth in the depth mat\n* @param Depth                         The depth\n* @return                                      The distance from the camera" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "ConvertCustomDepthToDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::SlFunctionLibrary_eventConvertCustomDepthToDistance_Parms), Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics
	{
		struct SlFunctionLibrary_eventConvertDepthToDistance_Parms
		{
			FSlViewportHelper ViewportHelper;
			FVector2D ScreenPosition;
			float Depth;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ViewportHelper_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ViewportHelper;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ScreenPosition;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ViewportHelper_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ViewportHelper = { "ViewportHelper", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertDepthToDistance_Parms, ViewportHelper), Z_Construct_UScriptStruct_FSlViewportHelper, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ViewportHelper_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ViewportHelper_MetaData)) }; // 3743845575
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertDepthToDistance_Parms, ScreenPosition), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ScreenPosition_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ScreenPosition_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertDepthToDistance_Parms, Depth), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventConvertDepthToDistance_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ViewportHelper,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Convert a depth retrieved using GetDepth to the distance from camera\n\x09 * @param ViewportHelper    The viewport helper of the current view\n\x09 * @param ScreenPosition    The screen position of the depth\n\x09 * @param Depth\x09\x09\x09\x09The depth\n\x09 * @return\x09\x09\x09\x09\x09The distance from the camera\n\x09 */" },
		{ "DisplayName", "ConvertDepthToDistance" },
		{ "Keywords", "get zed depth to distance" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Convert a depth retrieved using GetDepth to the distance from camera\n* @param ViewportHelper    The viewport helper of the current view\n* @param ScreenPosition    The screen position of the depth\n* @param Depth                         The depth\n* @return                                      The distance from the camera" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "ConvertDepthToDistance", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::SlFunctionLibrary_eventConvertDepthToDistance_Parms), Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventEqualEqual_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventEqualEqual_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventEqualEqual_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	void Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventEqualEqual_TimestampTimestamp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventEqualEqual_TimestampTimestamp_Parms), &Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** return true if A is equal to B (A == B) */" },
		{ "CompactNodeTitle", "==" },
		{ "DisplayName", "== (timestamp)" },
		{ "Keywords", "==" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "return true if A is equal to B (A == B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "EqualEqual_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::SlFunctionLibrary_eventEqualEqual_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics
	{
		struct SlFunctionLibrary_eventErrorCodeToString_Parms
		{
			ESlErrorCode ErrorCode;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ErrorCode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ErrorCode;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::NewProp_ErrorCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventErrorCodeToString_Parms, ErrorCode), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventErrorCodeToString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::NewProp_ErrorCode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Convert sl::ERROR_CODE to string\n\x09 * @param ErrorCode The sl:ERROR_CODE to convert\n\x09 * @return\x09\x09\x09The converted string\n\x09 */" },
		{ "DisplayName", "ErrorCodeToString" },
		{ "Keywords", "zed error code to string" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Convert sl::ERROR_CODE to string\n* @param ErrorCode The sl:ERROR_CODE to convert\n* @return                      The converted string" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "ErrorCodeToString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::SlFunctionLibrary_eventErrorCodeToString_Parms), Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics
	{
		struct SlFunctionLibrary_eventGenerateTextureFromTxtFile_Parms
		{
			FString filepath;
			UTexture2D* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_filepath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_filepath;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_filepath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_filepath = { "filepath", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGenerateTextureFromTxtFile_Parms, filepath), METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_filepath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_filepath_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGenerateTextureFromTxtFile_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_filepath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** Generate texture from txt file */" },
		{ "DisplayName", "GenerateTextureFromTxtFile" },
		{ "Keywords", "texture" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "Generate texture from txt file" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GenerateTextureFromTxtFile", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::SlFunctionLibrary_eventGenerateTextureFromTxtFile_Parms), Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics
	{
		struct SlFunctionLibrary_eventGetCameraProxy_Parms
		{
			USlCameraProxy* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetCameraProxy_Parms, ReturnValue), Z_Construct_UClass_USlCameraProxy_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Retrieve the camera proxy instance. Can be null.\n\x09 * @return The camera proxy instance\n\x09 */" },
		{ "DisplayName", "GetCameraProxy" },
		{ "Keywords", "get zed camera proxy" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Retrieve the camera proxy instance. Can be null.\n* @return The camera proxy instance" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetCameraProxy", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::SlFunctionLibrary_eventGetCameraProxy_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics
	{
		struct SlFunctionLibrary_eventGetHmdFocale_Parms
		{
			FVector2D ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetHmdFocale_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** Return HMD HFocal et VFocal lenght*/" },
		{ "DisplayName", "HmdFocal" },
		{ "Keywords", "Focal" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "Return HMD HFocal et VFocal lenght" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetHmdFocale", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::SlFunctionLibrary_eventGetHmdFocale_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics
	{
		struct SlFunctionLibrary_eventGetOffCenterProjectionOffset_Parms
		{
			ESlEye Eye;
			FVector2D ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Eye_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Eye;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::NewProp_Eye_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::NewProp_Eye = { "Eye", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetOffCenterProjectionOffset_Parms, Eye), Z_Construct_UEnum_Stereolabs_ESlEye, METADATA_PARAMS(nullptr, 0) }; // 1045116032
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetOffCenterProjectionOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::NewProp_Eye_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::NewProp_Eye,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Get the optical center offset for the selected eye\n\x09 * @param Eye The eye\n\x09 * @return\x09  The offsets\n\x09 */" },
		{ "CPP_Default_Eye", "E_Left" },
		{ "DisplayName", "GetOffCenterProjectionOffset" },
		{ "Keywords", "get zed off center projection offset" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Get the optical center offset for the selected eye\n* @param Eye The eye\n* @return        The offsets" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetOffCenterProjectionOffset", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::SlFunctionLibrary_eventGetOffCenterProjectionOffset_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics
	{
		struct SlFunctionLibrary_eventGetOpticalCentersOffsets_Parms
		{
			FIntPoint ImageResolution;
			float Distance;
			FVector4 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageResolution_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImageResolution;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ImageResolution_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ImageResolution = { "ImageResolution", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetOpticalCentersOffsets_Parms, ImageResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ImageResolution_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ImageResolution_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetOpticalCentersOffsets_Parms, Distance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetOpticalCentersOffsets_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector4, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ImageResolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Compute optical center offsets for left/right images\n\x09 * @paramI mageResolution  Zed image resolution\n\x09 * @param Distance         Distance from camera\n\x09 * @return the x/y offset for each eye\n\x09 */" },
		{ "DisplayName", "GetOpticalCentersOffsets" },
		{ "Keywords", "get zed optical centers offsets" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Compute optical center offsets for left/right images\n* @paramI mageResolution  Zed image resolution\n* @param Distance         Distance from camera\n* @return the x/y offset for each eye" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetOpticalCentersOffsets", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::SlFunctionLibrary_eventGetOpticalCentersOffsets_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics
	{
		struct SlFunctionLibrary_eventGetRenderPlaneSize_Parms
		{
			FIntPoint ImageResolution;
			float VerticalFOV;
			float PlaneDistance;
			FVector2D ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageResolution_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImageResolution;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalFOV;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaneDistance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ImageResolution_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ImageResolution = { "ImageResolution", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSize_Parms, ImageResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ImageResolution_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ImageResolution_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_VerticalFOV = { "VerticalFOV", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSize_Parms, VerticalFOV), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_PlaneDistance = { "PlaneDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSize_Parms, PlaneDistance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSize_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ImageResolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_VerticalFOV,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_PlaneDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Compute rendering plane size\n\x09 * @param VerticalFOV\x09\x09Zed vertical FOV\n\x09 * @param PlaneDistance\x09    Plane rendering distance from camera\n\x09 * @param ImageResolution   Zed image resolution\n\x09 * @return size width/height of the plane\n\x09 */" },
		{ "DisplayName", "GetRenderPlaneSize" },
		{ "Keywords", "get zed render plane size" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Compute rendering plane size\n* @param VerticalFOV           Zed vertical FOV\n* @param PlaneDistance     Plane rendering distance from camera\n* @param ImageResolution   Zed image resolution\n* @return size width/height of the plane" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetRenderPlaneSize", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::SlFunctionLibrary_eventGetRenderPlaneSize_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics
	{
		struct SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms
		{
			UObject* WorldContextObject;
			FIntPoint ImageResolution;
			float PerceptionDistance;
			float ZedFocal;
			float PlaneDistance;
			FVector2D ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImageResolution_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImageResolution;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PerceptionDistance;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ZedFocal;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_PlaneDistance;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ImageResolution_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ImageResolution = { "ImageResolution", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms, ImageResolution), Z_Construct_UScriptStruct_FIntPoint, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ImageResolution_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ImageResolution_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_PerceptionDistance = { "PerceptionDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms, PerceptionDistance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ZedFocal = { "ZedFocal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms, ZedFocal), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_PlaneDistance = { "PlaneDistance", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms, PlaneDistance), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ImageResolution,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_PerceptionDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ZedFocal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_PlaneDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Compute rendering plane size using gamma\n\x09 * @param PerceptionDistance The distance at which objects will have their correct size\n\x09 * @param ImageResolution    Zed image resolution\n\x09 * @param PerceptionDistance Distance at which object match their real size\n\x09 * @param ZedFocal\x09         Zed focal\n\x09 * @param PlaneDistance\x09     Plane rendering distance from camera\n\x09 * @return size width/height of the plane\n\x09 */" },
		{ "DisplayName", "GetRenderPlaneSizeWithGamma" },
		{ "Keywords", "get zed render plane size with gamma" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Compute rendering plane size using gamma\n* @param PerceptionDistance The distance at which objects will have their correct size\n* @param ImageResolution    Zed image resolution\n* @param PerceptionDistance Distance at which object match their real size\n* @param ZedFocal               Zed focal\n* @param PlaneDistance      Plane rendering distance from camera\n* @return size width/height of the plane" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetRenderPlaneSizeWithGamma", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::SlFunctionLibrary_eventGetRenderPlaneSizeWithGamma_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics
	{
		struct FMatrix
		{
			FPlane XPlane;
			FPlane YPlane;
			FPlane ZPlane;
			FPlane WPlane;
		};

		struct SlFunctionLibrary_eventGetSceneCaptureProjectionMatrix_Parms
		{
			FMatrix ProjectionMatrix;
			ESlEye Eye;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectionMatrix;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Eye_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Eye;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::NewProp_ProjectionMatrix = { "ProjectionMatrix", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetSceneCaptureProjectionMatrix_Parms, ProjectionMatrix), Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::NewProp_Eye_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::NewProp_Eye = { "Eye", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGetSceneCaptureProjectionMatrix_Parms, Eye), Z_Construct_UEnum_Stereolabs_ESlEye, METADATA_PARAMS(nullptr, 0) }; // 1045116032
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::NewProp_ProjectionMatrix,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::NewProp_Eye_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::NewProp_Eye,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Get the projection matrix for a scene capture\n\x09 * @param ProjectionMatrix The projection matrix\n\x09 * @param Eye\x09\x09\x09   The eye\n\x09 */" },
		{ "CPP_Default_Eye", "E_Left" },
		{ "DisplayName", "GetSceneCaptureProjectionMatrix" },
		{ "Keywords", "get zed projection matrix" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Get the projection matrix for a scene capture\n* @param ProjectionMatrix The projection matrix\n* @param Eye                      The eye" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GetSceneCaptureProjectionMatrix", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::SlFunctionLibrary_eventGetSceneCaptureProjectionMatrix_Parms), Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventGreater_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGreater_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGreater_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	void Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventGreater_TimestampTimestamp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventGreater_TimestampTimestamp_Parms), &Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** return true if A is greater than B (A > B) */" },
		{ "CompactNodeTitle", ">" },
		{ "DisplayName", "> (timestamp)" },
		{ "Keywords", ">" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "return true if A is greater than B (A > B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "Greater_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::SlFunctionLibrary_eventGreater_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventGreaterEqual_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGreaterEqual_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventGreaterEqual_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	void Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventGreaterEqual_TimestampTimestamp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventGreaterEqual_TimestampTimestamp_Parms), &Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** return true if A is greater than or equal to B (A >= B) */" },
		{ "CompactNodeTitle", ">=" },
		{ "DisplayName", ">= (timestamp)" },
		{ "Keywords", ">=" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "return true if A is greater than or equal to B (A >= B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "GreaterEqual_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::SlFunctionLibrary_eventGreaterEqual_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics
	{
		struct SlFunctionLibrary_eventIsInGrabThread_Parms
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
	void Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventIsInGrabThread_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventIsInGrabThread_Parms), &Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * @return True if in grab thread\n\x09 */" },
		{ "DisplayName", "IsInGrabThread" },
		{ "Keywords", "get zed in grab thread" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* @return True if in grab thread" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "IsInGrabThread", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::SlFunctionLibrary_eventIsInGrabThread_Parms), Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventLess_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventLess_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventLess_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	void Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventLess_TimestampTimestamp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventLess_TimestampTimestamp_Parms), &Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** return true if A is less than B (A < B) */" },
		{ "CompactNodeTitle", "<" },
		{ "DisplayName", "< (timestamp)" },
		{ "Keywords", "<" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "return true if A is less than B (A < B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "Less_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::SlFunctionLibrary_eventLess_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventLessEqual_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventLessEqual_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventLessEqual_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	void Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventLessEqual_TimestampTimestamp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventLessEqual_TimestampTimestamp_Parms), &Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** return true if A is less than or equal to B (A <= B) */" },
		{ "CompactNodeTitle", "<=" },
		{ "DisplayName", "<= (timestamp)" },
		{ "Keywords", "<=" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "return true if A is less than or equal to B (A <= B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "LessEqual_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::SlFunctionLibrary_eventLessEqual_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventNotEqual_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventNotEqual_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventNotEqual_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	void Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlFunctionLibrary_eventNotEqual_TimestampTimestamp_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlFunctionLibrary_eventNotEqual_TimestampTimestamp_Parms), &Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** return true if A is not equal to B (A != B) */" },
		{ "CompactNodeTitle", "!=" },
		{ "DisplayName", "!= (timestamp)" },
		{ "Keywords", "!=" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "return true if A is not equal to B (A != B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "NotEqual_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::SlFunctionLibrary_eventNotEqual_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics
	{
		struct SlFunctionLibrary_eventSet3DBoxTransform_Parms
		{
			AActor* BBox;
			FSlObjectData ObjectData;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ObjectData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_BBox = { "BBox", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSet3DBoxTransform_Parms, BBox), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_ObjectData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_ObjectData = { "ObjectData", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSet3DBoxTransform_Parms, ObjectData), Z_Construct_UScriptStruct_FSlObjectData, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_ObjectData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_ObjectData_MetaData)) }; // 394447587
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_BBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::NewProp_ObjectData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/* Compute 3d box position, orientation and scale based on Objectdata informations*/" },
		{ "DisplayName", "Set3DBoxTransform" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "Compute 3d box position, orientation and scale based on Objectdata informations" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "Set3DBoxTransform", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::SlFunctionLibrary_eventSet3DBoxTransform_Parms), Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics
	{
		struct SlFunctionLibrary_eventSetMaxRangePreset_Parms
		{
			FSlSpatialMappingParameters SpatialMappingParameters;
			ESlSpatialMappingRange NewMaxRange;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpatialMappingParameters;
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewMaxRange_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewMaxRange;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::NewProp_SpatialMappingParameters = { "SpatialMappingParameters", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetMaxRangePreset_Parms, SpatialMappingParameters), Z_Construct_UScriptStruct_FSlSpatialMappingParameters, METADATA_PARAMS(nullptr, 0) }; // 2971678113
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::NewProp_NewMaxRange_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::NewProp_NewMaxRange = { "NewMaxRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetMaxRangePreset_Parms, NewMaxRange), Z_Construct_UEnum_Stereolabs_ESlSpatialMappingRange, METADATA_PARAMS(nullptr, 0) }; // 3482371252
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::NewProp_SpatialMappingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::NewProp_NewMaxRange_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::NewProp_NewMaxRange,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Set the max range of a FSlSpatialMappingParameters struct\n\x09 * @param NewMaxRange The new max range\n\x09 */" },
		{ "DisplayName", "SetMaxRange" },
		{ "Keywords", "set max range" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Set the max range of a FSlSpatialMappingParameters struct\n* @param NewMaxRange The new max range" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "SetMaxRangePreset", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::SlFunctionLibrary_eventSetMaxRangePreset_Parms), Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics
	{
		struct SlFunctionLibrary_eventSetMaxRangeValue_Parms
		{
			FSlSpatialMappingParameters SpatialMappingParameters;
			float NewMaxRange;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpatialMappingParameters;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NewMaxRange;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::NewProp_SpatialMappingParameters = { "SpatialMappingParameters", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetMaxRangeValue_Parms, SpatialMappingParameters), Z_Construct_UScriptStruct_FSlSpatialMappingParameters, METADATA_PARAMS(nullptr, 0) }; // 2971678113
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::NewProp_NewMaxRange = { "NewMaxRange", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetMaxRangeValue_Parms, NewMaxRange), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::NewProp_SpatialMappingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::NewProp_NewMaxRange,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Set the max range of a FSlSpatialMappingParameters struct\n\x09 * @param NewMaxRange The new max range\n\x09 */" },
		{ "DisplayName", "SetMaxRange" },
		{ "Keywords", "set max range" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Set the max range of a FSlSpatialMappingParameters struct\n* @param NewMaxRange The new max range" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "SetMaxRangeValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::SlFunctionLibrary_eventSetMaxRangeValue_Parms), Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics
	{
		struct SlFunctionLibrary_eventSetResolutionPreset_Parms
		{
			FSlSpatialMappingParameters SpatialMappingParameters;
			ESlSpatialMappingResolution NewResolution;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpatialMappingParameters;
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewResolution_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewResolution;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::NewProp_SpatialMappingParameters = { "SpatialMappingParameters", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetResolutionPreset_Parms, SpatialMappingParameters), Z_Construct_UScriptStruct_FSlSpatialMappingParameters, METADATA_PARAMS(nullptr, 0) }; // 2971678113
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::NewProp_NewResolution_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::NewProp_NewResolution = { "NewResolution", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetResolutionPreset_Parms, NewResolution), Z_Construct_UEnum_Stereolabs_ESlSpatialMappingResolution, METADATA_PARAMS(nullptr, 0) }; // 4149091728
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::NewProp_SpatialMappingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::NewProp_NewResolution_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::NewProp_NewResolution,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Set the resolution of a FZEDSpatialMappingParameters struct\n\x09 * @param NewResolution\x09The new resolution\n\x09 */" },
		{ "DisplayName", "SetResolution" },
		{ "Keywords", "set resolution" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Set the resolution of a FZEDSpatialMappingParameters struct\n* @param NewResolution The new resolution" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "SetResolutionPreset", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::SlFunctionLibrary_eventSetResolutionPreset_Parms), Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics
	{
		struct SlFunctionLibrary_eventSetResolutionValue_Parms
		{
			FSlSpatialMappingParameters SpatialMappingParameters;
			float NewResolution;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_SpatialMappingParameters;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NewResolution;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::NewProp_SpatialMappingParameters = { "SpatialMappingParameters", nullptr, (EPropertyFlags)0x0010000008000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetResolutionValue_Parms, SpatialMappingParameters), Z_Construct_UScriptStruct_FSlSpatialMappingParameters, METADATA_PARAMS(nullptr, 0) }; // 2971678113
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::NewProp_NewResolution = { "NewResolution", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSetResolutionValue_Parms, NewResolution), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::NewProp_SpatialMappingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::NewProp_NewResolution,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Set the resolution of a FSlSpatialMappingParameters struct\n\x09 * @param NewResolution\x09The new resolution\n\x09 */" },
		{ "DisplayName", "SetResolution" },
		{ "Keywords", "set resolution" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "* Set the resolution of a FSlSpatialMappingParameters struct\n* @param NewResolution The new resolution" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "SetResolutionValue", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::SlFunctionLibrary_eventSetResolutionValue_Parms), Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics
	{
		struct SlFunctionLibrary_eventSubstract_TimestampTimestamp_Parms
		{
			FSlTimestamp A;
			FSlTimestamp B;
			FSlTimestamp ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_B;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSubstract_TimestampTimestamp_Parms, A), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_A_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSubstract_TimestampTimestamp_Parms, B), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_B_MetaData)) }; // 2964665703
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlFunctionLibrary_eventSubstract_TimestampTimestamp_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(nullptr, 0) }; // 2964665703
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_A,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_B,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/** Subtraction (A - B) */" },
		{ "CompactNodeTitle", "-" },
		{ "DisplayName", "timestamp - timestamp" },
		{ "Keywords", "- substract minus" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
		{ "ToolTip", "Subtraction (A - B)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlFunctionLibrary, nullptr, "Substract_TimestampTimestamp", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::SlFunctionLibrary_eventSubstract_TimestampTimestamp_Parms), Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlFunctionLibrary);
	UClass* Z_Construct_UClass_USlFunctionLibrary_NoRegister()
	{
		return USlFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USlFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlFunctionLibrary_Add_TimestampTimestamp, "Add_TimestampTimestamp" }, // 3029867809
		{ &Z_Construct_UFunction_USlFunctionLibrary_ClearMeshData, "ClearMeshData" }, // 3522127845
		{ &Z_Construct_UFunction_USlFunctionLibrary_Conv_TimestampToString, "Conv_TimestampToString" }, // 3991420603
		{ &Z_Construct_UFunction_USlFunctionLibrary_ConvertCustomDepthToDistance, "ConvertCustomDepthToDistance" }, // 3082745317
		{ &Z_Construct_UFunction_USlFunctionLibrary_ConvertDepthToDistance, "ConvertDepthToDistance" }, // 2957220354
		{ &Z_Construct_UFunction_USlFunctionLibrary_EqualEqual_TimestampTimestamp, "EqualEqual_TimestampTimestamp" }, // 4253244768
		{ &Z_Construct_UFunction_USlFunctionLibrary_ErrorCodeToString, "ErrorCodeToString" }, // 3616549928
		{ &Z_Construct_UFunction_USlFunctionLibrary_GenerateTextureFromTxtFile, "GenerateTextureFromTxtFile" }, // 216425509
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetCameraProxy, "GetCameraProxy" }, // 3501859536
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetHmdFocale, "GetHmdFocale" }, // 591845745
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetOffCenterProjectionOffset, "GetOffCenterProjectionOffset" }, // 1061485858
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetOpticalCentersOffsets, "GetOpticalCentersOffsets" }, // 784480844
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSize, "GetRenderPlaneSize" }, // 3431665763
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetRenderPlaneSizeWithGamma, "GetRenderPlaneSizeWithGamma" }, // 1602981530
		{ &Z_Construct_UFunction_USlFunctionLibrary_GetSceneCaptureProjectionMatrix, "GetSceneCaptureProjectionMatrix" }, // 528913250
		{ &Z_Construct_UFunction_USlFunctionLibrary_Greater_TimestampTimestamp, "Greater_TimestampTimestamp" }, // 2922408312
		{ &Z_Construct_UFunction_USlFunctionLibrary_GreaterEqual_TimestampTimestamp, "GreaterEqual_TimestampTimestamp" }, // 2430891240
		{ &Z_Construct_UFunction_USlFunctionLibrary_IsInGrabThread, "IsInGrabThread" }, // 1584670745
		{ &Z_Construct_UFunction_USlFunctionLibrary_Less_TimestampTimestamp, "Less_TimestampTimestamp" }, // 3427062120
		{ &Z_Construct_UFunction_USlFunctionLibrary_LessEqual_TimestampTimestamp, "LessEqual_TimestampTimestamp" }, // 2063463000
		{ &Z_Construct_UFunction_USlFunctionLibrary_NotEqual_TimestampTimestamp, "NotEqual_TimestampTimestamp" }, // 3705797922
		{ &Z_Construct_UFunction_USlFunctionLibrary_Set3DBoxTransform, "Set3DBoxTransform" }, // 2884119811
		{ &Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangePreset, "SetMaxRangePreset" }, // 1681503932
		{ &Z_Construct_UFunction_USlFunctionLibrary_SetMaxRangeValue, "SetMaxRangeValue" }, // 1720099188
		{ &Z_Construct_UFunction_USlFunctionLibrary_SetResolutionPreset, "SetResolutionPreset" }, // 423243750
		{ &Z_Construct_UFunction_USlFunctionLibrary_SetResolutionValue, "SetResolutionValue" }, // 3363474841
		{ &Z_Construct_UFunction_USlFunctionLibrary_Substract_TimestampTimestamp, "Substract_TimestampTimestamp" }, // 2848164963
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Utilities/StereolabsFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/Utilities/StereolabsFunctionLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlFunctionLibrary_Statics::ClassParams = {
		&USlFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USlFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_USlFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlFunctionLibrary.OuterSingleton, Z_Construct_UClass_USlFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlFunctionLibrary.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlFunctionLibrary>()
	{
		return USlFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlFunctionLibrary);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USlFunctionLibrary, USlFunctionLibrary::StaticClass, TEXT("USlFunctionLibrary"), &Z_Registration_Info_UClass_USlFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlFunctionLibrary), 598763480U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_3377870085(TEXT("/Script/Stereolabs"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Utilities_StereolabsFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
