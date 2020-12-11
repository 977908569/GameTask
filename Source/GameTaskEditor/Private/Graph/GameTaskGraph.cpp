#include "GameTaskGraph.h"
#include "GameTask.h"
#include "GameTaskComposite_Flow.h"
#include "GameTaskComposite_Parallel.h"
#include "GameTaskComposite_Sequence.h"
#include "GameTaskEditorGraphSchema.h"
#include "GameTaskEditorTypes.h"
#include "Node/GameTaskGraphNode_Event.h"
#include "Node/GameTaskGraphNode_Execute.h"
#include "Node/GameTaskGraphNode_Parallel.h"
#include "Node/GameTaskGraphNode_Root.h"
#include "GameTaskNode.h"
#include "GameTask_Execute.h"
#include "Node/GameTaskGraphNode_Flow.h"
#include "Node/GameTaskGraphNode_Sequence.h"

UGameTaskGraph::UGameTaskGraph(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Schema = UGameTaskEditorGraphSchema::StaticClass();
}

void UGameTaskGraph::OnCreated()
{
	Super::OnCreated();
	SpawnMissingNodes();
}

void UGameTaskGraph::OnLoaded()
{
	Super::OnLoaded();
	UpdatePinConnectionTypes();
	RemoveUnknownSubNodes();
}

void UGameTaskGraph::Initialize()
{
	Super::Initialize();
}

void UGameTaskGraph::OnSave()
{
	UpdateAsset();
}

void UGameTaskGraph::UpdateVersion() {}

void UGameTaskGraph::MarkVersion() {}

void UGameTaskGraph::UpdateAsset(int32 UpdateFlags)
{
	if (bLockUpdates)
	{
		return;
	}

	// initial cleanup & root node search
	UGameTaskGraphNode_Root* RootNode = nullptr;
	for (int32 Index = 0; Index < Nodes.Num(); ++Index)
	{
		UGameTaskGraphNode* Node = Cast<UGameTaskGraphNode>(Nodes[Index]);
		if (Node == nullptr)
		{
			// ignore.
			continue;
		}
		// debugger flags
		if (UpdateFlags & ClearDebuggerFlags)
		{
			//TODO Debug
		}
		// parent chain
		Node->ParentNode = nullptr;
		Node->UpdateGraph();

		// prepare node instance
		UGameTaskNode* NodeInstance = Cast<UGameTaskNode>(Node->NodeInstance);
		if (NodeInstance)
		{
			NodeInstance->InitializeNode(nullptr);
		}

		// cache root
		if (RootNode == nullptr)
		{
			RootNode = Cast<UGameTaskGraphNode_Root>(Nodes[Index]);
		}
	}

	// we can't look at pins until pin references have been fixed up post undo:
	UEdGraphPin::ResolveAllPinReferences();
	check(RootNode);
	if (RootNode && RootNode->Pins.Num() > 0 && RootNode->Pins[0]->LinkedTo.Num() > 0)
	{
		UGameTaskGraphNode* Node = Cast<UGameTaskGraphNode>(RootNode->Pins[0]->LinkedTo[0]->GetOwningNode());
		if (Node)
		{
			CreateGameTaskFromGraph(Node);
		}
	}
}

void UGameTaskGraph::OnSubNodeDropped()
{
	Super::OnSubNodeDropped();
}

