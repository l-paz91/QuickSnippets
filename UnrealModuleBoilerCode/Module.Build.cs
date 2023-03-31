// Copyright longPointer

// -----------------------------------------------------------------------------

using UnrealBuildTool;

// -----------------------------------------------------------------------------

public class ModuleName : ModuleRules
{
	public ModuleName(ReadOnlyTargetRules Target) 
		: base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
		});
	}
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
