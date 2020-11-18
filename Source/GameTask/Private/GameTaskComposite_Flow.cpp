#include "GameTaskComposite_Flow.h"
#include "GameTaskEvent.h"

UGameTaskComposite_Flow::UGameTaskComposite_Flow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeName = "Flow";
}

void UGameTaskComposite_Flow::DoEnter() {
	for (auto& Each : EnterEvents) {
		Each->Enter();
	}

}

void UGameTaskComposite_Flow::DoExit() {
	for (auto& Each : ExitEvents) {
		Each->Exit();
	}
	Super::DoExit();
	if (Next)
	{
		Next->Enter();
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

