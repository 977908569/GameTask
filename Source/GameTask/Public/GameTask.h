#pragma once
#include "UObject/Object.h"
#include "GameTask.generated.h"

UCLASS(BlueprintType)
class GAMETASK_API UGameTask :public UObject
{
	GENERATED_BODY()

public:
	UGameTask();

	UPROPERTY()
		class UGameTaskCompositeNode* RootNode;

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

};
