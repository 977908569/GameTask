#pragma once
#include "GameTaskFactory.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual FText GetDisplayName() const override;
	virtual uint32 GetMenuCategories() const override;
	virtual bool CanCreateNew() const override;
	// End of UFactory interface
};
