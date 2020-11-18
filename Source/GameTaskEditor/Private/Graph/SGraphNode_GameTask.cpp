#include "SGraphNode_GameTask.h"
#include "GameTaskColor.h"
#include "GameTaskCompositeNode.h"
#include "GameTaskNode.h"
#include "GraphEditorSettings.h"
#include "IDocumentation.h"
#include "NodeFactory.h"
#include "SCommentBubble.h"
#include "SGraphPanel.h"
#include "Node/GameTaskGraphNode.h"
#include "Node/GameTaskGraphNode_Event.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"
#include "SLevelOfDetailBranchNode.h"
#include "Debug/GameTaskDebugger.h"
#include "Node/GameTaskGraphNode_Composite.h"
#include "Node/GameTaskGraphNode_Execute.h"
#include "Node/GameTaskGraphNode_Flow.h"
#include "Node/GameTaskGraphNode_Root.h"

#define LOCTEXT_NAMESPACE "GameTask"
namespace
{
	static const bool bShowExecutionIndexInEditorMode = true;
}


class SGameTaskPin : public SGraphPinGameTask
{
public:
	SLATE_BEGIN_ARGS(SGameTaskPin) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, UEdGraphPin* InPin);
protected:
	/** @return The color that we should use to draw this pin */
	virtual FSlateColor GetPinColor() const override;
	virtual void OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	virtual void OnDragLeave(const FDragDropEvent& DragDropEvent) override;
};

void SGameTaskPin::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	SGraphPinGameTask::Construct(SGraphPinGameTask::FArguments(), InPin);
}

FSlateColor SGameTaskPin::GetPinColor() const
{
	return
		GraphPinObj->bIsDiffing ? GameTaskColors::Pin::Diff :
		IsHovered() ? GameTaskColors::Pin::Hover :
		(GraphPinObj->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleComposite) ? GameTaskColors::Pin::CompositeOnly :
		(GraphPinObj->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleExecute) ? GameTaskColors::Pin::TaskOnly :
		(GraphPinObj->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleFlow) ? GameTaskColors::Pin::SingleNode :
		GameTaskColors::Pin::Default;
}

void SGameTaskPin::OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
	SGraphPinGameTask::OnDragEnter(MyGeometry, DragDropEvent);
	const EEdGraphPinDirection DragDir = GetDirection();
	if (const auto MyNode = Cast<UGameTaskGraphNode>(GraphPinObj->GetOwningNode()))
	{
		MyNode->bDragEnter = DragDir == EEdGraphPinDirection::EGPD_Input;
	}
}

void SGameTaskPin::OnDragLeave(const FDragDropEvent& DragDropEvent)
{
	SGraphPinGameTask::OnDragLeave(DragDropEvent);
	if (const auto MyNode = Cast<UGameTaskGraphNode>(GraphPinObj->GetOwningNode()))
	{
		MyNode->bDragEnter = true;
	}
}


class SGameTaskIndex : public SCompoundWidget
{
public:
	/** Delegate event fired when the hover state of this widget changes */
	DECLARE_DELEGATE_OneParam(FOnHoverStateChanged, bool /* bHovered */);

	/** Delegate used to receive the color of the node, depending on hover state and state of other siblings */
	DECLARE_DELEGATE_RetVal_OneParam(FSlateColor, FOnGetIndexColor, bool /* bHovered */);

	SLATE_BEGIN_ARGS(SGameTaskIndex) {}
	SLATE_ATTRIBUTE(FText, Text)
		SLATE_EVENT(FOnHoverStateChanged, OnHoverStateChanged)
		SLATE_EVENT(FOnGetIndexColor, OnGetIndexColor)
		SLATE_END_ARGS()

