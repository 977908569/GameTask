#pragma once
#include "GameTaskNode.h"
#include "GameTaskComposite_Sequence.generated.h"

UCLASS()
class GAMETASK_API UGameTaskComposite_Sequence : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()
public:
	virtual void Enter() override;
	bool Next();
	virtual void CheckNodeState() override;

	UGameTaskNode* GetChild(int32 ChildIdx);
#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif
private:
	int32 CurrentIndex = -1;
};