#include "GameTaskComposite_Sequence.h"

UGameTaskComposite_Sequence::UGameTaskComposite_Sequence(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	NodeName = "Sequence";
}

#if WITH_EDITOR
FName UGameTaskComposite_Sequence::GetNodeIconName() const
{
	return FName("BTEditor.Graph.BTNode.Composite.Sequence.Icon");
}
#endif

