#include <gtest/gtest.h>
#include <SharedMemory.hpp>
#include <MMaper.hpp>

//////////////////////////////////////////////////////////////////
TEST(MMaper, test_001)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, f, false);
     sm3.open().truncate(4096);
     posix::MMapOptions mo;
     ASSERT_EQ(posix::mmap::READ |
	       posix::mmap::WRITE,
	       mo.get_protection().get());
     ASSERT_EQ(posix::mmap::MSHARED, mo.get_flag().get());
}
//////////////////////////////////////////////////////////////////
