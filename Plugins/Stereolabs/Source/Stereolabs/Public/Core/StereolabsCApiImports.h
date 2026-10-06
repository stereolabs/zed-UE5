//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsCoreGlobals.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/WindowsHWrapper.h"
#include <delayimp.h>
#include "Windows/HideWindowsPlatformTypes.h"

namespace SlCApiImports
{
	inline LONG Filter(const EXCEPTION_POINTERS* Exception, const ANSICHAR*& OutMissingFunction)
	{
		const DWORD Code = Exception->ExceptionRecord->ExceptionCode;

		if (Code == VcppException(ERROR_SEVERITY_ERROR, ERROR_PROC_NOT_FOUND))
		{
			const DelayLoadInfo* Info = reinterpret_cast<const DelayLoadInfo*>(Exception->ExceptionRecord->ExceptionInformation[0]);
			OutMissingFunction = Info->dlp.fImportByName ? Info->dlp.szProcName : "(import by ordinal)";
			return EXCEPTION_EXECUTE_HANDLER;
		}

		return Code == VcppException(ERROR_SEVERITY_ERROR, ERROR_MOD_NOT_FOUND) ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH;
	}

	// No object with a destructor in this frame, __try does not allow it
	inline bool BindAll(const ANSICHAR*& OutMissingFunction)
	{
		__try
		{
			// Returns a failure without raising when the calling binary imports nothing from the DLL
			__HrLoadAllImportsForDll("sl_zed_c.dll");
			return true;
		}
		__except (Filter(GetExceptionInformation(), OutMissingFunction))
		{
			return false;
		}
	}
}
#endif

/**
 * sl_zed_c.dll is delay loaded, so a function missing from an older DLL only shows up as a crash on its first call.
 * This binds every sl_zed_c import of the calling binary now and clears GSlCApiAvailable if one is missing.
 * Delay-load tables are per binary: call it from the StartupModule() of every module that calls the C API.
 */
inline void SlBindCApiImports(const TCHAR* ModuleName)
{
#if PLATFORM_WINDOWS
	if (!GSlCApiAvailable)
	{
		return;
	}

	const ANSICHAR* MissingFunction = nullptr;
	if (!SlCApiImports::BindAll(MissingFunction))
	{
		SlSetCApiUnavailable(ModuleName, MissingFunction);
	}
#endif
}
