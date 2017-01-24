//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"
#include <sys/mman.h>

#ifndef __linux_posix_Protection__
#define __linux_posix_Protection__

namespace linux {
     namespace posix {
	  namespace mmap {
//////////////////////////////////////////////////////////////////
	       const flag_t NONE  = PROT_NONE;
	       const flag_t EXEC  = PROT_EXEC;
	       const flag_t READ  = PROT_READ;
	       const flag_t WRITE = PROT_WRITE;
//////////////////////////////////////////////////////////////////
	  }
     }
}

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class Protection {

	  public:
	       Protection() {
		    using namespace mmap;
		    flag = (READ | WRITE);
	       }

	       Protection(const flag_t f) { flag = f; }
	       ~Protection() = default;

	       flag_t get() const { return flag; }

	       Protection& add(const flag_t f) {
		    flag = flag | f;
		    return *this;
	       }

	  private:
	       flag_t flag;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_Protection__
