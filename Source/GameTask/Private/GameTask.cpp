#include "GameTask.h"
#include "GameTaskActor.h"
#include "GameTaskComposite_Flow.h"
#include "GameTaskNode.h"

UGameTask::UGameTask()
{
}

void UGameTask::Start(AGameTaskActor* InOwner) {
	TaskActor = InOwner;
	CheckInit();
	if (RootNode) {
		RootNode->Enter();
	}
}

AGameTaskActor* UGameTask::GetTaskActor() const {
	if (TaskActor.IsValid()) return TaskActor.Get();
	return nullptr;
}

UGameTaskNode* UGameTask::FindNode(const int32 InID) {
	for (auto& Each : CachNodes) {
		if (Each->ID == InID) return Each;
	}
	return nullptr;
}

UWorld* UGameTask::GetWorld() const
{
	if (TaskActor.IsValid()) {
		return TaskActor->GetWorld();
	}
	return nullptr;
}

void UGameTask::CheckInit() {
	if (bInit) return;
	bInit = true;
}


