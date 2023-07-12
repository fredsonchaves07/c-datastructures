# include <string.h>

# include "../../../include/stack/array_stack.h"
# include "../../test_app.h"

ArrayStack *create_array_stack() {
    ArrayStack *stack = array_stack_create(sizeof(char *));
    array_stack_push(stack, (char *) "Java");
    array_stack_push(stack, (char *) "Python");
    array_stack_push(stack, (char *) "Javascript");
    return stack;
}

void array_stack_test_create_stack() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayStack *stack = array_stack_create(sizeof(char *));
    array_stack_push(stack, (char *) "Java");
    array_stack_push(stack, (char *) "Python");
    array_stack_push(stack, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, array_stack_length(stack));
    TEST_ASSERT_EQUAL_STRING(expected, array_stack_to_string(stack));
    array_stack_free(&stack);
}

void array_stack_test_create_list_with_capacity() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayStack *stack = array_stack_create_capacity(sizeof(char *), 3);
    array_stack_push(stack, (char *) "Java");
    array_stack_push(stack, (char *) "Python");
    array_stack_push(stack, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, array_stack_length(stack));
    TEST_ASSERT_EQUAL_STRING(expected, array_stack_to_string(stack));
    array_stack_free(&stack);
}

void array_stack_test_create_list_empty() {
    ArrayStack *stack = array_stack_create(sizeof(char *));
    TEST_ASSERT_EQUAL(0, array_stack_length(stack));
    TEST_ASSERT_TRUE(array_stack_is_empty(stack));
    array_stack_free(&stack);
}

void array_stack_test_pop_element() {
    ArrayStack *stack = create_array_stack();
    TEST_ASSERT_EQUAL("Javascript", array_stack_pop(stack));
    TEST_ASSERT_EQUAL(2, array_stack_length(stack));
    array_stack_free(&stack);
}

void array_stack_test_peek_element() {
    ArrayStack *stack = create_array_stack();
    TEST_ASSERT_EQUAL("Javascript", array_stack_peek(stack));
    TEST_ASSERT_EQUAL(3, array_stack_length(stack));
    array_stack_free(&stack);
}

void array_stack_test_clear_stack() {
    ArrayStack *stack = create_array_stack();
    array_stack_clear(stack);
    TEST_ASSERT_TRUE(array_stack_is_empty(stack));
    TEST_ASSERT_EQUAL_STRING("[]", array_stack_to_string(stack));
    array_stack_free(&stack);
}

void run_test_array_stack() {
    RUN_TEST(array_stack_test_create_stack);
    RUN_TEST(array_stack_test_create_list_with_capacity);
    RUN_TEST(array_stack_test_create_list_empty);
    RUN_TEST(array_stack_test_pop_element);
    RUN_TEST(array_stack_test_peek_element);
    RUN_TEST(array_stack_test_clear_stack);
}