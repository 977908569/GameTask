// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameTaskEditor : ModuleRules
{
    public GameTaskEditor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
				// ... add public include paths required here ...
			}
            );

        PrivateIncludePathModuleNames.AddRange(
          new string[] {
                "AssetRegistry",
                "AssetTools",
                "PropertyEditor",
                "ContentBrowser"
          }
      );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "RenderCore",
                "InputCore",
                "UnrealEd",
                "ToolMenus",
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "ApplicationCore",
                "Engine",
                "EditorStyle",
                "MessageLog",
                "GraphEditor",
                "Kismet",
                "PropertyEditor",
                "AnimGraph",
                "BlueprintGraph",
                "AIModule",
                "Kismet",
                "KismetWidgets",
                "ClassViewer",
                "GameTask",
				// ... add private dependencies that you statically link with here ...	
			}
            );

        PublicIncludePathModuleNames.Add("LevelEditor");

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                "WorkspaceMenuStructure",
                "AssetTools",
                "AssetRegistry",
                "ContentBrowser"
            }
            );
    }
}
