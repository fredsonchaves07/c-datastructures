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
    char expected[100] = {"[Java, Python, Javascript]"};
    DoublyLinkedList *list = create_doubly_linked_list();
    TEST_ASSERT_EQUAL(3, doubly_linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_linked_list_to_string(list));
}

void test_get_string_doubly_linked_list() {
    char expected[100] = {"[Java, Python, Javascript]"};
    DoublyLinkedList *list = create_doubly_linked_list();
    printf("%s\n", doubly_linked_list_to_string(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_linked_list_to_string(list));
    doubly_linked_list_free(list);
}

void test_doubly_insert_element_index() {
    char expected[100] = {"[Python, Java, C++, Javascript]"};
    DoublyLinkedList *list = doubly_linked_list_create(sizeof(char *));
    doubly_linked_list_push_index(list, (char *) "Java", 1);
    doubly_linked_list_push_index(list, (char *) "Python", 0);
    doubly_linked_list_push_index(list, (char *) "Javascript", 11);
    doubly_linked_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(4, doubly_linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_linked_list_to_string(list));
    doubly_linked_list_free(list);
}

void test_doubly_insert_element_first_last_and_index() {
    char expected[100] = {"[Python, Javascript, C++]"};
    DoublyLinkedList *list = doubly_linked_list_create(sizeof(char *));
    doubly_linked_list_push(list, (char *) "Java");
    doubly_linked_list_push(list, (char *) "Javascript");
    doubly_linked_list_push_index(list, (char *) "Python", 0);
    doubly_linked_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(3, doubly_linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_linked_list_to_string(list));
    doubly_linked_list_free(list);
}

void test_doubly_insert_element_first_index_and_last() {
    char expected[100] = {"[Python, Delphi, C++, Java, Javascript]"};
    DoublyLinkedList *list = doubly_linked_list_create(sizeof(char *));
    doubly_linked_list_push_index(list, (char *) "C++", 2);
    doubly_linked_list_push(list, (char *) "Java");
    doubly_linked_list_push(list, (char *) "Javascript");
    doubly_linked_list_push_index(list, (char *) "Python", 0);
    doubly_linked_list_push_index(list, (char *) "Delphi", 1);
    TEST_ASSERT_EQUAL(5, doubly_linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_linked_list_to_string(list));
    doubly_linked_list_free(list);
}

void test_should_create_doubly_list_empty() {
    DoublyLinkedList *list = doubly_linked_list_create(sizeof(char *));
    TEST_ASSERT_TRUE(doubly_linked_list_is_empty(list));
    doubly_linked_list_free(list);
}

void test_doubly_get_element() {
    DoublyLinkedList *list = create_doubly_linked_list();
    TEST_ASSERT_NOT_NULL(doubly_linked_list_get_element(list, (char *) "Python"));
    TEST_ASSERT_EQUAL("Python", doubly_linked_list_get_element(list, (char *) "Python"));
    doubly_linked_list_free(list);
}

void run_test_doubly_linked_list() {
    RUN_TEST(test_create_doubly_linked_list);
    RUN_TEST(test_get_string_doubly_linked_list);
    RUN_TEST(test_doubly_insert_element_index);
    RUN_TEST(test_doubly_insert_element_first_last_and_index);
    RUN_TEST(test_doubly_insert_element_first_index_and_last);
    RUN_TEST(test_should_create_doubly_list_empty);
    RUN_TEST(test_doubly_get_element);
}