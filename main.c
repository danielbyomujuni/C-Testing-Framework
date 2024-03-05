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
    int *one = NULL;
    ASSERT_NULL(one);
}

TEST(HelloNullWorld, EXPECT_NOT_NULL) {
    int *one = malloc(sizeof(int));
    *one = 1;
    ASSERT_NULL(one);
}

TEST(HelloNullWorld, NOT_EXPECT_NULL_BUT_GOT) {
    int *one = NULL;
    ASSERT_NOT_NULL(one);
}

TEST(HelloNullWorld, NOT_EXPECT_NOT_NULL) {
    int *one = malloc(sizeof(int));
    *one = 1;
    ASSERT_NOT_NULL(one);
}