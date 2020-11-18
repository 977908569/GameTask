#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Root.generated.h"

/** Root node of this game task */
UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Root : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()
public:
	virtual void AllocateDefaultPins() override;
	virtual bool CanDuplicateNode() const override { return false; }
	virtual bool CanUserDeleteNode() const override { return false; }
	virtual bool HasErrors() const override { return false; }
	virtual bool RefreshNodeClass() override { return false; }
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FName GetNameIcon() const override;
	virtual FText GetTooltipText() const override;

	virtual FText GetDescription() const override;
};
