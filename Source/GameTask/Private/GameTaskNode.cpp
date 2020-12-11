#include "GameTaskNode.h"
#include "GameTask.h"
#include "GameTaskComposite_Sequence.h"
#include "GameTaskTypes.h"

UGameTaskNode::UGameTaskNode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer), ID(0), GameTaskAsset(nullptr),
	ParentNode(nullptr) {
}

UWorld* UGameTaskNode::GetWorld() const
{
	if (GameTaskAsset) return GameTaskAsset->GetWorld();
	return nullptr;
}

void UGameTaskNode::InitializeFromAsset(UGameTask& Asset)
{
	GameTaskAsset = &Asset;
}

void UGameTaskNode::InitializeNode(UGameTaskNode* InParentNode)
{
	ParentNode = InParentNode;
}

UGameTaskNode* UGameTaskNode::GetParentNode() const
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

void UGameTaskNode::SetNodeState(const ENodeState InState) {
	NodeState = InState;
	if (NodeState == ENodeState::Succeeded) {
		if (auto Parent = GetParentNode()) {
			Parent->CheckNodeState();
		}
	}
}

ENodeState UGameTaskNode::GetNodeState() const {
	return  NodeState;
}

void UGameTaskNode::CheckNodeState() {
}

void UGameTaskNode::Enter() {
	SetNodeState(ENodeState::InProgress);
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

