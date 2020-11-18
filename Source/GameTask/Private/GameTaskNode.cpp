#include "GameTaskNode.h"
#include "GameTaskTypes.h"

UGameTaskNode::UGameTaskNode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), GameTaskAsset(nullptr), ParentNode(nullptr) {
}

void UGameTaskNode::Enter() {
	DoEnter();
	OnEnter();
}

void UGameTaskNode::DoEnter() {
}

void UGameTaskNode::Exit() {
	DoExit();
	OnExit();
}

void UGameTaskNode::DoExit() {
}

UWorld* UGameTaskNode::GetWorld() const
{
	if (GetOuter() == nullptr)
	{
		return nullptr;
	}
	return GetOuter()->GetWorld();
}

void UGameTaskNode::InitializeFromAsset(UGameTask& Asset)
{
	GameTaskAsset = &Asset;
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
	return UGameTaskTypes::GetShortTypeName(this);
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

