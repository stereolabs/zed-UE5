//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Modules/ModuleManager.h"

class FStereolabsSpatialMappingEditor : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};