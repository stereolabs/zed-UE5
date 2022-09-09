// Fill out your copyright notice in the Description page of Project Settings.

#include "SamplesBlueprintFunctionLibrary.h"
#include "EngineGlobals.h"
#include "Engine/Engine.h"
#include "IHeadMountedDisplay.h"
#include "IXRTrackingSystem.h"

EHMDType USamplesBlueprintFunctionLibrary::GetHMDType()
{
	if (GEngine->XRSystem.IsValid() && GEngine->XRSystem->GetHMDDevice())
	{
		if (GEngine->StereoRenderingDevice.IsValid())
		{
			FName Type = GEngine->XRSystem->GetSystemName();

			if (Type == TEXT("OculusHMD"))
			{
				return EHMDType::T_Oculus;
			}
			else if (Type == TEXT("SteamVR"))
			{
				return EHMDType::T_Vive;
			}
		}
	}

	return EHMDType::T_Unknown;
}