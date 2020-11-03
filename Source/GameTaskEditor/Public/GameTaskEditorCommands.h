// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameTaskEditorStyle.h"
#include "Framework/Commands/Commands.h"
class FGameTaskEditorCommands : public TCommands<FGameTaskEditorCommands>
{
public:

	FGameTaskEditorCommands()
		: TCommands<FGameTaskEditorCommands>(TEXT("GameTask"), NSLOCTEXT("Contexts", "GameTask", "GameTask Plugin"), NAME_None, FGameTaskEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:

};