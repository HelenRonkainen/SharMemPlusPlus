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

void linux::posix::Semaphore::close() {
     if (semaphore == SEM_FAILED) return;
     if (semaphore == nullptr) return;
     int res = sem_close(semaphore);
     if (res == -1) {
	  int e = errno;
	  ErrorBuilder eb;
	  throw eb.build(e);
     }
     semaphore = nullptr;
}

linux::posix::
Semaphore::~Semaphore() {
     if (semaphore == SEM_FAILED) return;
     if (semaphore == nullptr) return;
     sem_close(semaphore);
     if (destroy) sem_unlink(name.c_str());
}
//////////////////////////////////////////////////////////////////
