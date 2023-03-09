# ifndef LINKED_LIST
# define LINKED_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _linked_list LinkedList;

LinkedList *linked_list_create(size_t data_size);

void linked_list_push(LinkedList *list, void *element);

void linked_list_push_index(LinkedList *list, void *element, size_t index);

int linked_list_index_of(const LinkedList *list, void *element);

void *linked_list_get_element(const LinkedList *list, void *element);

void *linked_list_get_element_index(const LinkedList *list, size_t index);

void linked_list_remove(LinkedList *list, void *element);

void linked_list_remove_index(LinkedList *list, size_t index);

bool linked_list_is_empty(const LinkedList *list);

int linked_list_length(const LinkedList *list);

char *linked_list_to_string(const LinkedList *list);

void linked_list_clear(LinkedList *list);

void linked_list_free(LinkedList *list);

# endif