# include "datastructures/list/test_linked_list.c"
# include "datastructures/list/test_doubly_linked_list.c"
# include "datastructures/list/test_array_list.c"
# include "datastructures/list/test_doubly_circular_list.c"
# include "datastructures/stack/test_array_stack.c"
# include "datastructures/stack/test_linked_stack.c"
# include "datastructures/queue/test_array_queue.c"
# include "datastructures/queue/test_linked_queue.c"

void setUp() {}

void tearDown(){}

int main() {
    UNITY_BEGIN();
    run_test_linked_list();
    run_test_doubly_linked_list();
    run_test_array_list();
    run_test_doubly_circular_list();
    run_test_array_stack();
    run_test_linked_stack();
    run_test_array_queue();
    run_test_linked_queue();
    return UNITY_END();
}