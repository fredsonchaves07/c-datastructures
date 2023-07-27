# include <string.h>

# include "../test_app.h"

# include "../../include/algorithms/decimal_to_binary.h"

void decimal_to_binary_test_should_converter_numbers() {
    TEST_ASSERT_EQUAL_STRING("11101001", execute(233));
    TEST_ASSERT_EQUAL_STRING("1010", execute(10));
    TEST_ASSERT_EQUAL_STRING("1111101000", execute(1000));
};

void run_test_decimal_to_binary() {
    RUN_TEST(decimal_to_binary_test_should_converter_numbers);
}