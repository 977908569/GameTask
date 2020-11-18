
#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameTaskNode.generated.h"

class UGameTaskCompositeNode;
class UGameTask;

/**
 * Task Node
 */
UCLASS(Abstract)
class GAMETASK_API UGameTaskNode : public UObject
{
	GENERATED_UCLASS_BODY()
public:
	/**
	 * Enter the node
	 */
	UFUNCTION(BlueprintCallable)
		virtual	void Enter();
	virtual void DoEnter();
	UFUNCTION(BlueprintImplementableEvent)
		void OnEnter();
	/**
	 * Exit the node
	 */
	UFUNCTION(BlueprintCallable)
		virtual void Exit();
	virtual  void DoExit();
	UFUNCTION(BlueprintImplementableEvent)
		void OnExit();


public:
	virtual UWorld* GetWorld() const override;


	virtual void InitializeFromAsset(UGameTask& Asset);
	virtual void InitializeNode(UGameTaskCompositeNode* InParentNode);

	/** @return parent node */
	UGameTaskCompositeNode* GetParentNode() const;

	/** @return name of node */
	FString GetNodeName() const;

	/** @return task asset */
	UGameTask* GetGameTaskAsset() const;

	/** @return string containing description of this node with all setup values */
	virtual FString GetStaticDescription() const;

#if WITH_EDITOR
	/** Get the name of the icon used to display this node in the editor */
	virtual FName GetNodeIconName() const;

	/** Get whether this node is using a blueprint for its logic */
	virtual bool UsesBlueprint() const;

	/** Called after creating new node in game task editor, use for versioning */
	virtual void OnNodeCreated() {}
#endif

	/** Gets called only for instanced nodes(bCreateNodeInstance == true). In practive overridden by BP-implemented game task nodes */
	virtual void SetOwner(AActor* ActorOwner) {}

	/** node name */
	UPROPERTY(Category = Description, EditAnywhere)
		FString NodeName;

private:

	/** source asset */
	UPROPERTY()
		UGameTask* GameTaskAsset;

	/** parent node */
	UPROPERTY()
		UGameTaskCompositeNode* ParentNode;
};

