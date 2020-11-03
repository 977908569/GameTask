#include "FAssetTypeActions_GameTask.h"
#include "GameTask.h"
#include "GameTaskEditor.h"

UClass* FAssetTypeActions_GameTask::GetSupportedClass() const {
	return UGameTask::StaticClass();
}

uint32 FAssetTypeActions_GameTask::GetCategories() {
	return EAssetTypeCategories::Gameplay;
}

void FAssetTypeActions_GameTask::OpenAssetEditor(
	const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor) {
	const EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto Object : InObjects)
	{
		const auto GameTask = Cast<UGameTask>(Object);
		if (GameTask != nullptr)
		{
			FGameTaskEditorModule& BehaviorTreeEditorModule = FModuleManager::GetModuleChecked<FGameTaskEditorModule>("GameTaskEditor");
			TSharedRef< IGameTaskEditor > NewEditor = BehaviorTreeEditorModule.CreateGameTaskEditor(Mode, EditWithinLevelEditor, GameTask);
		}
	}
}

