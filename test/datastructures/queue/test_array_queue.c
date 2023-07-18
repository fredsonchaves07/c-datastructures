# include <string.h>

# include "../../../include/queue/array_queue.h"
# include "../../test_app.h"

ArrayQueue *create_array_queue() {
    ArrayQueue *queue = array_queue_create(sizeof(char *));
    array_queue_enqueue(queue, (char *) "Java");
    array_queue_enqueue(queue, (char *) "Python");
    array_queue_enqueue(queue, (char *) "Javascript");
    return queue;
}

void array_queue_test_create_queue() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayQueue *queue = array_queue_create(sizeof(char *));
    array_queue_enqueue(queue, (char *) "Java");
    array_queue_enqueue(queue, (char *) "Python");
    array_queue_enqueue(queue, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, array_queue_length(queue));
    TEST_ASSERT_EQUAL_STRING(expected, array_queue_to_string(queue));
    array_queue_free(&queue);
}

void array_queue_test_create_queue_with_capacity() {
    char expected[100] = {"[Java, Python, Javascript]"};
    ArrayQueue *queue = array_queue_create_capacity(sizeof(char *), 3);
    array_queue_enqueue(queue, (char *) "Java");
    array_queue_enqueue(queue, (char *) "Python");
    array_queue_enqueue(queue, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, array_queue_length(queue));
    TEST_ASSERT_EQUAL_STRING(expected, array_queue_to_string(queue));
    array_queue_free(&queue);
}

void array_queue_test_create_queue_empty() {
    ArrayQueue *queue = array_queue_create(sizeof(char *));
    TEST_ASSERT_EQUAL(0, array_queue_length(queue));
    TEST_ASSERT_TRUE(array_queue_is_empty(queue));
    array_queue_free(&queue);
}

void array_queue_test_enqueue_element() {
    ArrayQueue *queue = create_array_queue();
    TEST_ASSERT_EQUAL("Java", array_queue_dequeue(queue));
    TEST_ASSERT_EQUAL(2, array_queue_length(queue));
    array_queue_free(&queue);
}

void array_queue_test_peek_element() {
    ArrayQueue *queue = create_array_queue();
    TEST_ASSERT_EQUAL("Java", array_queue_peek(queue));
    TEST_ASSERT_EQUAL(3, array_queue_length(queue));
    array_queue_free(&queue);
}

void array_queue_test_clear_queue() {
    ArrayQueue *queue = create_array_queue();
    array_queue_clear(queue);
    TEST_ASSERT_TRUE(array_queue_is_empty(queue));
    TEST_ASSERT_EQUAL_STRING("[]", array_queue_to_string(queue));
    array_queue_free(&queue);
}

void run_test_array_queue() {
    RUN_TEST(array_queue_test_create_queue);
    RUN_TEST(array_queue_test_create_queue_with_capacity);
    RUN_TEST(array_queue_test_create_queue_empty);
    RUN_TEST(array_queue_test_enqueue_element);
    RUN_TEST(array_queue_test_peek_element);
    RUN_TEST(array_queue_test_clear_queue);
}