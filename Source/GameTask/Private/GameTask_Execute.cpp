#include "GameTask_Execute.h"

UGameTask_Execute::UGameTask_Execute(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	NodeName = "Execute";
}

void UGameTask_Execute::Enter() {
	ItemState = EItemState::Disable;
	Active();
	Super::Enter();
}

void UGameTask_Execute::Active() {
	SetItemState(EItemState::Progress);
	for (auto& Each : ActiveEvents) {
		Each->OnTrigger();
	}
}

void UGameTask_Execute::Disable() {
	SetItemState(EItemState::Disable);
}

void UGameTask_Execute::Finish() {
	SetItemState(EItemState::Finish);
	SetNodeState(ENodeState::Succeeded);
	for (auto& Each : FinishEvents) {
		Each->OnTrigger();
	}
}

void UGameTask_Execute::Fail() {
	SetItemState(EItemState::Fail);
}

void UGameTask_Execute::SetItemState(EItemState InState) {
	if (InState == ItemState) return;
	ItemState = InState;
	switch (ItemState) {
	case EItemState::Disable:
		OnDisable();
		break;
	case EItemState::Progress:
		OnActive();
		break;
	case EItemState::Finish:
		OnFinish();
		break;
	case EItemState::Fail:
		OnFail();
		break;
	default:;
	}
}

EItemState UGameTask_Execute::GetItemState() const {
	return ItemState;
}


#if WITH_EDITOR
FName UGameTask_Execute::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Task.Icon");
}

#endif
