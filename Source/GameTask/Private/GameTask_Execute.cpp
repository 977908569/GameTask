#include "GameTask_Execute.h"

UGameTask_Execute::UGameTask_Execute(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
	NodeName = "Execute";
}
#if WITH_EDITOR
FName UGameTask_Execute::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Task.Icon");
}

#endif
