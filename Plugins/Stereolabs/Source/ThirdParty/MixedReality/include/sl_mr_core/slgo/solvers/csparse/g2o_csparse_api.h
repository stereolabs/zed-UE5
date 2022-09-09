/***************************************************************************
 *  Description: import/export macros for creating DLLS with Microsoft
 *	compiler. Any exported function needs to be declared with the
 *  appropriate SLGO_XXXX_API macro. Also, there must be separate macros
 *  for each DLL (arrrrrgh!!!)
 *
 *  17 Jan 2012
 *  Email: pupilli@cs.bris.ac.uk
 ****************************************************************************/
#ifndef SLGO_SOLVER_CSPARSE_API_H
#define SLGO_SOLVER_CSPARSE_API_H

#include "sl_mr_core/slgo/config.h"

#ifdef _MSC_VER
// We are using a Microsoft compiler:
#ifdef SLGO_SHARED_LIBS
#ifdef solver_csparse_EXPORTS
#define SLGO_SOLVER_CSPARSE_API __declspec(dllexport)
#else
#define SLGO_SOLVER_CSPARSE_API __declspec(dllimport)
#endif
#else
#define SLGO_SOLVER_CSPARSE_API
#endif

#else
// Not Microsoft compiler so set empty definition:
#define SLGO_SOLVER_CSPARSE_API
#endif

#endif // SLGO_CSPARSE_API_H
