#include "SGraphNodeGameTaskBase.h"

#include "SGraphNode_GameTask.h"
#include "SGraphPanel.h"
#include "Node/GameTaskGraphNode.h"
#include "Node/GameTaskGraphNode_Execute.h"
#include "Node/GameTaskGraphNode_Flow.h"
#define LOCTEXT_NAMESPACE "GameTask"

TSharedRef<FDragGameTaskGraphNode> FDragGameTaskGraphNode::New(const TSharedRef<SGraphPanel>& InGraphPanel,
	const TSharedRef<SGraphNode>& InDraggedNode)
{
	TSharedRef<FDragGameTaskGraphNode> Operation = MakeShareable(new FDragGameTaskGraphNode);
	Operation->StartTime = FPlatformTime::Seconds();
	Operation->GraphPanel = InGraphPanel;
	Operation->DraggedNodes.Add(InDraggedNode);
	Operation->DecoratorAdjust = FSlateApplication::Get().GetCursorSize();
	Operation->Construct();
	return Operation;
}

TSharedRef<FDragGameTaskGraphNode> FDragGameTaskGraphNode::New(const TSharedRef<SGraphPanel>& InGraphPanel,
	const TArray<TSharedRef<SGraphNode>>& InDraggedNodes)
{
	TSharedRef<FDragGameTaskGraphNode> Operation = MakeShareable(new FDragGameTaskGraphNode);
	Operation->StartTime = FPlatformTime::Seconds();
	Operation->GraphPanel = InGraphPanel;
	Operation->DraggedNodes = InDraggedNodes;
	Operation->DecoratorAdjust = FSlateApplication::Get().GetCursorSize();
	Operation->Construct();
	return Operation;
}

UGameTaskGraphNode* FDragGameTaskGraphNode::GetDropTargetNode() const
{
	return Cast<UGameTaskGraphNode>(GetHoveredNode());
}
//===============================
void SGraphNodeGameTaskBase::Construct(const FArguments& InArgs, UGameTaskGraphNode* InNode)
{
	SetCursor(EMouseCursor::CardinalCross);

	GraphNode = InNode;
	UpdateGraphNode();

	bDragMarkerVisible = false;
}

TSharedPtr<SToolTip> SGraphNodeGameTaskBase::GetComplexTooltip()
{
	return nullptr;
}

void SGraphNodeGameTaskBase::OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	// Is someone dragging a node?
	TSharedPtr<FDragNode> DragConnectionOp = DragDropEvent.GetOperationAs<FDragNode>();
	if (DragConnectionOp.IsValid())
	{
		// Inform the Drag and Drop operation that we are hovering over this node.
		TSharedPtr<SGraphNode> SubNode = GetSubNodeUnderCursor(MyGeometry, DragDropEvent);
		DragConnectionOp->SetHoveredNode(SubNode.IsValid() ? SubNode : SharedThis(this));

		UGameTaskGraphNode* TestNode = Cast<UGameTaskGraphNode>(GraphNode);
		if (DragConnectionOp->IsValidOperation() && TestNode && TestNode->IsSubNode())
		{
			SetDragMarker(true);
		}
	}

	SGraphNode::OnDragEnter(MyGeometry, DragDropEvent);
}

FReply SGraphNodeGameTaskBase::OnDragOver(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	// Is someone dragging a node?
	TSharedPtr<FDragNode> DragConnectionOp = DragDropEvent.GetOperationAs<FDragNode>();
	if (DragConnectionOp.IsValid())
	{
		// Inform the Drag and Drop operation that we are hovering over this node.
		TSharedPtr<SGraphNode> SubNode = GetSubNodeUnderCursor(MyGeometry, DragDropEvent);
		DragConnectionOp->SetHoveredNode(SubNode.IsValid() ? SubNode : SharedThis(this));
	}
	return SGraphNode::OnDragOver(MyGeometry, DragDropEvent);
}

