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

bool _array_stack_is_full(const ArrayStack *list) {
    return list->count >= list->capacity;
}

void _array_stack_increase_capacity(ArrayStack *list) {
    size_t new_capacity = (list->capacity * 2) + 3;
    void *new_elements[new_capacity];
    for (int i = 0; i <= new_capacity; i ++) {
        if (list->elements[i] == NULL || i > list->capacity)
            continue;
        new_elements[i] = list->elements[i];
    }
    list->capacity = new_capacity;
    *list->elements = *new_elements;
}

void array_stack_push(ArrayStack *list, void *element) {
    if (_array_stack_is_full(list))
        _array_stack_increase_capacity(list);
    for (int i = list->capacity - 1; i >= 0; i --) {
        if (list->elements[i] != NULL) {
            list->elements[i + 1] = element;
            break;
        }
        if (list->elements[i] == NULL && i == 0) {
            list->elements[i] = element;
        }
    }
    list->count += 1;
}

void array_stack_remove(ArrayStack *stack, void *element) {
    for (int i = 0; i < stack->count; i ++) {
        if (*stack->elements != NULL && stack->elements[i] == element) {
            stack->elements[i] = NULL;
            stack->count -= 1;
        }
    }
}

void *array_stack_pop(ArrayStack *stack) {
    if (array_stack_is_empty(stack)) return NULL;
    void *element = stack->elements[array_stack_length(stack)];
    stack->count -= 1;
    return element;
}

void *array_stack_peek(ArrayStack *stack) {
    return stack->elements[array_stack_length(stack) - 1];
}

void _array_stack_increase_capacity_index(ArrayStack *list, size_t index) {
    size_t new_capacity;
    if (index > list->capacity)
        new_capacity = index + 2;
    else
        new_capacity = (list->capacity * 2) + index;
    void *new_elements[list->capacity];
    for (int i = 0; i <= new_capacity; i ++) {
        if (list->elements[i] == NULL || i > list->capacity)
            continue;
        new_elements[i] = list->elements[i];
    }
    list->capacity = new_capacity;
    *list->elements = *new_elements;
}

void _array_stack_add_element_first_index(ArrayStack *list, void *element, size_t index) {
    if (array_stack_is_empty(list) || list->elements[index] == NULL) {
        list->elements[index] = element;
        list->count +=1;
    } else {
        list->elements[index] = element;
    }
}

void _array_stack_add_element_index(ArrayStack *list, void *element, size_t index) {
    if (index > list->capacity)
        _array_stack_increase_capacity_index(list, index);
    list->elements[index] = element;
    list->count += 1;
}

void array_stack_push_index(ArrayStack *list, void *element, size_t index) {
    if (_array_stack_is_full(list) || index >= list->capacity)
        _array_stack_increase_capacity_index(list, index);
    if (array_stack_is_empty(list) || index == 0)
        _array_stack_add_element_first_index(list, element, index);
    else {
        _array_stack_add_element_index(list, element, index);
    }
}

bool array_stack_is_empty(const ArrayStack *list) {
    return list->count == 0;
}

size_t array_stack_length(const ArrayStack *list) {
    return list->count;
}

char *array_stack_to_string(const ArrayStack *list) {
    if (array_stack_is_empty(list))
        return "[]";
    char *array_list_data = calloc(1, list->data_size * sizeof(char *));
    strcat(array_list_data, "[");
    for (int i = 0; i < list->capacity; i++) {
        if (list->elements[i] != NULL) {
            if (strlen(array_list_data) > 1)
                strcat(array_list_data, ", ");
            strcat(array_list_data, list->elements[i]);
        }
    }
    return strcat(array_list_data, (char *) "]");
}

void array_stack_clear(ArrayStack *list) {
    *list->elements = NULL;
    list->count = 0;
    list->capacity = 0;
    list->data_size = 0;
}

void array_stack_free(ArrayStack **stack) {
    ArrayStack *list_ref = *stack;
    array_stack_clear(*stack);
    free(list_ref);
    stack = NULL;
}