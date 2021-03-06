#include "GameTaskEditorGraphSchema.h"
#include "EdGraphNode_Comment.h"
#include "GameTaskComposite_Flow.h"
#include "GameTaskEditorModule.h"
#include "GameTaskEvent.h"
#include "Graph/GameTaskGraphConnectionDrawingPolicy.h"
#include "Node/GameTaskGraphNodeBase.h"
#include "Node/GameTaskGraphNode_Root.h"
#include "GraphEditorActions.h"
#include "ToolMenu.h"
#include "Framework/Commands/GenericCommands.h"
#include "Node/GameTaskGraphNode_Event.h"
#include "GameTaskEditorTypes.h"
#include "GameTaskComposite_Parallel.h"
#include "GameTaskComposite_Sequence.h"
#include "GameTask_Execute.h"
#include "Node/GameTaskGraphNode_Execute.h"
#include "Node/GameTaskGraphNode_Flow.h"
#include "Node/GameTaskGraphNode_Parallel.h"
#include "Node/GameTaskGraphNode_Sequence.h"
#define LOCTEXT_NAMESPACE "GameTask"
#define SNAP_GRID (16) // @todo ensure this is the same as SNodePanel::GetSnapGridSize()
namespace
{
	// Maximum distance a drag can be off a node edge to require 'push off' from node
	const int32 NodeDistance = 60;
}

int32 UGameTaskEditorGraphSchema::CurrentCacheRefreshID = 0;



UEdGraphNode* FGameTaskSchemaAction_AddComment::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
	const FVector2D Location, bool bSelectNewNode)
{
	UEdGraphNode_Comment* const CommentTemplate = NewObject<UEdGraphNode_Comment>();

	FVector2D SpawnLocation = Location;
	FSlateRect Bounds;

	TSharedPtr<SGraphEditor> GraphEditorPtr = SGraphEditor::FindGraphEditorForGraph(ParentGraph);
	if (GraphEditorPtr.IsValid() && GraphEditorPtr->GetBoundsForSelectedNodes(/*out*/ Bounds, 50.0f))
	{
		CommentTemplate->SetBounds(Bounds);
		SpawnLocation.X = CommentTemplate->NodePosX;
		SpawnLocation.Y = CommentTemplate->NodePosY;
	}

	UEdGraphNode* const NewNode = FEdGraphSchemaAction_NewNode::SpawnNodeFromTemplate<UEdGraphNode_Comment>(ParentGraph, CommentTemplate, SpawnLocation, bSelectNewNode);

	return NewNode;
}

UEdGraphNode* FGameTaskSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
	const FVector2D Location, bool bSelectNewNode)
{
	UEdGraphNode* ResultNode = nullptr;

	// If there is a template, we actually use it
	if (NodeTemplate != nullptr)
	{
		const FScopedTransaction Transaction(LOCTEXT("AddNode", "Add Node"));
		ParentGraph->Modify();
		if (FromPin)
		{
			FromPin->Modify();
		}

		NodeTemplate->SetFlags(RF_Transactional);

		// set outer to be the graph so it doesn't go away
		NodeTemplate->Rename(nullptr, ParentGraph, REN_NonTransactional);
		ParentGraph->AddNode(NodeTemplate, true);

		NodeTemplate->CreateNewGuid();
		NodeTemplate->PostPlacedNewNode();

		// For input pins, new node will generally overlap node being dragged off
		// Work out if we want to visually push away from connected node
		int32 XLocation = Location.X;
		if (FromPin && FromPin->Direction == EGPD_Input)
		{
			UEdGraphNode* PinNode = FromPin->GetOwningNode();
			const float XDelta = FMath::Abs(PinNode->NodePosX - Location.X);

			if (XDelta < NodeDistance)
			{
				// Set location to edge of current node minus the max move distance
				// to force node to push off from connect node enough to give selection handle
				XLocation = PinNode->NodePosX - NodeDistance;
			}
		}

		NodeTemplate->NodePosX = XLocation;
		NodeTemplate->NodePosY = Location.Y;
		NodeTemplate->SnapToGrid(SNAP_GRID);

		// setup pins after placing node in correct spot, since pin sorting will happen as soon as link connection change occurs
		NodeTemplate->AllocateDefaultPins();
		NodeTemplate->AutowireNewNode(FromPin);

		ResultNode = NodeTemplate;
	}

	return ResultNode;
}

