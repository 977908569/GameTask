#pragma once
#include "GameTaskEditorGraphTypes.h"
#include "GameTaskGraphNodeBase.generated.h"

UCLASS()
class GAMETASKEDITOR_API UGameTaskGraphNodeBase : public UEdGraphNode
{
	GENERATED_UCLASS_BODY()
public:

	/** instance class */
	UPROPERTY()
		struct FGameTaskGraphNodeClassData ClassData;

	UPROPERTY()
		UObject* NodeInstance;

	UPROPERTY(transient)
		UGameTaskGraphNodeBase* ParentNode;

	UPROPERTY()
		TArray<UGameTaskGraphNodeBase*> SubNodes;

	/** subnode index assigned during copy operation to connect nodes again on paste */
	UPROPERTY()
		int32 CopySubNodeIndex;

	/** if set, all modifications (including delete/cut) are disabled */
	UPROPERTY()
		uint32 bIsReadOnly : 1;

	/** if set, this node will be always considered as subnode */
	UPROPERTY()
		uint32 bIsSubNode : 1;

	/** error message for node */
	UPROPERTY()
		FString ErrorMessage;

	//~ Begin UEdGraphNode Interface
	virtual class UGameTaskGraphBase* GetGameTaskGraph();
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;
	virtual void PostPlacedNewNode() override;
	virtual void PrepareForCopying() override;
	virtual bool CanDuplicateNode() const override;
	virtual bool CanUserDeleteNode() const override;
	virtual void DestroyNode() override;
	virtual FText GetTooltipText() const override;
	virtual void NodeConnectionListChanged() override;
	virtual bool CanCreateUnderSpecifiedSchema(const UEdGraphSchema* DesiredSchema) const override;
	virtual void FindDiffs(class UEdGraphNode* OtherNode, struct FDiffResults& Results) override;
	virtual FString GetPropertyNameAndValueForDiff(const FProperty* Prop, const uint8* PropertyAddr) const override;
	//~ End UEdGraphNode Interface

	//~ Begin UObject Interface
#if WITH_EDITOR
	virtual void PostEditImport() override;
	virtual void PostEditUndo() override;
#endif
	// End UObject

	// @return the input pin for this state
	virtual UEdGraphPin* GetInputPin(int32 InputIndex = 0) const;
	// @return the output pin for this state
	virtual UEdGraphPin* GetOutputPin(int32 InputIndex = 0) const;
	virtual UEdGraph* GetBoundGraph() const { return NULL; }

	virtual FText GetDescription() const;
	virtual void PostCopyNode();

	void AddSubNode(UGameTaskGraphNodeBase* SubNode, class UEdGraph* ParentGraph);
	void RemoveSubNode(UGameTaskGraphNodeBase* SubNode);
	virtual void RemoveAllSubNodes();
	virtual void OnSubNodeRemoved(UGameTaskGraphNodeBase* SubNode);
	virtual void OnSubNodeAdded(UGameTaskGraphNodeBase* SubNode);

	virtual int32 FindSubNodeDropIndex(UGameTaskGraphNodeBase* SubNode) const;
	virtual void InsertSubNodeAt(UGameTaskGraphNodeBase* SubNode, int32 DropIndex);

	/** check if node is subnode */
	virtual bool IsSubNode() const;

	/** initialize instance object  */
	virtual void InitializeInstance();

	/** reinitialize node instance */
	virtual bool RefreshNodeClass();

	/** updates ClassData from node instance */
	virtual void UpdateNodeClassData();

	/** Check if node instance uses blueprint for its implementation */
	bool UsesBlueprint() const;

	/** check if node has any errors, used for assigning colors on graph */
	virtual bool HasErrors() const;

	static void UpdateNodeClassDataFrom(UClass* InstanceClass, FGameTaskGraphNodeClassData& UpdatedData);

protected:

	virtual void ResetNodeOwner();
};
