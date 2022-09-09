//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Misc/DateTime.h"

/*
 * A timer to measure threads loop time and get sleep time
 */
struct STEREOLABS_API FSlTimer
{
public:
	FSlTimer()
		:
		CycleTime(0.0),
		ExecTime(0.0),
		StartTime(0.0)
	{
	}

	/* 
	 * Set the frequency
	 * @param Frequency The frequency in seconds
	 */
	FORCEINLINE void SetFrequency(double Frequency)
	{
		CycleTime = 1.0 / Frequency * 1000.0;
	}

	/*
	 * Start the timer
	 */
	FORCEINLINE void Start()
	{
		StartTime = FDateTime::Now().GetTimeOfDay().GetTotalMilliseconds();
	}

	/*
	 * Stop the timer
	 */
	FORCEINLINE void Stop()
	{
		double StopTime = FDateTime::Now().GetTimeOfDay().GetTotalMilliseconds();
		ExecTime = StopTime - StartTime;
	}

	/*
	 * @return True if the timer stopped before one full cycle
	 */
	FORCEINLINE bool CanSleep() const
	{
		return (ExecTime < CycleTime);
	}

	/*
	 * @return The time needed to finish the cycle
	 */
	FORCEINLINE float GetSleepingTimeSeconds() const
	{
		return (CycleTime - ExecTime) / 1000.0f;
	}

private:
	/** Maximum time in milliseconds */
	double  CycleTime;

	/** Execution time in milliseconds */
	double  ExecTime;

	/** Start time in milliseconds */
	double  StartTime;
};