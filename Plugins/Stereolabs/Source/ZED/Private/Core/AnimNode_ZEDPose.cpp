// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZED/Public/Core/AnimNode_ZEDPose.h"

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
        26,
        20,
        24
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

static FName GetParentBoneName(FName BoneName)
{
    FName ParentBoneName = "None";

    if (BoneName.IsEqual("PELVIS"))
        ParentBoneName = "None";
    else if (BoneName.IsEqual("NAVAL_SPINE"))
        ParentBoneName = "PELVIS";
    else if (BoneName.IsEqual("CHEST_SPINE"))
        ParentBoneName = "NAVAL_SPINE";
    else if (BoneName.IsEqual("NECK"))
        ParentBoneName = "CHEST_SPINE";
    else if (BoneName.IsEqual("LEFT_CLAVICLE"))
        ParentBoneName = "CHEST_SPINE";
    else if (BoneName.IsEqual("LEFT_SHOULDER"))
        ParentBoneName = "LEFT_CLAVICLE";
    else if (BoneName.IsEqual("LEFT_ELBOW"))
        ParentBoneName = "LEFT_SHOULDER";
    else if (BoneName.IsEqual("LEFT_WRIST"))
        ParentBoneName = "LEFT_ELBOW";
    else if (BoneName.IsEqual("LEFT_HAND"))
        ParentBoneName = "LEFT_WRIST";
    else if (BoneName.IsEqual("LEFT_HANDTIP"))
        ParentBoneName = "LEFT_HAND";
    else if (BoneName.IsEqual("LEFT_THUMB"))
        ParentBoneName = "LEFT_WRIST";
    else if (BoneName.IsEqual("RIGHT_CLAVICLE"))
        ParentBoneName = "CHEST_SPINE";
    else if (BoneName.IsEqual("RIGHT_SHOULDER"))
        ParentBoneName = "RIGHT_CLAVICLE";
    else if (BoneName.IsEqual("RIGHT_ELBOW"))
        ParentBoneName = "RIGHT_SHOULDER";
    else if (BoneName.IsEqual("RIGHT_WRIST"))
        ParentBoneName = "RIGHT_ELBOW";
    else if (BoneName.IsEqual("RIGHT_HAND"))
        ParentBoneName = "RIGHT_WRIST";
    else if (BoneName.IsEqual("RIGHT_HANDTIP"))
        ParentBoneName = "RIGHT_HAND";
    else if (BoneName.IsEqual("RIGHT_THUMB"))
        ParentBoneName = "RIGHT_WRIST";
    else if (BoneName.IsEqual("LEFT_HIP"))
        ParentBoneName = "PELVIS";
    else if (BoneName.IsEqual("LEFT_KNEE"))
        ParentBoneName = "LEFT_HIP";
    else if (BoneName.IsEqual("LEFT_ANKLE"))
        ParentBoneName = "LEFT_KNEE";
    else if (BoneName.IsEqual("LEFT_FOOT"))
        ParentBoneName = "LEFT_ANKLE";
    else if (BoneName.IsEqual("RIGHT_HIP"))
        ParentBoneName = "PELVIS";
    else if (BoneName.IsEqual("RIGHT_KNEE"))
        ParentBoneName = "RIGHT_HIP";
    else if (BoneName.IsEqual("RIGHT_ANKLE"))
        ParentBoneName = "RIGHT_KNEE";
    else if (BoneName.IsEqual("RIGHT_FOOT"))
        ParentBoneName = "RIGHT_ANKLE";
    else if (BoneName.IsEqual("HEAD"))
        ParentBoneName = "NECK";
    else if (BoneName.IsEqual("NOSE"))
        ParentBoneName = "HEAD";
    else if (BoneName.IsEqual("LEFT_EYE"))
        ParentBoneName = "HEAD";
    else if (BoneName.IsEqual("RIGHT_EYE"))
        ParentBoneName = "HEAD";
    else if (BoneName.IsEqual("LEFT_EAR"))
        ParentBoneName = "HEAD";
    else if (BoneName.IsEqual("RIGHT_EAR"))
        ParentBoneName = "HEAD";
    else if (BoneName.IsEqual("LEFT_HEEL"))
        ParentBoneName = "LEFT_ANKLE";
    else if (BoneName.IsEqual("RIGHT_HEEL"))
        ParentBoneName = "RIGHT_ANKLE";

    return ParentBoneName;
}

float FindFeetOffset(std::deque<float> Offsets, bool isAboveTheGround)
{
    float min = std::numeric_limits<float>::max();
    float max = -std::numeric_limits<float>::max();

    for (int i = 0; i < Offsets.size(); i++)
    {
        float value = Offsets[i];
        if (isAboveTheGround && value >= 0)
        {
            if (value < min)
            {
                min = value;
            }
        }
        else if (!isAboveTheGround && value < 0)
        {
            if (value > max) // negative values
            {
                max = value;
            }
        }
    }
    
    return isAboveTheGround ? min : max;
}

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

