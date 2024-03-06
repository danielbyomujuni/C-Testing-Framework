# C Testing Framework Readme

## Introduction
The C Testing Framework is a lightweight unit testing framework for the C programming language. It allows developers to write and execute unit tests easily within their C projects.

## Features
- Simple and intuitive syntax for defining test cases
- Support for assertions to validate expected outcomes
- Automatic registration and execution of test cases
- Detailed test results output
- Easy integration into C projects

## Installation
To use the C Testing Framework in your project, follow these steps:

1. Download the `c_test.h` header file from this repository.
2. Place the `c_test.h` file in your project directory or a location where your build tool can access it.

## Usage
### Writing Test Cases
Define your test cases using the `TEST` macro provided by the framework. Each test case should have a unique name and belong to a specific group. Here's an example of how to define a test case:

```c
TEST(GroupName, TestName) {
    // Test logic and assertions
    ASSERT_EQ(1, 1);
}
```

### Assertions
The framework provides various assertion macros to validate test outcomes. Some of the commonly used assertions include:
- `ASSERT_EQ(expected, actual)`: Asserts that the expected and actual values are equal.
- `ASSERT_NOT_EQ(expected, actual)`: Asserts that the expected and actual values are not equal.
- `ASSERT_TRUE(condition)`: Asserts that the condition is true.
- `ASSERT_FALSE(condition)`: Asserts that the condition is false.
- `ASSERT_NULL(pointer)`: Asserts that the pointer is NULL.
- `ASSERT_NOT_NULL(pointer)`: Asserts that the pointer is not NULL.
- `ASSERT_ARRAY_EQ(expected_array, actual_array)`: Asserts that two arrays are equal.
- `ASSERT_ARRAY_NOT_EQ(expected_array, actual_array)`: Asserts that two arrays are not equal.

### Running Tests
To run the tests, create a separate executable with a `main` function that calls the `test_main()` function provided by the framework. Here's an example of a simple `main` function:

```c
#include "include/c_test.h"

int main() {
    return test_main();
}
```

## Example Test Cases
Here are some example test cases to demonstrate the usage of the framework:

```c
#include "include/c_test.h"

TEST(Math, Addition) {
    ASSERT_EQ(2 + 2, 4);
}

TEST(Math, Subtraction) {
    ASSERT_EQ(5 - 3, 2);
}

TEST(String, Length) {
    char str[] = "Hello";
    ASSERT_EQ(strlen(str), 5);
}

// Add more test cases as needed...
```

## Contributing
Contributions to the C Testing Framework are welcome! If you encounter any issues, have feature requests, or want to contribute enhancements, please open an issue or submit a pull request on the GitHub repository.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements
The C Testing Framework was inspired by similar frameworks for other programming languages and developed to meet the needs of C programmers for simple and efficient unit testing.

## Contact
For any inquiries or questions, please contact danielbyomujuni@nekosyndicate.com.

---

This README provides an overview of the C Testing Framework, including installation instructions, usage guidelines, example test cases, and information on contributing and licensing. Get started with unit testing in your C projects today using the C Testing Framework!