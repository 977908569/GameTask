#include "GameTaskGraphNode.h"
#include "GameTaskEditorGraphSchema.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskNode.h"
#include "ToolMenu.h"
#include "ToolMenuEntry.h"
#include "Graph/SGraphEditorActionMenuGameTask.h"

#define LOCTEXT_NAMESPACE "GameTask"

UGameTaskGraphNode::UGameTaskGraphNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

UGameTaskGraph* UGameTaskGraphNode::GetGameTaskGraph() {
	return CastChecked<UGameTaskGraph>(GetGraph());
}

void UGameTaskGraphNode::AllocateDefaultPins() {
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_MultipleNodes, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_MultipleNodes, TEXT("Out"));
}

FText UGameTaskGraphNode::GetTooltipText() const {
	FText TooltipDesc;
	return TooltipDesc;
}

bool UGameTaskGraphNode::CanCreateUnderSpecifiedSchema(
	const UEdGraphSchema* DesiredSchema) const {
	return DesiredSchema->GetClass()->IsChildOf(UGameTaskEditorGraphSchemaBase::StaticClass());
}

void UGameTaskGraphNode::FindDiffs(UEdGraphNode* OtherNode,
	FDiffResults& Results) {
	Super::FindDiffs(OtherNode, Results);
}
#if WITH_EDITOR
void UGameTaskGraphNode::PostEditUndo()
{
	Super::PostEditUndo();
}

#endif


FText UGameTaskGraphNode::GetDescription() const
{
	const UGameTaskNode* GameTaskNode = Cast<const UGameTaskNode>(NodeInstance);
	if (GameTaskNode)
	{
		return FText::FromString(GameTaskNode->GetStaticDescription());
	}
	return Super::GetDescription();
}

void UGameTaskGraphNode::InitializeInstance()
{
	UGameTaskNode* GameTaskNode = Cast<UGameTaskNode>(NodeInstance);
	UGameTask* GameTaskAsset = GameTaskNode ? Cast<UGameTask>(GameTaskNode->GetOuter()) : nullptr;
	if (GameTaskNode && GameTaskAsset)
	{
		GameTaskNode->InitializeFromAsset(*GameTaskAsset);
		GameTaskNode->InitializeNode(nullptr);
		GameTaskNode->OnNodeCreated();
	}
}

FName UGameTaskGraphNode::GetNameIcon() const
{
	UGameTaskNode* GameTaskNodeInstance = Cast<UGameTaskNode>(NodeInstance);
	return GameTaskNodeInstance != nullptr ? GameTaskNodeInstance->GetNodeIconName() : FName("BTEditor.Graph.BTNode.Icon");
}

void UGameTaskGraphNode::CreateAddEventSubMenu(UToolMenu* Menu, UEdGraph* Graph) const
{
	TSharedRef<SGraphEditorActionMenuGameTask> Widget =
		SNew(SGraphEditorActionMenuGameTask)
		.GraphObj(Graph)
		.GraphNode((UGameTaskGraphNode*)this)
		.SubNodeFlags(EGameTaskSubNode::Event)
		.AutoExpandActionMenu(true);

	FToolMenuSection& Section = Menu->FindOrAddSection("Section");
	Section.AddEntry(FToolMenuEntry::InitWidget("EventWidget", Widget, FText(), true));
}

void UGameTaskGraphNode::AddContextMenuActionsEvents(UToolMenu* Menu, const FName SectionName,
	UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection(SectionName);
	Section.AddSubMenu(
		"AddEvent",
		LOCTEXT("AddEvent", "Add Event..."),
		LOCTEXT("AddEventTooltip", "Adds new event as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UGameTaskGraphNode::CreateAddEventSubMenu, (UEdGraph*)Context->Graph));
}

#undef LOCTEXT_NAMESPACE