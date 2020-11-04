#include "GameTaskEditorModes.h"
#include "GameTaskEditor.h"
#include "GameTaskEditorTabFactories.h"
#include "GameTaskEditorToolbar.h"
#define LOCTEXT_NAMESPACE "GameTaskApplicationMode"

FGameTaskEditorApplicationModes::FGameTaskEditorApplicationModes(TSharedPtr<FGameTaskEditor> InGameTaskEditor)
	: FApplicationMode(FGameTaskEditor::GameTaskMode)
{
	GameTaskEditor = InGameTaskEditor;

	GameTaskEditorTabFactories.RegisterFactory(MakeShareable(new FGameTaskDetailsSummoner(InGameTaskEditor)));

	TabLayout = FTabManager::NewLayout("Standalone_GameTask_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.1f)
				->AddTab(InGameTaskEditor->GetToolbarTabId(), ETabState::OpenedTab)
				->SetHideTabWell(true)
			)
			->Split
			(
				FTabManager::NewSplitter()->SetOrientation(Orient_Horizontal)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.7f)
					->AddTab(FGameTaskEditorTabs::GraphEditorID, ETabState::ClosedTab)
				)
				->Split
				(
					FTabManager::NewSplitter()->SetOrientation(Orient_Vertical)
					->SetSizeCoefficient(0.3f)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.6f)
						->AddTab(FGameTaskEditorTabs::GraphDetailsID, ETabState::OpenedTab)
						
					)
					->Split
					(
						FTabManager::NewStack()
						->SetSizeCoefficient(0.4f)
						
					)
				)
			)
		);

	InGameTaskEditor->GetToolbarBuilder()->AddModesToolbar(ToolbarExtender);
	InGameTaskEditor->GetToolbarBuilder()->AddDebuggerToolbar(ToolbarExtender);
	InGameTaskEditor->GetToolbarBuilder()->AddGameTaskToolbar(ToolbarExtender);
}

void FGameTaskEditorApplicationModes::RegisterTabFactories(
    TSharedPtr<FTabManager> InTabManager) {
}

void FGameTaskEditorApplicationModes::PreDeactivateMode() {
	FApplicationMode::PreDeactivateMode();

	check(GameTaskEditor.IsValid());
	TSharedPtr<FGameTaskEditor> GameTaskEditorPtr = GameTaskEditor.Pin();

	//GameTaskEditorPtr->SaveEditedObjectState();
}

void FGameTaskEditorApplicationModes::PostActivateMode() {

	check(GameTaskEditor.IsValid());
	TSharedPtr<FGameTaskEditor> BehaviorTreeEditorPtr = GameTaskEditor.Pin();
	BehaviorTreeEditorPtr->RestoreGameTask();
	FApplicationMode::PostActivateMode();
}

#undef LOCTEXT_NAMESPACE
