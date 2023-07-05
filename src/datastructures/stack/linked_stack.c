#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/stack/linked_stack.h"

typedef struct _stack_node {
    void *element;
    struct _stack_node *next_node;
    size_t index;
} StackNode;

struct _linked_stack {
    StackNode *tail;
    size_t count;
    size_t data_size;
};

LinkedStack *linked_stack_create(size_t data_size) {
    LinkedStack *stack = calloc(1, sizeof(LinkedStack));
    stack->tail = NULL;
    stack->data_size = data_size;
    return stack;
}

StackNode *_create_stack_node(size_t size, void *element) {
    StackNode *node = calloc(1, sizeof(StackNode));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    node ->index = 0;
    return node;
}

void linked_stack_push(LinkedStack *stack, void *element) {
    StackNode *node = _create_stack_node(stack->data_size, element);
    if (!linked_stack_is_empty(stack))
        stack->tail->next_node = node;
    stack->tail = node;
    stack->count ++;
}

void *linked_stack_pop(LinkedStack *stack) {
    void *element = stack->tail->element;
    stack->tail =
}