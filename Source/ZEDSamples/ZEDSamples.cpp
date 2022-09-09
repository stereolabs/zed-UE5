// Fill out your copyright notice in the Description page of Project Settings.

#include "ZEDSamples.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, ZEDSamples, "ZEDSamples" );

//IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MyGame, "MyGame" );
class FZEDSamplesModule : public FDefaultGameModuleImpl
{
#if    WITH_EDITOR
	virtual void StartupModule() override
	{
		FModuleManager::Get().LoadModule(TEXT("BlueprintGraph"));
		FModuleManager::Get().LoadModule(TEXT("AnimGraph"));
		FModuleManager::Get().LoadModule(TEXT("ZEDSamplesEditor"));
	}
#endif
};
