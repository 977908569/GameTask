#pragma once
#include "CoreMinimal.h"

class UGameTaskEvent;
namespace GameTaskEditorUtils
{
	struct FGameTaskPropertySelectionInfo
	{
		FGameTaskPropertySelectionInfo(): FoundEvent(nullptr)
		{
		}

		UGameTaskEvent* FoundEvent;
	};

	/** Given a selection of nodes, return the instances that should be selected be selected for editing in the property panel */
	TArray<UObject*> GetSelectionForPropertyEditor(const TSet<UObject*>& InSelection, FGameTaskPropertySelectionInfo& OutSelectionInfo);
}