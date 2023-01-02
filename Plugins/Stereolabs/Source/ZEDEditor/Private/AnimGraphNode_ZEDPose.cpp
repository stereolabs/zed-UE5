// Copyright Epic Games, Inc. All Rights Reserved.

#include "AnimGraphNode_ZEDPose.h"
#include "EdGraph/EdGraphSchema.h"
#include "Animation/AnimAttributes.h"

#define LOCTEXT_NAMESPACE "ZEDAnimNode"

FText UAnimGraphNode_ZEDPose::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("NodeTitle", "ZED Pose");
}

FText UAnimGraphNode_ZEDPose::GetTooltipText() const
{
	return LOCTEXT("NodeTooltip", "Retrieves the current pose associated with the supplied detection");
}

FText UAnimGraphNode_ZEDPose::GetMenuCategory() const
{
	return LOCTEXT("NodeCategory", "ZED");
}


#undef LOCTEXT_NAMESPACE