void FAnimNode_ZEDPose::PropagateRestPoseRotations(int32 parentIdx, FCompactPose& OutPose, FQuat restPoseRot, bool inverse) 
{

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

void FAnimNode_ZEDPose::BuildPoseFromSlObjectData(FPoseContext& PoseContext)
{
    FCompactPose& OutPose = PoseContext.Pose;
    TArray<FName> SourceBoneNames;
    SourceBoneNames.SetNum(RemapAsset.Num());
    RemapAsset.GetKeys(SourceBoneNames);

    PutInRefPose(OutPose, SourceBoneNames);

    // Compact Pose Root index
    FCompactPoseBoneIndex CPIndexRoot = GetCPIndex(0, OutPose);

    TArray<FName> TargetBoneNames;
    SkeletalMesh->GetBoneNames(TargetBoneNames);

    // Apply an offset to put the feet of the ground and offset "floating" avatars.
    if (bStickAvatarOnFloor && ObjectData.KeypointConfidence[20] > 90 && ObjectData.KeypointConfidence[24] > 90) { //if both foot are visible/detected
        if (SkeletalMesh) {
            // Retrieve Feet position
            FVector LeftFootPosition = SkeletalMesh->GetBoneLocation(RemapAsset[Keypoints[21]]) ;
            FVector RightFootPosition = SkeletalMesh->GetBoneLocation(RemapAsset[Keypoints[25]]);

            // Shot raycast to the ground.
            FHitResult HitLeftFoot;
            bool RaycastLeftFoot = SkeletalMesh->GetWorld()->LineTraceSingleByObjectType(OUT HitLeftFoot, LeftFootPosition + FVector(0, 0, 200), LeftFootPosition - FVector(0, 0, 200),
                FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic));

            // Same for the right foot
            FHitResult HitRightFoot;
            bool RaycastRightFoot = SkeletalMesh->GetWorld()->LineTraceSingleByObjectType(OUT HitRightFoot, RightFootPosition + FVector(0, 0, 200), RightFootPosition - FVector(0, 0, 200),
                FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic));

            float LeftFootFloorDistance = 0;
            float RightFootFloorDistance = 0;

            // Compute the distance between one foot and the ground (the first static object found by the ray cast).
            if (RaycastLeftFoot)
            {
                LeftFootFloorDistance = (LeftFootPosition + FVector(0, 0, FeetOffset) - HitLeftFoot.ImpactPoint).Z;
            }

            if (RaycastRightFoot)
            {
                RightFootFloorDistance = (RightFootPosition + FVector(0, 0, FeetOffset) - HitRightFoot.ImpactPoint).Z;
            }

            float MinFootFloorDistance = 0;

            // If both feet are under the ground, use the max value instead of the min value.
            if (RightFootFloorDistance < 0 && LeftFootFloorDistance < 0) {

                MinFootFloorDistance = -1.0f * fmax(abs(RightFootFloorDistance), abs(LeftFootFloorDistance));
                FeetOffset = FeetOffsetAlpha * MinFootFloorDistance + (1 - FeetOffsetAlpha) * FeetOffset;
            }
            else if (RightFootFloorDistance > 0 && LeftFootFloorDistance > 0)
            {
                MinFootFloorDistance = fmin(abs(RightFootFloorDistance), abs(LeftFootFloorDistance));

                // The feet offset is added in the buffer of size "FeetOffsetBufferSize". If the buffer is already full, remove the oldest value (the first of the deque)
                if (FeetOffsetBuffer.size() == FeetOffsetBufferSize)
                {
                    FeetOffsetBuffer.pop_front();
                }
                FeetOffsetBuffer.push_back(MinFootFloorDistance);

                // The feet offset is the min element of this deque (of size FeetOffsetBufferSize).
                FeetOffset = FindFeetOffset(FeetOffsetBuffer, true);
            }
            else
            {
                MinFootFloorDistance = fmin(RightFootFloorDistance, LeftFootFloorDistance);
                FeetOffset = FeetOffsetAlpha * MinFootFloorDistance + (1 - FeetOffsetAlpha) * FeetOffset;
            }
        }
    }

    // If the Bone Scaling option is enabled, compute the size of each bone coming from the ZED SDK.
    if (bEnableBoneScaling)
    {
        for (auto& TargetBoneName : TargetBoneNames)
        {
            const FName* SourceBoneName = RemapAsset.FindKey(TargetBoneName);

            if (SourceBoneName && !SourceBoneName->IsEqual("PELVIS")) // Do not scale the root
            {
                int SourceBoneID = *Keypoints.FindKey(*SourceBoneName);
                FVector BonePosition = ObjectData.Keypoint[SourceBoneID];
                FVector ParentSourceBonePosition = ObjectData.Keypoint[ParentsIdx[SourceBoneID]];;
                FName ParentSourceBoneName = RemapAsset[*Keypoints.Find(ParentsIdx[SourceBoneID])];
                float BoneSize = (ParentSourceBonePosition - BonePosition).Size();

                // Store the size of each bone of the ref pose.
                ZEDBoneSize.Add(ParentSourceBoneName, BoneSize);
            }
        }
    }

    if (CPIndexRoot != INDEX_NONE)
    {
        PropagateRestPoseRotations(0, OutPose, OutPose.GetRefPose(CPIndexRoot).GetRotation(), false);
    }

    //// Iterate over remapped bone names, find the index of that bone on the skeleton, and apply the pose data.
    for (auto& SourceBoneName : SourceBoneNames)
    {
        FName TargetBoneName = RemapAsset[SourceBoneName];
        int idx = bMirrorOnZAxis ? *KeypointsMirrored.FindKey(SourceBoneName) : *Keypoints.FindKey(SourceBoneName);
        FCompactPoseBoneIndex CPIndex = GetCPIndex(idx, OutPose);
        if (CPIndex != INDEX_NONE)
        {
            FQuat Rotation;
            FVector Translation;

            // Only use position + rotation data for root. For all other bones, set rotation only.
            if (TargetBoneName == *RemapAsset.Find(GetTargetRootName()))
            {
                FVector RootPosition = ObjectData.Keypoint[0];
                FCompactPoseBoneIndex leftUpLegIndex = GetCPIndex(*Keypoints.FindKey("LEFT_HIP"), OutPose); // 18 = LEFT_HIP
                float HipOffset = FMath::Abs(OutPose[leftUpLegIndex].GetTranslation().Z) * OutPose[CPIndexRoot].GetScale3D().Z;
                RootPosition.Z += HipOffset;
                RootPosition.Z += HeightOffset;
                RootPosition.Z -= FeetOffset;

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

                if (bMirrorOnZAxis) 
                {
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

    // If the Bone Scaling option is enabled, compare the bone size between the ZED SDK data and the avatar's bones size. apply this factor to the Avatar bones in order 
    // to scale the mesh to the person's size.
    if (bEnableBoneScaling)
    {
        FVector ZEDNeckPosition = ObjectData.Keypoint[*Keypoints.FindKey("NECK")];
        FVector ZEDPelvisPosition = ObjectData.Keypoint[*Keypoints.FindKey("PELVIS")];

        float ZEDChestLength = (ZEDNeckPosition - ZEDPelvisPosition).Size();

        for (auto& TargetBoneName : TargetBoneNames)
        {
            if (ZEDBoneSize.Find(TargetBoneName) && RefPoseBoneSize.Find(TargetBoneName) && RefPoseBoneSize.Find(TargetBoneName) != 0)
            {
                if (!BonesScale.Contains(TargetBoneName)) BonesScale.Add(TargetBoneName, FVector::OneVector);

                FName SourceBoneName = *RemapAsset.FindKey(TargetBoneName);
                int SourceBoneID = *Keypoints.FindKey(SourceBoneName);
                float SourceBoneConfidence = ObjectData.KeypointConfidence[SourceBoneID];

                float BoneScale = 1;
                float ParentBoneScale = 1;
                FVector FinalScale = FVector::OneVector;

                if (TargetBoneName.IsEqual("Hips")) //
                {
                    if (ObjectData.KeypointConfidence[*Keypoints.FindKey("NECK")] > 90 && ObjectData.KeypointConfidence[*Keypoints.FindKey("PELVIS")] > 90)
                    {
                        BoneScale = ZEDChestLength / RefPoseChestLength;

                        FinalScale = BoneScaleAlpha * *BonesScale.Find(TargetBoneName) + (1 - BoneScaleAlpha) * FVector(BoneScale, BoneScale, BoneScale);
                    }
                    else
                    {
                        FinalScale = *BonesScale.Find(TargetBoneName);
                    }
                }
                // Scale all the bones of the chest with the same scale
                else if (TargetBoneName.IsEqual("Head") || TargetBoneName.IsEqual("Spine") || TargetBoneName.IsEqual("Spine1") || TargetBoneName.IsEqual("Spine2")
                    || TargetBoneName.IsEqual("Neck") || TargetBoneName.IsEqual("LeftShoulder") || TargetBoneName.IsEqual("RightShoulder"))
                {
                    FinalScale = FVector::OneVector;
                }
                else
                {
                    if (Keypoints.FindKey(SourceBoneName) && Keypoints.Find(ParentsIdx[*Keypoints.FindKey(SourceBoneName)]))
                    {
                        if (ObjectData.KeypointConfidence[*Keypoints.FindKey(SourceBoneName)] > 90)
                        {
                            FName TargetParentBoneName = RemapAsset[*Keypoints.Find(ParentsIdx[*Keypoints.FindKey(SourceBoneName)])];

                            BoneScale = *ZEDBoneSize.Find(TargetBoneName) / *RefPoseBoneSize.Find(TargetBoneName);
                            ParentBoneScale = *ZEDBoneSize.Find(TargetParentBoneName) / *RefPoseBoneSize.Find(TargetParentBoneName);

                            if (!TargetBoneName.IsEqual("LeftUpLeg") && !TargetBoneName.IsEqual("RightUpLeg") && !TargetBoneName.IsEqual("LeftArm") && !TargetBoneName.IsEqual("RightArm"))
                            {
                                BoneScale /= ParentBoneScale;
                            }

                            FinalScale = BoneScaleAlpha * (*BonesScale.Find(TargetBoneName)) + (1 - BoneScaleAlpha) * FVector(1, 1, BoneScale);
                        }
                        else
                        {
                            FinalScale = *BonesScale.Find(TargetBoneName);
                        }
                    }
                }

                BonesScale.Emplace(TargetBoneName, FinalScale);
                int idx = bMirrorOnZAxis ? *KeypointsMirrored.FindKey(SourceBoneName) : *Keypoints.FindKey(SourceBoneName);
                FCompactPoseBoneIndex CPIndex = GetCPIndex(idx, OutPose);

                OutPose[CPIndex].SetScale3D(FinalScale);
            }
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

    BoneScaleAlpha = 0.2f;
}

void FAnimNode_ZEDPose::PreUpdate(const UAnimInstance* InAnimInstance)
{
}

void FAnimNode_ZEDPose::Update_AnyThread(const FAnimationUpdateContext& Context)
{
    InputPose.Update(Context);

    GetEvaluateGraphExposedInputs().Execute(Context);

    if (SkeletalMesh)
    {
        if (RefPoseBoneSize.Num() == 0)
        {
            TArray<FName> TargetBoneNames;
            SkeletalMesh->GetBoneNames(TargetBoneNames);

            for (auto& TargetBoneName : TargetBoneNames)
            {
                FVector TargetBonePosition = SkeletalMesh->GetBoneLocation(TargetBoneName, EBoneSpaces::WorldSpace);

                const FName* SourceBoneName = RemapAsset.FindKey(TargetBoneName);
                if (SourceBoneName && !SourceBoneName->IsEqual("PELVIS")) // Do not scale the root
                {
                    FName ParentTargetBoneName = RemapAsset[GetParentBoneName(*SourceBoneName)];
                    FVector ParentTargetBonePosition = SkeletalMesh->GetBoneLocation(ParentTargetBoneName, EBoneSpaces::WorldSpace);

                    float BoneSize = FVector::Distance(TargetBonePosition, ParentTargetBonePosition) ;

                    // Store the size of each bone of the ref pose.
                    RefPoseBoneSize.Add(ParentTargetBoneName, BoneSize);
                }
                else
                {
                    RefPoseBoneSize.Add(TargetBoneName, 1);
                }
            }

            FVector NeckPosition = SkeletalMesh->GetBoneLocation(RemapAsset["NECK"], EBoneSpaces::WorldSpace);
            FVector PelvisPosition = (SkeletalMesh->GetBoneLocation(RemapAsset["LEFT_HIP"], EBoneSpaces::WorldSpace) + SkeletalMesh->GetBoneLocation(RemapAsset["RIGHT_HIP"], EBoneSpaces::WorldSpace)) / 2.0f;
            
            RefPoseChestLength = (NeckPosition - PelvisPosition).Size();
        }
    }
}

void FAnimNode_ZEDPose::Evaluate_AnyThread(FPoseContext& Output)
{
	InputPose.Evaluate(Output);

    if (ObjectData.Keypoint.Num() > 0)
    {
        if (!PrevDataInitialized) 
        {
            // Rotations
            for (int i = 0; i < ObjectData.LocalOrientationPerJoint.Num(); ++i) 
            { 
                PreviousRotations.Add(ObjectData.LocalOrientationPerJoint[i]); 
            }

            // Root position
            PreviousRootPosition = ObjectData.Keypoint[0];

            // Root rotation
            PreviousRootRotation = ObjectData.GlobalRootOrientation;

            PrevDataInitialized = true;
        }
        BuildPoseFromSlObjectData(Output);
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
