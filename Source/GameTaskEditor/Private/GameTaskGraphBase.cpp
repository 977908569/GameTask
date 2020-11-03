#include "GameTaskGraphBase.h"

#include "GameTaskGraphNodeBase.h"

UGameTaskGraphBase::UGameTaskGraphBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer),
	GraphVersion(0)
{
	bLockUpdates = false;
}

void UGameTaskGraphBase::UpdateAsset(int32 UpdateFlags)
{
	// empty in base class
}

void UGameTaskGraphBase::OnCreated()
{
	MarkVersion();
}

void UGameTaskGraphBase::OnLoaded()
{
	UpdateDeprecatedClasses();
	UpdateUnknownNodeClasses();
}

void UGameTaskGraphBase::Initialize()
{
	UpdateVersion();
}

void UGameTaskGraphBase::UpdateVersion()
{
	if (GraphVersion == 1)
	{
		return;
	}

	MarkVersion();
	Modify();
}

void UGameTaskGraphBase::MarkVersion()
{
	GraphVersion = 1;
}

bool UGameTaskGraphBase::UpdateUnknownNodeClasses()
{
	bool bUpdated = false;
	for (int32 NodeIdx = 0; NodeIdx < Nodes.Num(); NodeIdx++)
	{
		UGameTaskGraphNodeBase* MyNode = Cast<UGameTaskGraphNodeBase>(Nodes[NodeIdx]);
		if (MyNode)
		{
			const bool bUpdatedNode = MyNode->RefreshNodeClass();
			bUpdated = bUpdated || bUpdatedNode;

			for (int32 SubNodeIdx = 0; SubNodeIdx < MyNode->SubNodes.Num(); SubNodeIdx++)
			{
				if (MyNode->SubNodes[SubNodeIdx])
				{
					const bool bUpdatedSubNode = MyNode->SubNodes[SubNodeIdx]->RefreshNodeClass();
					bUpdated = bUpdated || bUpdatedSubNode;
				}
			}
		}
	}

	return bUpdated;
}

void UpdateAIGraphNodeErrorMessage(UGameTaskGraphNodeBase& Node)
{
	// Broke out setting error message in to own function so it can be reused when iterating nodes collection.
	if (Node.NodeInstance)
	{
		Node.ErrorMessage = FGameTaskGraphNodeClassHelper::GetDeprecationMessage(Node.NodeInstance->GetClass());
	}
	else
	{
		// Null instance. Do we have any meaningful class data?
		FString StoredClassName = Node.ClassData.GetClassName();
		StoredClassName.RemoveFromEnd(TEXT("_C"));

		if (!StoredClassName.IsEmpty())
		{
			// There is class data here but the instance was not be created.
			static const FString IsMissingClassMessage(" class missing. Referenced by ");
			Node.ErrorMessage = StoredClassName + IsMissingClassMessage + Node.GetFullName();
		}
	}

	if (Node.HasErrors())
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), *Node.ErrorMessage);
	}
}

void UGameTaskGraphBase::UpdateDeprecatedClasses()
{
	// This function sets error messages and logs errors about nodes.

	for (int32 Idx = 0, IdxNum = Nodes.Num(); Idx < IdxNum; ++Idx)
	{
		UGameTaskGraphNodeBase* Node = Cast<UGameTaskGraphNodeBase>(Nodes[Idx]);
		if (Node != nullptr)
		{
			UpdateAIGraphNodeErrorMessage(*Node);

			for (int32 SubIdx = 0, SubIdxNum = Node->SubNodes.Num(); SubIdx < SubIdxNum; ++SubIdx)
			{
				if (Node->SubNodes[SubIdx] != nullptr)
				{
					UpdateAIGraphNodeErrorMessage(*Node->SubNodes[SubIdx]);
				}
			}
		}
	}
}

