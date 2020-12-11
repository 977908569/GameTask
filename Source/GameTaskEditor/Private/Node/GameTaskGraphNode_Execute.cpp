#include "GameTaskGraphNode_Execute.h"
#include "GameTask.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskEvent.h"
#include "GameTaskNode.h"
#include "GameTask_Execute.h"

UGameTaskGraphNode_Execute::UGameTaskGraphNode_Execute(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskGraphNode_Execute::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleNode, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_OnlyShow, TEXT("Out"));
}

FText UGameTaskGraphNode_Execute::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	const UGameTaskNode* MyNode = Cast<UGameTaskNode>(NodeInstance);
	if (MyNode != nullptr)
	{
		return FText::FromString(MyNode->GetNodeName());
	}
	else if (!ClassData.GetClassName().IsEmpty())
	{
		FString StoredClassName = ClassData.GetClassName();
		StoredClassName.RemoveFromEnd(TEXT("_C"));

		return FText::Format(NSLOCTEXT("GameTaskGraph", "NodeClassError", "Class {0} not found, make sure it's saved!"), FText::FromString(StoredClassName));
	}

	return Super::GetNodeTitle(TitleType);
}

void UGameTaskGraphNode_Execute::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	AddContextMenuActionsEvents(Menu, "GameTaskGraphNode", Context, EGameTaskSubNode::EnterEvent);
	AddContextMenuActionsEvents(Menu, "GameTaskGraphNode", Context, EGameTaskSubNode::ExitEvent);
}

void UGameTaskGraphNode_Execute::InsertSubNodeAt(UGameTaskGraphNodeBase* SubNode, int32 DropIndex)
{
	const int32 SubIdx = (DropIndex & 0xff) - 1;
	const int32 EnterIdx = ((DropIndex >> 8) & 0xff) - 1;
	const int32 ExitIdx = ((DropIndex >> 16) & 0xff) - 1;

	if (SubIdx >= 0)
	{
		SubNodes.Insert(SubNode, SubIdx);
	}
	else
	{
		SubNodes.Add(SubNode);
	}

	UGameTaskGraphNode_Event* TypedNode = Cast<UGameTaskGraphNode_Event>(SubNode);
	if (TypedNode)
	{
		if (TypedNode->bEnterEvent)
		{
			if (EnterIdx >= 0)
			{
				EnterEvents.Insert(TypedNode, EnterIdx);
			}
			else
			{
				EnterEvents.Add(TypedNode);
			}

		}
		else
		{
			if (ExitIdx >= 0)
			{
				ExitEvents.Insert(TypedNode, ExitIdx);
			}
			else
			{
				ExitEvents.Add(TypedNode);
			}
		}
	}
}

void UGameTaskGraphNode_Execute::OnSubNodeRemoved(UGameTaskGraphNodeBase* SubNode)
{
	const int32 EnterEventIdx = EnterEvents.IndexOfByKey(SubNode);
	const int32 ExitEventIdx = ExitEvents.IndexOfByKey(SubNode);

	if (EnterEventIdx >= 0)
	{
		EnterEvents.RemoveAt(EnterEventIdx);
	}
	if (ExitEventIdx >= 0)
	{
		ExitEvents.RemoveAt(ExitEventIdx);
	}
}

void UGameTaskGraphNode_Execute::RemoveAllSubNodes()
{
	Super::RemoveAllSubNodes();
	EnterEvents.Reset();
	ExitEvents.Reset();
}

int32 UGameTaskGraphNode_Execute::FindSubNodeDropIndex(UGameTaskGraphNodeBase* SubNode) const
{
	const int32 SubIdx = SubNodes.IndexOfByKey(SubNode) + 1;
	const int32 EnterIdx = EnterEvents.IndexOfByKey(SubNode) + 1;
	const int32 ExitIdx = ExitEvents.IndexOfByKey(SubNode) + 1;

	const int32 CombinedIdx = (SubIdx & 0xff) | ((EnterIdx & 0xff) << 8) | ((ExitIdx & 0xff) << 16);
	return CombinedIdx;
}

void UGameTaskGraphNode_Execute::OnSubNodeAdded(UGameTaskGraphNodeBase* SubNode)
{
	UGameTaskGraphNode_Event* EventNode = Cast<UGameTaskGraphNode_Event>(SubNode);
	if (EventNode)
	{
		if (EventNode->bEnterEvent)
		{
			EnterEvents.Add(EventNode);
		}
		else
		{
			ExitEvents.Add(EventNode);
		}
	}
}

int32 UGameTaskGraphNode_Execute::GetSubNodeNum() {
	return EnterEvents.Num() + ExitEvents.Num();
}

void UGameTaskGraphNode_Execute::UpdateGraph()
{
	Super::UpdateGraph();
	for (auto& Each : EnterEvents)
	{
		if (Each)
			Each->ParentNode = this;
	}

	for (auto& Each : ExitEvents)
	{
		if (Each)
			Each->ParentNode = this;
	}
}

void UGameTaskGraphNode_Execute::UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode)
{
	Super::UpdateAsset(InTaskAsset, InParentNode);
	UGameTask_Execute* Asset = Cast<UGameTask_Execute>(this->NodeInstance);
	check(Asset);
	CollectEvents(InTaskAsset, EnterEvents, Asset->ActiveEvents);
	CollectEvents(InTaskAsset, ExitEvents, Asset->FinishEvents);
	InParentNode->Children.Add(Asset);
}

void UGameTaskGraphNode_Execute::CollectEvents(UGameTask* TaskAsset, TArray<UGameTaskGraphNode_Event*>& Events, TArray<UGameTaskEvent*>& InEventIns) const
{
	InEventIns.Reset();
	TArray<UGameTaskEvent*> EventInstances;
	for (auto& Each : Events)
	{
		Each->CollectEventData(EventInstances);
	}

	for (int32 InsIdx = 0; InsIdx < EventInstances.Num(); InsIdx++)
	{
		if (EventInstances[InsIdx] && TaskAsset && Cast<UGameTask>(EventInstances[InsIdx]->GetOuter()) == nullptr)
		{
			EventInstances[InsIdx]->Rename(nullptr, TaskAsset);
		}

		EventInstances[InsIdx]->InitializeNode(Cast<UGameTask_Execute>(NodeInstance));
	}
	InEventIns.Append(EventInstances);
}
