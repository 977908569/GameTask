#include "GameTaskGraph.h"
#include "GameTask.h"
#include "GameTaskCompositeNode.h"
#include "GameTaskComposite_Flow.h"
#include "GameTaskComposite_Parallel.h"
#include "GameTaskComposite_Sequence.h"
#include "GameTaskEditorGraphSchema.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskEvent.h"
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

void UGameTaskGraph::UpdateVersion()
{

}

void UGameTaskGraph::MarkVersion()
{
}

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

		if (auto FlowNode = Cast<UGameTaskGraphNode_Flow>(Node))
		{
			for (auto FlowEach : FlowNode->EnterEvents)
			{
				if (FlowEach)
					FlowEach->ParentNode = Node;
			}
		}

		if (auto ExecuteNode = Cast<UGameTaskGraphNode_Execute>(Node))
		{
			for (auto ExecuteEach : ExecuteNode->EnterEvents)
			{
				if (ExecuteEach)
					ExecuteEach->ParentNode = Node;
			}
		}

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


namespace GameTaskGraphHelpers
{
	struct FIntIntPair
	{
		int32 FirstIdx;
		int32 LastIdx;
	};

	void CollectEvents(UGameTask* GameTaskAsset, UGameTaskGraphNode* GraphNode, TArray<UGameTaskEvent*>& EventInstances, UGameTaskCompositeNode* RootNode)
	{
		TArray<UGameTaskGraphNode*> Events;
		if (const auto FlowNode = Cast<UGameTaskGraphNode_Flow>(GraphNode))
		{
			Events.Append(FlowNode->EnterEvents);
		}
		else if (const auto ExeNode = Cast<UGameTaskGraphNode_Execute>(GraphNode))
		{
			Events.Append(ExeNode->EnterEvents);
		}

		int32 NumNodes = 0;

		for (int32 Index = 0; Index < Events.Num(); Index++)
		{
			UGameTaskGraphNode* MyNode = Events[Index];
			if (MyNode == nullptr)
			{
				continue;
			}

			UGameTaskGraphNode_Event* MyEventNode = Cast<UGameTaskGraphNode_Event>(MyNode);

			if (MyEventNode)
			{
				MyEventNode->CollectEventData(EventInstances);
				NumNodes++;
			}
		}

		for (int32 InsIdx = 0; InsIdx < EventInstances.Num(); InsIdx++)
		{
			if (EventInstances[InsIdx] && GameTaskAsset && Cast<UGameTask>(EventInstances[InsIdx]->GetOuter()) == nullptr)
			{
				EventInstances[InsIdx]->Rename(nullptr, GameTaskAsset);
			}

			EventInstances[InsIdx]->InitializeNode(RootNode);
		}
	}

	void CreateChildren(UGameTask* GameTaskAsset, UGameTaskCompositeNode* RootNode, const UGameTaskGraphNode* RootEdNode)
	{
		if (RootEdNode == nullptr)
		{
			return;
		}

		RootNode->Children.Reset();
		// gather all nodes
		int32 ChildIdx = 0;
		for (int32 PinIdx = 0; PinIdx < RootEdNode->Pins.Num(); PinIdx++)
		{
			//Ignor InPut
			UEdGraphPin* Pin = RootEdNode->Pins[PinIdx];
			if (Pin->Direction != EGPD_Output)
			{
				continue;
			}

			// sort connections so that they're organized the same as user can see in the editor
			Pin->LinkedTo.Sort(FGameTaskCompareNodeXLocation());

			for (int32 Index = 0; Index < Pin->LinkedTo.Num(); ++Index)
			{
				UGameTaskGraphNode* GraphNode = Cast<UGameTaskGraphNode>(Pin->LinkedTo[Index]->GetOwningNode());
				if (GraphNode == nullptr)
				{
					continue;
				}
				//Execute
				UGameTask_Execute* ExecuteInstance = Cast<UGameTask_Execute>(GraphNode->NodeInstance);
				if (ExecuteInstance && Cast<UGameTask>(ExecuteInstance->GetOuter()) == nullptr)
				{
					ExecuteInstance->Rename(nullptr, GameTaskAsset);
				}
				//Child
				UGameTaskCompositeNode* CompositeInstance = Cast<UGameTaskCompositeNode>(GraphNode->NodeInstance);
				if (CompositeInstance && Cast<UGameTask>(CompositeInstance->GetOuter()) == nullptr)
				{
					CompositeInstance->Rename(nullptr, GameTaskAsset);
				}

				if (ExecuteInstance == nullptr && CompositeInstance == nullptr)
				{
					continue;
				}

				UGameTaskNode* ChildNode = CompositeInstance ? (UGameTaskNode*)CompositeInstance : (UGameTaskNode*)ExecuteInstance;
				if (ChildNode && Cast<UGameTask>(ChildNode->GetOuter()) == nullptr)
				{
					ChildNode->Rename(nullptr, GameTaskAsset);
				}

				//Flow
				UGameTaskComposite_Flow* FlowInstance = Cast<UGameTaskComposite_Flow>(ChildNode);
				if (FlowInstance)
				{
					FlowInstance->EnterEvents.Reset();
					FlowInstance->ExitEvents.Reset();
					TArray<UGameTaskEvent*>EnterInstances;
					CollectEvents(GameTaskAsset, GraphNode, EnterInstances, RootNode);
					FlowInstance->EnterEvents.Append(EnterInstances);
					UGameTaskComposite_Flow* RootFlow = Cast<UGameTaskComposite_Flow>(RootNode);
					if (RootFlow)
					{
						RootFlow->Next = FlowInstance;
					}
				}
				else
				{
					// store child data
					ChildIdx = RootNode->Children.AddDefaulted();
					FGameTaskCompositeChild& ChildInfo = RootNode->Children[ChildIdx];
					ChildInfo.ChildComposite = CompositeInstance;
					ChildInfo.ChildExecute = ExecuteInstance;
				}

				//任务节点
				if (ExecuteInstance)
				{
					ExecuteInstance->Events.Reset();
					TArray<UGameTaskEvent*>EventInstances;
					CollectEvents(GameTaskAsset, GraphNode, EventInstances, RootNode);
					ExecuteInstance->Events.Append(EventInstances);
				}

				// assign execution index to child node
				ChildNode->InitializeNode(RootNode);

				if (CompositeInstance)
				{
					CreateChildren(GameTaskAsset, CompositeInstance, GraphNode);
				}
			}
		}
	}

