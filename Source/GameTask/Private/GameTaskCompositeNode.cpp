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

void UGameTaskCompositeNode::DoEnter() {
	CurrentIndex = 0;
	if (UGameTaskNode* FindNode = GetChildNode(CurrentIndex)) {
		FindNode->Enter();
		CurrentIndex++;
	}
	else {
		Exit();
	}
}

int32 UGameTaskCompositeNode::GetChildrenNum() const
{
	return Children.Num();
}
