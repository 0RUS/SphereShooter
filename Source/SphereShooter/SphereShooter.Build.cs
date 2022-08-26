using UnrealBuildTool;

public class SphereShooter : ModuleRules
{
	public SphereShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG"});

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore"});
	}
}