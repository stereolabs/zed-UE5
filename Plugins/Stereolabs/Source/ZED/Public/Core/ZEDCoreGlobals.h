//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "ZED/Public/Core/ZEDBaseTypes.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"

/** Current frame tracking data */
extern ZED_API FZEDTrackingData GZedTrackingData;

/** Current Zed rotation */
extern ZED_API FRotator GZedRawRotation;

/** Current Zed location */
extern ZED_API FVector GZedRawLocation;

/** Current view point rotation */
extern ZED_API FRotator GZedViewPointRotation;

/** Current view point location */
extern ZED_API FVector GZedViewPointLocation;