#include "GameTaskNode.h"

UGameTaskNode::UGameTaskNode(const FObjectInitializer& ObjectInitializer)
  : Super(ObjectInitializer), GameTaskAsset(nullptr), ParentNode(nullptr) {
}

UWorld* UGameTaskNode::GetWorld() const
{
	if (GetOuter() == nullptr)
	{
		return nullptr;
	}
	return GetOuter()->GetWorld();
}

void UGameTaskNode::InitializeNode(UGameTaskCompositeNode* InParentNode)
{
	ParentNode = InParentNode;
}

UGameTaskCompositeNode* UGameTaskNode::GetParentNode() const
{
	return ParentNode;
}

FString UGameTaskNode::GetNodeName() const
{
	return NodeName.Len() ? NodeName : TEXT("");
}

UGameTask* UGameTaskNode::GetGameTaskAsset() const
{
	return GameTaskAsset;
}

FString UGameTaskNode::GetStaticDescription() const
{
	return TEXT("");
}

#if WITH_EDITOR
FName UGameTaskNode::GetNodeIconName() const
{
	return NAME_None;
}

bool UGameTaskNode::UsesBlueprint() const
{
	return false;
}

#endif

