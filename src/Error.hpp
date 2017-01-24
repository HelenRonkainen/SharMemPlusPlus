//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"

#ifndef __linux_posix_Error__
#define __linux_posix_Error__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  using Message = String;
	  using Code = int;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
	  class Error: public std::exception {

	  public:
	       Error(const Message, const Code);
	       virtual ~Error();

	       Code getCode() const;
	       virtual const char* what() const noexcept;

	  private:
	       const Code code;
	       const Message mess;
     };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_Error__
