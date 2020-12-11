#include "GameTaskEvent.h"
#include "GameTaskTypes.h"

UGameTaskEvent::UGameTaskEvent()
{
	NodeName = TEXT("Event");
}

void UGameTaskEvent::Enter() {
	if (OnTrigger()) {
		SetNodeState(ENodeState::Succeeded);
	}
	else {
		SetNodeState(ENodeState::Failed);
		UE_LOG(LogTemp, Error, TEXT("Event Fail"))
	}
}

void UGameTaskEvent::SetNodeState(ENodeState InState) {
	NodeState = InState;
}

FString UGameTaskEvent::GetStaticDescription() const
{
	return FString::Printf(TEXT("%s"), *UGameTaskTypes::GetShortTypeName(this));
}

#if WITH_EDITOR
FName UGameTaskEvent::GetEnterIconName() const
{
	return FName("BTEditor.Graph.BTNode.Service.Icon");
}

FName UGameTaskEvent::GetExitIconName() const
{
	return FName("BTEditor.Graph.BTNode.Decorator.Cooldown.Icon");
}
#endif
