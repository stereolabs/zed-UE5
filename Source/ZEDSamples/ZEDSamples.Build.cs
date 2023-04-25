//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;

public class ZEDSamples : ModuleRules
{
	public ZEDSamples(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Stereolabs", "ProceduralMeshComponent", "MeshDescription" });

		PrivateDependencyModuleNames.AddRange(new string[] {
			 "AnimGraphRuntime",
			 });
		
	// Uncomment if you are using Slate UI
	// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

	// Uncomment if you are using online features
	// PrivateDependencyModuleNames.Add("OnlineSubsystem");

	// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
}
}
