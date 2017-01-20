#include <gtest/gtest.h>
#include <Mode.hpp>

//////////////////////////////////////////////////////////////////
TEST(Mode, test_01)
{
     using namespace linux::posix;
     Mode m(0777);
     ASSERT_EQ(0777, m.get());
}
/*
TEST(Mode, test_02)
{
     using namespace linux::posix;
     Mode m;
     ASSERT_EQ(0644, m.get());
}

TEST(Mode, test_03)
{
     using namespace linux::posix;
     Mode m;
     m.user.set_read();
     m.group.set_read();
     m.other.set_read();
     m.user.set_write();
     m.group.set_write();
     m.other.set_write();
     m.user.set_execute();
     m.group.set_execute();
     m.other.set_execute();
     ASSERT_EQ(0777, m.get());
}

TEST(Mode, test_04)
{
     using namespace linux::posix;
     Mode m1(0777);
     Mode m2;
     ASSERT_NE(m1, m2);
}

TEST(Mode, test_05)
{
     using namespace linux::posix;
     Mode m1(0777);
     Mode m2;
     m2.user.set_read();
     m2.group.set_read();
     m2.other.set_read();
     m2.user.set_write();
     m2.group.set_write();
     m2.other.set_write();
     m2.user.set_execute();
     m2.group.set_execute();
     m2.other.set_execute();
     ASSERT_EQ(m1, m2);
}
*/
//////////////////////////////////////////////////////////////////
