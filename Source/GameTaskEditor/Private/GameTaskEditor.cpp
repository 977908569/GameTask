#include "GameTaskEditor.h"
#include "Debug/GameTaskDebugger.h"
#include "GameTaskEditorGraphSchema.h"
#include "Modes/GameTaskEditorModes.h"
#include "GameTaskEditorTabFactories.h"
#include "GameTaskEditorToolbar.h"
#include "Graph/GameTaskGraph.h"
#include "GraphEditorActions.h"
#include "Kismet2/BlueprintEditorUtils.h"

#define LOCTEXT_NAMESPACE "GameTaskEditor"

const FName FGameTaskEditor::GameTaskMode(TEXT("GameTask"));

FGameTaskEditor::FGameTaskEditor() : IGameTaskEditor()
{
	//
}

FGameTaskEditor::~FGameTaskEditor()
{
	UPackage::PackageSavedEvent.Remove(OnPackageSavedDelegateHandle);

	Debugger.Reset();
}

void FGameTaskEditor::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	DocumentManager->SetTabManager(InTabManager);
	FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}

void FGameTaskEditor::InitGameTaskEditor(const EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost,
	UObject* InObject)
{
	UGameTask* GameTaskToEdit = Cast<UGameTask>(InObject);
	if (GameTaskToEdit) {
		GameTask = GameTaskToEdit;
	}
	TSharedPtr<FGameTaskEditor> ThisPtr(SharedThis(this));

	if (!DocumentManager.IsValid()) {
		DocumentManager = MakeShareable(new FDocumentTracker);
		DocumentManager->Initialize(ThisPtr);
		// Register the document factories
		{
			TSharedRef<FDocumentTabFactory> GraphEditorFactory = MakeShareable(new FGameTaskGraphEditorSummoner(ThisPtr,
				FGameTaskGraphEditorSummoner::FOnCreateGraphEditorWidget::CreateSP(this, &FGameTaskEditor::CreateGraphEditorWidget)
			));

			// Also store off a reference to the grapheditor factory so we can find all the tabs spawned by it later.
			GraphEditorTabFactoryPtr = GraphEditorFactory;
			DocumentManager->RegisterDocumentFactory(GraphEditorFactory);
		}
	}
	//
	if (!ToolbarBuilder.IsValid())
	{
		ToolbarBuilder = MakeShareable(new FGameTaskEditorToolbar(SharedThis(this)));
	}

	TArray<UObject*> ObjectsToEdit;
	if (GameTask != nullptr)
	{
		ObjectsToEdit.Add(GameTask);
	}

	const TArray<UObject*>* EditedObjects = GetObjectsCurrentlyBeingEdited();
	if (EditedObjects == nullptr || EditedObjects->Num() == 0)
	{
		FGraphEditorCommands::Register();

		const TSharedRef<FTabManager::FLayout> DummyLayout = FTabManager::NewLayout("NullLayout")->AddArea(FTabManager::NewPrimaryArea());
		const bool bCreateDefaultStandaloneMenu = true;
		const bool bCreateDefaultToolbar = true;
		InitAssetEditor(Mode, InitToolkitHost, FGameTaskEditorModule::GameTaskEditorAppIdentifier, DummyLayout, bCreateDefaultStandaloneMenu, bCreateDefaultToolbar, ObjectsToEdit);

		BindCommonCommands();
		ExtendMenu();
		CreateInternalWidgets();

		//Debug
		Debugger = MakeShareable(new FGameTaskDebugger);
		//
		FGameTaskEditorModule& GameTaskEditorModule = FModuleManager::LoadModuleChecked<FGameTaskEditorModule>("GameTaskEditor");
		AddMenuExtender(GameTaskEditorModule.GetMenuExtensibilityManager()->GetAllExtenders(GetToolkitCommands(), GetEditingObjects()));
		AddApplicationMode(GameTaskMode, MakeShareable(new FGameTaskEditorApplicationModes(SharedThis(this))));
	}
	else
	{
		for (UObject* ObjectToEdit : ObjectsToEdit)
		{
			if (!EditedObjects->Contains(ObjectToEdit))
			{
				AddEditingObject(ObjectToEdit);
			}
		}
	}
	if (GameTask)
	{
		SetCurrentMode(GameTaskMode);
	}
	else
	{
		//TODO
		SetCurrentMode(GameTaskMode);
	}
	RegenerateMenusAndToolbars();
}

FName FGameTaskEditor::GetToolkitFName() const
{
	return FName("GameTask");
}

