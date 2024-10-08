//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.Collections.Generic;

public class ZEDSamplesEditorTarget : TargetRules
{
	public ZEDSamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		bUseAdaptiveUnityBuild = false;

        bOverrideBuildEnvironment = true;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        Type = TargetType.Editor;
		ExtraModuleNames.AddRange( new string[] { "ZEDSamples" } );
	}
}
