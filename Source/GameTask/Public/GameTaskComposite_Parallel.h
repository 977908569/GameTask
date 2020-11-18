#pragma once
#include "GameTaskCompositeNode.h"
#include "GameTaskComposite_Parallel.generated.h"

UCLASS(HideCategories = (Composite))
class GAMETASK_API UGameTaskComposite_Parallel : public UGameTaskCompositeNode
{
	GENERATED_UCLASS_BODY()

	virtual FString GetStaticDescription() const override;
	
#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR
};