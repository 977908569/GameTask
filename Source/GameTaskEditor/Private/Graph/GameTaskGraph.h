#pragma once
#include "GameTaskGraphBase.h"
#include "GameTaskGraph.generated.h"
UCLASS()
class UGameTaskGraph : public UGameTaskGraphBase
{
	GENERATED_UCLASS_BODY()
public:
	enum EUpdateFlags
	{
		RebuildGraph = 0,
		ClearDebuggerFlags = 1,
		KeepRebuildCounter = 2,
	};

	virtual void OnCreated() override;
	virtual void OnLoaded() override;
	virtual void Initialize() override;
	void OnSave();

	virtual void UpdateVersion() override;
	virtual void MarkVersion() override;
	virtual void UpdateAsset(int32 UpdateFlags = 0) override;
	virtual void OnSubNodeDropped() override;
	void CreateGameTaskFromGraph(class UGameTaskGraphNode* RootEdNode);
	void SpawnMissingNodes();
	void UpdatePinConnectionTypes();

	void ReplaceNodeConnections(UEdGraphNode* OldNode, UEdGraphNode* NewNode);

	void RebuildChildOrder(UEdGraphNode* ParentNode);
	void RemoveUnknownSubNodes();

	void AutoArrange();
	//~ Help Function
	static void CreateChildren(class UGameTask* GameTaskAsset, class UGameTaskNode* RootNode, const UGameTaskGraphNode* RootEdNode);
	static UEdGraphPin* FindGraphNodePin(UEdGraphNode* Node, EEdGraphPinDirection Dir);
	static UGameTaskGraphNode* SpawnMissingGraphNodesWorker(UGameTaskNode* Node, UGameTaskGraphNode* ParentGraphNode, UGameTaskGraph* Graph, int32 ChildIdx, int32 ParentEventCount);
	static UGameTaskGraphNode* SpawnMissingGraphNodes(UGameTask* Asset, UGameTaskGraphNode* ParentGraphNode, UGameTaskGraph* Graph);
	//~ End Help Function

protected:
	void CollectAllNodeInstances(TSet<UObject*>& NodeInstances) override;

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif
};
