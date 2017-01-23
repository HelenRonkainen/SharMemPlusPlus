//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "OFlag.hpp"
#include "Mode.hpp"

#ifndef __linux_posix_shm_OpenOptions__
#define __linux_posix_shm_OpenOptions__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	       class OpenOptions {

	       public:
		    OpenOptions() = default;
		    OpenOptions(const OFlag);
		    OpenOptions(const Mode);
		    OpenOptions(const OFlag, const Mode);
		    OpenOptions(const Mode, const OFlag);
		    ~OpenOptions() = default;

		    Mode& get_mode();
		    OFlag& get_oflag();

	       private:
		    Mode mode;
		    OFlag flag;
	       };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_OpenOptions__
