# include <string.h>

# include "../test_app.h"

# include "../../include/algorithms/palindrome.h"

void palindrome_should_string_is_palindrome() {
    TEST_ASSERT_TRUE(is_palindrome("Ana"));
    TEST_ASSERT_TRUE(is_palindrome("A babá baba"));
    TEST_ASSERT_TRUE(is_palindrome("Socorram me subi no onibus em Marrocos"));
};

void palindrome_should_string_is_no_palindrome() {
    TEST_ASSERT_FALSE(is_palindrome("Jhon"));
    TEST_ASSERT_FALSE(is_palindrome("O cachorro late"));
};

void run_test_palindrome() {
    RUN_TEST(palindrome_should_string_is_palindrome);
    RUN_TEST(palindrome_should_string_is_no_palindrome);
}