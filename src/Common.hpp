//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <string>

#ifndef __linux_posix_Common__
#define __linux_posix_Common__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  using String = std::string;
	  using flag_t = int;
	  using UNLINK_AFTER_DESTROY = bool;
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_Common__
