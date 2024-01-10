// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class mineworld : ModuleRules
{
	public mineworld(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		CppStandard = CppStandardVersion.Cpp20;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ProceduralMeshComponent" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
		string ThridPartyPath = Path.Combine(ModuleDirectory, "../ThirdParty/");
		
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotobuf.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotoc.lib"));
			PublicSystemLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotobuf.lib"));
			PublicSystemLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotoc.lib"));
		}
        
        
		PublicIncludePaths.AddRange(new string[] {Path.Combine(ThridPartyPath, "Protobuf/include")});
           
           
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicAdditionalLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotobuf.lib"));
			PublicAdditionalLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotoc.lib"));
			PublicSystemLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotobuf.lib"));
			PublicSystemLibraries.Add(Path.Combine(ThridPartyPath, "Protobuf", "lib", "Win64", "libprotoc.lib"));
		}
        
		PublicDefinitions.Add("GOOGLE_PROTOBUF_NO_RTTI=1");

		ShadowVariableWarningLevel = WarningLevel.Off;
		bEnableUndefinedIdentifierWarnings = false;
		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			bEnableExceptions = true;
		}
        
		PublicDefinitions.Add("_CRT_SECURE_NO_WARNINGS");
	}
}
