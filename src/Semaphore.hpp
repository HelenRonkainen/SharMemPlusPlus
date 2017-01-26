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
#include <semaphore.h>

#ifndef __linux_posix_Semaphore__
#define __linux_posix_Semaphore__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class Semaphore {

	  public:
	       Semaphore(const Name,
			 const UNLINK_AFTER_DESTROY = false,
			 const OpenOptions = OpenOptions(),
			 unsigned int = 1);
	       ~Semaphore();

	       Semaphore(const Semaphore&) = delete;
	       Semaphore& operator=(const Semaphore&) = delete;
	       Semaphore(const Semaphore&&) = delete;
	       Semaphore& operator=(const Semaphore&&) = delete;

	       void open();
	       void close() const;
	       void post() const;
	       void wait() const;
	       int get() const;

	  private:
	       const Name name;
	       const UNLINK_AFTER_DESTROY destroy;
	       OpenOptions options;
	       const unsigned int value;

	       sem_t* semaphore;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_Semaphore__
