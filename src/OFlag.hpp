//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <fcntl.h>

#ifndef __linux_posix_OFlag__
#define __linux_posix_OFlag__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  using flag_t = int;
//////////////////////////////////////////////////////////////////
     }
}

namespace linux {
     namespace posix {
	  namespace oflag {
//////////////////////////////////////////////////////////////////
	       const flag_t CREAT  = O_CREAT;
	       const flag_t RDWR   = O_RDWR;
	       const flag_t RDONLY = O_RDONLY;
	       const flag_t EXCL   = O_EXCL;
	       const flag_t TRUNC  = O_TRUNC;
//////////////////////////////////////////////////////////////////
	  }
     }
}

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class OFlag {

	  public:
	       OFlag() {
		    using namespace oflag;
		    flag = (CREAT | RDWR);
	       }

	       OFlag(const flag_t f) { flag = f; }
	       ~OFlag() = default;

	       flag_t get() const { return flag; }

	       OFlag& add(const flag_t f) {
		    flag = flag | f;
		    return *this;
	       }

	  private:
	       flag_t flag;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_OFlag__
