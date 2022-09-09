//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "SpatialMapping.h"

#include "Engine.h"
#include "CoreUObject.h"
#include "GameFramework/Actor.h"

DECLARE_STATS_GROUP(TEXT("SPATIALMAPPING"), STATGROUP_SPATIALMAPPING, STATCAT_Advanced);
DECLARE_CYCLE_STAT_EXTERN(TEXT("UpdateMesh"), STAT_UpdateMesh, STATGROUP_SPATIALMAPPING, SPATIALMAPPING_API);