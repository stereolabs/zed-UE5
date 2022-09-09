#include "ZEDEditorPlugin.h"
#include "ZEDEditorPrivatePCH.h"
#include "ZEDEditor/Public/ZEDInitializerDetails.h"
#include "ZEDEditor/Public/ZEDCameraDetails.h"
#include "ZED/Public/Core/ZEDInitializer.h"
#include "ZED/Public/Core/ZEDCamera.h"

#define LOCTEXT_NAMESPACE "FStereolabsZEDEditor"

void FStereolabsZEDEditor::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		
	PropertyModule.RegisterCustomClassLayout(AZEDInitializer::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FZEDInitializerDetails::MakeInstance));
	PropertyModule.RegisterCustomClassLayout(AZEDCamera::StaticClass()->GetFName(), FOnGetDetailCustomizationInstance::CreateStatic(&FZEDCameraDetails::MakeInstance));
}

void FStereolabsZEDEditor::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyModule.UnregisterCustomClassLayout(AZEDCamera::StaticClass()->GetFName());
	PropertyModule.UnregisterCustomClassLayout(AZEDInitializer::StaticClass()->GetFName());
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FStereolabsZEDEditor, ZEDEditor)