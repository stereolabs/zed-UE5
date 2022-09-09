// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZEDBaseTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDBaseTypes() {}
// Cross Module References
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDTrackingData();
	UPackage* Z_Construct_UPackage__Script_ZED();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlTrackingState();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlTimestamp();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDExternalViewParameters();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZEDTrackingData;
class UScriptStruct* FZEDTrackingData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZEDTrackingData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZEDTrackingData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZEDTrackingData, Z_Construct_UPackage__Script_ZED(), TEXT("ZEDTrackingData"));
	}
	return Z_Registration_Info_UScriptStruct_ZEDTrackingData.OuterSingleton;
}
template<> ZED_API UScriptStruct* StaticStruct<FZEDTrackingData>()
{
	return FZEDTrackingData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FZEDTrackingData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FBytePropertyParams NewProp_TrackingState_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackingState_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_TrackingState;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Timestamp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OffsetZedWorldTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_OffsetZedWorldTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedWorldTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ZedWorldTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedPathTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ZedPathTransform;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IMURotator_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_IMURotator;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "ZED|Struct" },
		{ "Comment", "/*\n * Tracking data of the camera\n */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "* Tracking data of the camera" },
	};
#endif
	void* Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZEDTrackingData>();
	}
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState_MetaData[] = {
		{ "Category", "ZEDTrackingData" },
		{ "Comment", "/** Tracking state */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Tracking state" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState = { "TrackingState", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDTrackingData, TrackingState), Z_Construct_UEnum_Stereolabs_ESlTrackingState, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState_MetaData)) }; // 3673151506
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_Timestamp_MetaData[] = {
		{ "Category", "ZEDTrackingData" },
		{ "Comment", "/** Timestamp */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Timestamp" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDTrackingData, Timestamp), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_Timestamp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_Timestamp_MetaData)) }; // 2964665703
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_OffsetZedWorldTransform_MetaData[] = {
		{ "Category", "ZEDTrackingData" },
		{ "Comment", "/**\x09Zed world space transform relative to the head with anti drift if using an HMD */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Zed world space transform relative to the head with anti drift if using an HMD" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_OffsetZedWorldTransform = { "OffsetZedWorldTransform", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDTrackingData, OffsetZedWorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_OffsetZedWorldTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_OffsetZedWorldTransform_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedWorldTransform_MetaData[] = {
		{ "Category", "ZEDTrackingData" },
		{ "Comment", "/** Zed world space transform with anti drift if using an HMD */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Zed world space transform with anti drift if using an HMD" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedWorldTransform = { "ZedWorldTransform", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDTrackingData, ZedWorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedWorldTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedWorldTransform_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedPathTransform_MetaData[] = {
		{ "Category", "ZEDTrackingData" },
		{ "Comment", "/** Raw path transform from tracking origin */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Raw path transform from tracking origin" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedPathTransform = { "ZedPathTransform", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDTrackingData, ZedPathTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedPathTransform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedPathTransform_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_IMURotator_MetaData[] = {
		{ "Category", "ZEDTrackingData" },
		{ "Comment", "/** IMU rotation */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "IMU rotation" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_IMURotator = { "IMURotator", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDTrackingData, IMURotator), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_IMURotator_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_IMURotator_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZEDTrackingData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_TrackingState,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_Timestamp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_OffsetZedWorldTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedWorldTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_ZedPathTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewProp_IMURotator,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZEDTrackingData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
		nullptr,
		&NewStructOps,
		"ZEDTrackingData",
		sizeof(FZEDTrackingData),
		alignof(FZEDTrackingData),
		Z_Construct_UScriptStruct_FZEDTrackingData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDTrackingData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FZEDTrackingData()
	{
		if (!Z_Registration_Info_UScriptStruct_ZEDTrackingData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZEDTrackingData.InnerSingleton, Z_Construct_UScriptStruct_FZEDTrackingData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ZEDTrackingData.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZEDHitResult;
class UScriptStruct* FZEDHitResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZEDHitResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZEDHitResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZEDHitResult, Z_Construct_UPackage__Script_ZED(), TEXT("ZEDHitResult"));
	}
	return Z_Registration_Info_UScriptStruct_ZEDHitResult.OuterSingleton;
}
template<> ZED_API UScriptStruct* StaticStruct<FZEDHitResult>()
{
	return FZEDHitResult::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FZEDHitResult_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImpactPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImpactPoint;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Normal_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Depth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Depth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Distance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Distance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsVisible_MetaData[];
#endif
		static void NewProp_bIsVisible_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsBehind_MetaData[];
#endif
		static void NewProp_bIsBehind_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBehind;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bNormalValid_MetaData[];
#endif
		static void NewProp_bNormalValid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNormalValid;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "ZED|Struct" },
		{ "Comment", "/*\n * Result of a hit test\n */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "* Result of a hit test" },
	};
#endif
	void* Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZEDHitResult>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Location_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** Location of the hit in world space */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Location of the hit in world space" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDHitResult, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_ImpactPoint_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** Location of the actual contact point. Equal the tested world location. */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Location of the actual contact point. Equal the tested world location." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_ImpactPoint = { "ImpactPoint", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDHitResult, ImpactPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_ImpactPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_ImpactPoint_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Normal_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** Normal of the hit in world space */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "Normal of the hit in world space" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDHitResult, Normal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Normal_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Normal_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Depth_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** The depth of the hit */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "The depth of the hit" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Depth = { "Depth", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDHitResult, Depth), METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Depth_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Depth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Distance_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** The distance from the hit location to the player */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "The distance from the hit location to the player" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Distance = { "Distance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FZEDHitResult, Distance), METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Distance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Distance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** True if the location is visible by the player */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "True if the location is visible by the player" },
	};
#endif
	void Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible_SetBit(void* Obj)
	{
		((FZEDHitResult*)Obj)->bIsVisible = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FZEDHitResult), &Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/* True if the ImpactPoint is behind real.\n\x09 * Always false if hit test \"bHitIfBehind\" set to false.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "True if the ImpactPoint is behind real.\n       * Always false if hit test \"bHitIfBehind\" set to false." },
	};
#endif
	void Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind_SetBit(void* Obj)
	{
		((FZEDHitResult*)Obj)->bIsBehind = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind = { "bIsBehind", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FZEDHitResult), &Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid_MetaData[] = {
		{ "Category", "ZEDHitResult" },
		{ "Comment", "/** True if the normal is valid */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "True if the normal is valid" },
	};
#endif
	void Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid_SetBit(void* Obj)
	{
		((FZEDHitResult*)Obj)->bNormalValid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid = { "bNormalValid", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FZEDHitResult), &Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FZEDHitResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_ImpactPoint,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Normal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Depth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_Distance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsVisible,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bIsBehind,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewProp_bNormalValid,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZEDHitResult_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
		nullptr,
		&NewStructOps,
		"ZEDHitResult",
		sizeof(FZEDHitResult),
		alignof(FZEDHitResult),
		Z_Construct_UScriptStruct_FZEDHitResult_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDHitResult_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDHitResult_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FZEDHitResult()
	{
		if (!Z_Registration_Info_UScriptStruct_ZEDHitResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZEDHitResult.InnerSingleton, Z_Construct_UScriptStruct_FZEDHitResult_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ZEDHitResult.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters;
class UScriptStruct* FZEDExternalViewParameters::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FZEDExternalViewParameters, Z_Construct_UPackage__Script_ZED(), TEXT("ZEDExternalViewParameters"));
	}
	return Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters.OuterSingleton;
}
template<> ZED_API UScriptStruct* StaticStruct<FZEDExternalViewParameters>()
{
	return FZEDExternalViewParameters::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "ZED|Struct" },
		{ "Comment", "/*\n * Camera calibration for external view\n */" },
		{ "ModuleRelativePath", "Public/Core/ZEDBaseTypes.h" },
		{ "ToolTip", "* Camera calibration for external view" },
	};
#endif
	void* Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FZEDExternalViewParameters>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
		nullptr,
		&NewStructOps,
		"ZEDExternalViewParameters",
		sizeof(FZEDExternalViewParameters),
		alignof(FZEDExternalViewParameters),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FZEDExternalViewParameters()
	{
		if (!Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters.InnerSingleton, Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDBaseTypes_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDBaseTypes_h_Statics::ScriptStructInfo[] = {
		{ FZEDTrackingData::StaticStruct, Z_Construct_UScriptStruct_FZEDTrackingData_Statics::NewStructOps, TEXT("ZEDTrackingData"), &Z_Registration_Info_UScriptStruct_ZEDTrackingData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZEDTrackingData), 2053750691U) },
		{ FZEDHitResult::StaticStruct, Z_Construct_UScriptStruct_FZEDHitResult_Statics::NewStructOps, TEXT("ZEDHitResult"), &Z_Registration_Info_UScriptStruct_ZEDHitResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZEDHitResult), 1875529980U) },
		{ FZEDExternalViewParameters::StaticStruct, Z_Construct_UScriptStruct_FZEDExternalViewParameters_Statics::NewStructOps, TEXT("ZEDExternalViewParameters"), &Z_Registration_Info_UScriptStruct_ZEDExternalViewParameters, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FZEDExternalViewParameters), 244445604U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDBaseTypes_h_487313043(TEXT("/Script/ZED"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDBaseTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDBaseTypes_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
