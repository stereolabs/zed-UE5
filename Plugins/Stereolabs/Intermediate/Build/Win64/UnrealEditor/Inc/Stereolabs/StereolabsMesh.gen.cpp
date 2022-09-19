// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Stereolabs/Public/Core/StereolabsMesh.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStereolabsMesh() {}
// Cross Module References
	STEREOLABS_API UClass* Z_Construct_UClass_USlMesh_NoRegister();
	STEREOLABS_API UClass* Z_Construct_UClass_USlMesh();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_Stereolabs();
	STEREOLABS_API UScriptStruct* Z_Construct_UScriptStruct_FSlMeshFilterParameters();
	STEREOLABS_API UEnum* Z_Construct_UEnum_Stereolabs_ESlMeshFileFormat();
// End Cross Module References
	DEFINE_FUNCTION(USlMesh::execClear)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Clear();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMesh::execLoad)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_UBOOL(Z_Param_bUpdateChunksOnly);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Load(Z_Param_FilePath,Z_Param_bUpdateChunksOnly);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMesh::execSave)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_TARRAY_REF(int32,Z_Param_Out_ChunksIDs);
		P_GET_ENUM(ESlMeshFileFormat,Z_Param_FileFormat);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Save(Z_Param_FilePath,Z_Param_Out_ChunksIDs,ESlMeshFileFormat(Z_Param_FileFormat));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMesh::execApplyTexture)
	{
		P_GET_UBOOL(Z_Param_bSRGB);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->ApplyTexture(Z_Param_bSRGB);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMesh::execFilter)
	{
		P_GET_STRUCT_REF(FSlMeshFilterParameters,Z_Param_Out_MeshFilterParameters);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->Filter(Z_Param_Out_MeshFilterParameters);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USlMesh::execUpdateMeshData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateMeshData();
		P_NATIVE_END;
	}
	void USlMesh::StaticRegisterNativesUSlMesh()
	{
		UClass* Class = USlMesh::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyTexture", &USlMesh::execApplyTexture },
			{ "Clear", &USlMesh::execClear },
			{ "Filter", &USlMesh::execFilter },
			{ "Load", &USlMesh::execLoad },
			{ "Save", &USlMesh::execSave },
			{ "UpdateMeshData", &USlMesh::execUpdateMeshData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USlMesh_ApplyTexture_Statics
	{
		struct SlMesh_eventApplyTexture_Parms
		{
			bool bSRGB;
			bool ReturnValue;
		};
		static void NewProp_bSRGB_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSRGB;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_bSRGB_SetBit(void* Obj)
	{
		((SlMesh_eventApplyTexture_Parms*)Obj)->bSRGB = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_bSRGB = { "bSRGB", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMesh_eventApplyTexture_Parms), &Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_bSRGB_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlMesh_eventApplyTexture_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMesh_eventApplyTexture_Parms), &Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_bSRGB,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n     * Applies texture to the mesh.\n\x09 *\n\x09 * By using this function you will get access to UV0 and Texture.\n\x09 * The number of triangles in the mesh may slightly differ before and after calling this functions due to missing texture informations.\n\x09 * There is only one texture for the mesh, the uv of each chunks are expressed for it in its globality.\n\x09 * Vectors of vertices/normals and uv have now the same size.\n\x09 *\n\x09 * @param bSRGB         True if texture must be SRGB, usefull if you want to create a cubemap from the mesh\n\x09 * @return\x09\x09\x09\x09True if the texturing was successful, false otherwise.\n     *\n\x09 * This function can be call as long as you do not start a new spatial mapping process, due to shared memory.\n\x09 * This function can require a lot of computation time depending on the number of triangles in the mesh. Its recommended to call it once a the end of your spatial mapping process.\n\x09 *  \n\x09 * The bSaveTexture parameter in FSlSpatialMappingParameters must be set as true when enabling the spatial mapping to be able to apply the textures.\n\x09 * The mesh should be filtered before calling this function since filter will erased the textures, the texturing is also significantly slower on non-filtered meshes.\n\x09 *\n\x09 * If not called in the render thread you must call MeshData.Texture->UpdateResource()\n\x09 */" },
		{ "CPP_Default_bSRGB", "false" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
		{ "ToolTip", "* Applies texture to the mesh.\n   *\n   * By using this function you will get access to UV0 and Texture.\n   * The number of triangles in the mesh may slightly differ before and after calling this functions due to missing texture informations.\n   * There is only one texture for the mesh, the uv of each chunks are expressed for it in its globality.\n   * Vectors of vertices/normals and uv have now the same size.\n   *\n   * @param bSRGB         True if texture must be SRGB, usefull if you want to create a cubemap from the mesh\n   * @return                              True if the texturing was successful, false otherwise.\n*\n   * This function can be call as long as you do not start a new spatial mapping process, due to shared memory.\n   * This function can require a lot of computation time depending on the number of triangles in the mesh. Its recommended to call it once a the end of your spatial mapping process.\n   *\n   * The bSaveTexture parameter in FSlSpatialMappingParameters must be set as true when enabling the spatial mapping to be able to apply the textures.\n   * The mesh should be filtered before calling this function since filter will erased the textures, the texturing is also significantly slower on non-filtered meshes.\n   *\n   * If not called in the render thread you must call MeshData.Texture->UpdateResource()" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMesh, nullptr, "ApplyTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::SlMesh_eventApplyTexture_Parms), Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMesh_ApplyTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMesh_ApplyTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMesh_Clear_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Clear_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n     * Clears all the data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
		{ "ToolTip", "* Clears all the data." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMesh_Clear_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMesh, nullptr, "Clear", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Clear_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Clear_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMesh_Clear()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMesh_Clear_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMesh_Filter_Statics
	{
		struct SlMesh_eventFilter_Parms
		{
			FSlMeshFilterParameters MeshFilterParameters;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshFilterParameters_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_MeshFilterParameters;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_MeshFilterParameters_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_MeshFilterParameters = { "MeshFilterParameters", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMesh_eventFilter_Parms, MeshFilterParameters), Z_Construct_UScriptStruct_FSlMeshFilterParameters, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_MeshFilterParameters_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_MeshFilterParameters_MetaData)) }; // 2013812210
	void Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlMesh_eventFilter_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMesh_eventFilter_Parms), &Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMesh_Filter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_MeshFilterParameters,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Filter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Filter_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "MeshFilterParameters" },
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n \x09 * Filters the mesh.\n\x09 *\n\x09 * The resulting mesh in smoothed, small holes are filled and small blobs of non connected triangles are deleted.\n     * \n\x09 * @param MeshFilterParameters The filtering parameters\n     * @return True if the filtering was successful, false otherwise.\n     *\n\x09 * The filtering is a costly operation, its not recommended to call it every time you retrieve a mesh but at the end of your spatial mapping process.\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
		{ "ToolTip", "* Filters the mesh.\n*\n* The resulting mesh in smoothed, small holes are filled and small blobs of non connected triangles are deleted.\n*\n* @param MeshFilterParameters The filtering parameters\n* @return True if the filtering was successful, false otherwise.\n*\n* The filtering is a costly operation, its not recommended to call it every time you retrieve a mesh but at the end of your spatial mapping process." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMesh_Filter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMesh, nullptr, "Filter", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMesh_Filter_Statics::SlMesh_eventFilter_Parms), Z_Construct_UFunction_USlMesh_Filter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Filter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Filter_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Filter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMesh_Filter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMesh_Filter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMesh_Load_Statics
	{
		struct SlMesh_eventLoad_Parms
		{
			FString FilePath;
			bool bUpdateChunksOnly;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static void NewProp_bUpdateChunksOnly_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUpdateChunksOnly;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMesh_eventLoad_Parms, FilePath), METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_FilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_FilePath_MetaData)) };
	void Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_bUpdateChunksOnly_SetBit(void* Obj)
	{
		((SlMesh_eventLoad_Parms*)Obj)->bUpdateChunksOnly = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_bUpdateChunksOnly = { "bUpdateChunksOnly", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMesh_eventLoad_Parms), &Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_bUpdateChunksOnly_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlMesh_eventLoad_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMesh_eventLoad_Parms), &Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMesh_Load_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_bUpdateChunksOnly,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Load_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Load_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Loads the mesh from a file.\n     * @param FilePath\x09\x09    The path and filename of the mesh (do not forget the extension).\n\x09 * @param bUpdateChunksOnly If set to false the mesh data (vertices/normals/triangles) are updated otherwise only the chunks data are updated. default : false.\n\x09 * @return\x09\x09\x09\x09    True if the loading was successful, false otherwise.\n\x09 */" },
		{ "CPP_Default_bUpdateChunksOnly", "false" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
		{ "ToolTip", "* Loads the mesh from a file.\n* @param FilePath             The path and filename of the mesh (do not forget the extension).\n* @param bUpdateChunksOnly If set to false the mesh data (vertices/normals/triangles) are updated otherwise only the chunks data are updated. default : false.\n* @return                                  True if the loading was successful, false otherwise." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMesh_Load_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMesh, nullptr, "Load", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMesh_Load_Statics::SlMesh_eventLoad_Parms), Z_Construct_UFunction_USlMesh_Load_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Load_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Load_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Load_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMesh_Load()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMesh_Load_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMesh_Save_Statics
	{
		struct SlMesh_eventSave_Parms
		{
			FString FilePath;
			TArray<int32> ChunksIDs;
			ESlMeshFileFormat FileFormat;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ChunksIDs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChunksIDs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ChunksIDs;
		static const UECodeGen_Private::FBytePropertyParams NewProp_FileFormat_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_FileFormat;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMesh_eventSave_Parms, FilePath), METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FilePath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FilePath_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs_Inner = { "ChunksIDs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs = { "ChunksIDs", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMesh_eventSave_Parms, ChunksIDs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FileFormat_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FileFormat = { "FileFormat", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SlMesh_eventSave_Parms, FileFormat), Z_Construct_UEnum_Stereolabs_ESlMeshFileFormat, METADATA_PARAMS(nullptr, 0) }; // 1271737075
	void Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SlMesh_eventSave_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(SlMesh_eventSave_Parms), &Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USlMesh_Save_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ChunksIDs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FileFormat_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_FileFormat,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USlMesh_Save_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_Save_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ChunksIDs" },
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Saves the current Mesh into a file.\n\x09 * @param FilePath   the path and filename of the mesh\n\x09 * @param ChunksIDs  Specify a set of chunks to be saved, if none provided alls chunks are saved\n\x09 * @param FileFormat The file type (extension). default : MESH_FILE_OBJ.\n\x09 * @return\x09\x09\x09 True if the file was successfully saved, false otherwise.\n\x09 *\n\x09 * Only ESlMeshFileFormat::MFF_OBJ support textures data.\n\x09 * This function operate on the Mesh not on the chunks. This way you can save different parts of your Mesh (update your Mesh with UpdateMeshFromChunks).\n\x09 */" },
		{ "CPP_Default_FileFormat", "MFF_OBJ" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
		{ "ToolTip", "* Saves the current Mesh into a file.\n* @param FilePath   the path and filename of the mesh\n* @param ChunksIDs  Specify a set of chunks to be saved, if none provided alls chunks are saved\n* @param FileFormat The file type (extension). default : MESH_FILE_OBJ.\n* @return                       True if the file was successfully saved, false otherwise.\n*\n* Only ESlMeshFileFormat::MFF_OBJ support textures data.\n* This function operate on the Mesh not on the chunks. This way you can save different parts of your Mesh (update your Mesh with UpdateMeshFromChunks)." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMesh_Save_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMesh, nullptr, "Save", nullptr, nullptr, sizeof(Z_Construct_UFunction_USlMesh_Save_Statics::SlMesh_eventSave_Parms), Z_Construct_UFunction_USlMesh_Save_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Save_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_Save_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_Save_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMesh_Save()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMesh_Save_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USlMesh_UpdateMeshData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USlMesh_UpdateMeshData_Statics::Function_MetaDataParams[] = {
		{ "Category", "Stereolabs" },
		{ "Comment", "/*\n\x09 * Updates the mesh data from underlying mesh.\n\x09 * Call this function after UpdateMeshFromChunks, Load, Filter, ApplyTexture\n\x09 */" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
		{ "ToolTip", "* Updates the mesh data from underlying mesh.\n* Call this function after UpdateMeshFromChunks, Load, Filter, ApplyTexture" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USlMesh_UpdateMeshData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USlMesh, nullptr, "UpdateMeshData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USlMesh_UpdateMeshData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USlMesh_UpdateMeshData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USlMesh_UpdateMeshData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USlMesh_UpdateMeshData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USlMesh);
	UClass* Z_Construct_UClass_USlMesh_NoRegister()
	{
		return USlMesh::StaticClass();
	}
	struct Z_Construct_UClass_USlMesh_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USlMesh_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_Stereolabs,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USlMesh_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USlMesh_ApplyTexture, "ApplyTexture" }, // 1380990179
		{ &Z_Construct_UFunction_USlMesh_Clear, "Clear" }, // 64151374
		{ &Z_Construct_UFunction_USlMesh_Filter, "Filter" }, // 4229231887
		{ &Z_Construct_UFunction_USlMesh_Load, "Load" }, // 3506540754
		{ &Z_Construct_UFunction_USlMesh_Save, "Save" }, // 3276051450
		{ &Z_Construct_UFunction_USlMesh_UpdateMeshData, "UpdateMeshData" }, // 2421118924
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USlMesh_Statics::Class_MetaDataParams[] = {
		{ "Category", "Stereolabs|Texture" },
		{ "IncludePath", "Core/StereolabsMesh.h" },
		{ "ModuleRelativePath", "Public/Core/StereolabsMesh.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USlMesh_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USlMesh>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USlMesh_Statics::ClassParams = {
		&USlMesh::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USlMesh_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USlMesh_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USlMesh()
	{
		if (!Z_Registration_Info_UClass_USlMesh.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USlMesh.OuterSingleton, Z_Construct_UClass_USlMesh_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USlMesh.OuterSingleton;
	}
	template<> STEREOLABS_API UClass* StaticClass<USlMesh>()
	{
		return USlMesh::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USlMesh);
	struct Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USlMesh, USlMesh::StaticClass, TEXT("USlMesh"), &Z_Registration_Info_UClass_USlMesh, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USlMesh), 3722880820U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_375288718(TEXT("/Script/Stereolabs"),
		Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_zed_UE5_Plugins_Stereolabs_Source_Stereolabs_Public_Core_StereolabsMesh_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
