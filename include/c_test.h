#include <stdio.h>

//public macros
#define TEST(GROUP, NAME) \
	void GROUP##_##NAME##_impl(void); \
	const test_struct GROUP##_##NAME = { \
		.group_name = #GROUP, \
		.test_name = #NAME, \
		.run = &GROUP##_##NAME##_impl \
	};                       \
    REGSITER_TEST \
    const test_struct* const GROUP##_##NAME##_data##_##ptr = &GROUP##_##NAME;\
    void GROUP##_##NAME##_impl(void)

typedef struct {
    const char* group_name;
    const char* test_name;
    void (*run)(void);
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

static void runTests() {
    for (const test_struct * const* it = TEST_DATA_BEGIN; it != TEST_DATA_END; it++) {
        if (*it == NULL) {
            continue;
        }
        test_struct test = **it;
        test.run();
    }
}

int test_main() {
    runTests();
    return 0;
}