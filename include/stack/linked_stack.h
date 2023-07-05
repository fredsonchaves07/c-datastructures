# ifndef LINKED_STACK
# define LINKED_STACK

#include <stdlib.h>
#include <stdbool.h>

typedef struct _linked_stack LinkedStack;

LinkedStack *linked_stack_create(size_t data_size);

void linked_stack_push(LinkedStack *stack, void *element);

void *linked_stack_pop(LinkedStack *stack);

void *linked_stack_peek(LinkedStack *stack);

bool linked_stack_is_empty(const LinkedStack *list);

size_t linked_stack_length(const LinkedStack *stack);

char *linked_stack_to_string(const LinkedStack *stack);

void linked_stack_free(LinkedStack **list);

void linked_stack_clear(LinkedStack *list);

#endif