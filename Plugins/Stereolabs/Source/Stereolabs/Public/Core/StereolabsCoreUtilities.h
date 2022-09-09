//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Misc/ScopeTryLock.h"

#define SL_SCOPE_LOCK(LockName, CriticalSection)\
	{\
		FScopeLock LockName(&CriticalSection);

#define  SL_SCOPE_UNLOCK\
	}\

#define SL_SCOPE_TRY_LOCK(LockName, CriticalSection)\
	{\
		FScopeTryLock LockName(&CriticalSection);\
		if(LockName.IsLocked())\
		{\

#define SL_SCOPE_TRY_UNLOCK\
		}\
	}\

#if WITH_EDITOR
/*
 * Log
 */
#define SL_LOG(LogCategory, Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
	const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(LogCategory, Log, TEXT("%s"), *Msg);\
    CLEAR_WARN_COLOR();\
}

/*
 * Warning
 */
#define SL_LOG_W(LogCategory, Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
	const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(LogCategory, Warning, TEXT("%s"), *Msg);\
    CLEAR_WARN_COLOR();\
}

/*
 * Error
 */
#define SL_LOG_E(LogCategory, Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
	const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(LogCategory, Error, TEXT("%s"), *Msg);\
    CLEAR_WARN_COLOR();\
}

/*
 * Fatal
 */
#define SL_LOG_F(LogCategory, Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
	const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(LogCategory, Fatal, TEXT("%s"), *Msg);\
    CLEAR_WARN_COLOR();\
}
#else
#define SL_LOG(LogCategory, Format, ...)
#define SL_LOG_W(LogCategory, Format, ...)
#define SL_LOG_E(LogCategory, Format, ...)
#define SL_LOG_F(LogCategory, Format, ...)
#endif

DECLARE_STATS_GROUP(TEXT("ZED"), STATGROUP_ZED, STATCAT_Advanced);