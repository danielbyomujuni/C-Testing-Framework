#include <stdio.h>
#include "include/c_test.h"

int main() {
    return test_main();
}

TEST(HelloWorld, EXPECT_EQUAL) {
    ASSERT_EQ(1,1);
}

TEST(HelloWorld, EXPECT_EQUAL_FAIL) {
    ASSERT_EQ(1,1);
}