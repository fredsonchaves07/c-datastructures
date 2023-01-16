# ifndef LINKED_LIST
# define LINKED_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _linked_list LinkedList;

LinkedList *linked_list_create(size_t data_size);

void linked_list_push(LinkedList *list, void *element);

void *linked_list_get_element(const LinkedList *list);

bool linked_list_is_empty(const LinkedList *list);

int linked_list_length(const LinkedList *list);

char *linked_list_to_string(const LinkedList *list);

# endif