//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"
#include "Name.hpp"
#include "OpenOptions.hpp"

#ifndef __linux_posix_SharedMemory__
#define __linux_posix_SharedMemory__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class SharedMemory {

	       friend class MMaper;

	  public:
	       SharedMemory(const Name,
			    const size_t = 0,
			    const UNLINK_AFTER_DESTROY = false,
			    const OpenOptions = OpenOptions());
	       ~SharedMemory();

	       SharedMemory(const SharedMemory&) = delete;
	       SharedMemory& operator=(const SharedMemory&) = delete;
	       SharedMemory(const SharedMemory&&) = delete;
	       SharedMemory& operator=(const SharedMemory&&) = delete;

	       SharedMemory& open();
	       SharedMemory& close();
	       SharedMemory& truncate();
	       SharedMemory& unlink();

	       size_t fd_size() const;

	  private:
	       const Name name;
	       OpenOptions options;
	       const UNLINK_AFTER_DESTROY destroy;

	       int fd;
	       const size_t size;

	       void error(const int) const;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_SharedMemory__
