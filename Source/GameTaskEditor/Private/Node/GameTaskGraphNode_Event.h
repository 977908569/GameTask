#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Event.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Event : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()

		virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
	void CollectEventData(TArray<class UGameTaskEvent*>& NodeInstances) const;
	
	bool bEnterEvent = true;
};