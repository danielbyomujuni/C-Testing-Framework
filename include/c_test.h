#include <stdio.h>

//public macros
#define TEST(GROUP, NAME) \
	void GROUP##_##NAME##_impl(void); \
	const test_struct GROUP##_##NAME = { \
		.group_name = #GROUP, \
		.test_name = #NAME, \
		.run = &GROUP##_##NAME##_impl \
	};                       \
    __attribute((used, section("c_test")) \
    const test_struct* const GROUP##_##NAME##_data##_##ptr = &GROUP##_##NAME##_data;\
    void GROUP##_##NAME##_impl(void)

typedef struct {
    const char* group_name;
    const char* test_name;
    void (*run)(void);
} test_struct;
//__declspec(allocate("c_test$begin")) const test_struct* const test_data_begin = NULL;
//__declspec(allocate("c_test$end")) const test_struct* const test_data_end = NULL;

int test_main() {
    //tests[0].run();
    return 0;
}