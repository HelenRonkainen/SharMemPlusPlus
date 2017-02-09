//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Error.hpp"

//////////////////////////////////////////////////////////////////
linux::posix::
Error::Error(const Message m, const Code c):
     code(c),
     mess(m)
{
     return;
}

linux::posix::
Error::~Error() noexcept {
     return;
}

linux::posix::
Code linux::posix::Error::getCode() const {
     return code;
}

const char* linux::posix::Error::what() const noexcept {
     return mess.c_str();
}
//////////////////////////////////////////////////////////////////
