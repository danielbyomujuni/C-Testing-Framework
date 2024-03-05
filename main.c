#include <stdio.h>
#include "include/c_test.h"

int main() {
    return test_main();
}

TEST(HelloWorld, EXPECT_EQUAL) {
    ASSERT_EQ(1,1);
}

TEST(HelloWorld, EXPECT_NOT_EQUAL) {
    ASSERT_NOT_EQ(1,2);
}

TEST(HelloWorld, EXPECT_TRUE) {
    ASSERT_TRUE(1);
}
//Fails
TEST(HelloWorld, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}

TEST(GoodbyeWorld, EXPECT_EQUAL) {
    ASSERT_EQ(1,1);
}

TEST(GoodbyeWorldFail, EXPECT_EQUAL_FAIL) {
    ASSERT_EQ(1,2);
}

TEST(GoodbyeWorldFail, EXPECT_EQUAL_FAIL_Not) {
    ASSERT_NOT_EQ(1,1);
}


TEST(GoodbyeWorld, EXPECT_NOT_EQUAL) {
    ASSERT_NOT_EQ(1,2);
}

TEST(GoodbyeWorld, EXPECT_TRUE) {
    ASSERT_TRUE(1);
}

TEST(GoodbyeWorld, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}

TEST(Group3, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}

TEST(Group4, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}


TEST(Group5, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}

TEST(HelloNullWorld, EXPECT_NULL) {
    ASSERT_NULL(NULL);
}

TEST(HelloNullWorld, EXPECT_NOT_NULL) {
    ASSERT_NULL(1);
}

TEST(HelloNullWorld, NOT_EXPECT_NULL_BUT_GOT) {
    ASSERT_NOT_NULL(NULL);
}

TEST(HelloNullWorld, NOT_EXPECT_NOT_NULL) {
    ASSERT_NOT_NULL(1);
}