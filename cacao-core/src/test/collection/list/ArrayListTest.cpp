#include <gtest/gtest.h>

#include "collection/list/ArrayList.h"

#include "string/String.h"

using namespace cacao;

TEST(ArrayListTest, shouldAddAnPrimitives) {
    ArrayList<int> list;
    EXPECT_EQ(list.size(), 0);
    list.add(5);
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), 5);
}

TEST(ArrayListTest, shouldAddAnClass) {
    ArrayList<String> list;
    EXPECT_EQ(list.size(), 0);
    list.add("fred");
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list.get(0), String("fred"));
}

TEST(ArrayListTest, shouldBeEquals) {
    ArrayList<String> list({"str1", "str2"});
    EXPECT_EQ(list, ArrayList<String>({"str1", "str2"}));
    EXPECT_NE(list, ArrayList<String>({String("str1")}));
}

TEST(ArrayListTest, shouldContains) {
    ArrayList<int> list({1, 5, 6});
    EXPECT_TRUE(list.contains(1));
    EXPECT_FALSE(list.contains(156));
    EXPECT_TRUE(list.contains(5));
    EXPECT_TRUE(list.contains(6));
}

TEST(ArrayListTest, shouldCopy) {
    ArrayList<String> list({"test1", "test2"});
    const ArrayList<String>* pCopiedList = dynamic_cast<const ArrayList<String>*>(list.clone());
    EXPECT_TRUE(pCopiedList != nullptr);
    EXPECT_EQ(pCopiedList->size(), 2);
    EXPECT_EQ(pCopiedList->get(0), String("test1"));
    EXPECT_EQ(pCopiedList->get(1), String("test2"));
    RELEASE(pCopiedList);
}

TEST(ArrayListTest, shouldAddPointers) {
    ArrayList<String*> list;
    EXPECT_EQ(list.size(), 0);
    String* str = new String("test");
    list.add(str);
    EXPECT_EQ(list.size(), 1);
    RELEASE(str);
}

TEST(ArrayListTest, shouldAddLotPointers) {
    ArrayList<String*> list;
    String* str;
    for (int i = 0; i < 10; i++) {
        str = new String("test");
        list.add(str);
        RELEASE(str);
    }
    EXPECT_EQ(list.size(), 10);
}