# include <string.h>

# include "../test_app.h"

# include "../../include/algorithms/hot_potato.h"

void hot_potato_test_should_execute_hot_potato() {
    ArrayList *names = array_list_create(sizeof (char *));
    char expected[100] = {"Eliminated: [Camila, Jack, Carl, Ingrid]\nWinner: Jhon\n"};
    array_list_push(names, "Jhon");
    array_list_push(names, "Jack");
    array_list_push(names, "Camila");
    array_list_push(names, "Ingrid");
    array_list_push(names, "Carl");
    TEST_ASSERT_EQUAL_STRING(expected, hot_potato_execute(names, 7));
};

void run_test_hot_potato() {
    RUN_TEST(hot_potato_test_should_execute_hot_potato);
}