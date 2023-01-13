# include <stdlib.h>

# include "../../../modules/Unity/unity.h"
# include "../../../include/list/linked_list.h"

void setUp() {}

void tearDown(){}

void test_create_linked_list() {
    LinkedList *list = linked_list_create(sizeof(char));
    linked_list_push(list, (char *) "Java");
    linked_list_push(list, (char *) "Python");
    linked_list_push(list, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, linked_list_length(list));
}


void test_insert_element_index() {

}

void test_get_element() {
    LinkedList *list = linked_list_create(sizeof(char));
    linked_list_push(list, (char *) "Java");
    linked_list_push(list, (char *) "Python");
    linked_list_push(list, (char *) "Javascript");
    printf("%s\n\n\n", (char *) linked_list_get_element(list));
}

void run_tests() {
    RUN_TEST(test_create_linked_list);
}

int main(void) {
    UNITY_BEGIN();
    run_tests();
    return UNITY_END();
}