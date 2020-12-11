#pragma once
#include "GameTaskAuxiliaryNode.h"
#include "GameTaskEvent.generated.h"

/**
 * Task Event Node
 */
UCLASS(BlueprintType, Blueprintable)
class GAMETASK_API UGameTaskEvent :public UGameTaskAuxiliaryNode
{
	GENERATED_BODY()
public:
	UGameTaskEvent();
	virtual void Enter() override;
	UFUNCTION(BlueprintImplementableEvent)
		bool OnTrigger();

	virtual void SetNodeState(ENodeState InState) override;

	virtual FString GetStaticDescription() const override;
#if WITH_EDITOR
	virtual FName GetEnterIconName() const;
	virtual FName GetExitIconName() const;
#endif

};
