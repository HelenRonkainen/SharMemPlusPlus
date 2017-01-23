#include <gtest/gtest.h>
#include <SharedMemory.hpp>

//////////////////////////////////////////////////////////////////
TEST(ShMem, test_001)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::OpenOptions f;
     ASSERT_EQ(00644, f.get_mode().get());
}

TEST(ShMem, test_002)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::OpenOptions f;
     ASSERT_EQ(O_CREAT | O_RDWR, f.get_oflag().get());
}

TEST(ShMem, test_003)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::Mode m;
     posix::OpenOptions f(m);
     ASSERT_EQ(O_CREAT | O_RDWR, f.get_oflag().get());
     ASSERT_EQ(00644, f.get_mode().get());
}

TEST(ShMem, test_004)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::OFlag m;
     posix::OpenOptions f(m);
     ASSERT_EQ(O_CREAT | O_RDWR, f.get_oflag().get());
     ASSERT_EQ(00644, f.get_mode().get());
}

TEST(ShMem, test_005)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::OFlag m1;
     posix::Mode m2;
     posix::OpenOptions f(m1, m2);
     ASSERT_EQ(O_CREAT | O_RDWR, f.get_oflag().get());
     ASSERT_EQ(00644, f.get_mode().get());
}

TEST(ShMem, test_006)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::OFlag m1;
     posix::Mode m2;
     posix::OpenOptions f(m2, m1);
     ASSERT_EQ(O_CREAT | O_RDWR, f.get_oflag().get());
     ASSERT_EQ(00644, f.get_mode().get());
}
//////////////////////////////////////////////////////////////////
