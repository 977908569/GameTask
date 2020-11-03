#pragma once
#include "GameTaskEditorModule.h"
#include "GameTaskGraphEditor.h"
#include "GameTask.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

/**
 * Editor
 */
class FGameTaskEditor : public IGameTaskEditor, FGameTaskGraphEditor, FNotifyHook
{
public:
	FGameTaskEditor();
	virtual ~FGameTaskEditor();

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;
	void InitGameTaskEditor(const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, UObject* InObject);


	//~ Begin IToolkit Interface
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual FText GetToolkitName() const override;
	virtual FText GetToolkitToolTipText() const override;
	//~ End IToolkit Interface

	//~ Begin IGameTaskEditor Interface
	virtual void InitializeDebuggerState(FGameTaskDebugger* ParentDebugger) const override;
	virtual void DoubleClickNode(UEdGraphNode* Node) override;
	//~ End IGameTaskEditor Interface

	//~ Begin FEditorUndoClient Interface
	virtual void PostUndo(bool bSuccess) override;
	virtual void PostRedo(bool bSuccess) override;
	// End of FEditorUndoClient

		//~ Begin FNotifyHook Interface
	virtual void NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent, FProperty* PropertyThatChanged) override;
	// End of FNotifyHook



  //
  // Delegates
	void OnNodeDoubleClicked(class UEdGraphNode* Node);
	void OnGraphEditorFocused(const TSharedRef<SGraphEditor>& InGraphEditor);
	void OnNodeTitleCommitted(const FText& NewText, ETextCommit::Type CommitInfo, UEdGraphNode* NodeBeingChanged);

	void OnAddInputPin();
	bool CanAddInputPin() const;
	void OnRemoveInputPin();
	bool CanRemoveInputPin() const;

	void OnEnableBreakpoint();
	bool CanEnableBreakpoint() const;
	void OnToggleBreakpoint();
	bool CanToggleBreakpoint() const;
	void OnDisableBreakpoint();
	bool CanDisableBreakpoint() const;
	void OnAddBreakpoint();
	bool CanAddBreakpoint() const;
	void OnRemoveBreakpoint();
	bool CanRemoveBreakpoint() const;

	//

	FGraphAppearanceInfo GetGraphAppearance() const;
	bool InEditingMode(bool bGraphIsEditable) const;

	/** Spawns the tab with the update graph inside */
	TSharedRef<SWidget> SpawnProperties();
	UGameTask* GetGameTask() const;

	void RestoreGameTask();

	TSharedPtr<class FGameTaskEditorToolbar> GetToolbarBuilder() const;

private:
	void CreateInternalWidgets();
	void ExtendMenu();
	void BindCommonCommands();

	TSharedRef<class SGraphEditor> CreateGraphEditorWidget(UEdGraph* InGraph);

private:
	//Data
	UGameTask* GameTask;
	TSharedPtr<FDocumentTracker> DocumentManager;
	TWeakPtr<FDocumentTabFactory> GraphEditorTabFactoryPtr;

	TSharedPtr<class FGameTaskEditorToolbar> ToolbarBuilder;
	TSharedPtr<class FGameTaskDebugger> Debugger;
	FDelegateHandle OnPackageSavedDelegateHandle;
	/** Property View */
	TSharedPtr<class IDetailsView> DetailsView;

public:
	static const FName GameTaskMode;
};