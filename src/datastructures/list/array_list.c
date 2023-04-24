#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/list/array_list.h"

struct _array_list {
    size_t count;
    size_t data_size;
    size_t capacity;
    void *elements[10];
};

ArrayList *array_list_create(size_t data_size) {
    ArrayList *arrayList = calloc(1, sizeof(ArrayList));
    arrayList->data_size = data_size;
    arrayList->capacity = 10;
    return arrayList;
}

bool _is_full(const ArrayList *list) {
    return list->count >= list->capacity;
}

void _increase_capacity(ArrayList *list) {
    list->capacity = list->count * 2;
    void *new_elements[list->capacity];
    for (int i = 0; i < list->count; i ++)
        new_elements[i] = list->elements[i];
    *list->elements = *new_elements;
}

void array_list_push(ArrayList *list, void *element) {
    if (_is_full(list)){
        _increase_capacity(list);
    }
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

bool array_list_is_empty(const ArrayList *list) {
    return list->count == 0;
}

size_t array_list_length(const ArrayList *list) {
    return list->count;
}

char *array_list_to_string(const ArrayList *list) {
    if (array_list_is_empty(list))
        return "[]";
    char *array_list_data = calloc(1, list->data_size * sizeof(char *));
    strcat(array_list_data, "[");
    for (int i = 0; i < list->count; i++) {
        strcat(array_list_data, list->elements[i]);
        if (list->elements[i + 1] != NULL)
            strcat(array_list_data, ", ");
    }
    return strcat(array_list_data, (char *) "]");
}