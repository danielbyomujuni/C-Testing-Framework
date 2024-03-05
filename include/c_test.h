#include <stdio.h>
#include <string.h>

#define EXIT_FAILURE -1
#define STATUS_LENGTH 6
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
        .did_test_pass = 0, \
		.run = &GROUP##_##NAME##_impl \
	};                       \
    REGSITER_TEST \
    const test_struct* const GROUP##_##NAME##_data##_##ptr = &GROUP##_##NAME;\
    void GROUP##_##NAME##_impl(struct test_struct *self)

#define ASSERT_EQ( x, y ) \
do {                      \
    if (x != y) {         \
        self->did_test_pass = 0;\
        test_failed(self->test_name);     \
        return; \
    }                     \
    self->did_test_pass = 1;\
    test_passed(self->test_name); \
} while (0)

#define ASSERT_NOT_EQ( x, y ) \
do {                      \
    if (x == y) {         \
        self->did_test_pass = 0;\
        test_failed(self->test_name);     \
        return; \
    }                     \
    self->did_test_pass = 1;\
    test_passed(self->test_name); \
} while (0)

#define ASSERT_TRUE( x ) ASSERT_EQ(x, 1)
#define ASSERT_FALSE( x ) ASSERT_EQ(x, 0)



typedef struct test_struct {
    const char* group_name;
    const char* test_name;
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
__attribute__((used, section("__DATA,c_test"))) const test_struct* const dummy = NULL;
#elif defined(__unix__)
extern const test_struct* const __start_rktest;
extern const test_struct* const __stop_rktest;
__attribute__((used, section("c_test"))) const test_struct* const dummy = NULL;
#endif

#define TEST_DATA_BEGIN (&__start_c_test)
#define TEST_DATA_END (&__stop_c_test)

static void test_passed(const char* testName) {
    int padlen = ( STATUS_LENGTH - strlen("Passed")) / 2;
    printf("\033[0;32m[ %*s%s%*s ]", padlen, "", "Passed", padlen, "");
    printf("\033[0;37m %s\n", testName);
}

static void test_failed(const char* testName) {
    int padlen = ( STATUS_LENGTH - strlen("Failed")) / 2;
    printf("\033[0;31m[ %*s%s%*s ]", padlen, "", "Failed", padlen, "");
    printf("\033[0;37m %s\n", testName);
}

static int run_tests() {

    //get tests
    //sort them into groups
    //run the tests
    int did_test_fail = 0;
    for (const test_struct * const* it = TEST_DATA_BEGIN; it != TEST_DATA_END; it++) {
        if (*it == NULL) {
            continue;
        }
        test_struct test = **it;
        test.run(&test);

        if (test.did_test_pass != 1) {
            did_test_fail = EXIT_FAILURE;
        }
    }
    return did_test_fail;
}

int test_main() {
    return run_tests();
}