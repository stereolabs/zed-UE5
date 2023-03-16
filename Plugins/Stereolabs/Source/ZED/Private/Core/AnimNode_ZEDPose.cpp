// Copyright Epic Games, Inc. All Rights Reserved.

#include "ZED/Public/Core/AnimNode_ZEDPose.h"

#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimTrace.h"
#include "Features/IModularFeatures.h"
#include "Math/Quat.h"
#include "Math/UnrealMathUtility.h"

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

void FAnimNode_ZEDPose::BuildPoseFromSlBodyData(FPoseContext& PoseContext)
{
    if (NbKeypoints < 0) // only the first time.
    {
        // Check the size of the input data to know which body format is used.
        if (BodyData.Keypoint.Num() == Keypoints34.Num())
        {
            NbKeypoints = 34;
            Keypoints = Keypoints34;
            KeypointsMirrored = Keypoints34Mirrored;
            ParentsIdx = parents34Idx;
        }
        else if (BodyData.Keypoint.Num() == Keypoints38.Num())
        {
            NbKeypoints = 38;
            Keypoints = Keypoints38;
            KeypointsMirrored = Keypoints38Mirrored;
            ParentsIdx = parents38Idx;
        }
        else if (BodyData.Keypoint.Num() == Keypoints70.Num())
        {
            NbKeypoints = 70;
            Keypoints = Keypoints70;
            KeypointsMirrored = Keypoints70Mirrored;
            ParentsIdx = parents70Idx;
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Incompatible body format, please use either body 34/38 or 70"));
        }
    }

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
    if (bStickAvatarOnFloor && BodyData.KeypointConfidence[*Keypoints.FindKey(FName("LEFT_ANKLE"))] > 90 && BodyData.KeypointConfidence[*Keypoints.FindKey(FName("RIGHT_ANKLE"))] > 90) { //if both foot are visible/detected
        if (SkeletalMesh) {

            FVector LeftFootPosition;
            FVector RightFootPosition;
            if (BodyData.Keypoint.Num() == 34) // body 34
            {
                LeftFootPosition = SkeletalMesh->GetBoneLocation(RemapAsset[Keypoints[21]]);
                RightFootPosition = SkeletalMesh->GetBoneLocation(RemapAsset[Keypoints[25]]);
            }
            else // body 38 or 70
            {
                LeftFootPosition = SkeletalMesh->GetBoneLocation(RemapAsset[Keypoints[24]]);
                RightFootPosition = SkeletalMesh->GetBoneLocation(RemapAsset[Keypoints[25]]);
            }

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
            if (RightFootFloorDistance < 0 && LeftFootFloorDistance < 0) 
            {
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
                FeetOffset = *std::min_element(FeetOffsetBuffer.begin(), FeetOffsetBuffer.end());
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
                FVector BonePosition = BodyData.Keypoint[SourceBoneID];
                FVector ParentSourceBonePosition = BodyData.Keypoint[ParentsIdx[SourceBoneID]];;
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
                FVector RootPosition = BodyData.Keypoint[0];
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
                    BodyData.GlobalRootOrientation,
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
                    BodyData.LocalOrientationPerJoint[idx],
                    FMath::Clamp(RotationSlerpIntensity, 0.0f, 1.0f)
                );
                PreviousRotations[idx] = Rotation;

                Translation = OutPose[CPIndex].GetTranslation();
                if (Translation.ContainsNaN())
                {
                    Translation = FVector::ZeroVector;
                }
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
        for (auto& TargetBoneName : TargetBoneNames)
        {
            if (ZEDBoneSize.Find(TargetBoneName) && RefPoseBoneSize.Find(TargetBoneName) && RefPoseBoneSize.Find(TargetBoneName) != 0)
            {
                if (!BonesScale.Contains(TargetBoneName)) BonesScale.Add(TargetBoneName, FVector::OneVector);

                FName SourceBoneName = *RemapAsset.FindKey(TargetBoneName);
                int SourceBoneID = *Keypoints.FindKey(SourceBoneName);
                float SourceBoneConfidence = BodyData.KeypointConfidence[SourceBoneID];

                float BoneScale = 1;
                float ParentBoneScale = 1;
                FVector FinalScale = FVector::OneVector;

                if (Keypoints.FindKey(SourceBoneName) && Keypoints.Find(ParentsIdx[*Keypoints.FindKey(SourceBoneName)]))
                {
                    if (BodyData.KeypointConfidence[*Keypoints.FindKey(SourceBoneName)] > 90)
                    {
                        FName TargetParentBoneName = RemapAsset[*Keypoints.Find(ParentsIdx[*Keypoints.FindKey(SourceBoneName)])];

                        BoneScale = *ZEDBoneSize.Find(TargetBoneName) / *RefPoseBoneSize.Find(TargetBoneName);
                        ParentBoneScale = *ZEDBoneSize.Find(TargetParentBoneName) / *RefPoseBoneSize.Find(TargetParentBoneName);
                        BoneScale /= ParentBoneScale;


                        FinalScale = BoneScaleAlpha * (*BonesScale.Find(TargetBoneName)) + (1 - BoneScaleAlpha) * FVector(BoneScale, BoneScale, BoneScale);
                    }
                    else
                    {
                        FinalScale = *BonesScale.Find(TargetBoneName);
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
        if (RefPoseBoneSize.Num() == 0 && NbKeypoints > 0)
        {
            TArray<FName> TargetBoneNames;
            SkeletalMesh->GetBoneNames(TargetBoneNames);

            for (auto& TargetBoneName : TargetBoneNames)
            {
                FVector TargetBonePosition = SkeletalMesh->GetBoneLocation(TargetBoneName, EBoneSpaces::WorldSpace);

                const FName* SourceBoneName = RemapAsset.FindKey(TargetBoneName);
                if (SourceBoneName && !SourceBoneName->IsEqual("PELVIS")) // Do not scale the root
                {
                    FName ParentTargetBoneName = RemapAsset[GetParentBoneName(*SourceBoneName, NbKeypoints)];
                    FVector ParentTargetBonePosition = SkeletalMesh->GetBoneLocation(ParentTargetBoneName, EBoneSpaces::WorldSpace);

                    float BoneSize = FVector::Distance(TargetBonePosition, ParentTargetBonePosition);

                    // Store the size of each bone of the ref pose.
                    RefPoseBoneSize.Add(ParentTargetBoneName, BoneSize);
                }
                else
                {
                    RefPoseBoneSize.Add(TargetBoneName, 1);
                }
            }
        }
    }
}

void FAnimNode_ZEDPose::Evaluate_AnyThread(FPoseContext& Output)
{
	InputPose.Evaluate(Output);

    if (BodyData.Keypoint.Num() > 0 && RemapAsset.Num() > 0)
    {
        if (!PrevDataInitialized) 
        {
            // Rotations
            for (int i = 0; i < BodyData.LocalOrientationPerJoint.Num(); ++i)
            { 
                PreviousRotations.Add(BodyData.LocalOrientationPerJoint[i]);
            }

            // Root position
            PreviousRootPosition = BodyData.Keypoint[0];

            // Root rotation
            PreviousRootRotation = BodyData.GlobalRootOrientation;

            PrevDataInitialized = true;
        }
        BuildPoseFromSlBodyData(Output);
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