		void Construct(const FArguments& InArgs)
	{
		OnHoverStateChangedEvent = InArgs._OnHoverStateChanged;
		OnGetIndexColorEvent = InArgs._OnGetIndexColor;

		const FSlateBrush* IndexBrush = FEditorStyle::GetBrush(TEXT("BTEditor.Graph.BTNode.Index"));

		ChildSlot
			[
				SNew(SOverlay)
				+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				// Add a dummy box here to make sure the widget doesnt get smaller than the brush
				SNew(SBox)
				.WidthOverride(IndexBrush->ImageSize.X)
			.HeightOverride(IndexBrush->ImageSize.Y)
			]
		+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
				.BorderImage(IndexBrush)
			.BorderBackgroundColor(this, &SGameTaskIndex::GetColor)
			.Padding(FMargin(4.0f, 0.0f, 4.0f, 1.0f))
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.Text(InArgs._Text)
			.Font(FEditorStyle::GetFontStyle("BTEditor.Graph.BTNode.IndexText"))
			]
			]
			];
	}

	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override
	{
		OnHoverStateChangedEvent.ExecuteIfBound(true);
		SCompoundWidget::OnMouseEnter(MyGeometry, MouseEvent);
	}

	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override
	{
		OnHoverStateChangedEvent.ExecuteIfBound(false);
		SCompoundWidget::OnMouseLeave(MouseEvent);
	}

	/** Get the color we use to display the rounded border */
	FSlateColor GetColor() const
	{
		if (OnGetIndexColorEvent.IsBound())
		{
			return OnGetIndexColorEvent.Execute(IsHovered());
		}

		return FSlateColor::UseForeground();
	}

private:
	/** Delegate event fired when the hover state of this widget changes */
	FOnHoverStateChanged OnHoverStateChangedEvent;

	/** Delegate used to receive the color of the node, depending on hover state and state of other siblings */
	FOnGetIndexColor OnGetIndexColorEvent;
};


void SGraphNode_GameTask::Construct(const FArguments& InArgs, UGameTaskGraphNode* InNode)
{
	DebuggerStateDuration = 0.0f;
	DebuggerStateCounter = INDEX_NONE;
	bSuppressDebuggerTriggers = false;

	SGraphNodeGameTaskBase::Construct(SGraphNodeGameTaskBase::FArguments(), InNode);
}

