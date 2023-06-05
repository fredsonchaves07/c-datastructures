# include <string.h>

# include "../../../include/list/doubly_circular_list.h"
# include "../../test_app.h"

DoublyCircularList *create_circular_doubly_linked_list() {
    DoublyCircularList *list = doubly_circular_list_create(sizeof(char *));
    doubly_circular_list_push(list, (char *) "Java");
    doubly_circular_list_push(list, (char *) "Python");
    doubly_circular_list_push(list, (char *) "Javascript");
    return list;
}

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

void doubly_circular_list_test_get_string() {
    char expected[100] = {"[Java, Python, Javascript]"};
    DoublyCircularList *list = create_circular_doubly_linked_list();
    printf("%s\n", doubly_circular_list_to_string(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_circular_list_to_string(list));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_insert_element_index() {
    char expected[100] = {"[Python, Java, C++, Javascript]"};
    DoublyCircularList *list = doubly_circular_list_create(sizeof(char *));
    doubly_circular_list_push_index(list, (char *) "Java", 1);
    doubly_circular_list_push_index(list, (char *) "Python", 0);
    doubly_circular_list_push_index(list, (char *) "Javascript", 11);
    doubly_circular_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(4, doubly_circular_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_circular_list_to_string(list));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_insert_element_first_last_and_index() {
    char expected[100] = {"[Python, Javascript, C++]"};
    DoublyCircularList *list = doubly_circular_list_create(sizeof(char *));
    doubly_circular_list_push(list, (char *) "Java");
    doubly_circular_list_push(list, (char *) "Javascript");
    doubly_circular_list_push_index(list, (char *) "Python", 0);
    doubly_circular_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(3, doubly_circular_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_circular_list_to_string(list));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_insert_element_first_index_and_last() {
    char expected[100] = {"[Python, Delphi, C++, Java, Javascript]"};
    DoublyCircularList *list = doubly_circular_list_create(sizeof(char *));
    doubly_circular_list_push_index(list, (char *) "C++", 2);
    doubly_circular_list_push(list, (char *) "Java");
    doubly_circular_list_push(list, (char *) "Javascript");
    doubly_circular_list_push_index(list, (char *) "Python", 0);
    doubly_circular_list_push_index(list, (char *) "Delphi", 1);
    TEST_ASSERT_EQUAL(5, doubly_circular_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, doubly_circular_list_to_string(list));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_list_empty() {
    DoublyCircularList *list = doubly_circular_list_create(sizeof(char *));
    TEST_ASSERT_TRUE(doubly_circular_list_is_empty(list));
}

void doubly_circular_list_test_get_element() {
    DoublyCircularList *list = create_circular_doubly_linked_list();
    TEST_ASSERT_NOT_NULL(doubly_circular_list_get_element(list, (char *) "Python"));
    TEST_ASSERT_EQUAL("Python", doubly_circular_list_get_element(list, (char *) "Python"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_get_null_if_element_not_exist() {
    DoublyCircularList *list = create_circular_doubly_linked_list();
    TEST_ASSERT_NULL(doubly_circular_list_get_element(list, (char * ) "Delphi"));
    doubly_circular_list_free(&list);
}

void run_test_doubly_circular_list() {
    RUN_TEST(doubly_circular_list_test_create_list);
    RUN_TEST(doubly_circular_list_test_get_string);
    RUN_TEST(doubly_circular_list_test_insert_element_index);
    RUN_TEST(doubly_circular_list_test_insert_element_first_last_and_index);
    RUN_TEST(doubly_circular_list_test_insert_element_first_index_and_last);
    RUN_TEST(doubly_circular_list_test_list_empty);
    RUN_TEST(doubly_circular_list_test_get_element);
    RUN_TEST(doubly_circular_list_test_get_null_if_element_not_exist);
}