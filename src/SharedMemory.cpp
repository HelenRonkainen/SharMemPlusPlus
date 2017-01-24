//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "SharedMemory.hpp"
#include "ErrorBuilder.hpp"
#include <sys/mman.h>
#include <errno.h>
#include <unistd.h>

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
	  close();
	  if (destroy) shm_unlink(name.c_str());
     }
}

linux::posix::
SharedMemory& linux::posix::SharedMemory::open() {
     fd = shm_open(name.c_str(),
		   options.get_oflag().get(),
		   options.get_mode().get());
     if (fd < 0) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
     return *this;
}

linux::posix::
SharedMemory& linux::posix::SharedMemory::close() {
     if (fd > 0) {
	  ::close(fd);
     }
     return *this;
}

linux::posix::
SharedMemory& linux::posix::SharedMemory::truncate(const size_t n) {
     int res = ftruncate(fd, n);
     if (res == -1) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
     return *this;
}
//////////////////////////////////////////////////////////////////
