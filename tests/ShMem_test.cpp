#include <gtest/gtest.h>
#include <SharedMemory.hpp>
#include <MMaper.hpp>

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
     posix::SharedMemory sm3(n, 5, true, f);
     //ASSERT_EQ(00644, f.get_mode().get());
}

TEST(ShMem, test_008)
{
     using namespace linux;
     posix::Name n("");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, false);
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
     posix::SharedMemory sm3(n, 4096, false, f);
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
     posix::SharedMemory sm3(n, 4096, false, f);
     sm3.open().close();
}

TEST(ShMem, test_011)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, 4096, false, f);
     sm3.open().truncate();
}

TEST(ShMem, test_012)
{
     using namespace linux;
     posix::Name n("/ARTA");
     posix::OpenOptions f;
     posix::SharedMemory sm3(n, -55, false, f);
     try {
	  sm3.open().truncate();

     } catch (...) {

	  ASSERT_TRUE(true);
	  return;
     }
     ASSERT_TRUE(false);
}

TEST(ShMem, test_013)
{
     using namespace linux::posix;
     Name n("test");
     {
	  SharedMemory sm(n, 256);
	  sm.open().truncate();
	  MMaper m(sm);
	  auto i = m.map();
	  void* p = std::get<void*>(i);
	  int* k = (int*)p;
	  (*k) = 1984;
	  m.unmap();
	  sm.close();
     }
     SharedMemory sm2(n, 256, true);
     sm2.open();
     MMaper m2(sm2, true);
     auto i2 = m2.map();
     void* p2 = std::get<void*>(i2);
     int* k2 = (int*)p2;
     ASSERT_EQ(1984, (*k2));
     m2.unmap();
     sm2.close();
}
//////////////////////////////////////////////////////////////////
