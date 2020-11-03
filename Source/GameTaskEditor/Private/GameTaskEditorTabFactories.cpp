#include "GameTaskEditorTabFactories.h"
#include "GameTaskEditor.h"

#define LOCTEXT_NAMESPACE "GameTask"

// Tab identifiers
const FName FGameTaskEditorTabs::GraphDetailsID(TEXT("GameTaskEditor_Properties"));

// Document tab identifiers
const FName FGameTaskEditorTabs::GraphEditorID(TEXT("Document"));


FGameTaskDetailsSummoner::FGameTaskDetailsSummoner(TSharedPtr<FGameTaskEditor> InGameTaskEditorPtr)
	: FWorkflowTabFactory(FGameTaskEditorTabs::GraphDetailsID, InGameTaskEditorPtr)
	, GameTaskEditorPtr(InGameTaskEditorPtr)
{
	TabLabel = LOCTEXT("GameTaskDetailsLabel", "Details");
	TabIcon = FSlateIcon(FEditorStyle::GetStyleSetName(), "Kismet.Tabs.Components");

	bIsSingleton = true;

	ViewMenuDescription = LOCTEXT("GameTaskDetailsView", "Details");
	ViewMenuTooltip = LOCTEXT("GameTaskDetailsView_ToolTip", "Show the details view");
}

TSharedRef<SWidget> FGameTaskDetailsSummoner::CreateTabBody( const FWorkflowTabSpawnInfo &Info) const {
	check(GameTaskEditorPtr.IsValid());
	return GameTaskEditorPtr.Pin()->SpawnProperties();
}

FText FGameTaskDetailsSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo &Info) const {
	return LOCTEXT("GameTaskDetailsTabTooltip", "The game task details tab allows editing of the properties of game task nodes");
}
//====================================
FGameTaskGraphEditorSummoner::FGameTaskGraphEditorSummoner(TSharedPtr<class FGameTaskEditor> InGameTaskEditorPtr, FOnCreateGraphEditorWidget CreateGraphEditorWidgetCallback)
	: FDocumentTabFactoryForObjects<UEdGraph>(FGameTaskEditorTabs::GraphEditorID, InGameTaskEditorPtr)
	, GameTaskEditorPtr(InGameTaskEditorPtr)
	, OnCreateGraphEditorWidget(CreateGraphEditorWidgetCallback)
{
}

void FGameTaskGraphEditorSummoner::OnTabActivated(
    TSharedPtr<SDockTab> Tab) const {
	check(GameTaskEditorPtr.IsValid());
	TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(Tab->GetContent());
	//GameTaskEditorPtr.Pin()->OnGraphEditorFocused(GraphEditor);
}

void FGameTaskGraphEditorSummoner::OnTabRefreshed(
    TSharedPtr<SDockTab> Tab) const {

}

TAttribute<FText> FGameTaskGraphEditorSummoner::ConstructTabNameForObject(
    UEdGraph *DocumentID) const {
	return TAttribute<FText>(FText::FromString(DocumentID->GetName()));
}

TSharedRef<SWidget> FGameTaskGraphEditorSummoner::CreateTabBodyForObject(
    const FWorkflowTabSpawnInfo &Info, UEdGraph *DocumentID) const {
	return OnCreateGraphEditorWidget.Execute(DocumentID);
}

const FSlateBrush * FGameTaskGraphEditorSummoner::GetTabIconForObject(
    const FWorkflowTabSpawnInfo &Info, UEdGraph *DocumentID) const {
	return FEditorStyle::GetBrush("NoBrush");
}

void FGameTaskGraphEditorSummoner::SaveState(TSharedPtr<SDockTab> Tab,
    TSharedPtr<FTabPayload> Payload) const {
	check(GameTaskEditorPtr.IsValid());
	check(GameTaskEditorPtr.Pin()->GetGameTask());

	TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(Tab->GetContent());

	FVector2D ViewLocation;
	float ZoomAmount;
	GraphEditor->GetViewLocation(ViewLocation, ZoomAmount);

	UEdGraph* Graph = FTabPayload_UObject::CastChecked<UEdGraph>(Payload);
	GameTaskEditorPtr.Pin()->GetGameTask()->LastEditedDocuments.Add(FEditedDocumentInfo(Graph, ViewLocation, ZoomAmount));
}

#undef LOCTEXT_NAMESPACE