void SGraphNode_GameTask::UpdateGraphNode()
{
	bDragMarkerVisible = false;
	InputPins.Empty();
	OutputPins.Empty();

	if (EnterEventsBox.IsValid())
	{
		EnterEventsBox->ClearChildren();
	}
	else
	{
		SAssignNew(EnterEventsBox, SVerticalBox);
	}

	if (ExitEventsBox.IsValid())
	{
		ExitEventsBox->ClearChildren();
	}
	else
	{
		SAssignNew(ExitEventsBox, SVerticalBox);
	}

	// Reset variables that are going to be exposed, in case we are refreshing an already setup node.
	RightNodeBox.Reset();
	LeftNodeBox.Reset();
	EnterWidgets.Reset();
	ExitWidgets.Reset();
	SubNodes.Reset();
	OutputPinBox.Reset();


	//Add Event

	if (UGameTaskGraphNode_Flow* GameTaskFlowNode = Cast<UGameTaskGraphNode_Flow>(GraphNode))
	{
		for (int32 i = 0; i < GameTaskFlowNode->EnterEvents.Num(); i++)
		{
			if (GameTaskFlowNode->EnterEvents[i])
			{
				TSharedPtr<SGraphNode> NewNode = FNodeFactory::CreateNodeWidget(GameTaskFlowNode->EnterEvents[i]);
				if (OwnerGraphPanelPtr.IsValid())
				{
					NewNode->SetOwner(OwnerGraphPanelPtr.Pin().ToSharedRef());
					OwnerGraphPanelPtr.Pin()->AttachGraphEvents(NewNode);
				}
				AddEvent(NewNode, true);
				NewNode->UpdateGraphNode();
			}
		}

		for (int32 i = 0; i < GameTaskFlowNode->ExitEvents.Num(); i++)
		{
			if (GameTaskFlowNode->ExitEvents[i])
			{
				TSharedPtr<SGraphNode> NewNode = FNodeFactory::CreateNodeWidget(GameTaskFlowNode->ExitEvents[i]);
				if (OwnerGraphPanelPtr.IsValid())
				{
					NewNode->SetOwner(OwnerGraphPanelPtr.Pin().ToSharedRef());
					OwnerGraphPanelPtr.Pin()->AttachGraphEvents(NewNode);
				}
				AddEvent(NewNode, false);
				NewNode->UpdateGraphNode();
			}
		}
	}
	else if (UGameTaskGraphNode_Execute* GameTaskExecuteNode = Cast<UGameTaskGraphNode_Execute>(GraphNode))
	{
		for (int32 i = 0; i < GameTaskExecuteNode->EnterEvents.Num(); i++)
		{
			if (GameTaskExecuteNode->EnterEvents[i])
			{
				TSharedPtr<SGraphNode> NewNode = FNodeFactory::CreateNodeWidget(GameTaskExecuteNode->EnterEvents[i]);
				if (OwnerGraphPanelPtr.IsValid())
				{
					NewNode->SetOwner(OwnerGraphPanelPtr.Pin().ToSharedRef());
					OwnerGraphPanelPtr.Pin()->AttachGraphEvents(NewNode);
				}
				AddEvent(NewNode);
				NewNode->UpdateGraphNode();
			}
		}
	}

	TSharedPtr<SErrorText> ErrorText;
	TSharedPtr<STextBlock> DescriptionText;
	TSharedPtr<SNodeTitle> NodeTitle = SNew(SNodeTitle, GraphNode);

	TWeakPtr<SNodeTitle> WeakNodeTitle = NodeTitle;
	auto GetNodeTitlePlaceholderWidth = [WeakNodeTitle]() -> FOptionalSize
	{
		TSharedPtr<SNodeTitle> NodeTitlePin = WeakNodeTitle.Pin();
		const float DesiredWidth = (NodeTitlePin.IsValid()) ? NodeTitlePin->GetTitleSize().X : 0.0f;
		return FMath::Max(75.0f, DesiredWidth);
	};
	auto GetNodeTitlePlaceholderHeight = [WeakNodeTitle]() -> FOptionalSize
	{
		TSharedPtr<SNodeTitle> NodeTitlePin = WeakNodeTitle.Pin();
		const float DesiredHeight = (NodeTitlePin.IsValid()) ? NodeTitlePin->GetTitleSize().Y : 0.0f;
		return FMath::Max(22.0f, DesiredHeight);
	};

	const FMargin NodePadding = Cast<UGameTaskGraphNode_Event>(GraphNode)
		? FMargin(2.0f)
		: FMargin(8.0f);

	IndexOverlay = SNew(SGameTaskIndex)
		.ToolTipText(this, &SGraphNode_GameTask::GetIndexTooltipText)
		.Visibility(this, &SGraphNode_GameTask::GetIndexVisibility)
		.Text(this, &SGraphNode_GameTask::GetIndexText)
		.OnHoverStateChanged(this, &SGraphNode_GameTask::OnIndexHoverStateChanged)
		.OnGetIndexColor(this, &SGraphNode_GameTask::GetIndexColor);

	this->ContentScale.Bind(this, &SGraphNode::GetContentScale);
	this->GetOrAddSlot(ENodeZone::Center)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SNew(SBorder)
			.BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
		.Padding(0.0f)
		.BorderBackgroundColor(this, &SGraphNode_GameTask::GetBorderBackgroundColor)
		.OnMouseButtonDown(this, &SGraphNode_GameTask::OnMouseDown)
		[
			SNew(SOverlay)

			// Pins and node details
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SVerticalBox)

			// INPUT PIN AREA
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBox)
			.MinDesiredHeight(NodePadding.Top)
		[
			SAssignNew(LeftNodeBox, SVerticalBox)
		]
		]

	// STATE NAME AREA
	+ SVerticalBox::Slot()
		.Padding(FMargin(NodePadding.Left, 0.0f, NodePadding.Right, 0.0f))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBox)
		.Visibility(this, &SGraphNode_GameTask::GetEventVisibility)
		[
			EnterEventsBox.ToSharedRef()
		]
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SAssignNew(NodeBody, SBorder)
			.BorderImage(FEditorStyle::GetBrush("BTEditor.Graph.BTNode.Body"))
		.BorderBackgroundColor(this, &SGraphNode_GameTask::GetBackgroundColor)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		.Visibility(EVisibility::SelfHitTestInvisible)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			// POPUP ERROR MESSAGE
			SAssignNew(ErrorText, SErrorText)
			.BackgroundColor(this, &SGraphNode_GameTask::GetErrorColor)
		.ToolTipText(this, &SGraphNode_GameTask::GetErrorMsgToolTip)
		]

	+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			SNew(SLevelOfDetailBranchNode)
			.UseLowDetailSlot(this, &SGraphNode_GameTask::UseLowDetailNodeTitles)
		.LowDetail()
		[
			SNew(SBox)
			.WidthOverride_Lambda(GetNodeTitlePlaceholderWidth)
		.HeightOverride_Lambda(GetNodeTitlePlaceholderHeight)
		]
	.HighDetail()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.AutoWidth()
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.Image(this, &SGraphNode_GameTask::GetNameIcon)
		]
	+ SHorizontalBox::Slot()
		.Padding(FMargin(4.0f, 0.0f, 4.0f, 0.0f))
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SAssignNew(InlineEditableText, SInlineEditableTextBlock)
			.Style(FEditorStyle::Get(), "Graph.StateNode.NodeTitleInlineEditableText")
		.Text(NodeTitle.Get(), &SNodeTitle::GetHeadTitle)
		.OnVerifyTextChanged(this, &SGraphNode_GameTask::OnVerifyNameTextChanged)
		.OnTextCommitted(this, &SGraphNode_GameTask::OnNameTextCommited)
		.IsReadOnly(this, &SGraphNode_GameTask::IsNameReadOnly)
		.IsSelected(this, &SGraphNode_GameTask::IsSelectedExclusively)
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			NodeTitle.ToSharedRef()
		]
		]
		]
		]
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			// DESCRIPTION MESSAGE
			SAssignNew(DescriptionText, STextBlock)
			.Visibility(this, &SGraphNode_GameTask::GetDescriptionVisibility)
		.Text(this, &SGraphNode_GameTask::GetDescription)
		]
		]
	+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Fill)
		[
			SNew(SBorder)
			.BorderImage(FEditorStyle::GetBrush("BTEditor.Graph.BTNode.Body"))
		.BorderBackgroundColor(GameTaskColors::Debugger::SearchFailed)
		.Padding(FMargin(4.0f, 0.0f))
		.Visibility(this, &SGraphNode_GameTask::GetDebuggerSearchFailedMarkerVisibility)
		]
		]
		]
	+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(FMargin(10.0f, 0, 0, 0))
		[
			SNew(SBox)
		.Visibility(this, &SGraphNode_GameTask::GetEventVisibility)
		[
			ExitEventsBox.ToSharedRef()
		]
		]
		]

	// OUTPUT PIN AREA
	+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SBox)
			.MinDesiredHeight(NodePadding.Bottom)
		[
			SAssignNew(RightNodeBox, SVerticalBox)
			+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(20.0f, 0.0f)
		.FillHeight(1.0f)
		[
			SAssignNew(OutputPinBox, SHorizontalBox)
		]
		]
		]
		]

	// Drag marker overlay
	+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Top)
		[
			SNew(SBorder)
			.BorderBackgroundColor(GameTaskColors::Action::DragMarker)
		.ColorAndOpacity(GameTaskColors::Action::DragMarker)
		.BorderImage(FEditorStyle::GetBrush("BTEditor.Graph.BTNode.Body"))
		.Visibility(this, &SGraphNode_GameTask::GetDragOverMarkerVisibility)
		[
			SNew(SBox)
			.HeightOverride(40)
		]
		]

	// Blueprint indicator overlay
	+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
		[
			SNew(SImage)
			.Image(FEditorStyle::GetBrush(TEXT("BTEditor.Graph.BTNode.Blueprint")))
		.Visibility(this, &SGraphNode_GameTask::GetBlueprintIconVisibility)
		]
		]
		];
	// Create comment bubble
	TSharedPtr<SCommentBubble> CommentBubble;
	const FSlateColor CommentColor = GetDefault<UGraphEditorSettings>()->DefaultCommentNodeTitleColor;

	SAssignNew(CommentBubble, SCommentBubble)
		.GraphNode(GraphNode)
		.Text(this, &SGraphNode::GetNodeComment)
		.OnTextCommitted(this, &SGraphNode::OnCommentTextCommitted)
		.ColorAndOpacity(CommentColor)
		.AllowPinning(true)
		.EnableTitleBarBubble(true)
		.EnableBubbleCtrls(true)
		.GraphLOD(this, &SGraphNode::GetCurrentLOD)
		.IsGraphNodeHovered(this, &SGraphNode::IsHovered);

	GetOrAddSlot(ENodeZone::TopCenter)
		.SlotOffset(TAttribute<FVector2D>(CommentBubble.Get(), &SCommentBubble::GetOffset))
		.SlotSize(TAttribute<FVector2D>(CommentBubble.Get(), &SCommentBubble::GetSize))
		.AllowScaling(TAttribute<bool>(CommentBubble.Get(), &SCommentBubble::IsScalingAllowed))
		.VAlign(VAlign_Top)
		[
			CommentBubble.ToSharedRef()
		];

	ErrorReporting = ErrorText;
	ErrorReporting->SetError(ErrorMsg);
	CreatePinWidgets();
}

