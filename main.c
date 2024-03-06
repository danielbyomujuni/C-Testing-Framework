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

TEST(Group5, TWO_EXPECTS) {
    ASSERT_FALSE(0);
    ASSERT_TRUE(1);
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


TEST(HelloArrays, EXPECT_ARRAY_EQ) {
    int arr_x[] = {1,2,3};
    int arr_y[] = {1,2,3};
    ASSERT_ARRAY_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_SAME_SIZE_ARRAY_EQ) {
    int arr_x[] = {1,2,3};
    int arr_y[] = {1,2,4};
    ASSERT_ARRAY_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_ARRAY_NOT_EQ) {
    int arr_x[] = {1,2,3};
    int arr_y[] = {1, 2};
    ASSERT_ARRAY_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_EMPTY_ARRAY) {
    int arr_x[] = {};
    int arr_y[] = {};
    ASSERT_ARRAY_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_EMPTY_AND_NON_EMPTY_ARRAY) {
    int arr_x[] = {};
    int arr_y[] = {1};
    ASSERT_ARRAY_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_SAME_SIZE_ARRAY_NOT_EQ) {
    int arr_x[] = {1,2,3};
    int arr_y[] = {1,2,4};
    ASSERT_ARRAY_NOT_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_ARRAY_NOT_NOT_EQ) {
    int arr_x[] = {1,2,3};
    int arr_y[] = {1, 2};
    ASSERT_ARRAY_NOT_EQ(arr_x, arr_y);
}

TEST(HelloArrays, EXPECT_SAME_SIZE_ARRAY_EQ_BUT_SOULDNT) {
    int arr_x[] = {1,2,3};
    int arr_y[] = {1,2,3};
    ASSERT_ARRAY_NOT_EQ(arr_x, arr_y);
}