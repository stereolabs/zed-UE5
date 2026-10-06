//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

uint32 GSlGrabThreadId = 0;

bool GSlIsGrabThreadIdInitialized = false;

USlCameraProxy* GSlCameraProxy = nullptr;

bool GSlCApiAvailable = true;

void SlSetCApiUnavailable(const TCHAR* ModuleName, const ANSICHAR* MissingFunction)
{
	GSlCApiAvailable = false;

	if (MissingFunction)
	{
		UE_LOG(SlCameraProxy, Error, TEXT("sl_zed_c.dll does not export %s, needed by the %s module. It is older than this plugin, replace it with the one shipped in Stereolabs/Source/ThirdParty/sl_zed_c/bin. The ZED camera will not be opened."),
			ANSI_TO_TCHAR(MissingFunction), ModuleName);
	}
	else
	{
		UE_LOG(SlCameraProxy, Error, TEXT("sl_zed_c.dll could not be loaded by the %s module. Check it is present in Stereolabs/Source/ThirdParty/sl_zed_c/bin and that the matching ZED SDK is installed. The ZED camera will not be opened."),
			ModuleName);
	}
}