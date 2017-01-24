#include <gtest/gtest.h>
#include <ErrorBuilder.hpp>
#include <errno.h>

//////////////////////////////////////////////////////////////////
TEST(ErrorBuilder, test_01)
{
     using namespace linux::posix;
     ErrorBuilder eb;
     auto e = eb.build(E2BIG);
     ASSERT_EQ(E2BIG, e.getCode());
     ASSERT_EQ("Argument list too long", String(e.what()));

     auto e2 = eb.build(ELIBACC);
     ASSERT_EQ(ELIBACC, e2.getCode());
     ASSERT_EQ("Can not access a needed shared library", String(e2.what()));

     auto e3 = eb.build(EISDIR);
     ASSERT_EQ(EISDIR, e3.getCode());
     ASSERT_EQ("Is a directory", String(e3.what()));
}
//////////////////////////////////////////////////////////////////
