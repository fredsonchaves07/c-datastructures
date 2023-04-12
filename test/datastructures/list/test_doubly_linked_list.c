# include "../../../include/list/doubly_linked_list.h"
# include "../../test_app.h"

DoublyLinkedList *create_doubly_linked_list() {
    DoublyLinkedList *list = doubly_linked_list_create(sizeof(char *));
    doubly_linked_list_push(list, (char *) "Java");
    doubly_linked_list_push(list, (char *) "Python");
    doubly_linked_list_push(list, (char *) "Javascript");
    return list;
}

void test_create_doubly_linked_list() {
    DoublyLinkedList *list = create_doubly_linked_list();
    TEST_ASSERT_EQUAL(3, doubly_linked_list_length(list));
}

void run_test_doubly_linked_list() {
    RUN_TEST(test_create_doubly_linked_list);
}