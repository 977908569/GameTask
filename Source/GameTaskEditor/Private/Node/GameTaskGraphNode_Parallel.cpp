#include "GameTaskGraphNode_Parallel.h"
#include "GameTaskEditorTypes.h"
#define LOCTEXT_NAMESPACE "GameTask"
UGameTaskGraphNode_Parallel::UGameTaskGraphNode_Parallel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskGraphNode_Parallel::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleComposite, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_MultipleNodes, TEXT("Out"));
}

void UGameTaskGraphNode_Parallel::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
}
#undef LOCTEXT_NAMESPACE