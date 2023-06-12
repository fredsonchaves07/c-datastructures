# ifndef DOUBLY_CIRCULAR_LIST
# define DOUBLY_CIRCULAR_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _doubly_circular_list DoublyCircularList;

DoublyCircularList *doubly_circular_list_create(size_t data_size);

void doubly_circular_list_push(DoublyCircularList *list, void *element);

void doubly_circular_list_push_index(DoublyCircularList *list, void *element, size_t index);

void *doubly_circular_list_get_element(const DoublyCircularList *list, void *element);

void *doubly_circular_list_get_element_index(const DoublyCircularList *list, size_t index);

void doubly_circular_list_remove(DoublyCircularList *list, void *element);

void doubly_circular_list_remove_index(DoublyCircularList *list, size_t index);

int circular_doubly_list_index_of(const DoublyCircularList *list, void *element);

int doubly_circular_list_length(const DoublyCircularList *list);

bool doubly_circular_list_is_empty(const DoublyCircularList *list);

char *doubly_circular_list_to_string(const DoublyCircularList *list);

void circular_doubly_list_clear(DoublyCircularList *list);

void doubly_circular_list_free(DoublyCircularList **list);

#endif