// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Animation/AnimNodeBase.h"

#include "CoreMinimal.h"
#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"

#include <deque>
#include <algorithm>

#include "AnimNode_ZEDPose.generated.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

USTRUCT(BlueprintInternalUseOnly)
struct ZED_API FAnimNode_ZEDPose : public FAnimNode_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	FPoseLink InputPose;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	FSlBodyData BodyData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	TMap<FName, FName> RemapAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	bool bMirrorOnZAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	float HeightOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	bool bStickAvatarOnFloor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	bool bEnableBoneScaling;

	/** Pose smoothing*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	float RotationSlerpIntensity;

	/** Pose smoothing*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	FVector RootLocationSlerpIntensity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	USkeletalMeshComponent* SkeletalMesh;

public:
	FAnimNode_ZEDPose();

	//~ FAnimNode_Base interface
	virtual void Initialize_AnyThread(const FAnimationInitializeContext& Context) override;
	virtual void CacheBones_AnyThread(const FAnimationCacheBonesContext & Context) override;
	virtual void Update_AnyThread(const FAnimationUpdateContext & Context) override;
	virtual void Evaluate_AnyThread(FPoseContext& Output) override;
	//virtual void EvaluateComponentSpace_AnyThread(FComponentSpacePoseContext& Output) final;
	virtual bool HasPreUpdate() const { return true; }
	virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	//~ End of FAnimNode_Base interface

	bool Serialize(FArchive& Ar);
protected:
	virtual void OnInitializeAnimInstance(const FAnimInstanceProxy* InProxy, const UAnimInstance* InAnimInstance) override;

private:
	void BuildPoseFromSlBodyData(FPoseContext& PoseContext);
	//void BuildPoseFromSlObjectData(FComponentSpacePoseContext& PoseContext);

	void PropagateRestPoseRotations(int32 parentIdx, FCompactPose& OutPose, FQuat restPoseRot, bool inverse);
	void PutInRefPose(FCompactPose& OutPose, TArray<FName> SourceBoneNames);
	FCompactPoseBoneIndex GetCPIndex(int32 idx, FCompactPose& OutPose);

	// This is the bone we will apply position translation to.
	// The root in our case is the pelvis (0)
	FName GetTargetRootName() const { return "PELVIS"; }

    int NbKeypoints = -1;
    TMap<int, FName> Keypoints;
    TMap<int, FName> KeypointsMirrored;
    TArray<int> ParentsIdx;

	//FBoneContainer& RequiredBones;

	TMap<FName, float> RefPoseBoneSize;
	TMap<FName, float> ZEDBoneSize;

	TMap<FName, FVector> BonesScale;

	// factor used to computer foot offset over time.
	float BoneScaleAlpha = 0.2f;

	int FeetOffsetBufferSize = 120;
	std::deque<float> FeetOffsetBuffer;
	float FeetOffset = 0;
	float FeetOffsetAlpha = 1.0f;

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









const TArray<int> parents38Idx = {
    -1,
    0,
    1,
    2,
    3,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    10,
    11,
    12,
    13,
    14,
    15,
    0,
    0,
    18,
    19,
    20,
    21,
    22,
    23,
    22,
    23,
    22,
    23,
    16,
    17,
    16,
    17,
    16,
    17,
    16,
    17
};

const TArray<int> parents70Idx = {
    -1,
    0,
    1,
    2,
    3,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    10,
    11,
    12,
    13,
    14,
    15,
    0,
    0,
    18,
    19,
    20,
    21,
    22,
    23,
    22,
    23,
    22,
    23,
    16,
    30,
    31,
    32,
    16,
    30,
    31,
    32,
    16,
    30,
    31,
    32,
    16,
    30,
    31,
    32,
    16,
    30,
    31,
    32,
    17,
    50,
    51,
    52,
    17,
    50,
    51,
    52,
    17,
    50,
    51,
    52,
    17,
    50,
    51,
    52,
    17,
    50,
    51,
    52,
};

static TMap<int, FName> Keypoints38 = TMap<int, FName>{
    {0, "PELVIS"},
    {1, "SPINE_1"},
    {2, "SPINE_2"},
    {3, "SPINE_3"},
    {4, "NECK"},
    {5, "NOSE"},
    {6, "LEFT_EYE"},
    {7, "RIGHT_EYE"},
    {8, "LEFT_EAR"},
    {9, "RIGHT_EAR"},
    {10, "LEFT_CLAVICLE"},
    {11, "RIGHT_CLAVICLE"},
    {12, "LEFT_SHOULDER"},
    {13, "RIGHT_SHOULDER"},
    {14, "LEFT_ELBOW"},
    {15, "RIGHT_ELBOW"},
    {16, "LEFT_WRIST"},
    {17, "RIGHT_WRIST"},
    {18, "LEFT_HIP"},
    {19, "RIGHT_HIP"},
    {20, "LEFT_KNEE"},
    {21, "RIGHT_KNEE"},
    {22, "LEFT_ANKLE"},
    {23, "RIGHT_ANKLE"},
    {24, "LEFT_BIG_TOE"},
    {25, "RIGHT_BIG_TOE"},
    {26, "LEFT_SMALL_TOE"},
    {27, "RIGHT_SMALL_TOE"},
    {28, "LEFT_HEEL"},
    {29, "RIGHT_HEEL"},
    {30, "LEFT_HAND_THUMB_4"},
    {31, "RIGHT_HAND_THUMB_4"},
    {32, "LEFT_HAND_INDEX_1"},
    {33, "RIGHT_HAND_INDEX_1"},
    {34, "LEFT_HAND_MIDDLE_4"},
    {35, "RIGHT_HAND_MIDDLE_4"},
    {36, "LEFT_HAND_PINKY_1"},
    {37, "RIGHT_HAND_PINKY_1"},
};

static TMap<int, FName> Keypoints38Mirrored = TMap<int, FName>{
     {0, "PELVIS"},
    {1, "SPINE_1"},
    {2, "SPINE_2"},
    {3, "SPINE_3"},
    {4, "NECK"},
    {5, "NOSE"},
    {6, "RIGHT_EYE"},
    {7, "LEFT_EYE"},
    {8, "RIGHT_EAR"},
    {9, "LEFT_EAR"},
    {10, "RIGHT_CLAVICLE"},
    {11, "LEFT_CLAVICLE"},
    {12, "RIGHT_SHOULDER"},
    {13, "LEFT_SHOULDER"},
    {14, "RIGHT_ELBOW"},
    {15, "LEFT_ELBOW"},
    {16, "RIGHT_WRIST"},
    {17, "LEFT_WRIST"},
    {18, "RIGHT_HIP"},
    {19, "LEFT_HIP"},
    {20, "RIGHT_KNEE"},
    {21, "LEFT_KNEE"},
    {22, "RIGHT_ANKLE"},
    {23, "LEFT_ANKLE"},
    {24, "RIGHT_BIG_TOE"},
    {25, "LEFT_BIG_TOE"},
    {26, "RIGHT_SMALL_TOE"},
    {27, "LEFT_SMALL_TOE"},
    {28, "RIGHT_HEEL"},
    {29, "LEFT_HEEL"},
    {30, "RIGHT_HAND_THUMB_4"},
    {31, "LEFT_HAND_THUMB_4"},
    {32, "RIGHT_HAND_INDEX_1"},
    {33, "LEFT_HAND_INDEX_1"},
    {34, "RIGHT_HAND_MIDDLE_4"},
    {35, "LEFT_HAND_MIDDLE_4"},
    {36, "RIGHT_HAND_PINKY_1"},
    {37, "LEFT_HAND_PINKY_1"},
};

static TMap<int, FName> Keypoints70 = TMap<int, FName>{
    {0, "PELVIS"},
    {1, "SPINE_1"},
    {2, "SPINE_2"},
    {3, "SPINE_3"},
    {4, "NECK"},
    {5, "NOSE"},
    {6, "LEFT_EYE"},
    {7, "RIGHT_EYE"},
    {8, "LEFT_EAR"},
    {9, "RIGHT_EAR"},
    {10, "LEFT_CLAVICLE"},
    {11, "RIGHT_CLAVICLE"},
    {12, "LEFT_SHOULDER"},
    {13, "RIGHT_SHOULDER"},
    {14, "LEFT_ELBOW"},
    {15, "RIGHT_ELBOW"},
    {16, "LEFT_WRIST"},
    {17, "RIGHT_WRIST"},
    {18, "LEFT_HIP"},
    {19, "RIGHT_HIP"},
    {20, "LEFT_KNEE"},
    {21, "RIGHT_KNEE"},
    {22, "LEFT_ANKLE"},
    {23, "RIGHT_ANKLE"},
    {24, "LEFT_BIG_TOE"},
    {25, "RIGHT_BIG_TOE"},
    {26, "LEFT_SMALL_TOE"},
    {27, "RIGHT_SMALL_TOE"},
    {28, "LEFT_HEEL"},
    {29, "RIGHT_HEEL"},
    {30, "LEFT_HAND_THUMB_1"},
    {31, "LEFT_HAND_THUMB_2"},
    {32, "LEFT_HAND_THUMB_3"},
    {33, "LEFT_HAND_THUMB_4"},
    {34, "LEFT_HAND_INDEX_1"},
    {35, "LEFT_HAND_INDEX_2"},
    {36, "LEFT_HAND_INDEX_3"},
    {37, "LEFT_HAND_INDEX_4"},
    {38, "LEFT_HAND_MIDDLE_1"},
    {39, "LEFT_HAND_MIDDLE_2"},
    {40, "LEFT_HAND_MIDDLE_3"},
    {41, "LEFT_HAND_MIDDLE_4"},
    {42, "LEFT_HAND_RING_1"},
    {43, "LEFT_HAND_RING_2"},
    {44, "LEFT_HAND_RING_3"},
    {45, "LEFT_HAND_RING_4"},
    {46, "LEFT_HAND_PINKY_1"},
    {47, "LEFT_HAND_PINKY_2"},
    {48, "LEFT_HAND_PINKY_3"},
    {49, "LEFT_HAND_PINKY_4"},
    {50, "RIGHT_HAND_THUMB_1"},
    {51, "RIGHT_HAND_THUMB_2"},
    {52, "RIGHT_HAND_THUMB_3"},
    {53, "RIGHT_HAND_THUMB_4"},
    {54, "RIGHT_HAND_INDEX_1"},
    {55, "RIGHT_HAND_INDEX_2"},
    {56, "RIGHT_HAND_INDEX_3"},
    {57, "RIGHT_HAND_INDEX_4"},
    {58, "RIGHT_HAND_MIDDLE_1"},
    {59, "RIGHT_HAND_MIDDLE_2"},
    {60, "RIGHT_HAND_MIDDLE_3"},
    {61, "RIGHT_HAND_MIDDLE_4"},
    {62, "RIGHT_HAND_RING_1"},
    {63, "RIGHT_HAND_RING_2"},
    {64, "RIGHT_HAND_RING_3"},
    {65, "RIGHT_HAND_RING_4"},
    {66, "RIGHT_HAND_PINKY_1"},
    {67, "RIGHT_HAND_PINKY_2"},
    {68, "RIGHT_HAND_PINKY_3"},
    {69, "RIGHT_HAND_PINKY_4"}
};

static TMap<int, FName> Keypoints70Mirrored = TMap<int, FName>{
    {0, "PELVIS"},
    {1, "SPINE_1"},
    {2, "SPINE_2"},
    {3, "SPINE_3"},
    {4, "NECK"},
    {5, "NOSE"},
    {6, "RIGHT_EYE"},
    {7, "LEFT_EYE"},
    {8, "RIGHT_EAR"},
    {9, "LEFT_EAR"},
    {10, "RIGHT_CLAVICLE"},
    {11, "LEFT_CLAVICLE"},
    {12, "RIGHT_SHOULDER"},
    {13, "LEFT_SHOULDER"},
    {14, "RIGHT_ELBOW"},
    {15, "LEFT_ELBOW"},
    {16, "RIGHT_WRIST"},
    {17, "LEFT_WRIST"},
    {18, "RIGHT_HIP"},
    {19, "LEFT_HIP"},
    {20, "RIGHT_KNEE"},
    {21, "LEFT_KNEE"},
    {22, "RIGHT_ANKLE"},
    {23, "LEFT_ANKLE"},
    {24, "RIGHT_BIG_TOE"},
    {25, "LEFT_BIG_TOE"},
    {26, "RIGHT_SMALL_TOE"},
    {27, "LEFT_SMALL_TOE"},
    {28, "RIGHT_HEEL"},
    {29, "LEFT_HEEL"},
    {30, "RIGHT_HAND_THUMB_1"},
    {31, "RIGHT_HAND_THUMB_2"},
    {32, "RIGHT_HAND_THUMB_3"},
    {33, "RIGHT_HAND_THUMB_4"},
    {34, "RIGHT_HAND_INDEX_1"},
    {35, "RIGHT_HAND_INDEX_2"},
    {36, "RIGHT_HAND_INDEX_3"},
    {37, "RIGHT_HAND_INDEX_4"},
    {38, "RIGHT_HAND_MIDDLE_1"},
    {39, "RIGHT_HAND_MIDDLE_2"},
    {40, "RIGHT_HAND_MIDDLE_3"},
    {41, "RIGHT_HAND_MIDDLE_4"},
    {42, "RIGHT_HAND_RING_1"},
    {43, "RIGHT_HAND_RING_2"},
    {44, "RIGHT_HAND_RING_3"},
    {45, "RIGHT_HAND_RING_4"},
    {46, "RIGHT_HAND_PINKY_1"},
    {47, "RIGHT_HAND_PINKY_2"},
    {48, "RIGHT_HAND_PINKY_3"},
    {49, "RIGHT_HAND_PINKY_4"},
    {50, "LEFT_HAND_THUMB_1"},
    {51, "LEFT_HAND_THUMB_2"},
    {52, "LEFT_HAND_THUMB_3"},
    {53, "LEFT_HAND_THUMB_4"},
    {54, "LEFT_HAND_INDEX_1"},
    {55, "LEFT_HAND_INDEX_2"},
    {56, "LEFT_HAND_INDEX_3"},
    {57, "LEFT_HAND_INDEX_4"},
    {58, "LEFT_HAND_MIDDLE_1"},
    {59, "LEFT_HAND_MIDDLE_2"},
    {60, "LEFT_HAND_MIDDLE_3"},
    {61, "LEFT_HAND_MIDDLE_4"},
    {62, "LEFT_HAND_RING_1"},
    {63, "LEFT_HAND_RING_2"},
    {64, "LEFT_HAND_RING_3"},
    {65, "LEFT_HAND_RING_4"},
    {66, "LEFT_HAND_PINKY_1"},
    {67, "LEFT_HAND_PINKY_2"},
    {68, "LEFT_HAND_PINKY_3"},
    {69, "LEFT_HAND_PINKY_4"}
};

static FName GetParentBoneName(FName BoneName)
{
    FName ParentBoneName = "None";

    if (BoneName.IsEqual("PELVIS"))
        ParentBoneName = "None";
    else if (BoneName.IsEqual("SPINE_1"))
        ParentBoneName = "PELVIS";
    else if (BoneName.IsEqual("SPINE_2"))
        ParentBoneName = "SPINE_1";
    else if (BoneName.IsEqual("SPINE_3"))
        ParentBoneName = "SPINE_2";
    else if (BoneName.IsEqual("NECK"))
        ParentBoneName = "SPINE_3";
    else if (BoneName.IsEqual("LEFT_CLAVICLE"))
        ParentBoneName = "SPINE_3";
    else if (BoneName.IsEqual("LEFT_SHOULDER"))
        ParentBoneName = "LEFT_CLAVICLE";
    else if (BoneName.IsEqual("LEFT_ELBOW"))
        ParentBoneName = "LEFT_SHOULDER";
    else if (BoneName.IsEqual("LEFT_WRIST"))
        ParentBoneName = "LEFT_ELBOW";
    else if (BoneName.IsEqual("LEFT_HAND_THUMB_4"))
        ParentBoneName = "LEFT_WRIST";
    else if (BoneName.IsEqual("LEFT_HAND_INDEX_1"))
        ParentBoneName = "LEFT_WRIST";
    else if (BoneName.IsEqual("LEFT_HAND_MIDDLE_4"))
        ParentBoneName = "LEFT_WRIST";
    else if (BoneName.IsEqual("LEFT_HAND_PINKY_1"))
        ParentBoneName = "LEFT_WRIST";
    else if (BoneName.IsEqual("RIGHT_CLAVICLE"))
        ParentBoneName = "SPINE_3";
    else if (BoneName.IsEqual("RIGHT_SHOULDER"))
        ParentBoneName = "RIGHT_CLAVICLE";
    else if (BoneName.IsEqual("RIGHT_ELBOW"))
        ParentBoneName = "RIGHT_SHOULDER";
    else if (BoneName.IsEqual("RIGHT_WRIST"))
        ParentBoneName = "RIGHT_ELBOW";
    else if (BoneName.IsEqual("RIGHT_HAND_THUMB_4"))
        ParentBoneName = "RIGHT_WRIST";
    else if (BoneName.IsEqual("RIGHT_HAND_INDEX_1"))
        ParentBoneName = "RIGHT_WRIST";
    else if (BoneName.IsEqual("RIGHT_HAND_MIDDLE_4"))
        ParentBoneName = "RIGHT_WRIST";
    else if (BoneName.IsEqual("RIGHT_HAND_PINKY_1"))
        ParentBoneName = "RIGHT_WRIST";
    else if (BoneName.IsEqual("LEFT_HIP"))
        ParentBoneName = "PELVIS";
    else if (BoneName.IsEqual("LEFT_KNEE"))
        ParentBoneName = "LEFT_HIP";
    else if (BoneName.IsEqual("LEFT_ANKLE"))
        ParentBoneName = "LEFT_KNEE";
    else if (BoneName.IsEqual("LEFT_BIG_TOE"))
        ParentBoneName = "LEFT_ANKLE";
    else if (BoneName.IsEqual("LEFT_SMALL_TOE"))
        ParentBoneName = "LEFT_ANKLE";
    else if (BoneName.IsEqual("RIGHT_HIP"))
        ParentBoneName = "PELVIS";
    else if (BoneName.IsEqual("RIGHT_KNEE"))
        ParentBoneName = "RIGHT_HIP";
    else if (BoneName.IsEqual("RIGHT_ANKLE"))
        ParentBoneName = "RIGHT_KNEE";
    else if (BoneName.IsEqual("RIGHT_BIG_TOE"))
        ParentBoneName = "RIGHT_ANKLE";
    else if (BoneName.IsEqual("RIGHT_SMALL_TOE"))
        ParentBoneName = "RIGHT_ANKLE";
    else if (BoneName.IsEqual("NOSE"))
        ParentBoneName = "NECK";
    else if (BoneName.IsEqual("LEFT_EYE"))
        ParentBoneName = "NECK";
    else if (BoneName.IsEqual("RIGHT_EYE"))
        ParentBoneName = "NECK";
    else if (BoneName.IsEqual("LEFT_EAR"))
        ParentBoneName = "LEFT_EYE";
    else if (BoneName.IsEqual("RIGHT_EAR"))
        ParentBoneName = "RIGHT_EYE";
    else if (BoneName.IsEqual("LEFT_HEEL"))
        ParentBoneName = "LEFT_ANKLE";
    else if (BoneName.IsEqual("RIGHT_HEEL"))
        ParentBoneName = "RIGHT_ANKLE";

    return ParentBoneName;
}
