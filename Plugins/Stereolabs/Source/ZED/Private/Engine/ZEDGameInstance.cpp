//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "ZED/Classes/ZEDGameInstance.h"
#include "ZEDPrivatePCH.h"
#include "Stereolabs/Public/Core/StereolabsCameraProxy.h"

#if WITH_EDITOR
void InitializeCameraProxy(UZEDGameInstance& GameInstance)
{
	// Uncomment if dedicated server is not supported
	//if (GEngine && GWorld)
	//{
	//	ENetMode Mode = GEngine->GetNetMode(GWorld);
	//
	//	if (Mode == ENetMode::NM_Client ||
	//		Mode == ENetMode::NM_Standalone ||
	//		Mode == ENetMode::NM_ListenServer)
	//	{
			CreateSlCameraProxyInstance();
	//	}
	//}
}
#endif

void UZEDGameInstance::Init()
{
	Super::Init();

	// Uncomment if dedicated server is not supported
	//if (!IsDedicatedServerInstance())
	//{
		CreateSlCameraProxyInstance();
	//}
}

void UZEDGameInstance::Shutdown()
{
	FreeSlCameraProxyInstance();

	if (GEngine)
	{
		GEngine->ForceGarbageCollection(true);
	}

	Super::Shutdown();
}

#if WITH_EDITOR
FGameInstancePIEResult UZEDGameInstance::InitializeForPlayInEditor(int32 PIEInstanceIndex, const FGameInstancePIEParameters& Params)
{
	FGameInstancePIEResult Result = Super::InitializeForPlayInEditor(PIEInstanceIndex, Params);

	if (Result.bSuccess)
	{
		InitializeCameraProxy(*this);
	}

	return Result;
}

FGameInstancePIEResult UZEDGameInstance::StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params)
{
	FGameInstancePIEResult Result = Super::StartPlayInEditorGameInstance(LocalPlayer, Params);

	if (Result.bSuccess)
	{
		InitializeCameraProxy(*this);
	}

	return Result;
}
#endif