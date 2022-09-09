//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#include "Stereolabs/Public/Threading/StereolabsRunnable.h"
#include "StereolabsPrivatePCH.h"

FSlRunnable::FSlRunnable()
	:
	Thread(nullptr),
	bIsRunning(false),
	bIsPaused(false),
	bIsSleeping(false)
{
}

FSlRunnable::~FSlRunnable()
{
	delete Thread;
	Thread = nullptr;
}