#include "GameTaskGraphNode_Flow.h"
#include "GameTask.h"
#include "GameTaskComposite_Flow.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskEvent.h"
#define LOCTEXT_NAMESPACE "GameTask"

UGameTaskGraphNode_Flow::UGameTaskGraphNode_Flow()
{
}

int32 UGameTaskGraphNode_Flow::GetSubNodeNum()
{
	return EnterEvents.Num() + ExitEvents.Num();
}

void UGameTaskGraphNode_Flow::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleFlow, TEXT("In"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_SingleNode, TEXT("Composite"));
	CreatePin(EGPD_Output, UGameTaskEditorTypes::PinCategory_SingleFlow, TEXT("Out"));
}

void UGameTaskGraphNode_Flow::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
}

void UGameTaskGraphNode_Flow::OnSubNodeAdded(UGameTaskGraphNodeBase* SubNode)
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

void UGameTaskGraphNode_Flow::OnSubNodeRemoved(UGameTaskGraphNodeBase* SubNode)
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

void UGameTaskGraphNode_Flow::RemoveAllSubNodes()
{
	Super::RemoveAllSubNodes();
	EnterEvents.Reset();
	ExitEvents.Reset();
}

void UGameTaskGraphNode_Flow::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const {
	AddContextMenuActionsEvents(Menu, "GameTaskGraphNode", Context, EGameTaskSubNode::EnterEvent);
	AddContextMenuActionsEvents(Menu, "GameTaskGraphNode", Context, EGameTaskSubNode::ExitEvent);
}

void UGameTaskGraphNode_Flow::UpdateAsset(UGameTask* InTaskAsset, UGameTaskNode* InParentNode)
{
	UGameTaskComposite_Flow* Asset = Cast<UGameTaskComposite_Flow>(NodeInstance);
	check(Asset);
	CollectEvents(InTaskAsset, EnterEvents, Asset->EnterEvents);
	CollectEvents(InTaskAsset, ExitEvents, Asset->ExitEvents);

	UGameTaskComposite_Flow* RootFlow = Cast<UGameTaskComposite_Flow>(InParentNode);
	if (RootFlow)
	{
		RootFlow->Next = Asset;
	}
}

void UGameTaskGraphNode_Flow::UpdateGraph()
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

int32 UGameTaskGraphNode_Flow::FindSubNodeDropIndex(UGameTaskGraphNodeBase* SubNode) const
{
	const int32 SubIdx = SubNodes.IndexOfByKey(SubNode) + 1;
	const int32 EnterIdx = EnterEvents.IndexOfByKey(SubNode) + 1;
	const int32 ExitIdx = ExitEvents.IndexOfByKey(SubNode) + 1;

	const int32 CombinedIdx = (SubIdx & 0xff) | ((EnterIdx & 0xff) << 8) | ((ExitIdx & 0xff) << 16);
	return CombinedIdx;
}

void UGameTaskGraphNode_Flow::InsertSubNodeAt(UGameTaskGraphNodeBase* SubNode, int32 DropIndex)
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

void UGameTaskGraphNode_Flow::CollectEvents(UGameTask* TaskAsset, TArray<UGameTaskGraphNode_Event*>& Events, TArray<UGameTaskEvent*>& InEventIns) const
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

		EventInstances[InsIdx]->InitializeNode(Cast<UGameTaskComposite_Flow>(NodeInstance));
	}
	InEventIns.Append(EventInstances);
}

#undef LOCTEXT_NAMESPACE
