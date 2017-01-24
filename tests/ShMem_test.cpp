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

TEST(ShMem, test_007)
{
     using namespace linux;
     posix::Name n("/ShMem_test");
     posix::OpenOptions f;
     //posix::SharedMemory sm1(n, f, true);
     //posix::SharedMemory sm2(n, f, false);
     posix::SharedMemory sm3(n, f);
     //ASSERT_EQ(00644, f.get_mode().get());
}

TEST(ShMem, test_008)
{
     using namespace linux;
     posix::Name n("");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n);
     try {
	  sm3.open();

     } catch (...) {
	  ASSERT_TRUE(true);
	  return;
     }
     ASSERT_TRUE(false);
}

TEST(ShMem, test_009)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, f, false);
     try {
	  sm3.open();

     } catch (...) {
	  ASSERT_TRUE(false);
	  return;
     }
     ASSERT_TRUE(true);
}

TEST(ShMem, test_010)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, f, false);
     sm3.open().close();
}

TEST(ShMem, test_011)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, f, false);
     sm3.open().truncate(4096);
}

TEST(ShMem, test_012)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, f, false);
     try {
	  sm3.open().truncate(-55);

     } catch (...) {

	  ASSERT_TRUE(true);
	  return;
     }
     ASSERT_TRUE(false);
}
//////////////////////////////////////////////////////////////////
