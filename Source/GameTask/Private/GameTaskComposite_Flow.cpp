#include "GameTaskComposite_Flow.h"
#include "GameTaskEvent.h"

UGameTaskComposite_Flow::UGameTaskComposite_Flow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), Next(nullptr) {
	NodeName = "Flow";
}

void UGameTaskComposite_Flow::Enter() {
	for (auto& Each : EnterEvents) Each->Enter();
	for (auto& Each : Children) Each->Enter();
	Super::Enter();
}

void UGameTaskComposite_Flow::Exit() {
	for (auto& Each : ExitEvents) Each->Enter();
	if (Next) Next->Enter();
	else UE_LOG(LogTemp, Log, TEXT("********TASK END*********"));
}

void UGameTaskComposite_Flow::CheckNodeState() {

	bool bAllSucc = true;
	for (auto& Each : Children) {
		if (Each->GetNodeState() != ENodeState::Succeeded) {
			bAllSucc = false;
		}
	}
	if (bAllSucc) {
		NodeState = ENodeState::Succeeded;
		Exit();
	}
}

FString UGameTaskComposite_Flow::GetStaticDescription() const
{
	return Super::GetStaticDescription();
}

#if WITH_EDITOR
FName UGameTaskComposite_Flow::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.SimpleParallel.Icon");
}
#endif

