#pragma once
#include "GameTaskTypes.generated.h"
/**
 *Current entry status
 */
UENUM(BlueprintType)
enum class ENodeState : uint8
{
	Normal,//空闲
	InProgress,//执行中
	Succeeded,//成功
	Failed,//失败
};


class UGameTaskNode;
UCLASS(Abstract)
class GAMETASK_API UGameTaskTypes : public UObject
{
	GENERATED_BODY()

		static FString GameTaskLoggingContext;
public:
	static FString DescribeNodeHelper(const UGameTaskNode* Node);
	static FString DescribeNodeResult(ENodeState NodeResult);
	static FString GetShortTypeName(const UObject* Ob);
};