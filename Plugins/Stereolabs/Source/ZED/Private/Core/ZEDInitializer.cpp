//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDInitializer.h"
#include "ZEDPrivatePCH.h"
#include "ZED/Public/Utilities/ZEDFunctionLibrary.h"

#if WITH_EDITOR
#define ZED_CONFIG_FILE_PATH			FPaths::Combine(*FPaths::ProjectDir(), *FString("Saved/Config/ZED/ZED.ini"))
#define ZED_CAMERA_CONFIG_FILE_PATH     FPaths::Combine(*FPaths::ProjectDir(), *FString("Saved/Config/ZED/Camera.ini"))
#define DEFAULT_VERBOSE_FILE_PATH       FPaths::Combine(*FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()), *FString("Binaries/Win64/ZedLog.txt"))
#else
#define ZED_CONFIG_FILE_PATH			FPaths::Combine(*FPaths::ConvertRelativePathToFull("../../"), *FString("Saved/Config/ZED/ZED.ini"))
#define ZED_CAMERA_CONFIG_FILE_PATH     FPaths::Combine(*FPaths::ConvertRelativePathToFull("../../"), *FString("Saved/Config/ZED/Camera.ini"))
#define DEFAULT_VERBOSE_FILE_PATH       FPaths::Combine(*FPaths::ConvertRelativePathToFull("."),      *FString("ZedLog.txt"))
#endif

bool CheckGConfigAvailable()
{
	if (!GConfig)
	{
		SL_LOG_E(ZEDFunctionLibrary, "GConfig not available");
		return false;
	}

	return true;
}

AZEDInitializer::AZEDInitializer()
	:
	bLoadParametersFromConfigFile(false),
	bLoadCameraSettingsFromConfigFile(false),
	bUseHMDTrackingAsOrigin(false),
	bDepthOcclusion(true),
	bShowZedImage(true),
	ImageView(ESlView::V_Left)
{
	if (InitParameters.VerboseFilePath.IsEmpty())
	{
		InitParameters.VerboseFilePath = DEFAULT_VERBOSE_FILE_PATH;
	}

	DepthClampThreshold = InitParameters.DepthMaximumDistance;
}

#if WITH_EDITOR
void AZEDInitializer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

bool AZEDInitializer::CanEditChange(const FProperty* InProperty) const
{
	FName PropertyName = InProperty->GetFName();

	if (InProperty->GetOwnerStruct())
	{
		FString StructName = InProperty->GetOwnerStruct()->GetName();

		if (StructName == FString("SlCameraSettings"))
		{
			return !(InitParameters.InputType == ESlInputType::IT_SVO);
		}
		
		if (StructName == FString("SlRuntimeParameters"))
		{
			if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlRuntimeParameters, ReferenceFrame))
			{
				return false;
			}

			return true;
		}
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, Resolution) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FSlRecordingParameters, VideoFilename) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FSlRecordingParameters, CompressionMode)
		)
	{
		return !(InitParameters.InputType == ESlInputType::IT_SVO);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, SvoPath) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, bRealTime) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, bLoop))
	{
		return (InitParameters.InputType == ESlInputType::IT_SVO);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, StreamIP) ||
		PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, StreamPort))
	{
		return (InitParameters.InputType == ESlInputType::IT_STREAM);
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlInitParameters, DepthMode))
	{
		return RuntimeParameters.bEnableDepth;
	}

	if(PropertyName == GET_MEMBER_NAME_CHECKED(FSlPositionalTrackingParameters, Location) || 
	   PropertyName == GET_MEMBER_NAME_CHECKED(FSlPositionalTrackingParameters, Rotation))
	{
		return !bUseHMDTrackingAsOrigin;
	}

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FSlPositionalTrackingParameters, bEnablePoseSmoothing))
	{
		return TrackingParameters.bEnableAreaMemory;
	}

	return Super::CanEditChange(InProperty);
}
#endif

void AZEDInitializer::LoadParametersAndSettings()
{
	if (bLoadParametersFromConfigFile)
	{
		LoadParameters();
	}
	if (bLoadCameraSettingsFromConfigFile)
	{
		LoadCameraSettings();
	}

	LoadAntiDriftParameters();
}

void AZEDInitializer::LoadParameters()
{
	if (!CheckGConfigAvailable())
	{
		return;
	}

	FString Path = ZED_CONFIG_FILE_PATH;
	FConfigFile* ConfigFile = GConfig->Find(Path);

	if (!ConfigFile)
	{
		SaveParameters();
	}
	else
	{
		InitParameters.Load(Path);
		if (InitParameters.VerboseFilePath.IsEmpty())
		{
			InitParameters.VerboseFilePath = DEFAULT_VERBOSE_FILE_PATH;
		}

		TrackingParameters.Load(Path);
		RuntimeParameters.Load(Path);
		RenderingParameters.Load(Path);
		RecordingParameters.Load(Path);
	}
}

void AZEDInitializer::LoadCameraSettings()
{
	if (!CheckGConfigAvailable())
	{
		return;
	}

	FString Path = ZED_CAMERA_CONFIG_FILE_PATH;
	FConfigFile* ConfigFile = GConfig->Find(Path);

	if (!ConfigFile)
	{
		SaveCameraSettings();
	}
	else
	{
		CameraSettings.Load(Path);
	}
}

void AZEDInitializer::SaveParameters()
{
	if (!CheckGConfigAvailable())
	{
		return;
	}

	FString Path = ZED_CONFIG_FILE_PATH;
	
#if WITH_EDITOR
	if (InitParameters.VerboseFilePath == DEFAULT_VERBOSE_FILE_PATH)
	{
		InitParameters.VerboseFilePath.Empty();
	}
#endif

	InitParameters.Save(Path);
	TrackingParameters.Save(Path);
	RuntimeParameters.Save(Path);
	RenderingParameters.Save(Path);
	RecordingParameters.Save(Path);

	GConfig->Flush(false, *Path);
}

void AZEDInitializer::SaveCameraSettings()
{
	if (!CheckGConfigAvailable())
	{
		return;
	}

	FString Path = ZED_CAMERA_CONFIG_FILE_PATH;
	CameraSettings.Save(Path);

	GConfig->Flush(false, *Path);
}

void AZEDInitializer::ResetParameters()
{
	InitParameters = FSlInitParameters();
	if (InitParameters.VerboseFilePath.IsEmpty())
	{
		InitParameters.VerboseFilePath = DEFAULT_VERBOSE_FILE_PATH;
	}

	TrackingParameters = FSlPositionalTrackingParameters();
	RuntimeParameters = FSlRuntimeParameters();
	RenderingParameters = FSlRenderingParameters();

	ObjectDetectionParameters = FSlObjectDetectionParameters();
	ObjectDetectionRuntimeParameters = FSlObjectDetectionRuntimeParameters();

	bDepthOcclusion = true;
	DepthClampThreshold = InitParameters.DepthMaximumDistance;

	ImageView = ESlView::V_Left;

	bShowZedImage = true;
}

void AZEDInitializer::ResetSettings()
{
	CameraSettings = FSlVideoSettings();
}

void AZEDInitializer::LoadAntiDriftParameters()
{
	if (!CheckGConfigAvailable())
	{
		return;
	}

	// Path set in build.cs
	FString Path = ZED_CALIBRAITON_FILE_PATH;
	FConfigFile* ConfigFile = GConfig->Find(Path);

	if (!ConfigFile)
	{
		AntiDriftParameters.Save(Path);

		GConfig->Flush(false, *Path);
	}
	else
	{
		AntiDriftParameters.Load(Path);
	}
}
