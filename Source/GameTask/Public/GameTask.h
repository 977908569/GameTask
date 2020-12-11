#pragma once
#include "UObject/Object.h"
#include "GameTask.generated.h"

UCLASS(BlueprintType)
class GAMETASK_API UGameTask :public UObject
{
	GENERATED_BODY()
public:
	UGameTask();
	//Main Node
	UPROPERTY(BlueprintReadOnly)
		class UGameTaskComposite_Flow* RootNode;
	//Sub Nodes
	UPROPERTY(BlueprintReadOnly)
		TArray<UGameTaskComposite_Flow*> SubNodes;
public:
	//任务开始
	UFUNCTION(BlueprintCallable)
		void Start(class AGameTaskActor* InOwner);

	UFUNCTION(BlueprintCallable)
		AGameTaskActor* GetTaskActor() const;
	//查找节点
	UFUNCTION(BlueprintCallable)
		class UGameTaskNode* FindNode(int32 InID);

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly)
		FName Name;

	UPROPERTY(EditDefaultsOnly)
		FString Comment;

	UPROPERTY()
		class UEdGraph* TaskGraph = nullptr;

	UPROPERTY()
		TArray<FEditedDocumentInfo> LastEditedDocuments;
#endif

	UFUNCTION(BlueprintCallable)
		UWorld* GetWorld() const override;
protected:
	void CheckInit();

private:
	TArray<UGameTaskNode*> CachNodes;
	bool bInit = false;
	TWeakObjectPtr<AGameTaskActor> TaskActor;
};
