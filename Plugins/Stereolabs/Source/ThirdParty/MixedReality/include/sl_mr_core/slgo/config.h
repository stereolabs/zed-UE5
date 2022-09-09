#ifndef SLGO_CONFIG_H
#define SLGO_CONFIG_H


/* #undef SLGO_HAVE_OPENGL */
/* #undef SLGO_OPENGL_FOUND */
/* #undef SLGO_OPENMP */
//#define SLGO_SHARED_LIBS 0
//#define SLGO_LGPL_SHARED_LIBS 0

// available sparse matrix libraries
/* #undef SLGO_HAVE_CHOLMOD */
#define SLGO_HAVE_CSPARSE 1

//#ifdef _WIN32
//#define SLGO_CXX_COMPILER "MSVC C:/Program Files (x86)/Microsoft Visual Studio 12.0/VC/bin/x86_amd64/cl.exe"
//#else
//#define SLGO_CXX_COMPILER "GNU /usr/bin/c++"
//#endif

#ifdef __cplusplus
#include <sl_mr_core/slgo/core/eigen_types.h>
#endif

#endif
