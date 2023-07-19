# include <string.h>

# include "../../../include/queue/linked_queue.h"
# include "../../test_app.h"

LinkedQueue *create_linked_queue() {
    LinkedQueue *queue = linked_queue_create(sizeof(char *));
    linked_queue_enqueue(queue, (char *) "Java");
    linked_queue_enqueue(queue, (char *) "Python");
    linked_queue_enqueue(queue, (char *) "Javascript");
    return queue;
}

void linked_queue_test_create_queue() {
    char expected[100] = {"[Java, Python, Javascript]"};
    LinkedQueue *queue = linked_queue_create(sizeof(char *));
    linked_queue_enqueue(queue, (char *) "Java");
    linked_queue_enqueue(queue, (char *) "Python");
    linked_queue_enqueue(queue, (char *) "Javascript");
    TEST_ASSERT_EQUAL(3, linked_queue_length(queue));
    TEST_ASSERT_EQUAL_STRING(expected, linked_queue_to_string(queue));
    linked_queue_free(&queue);
}

void linked_queue_test_create_queue_empty() {
    LinkedQueue *queue = linked_queue_create(sizeof(char *));
    TEST_ASSERT_EQUAL(0, linked_queue_length(queue));
    TEST_ASSERT_TRUE(linked_queue_is_empty(queue));
    linked_queue_free(&queue);
}

void linked_queue_test_dequeue_element() {
    LinkedQueue *queue = create_linked_queue();
    TEST_ASSERT_EQUAL("Java", linked_queue_dequeue(queue));
    TEST_ASSERT_EQUAL(2, linked_queue_length(queue));
    linked_queue_free(&queue);
}

void linked_queue_test_peek_element() {
    LinkedQueue *queue = create_linked_queue();
    TEST_ASSERT_EQUAL("Java", linked_queue_peek(queue));
    TEST_ASSERT_EQUAL(3, linked_queue_length(queue));
    linked_queue_free(&queue);
}

void linked_queue_test_clear_stack() {
    LinkedQueue *queue = create_linked_queue();
    linked_queue_clear(queue);
    TEST_ASSERT_TRUE(linked_queue_is_empty(queue));
    TEST_ASSERT_EQUAL_STRING("[]", linked_queue_to_string(queue));
    linked_queue_free(&queue);
}

void run_test_linked_queue() {
    RUN_TEST(linked_queue_test_create_queue);
    RUN_TEST(linked_queue_test_create_queue_empty);
    RUN_TEST(linked_queue_test_dequeue_element);
    RUN_TEST(linked_queue_test_peek_element);
    RUN_TEST(linked_queue_test_clear_stack);
}