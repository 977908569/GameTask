#pragma once
#include "GameTaskEvent.h"
#include "GameTaskNode.h"
#include "GameTask_Execute.generated.h"

UCLASS()
class GAMETASK_API UGameTask_Execute : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()
	/**
	 * Active Events
	 */
	UPROPERTY()
		TArray<UGameTaskEvent*> Events;

	
#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR
};