void UGameTaskGraphBase::Serialize(FArchive& Ar)
{
	// Overridden to flags up errors in the behavior tree while cooking.
	Super::Serialize(Ar);

	if (Ar.IsSaving() || Ar.IsCooking())
	{
		// Logging of errors happens in UpdateDeprecatedClasses
		UpdateDeprecatedClasses();
	}
}

void UGameTaskGraphBase::UpdateClassData()
{
	for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
	{
		UGameTaskGraphNodeBase* Node = Cast<UGameTaskGraphNodeBase>(Nodes[Idx]);
		if (Node)
		{
			Node->UpdateNodeClassData();

			for (int32 SubIdx = 0; SubIdx < Node->SubNodes.Num(); SubIdx++)
			{
				if (Node->SubNodes[SubIdx])
				{
					Node->UpdateNodeClassData();
				}
			}
		}
	}
}

void UGameTaskGraphBase::CollectAllNodeInstances(TSet<UObject*>& NodeInstances)
{
	for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
	{
		UGameTaskGraphNodeBase* MyNode = Cast<UGameTaskGraphNodeBase>(Nodes[Idx]);
		if (MyNode)
		{
			NodeInstances.Add(MyNode->NodeInstance);

			for (int32 SubIdx = 0; SubIdx < MyNode->SubNodes.Num(); SubIdx++)
			{
				if (MyNode->SubNodes[SubIdx])
				{
					NodeInstances.Add(MyNode->SubNodes[SubIdx]->NodeInstance);
				}
			}
		}
	}
}

bool UGameTaskGraphBase::CanRemoveNestedObject(UObject* TestObject) const
{
	return !TestObject->IsA(UEdGraphNode::StaticClass()) &&
		!TestObject->IsA(UEdGraph::StaticClass()) &&
		!TestObject->IsA(UEdGraphSchema::StaticClass());
}

void UGameTaskGraphBase::RemoveOrphanedNodes()
{
	TSet<UObject*> NodeInstances;
	CollectAllNodeInstances(NodeInstances);

	NodeInstances.Remove(nullptr);

	// Obtain a list of all nodes actually in the asset and discard unused nodes
	TArray<UObject*> AllInners;
	const bool bIncludeNestedObjects = false;
	GetObjectsWithOuter(GetOuter(), AllInners, bIncludeNestedObjects);
	for (auto InnerIt = AllInners.CreateConstIterator(); InnerIt; ++InnerIt)
	{
		UObject* TestObject = *InnerIt;
		if (!NodeInstances.Contains(TestObject) && CanRemoveNestedObject(TestObject))
		{
			OnNodeInstanceRemoved(TestObject);

			TestObject->SetFlags(RF_Transient);
			TestObject->Rename(NULL, GetTransientPackage(), REN_DontCreateRedirectors | REN_NonTransactional | REN_ForceNoResetLoaders);
		}
	}
}

void UGameTaskGraphBase::OnNodeInstanceRemoved(UObject* NodeInstance)
{
	// empty in base class
}

void UGameTaskGraphBase::OnNodesPasted(const FString& ImportStr)
{
	// empty in base class
}

UEdGraphPin* UGameTaskGraphBase::FindGraphNodePin(UEdGraphNode* Node, EEdGraphPinDirection Dir)
{
	UEdGraphPin* Pin = nullptr;
	for (int32 Idx = 0; Idx < Node->Pins.Num(); Idx++)
	{
		if (Node->Pins[Idx]->Direction == Dir)
		{
			Pin = Node->Pins[Idx];
			break;
		}
	}

	return Pin;
}

bool UGameTaskGraphBase::IsLocked() const
{
	return bLockUpdates;
}

void UGameTaskGraphBase::LockUpdates()
{
	bLockUpdates = true;
}

void UGameTaskGraphBase::UnlockUpdates()
{
	bLockUpdates = false;
	UpdateAsset();
}

void UGameTaskGraphBase::OnSubNodeDropped()
{
	NotifyGraphChanged();
}
