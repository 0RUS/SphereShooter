using UnrealBuildTool;
using System.Collections.Generic;

public class SphereShooterTarget : TargetRules
{
	public SphereShooterTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("SphereShooter");
	}
}