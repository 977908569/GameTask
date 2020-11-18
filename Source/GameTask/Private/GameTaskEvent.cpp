#include "GameTaskEvent.h"
#include "GameTaskTypes.h"


UGameTaskEvent::UGameTaskEvent()
{
	NodeName = TEXT("Event");
}

FString UGameTaskEvent::GetStaticDescription() const
{
	return FString::Printf(TEXT("%s"), *UGameTaskTypes::GetShortTypeName(this));
}


#if WITH_EDITOR

FName UGameTaskEvent::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Service.Icon");
}

#endif
