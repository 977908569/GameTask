#pragma once
#include "GameTaskEditorTypes.generated.h"

struct FGameTaskCompareNodeXLocation
{
	FORCEINLINE bool operator()(const UEdGraphPin& A, const UEdGraphPin& B) const
	{
		const UEdGraphNode* NodeA = A.GetOwningNode();
		const UEdGraphNode* NodeB = B.GetOwningNode();

		if (NodeA->NodePosX == NodeB->NodePosX)
		{
			return NodeA->NodePosY < NodeB->NodePosY;
		}

		return NodeA->NodePosX < NodeB->NodePosX;
	}
};


enum  class EGameTaskSubNode : uint8 {
	Event,
	Condition
};


struct FGameTaskNodeBounds
{
	FVector2D Position;
	FVector2D Size;

	FGameTaskNodeBounds(FVector2D InPos, FVector2D InSize)
	{
		Position = InPos;
		Size = InSize;
	}
};

UCLASS()
class UGameTaskEditorTypes : public UObject
{
	GENERATED_UCLASS_BODY()
		static const FName PinCategory_SingleFlow;

	static const FName PinCategory_CompositeOrExecute;
	static const FName PinCategory_MultipleNodes;
	static const FName PinCategory_SingleComposite;
	static const FName PinCategory_SingleExecute;
	static const FName PinCategory_OnlyShow;
	
};