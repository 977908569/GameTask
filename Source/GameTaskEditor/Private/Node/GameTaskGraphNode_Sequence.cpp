#include "GameTaskGraphNode_Sequence.h"

#include "GameTaskEditorTypes.h"

UGameTaskGraphNode_Sequence::UGameTaskGraphNode_Sequence()
{
}

void UGameTaskGraphNode_Sequence::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleComposite, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_MultipleNodes, TEXT("Out"));
}

void UGameTaskGraphNode_Sequence::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
}
