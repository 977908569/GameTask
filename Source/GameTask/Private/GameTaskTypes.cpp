#include "GameTaskTypes.h"
#include "GameTaskNode.h"
#include "GameTask.h"

FString UGameTaskTypes::DescribeNodeHelper(const UGameTaskNode* Node)
{
	return Node ? FString::Printf(TEXT("%s::%s"), *GetNameSafe(Node->GetGameTaskAsset()), *Node->GetNodeName()) : FString();
}

FString UGameTaskTypes::DescribeNodeResult(ENodeState NodeResult)
{
	static FString ResultDesc[] = { TEXT("Normal"),TEXT("InProgress"), TEXT("Succeeded"), TEXT("Failed") };
	return ResultDesc[static_cast<int32>(NodeResult)];
}

FString UGameTaskTypes::GetShortTypeName(const UObject* Ob)
{
	if (Ob->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
	{
		return Ob->GetClass()->GetName().LeftChop(2);
	}

	FString TypeDesc = Ob->GetClass()->GetName();
	const int32 ShortNameIdx = TypeDesc.Find(TEXT("_"), ESearchCase::CaseSensitive);
	if (ShortNameIdx != INDEX_NONE)
	{
		TypeDesc.MidInline(ShortNameIdx + 1, MAX_int32, false);
	}

	return TypeDesc;
}
