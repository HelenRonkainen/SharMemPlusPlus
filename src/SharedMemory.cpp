//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "SharedMemory.hpp"
#include <sys/mman.h>

//////////////////////////////////////////////////////////////////
linux::posix::
SharedMemory::SharedMemory(const Name n,
			   const OpenOptions oo,
			   UNLINK_AFTER_DESTROY d):
     name(n),
     options(oo),
     destroy(d),
     fd(0)
{
     return;
}

linux::posix::
SharedMemory::~SharedMemory() {
     if (fd > 0) {
	  if (destroy) shm_unlink(name.c_str());
     }
}
//////////////////////////////////////////////////////////////////
