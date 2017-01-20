//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Mode.hpp"

//////////////////////////////////////////////////////////////////
linux::posix::
Mode::Mode():
     mode(00644) {
}

linux::posix::
Mode::Mode(const mode_t m):
     mode(m) {
}

mode_t linux::posix::Mode::get() const {
     return mode;
}

bool linux::posix::Mode::operator==(const Mode& m) const {
     return mode == m.mode;
}

bool linux::posix::Mode::operator!=(const Mode& m) const {
     return mode != m.mode;
}
//////////////////////////////////////////////////////////////////
