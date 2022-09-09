//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Engine/GameViewportClient.h"

#include "ZEDGameViewportClient.generated.h"

UCLASS()
class ZED_API UZEDGameViewportClient : public UGameViewportClient
{
	GENERATED_UCLASS_BODY()

public:
	virtual ~UZEDGameViewportClient();

public:
	virtual void Draw(FViewport* Viewport, FCanvas* SceneCanvas) override;

private:
	/** Current buffer visualization mode for this game viewport */
	FName CurrentBufferVisualizationMode;

	/** Delegate called when the engine starts drawing a game viewport */
	FSimpleMulticastDelegate BeginDrawDelegate;

	/** Delegate called when the game viewport is drawn, before drawing the console */
	FSimpleMulticastDelegate DrawnDelegate;

	/** Delegate called when the engine finishes drawing a game viewport */
	FSimpleMulticastDelegate EndDrawDelegate;

	/** Whether or not this audio device is in audio-focus */
	bool bHasAudioFocus;
};