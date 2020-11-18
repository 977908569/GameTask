#pragma once
#include "SGraphNode.h"
#include "SGraphPin.h"
#include "Input/DragAndDrop.h"
#include "Editor/GraphEditor/Private/DragNode.h"

class UGameTaskGraphNode;

class FDragGameTaskGraphNode : public FDragNode
{
public:
	DRAG_DROP_OPERATOR_TYPE(FDragGameTaskGraphNode, FDragNode)

		static TSharedRef<FDragGameTaskGraphNode> New(const TSharedRef<SGraphPanel>& InGraphPanel, const TSharedRef<SGraphNode>& InDraggedNode);
	static TSharedRef<FDragGameTaskGraphNode> New(const TSharedRef<SGraphPanel>& InGraphPanel, const TArray< TSharedRef<SGraphNode> >& InDraggedNodes);

	UGameTaskGraphNode* GetDropTargetNode() const;

	double StartTime;

	bool bEnter;
protected:
	typedef FDragNode Super;
};


class GAMETASKEDITOR_API SGraphNodeGameTaskBase : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SGraphNodeGameTaskBase) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, UGameTaskGraphNode* InNode);

	//~ Begin SGraphNode Interface
	virtual TSharedPtr<SToolTip> GetComplexTooltip() override;
	virtual void OnDragEnter(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	virtual FReply OnDragOver(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
	virtual void OnDragLeave(const FDragDropEvent& DragDropEvent) override;
	virtual FReply OnMouseMove(const FGeometry& SenderGeometry, const FPointerEvent& MouseEvent) override;
	virtual void SetOwner(const TSharedRef<SGraphPanel>& OwnerPanel) override;
	virtual void AddPin(const TSharedRef<SGraphPin>& PinToAdd) override;
	//~ End SGraphNode Interface

	/** handle mouse down on the node */
	FReply OnMouseDown(const FGeometry& SenderGeometry, const FPointerEvent& MouseEvent);

	/** adds subnode widget inside current node */
	virtual void AddSubNode(TSharedPtr<SGraphNode> SubNodeWidget);

	/** gets event node if one is found under mouse cursor */
	TSharedPtr<SGraphNode> GetSubNodeUnderCursor(const FGeometry& WidgetGeometry, const FPointerEvent& MouseEvent);

	/** gets drag over marker visibility */
	EVisibility GetDragOverMarkerVisibility() const;

	/** sets drag marker visible or collapsed on this node */
	void SetDragMarker(bool bEnabled);

protected:
	TArray< TSharedPtr<SGraphNode> > SubNodes;

	uint32 bDragMarkerVisible : 1;

	virtual FText GetDescription() const;
	virtual EVisibility GetDescriptionVisibility() const;
	virtual  EVisibility GetEventVisibility() const;

	virtual FText GetPreviewCornerText() const;
	virtual const FSlateBrush* GetNameIcon() const;
};

class GAMETASKEDITOR_API SGraphPinGameTask : public SGraphPin
{
public:
	SLATE_BEGIN_ARGS(SGraphPinGameTask) {}
	SLATE_END_ARGS()

		void Construct(const FArguments& InArgs, UEdGraphPin* InPin);
protected:
	//~ Begin SGraphPin Interface
	virtual FSlateColor GetPinColor() const override;
	virtual TSharedRef<SWidget>	GetDefaultValueWidget() override;
	//~ End SGraphPin Interface
	const FSlateBrush* GetPinBorder() const;
};
