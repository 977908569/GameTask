
#pragma once
#include "GameTaskNode.h"
#include "GameTaskExecuteNode.generated.h"


class UGameTaskEvent;
UCLASS()
class GAMETASK_API UGameTaskExecuteNode : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
		TArray<UGameTaskEvent*> Events;
	
};

