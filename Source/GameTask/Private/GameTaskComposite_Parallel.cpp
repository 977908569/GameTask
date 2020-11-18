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

#if WITH_EDITOR
FName UGameTaskComposite_Parallel::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.SimpleParallel.Icon");
}
#endif

