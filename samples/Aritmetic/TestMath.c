//
// Created by Daniel Byomujuni on 3/5/24.
//
#include "../../include/c_test.h"
#include "Math.h"

TEST(TEST_MATH, ADD_ONE_PLUS_ONE) {
    ASSERT_EQ(add(1,1), 2);
}

TEST(TEST_MATH, ADD_ZERO_PLUS_TEN) {
    ASSERT_EQ(add(0,10), 10);
}

TEST(TEST_MATH, SUB_ONE_MINUS_ONE) {
    ASSERT_EQ(sub(1,1), 0);
}

TEST(TEST_MATH, SUB_25_MINUS_15) {
    ASSERT_EQ(sub(25,15), 10);
}

TEST(TEST_MATH, SUB_420_MINUS_20) {
    ASSERT_EQ(sub(420,20), 420);
}