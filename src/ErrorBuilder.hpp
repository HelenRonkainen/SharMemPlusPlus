//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Error.hpp"
#include <array>

#ifndef __linux_posix_ErrorBuilder__
#define __linux_posix_ErrorBuilder__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  class ErrorBuilder {

	  public:
	       ErrorBuilder() = default;
	       ~ErrorBuilder() = default;

	       Error build(const Code);

	  private:
	       void clean();

	       typedef std::array<char, 2048> Buffer;
	       Buffer buffer;
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_ErrorBuilder__
