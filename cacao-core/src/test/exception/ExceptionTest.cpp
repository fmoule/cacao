#include <gtest/gtest.h>

#include "exception/Exception.h"

using namespace cacao;

///// Fonctions utilitaires :

bool testInt(const int value, const String msg) {
    const int res = value % 5;
    if (res == 0) {
        throw Exception(msg);
    }
    return res;
}

///// Tests unitaires :

TEST(FinallyClauseTest, shouldExecuteFinallyClause) {
    int cursor = 0;
    FinallyClause* pClause = new FinallyClause([&cursor]() -> void { cursor++; });
    RELEASE(pClause);
    EXPECT_EQ(cursor, 1);
}

TEST(FinallyClauseTest, shouldBeEquals) {
    int cursor = 0;
    auto pFunction = [&cursor]() -> void { cursor++; };
    FinallyClause* pClause = new FinallyClause(pFunction);
    EXPECT_NE(*pClause, FinallyClause(pFunction));
    RELEASE(pClause);
    EXPECT_EQ(cursor, 2);
}

TEST(ExceptionTest, shouldBeEquals) {
    Exception ex1("message");
    EXPECT_EQ(ex1, Exception("message"));
    EXPECT_EQ(ex1.hashCode(), Exception("message").hashCode());
    EXPECT_NE(ex1, Exception("otherMessage"));
    EXPECT_NE(ex1, Exception());
}

TEST(ExceptionTest, shouldCopyValue) {
    Exception ex("message"), ex1;
    ex1 = ex;
    EXPECT_EQ(ex1.getMessage(), String("message"));
}

TEST(ExceptionTest, shouldUseTheFinallyClause) {
    int cursor = 0;
    if (true) {
        try {
            testInt(25, "Message");
        } catch (const Exception& ex) {
            // TEST
        }
        FINALLY([&cursor]() -> void {
            cursor++;
        });
    }
    EXPECT_EQ(cursor, 1);
}