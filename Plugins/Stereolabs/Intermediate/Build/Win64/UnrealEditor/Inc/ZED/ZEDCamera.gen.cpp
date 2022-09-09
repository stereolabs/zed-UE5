// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZEDCamera.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDCamera() {}
// Cross Module References
	ZED_API UFunction* Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ZED();
	ZED_API UScriptStruct* Z_Construct_UScriptStruct_FZEDTrackingData();
	ZED_API UFunction* Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature();
	ZED_API UClass* Z_Construct_UClass_AZEDCamera_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDCamera();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlErrorCode();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlTimestamp();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlVideoSettings();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlRuntimeParameters();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlThreadingMode();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlAntiDriftParameters();
	STEREOLABS_API UClass* Z_Construct_UClass_USlTexture_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlRenderingParameters();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlRenderingMode();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlPositionalTrackingParameters();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlRecordingParameters();
	STEREOLABS_API UClass* Z_Construct_UClass_USlTextureBatch_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics
	{
		struct _Script_ZED_eventZEDTrackingDataUpdatedDelegate_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::NewProp_NewTrackingData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::NewProp_NewTrackingData = { "NewTrackingData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_ZED_eventZEDTrackingDataUpdatedDelegate_Parms, NewTrackingData), Z_Construct_UScriptStruct_FZEDTrackingData, METADATA_PARAMS(Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::NewProp_NewTrackingData_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::NewProp_NewTrackingData_MetaData)) }; // 2053750691
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::NewProp_NewTrackingData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n * Notify that the tracking data have been updated\n */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Notify that the tracking data have been updated" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ZED, nullptr, "ZEDTrackingDataUpdatedDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::_Script_ZED_eventZEDTrackingDataUpdatedDelegate_Parms), Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n * Notify that the actor is initialized\n */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Notify that the actor is initialized" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ZED, nullptr, "ZEDCameraActorInitializedDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(AZEDCamera::execCameraClosed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CameraClosed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execGrabCallback)
	{
		P_GET_ENUM(ESlErrorCode,Z_Param_ErrorCode);
		P_GET_STRUCT_REF(FSlTimestamp,Z_Param_Out_Timestamp);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GrabCallback(ESlErrorCode(Z_Param_ErrorCode),Z_Param_Out_Timestamp);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execSetSVOPlaybackLooping)
	{
		P_GET_UBOOL(Z_Param_bLooping);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSVOPlaybackLooping(Z_Param_bLooping);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execDisableSVORecording)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisableSVORecording();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execEnableSVORecording)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ESlErrorCode*)Z_Param__Result=P_THIS->EnableSVORecording();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execSetCameraSettings)
	{
		P_GET_STRUCT_REF(FSlVideoSettings,Z_Param_Out_NewValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetCameraSettings(Z_Param_Out_NewValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execSetRuntimeParameters)
	{
		P_GET_STRUCT_REF(FSlRuntimeParameters,Z_Param_Out_NewValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetRuntimeParameters(Z_Param_Out_NewValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execSetDepthClampThreshold)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_DepthDistance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetDepthClampThreshold(Z_Param_DepthDistance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execSetThreadingMode)
	{
		P_GET_ENUM(ESlThreadingMode,Z_Param_NewValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetThreadingMode(ESlThreadingMode(Z_Param_NewValue));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execSaveSpatialMemoryArea)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SaveSpatialMemoryArea();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execResetTrackingOrigin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetTrackingOrigin();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execDisableTracking)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DisableTracking();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDCamera::execEnableTracking)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableTracking();
		P_NATIVE_END;
	}
	void AZEDCamera::StaticRegisterNativesAZEDCamera()
	{
		UClass* Class = AZEDCamera::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CameraClosed", &AZEDCamera::execCameraClosed },
			{ "DisableSVORecording", &AZEDCamera::execDisableSVORecording },
			{ "DisableTracking", &AZEDCamera::execDisableTracking },
			{ "EnableSVORecording", &AZEDCamera::execEnableSVORecording },
			{ "EnableTracking", &AZEDCamera::execEnableTracking },
			{ "GrabCallback", &AZEDCamera::execGrabCallback },
			{ "ResetTrackingOrigin", &AZEDCamera::execResetTrackingOrigin },
			{ "SaveSpatialMemoryArea", &AZEDCamera::execSaveSpatialMemoryArea },
			{ "SetCameraSettings", &AZEDCamera::execSetCameraSettings },
			{ "SetDepthClampThreshold", &AZEDCamera::execSetDepthClampThreshold },
			{ "SetRuntimeParameters", &AZEDCamera::execSetRuntimeParameters },
			{ "SetSVOPlaybackLooping", &AZEDCamera::execSetSVOPlaybackLooping },
			{ "SetThreadingMode", &AZEDCamera::execSetThreadingMode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZEDCamera_CameraClosed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_CameraClosed_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Zed closed\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Zed closed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_CameraClosed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "CameraClosed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_CameraClosed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_CameraClosed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_CameraClosed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_CameraClosed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_DisableSVORecording_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_DisableSVORecording_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|SVO" },
		{ "Comment", "/*\n\x09 * Disable SVO recording\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Disable SVO recording" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_DisableSVORecording_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "DisableSVORecording", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_DisableSVORecording_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_DisableSVORecording_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_DisableSVORecording()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_DisableSVORecording_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_DisableTracking_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_DisableTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/*\n\x09 * Disable tracking\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Disable tracking" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_DisableTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "DisableTracking", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_DisableTracking_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_DisableTracking_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_DisableTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_DisableTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics
	{
		struct ZEDCamera_eventEnableSVORecording_Parms
		{
			ESlErrorCode ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventEnableSVORecording_Parms, ReturnValue), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::NewProp_ReturnValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|SVO" },
		{ "Comment", "/*\n\x09 * Enable recording using Init and SVO parameters\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Enable recording using Init and SVO parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "EnableSVORecording", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::ZEDCamera_eventEnableSVORecording_Parms), Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_EnableSVORecording()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_EnableSVORecording_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_EnableTracking_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_EnableTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/*\n\x09 * Enable tracking using current tracking parameters\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Enable tracking using current tracking parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_EnableTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "EnableTracking", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_EnableTracking_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_EnableTracking_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_EnableTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_EnableTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics
	{
		struct ZEDCamera_eventGrabCallback_Parms
		{
			ESlErrorCode ErrorCode;
			FSlTimestamp Timestamp;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ErrorCode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ErrorCode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Timestamp_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Timestamp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_ErrorCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventGrabCallback_Parms, ErrorCode), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_Timestamp_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_Timestamp = { "Timestamp", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventGrabCallback_Parms, Timestamp), Z_Construct_UScriptStruct_FSlTimestamp, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_Timestamp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_Timestamp_MetaData)) }; // 2964665703
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_ErrorCode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::NewProp_Timestamp,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Callback function for the grab delegate\n\x09 * @param ErrorCode Grab error code\n\x09 * @param Timestamp Image timestamp\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Callback function for the grab delegate\n* @param ErrorCode Grab error code\n* @param Timestamp Image timestamp" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "GrabCallback", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::ZEDCamera_eventGrabCallback_Parms), Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_GrabCallback()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_GrabCallback_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/*\n\x09 * Reset the tracking origin of the camera.\n\x09 * If using an HMD, reset with its current transform.\n\x09 * Else use the current tracking data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Reset the tracking origin of the camera.\n* If using an HMD, reset with its current transform.\n* Else use the current tracking data." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "ResetTrackingOrigin", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/*\n\x09 * Save the tracking area using current tracking parameters path\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Save the tracking area using current tracking parameters path" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "SaveSpatialMemoryArea", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics
	{
		struct ZEDCamera_eventSetCameraSettings_Parms
		{
			FSlVideoSettings NewValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewValue_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::NewProp_NewValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::NewProp_NewValue = { "NewValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventSetCameraSettings_Parms, NewValue), Z_Construct_UScriptStruct_FSlVideoSettings, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::NewProp_NewValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::NewProp_NewValue_MetaData)) }; // 3695001135
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::NewProp_NewValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Camera" },
		{ "Comment", "/*\n\x09 * Set the camera settings. Take effect next grab \n\x09 * @param NewValue The news camera settings\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Set the camera settings. Take effect next grab\n* @param NewValue The news camera settings" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "SetCameraSettings", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::ZEDCamera_eventSetCameraSettings_Parms), Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_SetCameraSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_SetCameraSettings_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics
	{
		struct ZEDCamera_eventSetDepthClampThreshold_Parms
		{
			float DepthDistance;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepthDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthDistance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::NewProp_DepthDistance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::NewProp_DepthDistance = { "DepthDistance", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventSetDepthClampThreshold_Parms, DepthDistance), METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::NewProp_DepthDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::NewProp_DepthDistance_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::NewProp_DepthDistance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Runtime" },
		{ "Comment", "/*\n\x09 * Set Max depth distance.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Set Max depth distance." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "SetDepthClampThreshold", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::ZEDCamera_eventSetDepthClampThreshold_Parms), Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics
	{
		struct ZEDCamera_eventSetRuntimeParameters_Parms
		{
			FSlRuntimeParameters NewValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewValue_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NewValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::NewProp_NewValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::NewProp_NewValue = { "NewValue", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventSetRuntimeParameters_Parms, NewValue), Z_Construct_UScriptStruct_FSlRuntimeParameters, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::NewProp_NewValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::NewProp_NewValue_MetaData)) }; // 1216080694
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::NewProp_NewValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Runtime" },
		{ "Comment", "/*\n\x09 * Set the runtime parameters. Take effect next grab\n\x09 * @param NewValue The news runtime parameters\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Set the runtime parameters. Take effect next grab\n* @param NewValue The news runtime parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "SetRuntimeParameters", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::ZEDCamera_eventSetRuntimeParameters_Parms), Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics
	{
		struct ZEDCamera_eventSetSVOPlaybackLooping_Parms
		{
			bool bLooping;
		};
		static void NewProp_bLooping_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLooping;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::NewProp_bLooping_SetBit(void* Obj)
	{
		((ZEDCamera_eventSetSVOPlaybackLooping_Parms*)Obj)->bLooping = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::NewProp_bLooping = { "bLooping", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDCamera_eventSetSVOPlaybackLooping_Parms), &Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::NewProp_bLooping_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::NewProp_bLooping,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|SVO" },
		{ "Comment", "/*\n\x09 * Enable/Disable SVO playback looping\n\x09 * @param bLooping True to loop\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Enable/Disable SVO playback looping\n* @param bLooping True to loop" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "SetSVOPlaybackLooping", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::ZEDCamera_eventSetSVOPlaybackLooping_Parms), Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics
	{
		struct ZEDCamera_eventSetThreadingMode_Parms
		{
			ESlThreadingMode NewValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_NewValue_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_NewValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::NewProp_NewValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::NewProp_NewValue = { "NewValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDCamera_eventSetThreadingMode_Parms, NewValue), Z_Construct_UEnum_Stereolabs_ESlThreadingMode, METADATA_PARAMS(nullptr, 0) }; // 3287782064
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::NewProp_NewValue_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::NewProp_NewValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/*\n\x09 * Set the threading mode and enable/disable the grab thread\n\x09 * @param NewValue The new threading mode\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Set the threading mode and enable/disable the grab thread\n* @param NewValue The new threading mode" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDCamera, nullptr, "SetThreadingMode", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::ZEDCamera_eventSetThreadingMode_Parms), Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDCamera_SetThreadingMode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDCamera_SetThreadingMode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZEDCamera);
	UClass* Z_Construct_UClass_AZEDCamera_NoRegister()
	{
		return AZEDCamera::StaticClass();
	}
	struct Z_Construct_UClass_AZEDCamera_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnTrackingDataUpdated_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTrackingDataUpdated;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnCameraActorInitialized_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCameraActorInitialized;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AntiDriftParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AntiDriftParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyeColor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftEyeColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyeDepth_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftEyeDepth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyeNormals_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftEyeNormals;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyeColor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RightEyeColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyeDepth_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RightEyeDepth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyeNormals_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RightEyeNormals;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftEyeRenderTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LeftEyeRenderTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightEyeRenderTarget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RightEyeRenderTarget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RuntimeParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraSettings_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CameraSettings;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderingParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RenderingParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CameraRenderPlaneDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraRenderPlaneDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HMDRenderPlaneDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HMDRenderPlaneDistance;
		static const UECodeGen_Private::FBytePropertyParams NewProp_RenderingMode_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RenderingMode_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_RenderingMode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackingData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TrackingData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TrackingParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_TrackingParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedLeftEyeMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedLeftEyeMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedRightEyeMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedRightEyeMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HMDLeftEyeMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HMDLeftEyeMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HMDRightEyeMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HMDRightEyeMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RecordingParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RecordingParameters;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseHMDTrackingAsOrigin_MetaData[];
#endif
		static void NewProp_bUseHMDTrackingAsOrigin_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseHMDTrackingAsOrigin;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDepthOcclusion_MetaData[];
#endif
		static void NewProp_bDepthOcclusion_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDepthOcclusion;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DepthClampThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DepthClampThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Batch_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Batch;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedSourceMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HMDLeftEyeSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HMDLeftEyeSourceMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HMDRightEyeSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HMDRightEyeSourceMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterLeftRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterLeftRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterRightRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterRightRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterLeftPlaneRotationRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterLeftPlaneRotationRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterRightPlaneRotationRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterRightPlaneRotationRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterLeftPlaneTranslationRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterLeftPlaneTranslationRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterRightPlaneTranslationRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterRightPlaneTranslationRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterLeftCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterLeftCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterRightCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterRightCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterLeftPlane_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterLeftPlane;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InterRightPlane_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InterRightPlane;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FinalRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FinalRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FinalTwRoot_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FinalTwRoot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FinalLeftPlane_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FinalLeftPlane;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FinalRightPlane_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FinalRightPlane;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AZEDCamera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZEDCamera_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZEDCamera_CameraClosed, "CameraClosed" }, // 1996020384
		{ &Z_Construct_UFunction_AZEDCamera_DisableSVORecording, "DisableSVORecording" }, // 3376548808
		{ &Z_Construct_UFunction_AZEDCamera_DisableTracking, "DisableTracking" }, // 2041917742
		{ &Z_Construct_UFunction_AZEDCamera_EnableSVORecording, "EnableSVORecording" }, // 4070537050
		{ &Z_Construct_UFunction_AZEDCamera_EnableTracking, "EnableTracking" }, // 907770696
		{ &Z_Construct_UFunction_AZEDCamera_GrabCallback, "GrabCallback" }, // 208602595
		{ &Z_Construct_UFunction_AZEDCamera_ResetTrackingOrigin, "ResetTrackingOrigin" }, // 4069024906
		{ &Z_Construct_UFunction_AZEDCamera_SaveSpatialMemoryArea, "SaveSpatialMemoryArea" }, // 2370600484
		{ &Z_Construct_UFunction_AZEDCamera_SetCameraSettings, "SetCameraSettings" }, // 845972023
		{ &Z_Construct_UFunction_AZEDCamera_SetDepthClampThreshold, "SetDepthClampThreshold" }, // 2532022779
		{ &Z_Construct_UFunction_AZEDCamera_SetRuntimeParameters, "SetRuntimeParameters" }, // 1419299455
		{ &Z_Construct_UFunction_AZEDCamera_SetSVOPlaybackLooping, "SetSVOPlaybackLooping" }, // 3408400205
		{ &Z_Construct_UFunction_AZEDCamera_SetThreadingMode, "SetThreadingMode" }, // 3189139825
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n * Engine representation of the ZED. Spawnable in a level\n */" },
		{ "IncludePath", "Core/ZEDCamera.h" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "* Engine representation of the ZED. Spawnable in a level" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnTrackingDataUpdated_MetaData[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/** Tracking data dispatcher */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Tracking data dispatcher" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnTrackingDataUpdated = { "OnTrackingDataUpdated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, OnTrackingDataUpdated), Z_Construct_UDelegateFunction_ZED_ZEDTrackingDataUpdatedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnTrackingDataUpdated_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnTrackingDataUpdated_MetaData)) }; // 2272968012
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnCameraActorInitialized_MetaData[] = {
		{ "Category", "Zed|Camera" },
		{ "Comment", "/** Actor initialized */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Actor initialized" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnCameraActorInitialized = { "OnCameraActorInitialized", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, OnCameraActorInitialized), Z_Construct_UDelegateFunction_ZED_ZEDCameraActorInitializedDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnCameraActorInitialized_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnCameraActorInitialized_MetaData)) }; // 1018733546
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_AntiDriftParameters_MetaData[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/** Anti drift parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Anti drift parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_AntiDriftParameters = { "AntiDriftParameters", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, AntiDriftParameters), Z_Construct_UScriptStruct_FSlAntiDriftParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_AntiDriftParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_AntiDriftParameters_MetaData)) }; // 4192755535
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeColor_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Left eye image texture */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Left eye image texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeColor = { "LeftEyeColor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, LeftEyeColor), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeDepth_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Left eye depth texture  */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Left eye depth texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeDepth = { "LeftEyeDepth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, LeftEyeDepth), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeDepth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeDepth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeNormals_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Left eye normals texture */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Left eye normals texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeNormals = { "LeftEyeNormals", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, LeftEyeNormals), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeNormals_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeNormals_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeColor_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Right eye image texture */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Right eye image texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeColor = { "RightEyeColor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RightEyeColor), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeColor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeColor_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeDepth_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Right eye depth texture  */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Right eye depth texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeDepth = { "RightEyeDepth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RightEyeDepth), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeDepth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeDepth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeNormals_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Right eye normals texture  */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Right eye normals texture" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeNormals = { "RightEyeNormals", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RightEyeNormals), Z_Construct_UClass_USlTexture_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeNormals_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeNormals_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeRenderTarget_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Render target left eye */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Render target left eye" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeRenderTarget = { "LeftEyeRenderTarget", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, LeftEyeRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeRenderTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeRenderTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeRenderTarget_MetaData[] = {
		{ "Category", "Zed|Textures" },
		{ "Comment", "/** Render target right eye */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Render target right eye" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeRenderTarget = { "RightEyeRenderTarget", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RightEyeRenderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeRenderTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeRenderTarget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RuntimeParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Runtime parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Runtime parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RuntimeParameters = { "RuntimeParameters", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RuntimeParameters), Z_Construct_UScriptStruct_FSlRuntimeParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RuntimeParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RuntimeParameters_MetaData)) }; // 1216080694
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraSettings_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Camera settings */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Camera settings" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraSettings = { "CameraSettings", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, CameraSettings), Z_Construct_UScriptStruct_FSlVideoSettings, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraSettings_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraSettings_MetaData)) }; // 3695001135
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Config rendering parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Config rendering parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingParameters = { "RenderingParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RenderingParameters), Z_Construct_UScriptStruct_FSlRenderingParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingParameters_MetaData)) }; // 2304709159
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraRenderPlaneDistance_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/**  Render distance of the ZED planes */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Render distance of the ZED planes" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraRenderPlaneDistance = { "CameraRenderPlaneDistance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, CameraRenderPlaneDistance), METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraRenderPlaneDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraRenderPlaneDistance_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRenderPlaneDistance_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Render distance of the HMD planes */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Render distance of the HMD planes" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRenderPlaneDistance = { "HMDRenderPlaneDistance", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, HMDRenderPlaneDistance), METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRenderPlaneDistance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRenderPlaneDistance_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Rendering mode */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Rendering mode" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode = { "RenderingMode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RenderingMode), Z_Construct_UEnum_Stereolabs_ESlRenderingMode, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode_MetaData)) }; // 2467298160
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingData_MetaData[] = {
		{ "Category", "Zed|Tracking" },
		{ "Comment", "/** The current tracking data */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "The current tracking data" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingData = { "TrackingData", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, TrackingData), Z_Construct_UScriptStruct_FZEDTrackingData, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingData_MetaData)) }; // 2053750691
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Tracking parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Tracking parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingParameters = { "TrackingParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, TrackingParameters), Z_Construct_UScriptStruct_FSlPositionalTrackingParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingParameters_MetaData)) }; // 491693935
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedLeftEyeMaterialInstanceDynamic_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Dynamic left Zed eye material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Dynamic left Zed eye material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedLeftEyeMaterialInstanceDynamic = { "ZedLeftEyeMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, ZedLeftEyeMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedLeftEyeMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedLeftEyeMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedRightEyeMaterialInstanceDynamic_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Dynamic right Zed eye material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Dynamic right Zed eye material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedRightEyeMaterialInstanceDynamic = { "ZedRightEyeMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, ZedRightEyeMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedRightEyeMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedRightEyeMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeMaterialInstanceDynamic_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Dynamic HMD left eye material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Dynamic HMD left eye material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeMaterialInstanceDynamic = { "HMDLeftEyeMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, HMDLeftEyeMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeMaterialInstanceDynamic_MetaData[] = {
		{ "Category", "Zed|Rendering" },
		{ "Comment", "/** Dynamic HMD right eye material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Dynamic HMD right eye material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeMaterialInstanceDynamic = { "HMDRightEyeMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, HMDRightEyeMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_RecordingParameters_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Recording parameters */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Recording parameters" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_RecordingParameters = { "RecordingParameters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, RecordingParameters), Z_Construct_UScriptStruct_FSlRecordingParameters, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RecordingParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_RecordingParameters_MetaData)) }; // 2111381437
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** True if HMD transform is used as tracking origin */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "True if HMD transform is used as tracking origin" },
	};
#endif
	void Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin_SetBit(void* Obj)
	{
		((AZEDCamera*)Obj)->bUseHMDTrackingAsOrigin = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin = { "bUseHMDTrackingAsOrigin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AZEDCamera), &Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** When enabled, the real world can occlude (cover up) virtual objects that are behind it. Otherwise, virtual objects will appear in front. */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "When enabled, the real world can occlude (cover up) virtual objects that are behind it. Otherwise, virtual objects will appear in front." },
	};
#endif
	void Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion_SetBit(void* Obj)
	{
		((AZEDCamera*)Obj)->bDepthOcclusion = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion = { "bDepthOcclusion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(AZEDCamera), &Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_DepthClampThreshold_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Max depth distance. Can be modified at runtime */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Max depth distance. Can be modified at runtime" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_DepthClampThreshold = { "DepthClampThreshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, DepthClampThreshold), METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_DepthClampThreshold_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_DepthClampThreshold_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_Batch_MetaData[] = {
		{ "Comment", "/** Current batch */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Current batch" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_Batch = { "Batch", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, Batch), Z_Construct_UClass_USlTextureBatch_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_Batch_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_Batch_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedSourceMaterial_MetaData[] = {
		{ "Comment", "/** Zed material resource */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Zed material resource" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedSourceMaterial = { "ZedSourceMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, ZedSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedSourceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeSourceMaterial_MetaData[] = {
		{ "Comment", "/** HMD left eye material resource */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "HMD left eye material resource" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeSourceMaterial = { "HMDLeftEyeSourceMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, HMDLeftEyeSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeSourceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeSourceMaterial_MetaData[] = {
		{ "Comment", "/** HMD right eye material resource */" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "HMD right eye material resource" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeSourceMaterial = { "HMDRightEyeSourceMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, HMDRightEyeSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeSourceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Root component for intermediate cameras and planes\n\x09\x09* This component takes the camera-HMD calibration translation \n\x09\x09*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Root component for intermediate cameras and planes\nThis component takes the camera-HMD calibration translation" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftRoot = { "InterLeftRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterLeftRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightRoot = { "InterRightRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterRightRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneRotationRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Root for intermediate planes that takes camera-HMD calibration rotation */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Root for intermediate planes that takes camera-HMD calibration rotation" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneRotationRoot = { "InterLeftPlaneRotationRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterLeftPlaneRotationRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneRotationRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneRotationRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneRotationRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneRotationRoot = { "InterRightPlaneRotationRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterRightPlaneRotationRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneRotationRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneRotationRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneTranslationRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Root for intermediate planes that a inter camera forward translation (to be far enough from the camera) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Root for intermediate planes that a inter camera forward translation (to be far enough from the camera)" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneTranslationRoot = { "InterLeftPlaneTranslationRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterLeftPlaneTranslationRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneTranslationRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneTranslationRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneTranslationRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneTranslationRoot = { "InterRightPlaneTranslationRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterRightPlaneTranslationRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneTranslationRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneTranslationRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftCamera_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Left intermediate camera (virtual equivalent of physical left zed camera) */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Left intermediate camera (virtual equivalent of physical left zed camera)" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftCamera = { "InterLeftCamera", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterLeftCamera), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightCamera_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Right intermediate camera (virtual equivalent of physical right zed camera)*/" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Right intermediate camera (virtual equivalent of physical right zed camera)" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightCamera = { "InterRightCamera", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterRightCamera), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlane_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Intermediate left plane on which Zed left image is displayed */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Intermediate left plane on which Zed left image is displayed" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlane = { "InterLeftPlane", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterLeftPlane), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlane_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlane_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlane_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Intermediate right plane on which Zed right image is displayed */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Intermediate right plane on which Zed right image is displayed" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlane = { "InterRightPlane", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, InterRightPlane), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlane_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlane_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Main root for final planes */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Main root for final planes" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRoot = { "FinalRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, FinalRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalTwRoot_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Root for final planes that takes time-warp rotations */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Root for final planes that takes time-warp rotations" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalTwRoot = { "FinalTwRoot", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, FinalTwRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalTwRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalTwRoot_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalLeftPlane_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Left final plane on which left fused (virtual and real) image is displayed */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Left final plane on which left fused (virtual and real) image is displayed" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalLeftPlane = { "FinalLeftPlane", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, FinalLeftPlane), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalLeftPlane_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalLeftPlane_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRightPlane_MetaData[] = {
		{ "Category", "Zed|Components" },
		{ "Comment", "/** Right final plane on which right fused (virtual and real) image is displayed */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDCamera.h" },
		{ "ToolTip", "Right final plane on which right fused (virtual and real) image is displayed" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRightPlane = { "FinalRightPlane", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDCamera, FinalRightPlane), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRightPlane_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRightPlane_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZEDCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnTrackingDataUpdated,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_OnCameraActorInitialized,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_AntiDriftParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeDepth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeNormals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeDepth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeNormals,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_LeftEyeRenderTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RightEyeRenderTarget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RuntimeParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraSettings,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_CameraRenderPlaneDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRenderPlaneDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RenderingMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_TrackingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedLeftEyeMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedRightEyeMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_RecordingParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_bUseHMDTrackingAsOrigin,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_bDepthOcclusion,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_DepthClampThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_Batch,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_ZedSourceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDLeftEyeSourceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_HMDRightEyeSourceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneRotationRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneRotationRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlaneTranslationRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlaneTranslationRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterLeftPlane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_InterRightPlane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalTwRoot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalLeftPlane,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDCamera_Statics::NewProp_FinalRightPlane,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZEDCamera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZEDCamera>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZEDCamera_Statics::ClassParams = {
		&AZEDCamera::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZEDCamera_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZEDCamera_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDCamera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZEDCamera()
	{
		if (!Z_Registration_Info_UClass_AZEDCamera.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZEDCamera.OuterSingleton, Z_Construct_UClass_AZEDCamera_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZEDCamera.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<AZEDCamera>()
	{
		return AZEDCamera::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZEDCamera);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZEDCamera, AZEDCamera::StaticClass, TEXT("AZEDCamera"), &Z_Registration_Info_UClass_AZEDCamera, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZEDCamera), 1323181358U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_2078176892(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDCamera_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
