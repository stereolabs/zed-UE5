///======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Public/Core/ZEDCoreGlobals.h"
#include "ZEDPrivatePCH.h"

FZEDTrackingData GZedTrackingData = FZEDTrackingData();

FRotator GZedRawRotation = FRotator::ZeroRotator;

FVector GZedRawLocation = FVector::ZeroVector;

FRotator GZedViewPointRotation = FRotator::ZeroRotator;

FVector GZedViewPointLocation = FVector::ZeroVector;