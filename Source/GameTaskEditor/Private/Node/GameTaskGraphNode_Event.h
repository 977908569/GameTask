#pragma once
#include "GameTaskGraphNode.h"
#include "GameTaskGraphNode_Event.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode_Event : public UGameTaskGraphNode
{
	GENERATED_UCLASS_BODY()
		virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual void AllocateDefaultPins() override;
	void CollectEventData(TArray<class UGameTaskEvent*>& NodeInstances) const;
	virtual FName GetNameIcon() const override;

	//标记是进入还是退出事件
	UPROPERTY()
		bool bEnterEvent = true;
};