#include "GameTaskGraphNode_Sequence.h"

#include "GameTaskComposite_Sequence.h"
#include "GameTaskEditorTypes.h"

UGameTaskGraphNode_Sequence::UGameTaskGraphNode_Sequence()
{
}

void UGameTaskGraphNode_Sequence::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleNode, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_MultipleNodes, TEXT("Out"));
}

void UGameTaskGraphNode_Sequence::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
}

void UGameTaskGraphNode_Sequence::UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode) {
	if (UGameTaskComposite_Sequence* Sequence = Cast<UGameTaskComposite_Sequence>(NodeInstance)) {
		InParentNode->Children.Add(Sequence);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Sequence Error"));
	}
}
