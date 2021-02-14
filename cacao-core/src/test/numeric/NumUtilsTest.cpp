#include <gtest/gtest.h>

#include "numeric/NumUtils.h"

using namespace cacao;

TEST(NumUtilsTest, shouldGetTheNbDigits) {
    EXPECT_EQ(getNbDigits(10), 2);
    EXPECT_EQ(getNbDigits(156), 3);
    EXPECT_EQ(getNbDigits(2), 1);
    EXPECT_EQ(getNbDigits(-6356), 4);
}