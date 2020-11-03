#include "GameTaskEditorTypes.h"

const FName UGameTaskEditorTypes::PinCategory_MultipleNodes("MultipleNodes");
const FName UGameTaskEditorTypes::PinCategory_SingleComposite("SingleComposite");
const FName UGameTaskEditorTypes::PinCategory_SingleExecute("SingleExecute");
const FName UGameTaskEditorTypes::PinCategory_SingleNode("SingleNode");

UGameTaskEditorTypes::UGameTaskEditorTypes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}