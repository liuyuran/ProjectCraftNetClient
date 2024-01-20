// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class mineworld : ModuleRules
{
	public mineworld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Sockets", "Networking" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ProceduralMeshComponent" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		var thirdPartyPath = Path.Combine(ModuleDirectory, "../ThirdParty/");
		
		PublicSystemIncludePaths.AddRange(new string[] {Path.Combine(thirdPartyPath, "Protobuf/include")});
		
		PublicSystemLibraryPaths.Add(Path.Combine(thirdPartyPath, "Protobuf/lib/Win64"));
		var dict = Directory.GetFiles(Path.Combine(thirdPartyPath, "Protobuf/lib/Win64"));
		foreach (var file in dict) {
			if (file.EndsWith(".lib")) PublicAdditionalLibraries.Add(file);				
		}
		bEnableExceptions = true;
        
		PublicDefinitions.Add("GOOGLE_PROTOBUF_NO_RTTI=1");

		ShadowVariableWarningLevel = WarningLevel.Off;
		bEnableUndefinedIdentifierWarnings = false;
        
		PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
	}
}
