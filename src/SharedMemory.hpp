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
			    const UNLINK_AFTER_DESTROY = true,
			    const OpenOptions = OpenOptions());
	       ~SharedMemory();

	       SharedMemory(const SharedMemory&) = delete;
	       SharedMemory& operator=(const SharedMemory&) = delete;
	       SharedMemory(const SharedMemory&&) = delete;
	       SharedMemory& operator=(const SharedMemory&&) = delete;

	       SharedMemory& open();
	       SharedMemory& close();
	       SharedMemory& truncate(const size_t);

	  private:
	       const Name name;
	       OpenOptions options;
	       const UNLINK_AFTER_DESTROY destroy;

	       int fd;
	       size_t size;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_SharedMemory__
