//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZEDEditor/Private/ZEDFilePathCustomization.h"

#include "DetailWidgetRow.h"
#include "EditorDirectories.h"
#include "PropertyHandle.h"
#include "Misc/Paths.h"
#include "Styling/AppStyle.h"
#include "Widgets/Input/SFilePathPicker.h"

#define LOCTEXT_NAMESPACE "FZEDFilePathCustomization"

TSharedRef<IPropertyTypeCustomization> FZEDFilePathCustomization::MakeInstance()
{
	return MakeShareable(new FZEDFilePathCustomization);
}

void FZEDFilePathCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	PathStringProperty = StructPropertyHandle->GetChildHandle("FilePath");

	// Same convention as the engine picker: a bare extension is expanded, a "Description|*.ext" filter is used as is
	const FString& FilterMetaData = StructPropertyHandle->GetMetaData(TEXT("FilePathFilter"));
	FString FileTypeFilter;

	if (FilterMetaData.IsEmpty())
	{
		FileTypeFilter = TEXT("All files (*.*)|*.*");
	}
	else if (FilterMetaData.Contains(TEXT("|")))
	{
		FileTypeFilter = FilterMetaData;
	}
	else
	{
		FileTypeFilter = FString::Printf(TEXT("%s files (*.%s)|*.%s"), *FilterMetaData, *FilterMetaData, *FilterMetaData);
	}

	// The engine picker omits this, so an FFilePath stays editable when CanEditChange says no
	HeaderRow.IsEnabled(TAttribute<bool>(StructPropertyHandle, &IPropertyHandle::IsEditable));

	HeaderRow
		.NameContent()
		[
			StructPropertyHandle->CreatePropertyNameWidget()
		]
		.ValueContent()
		.MaxDesiredWidth(0.0f)
		.MinDesiredWidth(125.0f)
		[
			SNew(SFilePathPicker)
			.BrowseButtonImage(FAppStyle::GetBrush("PropertyWindow.Button_Ellipsis"))
			.BrowseButtonStyle(FAppStyle::Get(), "HoverHintOnly")
			.BrowseButtonToolTip(LOCTEXT("FileButtonToolTipText", "Choose a file from this computer"))
			.BrowseDirectory(FEditorDirectories::Get().GetLastDirectory(ELastDirectory::GENERIC_OPEN))
			.BrowseTitle(LOCTEXT("PropertyEditorTitle", "File picker..."))
			.FilePath(this, &FZEDFilePathCustomization::HandleFilePath)
			.FileTypeFilter(FileTypeFilter)
			.OnPathPicked(this, &FZEDFilePathCustomization::HandlePathPicked)
		];
}

void FZEDFilePathCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, IDetailChildrenBuilder& StructBuilder, IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
}

FString FZEDFilePathCustomization::HandleFilePath() const
{
	FString FilePath;
	PathStringProperty->GetValue(FilePath);

	return FilePath;
}

void FZEDFilePathCustomization::HandlePathPicked(const FString& PickedPath)
{
	PathStringProperty->SetValue(PickedPath);
	FEditorDirectories::Get().SetLastDirectory(ELastDirectory::GENERIC_OPEN, FPaths::GetPath(PickedPath));
}

#undef LOCTEXT_NAMESPACE
