# include <string.h>

# include "../../../include/stack/array_stack.h"
# include "../../test_app.h"

void array_stack_test_create_stack() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayStack *stack = array_stack_create(sizeof(char *));
//    array_stack_push(stack, (char *) "Java");
//    array_stack_push(stack, (char *) "Python");
//    array_stack_push(stack, (char *) "Javascript");
//    TEST_ASSERT_EQUAL(3, array_stack_length(stack));
//    TEST_ASSERT_EQUAL_STRING(expected, array_stack_to_string(stack));
//    array_stack_free(&stack);
}

void run_test_array_stack() {
    RUN_TEST(array_stack_test_create_stack);
}