#include <gtest/gtest.h>
#include <Semaphore.hpp>

//////////////////////////////////////////////////////////////////
TEST(Semaphore, test_01)
{
     using namespace linux::posix;
     ASSERT_TRUE(true);
     Name n("/ARTA");
     OpenOptions f;
     Semaphore s1(n, false, f, 4);
     Semaphore s2(n, false);
     // ASSERT_EQ(posix::mmap::READ |
     // 	       posix::mmap::WRITE,
     // 	       mo.get_protection().get());
     // ASSERT_EQ(posix::mmap::MSHARED, mo.get_flag().get());
}

TEST(Semaphore, test_02)
{
     using namespace linux::posix;
     ASSERT_TRUE(true);
     Name n("/AA");
     Semaphore s2(n, true);
     s2.open();
     s2.close();
     // ASSERT_EQ(posix::mmap::READ |
     // 	       posix::mmap::WRITE,
     // 	       mo.get_protection().get());
     // ASSERT_EQ(posix::mmap::MSHARED, mo.get_flag().get());
}
//////////////////////////////////////////////////////////////////
