# include <stdlib.h>
# include <string.h>

# include "../../../modules/Unity/unity.h"
# include "../../../include/list/linked_list.h"

void setUp() {}

void tearDown(){}

LinkedList *create_list() {
    LinkedList *list = linked_list_create(sizeof(char *));
    linked_list_push(list, (char *) "Java");
    linked_list_push(list, (char *) "Python");
    linked_list_push(list, (char *) "Javascript");
    return list;
}

void test_create_linked_list() {
    LinkedList *list = create_list();
    TEST_ASSERT_EQUAL(3, linked_list_length(list));
}

void test_insert_element_index() {
    char expected[100] = {"[Python, Java, C++, Javascript]"};
    LinkedList *list = linked_list_create(sizeof(char *));
    linked_list_push_index(list, (char *) "Java", 1);
    linked_list_push_index(list, (char *) "Python", 0);
    linked_list_push_index(list, (char *) "Javascript", 11);
    linked_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(4, linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, linked_list_to_string(list));
    linked_list_free(list);
}

void test_insert_element_first_last_and_index() {
    char expected[100] = {"[Python, Javascript, C++]"};
    LinkedList *list = linked_list_create(sizeof(char *));
    linked_list_push(list, (char *) "Java");
    linked_list_push(list, (char *) "Javascript");
    linked_list_push_index(list, (char *) "Python", 0);
    linked_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(3, linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, linked_list_to_string(list));
    linked_list_free(list);
}

void test_insert_element_first_index_and_last() {
    char expected[100] = {"[Python, Delphi, C++, Java, Javascript]"};
    LinkedList *list = linked_list_create(sizeof(char *));
    linked_list_push_index(list, (char *) "C++", 2);
    linked_list_push(list, (char *) "Java");
    linked_list_push(list, (char *) "Javascript");
    linked_list_push_index(list, (char *) "Python", 0);
    linked_list_push_index(list, (char *) "Delphi", 1);
    TEST_ASSERT_EQUAL(5, linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, linked_list_to_string(list));
    linked_list_free(list);
}

void test_get_string_linked_list() {
    char expected[100] = {"[Java, Python, Javascript]"};
    LinkedList *list = create_list();
    printf("%s\n", linked_list_to_string(list));
    TEST_ASSERT_EQUAL_STRING(expected, linked_list_to_string(list));
    linked_list_free(list);
}

void test_should_create_list_empty() {
    LinkedList *list = linked_list_create(sizeof(char *));
    TEST_ASSERT_TRUE(linked_list_is_empty(list));
    linked_list_free(list);
}

void test_get_element() {
    LinkedList *list = create_list();
    TEST_ASSERT_NOT_NULL(linked_list_get_element(list, (char *) "Python"));
    TEST_ASSERT_EQUAL("Python", linked_list_get_element(list, (char *) "Python"));
    linked_list_free(list);
}

void test_get_null_if_element_not_exist() {
    LinkedList *list = create_list();
    TEST_ASSERT_NULL(linked_list_get_element(list, (char * ) "Delphi"));
    linked_list_free(list);
}

void test_should_remove_element() {
    LinkedList *list = create_list();
    linked_list_remove(list, (char *) "Python");
    TEST_ASSERT_EQUAL(2, linked_list_length(list));
    TEST_ASSERT_NULL(linked_list_get_element(list, (char * ) "Python"));
    linked_list_free(list);
}

void test_not_should_remove_element_if_element_is_not_exist() {
    LinkedList *list = create_list();
    linked_list_remove(list, (char *) "Delphi");
    TEST_ASSERT_EQUAL(3, linked_list_length(list));
    linked_list_free(list);
}

void test_should_remove_element_at_index() {
    LinkedList *list = create_list();
    linked_list_remove_index(list, 1);
    TEST_ASSERT_EQUAL(2, linked_list_length(list));
    TEST_ASSERT_NULL(linked_list_get_element(list, (char * ) "Python"));
    linked_list_free(list);
}

void test_should_remove_index_with_append() {
    LinkedList *list = create_list();
    linked_list_push_index(list, (char * ) "Delphi", 0);
    linked_list_push(list, (char * ) "Java");
    linked_list_remove_index(list, 0);
    linked_list_remove_index(list, 3);
    TEST_ASSERT_NULL(linked_list_get_element(list, (char * ) "Delphi"));
    TEST_ASSERT_NULL(linked_list_get_element(list, (char * ) "Java"));
    TEST_ASSERT_EQUAL(2, linked_list_length(list));
}

void test_should_get_index_element() {
    LinkedList *list = create_list();
    TEST_ASSERT_EQUAL(1, linked_list_index_of(list, (char * ) "Python"));
    linked_list_free(list);
}

void test_should_get_element_by_element() {
    LinkedList *list = create_list();
    TEST_ASSERT_EQUAL("Python", linked_list_get_element(list, (char * ) "Python"));
    linked_list_free(list);
}

void test_should_get_element_by_index() {
    LinkedList *list = create_list();
    TEST_ASSERT_EQUAL("Python", linked_list_get_element_index(list, 1));
    linked_list_free(list);
}

void test_should_get_element_by_index_after_insert_with_index_and_without_index() {
    LinkedList *list = linked_list_create(sizeof(char *));
    linked_list_push_index(list, (char *) "C++", 2);
    linked_list_push(list, (char *) "Java");
    linked_list_push(list, (char *) "Javascript");
    linked_list_push_index(list, (char *) "Python", 0);
    linked_list_push_index(list, (char *) "Delphi", 1);
    TEST_ASSERT_EQUAL("C++", linked_list_get_element_index(list, 2));
    TEST_ASSERT_EQUAL("Python", linked_list_get_element_index(list, 0));
    TEST_ASSERT_EQUAL("Delphi", linked_list_get_element_index(list, 1));
    TEST_ASSERT_EQUAL("Java", linked_list_get_element_index(list, 3));
    TEST_ASSERT_EQUAL("Javascript", linked_list_get_element_index(list, 4));
    linked_list_free(list);
}

void test_should_clear_list() {
    LinkedList *list = create_list();
    linked_list_clear(list);
    TEST_ASSERT_EQUAL(0, linked_list_length(list));
    TEST_ASSERT_TRUE(linked_list_is_empty(list));
    linked_list_free(list);
}

void run_tests() {
    RUN_TEST(test_create_linked_list);
    RUN_TEST(test_get_string_linked_list);
    RUN_TEST(test_insert_element_index);
    RUN_TEST(test_insert_element_first_last_and_index);
    RUN_TEST(test_insert_element_first_index_and_last);
    RUN_TEST(test_should_create_list_empty);
    RUN_TEST(test_get_element);
    RUN_TEST(test_get_null_if_element_not_exist);
    RUN_TEST(test_should_remove_element);
    RUN_TEST(test_not_should_remove_element_if_element_is_not_exist);
    RUN_TEST(test_should_remove_element_at_index);
    RUN_TEST(test_should_remove_index_with_append);
    RUN_TEST(test_should_get_index_element);
    RUN_TEST(test_should_get_element_by_element);
    RUN_TEST(test_should_get_element_by_index);
    RUN_TEST(test_should_get_element_by_index_after_insert_with_index_and_without_index);
    RUN_TEST(test_should_clear_list);
}

int main(void) {
    UNITY_BEGIN();
    run_tests();
    return UNITY_END();
}