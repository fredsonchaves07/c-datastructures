# ifndef DOUBLY_CIRCULAR_LIST
# define DOUBLY_CIRCULAR_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _doubly_circular_list DoublyCircularList;

DoublyCircularList *doubly_circular_list_create(size_t data_size);

void doubly_circular_list_push(DoublyCircularList *list, void *element);

int doubly_circular_list_length(const DoublyCircularList *list);

bool doubly_circular_list_is_empty(const DoublyCircularList *list);

char *doubly_circular_list_to_string(const DoublyCircularList *list);

#endif