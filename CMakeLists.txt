cmake_minimum_required(VERSION 3.27)
project(c_testing_framework C)

set(CMAKE_C_STANDARD 11)

add_executable(c_testing_framework main.c
        include/c_test.h)