void SGraphNode_GameTask::CreatePinWidgets()
{
	UGameTaskGraphNode* StateNode = CastChecked<UGameTaskGraphNode>(GraphNode);

	for (int32 PinIdx = 0; PinIdx < StateNode->Pins.Num(); PinIdx++)
	{
		UEdGraphPin* MyPin = StateNode->Pins[PinIdx];
		if (!MyPin->bHidden)
		{
			TSharedPtr<SGraphPin> NewPin = SNew(SGameTaskPin, MyPin)
				.ToolTipText(this, &SGraphNode_GameTask::GetPinTooltip, MyPin);

			AddPin(NewPin.ToSharedRef());
		}
	}
}

void SGraphNode_GameTask::AddPin(const TSharedRef<SGraphPin>& PinToAdd)
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
			.Padding(20.0f, 0.0f)
			[
				PinToAdd
			];
		InputPins.Add(PinToAdd);
	}
	else // Direction == EEdGraphPinDirection::EGPD_Output
	{
		const bool bIsSingleTaskPin = PinObj && (PinObj->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleFlow);
		if (bIsSingleTaskPin)
		{
			OutputPinBox->AddSlot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillWidth(0.4f)
				.Padding(8.0f, 0, 5.0f, 0)
				[
					PinToAdd
				];
		}
		else
		{
			OutputPinBox->AddSlot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.FillWidth(1.0f)
				[
					PinToAdd
				];
		}
		OutputPins.Add(PinToAdd);
	}
}

