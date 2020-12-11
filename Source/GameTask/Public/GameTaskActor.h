#pragma once
#include "GameTaskActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class GAMETASK_API AGameTaskActor :public AActor
{
	GENERATED_BODY()
public:
	AGameTaskActor();

	UFUNCTION(BlueprintCallable)
		void DoTask(const FString& InPath);
};