//创建连接节点
void UGameTaskGraph::CreateChildren(UGameTask* GameTaskAsset, UGameTaskNode* RootNode, const UGameTaskGraphNode* RootEdNode)
{
	if (RootEdNode == nullptr)
	{
		return;
	}
	//Clear
	RootNode->Children.Empty();
	// gather all nodes
	for (int32 PinIdx = 0; PinIdx < RootEdNode->Pins.Num(); PinIdx++)
	{
		//Ignor InPut
		UEdGraphPin* Pin = RootEdNode->Pins[PinIdx];
		if (Pin->Direction != EGPD_Output)
		{
			continue;
		}

		// Sort 
		Pin->LinkedTo.Sort(FGameTaskCompareNodeXLocation());

		for (int32 Index = 0; Index < Pin->LinkedTo.Num(); ++Index)
		{
			UGameTaskGraphNode* GraphNode = Cast<UGameTaskGraphNode>(Pin->LinkedTo[Index]->GetOwningNode());
			if (GraphNode == nullptr)
			{
				continue;
			}

			//Child
			UGameTaskNode* ChildInstance = Cast<UGameTaskNode>(GraphNode->NodeInstance);
			if (ChildInstance && Cast<UGameTask>(ChildInstance->GetOuter()) == nullptr)
			{
				ChildInstance->Rename(nullptr, GameTaskAsset);
			}

			if (ChildInstance == nullptr)
			{
				continue;
			}

			// assign execution index to child node
			ChildInstance->InitializeNode(RootNode);
			//更新资源
			GraphNode->UpdateAsset(GameTaskAsset, RootNode);

			if (ChildInstance)
			{
				CreateChildren(GameTaskAsset, ChildInstance, GraphNode);
			}
		}
	}
}

UEdGraphPin* UGameTaskGraph::FindGraphNodePin(UEdGraphNode* Node, EEdGraphPinDirection Dir)
{
	UEdGraphPin* Pin = nullptr;
	for (int32 Idx = 0; Idx < Node->Pins.Num(); Idx++)
	{
		if (Node->Pins[Idx]->Direction == Dir)
		{
			Pin = Node->Pins[Idx];
			break;
		}
	}

	return Pin;
}

UGameTaskGraphNode* UGameTaskGraph::SpawnMissingGraphNodesWorker(UGameTaskNode* Node, UGameTaskGraphNode* ParentGraphNode, UGameTaskGraph* Graph, int32 ChildIdx, int32 ParentEventCount)
{
	if (Node == nullptr)
	{
		return nullptr;
	}
	UGameTaskGraphNode* GraphNode = nullptr;
	if (Node->IsA(UGameTaskComposite_Parallel::StaticClass()))
	{
		FGraphNodeCreator<UGameTaskGraphNode_Parallel> NodeBuilder(*Graph);
		GraphNode = NodeBuilder.CreateNode();
		NodeBuilder.Finalize();
	}
	else if (Node->IsA(UGameTaskComposite_Sequence::StaticClass()))
	{
		FGraphNodeCreator<UGameTaskGraphNode_Sequence> NodeBuilder(*Graph);
		GraphNode = NodeBuilder.CreateNode();
		NodeBuilder.Finalize();
	}
	else if (Node->IsA(UGameTaskComposite_Flow::StaticClass()))
	{
		FGraphNodeCreator<UGameTaskGraphNode_Flow> NodeBuilder(*Graph);
		GraphNode = NodeBuilder.CreateNode();
		NodeBuilder.Finalize();
	}
	else if (Node->IsA(UGameTask_Execute::StaticClass()))
	{
		FGraphNodeCreator<UGameTaskGraphNode_Execute> NodeBuilder(*Graph);
		GraphNode = NodeBuilder.CreateNode();
		NodeBuilder.Finalize();
	}
	else
	{
		FGraphNodeCreator<UGameTaskGraphNode> NodeBuilder(*Graph);
		GraphNode = NodeBuilder.CreateNode();
		NodeBuilder.Finalize();
	}

	if (GraphNode)
	{
		const int32 ParentSubNodes = ParentGraphNode->GetSubNodeNum();
		GraphNode->NodePosX = ParentGraphNode->NodePosX + ChildIdx * 400.0f;
		GraphNode->NodePosY = ParentGraphNode->NodePosY + (ParentEventCount + ParentSubNodes + 1) * 75.0f;
		GraphNode->NodeInstance = Node;
	}

	if (auto ExecuteNode = Cast<UGameTask_Execute>(Node))
	{
		for (int32 SubIdx = 0; SubIdx < ExecuteNode->ActiveEvents.Num(); SubIdx++)
		{
			UGameTaskGraphNode* EventNode = NewObject<UGameTaskGraphNode_Event>(Graph);
			EventNode->NodeInstance = ExecuteNode->ActiveEvents[SubIdx];
			GraphNode->AddSubNode(EventNode, Graph);
		}

		for (int32 SubIdx = 0; SubIdx < ExecuteNode->FinishEvents.Num(); SubIdx++)
		{
			UGameTaskGraphNode* EventNode = NewObject<UGameTaskGraphNode_Event>(Graph);
			EventNode->NodeInstance = ExecuteNode->FinishEvents[SubIdx];
			GraphNode->AddSubNode(EventNode, Graph);
		}
	}
	else if (auto FlowNode = Cast<UGameTaskComposite_Flow>(Node))
	{
		for (int32 SubIdx = 0; SubIdx < FlowNode->EnterEvents.Num(); SubIdx++)
		{
			UGameTaskGraphNode* EventNode = NewObject<UGameTaskGraphNode_Event>(Graph);
			EventNode->NodeInstance = FlowNode->EnterEvents[SubIdx];
			GraphNode->AddSubNode(EventNode, Graph);
		}

		for (int32 SubIdx = 0; SubIdx < FlowNode->ExitEvents.Num(); SubIdx++)
		{
			UGameTaskGraphNode* EventNode = NewObject<UGameTaskGraphNode_Event>(Graph);
			EventNode->NodeInstance = FlowNode->ExitEvents[SubIdx];
			GraphNode->AddSubNode(EventNode, Graph);
		}
	}

	UEdGraphPin* OutputPin = FindGraphNodePin(GraphNode, EGPD_Output);

	for (int32 Idx = 0; Idx < Node->Children.Num(); Idx++)
	{
		UGameTaskNode* ChildNode = Node->Children[Idx];
		UGameTaskGraphNode* ChildGraphNode = SpawnMissingGraphNodesWorker(ChildNode, GraphNode, Graph, Idx, ParentEventCount);
		UEdGraphPin* ChildInputPin = FindGraphNodePin(ChildGraphNode, EGPD_Input);
		OutputPin->MakeLinkTo(ChildInputPin);
	}

	return GraphNode;
}

