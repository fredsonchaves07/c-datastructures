# ifndef LINKED_QUEUE
# define LINKED_QUEUE

#include <stdlib.h>
#include <stdbool.h>

typedef struct _linked_queue LinkedQueue;

LinkedQueue *linked_queue_create(size_t data_size);

void linked_queue_enqueue(LinkedQueue *queue, void *element);

void *linked_queue_dequeue(LinkedQueue *queue);

void *linked_queue_peek(LinkedQueue *queue);

bool linked_queue_is_empty(const LinkedQueue *queue);

size_t linked_queue_length(const LinkedQueue *queue);

char *linked_queue_to_string(const LinkedQueue *queue);

void linked_queue_free(LinkedQueue **queue);

void linked_queue_clear(LinkedQueue *queue);

#endif