// Copyright Epic Games, Inc. All Rights Reserved.

#include "../Public/AnimNode_ZEDPose.h"

#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimTrace.h"
#include "Features/IModularFeatures.h"
#include "Math/Quat.h"
#include "Math/UnrealMathUtility.h"

// Index of joints parent
static TArray<int> ParentsIdx = TArray<int>{
    -1,
        0,
        1,
        2,
        2,
        4,
        5,
        6,
        7,
        8,
        7,
        2,
        11,
        12,
        13,
        14,
        15,
        14,
        0,
        18,
        19,
        20,
        0,
        22,
        23,
        24,
        3,
        26,
        26,
        26,
        26,
        26
};

static TMap<int, FName> Keypoints = TMap<int, FName>{
    {0, "PELVIS"},
    {1, "NAVAL_SPINE"},
    {2, "CHEST_SPINE"},
    {3, "NECK"},
    {4, "LEFT_CLAVICLE"},
    {5, "LEFT_SHOULDER"},
    {6, "LEFT_ELBOW"},
    {7, "LEFT_WRIST"},
    {8, "LEFT_HAND"},
    {9, "LEFT_HANDTIP"},
    {10, "LEFT_THUMB"},
    {11, "RIGHT_CLAVICLE"},
    {12, "RIGHT_SHOULDER"},
    {13, "RIGHT_ELBOW"},
    {14, "RIGHT_WRIST"},
    {15, "RIGHT_HAND"},
    {16, "RIGHT_HANDTIP"},
    {17, "RIGHT_THUMB"},
    {18, "LEFT_HIP"},
    {19, "LEFT_KNEE"},
    {20, "LEFT_ANKLE"},
    {21, "LEFT_FOOT"},
    {22, "RIGHT_HIP"},
    {23, "RIGHT_KNEE"},
    {24, "RIGHT_ANKLE"},
    {25, "RIGHT_FOOT"},
    {26, "HEAD"},
    {27, "NOSE"},
    {28, "LEFT_EYE"},
    {29, "LEFT_EAR"},
    {30, "RIGHT_EYE"},
    {31, "RIGHT_EAR"},
    {32, "LEFT_HEEL"},
    {33, "RIGHT_HEEL"}
};

static TMap<int, FName> KeypointsMirrored = TMap<int, FName>{
    {0, "PELVIS"},
    {1, "NAVAL_SPINE"},
    {2, "CHEST_SPINE"},
    {3, "NECK"},
    {4, "RIGHT_CLAVICLE"},
    {5, "RIGHT_SHOULDER"},
    {6, "RIGHT_ELBOW"},
    {7, "RIGHT_WRIST"},
    {8, "RIGHT_HAND"},
    {9, "RIGHT_HANDTIP"},
    {10, "RIGHT_THUMB"},
    {11, "LEFT_CLAVICLE"},
    {12, "LEFT_SHOULDER"},
    {13, "LEFT_ELBOW"},
    {14, "LEFT_WRIST"},
    {15, "LEFT_HAND"},
    {16, "LEFT_HANDTIP"},
    {17, "LEFT_THUMB"},
    {18, "RIGHT_HIP"},
    {19, "RIGHT_KNEE"},
    {20, "RIGHT_ANKLE"},
    {21, "RIGHT_FOOT"},
    {22, "LEFT_HIP"},
    {23, "LEFT_KNEE"},
    {24, "LEFT_ANKLE"},
    {25, "LEFT_FOOT"},
    {26, "HEAD"},
    {27, "NOSE"},
    {28, "RIGHT_EYE"},
    {29, "RIGHT_EAR"},
    {30, "LEFT_EYE"},
    {31, "LEFT_EAR"},
    {32, "RIGHT_HEEL"},
    {33, "LEFT_HEEL"}
};

#define DISTANCE_THRESH 2
#define HEIGHT_THRESH 2

float FAnimNode_ZEDPose::ComputeRootTranslationFactor(FCompactPose& OutPose, const FSlObjectData& InObjectData) 
{
    float avatarTotalTranslation = 0.f;
    float SDKTotalTranslation = 0.f;
    for (int32 i = 23; i < 25; i++)
    {
        FVector BonePosition = InObjectData.LocalPositionPerJoint[i];
        FCompactPoseBoneIndex CPIndex = GetCPIndex(i, OutPose);
        if (CPIndex != INDEX_NONE)
        {
            avatarTotalTranslation += OutPose[CPIndex].GetTranslation().Size();
            SDKTotalTranslation += BonePosition.Size();
        }
    }

    float factor = avatarTotalTranslation / SDKTotalTranslation;
    float scale = 1.f;
    FCompactPoseBoneIndex CPIndexRoot = GetCPIndex(0, OutPose);
    if (CPIndexRoot != INDEX_NONE)
        scale = OutPose[CPIndexRoot].GetScale3D().Z;
    return FMath::Abs(scale * factor);
}

