//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "EnvironmentalLighting.h"
#include "EnvironmentalLightingPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FStereolabsEnvironmentalLighting"

void FStereolabsEnvironmentalLighting::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FStereolabsEnvironmentalLighting::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FStereolabsEnvironmentalLighting, EnvironmentalLighting)