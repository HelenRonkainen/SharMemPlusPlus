//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include <sys/stat.h>

#ifndef __linux_posix_Mode__
#define __linux_posix_Mode__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class Mode {

	  public:
	       Mode(const mode_t);
	       ~Mode() = default;

	       mode_t get() const;

	  private:
	       mode_t mode;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_Mode__
