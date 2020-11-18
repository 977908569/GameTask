#pragma once
#include "GameTaskAuxiliaryNode.h"
#include "GameTaskEvent.generated.h"

/**
 * Task Event Node
 */
UCLASS(BlueprintType)
class GAMETASK_API UGameTaskEvent :public UGameTaskAuxiliaryNode
{
	GENERATED_BODY()

public:
	UGameTaskEvent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bTest;

	virtual FString GetStaticDescription() const override;

#if WITH_EDITOR

	virtual FName GetNodeIconName() const override;
#endif

};
