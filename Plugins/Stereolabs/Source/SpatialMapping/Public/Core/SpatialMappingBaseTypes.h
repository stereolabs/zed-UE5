//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

/*
 * Current step of SpatialMapping
 */
UENUM()
enum class ESpatialMappingStep : uint8
{
	SS_Scan    UMETA(DisplayName = "SpatialMapping"),
	SS_Filter  UMETA(DisplayName = "Filtering"),
	SS_Texture UMETA(DisplayName = "Texturing"),
	SS_Load	   UMETA(DisplayName = "Loading"),
	SS_Save	   UMETA(DisplayName = "Saving"),
	SS_Pause   UMETA(DisplayName = "Pause"),
	SS_None    UMETA(Hidden, DisplayName = "None")
};

/*
 *
 */
UENUM(BlueprintType, Category = "Stereolabs|SpatialMapping|Enum")
enum class ESpatialMappingTexturingMode : uint8
{
	TM_Cubemap   UMETA(DisplayName = "Cubemap"),
	TM_Render    UMETA(DisplayName = "Render"),
	TM_None		 UMETA(Hidden, DisplayName = "None")
};