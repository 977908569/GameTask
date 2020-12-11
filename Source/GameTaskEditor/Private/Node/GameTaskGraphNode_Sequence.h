#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Sequence.generated.h"

class UEdGraphPin;

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Sequence : public UGameTaskGraphNode
{
	GENERATED_BODY()
public:
	UGameTaskGraphNode_Sequence();

		virtual void AllocateDefaultPins() override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
  virtual void UpdateAsset(UGameTask *InTaskAsset, UGameTaskNode *InParentNode) override;
};