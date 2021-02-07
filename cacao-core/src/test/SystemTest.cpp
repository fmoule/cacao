#include "gtest/gtest.h"
#include "System.h"

using namespace cacao;

///// Tests unitaires :

TEST(SystemTest, shouldGetInstance) {
    const System* pSystem = System::getInstance();
    EXPECT_FALSE(pSystem == nullptr);
}