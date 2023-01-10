#include <stdlib.h>
#include <string.h>
#include "../../../include/list/linked_list.h"

typedef struct _node {
    void *element;
    struct _node *next_node;
} Node;

struct _linked_list {
    Node *head;
    size_t count;
    size_t data_size;
};

LinkedList *linked_list_create(size_t data_size) {
//    Node  *node = calloc(1, sizeof(Node));
    LinkedList *linkedList = calloc(1, sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->data_size = data_size;
    return linkedList;
}

//void linked_list_push(LinkedList *list, void *element) {
//    Node *node = calloc(1, sizeof(Node));
//    node->element = calloc(1, list->data_size);
//    memcpy(node->element, element, list->data_size);
//    if (list->head == NULL) {
//        list->head = node;
//    } else {
//        list->head->next_node = node;
//    }
//    list->count ++;
//}
