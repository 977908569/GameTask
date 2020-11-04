#include "GameTaskGraphNode_Event.h"
#define LOCTEXT_NAMESPACE "GameTask"
UGameTaskGraphNode_Event::UGameTaskGraphNode_Event(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsSubNode = true;
}

FText UGameTaskGraphNode_Event::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return Super::GetNodeTitle(TitleType);
}

void UGameTaskGraphNode_Event::AllocateDefaultPins()
{
}

void UGameTaskGraphNode_Event::CollectEventData(TArray<UGameTaskEvent*>& NodeInstances) const
{
	if (NodeInstance)
	{
		UGameTaskEvent* EventNode = Cast<UGameTaskEvent>(NodeInstance);
		const int32 InstanceIdx = NodeInstances.Add(EventNode);
	}
}

FString UGameTaskGraphNode_Event::GetNodeTypeDescription() const
{
	return LOCTEXT("Composite", "Composite").ToString();
}
#undef LOCTEXT_NAMESPACE