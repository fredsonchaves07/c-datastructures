# ifndef DOUBLY_LINKED_LIST
# define DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _doubly_linked_list DoublyLinkedList;

DoublyLinkedList *doubly_linked_list_create(size_t data_size);

void doubly_linked_list_push(DoublyLinkedList *list, void *element);

bool doubly_linked_list_is_empty(const DoublyLinkedList *list);

int doubly_linked_list_length(const DoublyLinkedList *list);

#endif