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

TEST(HelloWorld, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}

TEST(GoodbyeWorld, EXPECT_EQUAL) {
    ASSERT_EQ(1,1);
}

TEST(GoodbyeWorld, EXPECT_NOT_EQUAL) {
    ASSERT_NOT_EQ(1,2);
}

TEST(GoodbyeWorld, EXPECT_TRUE) {
    ASSERT_TRUE(1);
}

//fails memory error
TEST(GoodbyeWorld, EXPECT_FALSE) {
    ASSERT_FALSE(0);
}