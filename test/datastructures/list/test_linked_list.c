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
    linked_list_push_index(list, (char *) "C++", 3);
    TEST_ASSERT_EQUAL(4, linked_list_length(list));
    TEST_ASSERT_EQUAL_STRING(expected, linked_list_to_string(list));
}

void test_get_string_linked_list() {
    char expected[100] = {"[Java, Python, Javascript]"};
    LinkedList *list = create_list();
    printf("%s\n", linked_list_to_string(list));
    TEST_ASSERT_EQUAL_STRING(expected, linked_list_to_string(list));
}

void test_get_element() {
    LinkedList *list = create_list();
    printf("%s\n", (char *) linked_list_get_element(list));
}

void run_tests() {
    RUN_TEST(test_create_linked_list);
    RUN_TEST(test_get_string_linked_list);
    RUN_TEST(test_insert_element_index);
}

int main(void) {
    UNITY_BEGIN();
    run_tests();
    return UNITY_END();
}