#include <gtest/gtest.h>
#include <SharedMemory.hpp>
#include <MMaper.hpp>
#include <Error.hpp>

//////////////////////////////////////////////////////////////////
TEST(MMaper, test_001)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, 4096, false, f);
     sm3.open().truncate();
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
     posix::SharedMemory sm3(n, 4096, false);
     sm3.open().truncate();
     posix::MMapOptions mo;
     posix::MMaper m1(sm3, true, mo);
     posix::MMaper m2(sm3, true);
     posix::MMaper m3(sm3);
     try {
	  m3.unmap();
     } catch (linux::posix::NullPointer& d) {
	  ASSERT_TRUE(true);
	  return;
     }
     ASSERT_TRUE(false);
}

TEST(MMaper, test_003)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::SharedMemory sm3(n, 4096, false);
     sm3.open().truncate();
     posix::MMaper m3(sm3);
     auto r = m3.map();
     ASSERT_EQ(4096, std::get<size_t>(r));
     ASSERT_NE(nullptr, std::get<void*>(r));
     m3.unmap();
}
//////////////////////////////////////////////////////////////////
