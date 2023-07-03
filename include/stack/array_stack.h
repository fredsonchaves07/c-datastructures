# ifndef ARRAY_STACK
# define ARRAY_STACK

#include <stdlib.h>
#include <stdbool.h>

typedef struct _array_stack ArrayStack;

ArrayStack *array_stack_create(size_t data_size);

ArrayStack *array_stack_create_capacity(size_t data_size, size_t capacity);

void array_stack_push(ArrayStack *stack, void *element);

bool array_stack_is_empty(const ArrayStack *list);

size_t array_stack_length(const ArrayStack *stack);

char *array_stack_to_string(const ArrayStack *stack);

void array_stack_free(ArrayStack **list);

#endif