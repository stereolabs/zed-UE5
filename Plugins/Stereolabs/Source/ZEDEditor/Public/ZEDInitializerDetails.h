//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "IDetailCustomization.h"
#include "DetailLayoutBuilder.h"

class FZEDInitializerDetails : public IDetailCustomization
{
public:
	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	/** Button enabled */
	bool IsEnabled() const { return true; }

	/** Clicking the reset parameters button */
	FReply OnClickResetParameters();

	/** Clicking the reset camera settings button */
	FReply OnClickResetSettings();

	/** Clicking the save parameters button */
	FReply OnClickSaveParameters();

	/** Clicking the load parameters button */
	FReply OnClickLoadParameters();

	/** Clicking the save camera settings button */
	FReply OnClickSaveSettings();

	/** Clicking the load camera settings button */
	FReply OnClickLoadSettings();

private:
	/** Can only be one initializer selected */
	TArray<TWeakObjectPtr<UObject>> SelectedObjects;
};