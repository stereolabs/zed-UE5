#include "ZEDEditor/Public/ZEDCameraDetails.h"
#include "ZEDEditor/Private/ZEDEditorPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreUtilities.h"
#include "ZED/Public/Core/ZEDCamera.h"
#include "ZEDEditor/Public/ZEDEditorCameraSession.h"
#include "DesktopPlatformModule.h"
#include "ScopedTransaction.h"
#include "PropertyHandle.h"
#include "Misc/EngineVersionComparison.h"

#define LOCTEXT_NAMESPACE "FZEDCameraDetails"

DEFINE_LOG_CATEGORY(ZEDCamera);

struct FZEDCameraDetailsGrabCallback
{
public:
	~FZEDCameraDetailsGrabCallback();

	void GrabCallback(ESlErrorCode ErrorCode);

	void Init();

	void SetSVOPlaybackTextBoxValue(int Value);

public:
	FDelegateHandle GrabDelegateHandle;

	FCriticalSection Section;

	TSharedPtr<SSlider> SVOPlaybackSlider;

	TSharedPtr<STextBlock> SVOPlaybackTextBox;

	TSharedPtr<SSpinBox<int>> SVOPlaybackSpinBox;

	bool bUpdateSVOPlaybackSlider = true;
};

FZEDCameraDetails::~FZEDCameraDetails() = default;

TSharedRef<IDetailCustomization> FZEDCameraDetails::MakeInstance()
{
	return MakeShareable(new FZEDCameraDetails);
}

void FZEDCameraDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	CachedDetailBuilder = &DetailBuilder;

#if UE_VERSION_NEWER_THAN(5, 7, 0)
	SelectedObjects = DetailBuilder.GetDetailsViewSharedPtr()->GetSelectedObjects();
#else
	SelectedObjects = DetailBuilder.GetDetailsView()->GetSelectedObjects();
