// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGameTaskEditor, Log, All);


/** GameTask Editor public interface */
class IGameTaskEditor : public FWorkflowCentricApplication
{
public:
	virtual void InitializeDebuggerState(class FGameTaskDebugger* ParentDebugger) const = 0;
	virtual void DoubleClickNode(class UEdGraphNode* Node) = 0;
};


class FGameTaskEditorModule : public IModuleInterface,
	public IHasMenuExtensibility, public IHasToolBarExtensibility
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual TSharedRef<IGameTaskEditor> CreateGameTaskEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UObject* Object);
	virtual TSharedPtr<FExtensibilityManager> GetMenuExtensibilityManager() override { return MenuExtensibilityManager; }
	virtual TSharedPtr<FExtensibilityManager> GetToolBarExtensibilityManager() override { return ToolBarExtensibilityManager; }

	TSharedPtr<struct FGameTaskGraphNodeClassHelper> GetClassCache() { return ClassCache; }
	static const FName GameTaskEditorAppIdentifier;
private:
	TSharedPtr<FExtensibilityManager> MenuExtensibilityManager;
	TSharedPtr<FExtensibilityManager> ToolBarExtensibilityManager;

	/** Asset type actions */
	TArray<TSharedPtr<class FAssetTypeActions_Base>> ItemDataAssetTypeActions;
	TSharedPtr<struct FGameTaskGraphNodeClassHelper> ClassCache;
};