FText FGameTaskEditor::GetBaseToolkitName() const
{
	return LOCTEXT("AppLabel", "GameTask");
}

FString FGameTaskEditor::GetWorldCentricTabPrefix() const
{
	return LOCTEXT("WorldCentricTabPrefix", "GameTask ").ToString();
}

FLinearColor FGameTaskEditor::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.0f, 0.0f, 0.2f, 0.5f);
}

FText FGameTaskEditor::GetToolkitName() const
{
	const UObject* EditingObject = GetCurrentMode() == GameTaskMode ? (UObject*)GameTask : nullptr;
	if (EditingObject != nullptr)
	{
		return FAssetEditorToolkit::GetLabelForObject(EditingObject);
	}

	return FText();
}

FText FGameTaskEditor::GetToolkitToolTipText() const
{
	const UObject* EditingObject = GetCurrentMode() == GameTaskMode ? (UObject*)GameTask : nullptr;
	if (EditingObject != nullptr)
	{
		return FAssetEditorToolkit::GetToolTipTextForObject(EditingObject);
	}

	return FText();
}

void FGameTaskEditor::InitializeDebuggerState(FGameTaskDebugger* ParentDebugger) const
{
	if (Debugger.IsValid())
	{
		//TODO
	}
}

void FGameTaskEditor::DoubleClickNode(UEdGraphNode* Node)
{

}

void FGameTaskEditor::PostUndo(bool bSuccess)
{
	FGameTaskGraphEditor::PostUndo(bSuccess);
}

void FGameTaskEditor::PostRedo(bool bSuccess)
{
	FGameTaskGraphEditor::PostRedo(bSuccess);
}

void FGameTaskEditor::NotifyPostChange(const FPropertyChangedEvent& PropertyChangedEvent,
	FProperty* PropertyThatChanged)
{
	//TODO
}

void FGameTaskEditor::OnNodeDoubleClicked(UEdGraphNode* Node) {
}

void FGameTaskEditor::OnGraphEditorFocused(
	const TSharedRef<SGraphEditor>& InGraphEditor) {
}

void FGameTaskEditor::OnNodeTitleCommitted(const FText& NewText,
	ETextCommit::Type CommitInfo, UEdGraphNode* NodeBeingChanged) {
}

void FGameTaskEditor::OnAddInputPin() {
}

bool FGameTaskEditor::CanAddInputPin() const {
	return true;
}

void FGameTaskEditor::OnRemoveInputPin() {
}

bool FGameTaskEditor::CanRemoveInputPin() const {
	return true;
}

void FGameTaskEditor::OnEnableBreakpoint() {
}

bool FGameTaskEditor::CanEnableBreakpoint() const {
	return true;
}

void FGameTaskEditor::OnToggleBreakpoint() {
}

bool FGameTaskEditor::CanToggleBreakpoint() const {
	return true;
}

void FGameTaskEditor::OnDisableBreakpoint() {
}

bool FGameTaskEditor::CanDisableBreakpoint() const {
	return true;
}

void FGameTaskEditor::OnAddBreakpoint() {
}

bool FGameTaskEditor::CanAddBreakpoint() const {
	return true;
}

void FGameTaskEditor::OnRemoveBreakpoint() {
}

bool FGameTaskEditor::CanRemoveBreakpoint() const {
	return true;
}

FGraphAppearanceInfo FGameTaskEditor::GetGraphAppearance() const {
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText", "GAME TASK");

	return AppearanceInfo;
}

bool FGameTaskEditor::InEditingMode(bool bGraphIsEditable) const {
	return bGraphIsEditable;
}

TSharedRef<SWidget> FGameTaskEditor::SpawnProperties() {
	return
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		.HAlign(HAlign_Fill)
		[
			DetailsView.ToSharedRef()
		];

}

UGameTask* FGameTaskEditor::GetGameTask() const {
	return GameTask;
}

