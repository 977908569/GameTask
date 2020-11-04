#include "GameTaskGraphNode_Execute.h"
#include "GameTaskEditorTypes.h"

UGameTaskGraphNode_Execute::UGameTaskGraphNode_Execute(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskGraphNode_Execute::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleComposite, TEXT("In"));
}

FText UGameTaskGraphNode_Execute::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return Super::GetNodeTitle(TitleType);
}

void UGameTaskGraphNode_Execute::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	
}
