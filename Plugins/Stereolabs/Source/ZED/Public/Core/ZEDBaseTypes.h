//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"

#include "ZEDBaseTypes.generated.h"


/*
 * Tracking data of the camera
 */
USTRUCT(BlueprintType, Category = "ZED|Struct")
struct ZED_API FZEDTrackingData
{
	GENERATED_BODY()

	FZEDTrackingData()
		:
		TrackingState(ESlTrackingState::TS_TrackingOff),
		Timestamp((sl::Timestamp)0),
		OffsetZedWorldTransform(FTransform::Identity),
		ZedWorldTransform(FTransform::Identity),
		ZedPathTransform(FTransform::Identity),
		IMURotator(FRotator::ZeroRotator)
	{
	}

	/** Tracking state */
	UPROPERTY(BlueprintReadWrite)
	ESlTrackingState TrackingState;

	/** Timestamp */
	UPROPERTY(BlueprintReadWrite)
	FSlTimestamp Timestamp;

	/**	Zed world space transform relative to the head with anti drift if using an HMD */
	UPROPERTY(BlueprintReadWrite)
	FTransform OffsetZedWorldTransform;

	/** Zed world space transform with anti drift if using an HMD */
	UPROPERTY(BlueprintReadWrite)
	FTransform ZedWorldTransform;

	/** Raw path transform from tracking origin */
	UPROPERTY(BlueprintReadWrite)
	FTransform ZedPathTransform;	

	/** IMU rotation */
	UPROPERTY(BlueprintReadWrite)
	FRotator IMURotator;
};

/*
 * Result of a hit test
 */
USTRUCT(BlueprintType, Category = "ZED|Struct")
struct ZED_API FZEDHitResult
{
	GENERATED_BODY()

	FZEDHitResult()
		:
		Location(FVector::ZeroVector),
		ImpactPoint(FVector::ZeroVector),
		Normal(FVector::ZeroVector),
		Depth(-1.0f),
		Distance(0.0f),
		bIsVisible(false),
		bIsBehind(false),
		bNormalValid(false)
	{
	}

	FORCEINLINE void Reset()
	{
		Location = FVector::ZeroVector;
		ImpactPoint = FVector::ZeroVector;
		Normal = FVector::ZeroVector;
		Depth = -1.0f;
		Distance = 0.0f;
		bIsVisible = false;
		bIsBehind = false;
		bNormalValid = false;
	}

	/** Location of the hit in world space */
	UPROPERTY(BlueprintReadWrite)
	FVector Location = FVector::ZeroVector;

	/** Location of the actual contact point. Equal the tested world location. */
	UPROPERTY(BlueprintReadWrite)
	FVector ImpactPoint = FVector::ZeroVector;

	/** Normal of the hit in world space */
	UPROPERTY(BlueprintReadWrite)
	FVector Normal = FVector::ZeroVector;

	/** The depth of the hit */
	UPROPERTY(BlueprintReadWrite)
	float Depth = -1.0f;

	/** The distance from the hit location to the player */
	UPROPERTY(BlueprintReadWrite)
	float Distance = 0.0f;

	/** True if the location is visible by the player */
	UPROPERTY(BlueprintReadWrite)
	bool bIsVisible = false;

	/* True if the ImpactPoint is behind real.
	 * Always false if hit test "bHitIfBehind" set to false.
	 */
	UPROPERTY(BlueprintReadWrite)
	bool bIsBehind = false;

	/** True if the normal is valid */
	UPROPERTY(BlueprintReadWrite)
	bool bNormalValid = false;
};

/*
 * RGB noise factors
 */
struct ZED_API FZEDNoiseFactors
{
	FZEDNoiseFactors()
		:
		R(FVector2D::ZeroVector),
		G(FVector2D::ZeroVector),
		B(FVector2D::ZeroVector)
	{
	}

	FZEDNoiseFactors(const FVector2D& R,
		const FVector2D& G, 
		const FVector2D& B)
		:
		R(R),
		G(G),
		B(B)
	{
	}

	bool IsZeroed()
	{
		return R == FVector2D::ZeroVector && G == FVector2D::ZeroVector && B == FVector2D::ZeroVector;
	}

	FVector2D R;
	FVector2D G;
	FVector2D B;
};

/*
 * Camera calibration for external view
 */
USTRUCT(BlueprintType, Category = "ZED|Struct")
struct ZED_API FZEDExternalViewParameters
{
	GENERATED_BODY()

	FZEDExternalViewParameters(FVector Location = FVector::ZeroVector, FRotator Rotation = FRotator::ZeroRotator)
		:
		Location(Location),
		Rotation(Rotation)
	{
	}

	FORCEINLINE void Load(const FString& Path, const TCHAR* Section = TEXT("Calibration"))
	{
		float X;
		float Y;
		float Z;
		float Yaw;
		float Pitch;
		float Roll;

		GConfig->GetFloat(
			Section,
			TEXT("x"),
			X,
			*Path
			);
		GConfig->GetFloat(
			Section,
			TEXT("y"),
			Y,
			*Path
			);
		GConfig->GetFloat(
			Section,
			TEXT("z"),
			Z,
			*Path
			);

		GConfig->GetFloat(
			Section,
			TEXT("rx"),
			Pitch,
			*Path
			);
		GConfig->GetFloat(
			Section,
			TEXT("ry"),
			Yaw,
			*Path
			);
		GConfig->GetFloat(
			Section,
			TEXT("rz"),
			Roll,
			*Path
			);

		Location = FVector(Z, X, Y) * 100.0f;
		Rotation = FRotator(-Pitch, Yaw, Roll);
	}

	FVector Location;
	FRotator Rotation;
};