void FGameTaskEditor::RestoreGameTask() {
	UGameTaskGraph* MyGraph = Cast<UGameTaskGraph>(GameTask->TaskGraph);
	const bool bNewGraph = MyGraph == nullptr;
	if (MyGraph == nullptr)
	{
		GameTask->TaskGraph = FBlueprintEditorUtils::CreateNewGraph(GameTask, TEXT("Game Task"), UGameTaskGraph::StaticClass(), UGameTaskEditorGraphSchema::StaticClass());
		MyGraph = Cast<UGameTaskGraph>(GameTask->TaskGraph);

		// Initialize the game task graph
		const UEdGraphSchema* Schema = MyGraph->GetSchema();
		Schema->CreateDefaultNodesForGraph(*MyGraph);

		MyGraph->OnCreated();
	}
	else
	{
		MyGraph->OnLoaded();
	}

	MyGraph->Initialize();

	TSharedRef<FTabPayload_UObject> Payload = FTabPayload_UObject::Make(MyGraph);
	TSharedPtr<SDockTab> DocumentTab = DocumentManager->OpenDocument(Payload, bNewGraph ? FDocumentTracker::OpenNewDocument : FDocumentTracker::RestorePreviousDocument);

	if (GameTask->LastEditedDocuments.Num() > 0)
	{
		TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(DocumentTab->GetContent());
		GraphEditor->SetViewLocation(GameTask->LastEditedDocuments[0].SavedViewOffset, GameTask->LastEditedDocuments[0].SavedZoomAmount);
	}

	const bool bIncreaseVersionNum = false;
	if (bNewGraph)
	{
		MyGraph->UpdateAsset(UGameTaskGraph::ClearDebuggerFlags | UGameTaskGraph::KeepRebuildCounter);

	}
	else
	{
		MyGraph->UpdateAsset(UGameTaskGraph::KeepRebuildCounter);

	}
}

TSharedPtr<FGameTaskEditorToolbar> FGameTaskEditor::GetToolbarBuilder() const {
	return ToolbarBuilder;
}

void FGameTaskEditor::CreateInternalWidgets() {
}

void FGameTaskEditor::ExtendMenu() {
}

void FGameTaskEditor::BindCommonCommands() {
}

TSharedRef<SGraphEditor> FGameTaskEditor::CreateGraphEditorWidget(
	UEdGraph* InGraph) {

	check(InGraph != NULL);

	if (!GraphEditorCommands.IsValid())
	{
		CreateCommandList();

		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().RemoveExecutionPin,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnRemoveInputPin),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanRemoveInputPin)
		);

		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().AddExecutionPin,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnAddInputPin),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanAddInputPin)
		);

		// Debug actions
		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().AddBreakpoint,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnAddBreakpoint),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanAddBreakpoint),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP(this, &FGameTaskEditor::CanAddBreakpoint)
		);

		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().RemoveBreakpoint,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnRemoveBreakpoint),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanRemoveBreakpoint),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP(this, &FGameTaskEditor::CanRemoveBreakpoint)
		);

		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().EnableBreakpoint,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnEnableBreakpoint),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanEnableBreakpoint),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP(this, &FGameTaskEditor::CanEnableBreakpoint)
		);

		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().DisableBreakpoint,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnDisableBreakpoint),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanDisableBreakpoint),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP(this, &FGameTaskEditor::CanDisableBreakpoint)
		);

		GraphEditorCommands->MapAction(FGraphEditorCommands::Get().ToggleBreakpoint,
			FExecuteAction::CreateSP(this, &FGameTaskEditor::OnToggleBreakpoint),
			FCanExecuteAction::CreateSP(this, &FGameTaskEditor::CanToggleBreakpoint),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP(this, &FGameTaskEditor::CanToggleBreakpoint)
		);
	}

	SGraphEditor::FGraphEditorEvents InEvents;
	InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FGameTaskEditor::OnSelectedNodesChanged);
	InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FGameTaskEditor::OnNodeDoubleClicked);
	InEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, &FGameTaskEditor::OnNodeTitleCommitted);

	// Make title bar
	TSharedRef<SWidget> TitleBarWidget =
		SNew(SBorder)
		.BorderImage(FEditorStyle::GetBrush(TEXT("Graph.TitleBackground")))
		.HAlign(HAlign_Fill)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.HAlign(HAlign_Center)
		.FillWidth(1.f)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("GameTaskGraphLabel", "Game Task"))
		.TextStyle(FEditorStyle::Get(), TEXT("GraphBreadcrumbButtonText"))
		]
		];

	// Make full graph editor
	const bool bGraphIsEditable = InGraph->bEditable;
	return SNew(SGraphEditor)
		.AdditionalCommands(GraphEditorCommands)
		.IsEditable(this, &FGameTaskEditor::InEditingMode, bGraphIsEditable)
		.Appearance(this, &FGameTaskEditor::GetGraphAppearance)
		.TitleBar(TitleBarWidget)
		.GraphToEdit(InGraph)
		.GraphEvents(InEvents);

}


#undef LOCTEXT_NAMESPACE
