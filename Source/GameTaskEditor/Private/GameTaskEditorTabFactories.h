#pragma once
#include "WorkflowOrientedApp/WorkflowTabFactory.h"
#include "WorkflowOrientedApp/WorkflowUObjectDocuments.h"

struct FGameTaskEditorTabs
{
	// Tab identifiers
	static const FName GraphDetailsID;

	// Document tab identifiers
	static const FName GraphEditorID;
};

struct FGameTaskDetailsSummoner : public FWorkflowTabFactory
{
public:
	FGameTaskDetailsSummoner(TSharedPtr<class FGameTaskEditor> InGameTaskEditorPtr);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<class FGameTaskEditor> GameTaskEditorPtr;
};

struct FGameTaskGraphEditorSummoner : public FDocumentTabFactoryForObjects<UEdGraph>
{
public:
	DECLARE_DELEGATE_RetVal_OneParam(TSharedRef<SGraphEditor>, FOnCreateGraphEditorWidget, UEdGraph*);
public:
	FGameTaskGraphEditorSummoner(TSharedPtr<class FGameTaskEditor> InGameTaskEditorPtr, FOnCreateGraphEditorWidget CreateGraphEditorWidgetCallback);

	virtual void OnTabActivated(TSharedPtr<SDockTab> Tab) const override;
	virtual void OnTabRefreshed(TSharedPtr<SDockTab> Tab) const override;

protected:
	virtual TAttribute<FText> ConstructTabNameForObject(UEdGraph* DocumentID) const override;
	virtual TSharedRef<SWidget> CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UEdGraph* DocumentID) const override;
	virtual const FSlateBrush* GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UEdGraph* DocumentID) const override;
	virtual void SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const override;

protected:
	TWeakPtr<class FGameTaskEditor> GameTaskEditorPtr;
	FOnCreateGraphEditorWidget OnCreateGraphEditorWidget;
};
