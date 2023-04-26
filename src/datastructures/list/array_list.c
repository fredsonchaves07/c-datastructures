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

ArrayList  *array_list_create_capacity(size_t data_size, size_t capacity) {
    ArrayList *arrayList = calloc(1, sizeof(ArrayList));
    arrayList->data_size = data_size;
    arrayList->capacity = capacity;
    return arrayList;
}

bool _is_full(const ArrayList *list) {
    return list->count >= list->capacity;
}

void _increase_capacity(ArrayList *list) {
    list->capacity = list->capacity * 2;
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

void _add_element_first_index(ArrayList *list, void *element, size_t index) {
    if (array_list_is_empty(list) || list->elements[index] == NULL) {
        list->elements[index] = element;
        list->count +=1;
    } else {
        list->elements[index] = element;
    }
}

void _add_element_index(ArrayList *list, void *element, size_t index) {
    list->elements[index] = element;
    list->count += 1;
}

void array_list_push_index(ArrayList *list, void *element, size_t index) {
    if (_is_full(list) || index > list->capacity)
        _increase_capacity(list);
    if (array_list_is_empty(list) || index == 0)
        _add_element_first_index(list, element, index);
    else {
        _add_element_index(list, element, index);
    }
}

int array_list_index_of(const ArrayList *list, void *element) {
    for (int i = 0; i < list->capacity; i ++)
        if (list->elements[i] == element)
            return i;
    return -1;
}

void *array_list_get_element(const ArrayList *list, void *element) {
    for (int i = 0; i < list->count; i ++)
        if (list->elements[i] == element)
            return list->elements[i];
    return NULL;
}

void *array_list_get_element_index(const ArrayList *list, size_t index) {
    if (index > list->capacity)
        return NULL;
    return list->elements[index];
}

void array_list_remove(ArrayList *list, void *element) {
    for (int i = 0; i < list->count; i ++) {
        if (*list->elements != NULL && list->elements[i] == element) {
            list->elements[i] = NULL;
            list->count -= 1;
        }
    }
}

void array_list_remove_index(ArrayList *list, size_t index) {
    for (int i = 0; i < list->capacity; i ++) {
        if (i == index) {
            if (list->elements[i] != NULL) {
                list->elements[i] = NULL;
                list->count -=1;
            }
            break;
        }
    }
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
    for (int i = 0; i < list->capacity; i++) {
//        printf("%p\n", list->elements[i]);
        if (list->elements[i] != NULL) {
            if (strlen(array_list_data) > 1)
                strcat(array_list_data, ", ");
            strcat(array_list_data, list->elements[i]);
        }
    }
    return strcat(array_list_data, (char *) "]");
}

void array_list_clear(ArrayList *list) {
    for (int i = 0; i < list->count; i ++) {
        list->elements[i] = NULL;
    }
    list->count = 0;
    list->capacity = 0;
    list->data_size = 0;
}

void array_list_free(ArrayList *list) {
    array_list_clear(list);
    *list->elements = NULL;
    free(list);
    list = NULL;
}