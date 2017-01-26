#include <gtest/gtest.h>
#include <Semaphore.hpp>

//////////////////////////////////////////////////////////////////
TEST(Semaphore, test_01)
{
     using namespace linux::posix;
     Name n("/ARTA");
     OpenOptions f;
     Semaphore s1(n, false, f, 4);
     Semaphore s2(n, false);
}

TEST(Semaphore, test_02)
{
     using namespace linux::posix;
     Name n("/AA");
     Semaphore s2(n, true);
     s2.open();
     ASSERT_EQ(1, s2.get());
     s2.close();
}

TEST(Semaphore, test_03)
{
     using namespace linux::posix;
     Name n("/A2");
     OpenOptions f;
     Semaphore s1(n, true, f, 4);
     s1.open();
     s1.close();
     Semaphore s2(n, true, f, 10);
     s2.open();
     auto a2 = s2.get();
     ASSERT_EQ(4, a2);
}
//////////////////////////////////////////////////////////////////
