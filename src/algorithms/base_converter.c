#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/algorithms/base_converter.h"
#include "../../include/stack/linked_stack.h"

char DIGITS[100] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

char *converter(size_t number, size_t base) {
    LinkedStack *stack = linked_stack_create(sizeof(char *));
    while (number > 0) {
        int rem = number % base;
        number = number / base;
        int *rem_index = (int *) rem;
        linked_stack_push(stack, (int *) rem_index);
    }
    char *base_converter_string = calloc(1, linked_stack_length(stack) * sizeof(char *));
    while (!linked_stack_is_empty(stack)) {
        char element_char[sizeof(linked_stack_length(stack)) + 10000];
        char char_at[2];
        void *element = linked_stack_pop(stack);
        sprintf(element_char, "%d", element);
        char_at[0] = DIGITS[atoi(element_char)];
        strcat(base_converter_string, &char_at[0]);
    }
    return base_converter_string;
}