FReply SGraphNodeGameTaskBase::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	SetDragMarker(false);

	TSharedPtr<FDragGameTaskGraphNode> DragNodeOp = DragDropEvent.GetOperationAs<FDragGameTaskGraphNode>();
	if (DragNodeOp.IsValid())
	{
		if (!DragNodeOp->IsValidOperation())
		{
			return FReply::Handled();
		}

		const float DragTime = float(FPlatformTime::Seconds() - DragNodeOp->StartTime);
		if (DragTime < 0.5f)
		{
			return FReply::Handled();
		}

		UGameTaskGraphNode* MyNode = Cast<UGameTaskGraphNode>(GraphNode);
		if (MyNode == nullptr || MyNode->IsSubNode())
		{
			return FReply::Unhandled();
		}

		const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_DragDropNode", "Drag&Drop Node"));
		bool bReorderOperation = true;

		const TArray< TSharedRef<SGraphNode> >& DraggedNodes = DragNodeOp->GetNodes();
		for (int32 Idx = 0; Idx < DraggedNodes.Num(); Idx++)
		{
			UGameTaskGraphNode* DraggedNode = Cast<UGameTaskGraphNode>(DraggedNodes[Idx]->GetNodeObj());
			if (DraggedNode && DraggedNode->ParentNode)
			{
				if (DraggedNode->ParentNode != GraphNode)
				{
					bReorderOperation = false;
				}

				DraggedNode->ParentNode->RemoveSubNode(DraggedNode);
			}
		}

		UGameTaskGraphNode* DropTargetNode = DragNodeOp->GetDropTargetNode();

		const int32 InsertIndex = MyNode->FindSubNodeDropIndex(DropTargetNode);

		for (int32 Idx = 0; Idx < DraggedNodes.Num(); Idx++)
		{
			UGameTaskGraphNode_Event* DraggedTestNode = Cast<UGameTaskGraphNode_Event>(DraggedNodes[Idx]->GetNodeObj());
			DraggedTestNode->Modify();
			DraggedTestNode->ParentNode = MyNode;
			DraggedTestNode->bEnterEvent = MyNode->bDragEnter;

			MyNode->Modify();
			MyNode->InsertSubNodeAt(DraggedTestNode, InsertIndex);
		}

		if (bReorderOperation)
		{
			UpdateGraphNode();
		}
		else
		{
			UGameTaskGraph* MyGraph = MyNode->GetGameTaskGraph();
			if (MyGraph)
			{
				MyGraph->OnSubNodeDropped();
			}
		}
		//Reset
		MyNode->bDragEnter = true;
	}

	return SGraphNode::OnDrop(MyGeometry, DragDropEvent);
}

void SGraphNodeGameTaskBase::OnDragLeave(const FDragDropEvent& DragDropEvent)
{
	TSharedPtr<FDragNode> DragConnectionOp = DragDropEvent.GetOperationAs<FDragNode>();
	if (DragConnectionOp.IsValid())
	{
		// Inform the Drag and Drop operation that we are not hovering any pins
		DragConnectionOp->SetHoveredNode(TSharedPtr<SGraphNode>(NULL));
	}

	SetDragMarker(false);
	SGraphNode::OnDragLeave(DragDropEvent);
}

FReply SGraphNodeGameTaskBase::OnMouseMove(const FGeometry& SenderGeometry, const FPointerEvent& MouseEvent)
{
	if (MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && !(GEditor->bIsSimulatingInEditor || GEditor->PlayWorld))
	{
		//if we are holding mouse over a subnode
		UGameTaskGraphNode* TestNode = Cast<UGameTaskGraphNode>(GraphNode);
		if (TestNode && TestNode->IsSubNode())
		{
			const TSharedRef<SGraphPanel>& Panel = GetOwnerPanel().ToSharedRef();
			const TSharedRef<SGraphNode>& Node = SharedThis(this);
			return FReply::Handled().BeginDragDrop(FDragGameTaskGraphNode::New(Panel, Node));
		}
	}

	if (!MouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton) && bDragMarkerVisible)
	{
		SetDragMarker(false);
	}

	return FReply::Unhandled();
}

void SGraphNodeGameTaskBase::SetOwner(const TSharedRef<SGraphPanel>& OwnerPanel)
{
	SGraphNode::SetOwner(OwnerPanel);

	for (auto& ChildWidget : SubNodes)
	{
		if (ChildWidget.IsValid())
		{
			ChildWidget->SetOwner(OwnerPanel);
			OwnerPanel->AttachGraphEvents(ChildWidget);
		}
	}
}

void SGraphNodeGameTaskBase::AddPin(const TSharedRef<SGraphPin>& PinToAdd)
{
	PinToAdd->SetOwner(SharedThis(this));

	const UEdGraphPin* PinObj = PinToAdd->GetPinObj();
	const bool bAdvancedParameter = PinObj && PinObj->bAdvancedView;
	if (bAdvancedParameter)
	{
		PinToAdd->SetVisibility(TAttribute<EVisibility>(PinToAdd, &SGraphPin::IsPinVisibleAsAdvanced));
	}

	if (PinToAdd->GetDirection() == EEdGraphPinDirection::EGPD_Input)
	{
		LeftNodeBox->AddSlot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.FillHeight(1.0f)
			[
				PinToAdd
			];
		InputPins.Add(PinToAdd);
	}
	else // Direction == EEdGraphPinDirection::EGPD_Output
	{
		RightNodeBox->AddSlot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.FillHeight(1.0f)
			[
				PinToAdd
			];
		OutputPins.Add(PinToAdd);
	}
}