TSharedPtr<SToolTip> SGraphNode_GameTask::GetComplexTooltip()
{
	return IDocumentation::Get()->CreateToolTip(TAttribute<FText>(this, &SGraphNode::GetNodeTooltip), nullptr, GraphNode->GetDocumentationLink(), GraphNode->GetDocumentationExcerptName());
}

void SGraphNode_GameTask::GetOverlayBrushes(bool bSelected, const FVector2D WidgetSize,
	TArray<FOverlayBrushInfo>& Brushes) const
{
	UGameTaskGraphNode* GameTaskNode = Cast<UGameTaskGraphNode>(GraphNode);
	if (GameTaskNode == nullptr)
	{
		return;
	}
}

TArray<FOverlayWidgetInfo> SGraphNode_GameTask::GetOverlayWidgets(bool bSelected, const FVector2D& WidgetSize) const
{
	TArray<FOverlayWidgetInfo> Widgets;

	check(NodeBody.IsValid());
	check(IndexOverlay.IsValid());

	FVector2D Origin(0.0f, 0.0f);

	// build overlays for event sub-nodes
	for (const auto& EventWidget : EnterWidgets)
	{
		TArray<FOverlayWidgetInfo> OverlayWidgets = EventWidget->GetOverlayWidgets(bSelected, WidgetSize);
		for (auto& OverlayWidget : OverlayWidgets)
		{
			OverlayWidget.OverlayOffset.Y += Origin.Y;
		}
		Widgets.Append(OverlayWidgets);
		Origin.Y += EventWidget->GetDesiredSize().Y;
	}

	FOverlayWidgetInfo Overlay(IndexOverlay);
	Overlay.OverlayOffset = FVector2D(WidgetSize.X - (IndexOverlay->GetDesiredSize().X * 0.5f), Origin.Y);
	Widgets.Add(Overlay);

	Origin.Y += NodeBody->GetDesiredSize().Y;

	for (const auto& ExitWidget : ExitWidgets)
	{
		TArray<FOverlayWidgetInfo> OverlayWidgets = ExitWidget->GetOverlayWidgets(bSelected, WidgetSize);
		for (auto& OverlayWidget : OverlayWidgets)
		{
			OverlayWidget.OverlayOffset.Y += Origin.Y;
		}
		Widgets.Append(OverlayWidgets);
		Origin.Y += ExitWidget->GetDesiredSize().Y;
	}

	return Widgets;
}