UGameTaskGraphNode* UGameTaskGraph::SpawnMissingGraphNodes(UGameTask* Asset, UGameTaskGraphNode* ParentGraphNode, UGameTaskGraph* Graph)
{
	if (ParentGraphNode == nullptr || Asset == nullptr)
	{
		return nullptr;
	}

	UGameTaskGraphNode* GraphNode = SpawnMissingGraphNodesWorker(Asset->RootNode, ParentGraphNode, Graph, 0, 0);
	return GraphNode;
}

void UGameTaskGraph::CreateGameTaskFromGraph(UGameTaskGraphNode* RootEdNode)
{
	//Asset
	UGameTask* GameTaskAsset = Cast<UGameTask>(GetOuter());
	GameTaskAsset->RootNode = nullptr;

	//Start Node
	GameTaskAsset->RootNode = Cast<UGameTaskComposite_Flow>(RootEdNode->NodeInstance);
	check(GameTaskAsset->RootNode);

	if (GameTaskAsset->RootNode)
	{
		//Clear Parent Node
		GameTaskAsset->RootNode->InitializeNode(nullptr);
	}
	RootEdNode->UpdateAsset(GameTaskAsset, nullptr);
	// connect tree nodes
	UGameTaskGraph::CreateChildren(GameTaskAsset, GameTaskAsset->RootNode, RootEdNode);

	// Now remove any orphaned nodes left behind after regeneration
	RemoveOrphanedNodes();
}

void UGameTaskGraph::SpawnMissingNodes()
{
	UGameTask* GameTaskAsset = Cast<UGameTask>(GetOuter());
	if (GameTaskAsset)
	{
		UGameTaskGraphNode* RootNode = nullptr;
		for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
		{
			RootNode = Cast<UGameTaskGraphNode_Root>(Nodes[Idx]);
			if (RootNode)
			{
				break;
			}
		}

		UGameTaskGraphNode* SpawnedRootNode = UGameTaskGraph::SpawnMissingGraphNodes(GameTaskAsset, RootNode, this);
		if (RootNode && SpawnedRootNode)
		{
			UEdGraphPin* RootOutPin = FindGraphNodePin(RootNode, EGPD_Output);
			UEdGraphPin* SpawnedInPin = FindGraphNodePin(SpawnedRootNode, EGPD_Input);

			RootOutPin->MakeLinkTo(SpawnedInPin);
		}
	}
}

