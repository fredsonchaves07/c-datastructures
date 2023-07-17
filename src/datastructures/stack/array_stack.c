#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/stack/array_stack.h"

struct _array_stack {
    size_t count;
    size_t data_size;
    size_t capacity;
    void *elements[10];
};

ArrayStack *array_stack_create(size_t data_size) {
    ArrayStack *arrayStack = calloc(1, sizeof(ArrayStack));
    arrayStack->data_size = data_size;
    arrayStack->capacity = 10;
    return arrayStack;
}

ArrayStack  *array_stack_create_capacity(size_t data_size, size_t capacity) {
    ArrayStack *arrayStack = calloc(1, sizeof(ArrayStack));
    arrayStack->data_size = data_size;
    arrayStack->capacity = capacity;
    if (arrayStack->capacity == 0)
        arrayStack->capacity = 10;
    return arrayStack;
}

bool _array_stack_is_full(const ArrayStack *stack) {
    return stack->count >= stack->capacity;
}

void _array_stack_increase_capacity(ArrayStack *stack) {
    size_t new_capacity = (stack->capacity * 2) + 3;
    void *new_elements[new_capacity];
    for (int i = 0; i <= new_capacity; i ++) {
        if (stack->elements[i] == NULL || i > stack->capacity)
            continue;
        new_elements[i] = stack->elements[i];
    }
    stack->capacity = new_capacity;
    *stack->elements = *new_elements;
}

void array_stack_push(ArrayStack *stack, void *element) {
    if (_array_stack_is_full(stack))
        _array_stack_increase_capacity(stack);
    for (int i = stack->capacity - 1; i >= 0; i --) {
        if (stack->elements[i] != NULL) {
            stack->elements[i + 1] = element;
            break;
        }
        if (stack->elements[i] == NULL && i == 0) {
            stack->elements[i] = element;
        }
    }
    stack->count += 1;
}

void *array_stack_pop(ArrayStack *stack) {
    if (array_stack_is_empty(stack)) return NULL;
    void *element = stack->elements[array_stack_length(stack) - 1];
    stack->count -= 1;
    return element;
}

void *array_stack_peek(ArrayStack *stack) {
    if (array_stack_is_empty(stack)) return NULL;
    return stack->elements[array_stack_length(stack) - 1];
}

void _array_stack_increase_capacity_index(ArrayStack *stack, size_t index) {
    size_t new_capacity;
    if (index > stack->capacity)
        new_capacity = index + 2;
    else
        new_capacity = (stack->capacity * 2) + index;
    void *new_elements[stack->capacity];
    for (int i = 0; i <= new_capacity; i ++) {
        if (stack->elements[i] == NULL || i > stack->capacity)
            continue;
        new_elements[i] = stack->elements[i];
    }
    stack->capacity = new_capacity;
    *stack->elements = *new_elements;
}

void _array_stack_add_element_first_index(ArrayStack *stack, void *element, size_t index) {
    if (array_stack_is_empty(stack) || stack->elements[index] == NULL) {
        stack->elements[index] = element;
        stack->count +=1;
    } else {
        stack->elements[index] = element;
    }
}

void _array_stack_add_element_index(ArrayStack *stack, void *element, size_t index) {
    if (index > stack->capacity)
        _array_stack_increase_capacity_index(stack, index);
    stack->elements[index] = element;
    stack->count += 1;
}

void array_stack_push_index(ArrayStack *stack, void *element, size_t index) {
    if (_array_stack_is_full(stack) || index >= stack->capacity)
        _array_stack_increase_capacity_index(list, index);
    if (array_stack_is_empty(stack) || index == 0)
        _array_stack_add_element_first_index(stack, element, index);
    else {
        _array_stack_add_element_index(stack, element, index);
    }
}

bool array_stack_is_empty(const ArrayStack *stack) {
    return stack->count == 0;
}

size_t array_stack_length(const ArrayStack *stack) {
    return stack->count;
}

char *array_stack_to_string(const ArrayStack *stack) {
    if (array_stack_is_empty(stack))
        return "[]";
    char *array_stack_data = calloc(1, stack->data_size * sizeof(char *));
    strcat(array_stack_data, "[");
    for (int i = 0; i < stack->capacity; i++) {
        if (stack->elements[i] != NULL) {
            if (strlen(array_stack_data) > 1)
                strcat(array_stack_data, ", ");
            strcat(array_stack_data, stack->elements[i]);
        }
    }
    return strcat(array_stack_data, (char *) "]");
}

void array_stack_clear(ArrayStack *stack) {
    *stack->elements = NULL;
    stack->count = 0;
    stack->capacity = 0;
    stack->data_size = 0;
}

void array_stack_free(ArrayStack **stack) {
    ArrayStack *stack_ref = *stack;
    array_stack_clear(*stack);
    free(stack_ref);
    stack = NULL;
}