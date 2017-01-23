//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "OpenOptions.hpp"

//////////////////////////////////////////////////////////////////
linux::posix::
OpenOptions::OpenOptions(const OFlag o):
     flag(o) {
     return;
}

linux::posix::
OpenOptions::OpenOptions(const Mode m):
     mode(m) {
     return;
}

linux::posix::
OpenOptions::OpenOptions(const OFlag o, const Mode m):
     mode(m),
     flag(o) { }
     
linux::posix::
OpenOptions::OpenOptions(const Mode m, const OFlag o):
     mode(m),
     flag(o) { }

linux::posix::
Mode& linux::posix::OpenOptions::get_mode() {
     return mode;
}

linux::posix::
OFlag& linux::posix::OpenOptions::get_oflag() {
     return flag;
}
//////////////////////////////////////////////////////////////////
