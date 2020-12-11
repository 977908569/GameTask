#include "GameTaskComposite_Sequence.h"

UGameTaskComposite_Sequence::UGameTaskComposite_Sequence(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	NodeName = "Sequence";
}

void UGameTaskComposite_Sequence::Enter() {
	CurrentIndex = -1;
	Next();
	Super::Enter();
}

bool UGameTaskComposite_Sequence::Next() {
	CurrentIndex++;
	auto Child = GetChild(CurrentIndex);
	if (Child) {
		Child->Enter();
		return true;
	}
	return false;
}

void UGameTaskComposite_Sequence::CheckNodeState() {
	if (!Next()) {
		SetNodeState(ENodeState::Succeeded);
	}
}

UGameTaskNode* UGameTaskComposite_Sequence::GetChild(const int32 ChildIdx) {
	if (Children.IsValidIndex(ChildIdx)) return Children[ChildIdx];
	return nullptr;
}

#if WITH_EDITOR
FName UGameTaskComposite_Sequence::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.Sequence.Icon");
}
#endif

