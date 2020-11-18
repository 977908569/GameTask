#include "GameTaskGraphNode_Execute.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskNode.h"

UGameTaskGraphNode_Execute::UGameTaskGraphNode_Execute(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskGraphNode_Execute::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UGameTaskEditorTypes::PinCategory_SingleComposite, TEXT("In"));
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
	AddContextMenuActionsEvents(Menu, "GameTaskGraphNode", Context);
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
