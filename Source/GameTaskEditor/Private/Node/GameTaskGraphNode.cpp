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
	return Super::GetTooltipText();
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

FText UGameTaskGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	const UGameTaskNode* MyNode = Cast<UGameTaskNode>(NodeInstance);
	if (MyNode != nullptr)
	{
		return FText::FromString(MyNode->GetNodeName());
	}
	return Super::GetNodeTitle(TitleType);
}

bool UGameTaskGraphNode::GetCanRenameNode() const {
	return true;
}

void UGameTaskGraphNode::UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode)
{

}

void UGameTaskGraphNode::UpdateGraph()
{

}

void UGameTaskGraphNode::CreateAddEventSubMenu(UToolMenu* Menu, UEdGraph* Graph, const EGameTaskSubNode NodeType) const
{
	const TSharedRef<SGraphEditorActionMenuGameTask> Widget =
		SNew(SGraphEditorActionMenuGameTask)
		.GraphObj(Graph)
		.GraphNode(const_cast<UGameTaskGraphNode*>(this))
		.SubNodeFlags(NodeType)
		.AutoExpandActionMenu(true);

	FToolMenuSection& Section = Menu->FindOrAddSection("Section");
	Section.AddEntry(FToolMenuEntry::InitWidget("EventWidget", Widget, FText(), true));
}

void UGameTaskGraphNode::AddContextMenuActionsEvents(UToolMenu* Menu, const FName SectionName, UGraphNodeContextMenuContext* Context, const EGameTaskSubNode NodeType) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection(SectionName);
	switch (NodeType) {
	case EGameTaskSubNode::EnterEvent:
		Section.AddSubMenu(
			"AddEnterEvent",
			LOCTEXT("AddEnterEvent", "Add Enter Event..."),
			LOCTEXT("AddEventTooltip", "Adds new event as a subnode"),
			FNewToolMenuDelegate::CreateUObject(this, &UGameTaskGraphNode::CreateAddEventSubMenu, const_cast<UEdGraph*>(Context->Graph), NodeType));
		break;
	case EGameTaskSubNode::ExitEvent:
		Section.AddSubMenu(
			"AddExitEvent",
			LOCTEXT("AddExitEvent", "Add Exit Event..."),
			LOCTEXT("AddEventTooltip", "Adds new event as a subnode"),
			FNewToolMenuDelegate::CreateUObject(this, &UGameTaskGraphNode::CreateAddEventSubMenu, const_cast<UEdGraph*>(Context->Graph), NodeType));
		break;
	default:;
	}

}

#undef LOCTEXT_NAMESPACE