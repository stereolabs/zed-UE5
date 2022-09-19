// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ZED/Public/Core/ZEDPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeZEDPlayerController() {}
// Cross Module References
	ZED_API UFunction* Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ZED();
	ZED_API UClass* Z_Construct_UClass_AZEDPlayerController_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlErrorCode();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ZED_API UClass* Z_Construct_UClass_AZEDPawn_NoRegister();
	ZED_API UClass* Z_Construct_UClass_AZEDCamera_NoRegister();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlViewportHelper();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTimelineComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCurveFloat_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n * Simple delegate\n */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Simple delegate" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_ZED, nullptr, "ZEDPlayerControllerDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execInternal_OpenZedCamera)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Internal_OpenZedCamera();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execOnRep_ZedPawn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_ZedPawn();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execResetHMDTrackingOrigin)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetHMDTrackingOrigin();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execZedCameraActorInitialized)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZedCameraActorInitialized();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execFading)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_FadingFactor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Fading(Z_Param_FadingFactor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execZedCameraTrackingEnabled)
	{
		P_GET_UBOOL(Z_Param_bSuccess);
		P_GET_ENUM(ESlErrorCode,Z_Param_ErrorCode);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_Location);
		P_GET_STRUCT_REF(FRotator,Z_Param_Out_Rotation);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZedCameraTrackingEnabled(Z_Param_bSuccess,ESlErrorCode(Z_Param_ErrorCode),Z_Param_Out_Location,Z_Param_Out_Rotation);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execZedCameraDisconnected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZedCameraDisconnected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execZedCameraClosed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZedCameraClosed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execZedCameraOpened)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ZedCameraOpened();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execUpdateHUDZedDisconnected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateHUDZedDisconnected_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execUpdateHUDZedTrackingEnabled)
	{
		P_GET_UBOOL(Z_Param_bSuccess);
		P_GET_ENUM(ESlErrorCode,Z_Param_ErrorCode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateHUDZedTrackingEnabled_Implementation(Z_Param_bSuccess,ESlErrorCode(Z_Param_ErrorCode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execUpdateHUDEnablingZedTracking)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateHUDEnablingZedTracking_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execUpdateHUDZedOpened)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateHUDZedOpened_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execUpdateHUDCheckOpeningZed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateHUDCheckOpeningZed_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execUpdateHUDOpeningZed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateHUDOpeningZed_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execInit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Init();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execFadeOut)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FadeOut();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execFadeIn)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FadeIn();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execSpawnZedCameraActor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SpawnZedCameraActor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execSpawnPawn)
	{
		P_GET_OBJECT(UClass,Z_Param_NewPawnClass);
		P_GET_UBOOL(Z_Param_bPossess);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->SpawnPawn(Z_Param_NewPawnClass,Z_Param_bPossess);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execMakeDefaultInit)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MakeDefaultInit();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execCloseZedCamera)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseZedCamera();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execOpenZedCamera)
	{
		P_GET_UBOOL(Z_Param_bHideWorld);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenZedCamera(Z_Param_bHideWorld);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execEmptyShowOnlyComponentList)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EmptyShowOnlyComponentList();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AZEDPlayerController::execAddShowOnlyComponent)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_InComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddShowOnlyComponent(Z_Param_InComponent);
		P_NATIVE_END;
	}
	static FName NAME_AZEDPlayerController_InitEvent = FName(TEXT("InitEvent"));
	void AZEDPlayerController::InitEvent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_InitEvent),NULL);
	}
	static FName NAME_AZEDPlayerController_UpdateHUDCheckOpeningZed = FName(TEXT("UpdateHUDCheckOpeningZed"));
	void AZEDPlayerController::UpdateHUDCheckOpeningZed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_UpdateHUDCheckOpeningZed),NULL);
	}
	static FName NAME_AZEDPlayerController_UpdateHUDEnablingZedTracking = FName(TEXT("UpdateHUDEnablingZedTracking"));
	void AZEDPlayerController::UpdateHUDEnablingZedTracking()
	{
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_UpdateHUDEnablingZedTracking),NULL);
	}
	static FName NAME_AZEDPlayerController_UpdateHUDOpeningZed = FName(TEXT("UpdateHUDOpeningZed"));
	void AZEDPlayerController::UpdateHUDOpeningZed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_UpdateHUDOpeningZed),NULL);
	}
	static FName NAME_AZEDPlayerController_UpdateHUDZedDisconnected = FName(TEXT("UpdateHUDZedDisconnected"));
	void AZEDPlayerController::UpdateHUDZedDisconnected()
	{
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_UpdateHUDZedDisconnected),NULL);
	}
	static FName NAME_AZEDPlayerController_UpdateHUDZedOpened = FName(TEXT("UpdateHUDZedOpened"));
	void AZEDPlayerController::UpdateHUDZedOpened()
	{
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_UpdateHUDZedOpened),NULL);
	}
	static FName NAME_AZEDPlayerController_UpdateHUDZedTrackingEnabled = FName(TEXT("UpdateHUDZedTrackingEnabled"));
	void AZEDPlayerController::UpdateHUDZedTrackingEnabled(bool bSuccess, ESlErrorCode ErrorCode)
	{
		ZEDPlayerController_eventUpdateHUDZedTrackingEnabled_Parms Parms;
		Parms.bSuccess=bSuccess ? true : false;
		Parms.ErrorCode=ErrorCode;
		ProcessEvent(FindFunctionChecked(NAME_AZEDPlayerController_UpdateHUDZedTrackingEnabled),&Parms);
	}
	void AZEDPlayerController::StaticRegisterNativesAZEDPlayerController()
	{
		UClass* Class = AZEDPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddShowOnlyComponent", &AZEDPlayerController::execAddShowOnlyComponent },
			{ "CloseZedCamera", &AZEDPlayerController::execCloseZedCamera },
			{ "EmptyShowOnlyComponentList", &AZEDPlayerController::execEmptyShowOnlyComponentList },
			{ "FadeIn", &AZEDPlayerController::execFadeIn },
			{ "FadeOut", &AZEDPlayerController::execFadeOut },
			{ "Fading", &AZEDPlayerController::execFading },
			{ "Init", &AZEDPlayerController::execInit },
			{ "Internal_OpenZedCamera", &AZEDPlayerController::execInternal_OpenZedCamera },
			{ "MakeDefaultInit", &AZEDPlayerController::execMakeDefaultInit },
			{ "OnRep_ZedPawn", &AZEDPlayerController::execOnRep_ZedPawn },
			{ "OpenZedCamera", &AZEDPlayerController::execOpenZedCamera },
			{ "ResetHMDTrackingOrigin", &AZEDPlayerController::execResetHMDTrackingOrigin },
			{ "SpawnPawn", &AZEDPlayerController::execSpawnPawn },
			{ "SpawnZedCameraActor", &AZEDPlayerController::execSpawnZedCameraActor },
			{ "UpdateHUDCheckOpeningZed", &AZEDPlayerController::execUpdateHUDCheckOpeningZed },
			{ "UpdateHUDEnablingZedTracking", &AZEDPlayerController::execUpdateHUDEnablingZedTracking },
			{ "UpdateHUDOpeningZed", &AZEDPlayerController::execUpdateHUDOpeningZed },
			{ "UpdateHUDZedDisconnected", &AZEDPlayerController::execUpdateHUDZedDisconnected },
			{ "UpdateHUDZedOpened", &AZEDPlayerController::execUpdateHUDZedOpened },
			{ "UpdateHUDZedTrackingEnabled", &AZEDPlayerController::execUpdateHUDZedTrackingEnabled },
			{ "ZedCameraActorInitialized", &AZEDPlayerController::execZedCameraActorInitialized },
			{ "ZedCameraClosed", &AZEDPlayerController::execZedCameraClosed },
			{ "ZedCameraDisconnected", &AZEDPlayerController::execZedCameraDisconnected },
			{ "ZedCameraOpened", &AZEDPlayerController::execZedCameraOpened },
			{ "ZedCameraTrackingEnabled", &AZEDPlayerController::execZedCameraTrackingEnabled },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics
	{
		struct ZEDPlayerController_eventAddShowOnlyComponent_Parms
		{
			UPrimitiveComponent* InComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventAddShowOnlyComponent_Parms, InComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::NewProp_InComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::NewProp_InComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::NewProp_InComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "AddShowOnlyComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::ZEDPlayerController_eventAddShowOnlyComponent_Parms), Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Close the camera\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Close the camera" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "CloseZedCamera", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "EmptyShowOnlyComponentList", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_FadeIn_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_FadeIn_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Fade in rendering\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Fade in rendering" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_FadeIn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "FadeIn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_FadeIn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_FadeIn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_FadeIn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_FadeIn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_FadeOut_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_FadeOut_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Fade out rendering\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Fade out rendering" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_FadeOut_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "FadeOut", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_FadeOut_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_FadeOut_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_FadeOut()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_FadeOut_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_Fading_Statics
	{
		struct ZEDPlayerController_eventFading_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::NewProp_FadingFactor = { "FadingFactor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventFading_Parms, FadingFactor), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::NewProp_FadingFactor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Timeline fade function\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Timeline fade function" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "Fading", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::ZEDPlayerController_eventFading_Parms), Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_Fading()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_Fading_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_Init_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_Init_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Initialize controller\n\x09 * @param bOpenCamera      Open the camera automatically after controller initialized\n\x09 * @param bStereoRendering Enable the HMD for stereo rendering\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Initialize controller\n* @param bOpenCamera      Open the camera automatically after controller initialized\n* @param bStereoRendering Enable the HMD for stereo rendering" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "Init", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_InitEvent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_InitEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Event called after internal init\n\x09 */" },
		{ "DisplayName", "Init" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Event called after internal init" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_InitEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "InitEvent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_InitEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_InitEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_InitEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_InitEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Open the camera\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Open the camera" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "Internal_OpenZedCamera", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09* Make default initialisation (the sequence done in begin play if bUseDefaultBeginPlay=true) : it creates pawn and camera and initialise them.\n\x09* You can put bUseDefaultBeginPlay=false and call this function later if you need to call other functions before. For instance it can be useful\n\x09* in a server configuration if you need to exchange info between client and server before spawn of pawn so that you can change pawn class.\n\x09*/" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Make default initialisation (the sequence done in begin play if bUseDefaultBeginPlay=true) : it creates pawn and camera and initialise them.\n* You can put bUseDefaultBeginPlay=false and call this function later if you need to call other functions before. For instance it can be useful\n* in a server configuration if you need to exchange info between client and server before spawn of pawn so that you can change pawn class." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "MakeDefaultInit", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Network notification for pawn spawning\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Network notification for pawn spawning" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "OnRep_ZedPawn", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics
	{
		struct ZEDPlayerController_eventOpenZedCamera_Parms
		{
			bool bHideWorld;
		};
		static void NewProp_bHideWorld_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideWorld;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::NewProp_bHideWorld_SetBit(void* Obj)
	{
		((ZEDPlayerController_eventOpenZedCamera_Parms*)Obj)->bHideWorld = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::NewProp_bHideWorld = { "bHideWorld", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDPlayerController_eventOpenZedCamera_Parms), &Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::NewProp_bHideWorld_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::NewProp_bHideWorld,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Open the camera\n\x09 */" },
		{ "CPP_Default_bHideWorld", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Open the camera" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "OpenZedCamera", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::ZEDPlayerController_eventOpenZedCamera_Parms), Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Reset HMD tracking to be close to world origin\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Reset HMD tracking to be close to world origin" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "ResetHMDTrackingOrigin", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics
	{
		struct ZEDPlayerController_eventSpawnPawn_Parms
		{
			UClass* NewPawnClass;
			bool bPossess;
			UObject* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_NewPawnClass;
		static void NewProp_bPossess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPossess;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_NewPawnClass = { "NewPawnClass", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventSpawnPawn_Parms, NewPawnClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_bPossess_SetBit(void* Obj)
	{
		((ZEDPlayerController_eventSpawnPawn_Parms*)Obj)->bPossess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_bPossess = { "bPossess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDPlayerController_eventSpawnPawn_Parms), &Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_bPossess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventSpawnPawn_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_NewPawnClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_bPossess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Spawn the pawn\n\x09 * @return The pawn\n\x09 */" },
		{ "CPP_Default_bPossess", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Spawn the pawn\n* @return The pawn" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "SpawnPawn", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::ZEDPlayerController_eventSpawnPawn_Parms), Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_SpawnPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_SpawnPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Spawn the zed actor\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Spawn the zed actor" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "SpawnZedCameraActor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Called every 2 seconds to check camera opening status\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called every 2 seconds to check camera opening status" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "UpdateHUDCheckOpeningZed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Called after Zed opened if tracking is enabled in tacking parameters\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called after Zed opened if tracking is enabled in tacking parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "UpdateHUDEnablingZedTracking", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Called before opening Zed\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called before opening Zed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "UpdateHUDOpeningZed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Called if camera disconnected\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called if camera disconnected" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "UpdateHUDZedDisconnected", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Called after Zed opened if tracking is not enabled in tracking parameters\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called after Zed opened if tracking is not enabled in tracking parameters" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "UpdateHUDZedOpened", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics
	{
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ErrorCode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ErrorCode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((ZEDPlayerController_eventUpdateHUDZedTrackingEnabled_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDPlayerController_eventUpdateHUDZedTrackingEnabled_Parms), &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_ErrorCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventUpdateHUDZedTrackingEnabled_Parms, ErrorCode), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_ErrorCode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::NewProp_ErrorCode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::Function_MetaDataParams[] = {
		{ "Category", "Zed" },
		{ "Comment", "/*\n\x09 * Called after tracking enabled\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called after tracking enabled" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "UpdateHUDZedTrackingEnabled", nullptr, nullptr, sizeof(ZEDPlayerController_eventUpdateHUDZedTrackingEnabled_Parms), Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Called after camera fully initialized\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Called after camera fully initialized" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "ZedCameraActorInitialized", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Camera closed\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Camera closed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "ZedCameraClosed", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Camera disconnected\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Camera disconnected" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "ZedCameraDisconnected", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Camera opened\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Camera opened" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "ZedCameraOpened", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics
	{
		struct ZEDPlayerController_eventZedCameraTrackingEnabled_Parms
		{
			bool bSuccess;
			ESlErrorCode ErrorCode;
			FVector Location;
			FRotator Rotation;
		};
		static void NewProp_bSuccess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ErrorCode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_ErrorCode;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Location;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Rotation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Rotation;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_bSuccess_SetBit(void* Obj)
	{
		((ZEDPlayerController_eventZedCameraTrackingEnabled_Parms*)Obj)->bSuccess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ZEDPlayerController_eventZedCameraTrackingEnabled_Parms), &Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_ErrorCode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventZedCameraTrackingEnabled_Parms, ErrorCode), Z_Construct_UEnum_Stereolabs_ESlErrorCode, METADATA_PARAMS(nullptr, 0) }; // 1669340549
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventZedCameraTrackingEnabled_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Location_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Location_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Rotation_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Rotation = { "Rotation", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ZEDPlayerController_eventZedCameraTrackingEnabled_Parms, Rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Rotation_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Rotation_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_bSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_ErrorCode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_ErrorCode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Location,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::NewProp_Rotation,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/*\n\x09 * Tracking enabled\n\x09 * @param bSuccess  True if enabled\n\x09 * @param ErrorCode The error code if failed\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Tracking enabled\n* @param bSuccess  True if enabled\n* @param ErrorCode The error code if failed" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AZEDPlayerController, nullptr, "ZedCameraTrackingEnabled", nullptr, nullptr, sizeof(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::ZEDPlayerController_eventZedCameraTrackingEnabled_Parms), Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AZEDPlayerController);
	UClass* Z_Construct_UClass_AZEDPlayerController_NoRegister()
	{
		return AZEDPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AZEDPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PawnClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_PawnClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPawnSpawned_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPawnSpawned;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPreZedCameraOpening_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPreZedCameraOpening;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedPawn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedPawn;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ZedCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ZedCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseDefaultBeginPlay_MetaData[];
#endif
		static void NewProp_bUseDefaultBeginPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseDefaultBeginPlay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOpenZedCameraAtInit_MetaData[];
#endif
		static void NewProp_bOpenZedCameraAtInit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOpenZedCameraAtInit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStereoRenderingSupport_MetaData[];
#endif
		static void NewProp_bStereoRenderingSupport_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStereoRenderingSupport;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsFirstPlayer_MetaData[];
#endif
		static void NewProp_bIsFirstPlayer_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsFirstPlayer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseShowOnlyList_MetaData[];
#endif
		static void NewProp_bUseShowOnlyList_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseShowOnlyList;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bHideWorldOpeningZedCamera_MetaData[];
#endif
		static void NewProp_bHideWorldOpeningZedCamera_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bHideWorldOpeningZedCamera;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ViewportHelper_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ViewportHelper;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessFadeMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessFadeMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessFadeSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessFadeSourceMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessZedMaterialInstanceDynamic_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessZedMaterialInstanceDynamic;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessZedSourceMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessZedSourceMaterial;
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
	UObject* (*const Z_Construct_UClass_AZEDPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_ZED,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AZEDPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AZEDPlayerController_AddShowOnlyComponent, "AddShowOnlyComponent" }, // 1054321046
		{ &Z_Construct_UFunction_AZEDPlayerController_CloseZedCamera, "CloseZedCamera" }, // 4031360024
		{ &Z_Construct_UFunction_AZEDPlayerController_EmptyShowOnlyComponentList, "EmptyShowOnlyComponentList" }, // 228871268
		{ &Z_Construct_UFunction_AZEDPlayerController_FadeIn, "FadeIn" }, // 314139150
		{ &Z_Construct_UFunction_AZEDPlayerController_FadeOut, "FadeOut" }, // 2512060318
		{ &Z_Construct_UFunction_AZEDPlayerController_Fading, "Fading" }, // 1950535619
		{ &Z_Construct_UFunction_AZEDPlayerController_Init, "Init" }, // 4081680106
		{ &Z_Construct_UFunction_AZEDPlayerController_InitEvent, "InitEvent" }, // 2705389160
		{ &Z_Construct_UFunction_AZEDPlayerController_Internal_OpenZedCamera, "Internal_OpenZedCamera" }, // 3842993970
		{ &Z_Construct_UFunction_AZEDPlayerController_MakeDefaultInit, "MakeDefaultInit" }, // 1818621836
		{ &Z_Construct_UFunction_AZEDPlayerController_OnRep_ZedPawn, "OnRep_ZedPawn" }, // 3290404511
		{ &Z_Construct_UFunction_AZEDPlayerController_OpenZedCamera, "OpenZedCamera" }, // 2528979306
		{ &Z_Construct_UFunction_AZEDPlayerController_ResetHMDTrackingOrigin, "ResetHMDTrackingOrigin" }, // 1109633409
		{ &Z_Construct_UFunction_AZEDPlayerController_SpawnPawn, "SpawnPawn" }, // 631722741
		{ &Z_Construct_UFunction_AZEDPlayerController_SpawnZedCameraActor, "SpawnZedCameraActor" }, // 3666709038
		{ &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDCheckOpeningZed, "UpdateHUDCheckOpeningZed" }, // 665450502
		{ &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDEnablingZedTracking, "UpdateHUDEnablingZedTracking" }, // 4192639317
		{ &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDOpeningZed, "UpdateHUDOpeningZed" }, // 1154633600
		{ &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedDisconnected, "UpdateHUDZedDisconnected" }, // 2327460112
		{ &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedOpened, "UpdateHUDZedOpened" }, // 1028048265
		{ &Z_Construct_UFunction_AZEDPlayerController_UpdateHUDZedTrackingEnabled, "UpdateHUDZedTrackingEnabled" }, // 2616062872
		{ &Z_Construct_UFunction_AZEDPlayerController_ZedCameraActorInitialized, "ZedCameraActorInitialized" }, // 4241285085
		{ &Z_Construct_UFunction_AZEDPlayerController_ZedCameraClosed, "ZedCameraClosed" }, // 624657332
		{ &Z_Construct_UFunction_AZEDPlayerController_ZedCameraDisconnected, "ZedCameraDisconnected" }, // 3119341607
		{ &Z_Construct_UFunction_AZEDPlayerController_ZedCameraOpened, "ZedCameraOpened" }, // 1794573402
		{ &Z_Construct_UFunction_AZEDPlayerController_ZedCameraTrackingEnabled, "ZedCameraTrackingEnabled" }, // 4139281826
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Zed" },
		{ "Comment", "/*\n * Base class for controller using the Zed.\n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "Core/ZEDPlayerController.h" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "* Base class for controller using the Zed." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PawnClass_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** The pawn class to spawn */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "The pawn class to spawn" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PawnClass = { "PawnClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, PawnClass), Z_Construct_UClass_AZEDPawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PawnClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PawnClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPawnSpawned_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Pawn spawned delegate */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Pawn spawned delegate" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPawnSpawned = { "OnPawnSpawned", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, OnPawnSpawned), Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPawnSpawned_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPawnSpawned_MetaData)) }; // 130332875
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPreZedCameraOpening_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Zed camera actor initialization */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Zed camera actor initialization" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPreZedCameraOpening = { "OnPreZedCameraOpening", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, OnPreZedCameraOpening), Z_Construct_UDelegateFunction_ZED_ZEDPlayerControllerDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPreZedCameraOpening_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPreZedCameraOpening_MetaData)) }; // 130332875
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedPawn_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** The current Zed pawn possessed */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "The current Zed pawn possessed" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedPawn = { "ZedPawn", "OnRep_ZedPawn", (EPropertyFlags)0x0010000100000034, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, ZedPawn), Z_Construct_UClass_AZEDPawn_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedPawn_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedPawn_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedCamera_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** The current Zed actor attached to the pawn */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "The current Zed actor attached to the pawn" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedCamera = { "ZedCamera", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, ZedCamera), Z_Construct_UClass_AZEDCamera_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** True to use pawn and Zed default spawn sequence and start initialization of the controller after pawn spawned */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "True to use pawn and Zed default spawn sequence and start initialization of the controller after pawn spawned" },
	};
#endif
	void Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay_SetBit(void* Obj)
	{
		((AZEDPlayerController*)Obj)->bUseDefaultBeginPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay = { "bUseDefaultBeginPlay", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDPlayerController), &Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** True to open the camera after initialization */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "True to open the camera after initialization" },
	};
#endif
	void Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit_SetBit(void* Obj)
	{
		((AZEDPlayerController*)Obj)->bOpenZedCameraAtInit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit = { "bOpenZedCameraAtInit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDPlayerController), &Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** True if stereo rendering is supported. If true the controller will automatically open th HMD before opening the camera if any HMD is connected. */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "True if stereo rendering is supported. If true the controller will automatically open th HMD before opening the camera if any HMD is connected." },
	};
#endif
	void Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport_SetBit(void* Obj)
	{
		((AZEDPlayerController*)Obj)->bStereoRenderingSupport = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport = { "bStereoRenderingSupport", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDPlayerController), &Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer_MetaData[] = {
		{ "Category", "ZEDPlayerController" },
		{ "Comment", "/** True if player 1 */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "True if player 1" },
	};
#endif
	void Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer_SetBit(void* Obj)
	{
		((AZEDPlayerController*)Obj)->bIsFirstPlayer = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer = { "bIsFirstPlayer", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDPlayerController), &Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** Whether to render primitives component. */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Whether to render primitives component." },
	};
#endif
	void Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList_SetBit(void* Obj)
	{
		((AZEDPlayerController*)Obj)->bUseShowOnlyList = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList = { "bUseShowOnlyList", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDPlayerController), &Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera_MetaData[] = {
		{ "Category", "Zed" },
		{ "Comment", "/** True to hide the world when opening the camera */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "True to hide the world when opening the camera" },
	};
#endif
	void Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera_SetBit(void* Obj)
	{
		((AZEDPlayerController*)Obj)->bHideWorldOpeningZedCamera = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera = { "bHideWorldOpeningZedCamera", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AZEDPlayerController), &Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera_SetBit, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ViewportHelper_MetaData[] = {
		{ "Category", "ZEDPlayerController" },
		{ "Comment", "/** Viewport helper */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Viewport helper" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ViewportHelper = { "ViewportHelper", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, ViewportHelper), Z_Construct_UScriptStruct_FSlViewportHelper, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ViewportHelper_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ViewportHelper_MetaData)) }; // 3743845575
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeMaterialInstanceDynamic_MetaData[] = {
		{ "Comment", "/** Dynamic instance of the post process fade material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Dynamic instance of the post process fade material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeMaterialInstanceDynamic = { "PostProcessFadeMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, PostProcessFadeMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeSourceMaterial_MetaData[] = {
		{ "Comment", "/** Post process material resource */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Post process material resource" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeSourceMaterial = { "PostProcessFadeSourceMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, PostProcessFadeSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeSourceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedMaterialInstanceDynamic_MetaData[] = {
		{ "Comment", "/** Dynamic instance of the post process ZED material */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Dynamic instance of the post process ZED material" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedMaterialInstanceDynamic = { "PostProcessZedMaterialInstanceDynamic", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, PostProcessZedMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedMaterialInstanceDynamic_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedSourceMaterial_MetaData[] = {
		{ "Comment", "/** Post process material resource */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Post process material resource" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedSourceMaterial = { "PostProcessZedSourceMaterial", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, PostProcessZedSourceMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedSourceMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedSourceMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimeline_MetaData[] = {
		{ "Comment", "/** Fade timeline */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Fade timeline" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimeline = { "FadeTimeline", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, FadeTimeline), Z_Construct_UClass_UTimelineComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimeline_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimeline_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimelineCurve_MetaData[] = {
		{ "Comment", "/** Fade timeline curve */" },
		{ "ModuleRelativePath", "Public/Core/ZEDPlayerController.h" },
		{ "ToolTip", "Fade timeline curve" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimelineCurve = { "FadeTimelineCurve", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AZEDPlayerController, FadeTimelineCurve), Z_Construct_UClass_UCurveFloat_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimelineCurve_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimelineCurve_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AZEDPlayerController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PawnClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPawnSpawned,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_OnPreZedCameraOpening,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedPawn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ZedCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseDefaultBeginPlay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bOpenZedCameraAtInit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bStereoRenderingSupport,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bIsFirstPlayer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bUseShowOnlyList,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_bHideWorldOpeningZedCamera,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_ViewportHelper,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessFadeSourceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedMaterialInstanceDynamic,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_PostProcessZedSourceMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimeline,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AZEDPlayerController_Statics::NewProp_FadeTimelineCurve,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AZEDPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AZEDPlayerController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AZEDPlayerController_Statics::ClassParams = {
		&AZEDPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AZEDPlayerController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AZEDPlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AZEDPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AZEDPlayerController()
	{
		if (!Z_Registration_Info_UClass_AZEDPlayerController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AZEDPlayerController.OuterSingleton, Z_Construct_UClass_AZEDPlayerController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AZEDPlayerController.OuterSingleton;
	}
	template<> ZED_API UClass* StaticClass<AZEDPlayerController>()
	{
		return AZEDPlayerController::StaticClass();
	}

	void AZEDPlayerController::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_ZedPawn(TEXT("ZedPawn"));

		const bool bIsValid = true
			&& Name_ZedPawn == ClassReps[(int32)ENetFields_Private::ZedPawn].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AZEDPlayerController"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AZEDPlayerController);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AZEDPlayerController, AZEDPlayerController::StaticClass, TEXT("AZEDPlayerController"), &Z_Registration_Info_UClass_AZEDPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AZEDPlayerController), 3974920493U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_2610013594(TEXT("/Script/ZED"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_ZED_Public_Core_ZEDPlayerController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
