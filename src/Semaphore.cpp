//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Semaphore.hpp"
#include "ErrorBuilder.hpp"

//////////////////////////////////////////////////////////////////
linux::posix::
Semaphore::Semaphore(const Name n,
		     const UNLINK_AFTER_DESTROY d,
		     const OpenOptions oo,
		     unsigned int v):
     name(n),
     destroy(d),
     options(oo),
     value(v),
     semaphore(nullptr)
{
     return;
}

void linux::posix::Semaphore::open() {
     semaphore = sem_open(name.c_str(),
			  options.get_oflag().get(),
			  options.get_mode().get(),
			  value);
     if (semaphore == SEM_FAILED) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
}

void linux::posix::Semaphore::close() const {
     if (semaphore == SEM_FAILED) return;
     if (semaphore == nullptr) return;
     int res = sem_close(semaphore);
     if (res == -1) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
}

void linux::posix::Semaphore::post() const {
     int res = sem_post(semaphore);
     if (res == -1) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
}

int linux::posix::Semaphore::get() const {
     int ret = 0;
     int res = sem_getvalue(semaphore, &ret);
     if (res == -1) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
     return ret;
}

linux::posix::
Semaphore::~Semaphore() {
     if (semaphore == SEM_FAILED) return;
     if (semaphore == nullptr) return;
     sem_close(semaphore);
     if (destroy) sem_unlink(name.c_str());
}
//////////////////////////////////////////////////////////////////
