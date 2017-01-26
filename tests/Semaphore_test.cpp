#include <gtest/gtest.h>
#include <Semaphore.hpp>
#include <Error.hpp>

//////////////////////////////////////////////////////////////////
TEST(Semaphore, test_01)
{
     using namespace linux::posix;
     Name n("/ARTA");
     OpenOptions f;
     Semaphore s1(n, false, f, 4);
     Semaphore s2(n, false);
     try {
	  s2.close();
     } catch (linux::posix::NullPointer& d) {
	  ASSERT_TRUE(true);
	  return;
     }
     ASSERT_TRUE(false);
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

TEST(Semaphore, test_04)
{
     using namespace linux::posix;
     Name n("/A3");
     OpenOptions f;
     Semaphore s1(n, true);
     s1.open();
     s1.post();
     auto a2 = s1.get();
     ASSERT_EQ(2, a2);
     s1.close();
}

TEST(Semaphore, test_05)
{
     using namespace linux::posix;
     Name n("/A3");
     OpenOptions f;
     Semaphore s1(n, true);
     s1.open();
     s1.post();
     auto a2 = s1.get();
     ASSERT_EQ(2, a2);
     s1.wait();
     a2 = s1.get();
     ASSERT_EQ(1, a2);
     s1.wait();
     a2 = s1.get();
     ASSERT_EQ(0, a2);
     s1.close();
}

TEST(Semaphore, test_06)
{
     using namespace linux::posix;
     Name n("/A3");
     OpenOptions f;
     Semaphore s1(n, true);
     s1.open();
     s1.post();
     auto a2 = s1.get();
     ASSERT_EQ(2, a2);
     ASSERT_TRUE(s1.trywait());
     a2 = s1.get();
     ASSERT_EQ(1, a2);
     ASSERT_TRUE(s1.trywait());
     a2 = s1.get();
     ASSERT_EQ(0, a2);
     ASSERT_FALSE(s1.trywait());
     s1.close();
}
//////////////////////////////////////////////////////////////////
