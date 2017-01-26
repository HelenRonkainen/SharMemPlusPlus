//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"

#ifndef __linux_posix_FlagCommon__
#define __linux_posix_FlagCommon__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class Flag {

	  public:
	       Flag() = default;
	       Flag(const flag_t f) { flag = f; }
	       virtual ~Flag() = 0;

	       flag_t get() const { return flag; }

	       Flag& add(const flag_t f) {
		    flag = flag | f;
		    return *this;
	       }

	  private:
	       flag_t flag;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_FlagCommon__
