# include <string.h>

# include "../../../include/list/doubly_circular_list.h"
# include "../../test_app.h"

void doubly_circular_list_test_create_list() {
    char expected[100] = {"[Java, Python, Javascript]"};
    DoublyCircularList *list = doubly_circular_list_create(sizeof(char *));
    doubly_circular_list_push(list, (char *) "Java");
    doubly_circular_list_push(list, (char *) "Python");
    doubly_circular_list_push(list, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, doubly_circular_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_circular_list_to_string(list));
    doubly_circular_list_free(&list);
}

void run_test_doubly_circular_list() {
    RUN_TEST(doubly_circular_list_test_create_list);
}