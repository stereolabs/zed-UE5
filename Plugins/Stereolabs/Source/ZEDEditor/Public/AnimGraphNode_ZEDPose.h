// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AnimGraphNode_Base.h"
#include "Core/AnimNode_ZEDPose.h"
#include "AnimGraphDefinitions.h"
#include "Kismet2/BlueprintEditorUtils.h" 

#include "AnimGraphNode_ZEDPose.generated.h"

UCLASS()
class UAnimGraphNode_ZEDPose : public UAnimGraphNode_Base
{
	GENERATED_BODY()

public:

	//~ UEdGraphNode interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FText GetMenuCategory() const;
	//~ End of UEdGraphNode

public:

	UPROPERTY(EditAnywhere, Category = Settings)
	FAnimNode_ZEDPose Node;

};
