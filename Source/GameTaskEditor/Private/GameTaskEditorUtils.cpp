#include "GameTaskEditorUtils.h"
#include "Node/GameTaskGraphNode_Composite.h"
#include "Node/GameTaskGraphNode_Execute.h"

TArray<UObject*> GameTaskEditorUtils::GetSelectionForPropertyEditor(const TSet<UObject*>& InSelection,
                                               FGameTaskPropertySelectionInfo& OutSelectionInfo)
{
	TArray<UObject*> Selection;

	for (UObject* SelectionEntry : InSelection)
	{
		UGameTaskGraphNode_Composite* GraphNode_Composite = Cast<UGameTaskGraphNode_Composite>(SelectionEntry);
		if (GraphNode_Composite)
		{
			Selection.Add(GraphNode_Composite->NodeInstance);
			continue;
		}

		UGameTaskGraphNode_Execute* GraphNode_Execute = Cast<UGameTaskGraphNode_Execute>(SelectionEntry);
		if (GraphNode_Execute)
		{
			Selection.Add(GraphNode_Execute->NodeInstance);
			continue;
		}

		UGameTaskGraphNode_Event* GraphNode_Event = Cast<UGameTaskGraphNode_Event>(SelectionEntry);
		if (GraphNode_Event)
		{
			Selection.Add(GraphNode_Event->NodeInstance);
			OutSelectionInfo.FoundEvent = Cast<UGameTaskEvent>(GraphNode_Event->NodeInstance);
			continue;
		}

		Selection.Add(SelectionEntry);
	}

	return Selection;
}
