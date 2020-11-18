#pragma once
#include "GameTaskCompositeNode.h"
#include "GameTaskComposite_Flow.generated.h"

/**
 * Flow
 */
UCLASS()
class GAMETASK_API UGameTaskComposite_Flow : public UGameTaskCompositeNode
{
	GENERATED_UCLASS_BODY()
		/**
		 * Enter Node Events
		 */
		UPROPERTY(BlueprintReadOnly)
		TArray<class UGameTaskEvent*> EnterEvents;
	/**
	 * Exit Node Event
	 */
	UPROPERTY(BlueprintReadOnly)
		TArray<class UGameTaskEvent*> ExitEvents;

	UPROPERTY()
		UGameTaskComposite_Flow* Next;
public:
	virtual void DoEnter() override;
	virtual void DoExit() override;

	virtual FString GetStaticDescription() const override;
#if WITH_EDITOR
	virtual FName GetNodeIconName() const override;
#endif // WITH_EDITOR
};