#pragma once
#include "GameTaskEditorTypes.h"
#include "SGraphActionMenu.h"
class UGameTaskGraphNode;

class GAMETASKEDITOR_API SGraphEditorActionMenuGameTask : public SBorder
{
public:
	SLATE_BEGIN_ARGS(SGraphEditorActionMenuGameTask)
		: _GraphObj(static_cast<UEdGraph*>(nullptr))
		, _GraphNode(nullptr)
		, _NewNodePosition(FVector2D::ZeroVector)
		, _AutoExpandActionMenu(false)
		, _SubNodeFlags(EGameTaskSubNode::EnterEvent)
	{}

	SLATE_ARGUMENT(UEdGraph*, GraphObj)
		SLATE_ARGUMENT(UGameTaskGraphNode*, GraphNode)
		SLATE_ARGUMENT(FVector2D, NewNodePosition)
		SLATE_ARGUMENT(TArray<UEdGraphPin*>, DraggedFromPins)
		SLATE_ARGUMENT(SGraphEditor::FActionMenuClosed, OnClosedCallback)
		SLATE_ARGUMENT(bool, AutoExpandActionMenu)
		SLATE_ARGUMENT(EGameTaskSubNode, SubNodeFlags)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs);

	~SGraphEditorActionMenuGameTask();

	TSharedRef<SEditableTextBox> GetFilterTextBox();

protected:
	UEdGraph* GraphObj;
	UGameTaskGraphNode* GraphNode;
	TArray<UEdGraphPin*> DraggedFromPins;
	FVector2D NewNodePosition;
	bool AutoExpandActionMenu;
	EGameTaskSubNode SubNodeFlags;

	SGraphEditor::FActionMenuClosed OnClosedCallback;
	TSharedPtr<SGraphActionMenu> GraphActionMenu;

	void OnActionSelected(const TArray< TSharedPtr<FEdGraphSchemaAction> >& SelectedAction, ESelectInfo::Type InSelectionType);

	/** Callback used to populate all actions list in SGraphActionMenu */
	void CollectAllActions(FGraphActionListBuilderBase& OutAllActions);
};
