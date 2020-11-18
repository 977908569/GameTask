#include "GameTaskEditorToolbar.h"
#include "GameTaskEditor.h"
#include "WorkflowOrientedApp/SModeWidget.h"

void FGameTaskEditorToolbar::AddModesToolbar(TSharedPtr<FExtender> Extender) {
	check(GameTaskEditor.IsValid());
	TSharedPtr<FGameTaskEditor> GameTaskEditorPtr = GameTaskEditor.Pin();

	Extender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		GameTaskEditorPtr->GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateSP(this, &FGameTaskEditorToolbar::FillModesToolbar));
}

void FGameTaskEditorToolbar::AddDebuggerToolbar(TSharedPtr<FExtender> Extender) {
}

void FGameTaskEditorToolbar::AddGameTaskToolbar(TSharedPtr<FExtender> Extender) {
	check(GameTaskEditor.IsValid());
	TSharedPtr<FGameTaskEditor> GameTaskEditorPtr = GameTaskEditor.Pin();

	TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
	ToolbarExtender->AddToolBarExtension("Asset", EExtensionHook::After, GameTaskEditorPtr->GetToolkitCommands(), FToolBarExtensionDelegate::CreateSP(this, &FGameTaskEditorToolbar::FillGameTaskToolbar));
	GameTaskEditorPtr->AddToolbarExtender(ToolbarExtender);
}

void FGameTaskEditorToolbar::FillModesToolbar(FToolBarBuilder& ToolbarBuilder)
{
	check(GameTaskEditor.IsValid());
	TSharedPtr<FGameTaskEditor> GameTaskEditorPtr = GameTaskEditor.Pin();
	// Left side padding
	GameTaskEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));
}

void FGameTaskEditorToolbar::FillDebuggerToolbar(FToolBarBuilder& ToolbarBuilder)
{
}

void FGameTaskEditorToolbar::FillGameTaskToolbar(FToolBarBuilder& ToolbarBuilder)
{
	check(GameTaskEditor.IsValid());
	TSharedPtr<FGameTaskEditor> GameTaskEditorPtr = GameTaskEditor.Pin();
	//TODO

}