	UEdGraphPin* FindGraphNodePin(UEdGraphNode* Node, EEdGraphPinDirection Dir)
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

	UGameTaskGraphNode* SpawnMissingGraphNodesWorker(UGameTaskNode* Node, UGameTaskGraphNode* ParentGraphNode, UGameTaskGraph* Graph, int32 ChildIdx, int32 ParentEventCount)
	{
		if (Node == nullptr)
		{
			return nullptr;
		}
		UGameTaskGraphNode* GraphNode = nullptr;
		UGameTaskCompositeNode* CompositeNode = Cast<UGameTaskCompositeNode>(Node);
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
		else if (CompositeNode)
		{
			FGraphNodeCreator<UGameTaskGraphNode_Composite> NodeBuilder(*Graph);
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
			for (int32 SubIdx = 0; SubIdx < ExecuteNode->Events.Num(); SubIdx++)
			{
				UGameTaskGraphNode* EventNode = NewObject<UGameTaskGraphNode_Event>(Graph);
				EventNode->NodeInstance = ExecuteNode->Events[SubIdx];
				GraphNode->AddSubNode(EventNode, Graph);
			}
		}

		if (CompositeNode)
		{
			auto FlowNode = Cast<UGameTaskComposite_Flow>(CompositeNode);
			if (FlowNode)
			{
				for (int32 SubIdx = 0; SubIdx < FlowNode->EnterEvents.Num(); SubIdx++)
				{
					UGameTaskGraphNode* EventNode = NewObject<UGameTaskGraphNode_Event>(Graph);
					EventNode->NodeInstance = FlowNode->EnterEvents[SubIdx];
					GraphNode->AddSubNode(EventNode, Graph);
				}
			}
			UEdGraphPin* OutputPin = FindGraphNodePin(GraphNode, EGPD_Output);

			for (int32 Idx = 0; Idx < CompositeNode->Children.Num(); Idx++)
			{
				UGameTaskNode* ChildNode = CompositeNode->GetChildNode(Idx);

				UGameTaskGraphNode* ChildGraphNode = SpawnMissingGraphNodesWorker(ChildNode, GraphNode, Graph,
					Idx, ParentEventCount);

				UEdGraphPin* ChildInputPin = FindGraphNodePin(ChildGraphNode, EGPD_Input);

				OutputPin->MakeLinkTo(ChildInputPin);
			}
		}

		return GraphNode;
	}

	UGameTaskGraphNode* SpawnMissingGraphNodes(UGameTask* Asset, UGameTaskGraphNode* ParentGraphNode, UGameTaskGraph* Graph)
	{
		if (ParentGraphNode == nullptr || Asset == nullptr)
		{
			return nullptr;
		}

		UGameTaskGraphNode* GraphNode = SpawnMissingGraphNodesWorker(Asset->RootNode, ParentGraphNode, Graph, 0, 0);
		return GraphNode;
	}

} // namespace GameTaskGraphHelpers

void UGameTaskGraph::CreateGameTaskFromGraph(UGameTaskGraphNode* RootEdNode)
{
	//Asset
	UGameTask* GameTaskAsset = Cast<UGameTask>(GetOuter());
	GameTaskAsset->RootNode = nullptr;
	//Start Node
	GameTaskAsset->RootNode = Cast<UGameTaskCompositeNode>(RootEdNode->NodeInstance);
	if (GameTaskAsset->RootNode)
	{
		//Clear Parent Node
		GameTaskAsset->RootNode->InitializeNode(nullptr);
	}

	// connect tree nodes
	GameTaskGraphHelpers::CreateChildren(GameTaskAsset, GameTaskAsset->RootNode, RootEdNode);

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

		UGameTaskGraphNode* SpawnedRootNode = GameTaskGraphHelpers::SpawnMissingGraphNodes(GameTaskAsset, RootNode, this);
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

		const bool bIsCompositeNode = Node->IsA(UGameTaskGraphNode_Composite::StaticClass());

		for (int32 iPin = 0; iPin < Node->Pins.Num(); iPin++)
		{
			FName& PinCategory = Node->Pins[iPin]->PinType.PinCategory;
			if (PinCategory == TEXT("Transition"))
			{
				PinCategory = bIsCompositeNode ?
					UGameTaskEditorTypes::PinCategory_MultipleNodes :
					UGameTaskEditorTypes::PinCategory_SingleComposite;
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

