#pragma once
#include "GameTaskTypes.generated.h"
/**
 *Current entry status
 */
UENUM(BlueprintType)
enum class GameTaskNodeStateType : uint8
{
	Disable,
	Progress,
	Finish,
	Fail,
};


class UGameTaskNode;
UCLASS(Abstract)
class GAMETASK_API UGameTaskTypes : public UObject
{
	GENERATED_BODY()

		static FString GameTaskLoggingContext;

public:

	static FString DescribeNodeHelper(const UGameTaskNode* Node);

	static FString DescribeNodeResult(GameTaskNodeStateType NodeResult);

	static FString GetShortTypeName(const UObject* Ob);
};