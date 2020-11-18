#pragma once
#include "GameTaskCompositeNode.h"
#include "GameTaskComposite_Sequence.generated.h"

UCLASS()
class GAMETASK_API UGameTaskComposite_Sequence : public UGameTaskCompositeNode
{
	GENERATED_UCLASS_BODY()

#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif
};