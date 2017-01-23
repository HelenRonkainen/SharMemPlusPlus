//
// Copyright (c) 2017, Boris Popov <popov@whitekefir.ru>
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.
//

#include "Common.hpp"
#include <bitset>
#include <sys/stat.h>

#ifndef __linux_posix_Mode__
#define __linux_posix_Mode__

namespace linux {
     namespace posix {
//////////////////////////////////////////////////////////////////
	  using ModeChunk = std::bitset<3>;
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
	  class _Mode {

	  public:
	       _Mode(const ModeChunk);
	       _Mode() = default;
	       ~_Mode() = default;

	       void set_read();
	       void set_write();
	       void set_execute();

	       void unset_read();
	       void unset_write();
	       void unset_execute();

	       mode_t get() const;

	       bool operator==(const _Mode&) const;
	       bool operator!=(const _Mode&) const;

	  private:
	       ModeChunk bits;
	  };
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
	  class Mode {

	  public:
	       Mode();
	       Mode(const mode_t);
	       ~Mode() = default;

	       mode_t get() const;

	       bool operator==(const Mode&) const;
	       bool operator!=(const Mode&) const;

	       _Mode user;
	       _Mode group;
	       _Mode other;

	  private:
	       static ModeChunk
	       for_user(const unsigned long);

	       static ModeChunk
	       for_group(const unsigned long);

	       static ModeChunk
	       for_other(const unsigned long);

	       static ModeChunk
	       for_(const unsigned long, const unsigned int);
	  };
//////////////////////////////////////////////////////////////////
     }
}
#endif // __linux_posix_Mode__
