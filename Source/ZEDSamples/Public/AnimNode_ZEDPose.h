// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Animation/AnimNodeBase.h"

#include "CoreMinimal.h"
#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"


#include "AnimNode_ZEDPose.generated.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

USTRUCT(BlueprintInternalUseOnly)
struct ZEDSAMPLES_API FAnimNode_ZEDPose : public FAnimNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	FPoseLink InputPose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	FSlObjectData ObjectData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	TMap<FName, FName> RemapAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	bool bMirrorOnZAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	float HeightOffset;

	/** Pose smoothing*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	float SlerpIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	USkeletalMeshComponent* SkeletalMesh;

public:
	FAnimNode_ZEDPose();

	//~ FAnimNode_Base interface
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext & Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext & Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	virtual bool HasPreUpdate() const { return true; }
	virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	//~ End of FAnimNode_Base interface

	bool Serialize(FArchive& Ar);
protected:
	virtual void OnInitializeAnimInstance(const FAnimInstanceProxy* InProxy, const UAnimInstance* InAnimInstance) override;

private:
	void BuildPoseFromSlObjectData(FCompactPose& OutPose);
	float ComputeRootTranslationFactor(FCompactPose& OutPose, const FSlObjectData& InObjectData);
	void PropagateRestPoseRotations(int32 parentIdx, FCompactPose& OutPose, FQuat restPoseRot, bool inverse);
	void PutInRefPose(FCompactPose& OutPose, TArray<FName> SourceBoneNames);
	FCompactPoseBoneIndex GetCPIndex(int32 idx, FCompactPose& OutPose);

	// This is the bone we will apply position translation to.
	// The root in our case is the pelvis (0)
	FName GetTargetRootName() const { return "PELVIS"; }

	float FeetOffset;
	// factor used to computer foot offset over time.
	float Alpha;

	// Used for slerping rotations to avoid stuttering
	TArray<FQuat> PreviousRotations;
	FVector PreviousRootPosition;
	FQuat PreviousRootRotation;	
	bool PrevDataInitialized;

};

PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> struct TStructOpsTypeTraits<FAnimNode_ZEDPose> : public TStructOpsTypeTraitsBase2<FAnimNode_ZEDPose>
{
	enum
	{
		WithSerializer = true
	};
};