UEdGraphNode* FGameTaskSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins,
	const FVector2D Location, bool bSelectNewNode)
{
	UEdGraphNode* ResultNode = nullptr;
	if (FromPins.Num() > 0)
	{
		ResultNode = PerformAction(ParentGraph, FromPins[0], Location);

		// Try autowiring the rest of the pins
		for (int32 Index = 1; Index < FromPins.Num(); ++Index)
		{
			ResultNode->AutowireNewNode(FromPins[Index]);
		}
	}
	else
	{
		ResultNode = PerformAction(ParentGraph, nullptr, Location, bSelectNewNode);
	}

	return ResultNode;
}

void FGameTaskSchemaAction_NewNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);

	// These don't get saved to disk, but we want to make sure the objects don't get GC'd while the action array is around
	Collector.AddReferencedObject(NodeTemplate);
}

UEdGraphNode* FGameTaskSchemaAction_NewSubNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
	const FVector2D Location, bool bSelectNewNode)
{
	ParentNode->AddSubNode(NodeTemplate, ParentGraph);
	return nullptr;
}

UEdGraphNode* FGameTaskSchemaAction_NewSubNode::PerformAction(UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins,
	const FVector2D Location, bool bSelectNewNode)
{
	return PerformAction(ParentGraph, nullptr, Location, bSelectNewNode);
}

void FGameTaskSchemaAction_NewSubNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);

	// These don't get saved to disk, but we want to make sure the objects don't get GC'd while the action array is around
	Collector.AddReferencedObject(NodeTemplate);
	Collector.AddReferencedObject(ParentNode);
}


UGameTaskEditorGraphSchemaBase::UGameTaskEditorGraphSchemaBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskEditorGraphSchemaBase::GetBreakLinkToSubMenuActions(UToolMenu* Menu, UEdGraphPin* InGraphPin)
{
	// Make sure we have a unique name for every entry in the list
	TMap< FString, uint32 > LinkTitleCount;

	FToolMenuSection& Section = Menu->FindOrAddSection("GameTaskGraphSchemaPinActions");

	// Add all the links we could break from
	for (TArray<class UEdGraphPin*>::TConstIterator Links(InGraphPin->LinkedTo); Links; ++Links)
	{
		UEdGraphPin* Pin = *Links;
		FString TitleString = Pin->GetOwningNode()->GetNodeTitle(ENodeTitleType::ListView).ToString();
		FText Title = FText::FromString(TitleString);
		if (Pin->PinName != TEXT(""))
		{
			TitleString = FString::Printf(TEXT("%s (%s)"), *TitleString, *Pin->PinName.ToString());

			// Add name of connection if possible
			FFormatNamedArguments Args;
			Args.Add(TEXT("NodeTitle"), Title);
			Args.Add(TEXT("PinName"), Pin->GetDisplayName());
			Title = FText::Format(LOCTEXT("BreakDescPin", "{NodeTitle} ({PinName})"), Args);
		}

		uint32& Count = LinkTitleCount.FindOrAdd(TitleString);

		FText Description;
		FFormatNamedArguments Args;
		Args.Add(TEXT("NodeTitle"), Title);
		Args.Add(TEXT("NumberOfNodes"), Count);

		if (Count == 0)
		{
			Description = FText::Format(LOCTEXT("BreakDesc", "Break link to {NodeTitle}"), Args);
		}
		else
		{
			Description = FText::Format(LOCTEXT("BreakDescMulti", "Break link to {NodeTitle} ({NumberOfNodes})"), Args);
		}
		++Count;

		Section.AddMenuEntry(NAME_None, Description, Description, FSlateIcon(), FUIAction(
			FExecuteAction::CreateUObject(this, &UGameTaskEditorGraphSchema::BreakSinglePinLink, const_cast<UEdGraphPin*>(InGraphPin), *Links)));
	}
}



