#pragma once
#include "GameTaskNode.h"
#include "GameTaskAuxiliaryNode.generated.h"
/**
 * Auxiliary nodes are supporting nodes
 */
UCLASS(Abstract)
class UGameTaskAuxiliaryNode : public UGameTaskNode
{
	GENERATED_BODY()
public:
	UGameTaskAuxiliaryNode();
	
};