TSharedRef<SGraphNode> SGraphNode_GameTask::GetNodeUnderMouse(const FGeometry& MyGeometry,
	const FPointerEvent& MouseEvent)
{
	TSharedPtr<SGraphNode> SubNode = GetSubNodeUnderCursor(MyGeometry, MouseEvent);
	return SubNode.IsValid() ? SubNode.ToSharedRef() : StaticCastSharedRef<SGraphNode>(AsShared());
}

void SGraphNode_GameTask::MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter)
{
	SGraphNodeGameTaskBase::MoveTo(NewPosition, NodeFilter);

	// keep node order (defined by linked pins) up to date with actual positions
	// this function will keep spamming on every mouse move update
	UGameTaskGraphNode* GameTaskGraphNode = Cast<UGameTaskGraphNode>(GraphNode);
	if (GameTaskGraphNode && !GameTaskGraphNode->IsSubNode())
	{
		UGameTaskGraph* BTGraph = GameTaskGraphNode->GetGameTaskGraph();
		if (BTGraph)
		{
			for (int32 Idx = 0; Idx < GameTaskGraphNode->Pins.Num(); Idx++)
			{
				UEdGraphPin* Pin = GameTaskGraphNode->Pins[Idx];
				if (Pin && Pin->Direction == EGPD_Input && Pin->LinkedTo.Num() == 1)
				{
					UEdGraphPin* ParentPin = Pin->LinkedTo[0];
					if (ParentPin)
					{
						BTGraph->RebuildChildOrder(ParentPin->GetOwningNode());
					}
				}
			}
		}
	}
}


FReply SGraphNode_GameTask::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	return SGraphNode::OnMouseButtonDoubleClick(InMyGeometry, InMouseEvent);
}

void SGraphNode_GameTask::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SGraphNode::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	CachedPosition = AllottedGeometry.AbsolutePosition / AllottedGeometry.Scale;
	UGameTaskGraphNode* MyNode = Cast<UGameTaskGraphNode>(GraphNode);
	DebuggerStateDuration += InDeltaTime;

	UGameTaskGraphNode* GameTaskGraphNode = Cast<UGameTaskGraphNode>(GraphNode);
	float NewFlashAlpha = 0.0f;
	TriggerOffsets.Reset();


	FlashAlpha = NewFlashAlpha;
}

void SGraphNode_GameTask::AddEvent(TSharedPtr<SGraphNode> EventWidget, bool bEnterEvent)
{
	if (bEnterEvent)
	{
		EnterEventsBox->AddSlot().AutoHeight()
			[
				EventWidget.ToSharedRef()
			];
		EnterWidgets.Add(EventWidget);
	}
	else
	{
		ExitEventsBox->AddSlot().AutoHeight()
			[
				EventWidget.ToSharedRef()
			];
		ExitWidgets.Add(EventWidget);
	}
	AddSubNode(EventWidget);
}

EVisibility SGraphNode_GameTask::GetDebuggerSearchFailedMarkerVisibility() const
{
	UGameTaskGraphNode_Event* MyNode = Cast<UGameTaskGraphNode_Event>(GraphNode);
	return MyNode ? EVisibility::HitTestInvisible : EVisibility::Collapsed;
}

