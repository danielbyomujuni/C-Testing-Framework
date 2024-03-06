#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// c_test.h
#ifndef C_TESTING_FRAMEWORK_C_TEST_H
#define C_TESTING_FRAMEWORK_C_TEST_H


#define MAX_GROUP_LENGTH 80
#define MAX_STRING_LENGTH 128
#define STATUS_LENGTH 7
#define STR(x) #x \


//public macros
/**
 * --TEST-- \n
 * A Macro that creates and registers a unit test
 * @param GROUP the name for testing group (convention: Name of File being tested)
 * @param Name the name of what you are testing
 */
#define TEST(GROUP, NAME) \
	void GROUP##_##NAME##_impl(struct test_struct *self); \
	const test_struct GROUP##_##NAME = { \
		.group_name = #GROUP, \
		.test_name = #NAME,     \
        .did_test_pass = 1, \
		.run = &GROUP##_##NAME##_impl \
	};                       \
    REGSITER_TEST \
    const test_struct* const GROUP##_##NAME##_data##_##ptr = &GROUP##_##NAME;\
    void GROUP##_##NAME##_impl(struct test_struct *self)

#define ASSERT_EQ(x, y) NEKOTEST_ASSERT_VAR_CMP(x != y, x, y, "%d", test_failed_expect)
#define ASSERT_NOT_EQ(x, y) NEKOTEST_ASSERT_VAR_CMP(x == y, x, y, "%d", test_failed_not_expect)

#define ASSERT_TRUE(x) ASSERT_EQ(x, 1)
#define ASSERT_FALSE(x) ASSERT_EQ(x, 0)

#define ASSERT_NULL(x) ASSERT_POINTER_EQ(x, NULL)
#define ASSERT_NOT_NULL(x) ASSERT_POINTER_NOT_EQ(x, NULL)

#define ASSERT_POINTER_EQ(x, y) NEKOTEST_ASSERT_VAR_CMP(x != y, x, y, "%p", test_failed_expect)
#define ASSERT_POINTER_NOT_EQ(x, y) NEKOTEST_ASSERT_VAR_CMP(x == y, x, y, "%p", test_failed_not_expect)


#define ASSERT_ARRAY_EQ(x, y) \
do {                            \
    int x_length = sizeof(x) / sizeof (x[0]); \
    int y_length = sizeof(y) / sizeof (y[0]); \
    char x_buf[MAX_STRING_LENGTH];        \
    array_to_string(x_buf, x, x_length);           \
    char y_buf[MAX_STRING_LENGTH];        \
    array_to_string(y_buf, y, y_length);  \
    if (sizeof(x) != sizeof(y)) {         \
        self->did_test_pass = 0;\
        test_failed_expect(self->test_name, x_buf, y_buf);     \
        return;                 \
    }                           \
    for (int i = 0; i < x_length; i ++) {     \
        if (x[i] != y[i]) {     \
            self->did_test_pass = 0; \
            test_failed_expect(self->test_name, x_buf, y_buf);     \
            return;                           \
        }\
    }                            \
    self->did_test_pass = 1;\
    \
} while (0)

#define ASSERT_ARRAY_NOT_EQ(x, y) \
do {                            \
    int x_length = sizeof(x) / sizeof (x[0]); \
    int y_length = sizeof(y) / sizeof (y[0]); \
    char x_buf[MAX_STRING_LENGTH];        \
    array_to_string(x_buf, x, x_length);           \
    char y_buf[MAX_STRING_LENGTH];        \
    array_to_string(y_buf, y, y_length);      \
    if (x_length != y_length) {   \
        self->did_test_pass = 1;  \
        return;                              \
    }\
    int index = 0;                \
    while (index < x_length) {    \
        if (x[index] != y[index]) {       \
            self->did_test_pass = 1;  \
            return;\
        }                         \
        index++;                              \
    }                         \
    self->did_test_pass = 0; \
    test_failed_not_expect(self->test_name, x_buf, y_buf);     \
} while (0)

#define NEKOTEST_ASSERT_VAR_CMP(compare_expression, x, y, format_str, fail_print_func) \
do {                                                                  \
    if (compare_expression) {                                         \
        self->did_test_pass = 0;                                      \
        char x_result[MAX_STRING_LENGTH];                             \
        if (x == NULL) { strcpy (x_result,"NULL"); } else {                   \
            snprintf(x_result, MAX_STRING_LENGTH, format_str, x);     \
        }                                                             \
        char y_result[MAX_STRING_LENGTH];                                              \
        if (y == NULL) { strcpy (y_result,"NULL"); } else {                                    \
            snprintf(y_result, MAX_STRING_LENGTH, format_str, y);                          \
        }                                                                                 \
        fail_print_func(self->test_name, y_result, x_result); \
        return; \
    }                     \
    self->did_test_pass = 1;\
} while (0)

