//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Core/StereolabsBaseTypes.h"
#include "StereolabsPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"

FSlSpatialMappingParameters::FSlSpatialMappingParameters()
	:
	MaxMemoryUsage(2048),
	PresetResolution(ESlSpatialMappingResolution::SMR_Medium),
	PresetRange(ESlSpatialMappingRange::SMR_Auto),
	bSaveTexture(false)/*,
	bUseChunkOnly(bUseChunkOnly)*/,
	StabilityCounter(0)
{
	MaxRange = sl::SpatialMappingParameters::get(sl::unreal::ToSlType(PresetRange));
	Resolution = sl::SpatialMappingParameters::get(sl::unreal::ToSlType(PresetResolution));
	 
}

void FSlSpatialMappingParameters::SetMaxRange(ESlSpatialMappingRange NewPresetRange)
{
	PresetRange = NewPresetRange;
	MaxRange = sl::SpatialMappingParameters::get(sl::unreal::ToSlType(PresetRange));
}

void FSlSpatialMappingParameters::SetResolution(ESlSpatialMappingResolution NewPresetResolution)
{
	PresetResolution = NewPresetResolution;
	Resolution = sl::SpatialMappingParameters::get(sl::unreal::ToSlType(PresetResolution)); 
}