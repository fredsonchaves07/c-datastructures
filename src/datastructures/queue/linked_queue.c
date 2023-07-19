#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/queue/linked_queue.h"

typedef struct _queue_node {
    void *element;
    struct _queue_node *next_node;
} QueueNode;

struct _linked_queue {
    QueueNode *head;
    QueueNode *tail;
    size_t count;
    size_t data_size;
};

LinkedQueue *linked_queue_create(size_t data_size) {
    LinkedQueue *queue = calloc(1, sizeof(LinkedQueue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->data_size = data_size;
    queue->count = 0;
    return queue;
}

QueueNode *_create_queue_node(size_t size, void *element) {
    QueueNode *node = calloc(1, sizeof(QueueNode));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    return node;
}

void linked_queue_enqueue(LinkedQueue *queue, void *element) {
    QueueNode *node = _create_queue_node(queue->data_size, element);
    if (linked_queue_is_empty(queue))
        queue->head = node;
    else
        queue->tail->next_node = node;
    queue->tail = node;
    queue->count ++;
}

void *linked_queue_dequeue(LinkedQueue *queue) {
    if (linked_queue_is_empty(queue)) return NULL;
    void *element = queue->head->element;
    queue->head = queue->head->next_node;
    queue->count --;
    return element;
}

void *linked_queue_peek(LinkedQueue *queue) {
    if (linked_queue_is_empty(queue)) return NULL;
    return queue->head->element;
}

bool linked_queue_is_empty(const LinkedQueue *queue) {
    return queue->count == 0;
}

size_t linked_queue_length(const LinkedQueue *queue) {
    return queue->count;
}

char *linked_queue_to_string(const LinkedQueue *queue) {
    if (linked_queue_is_empty(queue)) {
        return "[]";
    }
    char *linked_queue_data = calloc(1, queue->data_size * sizeof(char *));
    strcat(linked_queue_data, "[");
    QueueNode *current_node = queue->head;
    while (current_node != NULL) {
        strcat(linked_queue_data, (char *) current_node->element);
        if (current_node->next_node != NULL) {
            strcat(linked_queue_data, ", ");
        }
        current_node = current_node->next_node;
    }
    return strcat(linked_queue_data, "]");
}

void linked_queue_free(LinkedQueue **queue) {
    LinkedQueue *stack_ref = *queue;
    linked_queue_clear(*queue);
    free(stack_ref);
    queue = NULL;
}

void linked_queue_clear(LinkedQueue *queue) {
    QueueNode *current_node = queue->head;
    QueueNode *aux_node = NULL;
    while (current_node != NULL) {
        aux_node = current_node;
        current_node = current_node->next_node;
        free(aux_node);
    }
    queue->head = NULL;
    queue->tail = NULL;
    queue->data_size = 0;
    queue->count = 0;
}