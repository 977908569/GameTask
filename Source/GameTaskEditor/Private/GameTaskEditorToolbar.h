#pragma once
#include "CoreMinimal.h"
class FGameTaskEditorToolbar :public TSharedFromThis<FGameTaskEditorToolbar>
{
public:
	FGameTaskEditorToolbar(TSharedPtr<class FGameTaskEditor> InGameTaskEditor)
	{
		GameTaskEditor = InGameTaskEditor;
	}

	void AddModesToolbar(TSharedPtr<FExtender> Extender);
	void AddDebuggerToolbar(TSharedPtr<FExtender> Extender);
	void AddGameTaskToolbar(TSharedPtr<FExtender> Extender);

private:
	void FillModesToolbar(FToolBarBuilder& ToolbarBuilder);
	void FillDebuggerToolbar(FToolBarBuilder& ToolbarBuilder);
	void FillGameTaskToolbar(FToolBarBuilder& ToolbarBuilder);
protected:
	TWeakPtr<FGameTaskEditor> GameTaskEditor;
};