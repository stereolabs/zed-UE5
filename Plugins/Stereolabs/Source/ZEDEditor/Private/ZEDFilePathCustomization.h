//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

/**
 * FFilePath picker that honours CanEditChange.
 *
 * The engine customization never binds the row to the property's edit state, so an FFilePath
 * stays editable even when CanEditChange returns false for it. Registered instanced, so it
 * only replaces the picker inside the ZED camera details panel.
 */
class FZEDFilePathCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

private:
	FString HandleFilePath() const;

	void HandlePathPicked(const FString& PickedPath);

	TSharedPtr<IPropertyHandle> PathStringProperty;
};
