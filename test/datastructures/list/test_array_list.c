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
}

void array_list_test_create_list_with_capacity() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayList *list = array_list_create_capacity(sizeof(char *), 3);
    array_list_push(list, (char *) "Java");
    array_list_push(list, (char *) "Python");
    array_list_push(list, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, array_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, array_list_to_string(list));
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
}

void run_test_array_list() {
    RUN_TEST(array_list_test_create_array_list);
    RUN_TEST(array_list_test_create_list_with_capacity);
    RUN_TEST(array_list_test_insert_element_in_index);
}