void UGameTaskEditorGraphSchemaBase::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	if (Context->Pin)
	{
		{
			FToolMenuSection& Section = Menu->AddSection("GameTaskGraphSchemaPinActions", LOCTEXT("PinActionsMenuHeader", "Pin Actions"));
			// Only display the 'Break Links' option if there is a link to break!
			if (Context->Pin->LinkedTo.Num() > 0)
			{
				Section.AddMenuEntry(FGraphEditorCommands::Get().BreakPinLinks);

				// add sub menu for break link to
				if (Context->Pin->LinkedTo.Num() > 1)
				{
					Section.AddSubMenu(
						"BreakLinkTo",
						LOCTEXT("BreakLinkTo", "Break Link To..."),
						LOCTEXT("BreakSpecificLinks", "Break a specific link..."),
						FNewToolMenuDelegate::CreateUObject((UGameTaskEditorGraphSchema* const)this, &UGameTaskEditorGraphSchema::GetBreakLinkToSubMenuActions, const_cast<UEdGraphPin*>(Context->Pin)));
				}
				else
				{
					((UGameTaskEditorGraphSchema* const)this)->GetBreakLinkToSubMenuActions(Menu, const_cast<UEdGraphPin*>(Context->Pin));
				}
			}
		}
	}
	else if (Context->Node)
	{
		{
			FToolMenuSection& Section = Menu->AddSection("GameTaskGraphSchemaNodeActions", LOCTEXT("ClassActionsMenuHeader", "Node Actions"));
			Section.AddMenuEntry(FGenericCommands::Get().Delete);
			Section.AddMenuEntry(FGenericCommands::Get().Cut);
			Section.AddMenuEntry(FGenericCommands::Get().Copy);
			Section.AddMenuEntry(FGenericCommands::Get().Duplicate);

			Section.AddMenuEntry(FGraphEditorCommands::Get().BreakNodeLinks);
		}
	}

	Super::GetContextMenuActions(Menu, Context);
}

FLinearColor UGameTaskEditorGraphSchemaBase::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
	return FColor::White;
}

bool UGameTaskEditorGraphSchemaBase::ShouldHidePinDefaultValue(UEdGraphPin* Pin) const
{
	check(Pin != NULL);
	return Pin->bDefaultValueIsIgnored;
}

FConnectionDrawingPolicy* UGameTaskEditorGraphSchemaBase::CreateConnectionDrawingPolicy(int32 InBackLayerID,
	int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements,
	UEdGraph* InGraphObj) const
{
	return new FGameTaskGraphConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements, InGraphObj);
}

void UGameTaskEditorGraphSchemaBase::BreakNodeLinks(UEdGraphNode& TargetNode) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakNodeLinks", "Break Node Links"));
	Super::BreakNodeLinks(TargetNode);
}

void UGameTaskEditorGraphSchemaBase::BreakPinLinks(UEdGraphPin& TargetPin, bool bSendsNodeNotification) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakPinLinks", "Break Pin Links"));

	Super::BreakPinLinks(TargetPin, bSendsNodeNotification);
}

void UGameTaskEditorGraphSchemaBase::BreakSinglePinLink(UEdGraphPin* SourcePin, UEdGraphPin* TargetPin) const
{
	const FScopedTransaction Transaction(NSLOCTEXT("UnrealEd", "GraphEd_BreakSinglePinLink", "Break Pin Link"));

	Super::BreakSinglePinLink(SourcePin, TargetPin);
}

TSharedPtr<FEdGraphSchemaAction> UGameTaskEditorGraphSchemaBase::GetCreateCommentAction() const
{
	return TSharedPtr<FEdGraphSchemaAction>(static_cast<FEdGraphSchemaAction*>(new FGameTaskSchemaAction_AddComment));
}

int32 UGameTaskEditorGraphSchemaBase::GetNodeSelectionCount(const UEdGraph* Graph) const
{
	if (Graph)
	{
		TSharedPtr<SGraphEditor> GraphEditorPtr = SGraphEditor::FindGraphEditorForGraph(Graph);
		if (GraphEditorPtr.IsValid())
		{
			return GraphEditorPtr->GetNumberOfSelectedNodes();
		}
	}

	return 0;
}

