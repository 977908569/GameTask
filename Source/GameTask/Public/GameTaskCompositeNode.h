
#pragma once
#include "GameTaskNode.h"
#include "GameTaskCompositeNode.generated.h"

class UGameTask_Execute;
class UGameTaskCompositeNode;

USTRUCT()
struct GAMETASK_API FGameTaskCompositeChild
{
	GENERATED_USTRUCT_BODY()

		/** child node */
		UPROPERTY()
		UGameTaskCompositeNode* ChildComposite;

	UPROPERTY()
		UGameTask_Execute* ChildExecute;
};

UCLASS()
class GAMETASK_API UGameTaskCompositeNode : public UGameTaskNode
{
	GENERATED_UCLASS_BODY()

public:
	virtual ~UGameTaskCompositeNode();

	/** child nodes */
	UPROPERTY()
		TArray<FGameTaskCompositeChild> Children;

	/** @return child node at given index */
	UGameTaskNode* GetChildNode(int32 Index) const;
	virtual void DoEnter() override;

	/** @return children count */
	int32 GetChildrenNum() const;
	/**
	 * index of currently active child node
	 */
	int32 CurrentIndex;
};

