# include "../../../modules/Unity/unity.h"
# include "../../../include/list/linked_list.h"

void setUp() {}

void tearDown(){}

void test_create_linked_list() {
    LinkedList *list = linked_list_create(sizeof(int));
    linked_list_push(list, (int *) 1);
    linked_list_push(list, (int *) 5);
    linked_list_push(list, (int *) 3);
    TEST_ASSERT_EQUAL(3, linked_list_length(list));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_linked_list);
    return UNITY_END();
}