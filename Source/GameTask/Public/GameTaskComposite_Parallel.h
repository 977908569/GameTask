#pragma once
#include "GameTaskNode.h"
#include "GameTaskComposite_Parallel.generated.h"
/**
 * 任务条目并行
 */
UCLASS()
class GAMETASK_API UGameTaskComposite_Parallel : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()

		virtual FString GetStaticDescription() const override;
	virtual void Enter() override;
	virtual void CheckNodeState() override;

#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR
};