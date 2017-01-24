//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"
#include <sys/mman.h>

#ifndef __linux_posix_MFlag__
#define __linux_posix_MFlag__

namespace linux {
     namespace posix {
	  namespace mmap {
//////////////////////////////////////////////////////////////////
	       const flag_t MSHARED        = MAP_SHARED;
	       const flag_t MPRIVATE       = MAP_PRIVATE;
	       const flag_t M32BIT         = MAP_32BIT;
	       const flag_t MANONYMOUS     = MAP_ANONYMOUS;
	       const flag_t MDENYWRITE     = MAP_DENYWRITE;
	       const flag_t MEXECUTABLE    = MAP_EXECUTABLE;
	       const flag_t MFILE          = MAP_FILE;
	       const flag_t MFIXED         = MAP_FIXED;
	       const flag_t MGROWSDOWN     = MAP_GROWSDOWN;
	       const flag_t MHUGETLB       = MAP_HUGETLB;
	       const flag_t MLOCKED        = MAP_LOCKED;
	       const flag_t MNONBLOCK      = MAP_NONBLOCK;
	       const flag_t MNORESERVE     = MAP_NORESERVE;
	       const flag_t MPOPULATE      = MAP_POPULATE;
	       const flag_t MSTACK         = MAP_STACK;
//////////////////////////////////////////////////////////////////
	  }
     }
}

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class MFlag {

	  public:
	       MFlag() {
		    using namespace mmap;
		    flag = MSHARED;
	       }

	       MFlag(const flag_t f) { flag = f; }
	       ~MFlag() = default;

	       flag_t get() const { return flag; }

	       MFlag& add(const flag_t f) {
		    flag = flag | f;
		    return *this;
	       }

	  private:
	       flag_t flag;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_MFlag__
