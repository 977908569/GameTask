#include "GameTask.h"
#include "GameTaskCompositeNode.h"

UGameTask::UGameTask()
{
}

void UGameTask::Start() {
	if (RootNode) {
		RootNode->Enter();
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Game Task Start Fial : RootNode is Null"));
	}
}

UWorld* UGameTask::GetWorld() const
{
	return Super::GetWorld();
}


