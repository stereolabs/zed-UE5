//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.Collections.Generic;

public class ZEDSamplesEditorTarget : TargetRules
{
	public ZEDSamplesEditorTarget(TargetInfo Target) : base(Target)
	{
		bUseAdaptiveUnityBuild = false;

		Type = TargetType.Editor;
		ExtraModuleNames.AddRange( new string[] { "ZEDSamples" } );

		ExtraModuleNames.AddRange(new string[] { "ZEDSamplesEditor" });
	}
}
