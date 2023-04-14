# ifndef DOUBLY_LINKED_LIST
# define DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <stdbool.h>

typedef struct _doubly_linked_list DoublyLinkedList;

DoublyLinkedList *doubly_linked_list_create(size_t data_size);

void doubly_linked_list_push(DoublyLinkedList *list, void *element);

void doubly_linked_list_push_index(DoublyLinkedList *list, void *element, size_t index);

void *doubly_linked_list_get_element(const DoublyLinkedList *list, void *element);

void doubly_linked_list_remove(DoublyLinkedList *list, void *element);

void doubly_linked_list_remove_index(DoublyLinkedList *list, size_t index);

bool doubly_linked_list_is_empty(const DoublyLinkedList *list);

int doubly_linked_list_length(const DoublyLinkedList *list);

char *doubly_linked_list_to_string(const DoublyLinkedList *list);

void doubly_linked_list_clear(DoublyLinkedList *list);

void doubly_linked_list_free(DoublyLinkedList *list);

#endif