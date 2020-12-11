#include "GameTaskActor.h"
#include "GameTask.h"
#include "Kismet/KismetSystemLibrary.h"

AGameTaskActor::AGameTaskActor() {
	bReplicates = true;
}

void AGameTaskActor::DoTask(const FString& InPath) {
	//
	const auto SoftPath = UKismetSystemLibrary::MakeSoftObjectPath(InPath);
	UGameTask* GameTask = Cast<UGameTask>(SoftPath.TryLoad());
	if (GameTask) {
		GameTask->Start(this);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Load Game Task Error %s"), *InPath);
	}
}
