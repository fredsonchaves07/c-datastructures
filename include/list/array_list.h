# ifndef ARRAY_LIST
# define ARRAY_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _array_list ArrayList;

ArrayList *array_list_create(size_t data_size);

ArrayList  *array_list_create_capacity(size_t data_size, size_t capacity);

void array_list_push(ArrayList *list, void *element);

void array_list_push_index(ArrayList *list, void *element, size_t index);

bool array_list_is_empty(const ArrayList *list);

size_t array_list_length(const ArrayList *list);

char *array_list_to_string(const ArrayList *list);

#endif