//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "SpatialMappingEditor/Public/SpatialMappingManagerDetails.h"
#include "SpatialMappingEditor/Private/SpatialMappingEditorPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"
#include "DesktopPlatformModule.h"

#define LOCTEXT_NAMESPACE "FSpatialMappingManagerDetails"

DEFINE_LOG_CATEGORY(SpatialMappingManagerDetails);

TSharedRef<IDetailCustomization> FSpatialMappingManagerDetails::MakeInstance()
{
	return MakeShareable(new FSpatialMappingManagerDetails);
}

void FSpatialMappingManagerDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	if (!GSlCameraProxy)
	{
		return;
	}

	CachedDetailBuilder = &DetailBuilder;
	SelectedObjects = DetailBuilder.GetDetailsView()->GetSelectedObjects();

	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("Spatial Mapping Controls");

	const FText SpatialMappingFilterString = FText::FromString("zed SpatialMapping");

	const FText EnableSpatialMappingText = FText::FromString("Enable");
	const FText DisableSpatialMappingText = FText::FromString("Disable");
	const FText ResetSpatialMappingText = FText::FromString("Reset");

	Category.AddCustomRow(SpatialMappingFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SpatialMapping", "SpatialMapping"))
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(325)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Enable SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickEnableSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingDisabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(EnableSpatialMappingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Disable SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickDisableSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(DisableSpatialMappingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Reset SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickResetSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(ResetSpatialMappingText)
				]
			]
		];

	
	const FText StartSpatialMappingText = FText::FromString("Start");
	const FText PauseSpatialMappingText = FText::FromString("Pause");
	const FText ResumeSpatialMappingText = FText::FromString("Resume");
	const FText StopSpatialMappingText = FText::FromString("Stop");

	Category.AddCustomRow(SpatialMappingFilterString, false)
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(325)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Start SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickStartSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingStopped)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(StartSpatialMappingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Pause SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickPauseSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingNotPaused)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(PauseSpatialMappingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Resume SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickResumeSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingPaused)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(ResumeSpatialMappingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Stop SpatialMapping"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickStopSpatialMapping)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingStarted)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(StopSpatialMappingText)
				]
			]
		];

	Category.AddCustomRow(SpatialMappingFilterString, false)
		.NameContent()
		[
			SNullWidget::NullWidget
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Fill)
		[
			SNew(SSeparator)
			.Orientation(EOrientation::Orient_Horizontal)
		];

	const FText FilterText = FText::FromString("Filter");
	const FText TextureText = FText::FromString("Texture");

	Category.AddCustomRow(SpatialMappingFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Mesh post-process", "Mesh post-process"))
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(325)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Filter mesh"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickFilterMesh)
				.IsEnabled(this, &FSpatialMappingManagerDetails::HasMeshVertices)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(FilterText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Texture mesh"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickTextureMesh)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsTexturingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(TextureText)
				]
			]
		];

	Category.AddCustomRow(SpatialMappingFilterString, false)
		.NameContent()
		[
			SNullWidget::NullWidget
		]
	.ValueContent()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Fill)
		[
			SNew(SSeparator)
			.Orientation(EOrientation::Orient_Horizontal)
		];

	const FText LoadMeshText = FText::FromString("Load");
	const FText SaveMeshText = FText::FromString("Save");

	Category.AddCustomRow(SpatialMappingFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Mesh operations", "Mesh operations"))
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(325)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Load mesh"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickLoadMesh)
				.IsEnabled(this, &FSpatialMappingManagerDetails::IsSpatialMappingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(LoadMeshText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Save mesh"))
				.OnClicked(this, &FSpatialMappingManagerDetails::OnClickSaveMesh)
				.IsEnabled(this, &FSpatialMappingManagerDetails::HasMeshVertices)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(SaveMeshText)
				]
			]
		];
}

FReply FSpatialMappingManagerDetails::OnClickEnableSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->EnableSpatialMapping();

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickDisableSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->DisableSpatialMapping();

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickResetSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->ResetSpatialMapping();

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickStartSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->StartSpatialMapping();

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickPauseSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->PauseSpatialMapping(true);

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickResumeSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->PauseSpatialMapping(false);

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickStopSpatialMapping()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->StopSpatialMapping();

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickFilterMesh()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->FilterMesh();

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickTextureMesh()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	SpatialMappingManager->TextureMesh(ESpatialMappingTexturingMode::TM_Render);

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickLoadMesh()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	FString CurrentPath = SpatialMappingManager->MeshLoadingPath;
	FString Path;
	FString FileName;

	if (!CurrentPath.IsEmpty())
	{
		int LastSeparatorIndex = INDEX_NONE;
		if (!CurrentPath.FindLastChar('\\', LastSeparatorIndex))
		{
			CurrentPath.FindLastChar('/', LastSeparatorIndex);
		}

		if (LastSeparatorIndex != INDEX_NONE)
		{
			Path = CurrentPath.LeftChop(CurrentPath.Len() - 1 - LastSeparatorIndex);
			FileName = CurrentPath.RightChop(LastSeparatorIndex + 1);
		}
	}

	TArray<FString> SelectedFile;
	if (FDesktopPlatformModule::Get()->OpenFileDialog(nullptr, TEXT("Loading mesh"), Path, FileName, TEXT("Mesh|*.obj|Poly|*.ply"), EFileDialogFlags::Type::None, SelectedFile))
	{
		FString FullPath = FPaths::ConvertRelativePathToFull(SelectedFile[0]);
		SpatialMappingManager->MeshLoadingPath = SelectedFile[0];
		SpatialMappingManager->LoadMesh();

		SL_LOG_W(SpatialMappingManagerDetails, "Mesh loaded : %s", *FullPath);
	}
	else
	{
		SL_LOG_W(SpatialMappingManagerDetails, "Mesh not loaded");
	}

	return FReply::Handled();
}

FReply FSpatialMappingManagerDetails::OnClickSaveMesh()
{
	ASpatialMappingManager* SpatialMappingManager = static_cast<ASpatialMappingManager*>(SelectedObjects[0].Get());

	FString CurrentPath = SpatialMappingManager->MeshSavingPath;
	FString Path;
	FString FileName;

	if (!CurrentPath.IsEmpty())
	{
		int LastSeparatorIndex = INDEX_NONE;
		if (!CurrentPath.FindLastChar('\\', LastSeparatorIndex))
		{
			CurrentPath.FindLastChar('/', LastSeparatorIndex);
		}

		if (LastSeparatorIndex != INDEX_NONE)
		{
			Path = CurrentPath.LeftChop(CurrentPath.Len() - 1 - LastSeparatorIndex);
			FileName = CurrentPath.RightChop(LastSeparatorIndex + 1);
		}
	}

	TArray<FString> SelectedFile;
	if (FDesktopPlatformModule::Get()->SaveFileDialog(nullptr, TEXT("Saving mesh"), Path, FileName, TEXT("Mesh|*.obj|Poly|*.ply"), EFileDialogFlags::Type::None, SelectedFile))
	{
		FString FullPath = FPaths::ConvertRelativePathToFull(SelectedFile[0]);
		SpatialMappingManager->MeshSavingPath = SelectedFile[0];
		SpatialMappingManager->SaveMesh();

		SL_LOG_W(SpatialMappingManagerDetails, "Mesh saved : %s", *FullPath);
	}
	else
	{
		SL_LOG_W(SpatialMappingManagerDetails, "Mesh not saved");
	}

	return FReply::Handled();
}

#undef  LOCTEXT_NAMESPACE