# include "../../../include/list/array_list.h"
# include "../../test_app.h"

ArrayList *create_array_list() {
    ArrayList *list = array_list_create(sizeof(char *));
    array_list_push(list, (char *) "Java");
    array_list_push(list, (char *) "Python");
    array_list_push(list, (char *) "Javascript");
    return list;
}

void array_list_test_create_array_list() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayList *list = create_array_list();
    TEST_ASSERT_EQUAL(3, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
    array_list_free(list);
}

void array_list_test_create_list_with_capacity() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayList *list = array_list_create_capacity(sizeof(char *), 3);
    array_list_push(list, (char *) "Java");
    array_list_push(list, (char *) "Python");
    array_list_push(list, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
    array_list_free(list);
}

void array_list_test_insert_element_in_index() {
    char expected[100] = {"[Python, Javascript, C++]"};
    ArrayList *list = array_list_create_capacity(sizeof(char *), 3);
    array_list_push(list, (char *) "Java");
    array_list_push(list, (char *) "Javascript");
    array_list_push_index(list, (char *) "Python", 0);
    array_list_push_index(list, (char *) "C++", 2);
    TEST_ASSERT_EQUAL(3, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
    array_list_free(list);
}

void array_list_test_insert_element_first_index_and_last() {
    char expected[100] = {"[Python, Delphi, C++, Java, Javascript]"};
    ArrayList *list = array_list_create(sizeof(char *));
    array_list_push_index(list, (char *) "C++", 2);
    array_list_push(list, (char *) "Java");
    array_list_push(list, (char *) "Javascript");
    array_list_push_index(list, (char *) "Python", 0);
    array_list_push_index(list, (char *) "Delphi", 1);
    TEST_ASSERT_EQUAL(5, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
    array_list_free(list);
}

void array_list_test_create_list_empty() {
    ArrayList *list = array_list_create(sizeof(char *));
    TEST_ASSERT_EQUAL(0, array_list_length(list));
    TEST_ASSERT_TRUE(array_list_is_empty(list));
    array_list_free(list);
}

void array_list_test_remove_element() {
    ArrayList *list = create_array_list();
    array_list_remove(list, (char *) "Python");
    TEST_ASSERT_EQUAL(2, array_list_length(list));
    TEST_ASSERT_NULL(array_list_get_element(list, (char * ) "Python"));
    array_list_free(list);
}

void array_list_test_remove_element_at_index() {
    char expected[100] = {"[Java, Javascript]"};
    ArrayList *list = create_array_list();
    array_list_remove_index(list, 1);
    TEST_ASSERT_EQUAL(2, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
    array_list_free(list);
}

void array_list_test_remove_index_with_append() {
    char expected[100] = {"[Python, Javascript]"};
    ArrayList *list = array_list_create_capacity(sizeof(char *), 3);
    array_list_push(list, (char *) "Java");
    array_list_push(list, (char *) "Python");
    array_list_push(list, (char *) "Javascript");
    array_list_push_index(list, (char *) "Delphi", 0);
    array_list_push(list, (char *) "Java");
    array_list_remove_index(list, 0);
    array_list_remove_index(list, 3);
    TEST_ASSERT_NULL(array_list_get_element(list, (char * ) "Delphi"));
    TEST_ASSERT_NULL(array_list_get_element(list, (char * ) "Java"));
    TEST_ASSERT_EQUAL(2, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
    array_list_free(list);
}

void array_list_test_get_index_element() {
    ArrayList *list = create_array_list();
    TEST_ASSERT_EQUAL(1, array_list_index_of(list, "Python"));
}

void array_list_test_get_index_element_with_append_last_and_index() {
    ArrayList *list = create_array_list();
    array_list_push_index(list, "Delphi", 13);
    array_list_push_index(list, "C#", 0);
    array_list_push(list, "C++");
    TEST_ASSERT_EQUAL(0, array_list_index_of(list, "C#"));
    TEST_ASSERT_EQUAL(1, array_list_index_of(list, "Python"));
    TEST_ASSERT_EQUAL(13, array_list_index_of(list, "Delphi"));
    TEST_ASSERT_EQUAL(14, array_list_index_of(list, "C++"));
}

void array_list_test_get_element_by_element() {
    ArrayList *list = create_array_list();
    TEST_ASSERT_EQUAL("Python", array_list_get_element(list, "Python"));
}

void array_list_test_get_element_by_index() {
    ArrayList *list = create_array_list();
    TEST_ASSERT_EQUAL("Python", array_list_get_element_index(list, 1));
}

void array_list_test_get_element_by_index_after_insert_with_index_and_without_index() {
    ArrayList *list = array_list_create_capacity(sizeof(char *), 1);
    array_list_push_index(list, "C++", 2);
    array_list_push(list, "Java");
    array_list_push(list, "Javascript");
    array_list_push_index(list, "Python", 0);
    array_list_push_index(list, "Delphi", 1);
    TEST_ASSERT_EQUAL("C++", array_list_get_element_index(list, 2));
    TEST_ASSERT_EQUAL("Python", array_list_get_element_index(list, 0));
    TEST_ASSERT_EQUAL("Delphi", array_list_get_element_index(list, 1));
    TEST_ASSERT_EQUAL("Java", array_list_get_element_index(list, 3));
    TEST_ASSERT_EQUAL("Javascript", array_list_get_element_index(list, 4));
}

void array_list_test_clear_list() {
    ArrayList *list = create_array_list();
    array_list_clear(list);
    TEST_ASSERT_TRUE(array_list_is_empty(list));
    TEST_ASSERT_EQUAL_STRING("[]", array_list_to_string(list));
}

void run_test_array_list() {
    RUN_TEST(array_list_test_create_array_list);
    RUN_TEST(array_list_test_create_list_with_capacity);
    RUN_TEST(array_list_test_insert_element_in_index);
    RUN_TEST(array_list_test_insert_element_first_index_and_last);
    RUN_TEST(array_list_test_create_list_empty);
    RUN_TEST(array_list_test_remove_element);
    RUN_TEST(array_list_test_remove_element_at_index);
    RUN_TEST(array_list_test_remove_index_with_append);
    RUN_TEST(array_list_test_get_index_element);
    RUN_TEST(array_list_test_get_index_element_with_append_last_and_index);
    RUN_TEST(array_list_test_get_element_by_element);
    RUN_TEST(array_list_test_get_element_by_index);
    RUN_TEST(array_list_test_get_element_by_index_after_insert_with_index_and_without_index);
    RUN_TEST(array_list_test_clear_list);
}