void UGameTaskEditorGraphSchemaBase::GetGraphNodeContextActions(FGraphContextMenuBuilder& ContextMenuBuilder,
	EGameTaskSubNode SubNodeFlags) const
{
	UEdGraph* Graph = (UEdGraph*)ContextMenuBuilder.CurrentGraph;
	UClass* GraphNodeClass = nullptr;
	TArray<FGameTaskGraphNodeClassData> NodeClasses;
	GetSubNodeClasses(SubNodeFlags, NodeClasses, GraphNodeClass);

	if (GraphNodeClass)
	{
		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));

			UGameTaskGraphNodeBase* OpNode = NewObject<UGameTaskGraphNodeBase>(Graph, GraphNodeClass);
			OpNode->ClassData = NodeClass;
			if (const auto Event = Cast<UGameTaskGraphNode_Event>(OpNode)) {
				Event->bEnterEvent = SubNodeFlags == EGameTaskSubNode::EnterEvent;
			}
			TSharedPtr<FGameTaskSchemaAction_NewSubNode> AddOpAction = UGameTaskEditorGraphSchema::AddNewSubNodeAction(ContextMenuBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			AddOpAction->ParentNode = Cast<UGameTaskGraphNodeBase>(ContextMenuBuilder.SelectedObjects[0]);
			AddOpAction->NodeTemplate = OpNode;
		}
	}
}

void UGameTaskEditorGraphSchemaBase::GetSubNodeClasses(EGameTaskSubNode SubNodeFlags, TArray<FGameTaskGraphNodeClassData>& ClassData,
	UClass*& GraphNodeClass) const
{
	// empty in base class
}

TSharedPtr<FGameTaskSchemaAction_NewNode> UGameTaskEditorGraphSchemaBase::AddNewNodeAction(
	FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
	TSharedPtr<FGameTaskSchemaAction_NewNode> NewAction = TSharedPtr<FGameTaskSchemaAction_NewNode>(new FGameTaskSchemaAction_NewNode(Category, MenuDesc, Tooltip, 0));
	ContextMenuBuilder.AddAction(NewAction);

	return NewAction;
}

TSharedPtr<FGameTaskSchemaAction_NewSubNode> UGameTaskEditorGraphSchemaBase::AddNewSubNodeAction(
	FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
	TSharedPtr<FGameTaskSchemaAction_NewSubNode> NewAction = TSharedPtr<FGameTaskSchemaAction_NewSubNode>(new FGameTaskSchemaAction_NewSubNode(Category, MenuDesc, Tooltip, 0));
	ContextMenuBuilder.AddAction(NewAction);
	return NewAction;
}
//=====================================================================================
UGameTaskEditorGraphSchema::UGameTaskEditorGraphSchema(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void UGameTaskEditorGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	FGraphNodeCreator<UGameTaskGraphNode_Root> NodeCreator(Graph);
	UGameTaskGraphNode_Root* MyNode = NodeCreator.CreateNode();
	NodeCreator.Finalize();
	SetNodeMetaData(MyNode, FNodeMetadata::DefaultGraphNode);
}

void UGameTaskEditorGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	const FName PinCategory = ContextMenuBuilder.FromPin ? ContextMenuBuilder.FromPin->PinType.PinCategory : UGameTaskEditorTypes::PinCategory_MultipleNodes;

	//忽略
	if (PinCategory == UGameTaskEditorTypes::PinCategory_OnlyShow)
		return;

	const bool bNoParent = ContextMenuBuilder.FromPin == nullptr;
	//仅仅流程节点
	const bool bOnlyFlow = PinCategory == UGameTaskEditorTypes::PinCategory_SingleFlow;
	//
	const bool bAllowFlow = bNoParent || bOnlyFlow;
	const bool bAllowExecute = bNoParent || !bOnlyFlow;
	const bool bAllowComposites = bNoParent || !bOnlyFlow;

	FGameTaskEditorModule& EditorModule = FModuleManager::GetModuleChecked<FGameTaskEditorModule>(TEXT("GameTaskEditor"));
	FGameTaskGraphNodeClassHelper* ClassCache = EditorModule.GetClassCache().Get();

	if (bAllowFlow)
	{
		FCategorizedGraphActionListBuilder FlowBuilder(TEXT("Flow"));
		TArray<FGameTaskGraphNodeClassData> NodeClasses;
		ClassCache->GatherClasses(UGameTaskComposite_Flow::StaticClass(), NodeClasses);

		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));
			TSharedPtr<FGameTaskSchemaAction_NewNode> AddOpAction = UGameTaskEditorGraphSchemaBase::AddNewNodeAction(FlowBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			UClass* GraphNodeClass = UGameTaskGraphNode_Flow::StaticClass();
			UGameTaskGraphNode_Flow* OpNode = NewObject<UGameTaskGraphNode_Flow>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
			OpNode->ClassData = NodeClass;
			AddOpAction->NodeTemplate = OpNode;
		}
		ContextMenuBuilder.Append(FlowBuilder);
	}

	if (bAllowExecute) {
		FCategorizedGraphActionListBuilder ExecutesBuilder(TEXT("Executes"));
		TArray<FGameTaskGraphNodeClassData> ExecuteNodeClasses;
		ClassCache->GatherClasses(UGameTask_Execute::StaticClass(), ExecuteNodeClasses);
		for (const auto& NodeClass : ExecuteNodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));
			TSharedPtr<FGameTaskSchemaAction_NewNode> AddOpAction = UGameTaskEditorGraphSchemaBase::AddNewNodeAction(ExecutesBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			UClass* GraphNodeClass = UGameTaskGraphNode_Execute::StaticClass();
			UGameTaskGraphNode_Execute* OpNode = NewObject<UGameTaskGraphNode_Execute>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
			OpNode->ClassData = NodeClass;
			AddOpAction->NodeTemplate = OpNode;
		}
		ContextMenuBuilder.Append(ExecutesBuilder);
	}

	if (bAllowComposites)
	{
		TArray<FGameTaskGraphNodeClassData> NodeClasses;
		FCategorizedGraphActionListBuilder CompositesBuilder(TEXT("Composites"));
		ClassCache->GatherClasses(UGameTaskNode::StaticClass(), NodeClasses);;
		for (auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));
			TSharedPtr<FGameTaskSchemaAction_NewNode> AddOpAction;
			UClass* GraphNodeClass = UGameTaskGraphNode::StaticClass();
			UGameTaskGraphNode* OpNode = nullptr;

			if (NodeClass.GetClass()->IsChildOf(UGameTaskComposite_Sequence::StaticClass()))
			{
				GraphNodeClass = UGameTaskGraphNode_Sequence::StaticClass();
				OpNode = NewObject<UGameTaskGraphNode_Sequence>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
				AddOpAction = UGameTaskEditorGraphSchemaBase::AddNewNodeAction(CompositesBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			}
			else if (NodeClass.GetClass()->IsChildOf(UGameTaskComposite_Parallel::StaticClass()))
			{
				GraphNodeClass = UGameTaskGraphNode_Parallel::StaticClass();
				OpNode = NewObject<UGameTaskGraphNode_Parallel>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
				AddOpAction = UGameTaskEditorGraphSchemaBase::AddNewNodeAction(CompositesBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			}
			if (OpNode) {
				OpNode->ClassData = NodeClass;
				AddOpAction->NodeTemplate = OpNode;
			}
		}
		ContextMenuBuilder.Append(CompositesBuilder);
	}
}

void UGameTaskEditorGraphSchema::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	if (Context->Node && !Context->Pin)
	{
		const UGameTaskGraphNode* GraphNode = Cast<const UGameTaskGraphNode>(Context->Node);
		if (GraphNode && GraphNode->CanPlaceBreakpoints())
		{
			FToolMenuSection& Section = Menu->AddSection("EdGraphSchemaBreakpoints", LOCTEXT("BreakpointsHeader", "Breakpoints"));
			{
				Section.AddMenuEntry(FGraphEditorCommands::Get().ToggleBreakpoint);
				Section.AddMenuEntry(FGraphEditorCommands::Get().AddBreakpoint);
				Section.AddMenuEntry(FGraphEditorCommands::Get().RemoveBreakpoint);
				Section.AddMenuEntry(FGraphEditorCommands::Get().EnableBreakpoint);
				Section.AddMenuEntry(FGraphEditorCommands::Get().DisableBreakpoint);
			}
		}
	}

	Super::GetContextMenuActions(Menu, Context);
}

