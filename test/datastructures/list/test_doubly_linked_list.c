# include "../../../modules/Unity/unity.h"
# include "../../../include/list/doubly_linked_list.h"

void setUp() {}

void tearDown(){}

void test_create_doubly_linked_list() {
    TEST_ASSERT_TRUE(1);
}

void run_tests() {
    RUN_TEST(test_create_doubly_linked_list);
}

int main(void) {
    UNITY_BEGIN();
    run_tests();
    return UNITY_END();
}