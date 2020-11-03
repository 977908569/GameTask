#pragma once
#include "GameTaskGraph.h"
#include "GameTaskGraphNodeBase.h"
#include "GameTaskGraphNode.generated.h"

UCLASS()
class UGameTaskGraphNode : public UGameTaskGraphNodeBase
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY()
		TArray<UGameTaskGraphNode*> Events;

	//~ Begin UEdGraphNode Interface
	virtual UGameTaskGraph* GetGameTaskGraph();
	virtual void AllocateDefaultPins() override;
	virtual FText GetTooltipText() const override;
	virtual bool CanCreateUnderSpecifiedSchema(const UEdGraphSchema* DesiredSchema) const override;
	virtual void FindDiffs(class UEdGraphNode* OtherNode, struct FDiffResults& Results) override;
	//~ End UEdGraphNode Interface
};