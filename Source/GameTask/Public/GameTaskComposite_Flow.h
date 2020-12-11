#pragma once
#include "GameTaskNode.h"
#include "GameTaskComposite_Flow.generated.h"

UCLASS(BlueprintType)
class GAMETASK_API UGameTaskComposite_Flow : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()
		UPROPERTY(BlueprintReadOnly)
		TArray<class UGameTaskEvent*> EnterEvents;
	UPROPERTY(BlueprintReadOnly)
		TArray<class UGameTaskEvent*> ExitEvents;
	UPROPERTY(BlueprintReadOnly)
		UGameTaskComposite_Flow* Next;
public:
	//进入节点
	UFUNCTION(BlueprintCallable)
		virtual void Enter() override;
	UFUNCTION(BlueprintImplementableEvent)
		void OnEnter();
	//退出节点
	UFUNCTION(BlueprintCallable)
		virtual void Exit();
	UFUNCTION(BlueprintImplementableEvent)
		void OnExit();

	virtual void CheckNodeState() override;

	virtual FString GetStaticDescription() const override;
#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR
};