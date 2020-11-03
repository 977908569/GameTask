#pragma once
class FGameTaskDebugger : FTickableGameObject
{
public:
	FGameTaskDebugger();
	virtual ~FGameTaskDebugger();

	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;
	
};