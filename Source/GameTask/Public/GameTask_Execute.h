#pragma once
#include "GameTaskEvent.h"
#include "GameTaskNode.h"
#include "GameTask_Execute.generated.h"
/**
 * 任务条目状态
 */
UENUM(BlueprintType)
enum class EItemState :uint8 {
	Disable			UMETA(DisplayName = "未激活"),
	Progress		UMETA(DisplayName = "进行中"),
	Finish			UMETA(DisplayName = "已完成"),
	Fail			UMETA(DisplayName = "失败"),
};

/**
 * 具体执行节点
 */
UCLASS(BlueprintType, Blueprintable)
class GAMETASK_API UGameTask_Execute : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "任务描述Key"))
		FString I18Key;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (DisplayName = "倒计时 单位秒，为-1表示不限时"))
		float CountDown = -1.0f;
	//
	UPROPERTY()
		TArray<UGameTaskEvent*> ActiveEvents;
	UPROPERTY()
		TArray<UGameTaskEvent*> FinishEvents;
public:
	virtual void Enter() override;

	UFUNCTION(BlueprintCallable)
		virtual void Active();
	UFUNCTION(BlueprintImplementableEvent)
		void OnActive();
	UFUNCTION(BlueprintCallable)
		virtual void Disable();
	UFUNCTION(BlueprintImplementableEvent)
		void OnDisable();
	UFUNCTION(BlueprintCallable)
		virtual void Finish();
	UFUNCTION(BlueprintImplementableEvent)
		void OnFinish();
	UFUNCTION(BlueprintCallable)
		void Fail();
	UFUNCTION(BlueprintImplementableEvent)
		void OnFail();

	//设置当前的状态
	UFUNCTION(BlueprintCallable)
		void SetItemState(EItemState InState);
	UFUNCTION(BlueprintCallable)
		EItemState GetItemState() const;

#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR

private:
	//当前状态
	UPROPERTY(Transient)
		EItemState ItemState = EItemState::Disable;
};