FCompactPoseBoneIndex FAnimNode_ZEDPose::GetCPIndex(int32 i, FCompactPose& OutPose) 
{
    FName Name = bMirrorOnZAxis ? KeypointsMirrored[i] : Keypoints[i];
    FName BoneName = RemapAsset[Name];
    const int32 MeshIndex = OutPose.GetBoneContainer().GetPoseBoneIndexForBoneName(BoneName);
    if (MeshIndex != INDEX_NONE)
    {
        FCompactPoseBoneIndex CPIndex = OutPose.GetBoneContainer().MakeCompactPoseIndex(
            FMeshPoseBoneIndex(MeshIndex));
        return CPIndex;
    }
    return (FCompactPoseBoneIndex)INDEX_NONE;
}

void FAnimNode_ZEDPose::PutInRefPose(FCompactPose& OutPose, TArray<FName> SourceBoneNames) 
{
    for (auto & i : SourceBoneNames)
    {
        int idx = bMirrorOnZAxis ? *KeypointsMirrored.FindKey(i) : *Keypoints.FindKey(i);
        FCompactPoseBoneIndex CPIndex = GetCPIndex(idx, OutPose);
        if (CPIndex != INDEX_NONE)
        {
            auto RefBoneTransform = OutPose.GetRefPose(CPIndex);
            OutPose[CPIndex].SetRotation(RefBoneTransform.GetRotation());
        }
    }
}

void FAnimNode_ZEDPose::PropagateRestPoseRotations(int32 parentIdx, FCompactPose& OutPose, FQuat restPoseRot, bool inverse) {
    for (int32 i = 0; i < ParentsIdx.Num(); i++) 
    {
        FCompactPoseBoneIndex CPIndex = GetCPIndex(i, OutPose);
        if (ParentsIdx[i] == parentIdx)
        {
            FQuat restPoseRotChild;
            if (CPIndex != INDEX_NONE)
            {
                FQuat jointRotation = restPoseRot * OutPose[CPIndex].GetRotation();
                OutPose[CPIndex].SetRotation(jointRotation);
                if (!inverse)
                    restPoseRotChild = restPoseRot * OutPose.GetRefPose(CPIndex).GetRotation();
                else
                    restPoseRotChild = OutPose.GetRefPose(CPIndex).GetRotation().Inverse() * restPoseRot;
            }
            else
                restPoseRotChild = restPoseRot; // in case the parent bone doesn't appear in 
                                                // the Unreal avatar, we propagate its own restposerot to 
                                                // its children 
            PropagateRestPoseRotations(i, OutPose, restPoseRotChild, inverse);
        }
    }
}

