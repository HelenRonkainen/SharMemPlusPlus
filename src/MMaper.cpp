//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MMaper.hpp"
#include "ErrorBuilder.hpp"
#include <sys/mman.h>
#include <errno.h>

//////////////////////////////////////////////////////////////////
linux::posix::
MMaper::MMaper(const SharedMemory& sm,
	       const UNMAP_AFTER_DESTROY u,
	       const MMapOptions mo):
     memory(sm),
     unmap_mode(u),
     options(mo),
     addr(nullptr),
     mmap_size(0)
{
     return;
}

linux::posix::
MMaper::~MMaper() {
     if (unmap_mode) {
	  if (addr != nullptr) munmap(addr, mmap_size);
     }
}

linux::posix::
MapInfo linux::posix::MMaper::map() {
     return maping(memory.size);
}

linux::posix::
MapInfo linux::posix::MMaper::map(const size_t sss) {
     return maping(sss);
}

linux::posix::
MapInfo linux::posix::MMaper::maping(const size_t s) {
     void* res = ::mmap(NULL,
			s,
			options.get_protection().get(),
			options.get_flag().get(),
			memory.fd,
			0);
     if (res == MAP_FAILED) error(errno);
     addr = res;
     mmap_size = s;
     return std::make_tuple(addr, s);
}

void linux::posix::MMaper::unmap() const {
     if (addr == nullptr) throw NullPointer();
     int res = munmap(addr, mmap_size);
     if (res == -1) error(errno);
}

void linux::posix::MMaper::error(const int n) const {
     ErrorBuilder eb;
     throw eb.build(n);
}
//////////////////////////////////////////////////////////////////
