#include "gtest/gtest.h"
#include "string/String.h"

using namespace cacao;

TEST(StringTest, shouldGetSize) {
    EXPECT_EQ(getStringSize("test"), 4);
    EXPECT_EQ(getStringSize(nullptr), 0);
}

TEST(StringTest, shouldBuildString) {
    String str("test");
    EXPECT_EQ(str.size(), 4);
    EXPECT_TRUE(str.equals(String("test")));
    EXPECT_FALSE(str.equals(String("otherTest")));
}

TEST(StringTest, shouldGetCharacter) {
    String str("coucou");
    EXPECT_EQ(str[0], 'c');
    EXPECT_EQ(str[1], 'o');
    EXPECT_EQ(str[2], 'u');
    EXPECT_EQ(str[3], 'c');
}

TEST(StringTest, shouldInit) {
    String str("coucou");
    str = String("test");
    EXPECT_TRUE(str.equals(String("test")));
    str = "fred";
    EXPECT_TRUE(str.equals(String("fred")));
}

TEST(StringTest, shouldClone) {
    String str("fred");
    const Object* pObject = str.clone();
    EXPECT_TRUE(instanceOf<String>(pObject));
    const String* pString = dynamic_cast<const String*>(pObject);
    EXPECT_TRUE(pString != nullptr);
    EXPECT_EQ(*pString, String("fred"));
    RELEASE(pObject);
}

TEST(StringTest, shouldToString) {
    String str("test");
    const String str2 = str.toString();
    EXPECT_EQ(str, str2);
}

TEST(StringTest, shouldAppend) {
    String str("test");
    str = str + "-fred";
    EXPECT_EQ(str, String("test-fred"));
    String str2("test");
    str2 + String("-derf");
    EXPECT_EQ(str2, String("test-derf"));
}

TEST(StringTest, shouldBuildFromInt) {
    EXPECT_EQ(String(25), String("25"));
    EXPECT_EQ(String(1256), String("1256"));
    EXPECT_EQ(String(-423), String("-423"));
}

TEST(StringTest, shouldBuildFromLong) {
    EXPECT_EQ(String(25l), String("25"));
    EXPECT_EQ(String(1245l), String("1245"));
    EXPECT_EQ(String(-405l), String("-405"));
}

