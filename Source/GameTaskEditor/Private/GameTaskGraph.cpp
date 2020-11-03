#include "GameTaskGraph.h"
#include "GameTask.h"
#include "GameTaskCompositeNode.h"
#include "GameTaskComposite_Parallel.h"
#include "GameTaskEditorGraphSchema.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskEvent.h"
#include "GameTaskExecuteNode.h"
#include "GameTaskGraphNode_Event.h"
#include "GameTaskGraphNode_Execute.h"
#include "GameTaskGraphNode_Parallel.h"
#include "GameTaskGraphNode_Root.h"
#include "GameTaskNode.h"

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
	SpawnMissingNodesForParallel();
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
	UGameTaskGraphNode_Root* RootNode = NULL;
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

		}

		// parent chain
		Node->ParentNode = NULL;
		for (int32 EIdx = 0; EIdx < Node->Events.Num(); EIdx++)
		{
			Node->Events[EIdx]->ParentNode = Node;
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

	void CollectEvents(UGameTask* GameTaskAsset,
		UGameTaskGraphNode* GraphNode, TArray<UGameTaskEvent*>& EventInstances, UGameTaskCompositeNode* RootNode)
	{
		int32 NumNodes = 0;

		for (int32 Index = 0; Index < GraphNode->Events.Num(); Index++)
		{
			UGameTaskGraphNode* MyNode = GraphNode->Events[Index];
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
		RootNode->Events.Reset();

		// collect events (composite node)
		if (RootEdNode->Events.Num())
		{
			for (int32 ServiceIdx = 0; ServiceIdx < RootEdNode->Events.Num(); ServiceIdx++)
			{
				UGameTaskEvent* EventInstance = RootEdNode->Events[ServiceIdx] ? Cast<UGameTaskEvent>(RootEdNode->Events[ServiceIdx]->NodeInstance) : nullptr;
				if (EventInstance)
				{
					if (Cast<UGameTask>(EventInstance->GetOuter()) == nullptr)
					{
						EventInstance->Rename(nullptr, GameTaskAsset);
					}
					EventInstance->InitializeNode(RootNode);

					RootNode->Events.Add(EventInstance);
				}
			}
		}

		// gather all nodes
		int32 ChildIdx = 0;
		for (int32 PinIdx = 0; PinIdx < RootEdNode->Pins.Num(); PinIdx++)
		{
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

				UGameTaskExecuteNode* ExecuteInstance = Cast<UGameTaskExecuteNode>(GraphNode->NodeInstance);
				if (ExecuteInstance && Cast<UGameTask>(ExecuteInstance->GetOuter()) == nullptr)
				{
					ExecuteInstance->Rename(nullptr, GameTaskAsset);
				}

				UGameTaskCompositeNode* CompositeInstance = Cast<UGameTaskCompositeNode>(GraphNode->NodeInstance);
				if (CompositeInstance && Cast<UGameTask>(CompositeInstance->GetOuter()) == nullptr)
				{
					CompositeInstance->Rename(nullptr, GameTaskAsset);
				}

				if (ExecuteInstance == nullptr && CompositeInstance == nullptr)
				{
					continue;
				}

				// collect events
				TArray<UGameTaskEvent*> EventInstances;

				CollectEvents(GameTaskAsset, GraphNode, EventInstances, RootNode);

				// store child data
				ChildIdx = RootNode->Children.AddDefaulted();
				FGameTaskCompositeChild& ChildInfo = RootNode->Children[ChildIdx];
				ChildInfo.ChildComposite = CompositeInstance;
				ChildInfo.ChildExecute = ExecuteInstance;
				ChildInfo.Events = EventInstances;


				UGameTaskNode* ChildNode = CompositeInstance ? (UGameTaskNode*)CompositeInstance : (UGameTaskNode*)ExecuteInstance;
				if (ChildNode && Cast<UGameTask>(ChildNode->GetOuter()) == nullptr)
				{
					ChildNode->Rename(nullptr, GameTaskAsset);
				}

				// collect events (exe node)
				if (ExecuteInstance)
				{
					ExecuteInstance->Events.Reset();

					for (int32 EventIdx = 0; EventIdx < GraphNode->Events.Num(); EventIdx++)
					{
						UGameTaskEvent* EventInstance = GraphNode->Events[EventIdx] ? Cast<UGameTaskEvent>(GraphNode->Events[EventIdx]->NodeInstance) : nullptr;
						if (EventInstance)
						{
							if (Cast<UGameTask>(EventInstance->GetOuter()) == nullptr)
							{
								EventInstance->Rename(nullptr, GameTaskAsset);
							}

							EventInstance->InitializeNode(RootNode);
							ExecuteInstance->Events.Add(EventInstance);
						}
					}
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

	void SpawnMissingEventNodes(UGameTaskGraphNode* GraphNode, const TArray<UGameTaskEvent*>& Events, UGameTaskGraph* Graph)
	{

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
		else if (CompositeNode)
		{
			FGraphNodeCreator<UGameTaskGraphNode_Composite> NodeBuilder(*Graph);
			GraphNode = NodeBuilder.CreateNode();
			NodeBuilder.Finalize();
		}
		else
		{
			FGraphNodeCreator<UGameTaskGraphNode_Execute> NodeBuilder(*Graph);
			GraphNode = NodeBuilder.CreateNode();
			NodeBuilder.Finalize();
		}

		if (GraphNode)
		{
			const int32 ParentSubNodes = ParentGraphNode->Events.Num();
			GraphNode->NodePosX = ParentGraphNode->NodePosX + ChildIdx * 400.0f;
			GraphNode->NodePosY = ParentGraphNode->NodePosY + (ParentEventCount + ParentSubNodes + 1) * 75.0f;
			GraphNode->NodeInstance = Node;
		}

		if (CompositeNode)
		{
			for (int32 SubIdx = 0; SubIdx < CompositeNode->Events.Num(); SubIdx++)
			{
				UGameTaskGraphNode* ServiceNode = NewObject<UGameTaskGraphNode_Event>(Graph);
				ServiceNode->NodeInstance = CompositeNode->Events[SubIdx];
				GraphNode->AddSubNode(ServiceNode, Graph);
			}

			UEdGraphPin* OutputPin = FindGraphNodePin(GraphNode, EGPD_Output);

			for (int32 Idx = 0; Idx < CompositeNode->Children.Num(); Idx++)
			{
				UGameTaskNode* ChildNode = CompositeNode->GetChildNode(Idx);
				UGameTaskGraphNode* ChildGraphNode = SpawnMissingGraphNodesWorker(ChildNode, GraphNode, Graph,
					Idx, ParentEventCount + CompositeNode->Children[Idx].Events.Num());

				SpawnMissingEventNodes(ChildGraphNode,
					CompositeNode->Children[Idx].Events,
					Graph);

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
		//SpawnMissingEventNodes(GraphNode, Asset->RootDecorators, Asset->RootDecoratorOps, Graph);
		return GraphNode;
	}

} // namespace BTGraphHelpers



void UGameTaskGraph::CreateGameTaskFromGraph(UGameTaskGraphNode* RootEdNode)
{
	UGameTask* GameTaskAsset = Cast<UGameTask>(GetOuter());
	GameTaskAsset->RootNode = nullptr;

	GameTaskAsset->RootNode = Cast<UGameTaskCompositeNode>(RootEdNode->NodeInstance);
	if (GameTaskAsset->RootNode)
	{
		GameTaskAsset->RootNode->InitializeNode(nullptr);
	}

	// collect root level decorators
	uint16 DummyIndex = MAX_uint16;

	//GameTaskGraphHelpers::CollectEvents(GameTaskAsset, RootEdNode, GameTaskAsset->RootDecorators);

	// connect tree nodes
	GameTaskGraphHelpers::CreateChildren(GameTaskAsset, GameTaskAsset->RootNode, RootEdNode); //-V595

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

void UGameTaskGraph::SpawnMissingNodesForParallel()
{
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
				const bool bIsDecorator = Node->Events.Contains(Node->SubNodes[SubIdx]);

				if (!bIsDecorator)
				{
					Node->SubNodes.RemoveAt(SubIdx);
				}
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

