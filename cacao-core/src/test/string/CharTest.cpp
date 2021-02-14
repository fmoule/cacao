#include <gtest/gtest.h>

#include "string/Char.h"

using namespace cacao;

///// Tests unitaires :

TEST(CharTest, shouldConvertIntoChar) {
    Char theChar(1);
    EXPECT_EQ(theChar, Char('1'));
}
