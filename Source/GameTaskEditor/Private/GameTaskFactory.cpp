#include "GameTaskFactory.h"
#include "GameTask.h"
#include "AssetTypeCategories.h"
#define LOCTEXT_NAMESPACE "GameTask"

UGameTaskFactory::UGameTaskFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UGameTask::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UGameTaskFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UGameTask::StaticClass()));
	const auto NewAsset = NewObject<UGameTask>(InParent, Class, Name, Flags | RF_Transactional);
	NewAsset->Comment = TEXT("Game Task");
	return NewAsset;
}


FText UGameTaskFactory::GetDisplayName() const {
	return LOCTEXT("GameTask", "GameTask");
}

uint32 UGameTaskFactory::GetMenuCategories() const
{
	return EAssetTypeCategories::Gameplay;
}

bool UGameTaskFactory::CanCreateNew() const {
	return true;
}
#undef LOCTEXT_NAMESPACE