void UGameTaskGraph::UpdatePinConnectionTypes()
{
	for (int32 Index = 0; Index < Nodes.Num(); ++Index)
	{
		UEdGraphNode* Node = Nodes[Index];
		check(Node);


		for (int32 iPin = 0; iPin < Node->Pins.Num(); iPin++)
		{
			FName& PinCategory = Node->Pins[iPin]->PinType.PinCategory;
			if (PinCategory == TEXT("Transition"))
			{
				PinCategory = UGameTaskEditorTypes::PinCategory_MultipleNodes;
			}
		}
	}
}

void UGameTaskGraph::ReplaceNodeConnections(UEdGraphNode* OldNode, UEdGraphNode* NewNode)
{
	for (int32 Index = 0; Index < Nodes.Num(); ++Index)
	{
		UEdGraphNode* Node = Nodes[Index];
		check(Node);
		for (int32 PinIndex = 0; PinIndex < Node->Pins.Num(); PinIndex++)
		{
			UEdGraphPin* Pin = Node->Pins[PinIndex];
			for (int32 LinkedIndex = 0; LinkedIndex < Pin->LinkedTo.Num(); LinkedIndex++)
			{
				UEdGraphPin* LinkedPin = Pin->LinkedTo[LinkedIndex];
				const UEdGraphNode* LinkedNode = LinkedPin ? LinkedPin->GetOwningNode() : NULL;

				if (LinkedNode == OldNode)
				{
					check(OldNode);
					check(LinkedPin);

					const int32 LinkedPinIndex = OldNode->Pins.IndexOfByKey(LinkedPin);
					Pin->LinkedTo[LinkedIndex] = NewNode->Pins[LinkedPinIndex];
					LinkedPin->LinkedTo.Remove(Pin);
				}
			}
		}
	}
}

void UGameTaskGraph::RebuildChildOrder(UEdGraphNode* ParentNode)
{
	bool bUpdateExecutionOrder = false;
	if (ParentNode)
	{
		for (int32 PinIdx = 0; PinIdx < ParentNode->Pins.Num(); PinIdx++)
		{
			UEdGraphPin* Pin = ParentNode->Pins[PinIdx];
			if (Pin->Direction == EGPD_Output)
			{
				TArray<UEdGraphPin*> PrevOrder(Pin->LinkedTo);
				Pin->LinkedTo.Sort(FGameTaskCompareNodeXLocation());

				bUpdateExecutionOrder = bUpdateExecutionOrder || (PrevOrder != Pin->LinkedTo);
			}
		}
	}

	if (bUpdateExecutionOrder)
	{
		UpdateAsset(KeepRebuildCounter);
		Modify();
	}
}

void UGameTaskGraph::RemoveUnknownSubNodes()
{
	for (int32 Index = 0; Index < Nodes.Num(); ++Index)
	{
		UGameTaskGraphNode* Node = Cast<UGameTaskGraphNode>(Nodes[Index]);
		if (Node)
		{
			for (int32 SubIdx = Node->SubNodes.Num() - 1; SubIdx >= 0; SubIdx--)
			{

			}
		}
	}
}

void UGameTaskGraph::AutoArrange()
{
}

void UGameTaskGraph::CollectAllNodeInstances(TSet<UObject*>& NodeInstances)
{
	Super::CollectAllNodeInstances(NodeInstances);
}

#if WITH_EDITOR
void UGameTaskGraph::PostEditUndo()
{
	Super::PostEditUndo();

	// make sure that all execution indices are up to date
	UpdateAsset(KeepRebuildCounter);
	Modify();
}

#endif