FSlateColor SGraphNode_GameTask::GetBorderBackgroundColor() const
{
	UGameTaskGraphNode* GameTaskGraphNode = Cast<UGameTaskGraphNode>(GraphNode);
	UGameTaskGraphNode* GameTaskParentNode = GameTaskGraphNode ? Cast<UGameTaskGraphNode>(GameTaskGraphNode->ParentNode) : nullptr;

	const bool bSelectedSubNode = GameTaskParentNode && GetOwnerPanel()->SelectionManager.SelectedNodes.Contains(GraphNode);

	UGameTaskNode* NodeInstance = GameTaskGraphNode ? Cast<UGameTaskNode>(GameTaskGraphNode->NodeInstance) : nullptr;
	const bool bIsConnectedTreeRoot = GameTaskGraphNode && GameTaskGraphNode->IsA<UGameTaskGraphNode_Root>() && GameTaskGraphNode->Pins.IsValidIndex(0) && GameTaskGraphNode->Pins[0]->LinkedTo.Num() > 0;
	const bool bIsEvent = GameTaskGraphNode && GameTaskGraphNode->IsA(UGameTaskGraphNode_Event::StaticClass());
	const bool bIsBrokenWithParent = bIsEvent;
	return bSelectedSubNode ? GameTaskColors::NodeBorder::Selected :
		bIsBrokenWithParent ? GameTaskColors::NodeBorder::BrokenWithParent :
		bIsConnectedTreeRoot ? GameTaskColors::NodeBorder::Root :
		GameTaskColors::NodeBorder::Inactive;
}

FSlateColor SGraphNode_GameTask::GetBackgroundColor() const
{
	UGameTaskGraphNode* GameTaskGraphNode = Cast<UGameTaskGraphNode>(GraphNode);
	UGameTaskGraphNode_Event* GameTaskGraph_Event = Cast<UGameTaskGraphNode_Event>(GraphNode);


	FLinearColor NodeColor = GameTaskColors::NodeBody::Default;
	if (GameTaskGraphNode && GameTaskGraphNode->HasErrors())
	{
		NodeColor = GameTaskColors::NodeBody::Error;
	}

	else if (Cast<UGameTaskGraphNode_Execute>(GraphNode))
	{
		check(GameTaskGraphNode);
		NodeColor = GameTaskColors::NodeBody::Execute;
	}
	else if (Cast<UGameTaskGraphNode_Composite>(GraphNode))
	{
		check(GameTaskGraphNode);
		UGameTaskCompositeNode* CompositeNodeInstance = Cast<UGameTaskCompositeNode>(GameTaskGraphNode->NodeInstance);
		NodeColor = GameTaskColors::NodeBody::Composite;
	}
	else if (Cast<UGameTaskGraphNode_Event>(GraphNode))
	{
		NodeColor = GameTaskColors::NodeBody::Event;
	}
	else if (Cast<UGameTaskGraphNode_Root>(GraphNode) && GraphNode->Pins.IsValidIndex(0) && GraphNode->Pins[0]->LinkedTo.Num() > 0)
	{
		NodeColor = GameTaskColors::NodeBody::Root;
	}

	return (FlashAlpha > 0.0f) ? FMath::Lerp(NodeColor, FlashColor, FlashAlpha) : NodeColor;
}

const FSlateBrush* SGraphNode_GameTask::GetNameIcon() const
{
	UGameTaskGraphNode* GameTaskGraphNode = Cast<UGameTaskGraphNode>(GraphNode);
	return GameTaskGraphNode != nullptr ? FEditorStyle::GetBrush(GameTaskGraphNode->GetNameIcon()) : FEditorStyle::GetBrush(TEXT("BTEditor.Graph.BTNode.Icon"));
}

