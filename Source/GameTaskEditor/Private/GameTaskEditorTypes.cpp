#include "GameTaskEditorTypes.h"

const FName UGameTaskEditorTypes::PinCategory_SingleFlow("SingleFlow");//RootNode
const FName UGameTaskEditorTypes::PinCategory_CompositeOrExecute("CompositeOrExecute");
const FName UGameTaskEditorTypes::PinCategory_MultipleNodes("MultipleNodes");
const FName UGameTaskEditorTypes::PinCategory_SingleComposite("SingleComposite");
const FName UGameTaskEditorTypes::PinCategory_SingleExecute("SingleExecute");
const FName UGameTaskEditorTypes::PinCategory_OnlyShow("OnlyShow");

UGameTaskEditorTypes::UGameTaskEditorTypes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}