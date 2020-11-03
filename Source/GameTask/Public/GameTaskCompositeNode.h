
#pragma once
#include "GameTaskNode.h"
#include "GameTaskCompositeNode.generated.h"

class UGameTaskEvent;
class UGameTaskExecuteNode;
class UGameTaskCompositeNode;
USTRUCT()
struct FGameTaskCompositeChild
{
	GENERATED_USTRUCT_BODY()

		/** child node */
		UPROPERTY()
		UGameTaskCompositeNode* ChildComposite;

	UPROPERTY()
		UGameTaskExecuteNode* ChildExecute;

	UPROPERTY()
		TArray<UGameTaskEvent*> Events;
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

	UPROPERTY()
		TArray<class UGameTaskEvent*> Events;

	/** @return child node at given index */
	UGameTaskNode* GetChildNode(int32 Index) const;

	/** @return children count */
	int32 GetChildrenNum() const;
};

