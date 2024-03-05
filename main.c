#include <stdio.h>
#include "include/c_test.h"

int main() {
    return test_main();
}

TEST(Hello, Hello) {
    printf("hello\n");
}

TEST(Hello2, Hello2) {
    printf("hello\n");
}