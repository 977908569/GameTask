#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "SGraphNode.h"
class UGameTaskGraphNode_Event;

class SGraphNode_Event : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SGraphNode_Event) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, UGameTaskGraphNode_Event* InNode);

	virtual FString GetNodeComment() const override;
};
