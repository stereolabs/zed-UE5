//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "ZED/Public/HUD/ZEDWidgetComponent.h"

#include "ZEDWidget.generated.h"

UCLASS()
class ZED_API UZEDWidget : public USceneComponent
{
	GENERATED_BODY()

public:
	UZEDWidget();

public:
	/*
	 * Set the widget visibility
	 * @param bNewVisibility       The new visibility
	 * @param bPropagateToChildren True to propagate to children
	 */
	void SetVisibility(bool bNewVisibility, bool bPropagateToChildren=false);

	/*
	 * @return The current widget space
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	EWidgetSpace GetWidgetSpace();

	/*
	 * Set the widget space
	 * @param NewWidgetSpace The new widget space
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SetWidgetSpace(EWidgetSpace NewWidgetSpace);

	/*
	 * Set the widget text
	 * @param NewText The new text
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SetText(const FText& NewText);

	/*
	 * Set the widget size
	 * @param NewSize The new size
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SetFontSize(int32 NewSize);

	/*
	 * Set the color and opacity
	 * @param NewColor The new color and opacity
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void SetTextColorAndOpacity(const FLinearColor& NewColor);

	/*
	 * Fade in the widget
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void FadeIn();

	/*
	 * Fade out the widget 
	 */
	UFUNCTION(BlueprintCallable, Category = "Zed")
	void FadeOut();

public:
	/** Widget component */
	UZEDWidgetComponent* WidgetComponent;
};