void FAnimNode_ZEDPose::BuildPoseFromSlObjectData(FCompactPose& OutPose) 
{
    TArray<FName> SourceBoneNames;
    SourceBoneNames.SetNum(RemapAsset.Num());
    RemapAsset.GetKeys(SourceBoneNames);
   
    PutInRefPose(OutPose, SourceBoneNames);
    FCompactPoseBoneIndex CPIndexRoot = GetCPIndex(0, OutPose);

    float LeftFootHeight = 0;
    float RightFootHeight = 0;
    if (ObjectData.KeypointConfidence.Num() == 34) 
    {
        if (ObjectData.KeypointConfidence[20] != 0 && ObjectData.KeypointConfidence[24] != 0) //if both foot are visible/detected
        { 
            if (SkeletalMesh) {
                LeftFootHeight = SkeletalMesh->GetBoneLocation(RemapAsset["LEFT_FOOT"]).Z;
                RightFootHeight = SkeletalMesh->GetBoneLocation(RemapAsset["RIGHT_FOOT"]).Z;
                FeetOffset = Alpha * fmin(LeftFootHeight, RightFootHeight) + (1 - Alpha) * FeetOffset;
            }       
        }
    }

    if (CPIndexRoot != INDEX_NONE)
        PropagateRestPoseRotations(0, OutPose, OutPose.GetRefPose(CPIndexRoot).GetRotation(), false);
    
    //// Iterate over remapped bone names, find the index of that bone on the skeleton, and apply the pose data.
    for (auto& i : SourceBoneNames)
    {
        FName BoneName = RemapAsset[i];
        int idx = bMirrorOnZAxis ? *KeypointsMirrored.FindKey(i) : *Keypoints.FindKey(i);
        FCompactPoseBoneIndex CPIndex = GetCPIndex(idx, OutPose);
        if (CPIndex != INDEX_NONE)
        {
            FQuat Rotation;
            FVector Translation;

            // Only use position + rotation data for root. For all other bones, set rotation only.
            if (BoneName == *RemapAsset.Find(GetTargetRootName()))
            {
                float rootTranslationFactor = ComputeRootTranslationFactor(OutPose, ObjectData);
                FVector RootPosition = ObjectData.Keypoint[0];
                FCompactPoseBoneIndex leftUpLegIndex = GetCPIndex(18, OutPose); // 18 = LEFT_HIP
                float HipOffset = FMath::Abs(OutPose[leftUpLegIndex].GetTranslation().Z) *OutPose[CPIndexRoot].GetScale3D().Z;
                RootPosition.Z += HipOffset;
                RootPosition.Z -= FeetOffset;
                RootPosition.Z += HeightOffset;
                RootPosition.Z *= rootTranslationFactor;

                Translation = FMath::Lerp(
                    PreviousRootPosition,
                    RootPosition,
                    RootLocationSlerpIntensity
                );
                PreviousRootPosition = Translation;

                Rotation = FQuat::Slerp(
                    PreviousRootRotation,
                    ObjectData.GlobalRootOrientation,
                    FMath::Clamp(RotationSlerpIntensity, 0.0f, 1.0f)
                );
                PreviousRootRotation = Rotation;

                if (bMirrorOnZAxis) {
                    Translation.Y *= -1.0f;
                }
            }
            else
            {             
                Rotation = FQuat::Slerp(
                    PreviousRotations[idx],
                    ObjectData.LocalOrientationPerJoint[idx],
                    FMath::Clamp(RotationSlerpIntensity, 0.0f, 1.0f)
                );
                PreviousRotations[idx] = Rotation;

                Translation = OutPose[CPIndex].GetTranslation();
            }

            if (bMirrorOnZAxis) {
                Rotation.W *= -1.f;
                Rotation.Y *= -1.f;
            }

            FQuat FinalRotation = Rotation * OutPose[CPIndex].GetRotation();
            OutPose[CPIndex].SetRotation(FinalRotation);
            OutPose[CPIndex].SetTranslation(Translation);
        }
    }
    if (CPIndexRoot != INDEX_NONE)
        PropagateRestPoseRotations(0, OutPose, OutPose.GetRefPose(CPIndexRoot).GetRotation().Inverse(), true);
}

FAnimNode_ZEDPose::FAnimNode_ZEDPose(): PrevDataInitialized(false)
{
}

void FAnimNode_ZEDPose::OnInitializeAnimInstance(const FAnimInstanceProxy* InProxy, const UAnimInstance* InAnimInstance)
{
	Super::OnInitializeAnimInstance(InProxy, InAnimInstance);
}

void FAnimNode_ZEDPose::Initialize_AnyThread(const FAnimationInitializeContext& Context)
{
	InputPose.Initialize(Context);

    FeetOffset = 0.0f;
    Alpha = 0.1f;
}

void FAnimNode_ZEDPose::PreUpdate(const UAnimInstance* InAnimInstance)
{
}

void FAnimNode_ZEDPose::Update_AnyThread(const FAnimationUpdateContext & Context)
{
	InputPose.Update(Context);

	GetEvaluateGraphExposedInputs().Execute(Context);

}

void FAnimNode_ZEDPose::Evaluate_AnyThread(FPoseContext& Output)
{
	InputPose.Evaluate(Output);

    if (ObjectData.Keypoint.Num() > 0) {
        if (!PrevDataInitialized) {
            // Rotations
            for (int i = 0; i < ObjectData.LocalOrientationPerJoint.Num(); ++i) 
            { 
                PreviousRotations.Add(ObjectData.LocalOrientationPerJoint[i]); 
            }

            // Root position
            PreviousRootPosition = (ObjectData.Keypoint[0] - FeetOffset + HeightOffset);

            // Root rotation
            PreviousRootRotation = ObjectData.GlobalRootOrientation;

            PrevDataInitialized = true;
        }
        BuildPoseFromSlObjectData(Output.Pose);
    }
}

void FAnimNode_ZEDPose::CacheBones_AnyThread(const FAnimationCacheBonesContext & Context)
{
	Super::CacheBones_AnyThread(Context);
	InputPose.CacheBones(Context);
}

bool FAnimNode_ZEDPose::Serialize(FArchive& Ar)
{
	return false;
}
