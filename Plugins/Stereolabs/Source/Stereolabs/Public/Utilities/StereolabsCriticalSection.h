//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"
#include "HAL/ThreadSafeBool.h"
#include "HAL/CriticalSection.h"
#include "StereolabsCriticalSection.generated.h"

/*
 * Critical section in blueprint
 */
UCLASS(BlueprintType, Category = "Stereolabs")
class STEREOLABS_API USlCriticalSection : public UObject
{
	GENERATED_BODY()

public:
	virtual void BeginDestroy() override
	{
		Unlock();

		Super::BeginDestroy();
	}

public:
	UFUNCTION(BlueprintCallable, Category = "Stereolabs|Critical Section")
	static USlCriticalSection* CreateCriticalSection()
	{
		return NewObject<USlCriticalSection>();
	}

	/*
	 * Lock the section
	 */
	UFUNCTION(BlueprintCallable)
	void Lock()
	{
		CriticalSection.Lock();
		bIsLocked = true;
	}

	/*
	 * Try to lock the section
	 * @return True if locked
	 */
	UFUNCTION(BlueprintCallable)
	bool TryLock()
	{
		bIsLocked = CriticalSection.TryLock();
		return bIsLocked;
	}

	/*
	 * Unlock the section
	 */
	UFUNCTION(BlueprintCallable)
	void Unlock()
	{
		CriticalSection.Unlock();
		bIsLocked = false;
	}

	/*
	 * @return True if locked
	 */
	UFUNCTION(BlueprintCallable)
	bool IsLocked()
	{
		return bIsLocked;
	}

private:
	/** Underlying critical section */
	FCriticalSection CriticalSection;

	/** True if locked */
	FThreadSafeBool bIsLocked;
};