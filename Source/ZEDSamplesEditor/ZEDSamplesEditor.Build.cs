//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;

public class ZEDSamplesEditor : ModuleRules
{
	public ZEDSamplesEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","Stereolabs","AnimGraph",
				"AnimGraphRuntime",
				"BlueprintGraph",
				 "ZEDSamples" });


			 PrivateDependencyModuleNames.AddRange(
	 new string[]
	 {
		"CoreUObject",
		"Engine",
		"Slate",
		"SlateCore",
		"UnrealEd",
		"GraphEditor",
		"PropertyEditor",
		"EditorStyle",
		"ContentBrowser",
		"ZEDSamples",
		"AnimGraph",
		"AnimGraphRuntime",
		 // ... add private dependencies that you statically link with here ...
	 }
	 );

	// Uncomment if you are using Slate UI
	// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

	// Uncomment if you are using online features
	// PrivateDependencyModuleNames.Add("OnlineSubsystem");

	// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
}
}
