//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs.h"
#include "StereolabsPrivatePCH.h"
#include "Core.h"
//#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FStereolabs"

#define SL_HANDLE_DEFINE(Name) void* ##Name##Handle = nullptr;
#define SL_IMPORT(Name, Lib) { ##Name##Handle = FPlatformProcess::GetDllHandle(TEXT(Lib)); }
#define SL_IMPORT_STRING(Name, Lib) { ##Name##Handle = FPlatformProcess::GetDllHandle(Lib); }
#define SL_FREE(Name) FPlatformProcess::FreeDllHandle(##Name##Handle);

SL_HANDLE_DEFINE(Core)
SL_HANDLE_DEFINE(Zed)
SL_HANDLE_DEFINE(Nvd3dumx)
SL_HANDLE_DEFINE(MRCore)
SL_HANDLE_DEFINE(ZedCApi)

void FStereolabs::StartupModule()
{
	FString pluginDir = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("Stereolabs"));
	FString ShaderDirectory = FPaths::Combine(pluginDir, TEXT("Shaders"));
	AddShaderSourceDirectoryMapping("/Plugin/Stereolabs", ShaderDirectory);

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	SL_IMPORT(Zed,     "sl_zed64.dll");
	SL_IMPORT(Nvd3dumx, "nvd3dumx.dll");

#if WITH_EDITOR
	FString MixedRealityBinPath = FPaths::Combine(*FPaths::ConvertRelativePathToFull(*FPaths::ProjectPluginsDir()), TEXT("Stereolabs/Source/ThirdParty/MixedReality/bin/"));

	FString CoreFilePath = FPaths::Combine(*MixedRealityBinPath, TEXT("sl_mr_core64.dll"));
	SL_IMPORT_STRING(MRCore, *CoreFilePath);

	FString zedCApiLibraryPath = FPaths::Combine(*FPaths::ConvertRelativePathToFull(*FPaths::ProjectPluginsDir()), TEXT("Stereolabs/Source/ThirdParty/sl_zed_c/bin/"));
	SL_IMPORT_STRING(ZedCApi, *FPaths::Combine(zedCApiLibraryPath, TEXT("sl_zed_c.dll")));
#else
	SL_IMPORT_STRING(MRCore, TEXT("../../Plugins/Stereolabs/Binaries/Win64/sl_mr_core64.dll"));

	SL_IMPORT_STRING(ZedCApi, TEXT("../../Plugins/Stereolabs/Binaries/Win64/sl_zed_c.dll"));
#endif
}

void FStereolabs::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	SL_FREE(Core);
	SL_FREE(Zed);
	SL_FREE(Nvd3dumx);
	SL_FREE(MRCore);
	SL_FREE(ZedCApi);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FStereolabs, Stereolabs)