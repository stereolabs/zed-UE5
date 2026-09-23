//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;

public class ZEDSamples : ModuleRules
{
	public ZEDSamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });
	}
}
