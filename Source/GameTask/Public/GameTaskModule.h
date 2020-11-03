#pragma once
#include "Modules/ModuleInterface.h"

/// 
class GAMETASK_API FGameTaskModule : public IModuleInterface {
public:
    void StartupModule() override;
    void ShutdownModule() override;
};