//Private Macros and structures
typedef struct test_struct {
    const char *group_name;
    const char *test_name;
    int did_test_pass;

    void (*run)(struct test_struct *self);
} test_struct;

#if defined(__APPLE__)
#define REGSITER_TEST __attribute__((used, section("__DATA,c_test")))
#elif defined(__unix__)
#define REGSITER_TEST __attribute__((used, section("c_test")))
#endif

#if defined(__APPLE__)
extern const test_struct* const __start_c_test __asm("section$start$__DATA$c_test");
extern const test_struct* const __stop_c_test __asm("section$end$__DATA$c_test");
__attribute__((used, section("__DATA,c_test"))) static const test_struct* const dummy = NULL;
#elif defined(__unix__)
extern const test_struct* const __start_rktest;
extern const test_struct* const __stop_rktest;
__attribute__((used, section("c_test"))) const test_struct* const dummy = NULL;
#endif

#define TEST_DATA_BEGIN (&__start_c_test)
#define TEST_DATA_END (&__stop_c_test)


static void get_all_tests(test_struct ***tests, int *test_len);
static void sort_tests(test_struct **tests, int test_len);
static int execute_tests(test_struct *const *tests, int test_len);

static void test_failed_expect(const char* testName, char* received, char* expected) {
    printf("  \033[0;31m[ FAILED ] \033[0;37m %s\n", testName);
    printf("\033[0;31m     Expected: %s\033[0;37m\n", expected);
    printf("\033[0;31m     Received: %s\033[0;37m\n", received);
}

static void test_failed_not_expect(const char* testName, char* received, char* expected) {
    printf("  \033[0;31m[ FAILED ] \033[0;37m %s\n", testName);
    printf("\033[0;31m     Did Not Expect: %s\033[0;37m\n", expected);
    printf("\033[0;31m     Received:       %s\033[0;37m\n", received);
}

#define array_to_string(str, arr, arr_len) \
do {                                           \
    char p[5]; int i;                      \
    strcpy(str, "[");                       \
    for( i = 0; i < arr_len; i++ ){        \
        if (i != 0) {strcat(str, ",");}                                \
        sprintf(p, "%x", arr[i]); \
        strcat(str, p); \
    }                                      \
    strcat(str, "]");                                       \
} while (0)

static int run_tests() {
    //create test array
    test_struct **tests;
    int test_len;
    //get and run the tests
    get_all_tests(&tests, &test_len);
    sort_tests(tests, test_len);
    int did_test_fail = execute_tests(tests, test_len);

    //clean up
    for (int i = 0; i < test_len; i++) {
        free(tests[i]);
    }
    //return results
    free(tests);
    return did_test_fail;
}


static void get_all_tests(test_struct ***tests, int *test_len) {
    (*tests) = calloc(0, sizeof(struct test_struct *));
    (*test_len) = 0;//read in all the tests
    for (const test_struct *const *it = TEST_DATA_BEGIN; it != TEST_DATA_END; it++) {
        if (*it == NULL) {
            continue;
        }
        //
        test_struct *temp_arr[(*test_len)];
        for (int i = 0; i < (*test_len); i++) {
            temp_arr[i] = (*tests)[i];
        }
        free((*tests));
        (*tests) = calloc((*test_len) + 1, sizeof(struct test_struct *));
        for (int i = 0; i < (*test_len); i++) {
            (*tests)[i] = temp_arr[i];
        }
        (*test_len)++;
        test_struct temp_test = **it;

        test_struct *new_test = calloc(1, sizeof(test_struct));
        *new_test = temp_test;
        (*tests)[(*test_len) - 1] = new_test;
    }
}

static void sort_tests(test_struct **tests, int test_len) {//sort all the tests
    for (int i = 0; i < test_len; i++) {
        for (int j = i + 1; j < test_len; j++) {
            if (strcmp(tests[i]->group_name, tests[j]->group_name) > 0) {
                test_struct *temp = tests[i];
                tests[i] = tests[j];
                tests[j] = temp;
            }
        }
    }
}

static int execute_tests(test_struct *const *tests, int test_len) {
    int failed_tests = 0;
    char current_group[MAX_GROUP_LENGTH];


    for (int i = 0; i < test_len; i++) {

        if (strcmp(current_group, tests[i]->group_name) != 0) {
            strcpy(current_group, tests[i]->group_name);
            printf("\033[0;1m\033[0;36m[-GROUP-]\033[0;37m %s \n", current_group);
        }
        tests[i]->run(tests[i]);
        if (tests[i]->did_test_pass != 1) {
            failed_tests++;
        } else {
            printf("  \033[0;32m[ PASSED ]\033[0;37m %s\n", tests[i]->test_name);
        }

    }

    printf("Results: %d Tests Passed out of %d\n",(test_len - failed_tests), test_len);
    return failed_tests == 0 ? 0 : EXIT_FAILURE;
}

static int test_main() {
    return run_tests();
}

#endif /* C_TESTING_FRAMEWORK_C_TEST_H */