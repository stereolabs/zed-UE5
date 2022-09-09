//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once
#include "Engine/GameInstance.h" 

#include "ZEDGameInstance.generated.h"

UCLASS()
class UZEDGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Shutdown() override;

#if WITH_EDITOR
	virtual FGameInstancePIEResult InitializeForPlayInEditor(int32 PIEInstanceIndex, const FGameInstancePIEParameters& Params) override;
	virtual FGameInstancePIEResult StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params) override;
#endif
};