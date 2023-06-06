# include <string.h>

# include "../../../include/list/doubly_circular_list.h"
# include "../../test_app.h"

DoublyCircularList *create_doubly_circular_list() {
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
    DoublyCircularList *list = create_doubly_circular_list();
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
    DoublyCircularList *list = create_doubly_circular_list();
    TEST_ASSERT_NOT_NULL(doubly_circular_list_get_element(list, (char *) "Python"));
    TEST_ASSERT_EQUAL("Python", doubly_circular_list_get_element(list, (char *) "Python"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_get_null_if_element_not_exist() {
    DoublyCircularList *list = create_doubly_circular_list();
    TEST_ASSERT_NULL(doubly_circular_list_get_element(list, (char * ) "Delphi"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_remove_element() {
    DoublyCircularList *list = create_doubly_circular_list();
    doubly_circular_list_remove(list, (char *) "Python");
    TEST_ASSERT_EQUAL(2, doubly_circular_list_length(list));
    TEST_ASSERT_NULL(doubly_circular_list_get_element(list, (char * ) "Python"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_not_should_remove_element_if_element_is_not_exist() {
    DoublyCircularList *list = create_doubly_circular_list();
    doubly_circular_list_remove(list, (char *) "Delphi");
    TEST_ASSERT_EQUAL(3, doubly_circular_list_length(list));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_should_remove_element_at_index() {
    DoublyCircularList *list = create_doubly_circular_list();
    doubly_circular_list_remove_index(list, 1);
    TEST_ASSERT_EQUAL(2, doubly_circular_list_length(list));
    TEST_ASSERT_NULL(doubly_circular_list_get_element(list, (char * ) "Python"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_should_remove_index_with_append() {
    DoublyCircularList *list = create_doubly_circular_list();
    doubly_circular_list_push_index(list, (char * ) "Delphi", 0);
    doubly_circular_list_push(list, (char * ) "Java");
    doubly_circular_list_remove_index(list, 0);
    doubly_circular_list_remove_index(list, 3);
    TEST_ASSERT_NULL(doubly_circular_list_get_element(list, (char * ) "Delphi"));
    TEST_ASSERT_NULL(doubly_circular_list_get_element(list, (char * ) "Java"));
    TEST_ASSERT_EQUAL(2, doubly_circular_list_length(list));
}

void doubly_circular_list_test_should_get_index_element() {
    DoublyCircularList *list = create_doubly_circular_list();
    TEST_ASSERT_EQUAL(1, circular_doubly_list_index_of(list, (char * ) "Python"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_should_get_index_element_with_append_last_and_index() {
    DoublyCircularList *list = create_doubly_circular_list();
    doubly_circular_list_push_index(list, (char * ) "Delphi", 13);
    doubly_circular_list_push_index(list, (char * ) "C#", 0);
    doubly_circular_list_push(list, (char * ) "C++");
    TEST_ASSERT_EQUAL(0, circular_doubly_list_index_of(list, (char * ) "C#"));
    TEST_ASSERT_EQUAL(1, circular_doubly_list_index_of(list, (char * ) "Python"));
    TEST_ASSERT_EQUAL(13, circular_doubly_list_index_of(list, (char * ) "Delphi"));
    TEST_ASSERT_EQUAL(14, circular_doubly_list_index_of(list, (char * ) "C++"));
}

void doubly_circular_list_test_should_get_element_by_element() {
    DoublyCircularList *list = create_doubly_circular_list();
    TEST_ASSERT_EQUAL("Python", doubly_circular_list_get_element(list, (char * ) "Python"));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_should_get_element_by_index() {
    DoublyCircularList *list = create_doubly_circular_list();
    TEST_ASSERT_EQUAL("Python", doubly_circular_list_get_element_index(list, 1));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_should_get_element_by_index_after_insert_with_index_and_without_index() {
    DoublyCircularList *list = create_doubly_circular_list();
    doubly_circular_list_push_index(list, (char *) "C++", 2);
    doubly_circular_list_push(list, (char *) "Java");
    doubly_circular_list_push(list, (char *) "Javascript");
    doubly_circular_list_push_index(list, (char *) "Python", 0);
    doubly_circular_list_push_index(list, (char *) "Delphi", 1);
    TEST_ASSERT_EQUAL("C++", doubly_circular_list_get_element_index(list, 2));
    TEST_ASSERT_EQUAL("Python", doubly_circular_list_get_element_index(list, 0));
    TEST_ASSERT_EQUAL("Delphi", doubly_circular_list_get_element_index(list, 1));
    TEST_ASSERT_EQUAL("Java", doubly_circular_list_get_element_index(list, 3));
    TEST_ASSERT_EQUAL("Javascript", doubly_circular_list_get_element_index(list, 4));
    doubly_circular_list_free(&list);
}

void doubly_circular_list_test_should_clear_list() {
    DoublyCircularList *list = create_doubly_circular_list();
    circular_doubly_list_clear(list);
    TEST_ASSERT_EQUAL(0, doubly_circular_list_length(list));
    TEST_ASSERT_TRUE(doubly_circular_list_is_empty(list));
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
    RUN_TEST(doubly_circular_list_test_remove_element);
    RUN_TEST(doubly_circular_list_test_not_should_remove_element_if_element_is_not_exist);
    RUN_TEST(doubly_circular_list_test_should_remove_element_at_index);
    RUN_TEST(doubly_circular_list_test_should_remove_index_with_append);
    RUN_TEST(doubly_circular_list_test_should_get_index_element);
    RUN_TEST(doubly_circular_list_test_should_get_index_element_with_append_last_and_index);
    RUN_TEST(doubly_circular_list_test_should_get_element_by_element);
    RUN_TEST(doubly_circular_list_test_should_get_element_by_index);
    RUN_TEST(doubly_circular_list_test_should_get_element_by_index_after_insert_with_index_and_without_index);
    RUN_TEST(doubly_circular_list_test_should_clear_list);
}