#include "GameTaskEditorTypes.h"

const FName UGameTaskEditorTypes::PinCategory_SingleFlow("SingleFlow");//RootNode
const FName UGameTaskEditorTypes::PinCategory_MultipleNodes("MultipleNodes");
const FName UGameTaskEditorTypes::PinCategory_SingleNode("SingleNode");
const FName UGameTaskEditorTypes::PinCategory_OnlyShow("OnlyShow");

UGameTaskEditorTypes::UGameTaskEditorTypes(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}