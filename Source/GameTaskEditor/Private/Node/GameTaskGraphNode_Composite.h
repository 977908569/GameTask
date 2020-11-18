#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Composite.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Composite : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()
public:
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetDescription() const override;
	virtual FText GetTooltipText() const override;
	virtual bool RefreshNodeClass() override { return false; }

	/** Gets a list of actions that can be done to this particular node */
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;

	/** check if node can accept breakpoints */
	virtual bool CanPlaceBreakpoints() const override { return true; }
};