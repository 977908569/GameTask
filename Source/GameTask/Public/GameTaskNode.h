
#pragma once
#include "CoreMinimal.h"

#include "GameTaskTypes.h"
#include "UObject/Object.h"
#include "GameTaskNode.generated.h"

class UGameTaskCompositeNode;
class UGameTask;

/**
 * Task Node
 */
UCLASS(BlueprintType, Abstract)
class GAMETASK_API UGameTaskNode : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly)
		int32 ID;
	UPROPERTY(BlueprintReadOnly)
		TArray<UGameTaskNode*> Children;
public:
	virtual UWorld* GetWorld() const override;
	virtual void InitializeFromAsset(UGameTask& Asset);
	virtual void InitializeNode(UGameTaskNode* InParentNode);
	UGameTaskNode* GetParentNode() const;
	FString GetNodeName() const;
	UGameTask* GetGameTaskAsset() const;
	virtual FString GetStaticDescription() const;

	virtual void SetNodeState(ENodeState InState);
	ENodeState GetNodeState() const;
	virtual void CheckNodeState();
	virtual void Enter();

#if WITH_EDITOR
	virtual FName GetNodeIconName() const;
	virtual bool UsesBlueprint() const;
	virtual void OnNodeCreated() {}
	virtual void UpdateData() {}
#endif

	virtual void SetOwner(AActor* ActorOwner) {}
	UPROPERTY(Category = Description, EditAnywhere)
		FString NodeName;
protected:
	UPROPERTY()
		UGameTask* GameTaskAsset;
	UPROPERTY()
		UGameTaskNode* ParentNode;
	//当前节点的执行状态
	ENodeState NodeState;
};

