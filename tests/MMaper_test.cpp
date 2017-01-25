#include <gtest/gtest.h>
#include <SharedMemory.hpp>
#include <MMaper.hpp>

//////////////////////////////////////////////////////////////////
TEST(MMaper, test_001)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, false, f);
     sm3.open().truncate(4096);
     posix::MMapOptions mo;
     ASSERT_EQ(posix::mmap::READ |
	       posix::mmap::WRITE,
	       mo.get_protection().get());
     ASSERT_EQ(posix::mmap::MSHARED, mo.get_flag().get());
}

TEST(MMaper, test_002)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::SharedMemory sm3(n, false);
     sm3.open().truncate(4096);
     posix::MMapOptions mo;
     // ASSERT_EQ(posix::mmap::READ |
     // 	       posix::mmap::WRITE,
     // 	       mo.get_protection().get());
     // ASSERT_EQ(posix::mmap::MSHARED, mo.get_flag().get());
}
//////////////////////////////////////////////////////////////////
