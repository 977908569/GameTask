#include "SGraphNode_Event.h"
#include "GameTaskEvent.h"
#include "Node/GameTaskGraphNode_Event.h"

void SGraphNode_Event::Construct(const FArguments& InArgs, UGameTaskGraphNode_Event* InNode)
{
	this->GraphNode = InNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
}

FString SGraphNode_Event::GetNodeComment() const
{
	const UGameTaskGraphNode_Event* MyGraphNode = Cast<const UGameTaskGraphNode_Event>(GetNodeObj());
	const UGameTaskEvent* MyNode = MyGraphNode ? Cast<const UGameTaskEvent>(MyGraphNode->NodeInstance) : NULL;

	if (MyNode)
	{
		return MyNode->GetNodeName();
	}

	return SGraphNode::GetNodeComment();
}
