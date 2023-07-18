#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/queue/array_queue.h"

struct _array_queue {
    size_t count;
    size_t data_size;
    size_t capacity;
    size_t top;
    void *elements[10];
};

ArrayQueue *array_queue_create(size_t data_size) {
    ArrayQueue *queue = calloc(1, sizeof(ArrayQueue));
    queue->data_size = data_size;
    queue->capacity = 10;
    queue->top = 0;
    queue->count = 0;
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

void array_queue_enqueue(ArrayQueue *queue, void *element) {
    if (_array_queue_is_full(queue))
        _array_queue_increase_capacity(queue);
    for (int i = queue->capacity - 1; i >= 0; i --) {
        if (queue->elements[i] != NULL) {
            queue->elements[i + 1] = element;
            break;
        }
        if (queue->elements[i] == NULL && i == 0) {
            queue->elements[i] = element;
        }
    }
    queue->count += 1;
}

void *array_queue_dequeue(ArrayQueue *queue) {
    if (array_queue_is_empty(queue)) return NULL;
    void *element = queue->elements[queue->top];
    queue->elements[queue->top] = NULL;
    queue->top += 1;
    queue->count -= 1;
    return element;
}

void *array_queue_peek(ArrayQueue *queue) {
    if (array_queue_is_empty(queue)) return NULL;
    return queue->elements[queue->top];
}

bool array_queue_is_empty(const ArrayQueue *queue) {
    return queue->count == 0;
}

size_t array_queue_length(const ArrayQueue *queue) {
    return queue->count;
}

char *array_queue_to_string(const ArrayQueue *queue) {
    if (array_queue_is_empty(queue))
        return "[]";
    char *array_queue_data = calloc(1, queue->data_size * sizeof(char *));
    strcat(array_queue_data, "[");
    for (int i = 0; i < queue->capacity; i++) {
        if (queue->elements[i] != NULL) {
            if (strlen(array_queue_data) > 1)
                strcat(array_queue_data, ", ");
            strcat(array_queue_data, queue->elements[i]);
        }
    }
    return strcat(array_queue_data, (char *) "]");
}

void array_queue_free(ArrayQueue **queue) {
    ArrayQueue *stack_ref = *queue;
    array_queue_clear(*queue);
    free(stack_ref);
    queue = NULL;
}

void array_queue_clear(ArrayQueue *queue) {
    *queue->elements = NULL;
    queue->count = 0;
    queue->capacity = 0;
    queue->data_size = 0;
}