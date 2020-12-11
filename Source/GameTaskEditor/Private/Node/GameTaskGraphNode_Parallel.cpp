#include "GameTaskGraphNode_Parallel.h"

#include "GameTaskComposite_Parallel.h"
#include "GameTaskEditorTypes.h"
#define LOCTEXT_NAMESPACE "GameTask"
UGameTaskGraphNode_Parallel::UGameTaskGraphNode_Parallel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskGraphNode_Parallel::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleNode, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_MultipleNodes, TEXT("Out"));
}

void UGameTaskGraphNode_Parallel::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
}

void UGameTaskGraphNode_Parallel::UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode) {
	if (UGameTaskComposite_Parallel* Asset = Cast<UGameTaskComposite_Parallel>(NodeInstance)) {
		InParentNode->Children.Add(Asset);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Parallel Error"));
	}
}
#undef LOCTEXT_NAMESPACE
