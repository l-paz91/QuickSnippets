// Copyright Epic Games, Inc. All Rights Reserved.

// -----------------------------------------------------------------------------

using UnrealBuildTool;
using System.Collections.Generic;

// -----------------------------------------------------------------------------

public class MainModuleTarget : TargetRules
{
	public MainModuleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.Add("MainModule");
		ExtraModuleNames.Add("AnotherModule");
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