const FPinConnectionResponse UGameTaskEditorGraphSchema::CanCreateConnection(const UEdGraphPin* PinA, const UEdGraphPin* PinB) const
{
	// same node
	if (PinA->GetOwningNode() == PinB->GetOwningNode())
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinErrorSameNode", "Both are on the same node"));
	}

	const bool bPinAIsSingleNode = PinA->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleNode;
	const bool bPinAIsMultipleNodes = PinA->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_MultipleNodes;
	const bool bPinAIsSingleFlow = PinA->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleFlow;

	const bool bPinBIsSingleNode = PinB->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleNode;
	const bool bPinBIsMultipleNodes = PinB->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_MultipleNodes;
	const bool bPinBIsSingleFlow = PinB->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleFlow;


	const bool bPinAIsExecute = PinA->GetOwningNode()->IsA(UGameTaskGraphNode_Execute::StaticClass());

	const bool bPinAIsFlow = PinA->GetOwningNode()->IsA(UGameTaskGraphNode_Flow::StaticClass());

	const bool bPinBIsExecute = PinB->GetOwningNode()->IsA(UGameTaskGraphNode_Execute::StaticClass());

	const bool bPinBIsFlow = PinB->GetOwningNode()->IsA(UGameTaskGraphNode_Flow::StaticClass());

	//仅显示 不能连接
	if (PinA->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_OnlyShow || PinB->PinType.PinCategory == UGameTaskEditorTypes::PinCategory_OnlyShow)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinErrorOnlyShow", "Only show"));
	}

	// Compare the directions
	if ((PinA->Direction == EGPD_Input) && (PinB->Direction == EGPD_Input))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinErrorInput", "Can't connect input node to input node"));
	}
	else if ((PinB->Direction == EGPD_Output) && (PinA->Direction == EGPD_Output))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinErrorOutput", "Can't connect output node to output node"));
	}

	class FNodeVisitorCycleChecker
	{
	public:
		/** Check whether a loop in the graph would be caused by linking the passed-in nodes */
		bool CheckForLoop(UEdGraphNode* StartNode, UEdGraphNode* EndNode)
		{
			VisitedNodes.Add(EndNode);
			return TraverseInputNodesToRoot(StartNode);
		}

	private:
		/**
		 * Helper function for CheckForLoop()
		 * @param	Node	The node to start traversal at
		 * @return true if we reached a root node (i.e. a node with no input pins), false if we encounter a node we have already seen
		 */
		bool TraverseInputNodesToRoot(UEdGraphNode* Node)
		{
			VisitedNodes.Add(Node);

			// Follow every input pin until we cant any more ('root') or we reach a node we have seen (cycle)
			for (int32 PinIndex = 0; PinIndex < Node->Pins.Num(); ++PinIndex)
			{
				UEdGraphPin* MyPin = Node->Pins[PinIndex];

				if (MyPin->Direction == EGPD_Input)
				{
					for (int32 LinkedPinIndex = 0; LinkedPinIndex < MyPin->LinkedTo.Num(); ++LinkedPinIndex)
					{
						UEdGraphPin* OtherPin = MyPin->LinkedTo[LinkedPinIndex];
						if (OtherPin)
						{
							UEdGraphNode* OtherNode = OtherPin->GetOwningNode();
							if (VisitedNodes.Contains(OtherNode))
							{
								return false;
							}
							else
							{
								return TraverseInputNodesToRoot(OtherNode);
							}
						}
					}
				}
			}

			return true;
		}

		TSet<UEdGraphNode*> VisitedNodes;
	};

	// check for cycles
	FNodeVisitorCycleChecker CycleChecker;
	if (!CycleChecker.CheckForLoop(PinA->GetOwningNode(), PinB->GetOwningNode()))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, LOCTEXT("PinErrorcycle", "Can't create a graph cycle"));
	}

	const bool bPinASingleLink = bPinAIsSingleNode || bPinAIsSingleFlow;
	const bool bPinBSingleLink = bPinBIsSingleNode || bPinBIsSingleFlow;

	if (PinB->Direction == EGPD_Input && PinB->LinkedTo.Num() > 0)
	{
		if (bPinASingleLink)
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, LOCTEXT("PinConnectReplace", "Replace connection"));
		}
		else
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_B, LOCTEXT("PinConnectReplace", "Replace connection"));
		}
	}
	else if (PinA->Direction == EGPD_Input && PinA->LinkedTo.Num() > 0)
	{
		if (bPinBSingleLink)
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, LOCTEXT("PinConnectReplace", "Replace connection"));
		}
		else
		{
			return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, LOCTEXT("PinConnectReplace", "Replace connection"));
		}
	}

	if (bPinASingleLink && PinA->LinkedTo.Num() > 0)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, LOCTEXT("PinConnectReplace", "Replace connection"));
	}
	else if (bPinBSingleLink && PinB->LinkedTo.Num() > 0)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_B, LOCTEXT("PinConnectReplace", "Replace connection"));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, LOCTEXT("PinConnect", "Connect nodes"));
}

