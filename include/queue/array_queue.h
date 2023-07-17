# ifndef ARRAY_QUEUE
# define ARRAY_QUEUE

#include <stdlib.h>
#include <stdbool.h>

typedef struct _array_queue ArrayQueue;

ArrayQueue *array_queue_create(size_t data_size);

ArrayQueue *array_queue_create_capacity(size_t data_size, size_t capacity);

void array_queue_enqueue(ArrayQueue *queue, void *element);

void *array_queue_dequeue(ArrayQueue *queue);

void *array_queue_peek(ArrayQueue *queue);

bool array_queue_is_empty(const ArrayQueue *queue);

size_t array_queue_length(const ArrayQueue *queue);

char *array_queue_to_string(const ArrayQueue *queue);

void array_queue_free(ArrayQueue **queue);

void array_queue_clear(ArrayQueue *queue);

#endif