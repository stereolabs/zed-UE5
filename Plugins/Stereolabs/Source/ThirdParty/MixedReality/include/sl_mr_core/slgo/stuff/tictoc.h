// slgo - General Graph Optimization
// Copyright (C) 2011 R. Kuemmerle, G. Grisetti, W. Burgard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
// TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef SLGO_TICTOC_H
#define SLGO_TICTOC_H

#include "g2o_stuff_api.h"

#include <string>

namespace sl_mr_g2o {

  /**
   * \brief Profile the timing of certain parts of your algorithm.
   *
   * Profile the timing of certain parts of your algorithm.
   * A typical use-case is as follows:
   *
   * tictoc("doSomething");
   * // place the code here.
   * tictoc("doSomething");
   *
   * This will calculate statistics for the operations within
   * the two calls to tictoc()
   *
   * If the environment variable SLGO_ENABLE_TICTOC is defined, the timing will
   * be performed.
   */
   SLGO_STUFF_API double tictoc(const char* algorithmPart);

   /**
    * \brief Simplify calls to tictoc() for a whole scope
    *
    * See also the macro SLGO_SCOPED_TICTOC below.
    */
   class SLGO_STUFF_API ScopedTictoc
   {
     public:
       ScopedTictoc(const char* algorithmPart);
       ~ScopedTictoc();
     protected:
       std::string _algorithmPart;
   };

} // end namespace

#ifndef SLGO_SCOPED_TICTOC
#define SLGO_SCOPED_TICTOC(s) \
  g2o::ScopedTictoc scopedTictoc (s)
#endif

#endif
