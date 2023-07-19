# include <string.h>

# include "../../../include/stack/linked_stack.h"
# include "../../test_app.h"

LinkedStack *create_linked_stack() {
    LinkedStack *stack = linked_stack_create(sizeof(char *));
    linked_stack_push(stack, (char *) "Java");
    linked_stack_push(stack, (char *) "Python");
    linked_stack_push(stack, (char *) "Javascript");
    return stack;
}

void linked_stack_test_create_stack() {
    char expected[100] = {"[Java, Python, Javascript]"};
    LinkedStack *stack = linked_stack_create(sizeof(char *));
    linked_stack_push(stack, (char *) "Java");
    linked_stack_push(stack, (char *) "Python");
    linked_stack_push(stack, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, linked_stack_length(stack));
    TEST_ASSERT_EQUAL_STRING(expected, linked_stack_to_string(stack));
    linked_stack_free(&stack);
}

void linked_stack_test_create_stack_empty() {
    LinkedStack *stack = linked_stack_create(sizeof(char *));
    TEST_ASSERT_EQUAL(0, linked_stack_length(stack));
    TEST_ASSERT_TRUE(linked_stack_is_empty(stack));
    linked_stack_free(&stack);
}

void linked_stack_test_pop_element() {
    LinkedStack *stack = create_linked_stack();
    TEST_ASSERT_EQUAL("Javascript", linked_stack_pop(stack));
    TEST_ASSERT_EQUAL(2, linked_stack_length(stack));
    linked_stack_free(&stack);
}

void linked_stack_test_peek_element() {
    LinkedStack *stack = create_linked_stack();
    TEST_ASSERT_EQUAL("Javascript", linked_stack_peek(stack));
    TEST_ASSERT_EQUAL(3, linked_stack_length(stack));
    linked_stack_free(&stack);
}

void linked_stack_test_clear_stack() {
    LinkedStack *stack = create_linked_stack();
    linked_stack_clear(stack);
    TEST_ASSERT_TRUE(linked_stack_is_empty(stack));
    TEST_ASSERT_EQUAL_STRING("[]", linked_stack_to_string(stack));
    linked_stack_free(&stack);
}

void run_test_linked_stack() {
    RUN_TEST(linked_stack_test_create_stack);
    RUN_TEST(linked_stack_test_create_stack_empty);
    RUN_TEST(linked_stack_test_pop_element);
    RUN_TEST(linked_stack_test_peek_element);
    RUN_TEST(linked_stack_test_clear_stack);
}