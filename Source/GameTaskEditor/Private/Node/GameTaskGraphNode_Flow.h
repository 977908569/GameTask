#pragma once
#include "GameTaskGraphNode_Composite.h"
#include "GameTaskGraphNode_Event.h"
#include "GameTaskGraphNode_Flow.generated.h"

class UEdGraphPin;

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Flow : public UGameTaskGraphNode_Composite
{
	GENERATED_BODY()
public:
	UGameTaskGraphNode_Flow();

	UPROPERTY()
		TArray<UGameTaskGraphNode_Event*> EnterEvents;
	UPROPERTY()
		TArray<UGameTaskGraphNode_Event*> ExitEvents;
	
	virtual int32 GetSubNodeNum() override;

	virtual void AllocateDefaultPins() override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
	virtual void OnSubNodeAdded(UGameTaskGraphNodeBase* SubNode) override;
	virtual void OnSubNodeRemoved(UGameTaskGraphNodeBase* SubNode) override;
	virtual void RemoveAllSubNodes() override;
	

	virtual int32 FindSubNodeDropIndex(UGameTaskGraphNodeBase* SubNode) const override;
	virtual void InsertSubNodeAt(UGameTaskGraphNodeBase* SubNode, int32 DropIndex) override;
};