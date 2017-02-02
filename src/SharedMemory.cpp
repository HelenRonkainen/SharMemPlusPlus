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
			   const size_t s,
			   UNLINK_AFTER_DESTROY d,
			   const OpenOptions oo):
     name(n),
     options(oo),
     destroy(d),
     fd(0),
     size(s)
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
SharedMemory& linux::posix::SharedMemory::truncate() {
     int res = ftruncate(fd, size);
     if (res == -1) error(errno);
     return *this;
}

size_t linux::posix::SharedMemory::fd_size() const {
     struct stat buffer;
     int res = fstat(fd, &buffer);
     if (res == -1) error(errno);
     return buffer.st_size;
}

void linux::posix::SharedMemory::error(const int n) const {
     ErrorBuilder eb;
     throw eb.build(n);
}
//////////////////////////////////////////////////////////////////
