#include "GameTaskGraphNode_Root.h"
#include "GameTaskEditorTypes.h"

UGameTaskGraphNode_Root::UGameTaskGraphNode_Root(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsReadOnly = true;
}

void UGameTaskGraphNode_Root::AllocateDefaultPins() {
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_SingleComposite, TEXT("In"));
}

FText UGameTaskGraphNode_Root::GetNodeTitle(
	ENodeTitleType::Type TitleType) const {
	return NSLOCTEXT("GameTaskEditor", "Root", "ROOT");
}

FName UGameTaskGraphNode_Root::GetNameIcon() const
{
	return FName("BTEditor.Graph.BTNode.Root.Icon");
}

FText UGameTaskGraphNode_Root::GetTooltipText() const {
	return UEdGraphNode::GetTooltipText();
}