EVisibility SGraphNode_GameTask::GetBlueprintIconVisibility() const
{
	UGameTaskGraphNode* GameTaskGraphNode = Cast<UGameTaskGraphNode>(GraphNode);
	const bool bCanShowIcon = (GameTaskGraphNode != nullptr && GameTaskGraphNode->UsesBlueprint());

	// LOD this out once things get too small
	TSharedPtr<SGraphPanel> MyOwnerPanel = GetOwnerPanel();
	return (bCanShowIcon && (!MyOwnerPanel.IsValid() || MyOwnerPanel->GetCurrentLOD() > EGraphRenderingLOD::LowDetail)) ? EVisibility::Visible : EVisibility::Collapsed;
}

EVisibility SGraphNode_GameTask::GetIndexVisibility() const
{
	// always hide the index on the root node
	if (GraphNode->IsA(UGameTaskGraphNode_Root::StaticClass()))
	{
		return EVisibility::Collapsed;
	}

	UGameTaskGraphNode* StateNode = CastChecked<UGameTaskGraphNode>(GraphNode);
	UEdGraphPin* MyInputPin = StateNode->GetInputPin();
	UEdGraphPin* MyParentOutputPin = NULL;
	if (MyInputPin != NULL && MyInputPin->LinkedTo.Num() > 0)
	{
		MyParentOutputPin = MyInputPin->LinkedTo[0];
	}

	// Visible if we are in PIE or if we have siblings
	CA_SUPPRESS(6235);
	const bool bCanShowIndex = (GEditor->bIsSimulatingInEditor || GEditor->PlayWorld != NULL) || (MyParentOutputPin && MyParentOutputPin->LinkedTo.Num() > 1);

	// LOD this out once things get too small
	TSharedPtr<SGraphPanel> MyOwnerPanel = GetOwnerPanel();
	return (bCanShowIndex && (!MyOwnerPanel.IsValid() || MyOwnerPanel->GetCurrentLOD() > EGraphRenderingLOD::LowDetail)) ? EVisibility::Visible : EVisibility::Collapsed;
}

FText SGraphNode_GameTask::GetIndexText() const
{
	UGameTaskGraphNode* StateNode = CastChecked<UGameTaskGraphNode>(GraphNode);
	UEdGraphPin* MyInputPin = StateNode->GetInputPin();
	UEdGraphPin* MyParentOutputPin = NULL;
	if (MyInputPin != NULL && MyInputPin->LinkedTo.Num() > 0)
	{
		MyParentOutputPin = MyInputPin->LinkedTo[0];
	}

	int32 Index = 0;

	CA_SUPPRESS(6235);
	if (bShowExecutionIndexInEditorMode || GEditor->bIsSimulatingInEditor || GEditor->PlayWorld != NULL)
	{
	}
	else
	{
	}
	return FText::AsNumber(Index);
}

FText SGraphNode_GameTask::GetIndexTooltipText() const
{
	CA_SUPPRESS(6235);
	if (bShowExecutionIndexInEditorMode || GEditor->bIsSimulatingInEditor || GEditor->PlayWorld != NULL)
	{
		return LOCTEXT("ExecutionIndexTooltip", "Execution index: this shows the order in which nodes are executed.");
	}
	else
	{
		return LOCTEXT("ChildIndexTooltip", "Child index: this shows the order in which child nodes are executed.");
	}
}

FSlateColor SGraphNode_GameTask::GetIndexColor(bool bHovered) const
{

	static const FName DefaultColor("BTEditor.Graph.BTNode.Index.Color");
	return  FEditorStyle::Get().GetSlateColor(DefaultColor);
}

void SGraphNode_GameTask::OnIndexHoverStateChanged(bool bHovered)
{

}

FText SGraphNode_GameTask::GetPinTooltip(UEdGraphPin* GraphPinObj) const
{
	FText HoverText = FText::GetEmpty();

	check(GraphPinObj != nullptr);
	UEdGraphNode* OwningGraphNode = GraphPinObj->GetOwningNode();
	if (OwningGraphNode != nullptr)
	{
		FString HoverStr;
		OwningGraphNode->GetPinHoverText(*GraphPinObj, /*out*/HoverStr);
		if (!HoverStr.IsEmpty())
		{
			HoverText = FText::FromString(HoverStr);
		}
	}

	return HoverText;
}

#undef LOCTEXT_NAMESPACE
