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
			   UNLINK_AFTER_DESTROY d,
			   const OpenOptions oo):
     name(n),
     options(oo),
     destroy(d),
     fd(0),
     size(0)
{
     return;
}

linux::posix::
SharedMemory::~SharedMemory() {
     if (fd > 0) ::close(fd);
     if (destroy) shm_unlink(name.c_str());
}

linux::posix::
SharedMemory& linux::posix::SharedMemory::open() {
     fd = shm_open(name.c_str(),
		   options.get_oflag().get(),
		   options.get_mode().get());
     if (fd == -1) error(errno);
     return *this;
}

linux::posix::
SharedMemory& linux::posix::SharedMemory::close() {
     int res = ::close(fd);
     if (res == -1) error(errno);
     return *this;
}

linux::posix::
SharedMemory& linux::posix::SharedMemory::truncate(const size_t n) {
     size = 0;
     int res = ftruncate(fd, n);
     if (res == -1) error(errno);
     size = n;
     return *this;
}

void linux::posix::SharedMemory::error(const int n) const {
     ErrorBuilder eb;
     throw eb.build(n);
}
//////////////////////////////////////////////////////////////////
