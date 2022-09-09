//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "SpatialMappingEditorPlugin.h"
#include "SpatialMappingEditorPrivatePCH.h"
#include "SpatialMappingEditor/Public/SpatialMappingManagerDetails.h"

#define LOCTEXT_NAMESPACE "FStereolabsSpatialMappingEditor"

void FStereolabsSpatialMappingEditor::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		
	PropertyModule.RegisterCustomClassLayout(ASpatialMappingManager::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FSpatialMappingManagerDetails::MakeInstance));
}

void FStereolabsSpatialMappingEditor::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomClassLayout(ASpatialMappingManager::StaticClass()->GetFName());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FStereolabsSpatialMappingEditor, SpatialMappingEditor)