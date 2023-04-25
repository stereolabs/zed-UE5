//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

uint32 GSlGrabThreadId = 0;

bool GSlIsGrabThreadIdInitialized = false;

USlCameraProxy* GSlCameraProxy = nullptr;