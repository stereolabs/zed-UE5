//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once
#include "Engine.h"
#include "kismet/BlueprintFunctionLibrary.h"

#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

#include "Windows/AllowWindowsPlatformTypes.h"
#include <sl/Camera.hpp>
#include "Windows/HideWindowsPlatformTypes.h"

#include "StereolabsMatFunctionLibrary.generated.h"

UCLASS(BlueprintType)
class STEREOLABS_API USlMatFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*
	 * Allocates the Mat memory
	 * @param Resolution The size of the matrix in pixels
	 * @param Type		 The type of the matrix (ESlMatType::MT_32F_C1, ESlMatType::MT__8U_C4)
	 * @param MemoryType Defines where the buffer will be stored (sl::MEM_CPU and/or sl::MEM_GPU)
	 * @warning			 It erases previously allocated memory
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static void Allocate(UPARAM(ref) FSlMat& Mat, const FIntPoint& Resolution, ESlMatType Type, UPARAM(DisplayName = "MemoryType", meta = (Bitmask, BitmaskEnum = ESlMemoryType)) ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		checkf(GSlCameraProxy && GSlCameraProxy->IsCameraOpened(), TEXT("Camera must be opened before allocating a Mat"));

		sl_mat_alloc(Mat.Mat, Resolution.X, Resolution.Y, (SL_MAT_TYPE)Type, (SL_MEM)MemoryType);
	}

	/*
	 * Free the owned memory
	 * @param MemoryType Specify whether you want to free the  MEM_CPU and/or  MEM_GPU memory
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static void Free(UPARAM(ref) FSlMat& Mat, UPARAM(DisplayName = "MemoryType", meta = (Bitmask, BitmaskEnum = ESlMemoryType)) ESlMemoryType MemoryType)
	{
		sl_mat_free(Mat.Mat, (SL_MEM)MemoryType);
	}

	/*
	 * Downloads data from DEVICE (GPU) to HOST (CPU), if possible
	 * @return  EC_Success if everything went well,  EC_Failure otherwise
	 * @note If no CPU or GPU memory are available for this Mat, some are directly allocated
	 * @note If verbose sets, you have informations in case of failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode UpdateCPUFromGPU(UPARAM(ref) FSlMat& Mat)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_update_cpu_from_gpu(Mat.Mat));
	}

	/*
	 * Uploads data from HOST (CPU) to DEVICE (GPU), if possible
	 * @return  EC_Success if everything went well,  EC_Failure otherwise
	 * @note If no CPU or GPU memory are available for this Mat, some are directly allocated
	 * @note If verbose sets, you have informations in case of failure
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode UpdateGPUFromCPU(UPARAM(ref) FSlMat& Mat)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_update_gpu_from_cpu(Mat.Mat));
	}

	/*
	 * Copies data in other Mat (deep copy)
	 * @param Dst	   The Mat where the data will be copied
	 * @param CopyType Specify the memories that will be used for the copy
	 * @return		   EC_Success if everything went well,  EC_Failure otherwise
	 * @note If the Destination is not allocated or has a not a compatible  MAT_TYPE or  Resolution,
	 * current memory is freed and new memory is directly allocated
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
		static ESlErrorCode CopyTo(const  FSlMat& Mat, UPARAM(ref) FSlMat& Dst, ESlCopyType CopyType = ESlCopyType::CT_CPUToCPU)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_copy_to(Mat.Mat, Dst.Mat, (SL_COPY_TYPE)CopyType));
	}

	/*
	 * Copies data from an other Mat (deep copy)
	 * @param Src	   The Mat where the data will be copied from
	 * @param CopyType Specify the memories that will be used for the update
	 * @return		   EC_Success if everything went well,  EC_Failure otherwise
	 * @note If the current Mat is not allocated or has a not a compatible  MAT_TYPE or  Resolution with the Src,
	 * current memory is freed and new memory is directly allocated
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetFrom(UPARAM(ref) FSlMat& Mat, const FSlMat& Src, ESlCopyType CopyType = ESlCopyType::CT_CPUToCPU)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_set_from(Mat.Mat, Src.Mat, (SL_COPY_TYPE)CopyType));
	}

	/*
	 * Reads an image from a file (only if  MEM_CPU is available on the current  Mat).
	 * Supported input files format are PNG and JPEG
	 * @param Path File path including the name and extension
	 * @return     EC_Success if everything went well,  EC_Failure otherwise
	 * @note Supported ESlMatType are : MT_8U_C1,  MT_8U_C3 and  MT_8U_C4
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode Read(UPARAM(ref) FSlMat& Mat, const FString& Path)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_read(Mat.Mat, (TCHAR_TO_UTF8(*Path))));
	}

	/*
	 * Writes the  Mat (only if  MEM_CPU is available) into a file as an image
	 * Supported output files format are PNG and JPEG
	 * @param Path File path including the name and extension
	 * @return	   EC_Success if everything went well,  EC_Failure otherwise
	 * @note Supported  ESlMatType are : MT_8U_C1,  MT_8U_C3 and  MT_8U_C4
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode Write(UPARAM(ref) FSlMat& Mat, const FString& Path)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_write(Mat.Mat, (TCHAR_TO_UTF8(*Path))));
	}

	//TODO
	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFloat(UPARAM(ref) FSlMat& Mat, float Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return (ESlErrorCode)sl_mat_set_to(Value, sl::unreal::ToSlType(MemoryType)));
	}

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFVector2D(UPARAM(ref) FSlMat& Mat, const FVector2D& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFVector(UPARAM(ref) FSlMat& Mat, const FVector& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFVector4(UPARAM(ref) FSlMat& Mat, const FVector4& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * Clamped to (0, 255) and converted to sl::uchar.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToInt32(UPARAM(ref) FSlMat& Mat, int32 Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(static_cast<sl::uchar1>(FMath::Clamp(Value, 0, 255)), sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * Clamped to (0, 255) and converted to sl::uchar2.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFIntPoint(UPARAM(ref) FSlMat& Mat, const FIntPoint& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		sl::uchar2 SlValue(FMath::Clamp(Value.X, 0, 255), FMath::Clamp(Value.Y, 0, 255));
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(SlValue, sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * Clamped to (0, 255) and converted to sl::uchar3.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFIntVector(UPARAM(ref) FSlMat& Mat, const FIntVector& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Fills the Mat with the given value.
	 * This function overwrite all the matrix.
	 * Converted to sl::uchar4.
	 * @param Value      The value to be copied all over the matrix
	 * @param MemoryType Defines which buffer to fill, CPU and/or GPU
	 * @return		     EC_Success if everything went well, EC_Failure otherwise.
	 */
	/*UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode SetToFColor(UPARAM(ref) FSlMat& Mat, const FColor& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return sl::unreal::ToUnrealType(Mat.Mat.setTo(sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	}*/

	/*
	 * Sets a value to a specific point in the matrix.
	 * @param Coordinates The coordinate to write to.
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFloat(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, float Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, Value, sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * @param Coordinates The coordinate to write to
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFVector2D(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, const FVector2D& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * @param Coordinates The coordinate to write to
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFVector(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, const FVector& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * @param Coordinates The coordinate to write to
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFVector4(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, const FVector4& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * @param Coordinates The coordinate to write to.
	 * Clamped to (0, 255) and converted to sl::uchar.
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueInt32(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, int32 Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, static_cast<sl::uchar1>(FMath::Clamp(Value, 0, 255)), sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * Clamped to (0, 255) and converted to sl::uchar2.
	 * @param Coordinates The coordinate to write to
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFIntPoint(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, const FIntPoint& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::uchar2 SLValue(FMath::Clamp(Value.X, 0, 255), FMath::Clamp(Value.Y, 0, 255));
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, SLValue, sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * Clamped to (0, 255) and converted to sl::uchar3.
	 * @param Coordinates The coordinate to write to
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFIntVector(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, const FIntVector& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Sets a value to a specific point in the matrix.
	 * Converted to sl::uchar4.
	 * @param Coordinates The coordinate to write to
	 * @param Value		  The value to be set
	 * @param MemoryType  Defines which memory will be updated
	 * @return			  EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	//static ESlErrorCode SetValueFColor(UPARAM(ref) FSlMat& Mat, const FIntPoint& Coordinates, const FColor& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.setValue(Coordinates.X, Coordinates.Y, sl::unreal::ToSlType(Value), sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFloat(const FSlMat& Mat, const FIntPoint& Coordinates, float& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	return sl::unreal::ToUnrealType(Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &Value, sl::unreal::ToSlType(MemoryType)));
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFVector2D(const FSlMat& Mat, const FIntPoint& Coordinates, FVector2D& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::float2 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = sl::unreal::ToUnrealType(SlValue);

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFVector(const FSlMat& Mat, const FIntPoint& Coordinates, FVector& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::float3 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = sl::unreal::ToUnrealType(SlValue);

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFVector4(const FSlMat& Mat, const FIntPoint& Coordinates, FVector4& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::float4 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = sl::unreal::ToUnrealType(SlValue);

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueInt32(const FSlMat& Mat, const FIntPoint& Coordinates, int32& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::uchar1 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = (int32)SlValue;

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFIntPoint(const FSlMat& Mat, const FIntPoint& Coordinates, FIntPoint& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::uchar2 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = sl::unreal::ToUnrealType(SlValue);

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	// */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFIntVector(const FSlMat& Mat, const FIntPoint& Coordinates, FIntVector& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::uchar3 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = sl::unreal::ToUnrealType(SlValue);

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the value of a specific point in the matrix.
	 * @param Coordinates The coordinate to read from
	 * @param MemoryType  Defines which memory should be read.
	 * @return EC_Success if everything went well, EC_Failure otherwise.
	 *
	 * @warning Not efficient for  MEM_GPU, use it on sparse data.
	 */
	//UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	//static ESlErrorCode GetValueFColor(const FSlMat& Mat, const FIntPoint& Coordinates, FColor& Value, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	//{
	//	sl::uchar4 SlValue;
	//	sl::ERROR_CODE ErrorCode = Mat.Mat.getValue(static_cast<size_t>(Coordinates.X), static_cast<size_t>(Coordinates.Y), &SlValue, sl::unreal::ToSlType(MemoryType));

	//	Value = sl::unreal::ToUnrealType(SlValue);

	//	return sl::unreal::ToUnrealType(ErrorCode);
	//}

	/*
	 * Returns the width of the matrix
	 * @return The width of the matrix in pixels
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static  int32 GetWidth(const FSlMat& Mat)
	{
		return static_cast<int32>(sl_mat_get_width(Mat.Mat));
	}

	/*
	 * Returns the height of the matrix
	 * @return The height of the matrix in pixels
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static int32 GetHeight(const FSlMat& Mat)
	{
		return static_cast<int32>(sl_mat_get_height(Mat.Mat));
	}

	/*
	 * Returns the height of the matrix
	 * @return The height of the matrix in pixels
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static FIntPoint GetResolution(const FSlMat& Mat)
	{
		return sl::unreal::ToUnrealType(sl_mat_get_resolution(Mat.Mat));
	}
	/*
	 * Returns the number of values stored in one pixel
	 * @return The number of values in a pixel
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static int32 GetChannels(const FSlMat& Mat)
	{
		return static_cast<int32>(sl_mat_get_channels(Mat.Mat));
	}

	/*
	 * Returns the format of the matrix
	 * @return The format of the current Mat
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static ESlMatType GetDataType(const FSlMat& Mat)
	{
		return (ESlMatType)sl_mat_get_data_type(Mat.Mat);
	}

	/*
	 * Returns the type of memory (CPU and/or GPU)
	 * @return The type of allocated memory
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static ESlMemoryType GetMemoryType(const FSlMat& Mat)
	{
		return (ESlMemoryType)sl_mat_get_memory_type(Mat.Mat);
	}

	/*
	 * Returns the memory step in Bytes (the Bytes size of one pixel row)
	 * @param MemoryTYpe Specify whether you want  MEM_CPU or  MEM_GPU step
	 * @return The step in bytes of the specified memory
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static int32 GetStepBytes(const FSlMat& Mat, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return static_cast<int32>(sl_mat_get_step_bytes(Mat.Mat, (SL_MEM)MemoryType));
	}

	/*
	 * Returns the size in bytes of one pixel
	 * @return The size in bytes of a pixel
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static int32 GetPixelBytes(const FSlMat& Mat)
	{
		return static_cast<int32>(sl_mat_get_pixel_bytes(Mat.Mat));
	}

	/*
	 * Returns the memory step in number of elements (the number of values in one pixel row)
	 * @param MemoryType Specify whether you want  MEM_CPU or  MEM_GPU step
	 * @return			  The step in number of elements.
	 */
	inline int32 getStep(const FSlMat& Mat, ESlMemoryType MemoryType = ESlMemoryType::MT_CPU)
	{
		return static_cast<int32>(sl_mat_get_step(Mat.Mat, (SL_MEM)MemoryType));
	}

	/*
	 * Returns the size in bytes of a row
	 * @return The size in bytes of a row
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static int32 getWidthBytes(const FSlMat& Mat)
	{
		return GetPixelBytes(Mat) * GetWidth(Mat);
	}

	/*
	 * Returns the informations about the Mat into a FString
	 * @return A string containing the Mat informations
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static FString GetInfos(UPARAM(ref) FSlMat& Mat)
	{
		char* buffer = new char[128];
		sl_mat_get_infos(Mat.Mat, buffer);

		FString output = FString(buffer);
		delete(buffer);
		return output;		
	}

	/*
	 * Defines whether the Mat is initialized or not
	 * @return True if current Mat has been allocated (by the constructor or therefore)
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static bool IsInit(const FSlMat& Mat)
	{
		return sl_mat_is_init(Mat.Mat);
	}

	/*
	 * Returns whether the Mat is the owner of the memory it access
	 * If not, the memory won't be freed if the Mat is destroyed
	 * @return True if the Mat is owning its memory, else false
	 */
	UFUNCTION(BlueprintPure, Category = "Stereolabs|Mat")
	static bool IsMemoryOwner(const FSlMat& Mat)
	{
		return sl_mat_is_memory_owner(Mat.Mat);
	}

	/*
	 * Duplicates Mat by copy (deep copy)
	 * @param Src The reference to the Mat to copy
	 * This function copies the data array(s), it mark the new Mat as the memory owner
	 */
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Mat")
	static ESlErrorCode Clone(UPARAM(ref) FSlMat& Mat, UPARAM(ref) FSlMat& Src)
	{
		return sl::unreal::ToUnrealType((SL_ERROR_CODE)sl_mat_clone(Mat.Mat, Src.Mat));
	}
};
