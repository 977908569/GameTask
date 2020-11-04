#include "GameTaskGraphNode.h"
#include "GameTaskEditorGraphSchema.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskNode.h"

UGameTaskGraphNode::UGameTaskGraphNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

UGameTaskGraph * UGameTaskGraphNode::GetGameTaskGraph() {
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
    const UEdGraphSchema *DesiredSchema) const {
	return DesiredSchema->GetClass()->IsChildOf(UGameTaskEditorGraphSchemaBase::StaticClass());
}

void UGameTaskGraphNode::FindDiffs(UEdGraphNode *OtherNode,
    FDiffResults &Results) {
	Super::FindDiffs(OtherNode, Results);
}

FName UGameTaskGraphNode::GetNameIcon() const
{
	UGameTaskNode* GameTaskNodeInstance = Cast<UGameTaskNode>(NodeInstance);
	return GameTaskNodeInstance != nullptr ? GameTaskNodeInstance->GetNodeIconName() : FName("BTEditor.Graph.BTNode.Icon");
}
