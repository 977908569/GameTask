#include "GameTaskEditorModule.h"
#include "AssetToolsModule.h"
#include "EdGraphUtilities.h"
#include "FAssetTypeActions_GameTask.h"
#include "GameTaskEditor.h"
#include "GameTaskEditorGraphTypes.h"
#include "GameTaskNode.h"
#include "IAssetTools.h"
#include "Node/GameTaskGraphNode.h"
#include "Graph/SGraphNode_GameTask.h"
#define LOCTEXT_NAMESPACE "FGameTaskModule"

const FName FGameTaskEditorModule::GameTaskEditorAppIdentifier(TEXT("GameTaskEditorApp"));

DEFINE_LOG_CATEGORY(LogGameTaskEditor);


class FGraphPanelNodeFactory_GameTask : public FGraphPanelNodeFactory
{
	virtual TSharedPtr<class SGraphNode> CreateNode(UEdGraphNode* Node) const override
	{
		if (UGameTaskGraphNode* GameTaskNode = Cast<UGameTaskGraphNode>(Node))
		{
			return SNew(SGraphNode_GameTask, GameTaskNode);
		}
		return nullptr;
	}
};

TSharedPtr<FGraphPanelNodeFactory> GraphPanelNodeFactory_GameTask;


void FGameTaskEditorModule::StartupModule()
{
	MenuExtensibilityManager = MakeShareable(new FExtensibilityManager);
	ToolBarExtensibilityManager = MakeShareable(new FExtensibilityManager);

	GraphPanelNodeFactory_GameTask = MakeShareable(new FGraphPanelNodeFactory_GameTask());
	FEdGraphUtilities::RegisterVisualNodeFactory(GraphPanelNodeFactory_GameTask);

	IAssetTools& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	TSharedPtr<FAssetTypeActions_GameTask> GameTaskAssetTypeAction = MakeShareable(new FAssetTypeActions_GameTask);
	ItemDataAssetTypeActions.Add(GameTaskAssetTypeAction);
	AssetToolsModule.RegisterAssetTypeActions(GameTaskAssetTypeAction.ToSharedRef());
	//
	  // Register the details customizer
	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	//TODO
	PropertyModule.NotifyCustomizationModuleChanged();
}

void FGameTaskEditorModule::ShutdownModule()
{
	MenuExtensibilityManager.Reset();
	ToolBarExtensibilityManager.Reset();
	ClassCache.Reset();

	if (GraphPanelNodeFactory_GameTask.IsValid())
	{
		FEdGraphUtilities::UnregisterVisualNodeFactory(GraphPanelNodeFactory_GameTask);
		GraphPanelNodeFactory_GameTask.Reset();
	}

	// Unregister the BehaviorTree item data asset type actions
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		IAssetTools& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();
		for (auto& AssetTypeAction : ItemDataAssetTypeActions)
		{
			if (AssetTypeAction.IsValid())
			{
				AssetToolsModule.UnregisterAssetTypeActions(AssetTypeAction.ToSharedRef());
			}
		}
	}
	ItemDataAssetTypeActions.Empty();

	// Unregister the details customization
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		//TODO
		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

TSharedRef<IGameTaskEditor> FGameTaskEditorModule::CreateGameTaskEditor(const EToolkitMode::Type Mode,
	const TSharedPtr<IToolkitHost>& InitToolkitHost, UObject* Object)
{
	if (!ClassCache.IsValid())
	{
		ClassCache = MakeShareable(new FGameTaskGraphNodeClassHelper(UGameTaskNode::StaticClass()));
		ClassCache->UpdateAvailableBlueprintClasses();
	}

	TSharedRef< FGameTaskEditor > NewGameTaskEditor(new FGameTaskEditor());
	NewGameTaskEditor->InitGameTaskEditor(Mode, InitToolkitHost, Object);
	return NewGameTaskEditor;
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameTaskEditorModule, GameTaskEditor)