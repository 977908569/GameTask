#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Execute.generated.h"

UCLASS()
class UGameTaskGraphNode_Execute : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()

		virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	/** Gets a list of actions that can be done to this particular node */
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
};