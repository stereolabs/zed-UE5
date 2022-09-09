//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/HUD/ZEDWidgetComponent.h"
#include "ZEDPrivatePCH.h"
#include "UMG.h"

#define GET_TEXT_BLOCK() static_cast<UTextBlock*>(GetUserWidgetObject()->WidgetTree->FindWidget(TEXT("Text")))

UZEDWidgetComponent::UZEDWidgetComponent()
{
	static ConstructorHelpers::FObjectFinder<UCurveFloat> FadeCurve(TEXT("CurveFloat'/Stereolabs/ZED/Utility/C_Fade.C_Fade'"));
	FadeTimelineCurve = FadeCurve.Object;

	FadeTimeline = CreateDefaultSubobject<UTimelineComponent>("FadeTimeline");
	FadeTimeline->SetTimelineLength(0.75f);

	FadeFunction.BindUFunction(this, "Fading");
	FadeTimeline->AddInterpFloat(FadeTimelineCurve, FadeFunction);
}

void UZEDWidgetComponent::SetText(const FText& NewText)
{
	UTextBlock* TextBlock = GET_TEXT_BLOCK();
	TextBlock->SetText(NewText);
}

void UZEDWidgetComponent::SetFontSize(int32 NewSize)
{
	UTextBlock* TextBlock = GET_TEXT_BLOCK();
	TextBlock->Font.Size = NewSize;
}

void UZEDWidgetComponent::SetTextColorAndOpacity(const FLinearColor& NewColor)
{
	UTextBlock* TextBlock = GET_TEXT_BLOCK();
	TextBlock->SetColorAndOpacity(NewColor);
}

void UZEDWidgetComponent::FadeIn()
{
	FadeTimeline->PlayFromStart();
}

void UZEDWidgetComponent::FadeOut()
{
	FadeTimeline->ReverseFromEnd();
}

void UZEDWidgetComponent::SetGeometryMode(EWidgetGeometryMode NewGeometryMode)
{
	GeometryMode = NewGeometryMode;
}

void UZEDWidgetComponent::SetCylinderArcAngle(float NewCylinderArcAngle)
{
	CylinderArcAngle = NewCylinderArcAngle;
}

void UZEDWidgetComponent::Fading(float FadingFactor)
{
	SetTintColorAndOpacity(FLinearColor(1.0f, 1.0f, 1.0f, FadingFactor));
}