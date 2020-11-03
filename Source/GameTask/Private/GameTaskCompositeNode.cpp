#include "GameTaskCompositeNode.h"

UGameTaskCompositeNode::UGameTaskCompositeNode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "UnknownComposite";
}

UGameTaskCompositeNode::~UGameTaskCompositeNode()
{
}

UGameTaskNode* UGameTaskCompositeNode::GetChildNode(int32 Index) const
{
	return Children.IsValidIndex(Index) ?
		(Children[Index].ChildComposite ?
			(UGameTaskNode*)Children[Index].ChildComposite :
			(UGameTaskNode*)Children[Index].ChildExecute) :
		nullptr;
}

int32 UGameTaskCompositeNode::GetChildrenNum() const
{
	return Children.Num();
}
