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
protected:
	TWeakPtr<FGameTaskEditor> GameTaskEditor;
};