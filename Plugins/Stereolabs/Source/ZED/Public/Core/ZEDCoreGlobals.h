//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "ZED/Public/Core/ZEDBaseTypes.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"

#include "sl_mr_core/defines.hpp"

/** Current frame tracking data */
extern ZED_API FZEDTrackingData GZedTrackingData;

/** Current Zed rotation (stereo/mono). Same as GZedViewPointRotation in mono. Antidrifted rotation in stereo. */
extern ZED_API FRotator GZedRawRotation;

/** Current Zed location (stereo/mono). Same as GZedViewPointLocation in mono. Antidrifted location in stereo.  */
extern ZED_API FVector GZedRawLocation;

/** Current view point rotation, head(stereo)/camera(mono) */
extern ZED_API FRotator GZedViewPointRotation;

/** Current view point location, head(stereo)/camera(mono) */
extern ZED_API FVector GZedViewPointLocation;

namespace sl
{
	namespace unreal
	{
		/*
		 * Convert from FZEDTrackingData to sl::mr::trackingData
		 */
		FORCEINLINE sl::mr::trackingData ToSlType(const FZEDTrackingData& UnrealType)
		{
			sl::mr::trackingData TrackingData;

			TrackingData.zedPathTransform = ToEigenType(UnrealType.ZedPathTransform);
			TrackingData.zedWorldTransform = ToEigenType(UnrealType.ZedWorldTransform);
			TrackingData.trackingState = (int)sl::unreal::ToSlType(UnrealType.TrackingState);

			return TrackingData;
		}

		/*
		 * Convert from sl::mr::noiseFactors to FZEDNoiseFactors
		 */
		FORCEINLINE FZEDNoiseFactors ToUnrealType(const sl::mr::noiseFactors& SlData)
		{
			return FZEDNoiseFactors(sl::unreal::ToUnrealType(SlData.r), sl::unreal::ToUnrealType(SlData.g), sl::unreal::ToUnrealType(SlData.b));
		}
	}
}