#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Event.h"
#include "GameTaskGraphNode_Execute.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Execute : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()

		UPROPERTY()
		TArray<UGameTaskGraphNode_Event*> EnterEvents;
	UPROPERTY()
		TArray<UGameTaskGraphNode_Event*> ExitEvents;

	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	/** Gets a list of actions that can be done to this particular node */
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
	virtual void InsertSubNodeAt(UGameTaskGraphNodeBase* SubNode, int32 DropIndex) override;
	virtual void OnSubNodeRemoved(UGameTaskGraphNodeBase* SubNode) override;
	virtual void RemoveAllSubNodes() override;
	virtual int32 FindSubNodeDropIndex(UGameTaskGraphNodeBase* SubNode) const override;
	virtual void OnSubNodeAdded(UGameTaskGraphNodeBase* SubNode) override;
	virtual int32 GetSubNodeNum() override;

	virtual void UpdateGraph() override;
	virtual void UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode) override;
private:
	void CollectEvents(UGameTask* TaskAsset, TArray<UGameTaskGraphNode_Event*>& Events, TArray<UGameTaskEvent*>& InEventIns) const;
};