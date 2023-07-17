#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/queue/array_queue.h"

struct _array_queue {
    size_t count;
    size_t data_size;
    size_t capacity;
    void *elements[10];
};

ArrayQueue *array_queue_create(size_t data_size) {
    ArrayQueue *queue = calloc(1, sizeof(ArrayQueue));
    queue->data_size = data_size;
    queue->capacity = 10;
    return queue;
}

ArrayQueue *array_queue_create_capacity(size_t data_size, size_t capacity) {
    ArrayQueue *queue = calloc(1, sizeof(ArrayQueue));
    queue->data_size = data_size;
    queue->capacity = capacity;
    if (queue->capacity == 0)
        queue->capacity = 10;
    return queue;
}

bool _array_queue_is_full(const ArrayQueue *queue) {
    return queue->count >= queue->capacity;
}

void _array_queue_increase_capacity(ArrayQueue *queue) {
    size_t new_capacity = (queue->capacity * 2) + 3;
    void *new_elements[new_capacity];
    for (int i = 0; i <= new_capacity; i ++) {
        if (queue->elements[i] == NULL || i > queue->capacity)
            continue;
        new_elements[i] = queue->elements[i];
    }
    queue->capacity = new_capacity;
    *queue->elements = *new_elements;
}

void array_queue_enqueue(ArrayQueue *queue, void *element);

void *array_queue_dequeue(ArrayQueue *queue);

void *array_queue_peek(ArrayQueue *queue);

bool array_queue_is_empty(const ArrayQueue *queue);

size_t array_queue_length(const ArrayQueue *queue);

char *array_queue_to_string(const ArrayQueue *queue);

void array_queue_free(ArrayQueue **queue);

void array_queue_clear(ArrayQueue *queue);