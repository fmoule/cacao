#include <gtest/gtest.h>

#include "Object.h"
#include "string/String.h"

using namespace cacao;

TEST(ObjectTest, shouldInstanceOf) {
    String str("test");
    EXPECT_TRUE(instanceOf<String>(&str));
    EXPECT_TRUE(instanceOf<Object>(&str));
    Object* obj = new String("test2");
    EXPECT_TRUE(instanceOf<String>(obj));
    RELEASE(obj);
}


