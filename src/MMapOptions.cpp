//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "MMapOptions.hpp"

//////////////////////////////////////////////////////////////////
linux::posix::
MMapOptions::MMapOptions(const Protection p):
     mode(p)
{
     return;
}

linux::posix::
MMapOptions::MMapOptions(const MFlag mf):
     flag(mf)
{
     return;
}

linux::posix::
MMapOptions::MMapOptions(const Protection p, const MFlag mf):
     mode(p),
     flag(mf)
{
     return;
}

linux::posix::
MMapOptions::MMapOptions(const MFlag mf, const Protection p):
     mode(p),
     flag(mf)
{
     return;
}

linux::posix::
Protection& linux::posix::MMapOptions::get_protection() {
     return mode;
}

linux::posix::
MFlag& linux::posix::MMapOptions::get_flag() {
     return flag;
}
//////////////////////////////////////////////////////////////////
