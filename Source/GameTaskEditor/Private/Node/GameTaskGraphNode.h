#pragma once
#include "Graph/GameTaskGraph.h"
#include "GameTaskGraphNodeBase.h"
#include "GameTaskGraphNode.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNode : public UGameTaskGraphNodeBase
{
	GENERATED_UCLASS_BODY()
public:
	bool bDragEnter = true;
	
	//~ Begin UEdGraphNode Interface
	virtual UGameTaskGraph* GetGameTaskGraph();
	virtual void AllocateDefaultPins() override;
	virtual FText GetTooltipText() const override;
	virtual bool CanCreateUnderSpecifiedSchema(const UEdGraphSchema* DesiredSchema) const override;
	virtual void FindDiffs(class UEdGraphNode* OtherNode, struct FDiffResults& Results) override;
	//~ End UEdGraphNode Interface

#if WITH_EDITOR
	virtual void PostEditUndo() override;
#endif
	
	virtual FText GetDescription() const override;
	virtual void InitializeInstance() override;

	virtual bool CanPlaceBreakpoints() const { return false; }
	virtual FName GetNameIcon() const;

protected:
	void CreateAddEventSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;
	void AddContextMenuActionsEvents(class UToolMenu* Menu, const FName SectionName, class UGraphNodeContextMenuContext* Context) const;
};