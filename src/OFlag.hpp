//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"
#include <fcntl.h>

#ifndef __linux_posix_OFlag__
#define __linux_posix_OFlag__

namespace linux {
     namespace posix {
	  namespace oflag {
//////////////////////////////////////////////////////////////////
	       const flag_t CREAT     = O_CREAT;
	       const flag_t RDWR      = O_RDWR;
	       const flag_t RDONLY    = O_RDONLY;
	       const flag_t EXCL      = O_EXCL;
	       const flag_t TRUNC     = O_TRUNC;
	       const flag_t WRONLY    = O_WRONLY;
	       const flag_t APPEND    = O_APPEND;
	       const flag_t ASYNC     = O_ASYNC;
	       const flag_t CLOEXEC   = O_CLOEXEC;
	       const flag_t DIRECT    = O_DIRECT;
	       const flag_t DIRECTORY = O_DIRECTORY;
	       const flag_t DSYNC     = O_DSYNC;
	       const flag_t LARGEFILE = O_LARGEFILE;
	       const flag_t NOATIME   = O_NOATIME;
	       const flag_t NOCTTY    = O_NOCTTY;
	       const flag_t NOFOLLOW  = O_NOFOLLOW;
	       const flag_t NONBLOCK  = O_NONBLOCK;
	       const flag_t NDELAY    = O_NDELAY;
	       const flag_t PATH      = O_PATH;
	       const flag_t SYNC      = O_SYNC;
	       const flag_t TMPFILE   = O_TMPFILE;
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
