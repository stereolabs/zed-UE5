//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Utilities/StereolabsTimer.h"

#include "HAL/ThreadingBase.h"

/* 
 * Base class for runnables allowing to start/pause/resume/stop a thread
 */
class STEREOLABS_API FSlRunnable : public FRunnable
{
public:
	FSlRunnable();
	virtual ~FSlRunnable();

	/*
	 * Start the thread
	 * @param Frequency The Frequency of the thread in seconds
	 */
	virtual void Start(float Frequency) { }

	virtual bool Init() override
	{
		bIsRunning = true;

		return true;
	}

	virtual void Stop() override
	{
		bIsRunning = false;
	}

	FORCEINLINE void EnsureCompletion()
	{
		if(!Thread)
		{
			return;
		}

		// Stop if running
		if (bIsRunning)
		{
			Stop();
		}

		// Awake if sleeping
		if (bIsSleeping)
		{
			Awake();
		}

		// Resume if paused
		if (bIsPaused)
		{
			Suspend(false);
		}

		Thread->WaitForCompletion();
	}

	/*
	 * Pause/Resume the thread
	 * @param bShouldPause True to pause the thread, false to resume
	 */
	FORCEINLINE void Suspend(bool bShouldPause = true)
	{
		Thread->Suspend(bShouldPause);
		bIsPaused = bShouldPause;
	}

	/*
	 * Set the thread to sleep
	 */
	FORCEINLINE void Sleep()
	{
		bIsSleeping = true;
	}

	/*
	 * Awake the thread
	 */
	FORCEINLINE void Awake()
	{
		bIsSleeping = false;
	}

	/*
	 * @return True if the thread is running
	 */
	FORCEINLINE bool IsRunning()
	{
		return bIsRunning;
	}

	/*
	 * @return True if the thread is paused
	 */
	FORCEINLINE bool IsPaused()
	{
		return bIsPaused;
	}

	/*
	 * @return True if the thread is sleeping
	 */
	FORCEINLINE bool IsSleeping()
	{
		return bIsSleeping;
	}

public:
	/** Current thread running the runnable */
	FRunnableThread* Thread;

protected:
	/** A timer for this runnable */
	FSlTimer Timer;

	/** True if the thread is running */
	bool bIsRunning;

	/** True if the thread is paused */
	bool bIsPaused;

	/** True if the thread is sleeping */
	bool bIsSleeping;
};