#include "GameTaskEditorUtils.h"
#include "Node/GameTaskGraphNode_Execute.h"

TArray<UObject*> GameTaskEditorUtils::GetSelectionForPropertyEditor(const TSet<UObject*>& InSelection,
	FGameTaskPropertySelectionInfo& OutSelectionInfo)
{
	TArray<UObject*> Selection;

	for (UObject* SelectionEntry : InSelection)
	{
		if (UGameTaskGraphNode_Event* GraphNode_Event = Cast<UGameTaskGraphNode_Event>(SelectionEntry))
		{
			Selection.Add(GraphNode_Event->NodeInstance);
			OutSelectionInfo.FoundEvent = Cast<UGameTaskEvent>(GraphNode_Event->NodeInstance);
			continue;
		}
		else {
			if (UGameTaskGraphNode* GraphNode = Cast<UGameTaskGraphNode>(SelectionEntry))
			{
				Selection.Add(GraphNode->NodeInstance);
				continue;
			}
		}

		Selection.Add(SelectionEntry);
	}

	return Selection;
}
