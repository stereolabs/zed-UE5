
#include "ZEDEditor/Public/ZEDInitializerDetails.h"
#include "ZEDEditor/Private/ZEDEditorPrivatePCH.h"
#include "ZED/Public/Core/ZEDInitializer.h"

TSharedRef<IDetailCustomization> FZEDInitializerDetails::MakeInstance()
{
	return MakeShareable(new FZEDInitializerDetails);
}

void FZEDInitializerDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("Zed");

	const FText FilterString = FText::FromString("parameters settings");

	const FText LoadParamettersText  = FText::FromString("Load parameters");
	const FText SaveParamettersText  = FText::FromString("Save parameters");
	const FText LoadSettingsText     = FText::FromString("Load settings");
	const FText SaveSettingsText     = FText::FromString("Save settings");
	const FText ResetParamettersText = FText::FromString("Reset parameters");
	const FText ResetSettingsText    = FText::FromString("Reset settings");

	// Cache set of selected things
	SelectedObjects = DetailBuilder.GetDetailsView()->GetSelectedObjects();

	Category.AddCustomRow(FilterString, false)
		.NameContent()
		[
			SNullWidget::NullWidget
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(350)
		[
			SNew(SBox)
			.MinDesiredWidth(350)
			[
				SNew( SHorizontalBox )
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.MaxWidth(150)
				[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.ToolTipText(FText::FromString("Load parameters from config file"))
					.OnClicked(this, &FZEDInitializerDetails::OnClickLoadParameters)
					.IsEnabled(this, &FZEDInitializerDetails::IsEnabled)
					.Content()
					[
						SNew(STextBlock)
						.Justification(ETextJustify::Center)
						.Text(LoadParamettersText)
					]
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.MaxWidth(150)
				[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.ToolTipText(FText::FromString("Save parameters to config file"))
					.OnClicked(this, &FZEDInitializerDetails::OnClickSaveParameters)
					.IsEnabled(this, &FZEDInitializerDetails::IsEnabled)
					.Content()
					[
						SNew(STextBlock)
						.Justification(ETextJustify::Center)
						.Text(SaveParamettersText)
					]
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.MaxWidth(150)
				[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.ToolTipText(FText::FromString("Reset parameters"))
					.OnClicked(this, &FZEDInitializerDetails::OnClickResetParameters)
					.IsEnabled(this, &FZEDInitializerDetails::IsEnabled)
					.Content()
					[
						SNew(STextBlock)
						.Justification(ETextJustify::Center)
						.Text(ResetParamettersText)
					]
				]
			]
		];

	Category.AddCustomRow(FilterString, false)
		.NameContent()
		[
			SNullWidget::NullWidget
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(350)
		[
			SNew(SBox)
			.MinDesiredWidth(350)
			[
				SNew( SHorizontalBox )
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.MaxWidth(150)
				[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.ToolTipText(FText::FromString("Load camera settings from config file"))
					.OnClicked(this, &FZEDInitializerDetails::OnClickLoadSettings)
					.IsEnabled(this, &FZEDInitializerDetails::IsEnabled)
					.Content()
					[
						SNew(STextBlock)
						.Justification(ETextJustify::Center)
						.Text(LoadSettingsText)
					]
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.MaxWidth(150)
				[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.ToolTipText(FText::FromString("Save camera settings to config file"))
					.OnClicked(this, &FZEDInitializerDetails::OnClickSaveSettings)
					.IsEnabled(this, &FZEDInitializerDetails::IsEnabled)
					.Content()
					[
						SNew(STextBlock)
						.Justification(ETextJustify::Center)
						.Text(SaveSettingsText)
					]
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.MaxWidth(150)
				[
					SNew(SButton)
					.VAlign(VAlign_Center)
					.ToolTipText(FText::FromString("Reset camera settings"))
					.OnClicked(this, &FZEDInitializerDetails::OnClickResetSettings)
					.IsEnabled(this, &FZEDInitializerDetails::IsEnabled)
					.Content()
					[
						SNew(STextBlock)
						.Justification(ETextJustify::Center)
						.Text(ResetSettingsText)
					]
				]
			]
		];
}

FReply FZEDInitializerDetails::OnClickResetParameters()
{
	AZEDInitializer* Initializer = static_cast<AZEDInitializer*>(SelectedObjects[0].Get());

	Initializer->ResetParameters();

	return FReply::Handled();
}

FReply FZEDInitializerDetails::OnClickResetSettings()
{
	AZEDInitializer* Initializer = static_cast<AZEDInitializer*>(SelectedObjects[0].Get());

	Initializer->ResetSettings();

	return FReply::Handled();
}

FReply FZEDInitializerDetails::OnClickSaveParameters()
{
	AZEDInitializer* Initializer = static_cast<AZEDInitializer*>(SelectedObjects[0].Get());

	Initializer->SaveParameters();

	return FReply::Handled();
}

FReply FZEDInitializerDetails::OnClickLoadParameters()
{
	AZEDInitializer* Initializer = static_cast<AZEDInitializer*>(SelectedObjects[0].Get());

	Initializer->LoadParameters();

	return FReply::Handled();
}

FReply FZEDInitializerDetails::OnClickSaveSettings()
{
	AZEDInitializer* Initializer = static_cast<AZEDInitializer*>(SelectedObjects[0].Get());

	Initializer->SaveCameraSettings();

	return FReply::Handled();
}

FReply FZEDInitializerDetails::OnClickLoadSettings()
{
	AZEDInitializer* Initializer = static_cast<AZEDInitializer*>(SelectedObjects[0].Get());

	Initializer->LoadCameraSettings();

	return FReply::Handled();
}
