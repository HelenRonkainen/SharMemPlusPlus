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
_Mode::_Mode(const ModeChunk mc):
     bits(mc) {
     return;
}

void linux::posix::_Mode::set_read() {
     bits.set(2);
}

void linux::posix::_Mode::set_write() {
     bits.set(1);
}

void linux::posix::_Mode::set_execute() {
     bits.set(0);
}

void linux::posix::_Mode::unset_read() {
     bits.reset(2);
}

void linux::posix::_Mode::unset_write() {
     bits.reset(1);
}

void linux::posix::_Mode::unset_execute() {
     bits.reset(0);
}

mode_t linux::posix::_Mode::get() const {
     return bits.to_ulong();
}

bool linux::posix::_Mode::operator==(const _Mode& m) const {
     return (bits == m.bits);
}

bool linux::posix::_Mode::operator!=(const _Mode& m) const {
     return (bits != m.bits);
}
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
linux::posix::
ModeChunk linux::posix::Mode::for_(const unsigned long m,
				   const unsigned int l) {
     unsigned long m2 = m >> l;
     return ModeChunk(m2);
}

linux::posix::
ModeChunk linux::posix::Mode::for_user(const unsigned long m) {
     return for_(m, 6);
}

linux::posix::
ModeChunk linux::posix::Mode::for_group(const unsigned long m) {
     return for_(m, 3);
}

linux::posix::
ModeChunk linux::posix::Mode::for_other(const unsigned long m) {
     return for_(m, 0);
}

linux::posix::
Mode::Mode():
     user(for_user(00644)),
     group(for_group(00644)),
     other(for_other(00644)) {
     return;
}

linux::posix::
Mode::Mode(const mode_t m):
     user(for_user(m)),
     group(for_group(m)),
     other(for_other(m)) {
     return;
}

mode_t linux::posix::Mode::get() const {
     mode_t u_m = user.get();
     u_m = u_m << 6;
     mode_t g_m = group.get();
     g_m = g_m << 3;
     mode_t o_m = other.get();
     return (u_m | g_m | o_m);
}

bool linux::posix::Mode::operator==(const Mode& m) const {
     if (user == m.user) {
	  if (group == m.group) {
	       return (other == m.other);
	  }
     }
     return false;
}

bool linux::posix::Mode::operator!=(const Mode& m) const {
     if (user != m.user) return true;
     if (group != m.group) return true;
     return (other != m.other);
}
//////////////////////////////////////////////////////////////////
