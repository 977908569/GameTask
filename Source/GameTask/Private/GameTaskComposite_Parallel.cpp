#include "GameTaskComposite_Parallel.h"

UGameTaskComposite_Parallel::UGameTaskComposite_Parallel(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeName = "Parallel";
}
FString UGameTaskComposite_Parallel::GetStaticDescription() const
{
	return Super::GetStaticDescription();
}

void UGameTaskComposite_Parallel::Enter() {
	for (auto& Each : Children) {
		Each->Enter();
	}
	Super::Enter();
}

void UGameTaskComposite_Parallel::CheckNodeState() {
	bool bAllSucc = true;
	for (auto& Each : Children) {
		if (Each->GetNodeState() != ENodeState::Succeeded) {
			bAllSucc = false;
		}
	}
	if (bAllSucc) SetNodeState(ENodeState::Succeeded);
}

#if WITH_EDITOR
FName UGameTaskComposite_Parallel::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.SimpleParallel.Icon");
}
#endif

