// slgo - General Graph Optimization
// Copyright (C) 2012 Rainer Kuemmerle
// 
// slgo is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published
// by the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// slgo is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef SLGO_CSPARSE_EXTENSION_API_H
#define SLGO_CSPARSE_EXTENSION_API_H

#include "sl_mr_core/slgo/config.h"

#ifdef _MSC_VER
// We are using a Microsoft compiler:
#ifdef SLGO_LGPL_SHARED_LIBS
#ifdef csparse_extension_EXPORTS
#define SLGO_CSPARSE_EXTENSION_API __declspec(dllexport)
#else
#define SLGO_CSPARSE_EXTENSION_API __declspec(dllimport)
#endif
#else
#define SLGO_CSPARSE_EXTENSION_API
#endif

#else
// Not Microsoft compiler so set empty definition:
#define SLGO_CSPARSE_EXTENSION_API
#endif

#endif // SLGO_CSPARSE_API_H