const FPinConnectionResponse UGameTaskEditorGraphSchema::CanMergeNodes(const UEdGraphNode* NodeA,
	const UEdGraphNode* NodeB) const
{
	// Make sure the nodes are not the same 
	if (NodeA == NodeB)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Both are the same node"));
	}

	const bool bNodeAIsEvent = NodeA->IsA(UGameTaskGraphNode_Event::StaticClass());

	const bool bNodeBIsFlow = NodeB->IsA(UGameTaskGraphNode_Flow::StaticClass());
	const bool bNodeBIsExecute = NodeB->IsA(UGameTaskGraphNode_Execute::StaticClass());

	if (bNodeAIsEvent && (bNodeBIsFlow || bNodeBIsExecute))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT(""));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT(""));
}

FLinearColor UGameTaskEditorGraphSchema::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
	if (PinType.PinCategory == UGameTaskEditorTypes::PinCategory_SingleFlow)
	{
		return FColor::Purple;
	}
	return FColor::White;
}

FConnectionDrawingPolicy* UGameTaskEditorGraphSchema::CreateConnectionDrawingPolicy(int32 InBackLayerID,
	int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements,
	UEdGraph* InGraphObj) const
{
	return new FGameTaskGraphConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements, InGraphObj);
}

bool UGameTaskEditorGraphSchema::IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const
{
	return CurrentCacheRefreshID != InVisualizationCacheID;
}

int32 UGameTaskEditorGraphSchema::GetCurrentVisualizationCacheID() const
{
	return CurrentCacheRefreshID;
}

void UGameTaskEditorGraphSchema::ForceVisualizationCacheClear() const
{
	++CurrentCacheRefreshID;
}

void UGameTaskEditorGraphSchema::GetGraphNodeContextActions(FGraphContextMenuBuilder& ContextMenuBuilder,
	EGameTaskSubNode SubNodeFlags) const
{
	Super::GetGraphNodeContextActions(ContextMenuBuilder, SubNodeFlags);
}

void UGameTaskEditorGraphSchema::GetSubNodeClasses(EGameTaskSubNode SubNodeFlags, TArray<FGameTaskGraphNodeClassData>& ClassData,
	UClass*& GraphNodeClass) const
{
	FGameTaskEditorModule& EditorModule = FModuleManager::GetModuleChecked<FGameTaskEditorModule>(TEXT("GameTaskEditor"));
	FGameTaskGraphNodeClassHelper* ClassCache = EditorModule.GetClassCache().Get();

	if (SubNodeFlags == EGameTaskSubNode::EnterEvent || SubNodeFlags == EGameTaskSubNode::ExitEvent)
	{
		ClassCache->GatherClasses(UGameTaskEvent::StaticClass(), ClassData);
		GraphNodeClass = UGameTaskGraphNode_Event::StaticClass();
	}

}

#undef LOCTEXT_NAMESPACE
