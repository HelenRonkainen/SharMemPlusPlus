//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "ErrorBuilder.hpp"
#include <string.h>

//////////////////////////////////////////////////////////////////
linux::posix::
Error linux::posix::ErrorBuilder::build(const Code c) {
     clean();
     char* res = strerror_r(c, &(buffer.front()), buffer.size());
     if (res == nullptr) return Error("NO MESSAGE!", c);
     return Error(String(res), c);
}

void linux::posix::ErrorBuilder::clean() {
     for (auto& i : buffer) i = '\0';
}
//////////////////////////////////////////////////////////////////
