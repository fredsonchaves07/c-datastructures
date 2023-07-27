#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/stack/linked_stack.h"

typedef struct _stack_node {
    void *element;
    struct _stack_node *next_node;
} StackNode;

struct _linked_stack {
    StackNode *head;
    StackNode *tail;
    size_t count;
    size_t data_size;
};

LinkedStack *linked_stack_create(size_t data_size) {
    LinkedStack *stack = calloc(1, sizeof(LinkedStack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->data_size = data_size;
    stack->count = 0;
    return stack;
}

StackNode *_create_stack_node(size_t size, void *element) {
    StackNode *node = calloc(1, sizeof(StackNode));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    return node;
}

void linked_stack_push(LinkedStack *stack, void *element) {
    StackNode *node = _create_stack_node(stack->data_size, element);
    if (linked_stack_is_empty(stack))
        stack->head = node;
    else
        stack->tail->next_node = node;
    stack->tail = node;
    stack->count ++;
}

StackNode *_get_before_stack_node(const LinkedStack *stack, StackNode *node) {
    StackNode *current_node = stack->head;
    while (current_node->next_node != NULL) {
        if (current_node->next_node == node) return current_node;
        current_node = current_node->next_node;
    }
    return NULL;
}

void *linked_stack_pop(LinkedStack *stack) {
    if (linked_stack_is_empty(stack)) return NULL;
    void *element = stack->tail->element;
    stack->tail = _get_before_stack_node(stack, stack->tail);
    if (stack->tail != NULL)
        stack->tail->next_node = NULL;
    stack->count --;
    return element;
}

void *linked_stack_peek(LinkedStack *stack) {
    if (linked_stack_is_empty(stack)) return NULL;
    return  stack->tail->element;
}

bool linked_stack_is_empty(const LinkedStack *stack) {
    return stack->count == 0;
}

size_t linked_stack_length(const LinkedStack *stack) {
    return stack->count;
}

char *linked_stack_to_string(const LinkedStack *stack) {
    if (linked_stack_is_empty(stack)) {
        return "[]";
    }
    char *linked_stack_data = calloc(1, stack->data_size * sizeof(char *));
    strcat(linked_stack_data, "[");
    StackNode *current_node = stack->head;
    while (current_node != NULL) {
        strcat(linked_stack_data, (char *) current_node->element);
        if (current_node->next_node != NULL) {
            strcat(linked_stack_data, ", ");
        }
        current_node = current_node->next_node;
    }
    return strcat(linked_stack_data, "]");
}

void linked_stack_clear(LinkedStack *stack) {
    StackNode *current_node = stack->head;
    StackNode *aux_node = NULL;
    while (current_node != NULL) {
        aux_node = current_node;
        current_node = current_node->next_node;
        free(aux_node);
    }
    stack->head = NULL;
    stack->tail = NULL;
    stack->data_size = 0;
    stack->count = 0;
}

void linked_stack_free(LinkedStack **stack) {
    LinkedStack *stack_ref = *stack;
    linked_stack_clear(*stack);
    free(stack_ref);
    stack = NULL;
}