FReply SGraphNodeGameTaskBase::OnMouseDown(const FGeometry& SenderGeometry, const FPointerEvent& MouseEvent)
{
	UGameTaskGraphNode* TestNode = Cast<UGameTaskGraphNode>(GraphNode);
	if (TestNode && TestNode->IsSubNode())
	{
		GetOwnerPanel()->SelectionManager.ClickedOnNode(GraphNode, MouseEvent);
		return FReply::Handled();
	}

	return FReply::Unhandled();
}

void SGraphNodeGameTaskBase::AddSubNode(TSharedPtr<SGraphNode> SubNodeWidget)
{
	SubNodes.Add(SubNodeWidget);
}

TSharedPtr<SGraphNode> SGraphNodeGameTaskBase::GetSubNodeUnderCursor(const FGeometry& WidgetGeometry,
	const FPointerEvent& MouseEvent)
{
	TSharedPtr<SGraphNode> ResultNode;

	// We just need to find the one WidgetToFind among our descendants.
	TSet< TSharedRef<SWidget> > SubWidgetsSet;
	for (int32 i = 0; i < SubNodes.Num(); i++)
	{
		SubWidgetsSet.Add(SubNodes[i].ToSharedRef());
	}

	TMap<TSharedRef<SWidget>, FArrangedWidget> Result;
	FindChildGeometries(WidgetGeometry, SubWidgetsSet, Result);

	if (Result.Num() > 0)
	{
		FArrangedChildren ArrangedChildren(EVisibility::Visible);
		Result.GenerateValueArray(ArrangedChildren.GetInternalArray());

		const int32 HoveredIndex = SWidget::FindChildUnderMouse(ArrangedChildren, MouseEvent);
		if (HoveredIndex != INDEX_NONE)
		{
			ResultNode = StaticCastSharedRef<SGraphNode>(ArrangedChildren[HoveredIndex].Widget);
		}
	}

	return ResultNode;
}

EVisibility SGraphNodeGameTaskBase::GetDragOverMarkerVisibility() const
{
	return bDragMarkerVisible ? EVisibility::Visible : EVisibility::Collapsed;
}

void SGraphNodeGameTaskBase::SetDragMarker(bool bEnabled)
{
	bDragMarkerVisible = bEnabled;
}

FText SGraphNodeGameTaskBase::GetDescription() const
{
	UGameTaskGraphNode* MyNode = CastChecked<UGameTaskGraphNode>(GraphNode);
	return MyNode ? MyNode->GetDescription() : FText::GetEmpty();
}

EVisibility SGraphNodeGameTaskBase::GetDescriptionVisibility() const
{
	// LOD this out once things get too small
	TSharedPtr<SGraphPanel> MyOwnerPanel = GetOwnerPanel();
	return (!MyOwnerPanel.IsValid() || MyOwnerPanel->GetCurrentLOD() > EGraphRenderingLOD::LowDetail) ? EVisibility::Visible : EVisibility::Collapsed;
}

EVisibility SGraphNodeGameTaskBase::GetEventVisibility() const
{
	if (GraphNode && (GraphNode->IsA(UGameTaskGraphNode_Flow::StaticClass()) || GraphNode->IsA(UGameTaskGraphNode_Execute::StaticClass())))
	{
		return EVisibility::SelfHitTestInvisible;
	}
	return EVisibility::Collapsed;
}

FText SGraphNodeGameTaskBase::GetPreviewCornerText() const
{
	return FText::GetEmpty();
}

const FSlateBrush* SGraphNodeGameTaskBase::GetNameIcon() const
{
	return FEditorStyle::GetBrush(TEXT("Graph.StateNode.Icon"));
}
//========================Pin================
void SGraphPinGameTask::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	this->SetCursor(EMouseCursor::Default);

	bShowLabel = true;

	GraphPinObj = InPin;
	check(GraphPinObj != nullptr);

	const UEdGraphSchema* Schema = GraphPinObj->GetSchema();
	check(Schema);

	SBorder::Construct(SBorder::FArguments()
		.BorderImage(this, &SGraphPinGameTask::GetPinBorder)
		.BorderBackgroundColor(this, &SGraphPinGameTask::GetPinColor)
		.OnMouseButtonDown(this, &SGraphPinGameTask::OnPinMouseDown)
		.Cursor(this, &SGraphPinGameTask::GetPinCursor)
		.Padding(FMargin(10.0f))
	);
}

FSlateColor SGraphPinGameTask::GetPinColor() const
{
	return FSlateColor(IsHovered() ? FLinearColor::Yellow : FLinearColor::Black);
}

TSharedRef<SWidget> SGraphPinGameTask::GetDefaultValueWidget()
{
	return SNew(STextBlock);
}

const FSlateBrush* SGraphPinGameTask::GetPinBorder() const
{
	return FEditorStyle::GetBrush(TEXT("Graph.StateNode.Body"));
}

#undef LOCTEXT_NAMESPACE
