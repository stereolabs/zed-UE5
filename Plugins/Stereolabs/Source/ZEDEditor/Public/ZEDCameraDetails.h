//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"
#include "IDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "Templates/UniquePtr.h"

struct FZEDCameraDetailsGrabCallback;

class FZEDCameraDetails : public IDetailCustomization
{
public:
	~FZEDCameraDetails();

	/** Makes a new instance of this detail layout class for a specific detail view requesting it */
	static TSharedRef<IDetailCustomization> MakeInstance();

	/** IDetailCustomization interface */
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder) override;

	/** Button enabled */
	bool IsSVORecordingEnabled() const { return GSlCameraProxy && GSlCameraProxy->bSVORecordingEnabled && GSlCameraProxy->GetSVONumberOfFrames() == -1; }

	/** Button enabled */
	bool IsSVORecordingDisabled() const { return GSlCameraProxy && !GSlCameraProxy->bSVORecordingEnabled && GSlCameraProxy->GetSVONumberOfFrames() == -1; }

	/** Button enabled */
	bool IsSVORecordingStarted() const { return IsSVORecordingEnabled() && GSlCameraProxy->bSVORecordingFrames;  }

	/** Button enabled */
	bool IsSVORecordingStopped() const { return IsSVORecordingEnabled() && !GSlCameraProxy->bSVORecordingFrames; }

	/** Clicking the enable SVO recording button */
	FReply OnClickEnableSVORecording();

	/** Clicking the disable SVO recording button */
	FReply OnClickDisableSVORecording();

	/** Clicking the start SVO recording button */
	FReply OnClickStartSVORecording();

	/** Clicking the stop SVO recording button */
	FReply OnClickStopSVORecording();

	/** Button enabled */
	bool IsSVOPlaybackEnabled() const { return GSlCameraProxy && GSlCameraProxy->GetSVONumberOfFrames() > -1; }

	/** Button enabled */
	bool IsSVOPlaybackPaused() const { return IsSVOPlaybackEnabled() && GSlCameraProxy->bSVOPlaybackPaused; }

	/** Button enabled */
	bool IsSVOPlaybackNotPaused() const { return IsSVOPlaybackEnabled() && !GSlCameraProxy->bSVOPlaybackPaused; }

	/** Clicking the pause SVO playback button */
	FReply OnClickPauseSVOPlayback();

	/** Clicking the resume SVO playback button */
	FReply OnClickResumeSVOPlayback();

	/** Clicking the resume SVO playback button */
	FReply OnClickNextFrameSVOPlayback();

	/** Clicking the resume SVO playback button */
	FReply OnClickPreviousFrameSVOPlayback();

	/** Button enabled */
	bool IsTrackingEnabled() const { return GSlCameraProxy && GSlCameraProxy->IsTrackingEnabled(); }

	/** Button enabled */
	bool IsTrackingDisabled() const { return GSlCameraProxy && !GSlCameraProxy->IsTrackingEnabled(); }

	/** Button enabled */
	bool IsSpatialMappingEnabled() const { return GSlCameraProxy && GSlCameraProxy->bSpatialMappingEnabled; }

	/** Clicking the reset tracking button */
	FReply OnClickResetTracking();

	/** Clicking the enable tracking button */
	FReply OnClickEnableTracking();

	/** Clicking the disable tracking button */
	FReply OnClickDisableTracking();

	/** Clicking the save tracking area button */
	FReply OnClickSaveTrackingArea();

	/** Config IO buttons enabled (design time authoring) */
	bool IsConfigIOEnabled() const { return SelectedObjects.Num() == 1 && SelectedObjects[0].IsValid(); }

	/** Button enabled */
	bool CanStartEditorSession() const;

	/** Button enabled */
	bool CanStopEditorSession() const;

	/** Clicking the start camera button */
	FReply OnClickStartEditorSession();

	/** Clicking the stop camera button */
	FReply OnClickStopEditorSession();

	/** Clicking the load parameters button */
	FReply OnClickLoadParameters();

	/** Clicking the save parameters button */
	FReply OnClickSaveParameters();

	/** Clicking the reset parameters button */
	FReply OnClickResetParameters();

	/** Clicking the load camera settings button */
	FReply OnClickLoadSettings();

	/** Clicking the save camera settings button */
	FReply OnClickSaveSettings();

	/** Clicking the reset camera settings button */
	FReply OnClickResetSettings();

private:
	void OnMouseCaptureSVOPlaybackSlider();
	void OnMouseCaptureEndSVOPlaybackSlider();
	void OnValueChangedSVOPlaybackSlider(float Value);

	void OnValueChangedSVOPlaybackSpinBox(int Value);
	void OnValueCommitedSVOPlaybackSpinBox(int Value, ETextCommit::Type TextCommitType);

private:
	/** Can only be one camera actor */
	TArray<TWeakObjectPtr<UObject>> SelectedObjects;

	/** Detail builder used to draw */
	IDetailLayoutBuilder* CachedDetailBuilder;

	/** Owned per customization instance: a details refresh builds the new one before destroying the old */
	TUniquePtr<FZEDCameraDetailsGrabCallback> GrabCallback;

	bool bIsSVOplaybackPaused;

	int SVOPlaybackSliderValue;

	int SVOPlaybackSpinBoxValue;
};