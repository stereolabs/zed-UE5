//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Components/WidgetComponent.h"

#include "ZEDWidgetComponent.generated.h"

UCLASS()
class ZED_API UZEDWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UZEDWidgetComponent();

public:
	/** Set the text of the widget */
	void SetText(const FText& NewText);

	/** Set the font size of the widget */
	void SetFontSize(int32 NewSize);

	/** Set Color and opacity */
	void SetTextColorAndOpacity(const FLinearColor& NewColor);

	/** Fade in */
	void FadeIn();

	/** Fade out */
	void FadeOut();

	/** Set geometry mode */
	void SetGeometryMode(EWidgetGeometryMode NewGeometryMode);

	/**Set the cylinder arc angle */
	void SetCylinderArcAngle(float NewCylinderArcAngle);

private:
	/*
	 * Timeline fade function
	 */
	UFUNCTION()
	void Fading(float FadingFactor);

public:
	/** Fade timeline */
	UPROPERTY(BlueprintReadWrite)
	UTimelineComponent* FadeTimeline;

	/** Fade timeline curve */
	UPROPERTY(BlueprintReadWrite)
	UCurveFloat* FadeTimelineCurve;

	/** Fade function */
	FOnTimelineFloat FadeFunction;
};