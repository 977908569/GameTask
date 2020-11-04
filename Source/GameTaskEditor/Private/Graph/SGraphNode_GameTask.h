#pragma once
#include "GameTaskEditorTypes.h"
#include "SGraphNodeGameTaskBase.h"

class SGraphNode_GameTask : public SGraphNodeGameTaskBase
{
public:
	SLATE_BEGIN_ARGS(SGraphNode_GameTask) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, UGameTaskGraphNode* InNode);

	// SGraphNode interface
	virtual void UpdateGraphNode() override;
	virtual void CreatePinWidgets() override;
	virtual void AddPin(const TSharedRef<SGraphPin>& PinToAdd) override;
	virtual TSharedPtr<SToolTip> GetComplexTooltip() override;
	virtual void GetOverlayBrushes(bool bSelected, const FVector2D WidgetSize, TArray<FOverlayBrushInfo>& Brushes) const override;
	virtual TArray<FOverlayWidgetInfo> GetOverlayWidgets(bool bSelected, const FVector2D& WidgetSize) const override;
	virtual TSharedRef<SGraphNode> GetNodeUnderMouse(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter) override;
	// End of SGraphNode interface

	/** handle double click */
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;

	/**
	 * Ticks this widget.  Override in derived classes, but always call the parent implementation.
	 *
	 * @param  AllottedGeometry The space allotted for this widget
	 * @param  InCurrentTime  Current absolute real time
	 * @param  InDeltaTime  Real time passed since last tick
	 */
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;

	/** adds event widget inside current node */
	void AddEvent(TSharedPtr<SGraphNode> EventWidget);


	/** shows red marker when search failed*/
	EVisibility GetDebuggerSearchFailedMarkerVisibility() const;

	FVector2D GetCachedPosition() const { return CachedPosition; }

protected:
	uint32 bSuppressDebuggerColor : 1;
	uint32 bSuppressDebuggerTriggers : 1;

	/** time spent in current state */
	float DebuggerStateDuration;

	/** currently displayed state */
	int32 DebuggerStateCounter;

	/** debugger colors */
	FLinearColor FlashColor;
	float FlashAlpha;

	/** height offsets for search triggers */
	TArray<FGameTaskNodeBounds> TriggerOffsets;

	/** cached draw position */
	FVector2D CachedPosition;

	TArray< TSharedPtr<SGraphNode> > EventWidgets;
	TSharedPtr<SVerticalBox> EventsBox;
	TSharedPtr<SHorizontalBox> OutputPinBox;

	/** The widget we use to display the index of the node */
	TSharedPtr<SWidget> IndexOverlay;

	/** The node body widget, cached here so we can determine its size when we want ot position our overlays */
	TSharedPtr<SBorder> NodeBody;

	FSlateColor GetBorderBackgroundColor() const;
	FSlateColor GetBackgroundColor() const;

	virtual const FSlateBrush* GetNameIcon() const override;
	virtual EVisibility GetBlueprintIconVisibility() const;

	/** Get the visibility of the index overlay */
	EVisibility GetIndexVisibility() const;

	/** Get the text to display in the index overlay */
	FText GetIndexText() const;

	/** Get the tooltip for the index overlay */
	FText GetIndexTooltipText() const;

	/** Get the color to display for the index overlay. This changes on hover state of sibling nodes */
	FSlateColor GetIndexColor(bool bHovered) const;

	/** Handle hover state changing for the index widget - we use this to highlight sibling nodes */
	void OnIndexHoverStateChanged(bool bHovered);

	FText GetPinTooltip(UEdGraphPin* GraphPinObj) const;
};
