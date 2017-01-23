#include <gtest/gtest.h>
#include <fcntl.h>
#include <OFlag.hpp>

//////////////////////////////////////////////////////////////////
TEST(OFlag, test_01)
{
     using namespace linux::posix;
     OFlag of;
     ASSERT_EQ(O_CREAT | O_RDWR, of.get());
}

TEST(OFlag, test_02)
{
     using namespace linux::posix;
     using namespace linux::posix::oflag;
     OFlag of(CREAT);
     ASSERT_EQ(O_CREAT, of.get());
}

TEST(OFlag, test_03)
{
     using namespace linux::posix;
     using namespace linux::posix::oflag;
     OFlag of(CREAT | RDWR);
     ASSERT_EQ(O_CREAT | O_RDWR, of.get());
}

TEST(OFlag, test_04)
{
     using namespace linux::posix;
     using namespace linux::posix::oflag;
     OFlag of(0);
     of.add(CREAT).add(RDWR);
     ASSERT_EQ(O_CREAT | O_RDWR, of.get());
}
//////////////////////////////////////////////////////////////////
