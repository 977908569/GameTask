#include "GameTaskGraphNode_Composite.h"
#include "GameTaskCompositeNode.h"
#include "GameTaskNode.h"

UGameTaskGraphNode_Composite::UGameTaskGraphNode_Composite(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FText UGameTaskGraphNode_Composite::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	const UGameTaskNode* MyNode = Cast<UGameTaskNode>(NodeInstance);
	if (MyNode != nullptr)
	{
		return FText::FromString(MyNode->GetNodeName());
	}
	return Super::GetNodeTitle(TitleType);
}

FText UGameTaskGraphNode_Composite::GetDescription() const
{
	const UGameTaskCompositeNode* CompositeNode = Cast<UGameTaskCompositeNode>(NodeInstance);
	if (CompositeNode)
	{
		return FText::Format(FText::FromString(TEXT("{0}\n{1}")),
			Super::GetDescription(),
			NSLOCTEXT("GameTaskEditor", "CompositeNodeScopeDesc", "Local scope for observers"));
	}
	return Super::GetDescription();
}

FText UGameTaskGraphNode_Composite::GetTooltipText() const
{
	return Super::GetTooltipText();
}

void UGameTaskGraphNode_Composite::GetNodeContextMenuActions(UToolMenu* Menu,
	UGraphNodeContextMenuContext* Context) const
{
	AddContextMenuActionsEvents(Menu, "GameTaskGraphNode", Context);
}
