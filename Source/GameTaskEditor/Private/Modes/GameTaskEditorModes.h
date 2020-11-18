#pragma once
#include "WorkflowOrientedApp/WorkflowTabManager.h"
#include "WorkflowOrientedApp/ApplicationMode.h"

class GAMETASKEDITOR_API FGameTaskEditorApplicationModes :public FApplicationMode
{
public:
	FGameTaskEditorApplicationModes(TSharedPtr<class FGameTaskEditor> InGameTaskEditor);
	virtual void RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;
protected:
	TWeakPtr<class FGameTaskEditor> GameTaskEditor;

	FWorkflowAllowedTabSet GameTaskEditorTabFactories;
};