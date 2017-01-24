//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Protection.hpp"
#include "MFlag.hpp"

#ifndef __linux_posix_MMapOptions__
#define __linux_posix_MMapOptions__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	       class MMapOptions {

	       public:
		    MMapOptions() = default;
		    MMapOptions(const Protection);
		    MMapOptions(const MFlag);
		    MMapOptions(const Protection, const MFlag);
		    MMapOptions(const MFlag, const Protection);
		    ~MMapOptions() = default;

		    Protection& get_protection();
		    MFlag& get_flag();

	       private:
		    Protection mode;
		    MFlag flag;
	       };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_MMapOptions__
