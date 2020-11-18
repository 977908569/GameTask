#pragma once
#include "GameTaskGraphNode_Composite.h"
#include "GameTaskGraphNode_Parallel.generated.h"

class UEdGraphPin;

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Parallel : public UGameTaskGraphNode_Composite
{
	GENERATED_UCLASS_BODY()

		virtual void AllocateDefaultPins() override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
};