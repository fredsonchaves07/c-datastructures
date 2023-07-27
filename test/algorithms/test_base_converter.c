# include <string.h>

# include "../test_app.h"

# include "../../include/algorithms/base_converter.h"

void base_converter_test_should_converter_number_to_base_2() {
    char expected[100] = {"11000011111111001"};
    TEST_ASSERT_EQUAL_STRING(expected, converter(100345, 2));
}

void base_converter_test_should_converter_number_to_base_8() {
    char expected[100] = {"303771"};
    TEST_ASSERT_EQUAL_STRING(expected, converter(100345, 8));
}

void base_converter_test_should_converter_number_to_base_16() {
    char expected[100] = {"187F9"};
    TEST_ASSERT_EQUAL_STRING(expected, converter(100345, 16));
}

void run_test_base_converter() {
    RUN_TEST(base_converter_test_should_converter_number_to_base_2);
    RUN_TEST(base_converter_test_should_converter_number_to_base_8);
    RUN_TEST(base_converter_test_should_converter_number_to_base_16);
}