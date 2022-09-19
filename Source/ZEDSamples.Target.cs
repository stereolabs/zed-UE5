//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

using UnrealBuildTool;
using System.Collections.Generic;

public class ZEDSamplesTarget : TargetRules
{
	public ZEDSamplesTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "ZEDSamples" } );

		if (bBuildEditor)
		{
			ExtraModuleNames.AddRange(new string[] { "ZEDSamplesEditor" });
		}
	}
}
