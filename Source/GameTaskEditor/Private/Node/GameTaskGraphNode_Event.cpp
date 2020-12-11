#include "GameTaskGraphNode_Event.h"
#include "GameTaskEvent.h"
#define LOCTEXT_NAMESPACE "GameTask"

UGameTaskGraphNode_Event::UGameTaskGraphNode_Event(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsSubNode = true;
}

FText UGameTaskGraphNode_Event::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	const UGameTaskEvent* Event = Cast<UGameTaskEvent>(NodeInstance);
	if (Event)
	{
		return FText::FromString(Event->GetNodeName());
	}
	else if (!ClassData.GetClassName().IsEmpty())
	{
		FString StoredClassName = ClassData.GetClassName();
		StoredClassName.RemoveFromEnd(TEXT("_C"));

		return FText::Format(NSLOCTEXT("GameTaskGraph", "NodeClassError", "Class {0} not found, make sure it's saved!"), FText::FromString(StoredClassName));
	}
	return Super::GetNodeTitle(TitleType);
}

void UGameTaskGraphNode_Event::AllocateDefaultPins()
{
	//No Pins for events
}

void UGameTaskGraphNode_Event::CollectEventData(TArray<UGameTaskEvent*>& NodeInstances) const
{
	if (NodeInstance)
	{
		UGameTaskEvent* EventNode = Cast<UGameTaskEvent>(NodeInstance);
		check(EventNode);
		NodeInstances.Add(EventNode);
	}
}

FName UGameTaskGraphNode_Event::GetNameIcon() const {
	if (UGameTaskEvent* EventNode = Cast<UGameTaskEvent>(NodeInstance))
	{
		if (bEnterEvent) return EventNode->GetEnterIconName();
		else return  EventNode->GetExitIconName();

	}
	return Super::GetNameIcon();
}
#undef LOCTEXT_NAMESPACE
