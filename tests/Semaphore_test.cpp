#include <gtest/gtest.h>
#include <Semaphore.hpp>

//////////////////////////////////////////////////////////////////
TEST(Semaphore, test_01)
{
     using namespace linux::posix;
     ASSERT_TRUE(true);
     Name n("/ARTA");
     OpenOptions f;
     Semaphore s(n, false, f, 4);
     
     // posix::SharedMemory sm3(n, false, f);
     // sm3.open().truncate(4096);
     // posix::MMapOptions mo;
     // ASSERT_EQ(posix::mmap::READ |
     // 	       posix::mmap::WRITE,
     // 	       mo.get_protection().get());
     // ASSERT_EQ(posix::mmap::MSHARED, mo.get_flag().get());
}
//////////////////////////////////////////////////////////////////
