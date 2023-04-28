# include "datastructures/list/test_linked_list.c"
# include "datastructures/list/test_doubly_linked_list.c"
# include "datastructures/list/test_array_list.c"

void setUp() {}

void tearDown(){}

int main() {
    UNITY_BEGIN();
    run_test_linked_list();
    run_test_doubly_linked_list();
    run_test_array_list();
    return UNITY_END();
}