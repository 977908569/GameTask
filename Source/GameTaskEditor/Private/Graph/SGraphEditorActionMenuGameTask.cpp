#include "SGraphEditorActionMenuGameTask.h"
#include "GameTaskEditorGraphSchema.h"
#include "Node/GameTaskGraphNode.h"

void SGraphEditorActionMenuGameTask::Construct(const FArguments& InArgs)
{
	this->GraphObj = InArgs._GraphObj;
	this->GraphNode = InArgs._GraphNode;
	this->DraggedFromPins = InArgs._DraggedFromPins;
	this->NewNodePosition = InArgs._NewNodePosition;
	this->OnClosedCallback = InArgs._OnClosedCallback;
	this->AutoExpandActionMenu = InArgs._AutoExpandActionMenu;
	this->SubNodeFlags = InArgs._SubNodeFlags;

	// Build the widget layout
	SBorder::Construct(SBorder::FArguments()
		.BorderImage(FEditorStyle::GetBrush("Menu.Background"))
		.Padding(5)
		[
			// Achieving fixed width by nesting items within a fixed width box.
			SNew(SBox)
			.WidthOverride(400)
		[
			SAssignNew(GraphActionMenu, SGraphActionMenu)
			.OnActionSelected(this, &SGraphEditorActionMenuGameTask::OnActionSelected)
		.OnCollectAllActions(this, &SGraphEditorActionMenuGameTask::CollectAllActions)
		.AutoExpandActionMenu(AutoExpandActionMenu)
		]
		]
	);
}

SGraphEditorActionMenuGameTask::~SGraphEditorActionMenuGameTask()
{
	OnClosedCallback.ExecuteIfBound();
}

TSharedRef<SEditableTextBox> SGraphEditorActionMenuGameTask::GetFilterTextBox()
{
	return GraphActionMenu->GetFilterTextBox();
}

void SGraphEditorActionMenuGameTask::OnActionSelected(const TArray<TSharedPtr<FEdGraphSchemaAction>>& SelectedAction,
	ESelectInfo::Type InSelectionType)
{
	if (InSelectionType == ESelectInfo::OnMouseClick || InSelectionType == ESelectInfo::OnKeyPress || SelectedAction.Num() == 0)
	{
		bool bDoDismissMenus = false;

		if (GraphObj)
		{
			for (int32 ActionIndex = 0; ActionIndex < SelectedAction.Num(); ActionIndex++)
			{
				TSharedPtr<FEdGraphSchemaAction> CurrentAction = SelectedAction[ActionIndex];

				if (CurrentAction.IsValid())
				{
					CurrentAction->PerformAction(GraphObj, DraggedFromPins, NewNodePosition);
					bDoDismissMenus = true;
				}
			}
		}

		if (bDoDismissMenus)
		{
			FSlateApplication::Get().DismissAllMenus();
		}
	}
}

void SGraphEditorActionMenuGameTask::CollectAllActions(FGraphActionListBuilderBase& OutAllActions)
{
	// Build up the context object
	FGraphContextMenuBuilder ContextMenuBuilder(GraphObj);
	if (GraphNode != nullptr)
	{
		ContextMenuBuilder.SelectedObjects.Add(GraphNode);
	}
	if (DraggedFromPins.Num() > 0)
	{
		ContextMenuBuilder.FromPin = DraggedFromPins[0];
	}

	// Determine all possible actions
	const UGameTaskEditorGraphSchemaBase* MySchema = Cast<const UGameTaskEditorGraphSchemaBase>(GraphObj->GetSchema());
	if (MySchema)
	{
		MySchema->GetGraphNodeContextActions(ContextMenuBuilder, SubNodeFlags);
	}

	// Copy the added options back to the main list
	//@TODO: Avoid this copy
	OutAllActions.Append(ContextMenuBuilder);
}