#endif

	// Config IO buttons: available at design time (no camera session needed)
	{
		IDetailCategoryBuilder& ZedCategory = DetailBuilder.EditCategory("Zed");

		const FText ConfigFilterString = FText::FromString("parameters settings");

		ZedCategory.AddCustomRow(FText::FromString("zed editor camera session"), false)
			.NameContent()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("EditorSession", "Camera"))
			]
			.ValueContent()
			.VAlign(VAlign_Center)
			.MaxDesiredWidth(350)
			[
				SNew(SBox)
				.MinDesiredWidth(350)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot().VAlign(VAlign_Center).Padding(2.0f)
					[
						SNew(SButton)
						.VAlign(VAlign_Center)
						.ToolTipText(FText::FromString("Open the camera in the editor, without playing"))
						.OnClicked(this, &FZEDCameraDetails::OnClickStartEditorSession)
						.IsEnabled(this, &FZEDCameraDetails::CanStartEditorSession)
						.Content()
						[
							SNew(STextBlock)
							.Justification(ETextJustify::Center)
							.Text(FText::FromString("Start camera"))
						]
					]
					+ SHorizontalBox::Slot().VAlign(VAlign_Center).Padding(2.0f)
					[
						SNew(SButton)
						.VAlign(VAlign_Center)
						.ToolTipText(FText::FromString("Close the camera opened in the editor"))
						.OnClicked(this, &FZEDCameraDetails::OnClickStopEditorSession)
						.IsEnabled(this, &FZEDCameraDetails::CanStopEditorSession)
						.Content()
						[
							SNew(STextBlock)
							.Justification(ETextJustify::Center)
							.Text(FText::FromString("Stop camera"))
						]
					]
				]
			];

		auto MakeConfigButton = [this](const FText& Text, const FText& ToolTip, FOnClicked OnClicked)
		{
			return SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(ToolTip)
				.OnClicked(OnClicked)
				.IsEnabled(this, &FZEDCameraDetails::IsConfigIOEnabled)
				.Content()
				[
					SNew(STextBlock)
					.Justification(ETextJustify::Center)
					.Text(Text)
				];
		};

		// Each group of parameters is followed by the buttons acting on that group only
		const TPair<FName, EZEDParameterGroup> ParameterGroups[] =
		{
			{ GET_MEMBER_NAME_CHECKED(AZEDCamera, InitParameters),      EZEDParameterGroup::PG_Init           },
			{ GET_MEMBER_NAME_CHECKED(AZEDCamera, TrackingParameters),  EZEDParameterGroup::PG_Tracking       },
			{ GET_MEMBER_NAME_CHECKED(AZEDCamera, RuntimeParameters),   EZEDParameterGroup::PG_Runtime        },
			{ GET_MEMBER_NAME_CHECKED(AZEDCamera, RecordingParameters), EZEDParameterGroup::PG_Recording      },
			{ GET_MEMBER_NAME_CHECKED(AZEDCamera, CameraSettings),      EZEDParameterGroup::PG_CameraSettings },
		};

		for (const TPair<FName, EZEDParameterGroup>& ParameterGroup : ParameterGroups)
		{
			const TSharedRef<IPropertyHandle> Handle = DetailBuilder.GetProperty(ParameterGroup.Key);
			const EZEDParameterGroup Group = ParameterGroup.Value;

			// Adding the property explicitly moves it, and the row below, ahead of the properties left to the default layout
			ZedCategory.AddProperty(Handle);

			ZedCategory.AddCustomRow(ConfigFilterString, false)
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
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot().VAlign(VAlign_Center).Padding(2.0f).MaxWidth(150)
						[
							MakeConfigButton(FText::FromString("Load"), FText::FromString("Load these parameters from the config file"),
								FOnClicked::CreateSP(this, &FZEDCameraDetails::OnClickConfigAction, EZEDConfigAction::Load, Group, TSharedPtr<IPropertyHandle>(Handle)))
						]
						+ SHorizontalBox::Slot().VAlign(VAlign_Center).Padding(2.0f).MaxWidth(150)
						[
							MakeConfigButton(FText::FromString("Save"), FText::FromString("Save these parameters to the config file"),
								FOnClicked::CreateSP(this, &FZEDCameraDetails::OnClickConfigAction, EZEDConfigAction::Save, Group, TSharedPtr<IPropertyHandle>(Handle)))
						]
						+ SHorizontalBox::Slot().VAlign(VAlign_Center).Padding(2.0f).MaxWidth(150)
						[
							MakeConfigButton(FText::FromString("Reset"), FText::FromString("Reset these parameters to their defaults"),
								FOnClicked::CreateSP(this, &FZEDCameraDetails::OnClickConfigAction, EZEDConfigAction::Reset, Group, TSharedPtr<IPropertyHandle>(Handle)))
						]
					]
				];
		}
	}

	// Runtime controls need a live camera session
	if (!GSlCameraProxy)
	{
		return;
	}

	GrabCallback = MakeUnique<FZEDCameraDetailsGrabCallback>();

	IDetailCategoryBuilder& Category = DetailBuilder.EditCategory("ZedControls");
	
	// SVO recording
	const FText SVORecordginFilterString = FText::FromString("zed svo recording");

	const FText EnableRecordingText = FText::FromString("Enable");
	const FText DisableRecordingText = FText::FromString("Disable");
	const FText StartRecordingText = FText::FromString("Start");
	const FText StopRecordingText = FText::FromString("Stop");

	Category.AddCustomRow(SVORecordginFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SVORecording", "SVO Recording"))
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(250)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Enable SVO recording"))
				.OnClicked(this, &FZEDCameraDetails::OnClickEnableSVORecording)
				.IsEnabled(this, &FZEDCameraDetails::IsSVORecordingDisabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(EnableRecordingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Disable SVO recording"))
				.OnClicked(this, &FZEDCameraDetails::OnClickDisableSVORecording)
				.IsEnabled(this, &FZEDCameraDetails::IsSVORecordingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(DisableRecordingText)
				]
			]
		];

	Category.AddCustomRow(SVORecordginFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(250)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Start recording"))
				.OnClicked(this, &FZEDCameraDetails::OnClickStartSVORecording)
				.IsEnabled(this, &FZEDCameraDetails::IsSVORecordingStopped)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(StartRecordingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Stop recording"))
				.OnClicked(this, &FZEDCameraDetails::OnClickStopSVORecording)
				.IsEnabled(this, &FZEDCameraDetails::IsSVORecordingStarted)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(StopRecordingText)
				]
			]
		];

	Category.AddCustomRow(SVORecordginFilterString, false)
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

	// SVO playback
	const FText SVOPlaybackFilterString = FText::FromString("zed svo playback");

	const FText PausePlaybackText = FText::FromString("Pause");
	const FText ResumePlaybackText = FText::FromString("Resume");
	const FText NextFramePlaybackText = FText::FromString("+");
	const FText PreviousPlaybackText = FText::FromString("-");

	Category.AddCustomRow(SVOPlaybackFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SVOPlayback", "SVO Playback"))
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(250)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			.FillWidth(4)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Pause playback"))
				.OnClicked(this, &FZEDCameraDetails::OnClickPauseSVOPlayback)
				.IsEnabled(this, &FZEDCameraDetails::IsSVOPlaybackNotPaused)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(PausePlaybackText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			.FillWidth(4)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Resume playback"))
				.OnClicked(this, &FZEDCameraDetails::OnClickResumeSVOPlayback)
				.IsEnabled(this, &FZEDCameraDetails::IsSVOPlaybackPaused)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(110)
					.Justification(ETextJustify::Center)
					.Text(ResumePlaybackText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			.MaxWidth(25)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Next frame"))
				.OnClicked(this, &FZEDCameraDetails::OnClickNextFrameSVOPlayback)
				.IsEnabled(this, &FZEDCameraDetails::IsSVOPlaybackPaused)
				.Content()
				[
					SNew(STextBlock)
					.Justification(ETextJustify::Center)
					.Text(NextFramePlaybackText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			.MaxWidth(25)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Previous frame"))
				.OnClicked(this, &FZEDCameraDetails::OnClickPreviousFrameSVOPlayback)
				.IsEnabled(this, &FZEDCameraDetails::IsSVOPlaybackPaused)
				.Content()
				[
					SNew(STextBlock)
					.Justification(ETextJustify::Center)
					.Text(PreviousPlaybackText)
				]
			]
		];

	SL_SCOPE_LOCK(Lock, GrabCallback->Section)
		SAssignNew(GrabCallback->SVOPlaybackSlider, SSlider)
			.ToolTipText(FText::FromString("SVO playback position"))
			.IsEnabled(this, &FZEDCameraDetails::IsSVOPlaybackEnabled)
			.StepSize(1.0f)
			.OnMouseCaptureBegin_Lambda([this]()
			{
				OnMouseCaptureSVOPlaybackSlider();
			})
			.OnMouseCaptureEnd_Lambda([this]()
			{
				OnMouseCaptureEndSVOPlaybackSlider();
			})
			.OnValueChanged_Lambda([this](float Value)
			{
				OnValueChangedSVOPlaybackSlider(Value);
			});

		SAssignNew(GrabCallback->SVOPlaybackTextBox, STextBlock)
			.IsEnabled(true)
			.ColorAndOpacity(FSlateColor(FLinearColor::Yellow))
			.ShadowOffset(FVector2D(1, 1))
			.Justification(ETextJustify::Right)
			.Text(FText::FromString(FString("0")));

		SAssignNew(GrabCallback->SVOPlaybackSpinBox, SSpinBox<int>)
			.MinSliderValue(0)
			.MinValue(0)
			.MaxValue(0)
			.Delta(1)
			.OnValueChanged_Lambda([this](int Value)
			{
				OnValueChangedSVOPlaybackSpinBox(Value);
			})
			.OnValueCommitted_Lambda([this](int Value, ETextCommit::Type TextCommitType)
			{
				OnValueCommitedSVOPlaybackSpinBox(Value, TextCommitType);
			})
			.IsEnabled(this, &FZEDCameraDetails::IsSVOPlaybackEnabled);
	SL_SCOPE_UNLOCK

	GrabCallback->Init();

	Category.AddCustomRow(SVORecordginFilterString, false)
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
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.FillWidth(1.1)
				[
					GrabCallback->SVOPlaybackTextBox.ToSharedRef()
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.FillWidth(4.7)
				.Padding(2.0f)
				[
					GrabCallback->SVOPlaybackSlider.ToSharedRef()
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.Padding(2.0f)
				.FillWidth(1.5)
				[
					GrabCallback->SVOPlaybackSpinBox.ToSharedRef()
				]
			]
		];

	Category.AddCustomRow(SVOPlaybackFilterString, false)
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

	// Tracking
	const FText TrackingFilterString = FText::FromString("zed tracking");

	const FText EnableTrackingText = FText::FromString("Enable");
	const FText DisableTrackingText = FText::FromString("Disable");
	const FText ResetTrackingText = FText::FromString("Reset");
	const FText SaveTrackingAreaText = FText::FromString("Save area");

	Category.AddCustomRow(TrackingFilterString, false)
		.NameContent()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Tracking", "Tracking"))
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(250)
		[
			SNew( SHorizontalBox )
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Enable tracking"))
				.OnClicked(this, &FZEDCameraDetails::OnClickEnableTracking)
				.IsEnabled(this, &FZEDCameraDetails::IsTrackingDisabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(125)
					.Justification(ETextJustify::Center)
					.Text(EnableTrackingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Disable tracking"))
				.OnClicked(this, &FZEDCameraDetails::OnClickDisableTracking)
				.IsEnabled(this, &FZEDCameraDetails::IsTrackingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(125)
					.Justification(ETextJustify::Center)
					.Text(DisableTrackingText)
				]
			]
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Reset tracking"))
				.OnClicked(this, &FZEDCameraDetails::OnClickResetTracking)
				.IsEnabled(this, &FZEDCameraDetails::IsTrackingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(50)
					.Justification(ETextJustify::Center)
					.Text(ResetTrackingText)
				]
			]
		];

	Category.AddCustomRow(TrackingFilterString, false)
		.NameContent()
		[
			SNullWidget::NullWidget
		]
		.ValueContent()
		.VAlign(VAlign_Center)
		.MaxDesiredWidth(75)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.VAlign(VAlign_Center)
			.Padding(2.0f)
			[
				SNew(SButton)
				.VAlign(VAlign_Center)
				.ToolTipText(FText::FromString("Save tracking area"))
				.OnClicked(this, &FZEDCameraDetails::OnClickSaveTrackingArea)
				.IsEnabled(this, &FZEDCameraDetails::IsSpatialMappingEnabled)
				.Content()
				[
					SNew(STextBlock)
					.MinDesiredWidth(75)
					.Justification(ETextJustify::Center)
					.Text(SaveTrackingAreaText)
				]
			]
		];
}

FReply FZEDCameraDetails::OnClickEnableSVORecording()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	ZedCameraActor->EnableSVORecording();

	CachedDetailBuilder->ForceRefreshDetails();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickDisableSVORecording()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	ZedCameraActor->DisableSVORecording();

	CachedDetailBuilder->ForceRefreshDetails();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickStartSVORecording()
{
	GSlCameraProxy->SetSVORecordFrames(true);

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickStopSVORecording()
{
	GSlCameraProxy->SetSVORecordFrames(false);

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickPauseSVOPlayback()
{
	GSlCameraProxy->PauseSVOplayback(true);

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickResumeSVOPlayback()
{
	GSlCameraProxy->PauseSVOplayback(false);

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickNextFrameSVOPlayback()
{
	GSlCameraProxy->SetSVOPlaybackPosition(GSlCameraProxy->GetSVOPlaybackPosition());

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickPreviousFrameSVOPlayback()
{
	GSlCameraProxy->SetSVOPlaybackPosition(GSlCameraProxy->GetSVOPlaybackPosition() - 2);

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickResetTracking()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	ZedCameraActor->ResetTrackingOrigin();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickEnableTracking()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	ZedCameraActor->EnableTracking();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickDisableTracking()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	ZedCameraActor->DisableTracking();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickSaveTrackingArea()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	FString CurrentPath = ZedCameraActor->TrackingParameters.AreaFilePath;
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
	if (FDesktopPlatformModule::Get()->SaveFileDialog(nullptr, TEXT("Saving area file"), Path, FileName, TEXT("ZED area file|.area"), EFileDialogFlags::Type::None, SelectedFile))
	{
		FString FullPath = FPaths::ConvertRelativePathToFull(SelectedFile[0]);
		GSlCameraProxy->SaveSpatialMemoryArea(FullPath);

		SL_LOG_W(ZEDCamera, "Area file saved : %s", *FullPath);
	}
	else
	{
		SL_LOG_W(ZEDCamera, "Area file not saved");
	}

	return FReply::Handled();
}

bool FZEDCameraDetails::CanStartEditorSession() const
{
	const UZEDEditorCameraSession* Session = UZEDEditorCameraSession::Get();

	return IsConfigIOEnabled() && Session && !Session->IsRunning();
}

bool FZEDCameraDetails::CanStopEditorSession() const
{
	const UZEDEditorCameraSession* Session = UZEDEditorCameraSession::Get();

	return IsConfigIOEnabled() && Session && Session->IsRunning() && Session->GetCamera() == SelectedObjects[0].Get();
}

FReply FZEDCameraDetails::OnClickStartEditorSession()
{
	AZEDCamera* ZedCameraActor = static_cast<AZEDCamera*>(SelectedObjects[0].Get());

	FString Error;
	if (!UZEDEditorCameraSession::Get()->Start(ZedCameraActor, Error))
	{
		SL_LOG_E(ZEDCamera, "Can't open the camera in the editor: %s", *Error);

		return FReply::Handled();
	}

	// Destroys this customization, the runtime controls become available
	CachedDetailBuilder->ForceRefreshDetails();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickStopEditorSession()
{
	UZEDEditorCameraSession::Get()->Stop();

	// Destroys this customization
	CachedDetailBuilder->ForceRefreshDetails();

	return FReply::Handled();
}

FReply FZEDCameraDetails::OnClickConfigAction(EZEDConfigAction Action, EZEDParameterGroup Group, TSharedPtr<IPropertyHandle> Handle)
{
	AZEDCamera* ZedCameraActor = Cast<AZEDCamera>(SelectedObjects[0].Get());
	if (!ZedCameraActor || !Handle.IsValid() || !Handle->IsValidHandle())
	{
		return FReply::Handled();
	}

	if (Action == EZEDConfigAction::Save)
	{
		ZedCameraActor->SaveParameterGroup(Group);

		return FReply::Handled();
	}

	// Going through the property handle keeps undo, the dirty flag and the panel refresh working
	const FScopedTransaction Transaction(Action == EZEDConfigAction::Load
		? LOCTEXT("LoadParameterGroup", "Load ZED parameters")
		: LOCTEXT("ResetParameterGroup", "Reset ZED parameters"));

	ZedCameraActor->Modify();

	Handle->NotifyPreChange();

	if (Action == EZEDConfigAction::Load)
	{
		ZedCameraActor->LoadParameterGroup(Group);
	}
	else
	{
		ZedCameraActor->ResetParameterGroup(Group);
	}

	Handle->NotifyPostChange(EPropertyChangeType::ValueSet);
	Handle->NotifyFinishedChangingProperties();

	return FReply::Handled();
}

void FZEDCameraDetails::OnMouseCaptureSVOPlaybackSlider()
{
	SL_SCOPE_LOCK(Lock, GrabCallback->Section)
		GrabCallback->bUpdateSVOPlaybackSlider = false;
	SL_SCOPE_UNLOCK
}

void FZEDCameraDetails::OnMouseCaptureEndSVOPlaybackSlider()
{
	if (GSlCameraProxy->bSVOPlaybackPaused)
	{
		GSlCameraProxy->PauseSVOplayback(true, SVOPlaybackSliderValue);
	}
	else
	{
		GSlCameraProxy->SetSVOPlaybackPosition(SVOPlaybackSliderValue);
	}

	SL_SCOPE_LOCK(Lock, GrabCallback->Section)
		GrabCallback->bUpdateSVOPlaybackSlider = true;
		GrabCallback->SVOPlaybackSpinBox->SetValue(SVOPlaybackSliderValue);
	SL_SCOPE_UNLOCK;
}

void FZEDCameraDetails::OnValueChangedSVOPlaybackSlider(float Value)
{
	int MaxValue = GSlCameraProxy->GetSVONumberOfFrames() - 1;
	SVOPlaybackSliderValue = FMath::Min(MaxValue, FMath::CeilToInt(Value * MaxValue));

	SL_SCOPE_LOCK(Lock, GrabCallback->Section)
		GrabCallback->SetSVOPlaybackTextBoxValue(SVOPlaybackSliderValue);
	SL_SCOPE_UNLOCK
}

void FZEDCameraDetailsGrabCallback::SetSVOPlaybackTextBoxValue(int Value)
{
	SVOPlaybackTextBox->SetText(FText::FromString(FString::FromInt(Value)));
}

void FZEDCameraDetails::OnValueChangedSVOPlaybackSpinBox(int Value)
{
	SVOPlaybackSpinBoxValue = Value;
}

void FZEDCameraDetails::OnValueCommitedSVOPlaybackSpinBox(int Value, ETextCommit::Type TextCommitType)
{
	if (TextCommitType == ETextCommit::OnEnter)
	{
		if (GSlCameraProxy->bSVOPlaybackPaused)
		{
			GSlCameraProxy->PauseSVOplayback(true, Value);
		}
		else
		{
			GSlCameraProxy->SetSVOPlaybackPosition(Value);
		}
	}
}

FZEDCameraDetailsGrabCallback::~FZEDCameraDetailsGrabCallback()
{
	SL_SCOPE_LOCK(Lock, Section)
		if (GSlCameraProxy)
		{
			GSlCameraProxy->RemoveFromGrabDelegate(GrabDelegateHandle);
		}
	SL_SCOPE_UNLOCK
}

void FZEDCameraDetailsGrabCallback::Init()
{
	if (GSlCameraProxy->bSVOPlaybackEnabled)
	{
		GrabDelegateHandle = GSlCameraProxy->AddToGrabDelegate([this](ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp) 
		{
				GrabCallback(ErrorCode);
		});
	}
}

void FZEDCameraDetailsGrabCallback::GrabCallback(ESlErrorCode ErrorCode)
{
	// Runs on the grab thread, where Slate must not be touched at all
	const int MaxValue = GSlCameraProxy->GetSVONumberOfFrames() - 1;

	TSharedPtr<SSpinBox<int>> SpinBox;
	TSharedPtr<SSlider> Slider;
	TSharedPtr<STextBlock> TextBox;
	int SVOPosition = INDEX_NONE;

	SL_SCOPE_LOCK(Lock, Section)
		SpinBox = SVOPlaybackSpinBox;

		if (bUpdateSVOPlaybackSlider)
		{
			Slider = SVOPlaybackSlider;
			TextBox = SVOPlaybackTextBox;
			SVOPosition = GSlCameraProxy->GetSVOPlaybackPosition() - 1;
		}
	SL_SCOPE_UNLOCK

	// The widgets are held by value, so a details panel closing before this runs is harmless
	AsyncTask(ENamedThreads::GameThread, [SpinBox, Slider, TextBox, SVOPosition, MaxValue]()
	{
		if (MaxValue > 0 && SpinBox.IsValid() && SpinBox->GetMaxValue() == 0)
		{
			SpinBox->SetMaxSliderValue(MaxValue);
			SpinBox->SetMaxValue(MaxValue);
		}

		if (MaxValue > 0 && SVOPosition != INDEX_NONE && Slider.IsValid() && TextBox.IsValid())
		{
			Slider->SetValue((float)SVOPosition / (float)MaxValue);
			TextBox->SetText(FText::FromString(FString::FromInt(SVOPosition)));
		}
	});
}

#undef  LOCTEXT_NAMESPACE