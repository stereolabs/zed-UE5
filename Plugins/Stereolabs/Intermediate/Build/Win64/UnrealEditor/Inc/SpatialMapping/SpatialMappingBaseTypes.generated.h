// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPATIALMAPPING_SpatialMappingBaseTypes_generated_h
#error "SpatialMappingBaseTypes.generated.h already included, missing '#pragma once' in SpatialMappingBaseTypes.h"
#endif
#define SPATIALMAPPING_SpatialMappingBaseTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_zed_UE5_Plugins_Stereolabs_Source_SpatialMapping_Public_Core_SpatialMappingBaseTypes_h


#define FOREACH_ENUM_ESPATIALMAPPINGSTEP(op) \
	op(ESpatialMappingStep::SS_Scan) \
	op(ESpatialMappingStep::SS_Filter) \
	op(ESpatialMappingStep::SS_Texture) \
	op(ESpatialMappingStep::SS_Load) \
	op(ESpatialMappingStep::SS_Save) \
	op(ESpatialMappingStep::SS_Pause) \
	op(ESpatialMappingStep::SS_None) 

enum class ESpatialMappingStep : uint8;
template<> SPATIALMAPPING_API UEnum* StaticEnum<ESpatialMappingStep>();

#define FOREACH_ENUM_ESPATIALMAPPINGTEXTURINGMODE(op) \
	op(ESpatialMappingTexturingMode::TM_Cubemap) \
	op(ESpatialMappingTexturingMode::TM_Render) \
	op(ESpatialMappingTexturingMode::TM_None) 

enum class ESpatialMappingTexturingMode : uint8;
template<> SPATIALMAPPING_API UEnum* StaticEnum<ESpatialMappingTexturingMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
