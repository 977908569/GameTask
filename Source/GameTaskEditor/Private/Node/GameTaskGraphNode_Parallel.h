#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Parallel.generated.h"

class UEdGraphPin;

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Parallel : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()

		virtual void AllocateDefaultPins() override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
	virtual void UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode) override;
};