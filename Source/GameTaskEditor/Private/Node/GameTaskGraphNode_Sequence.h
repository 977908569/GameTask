#pragma once
#include "GameTaskGraphNode_Composite.h"
#include "GameTaskGraphNode_Sequence.generated.h"

class UEdGraphPin;

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Sequence : public UGameTaskGraphNode_Composite
{
	GENERATED_BODY()
public:
	UGameTaskGraphNode_Sequence();

		virtual void AllocateDefaultPins() override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
};