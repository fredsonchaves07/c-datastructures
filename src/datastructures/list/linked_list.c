#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
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

Node *_create_node(size_t size, void *element) {
    Node *node = calloc(1, sizeof(Node));
    node->next_node = NULL;
    node->element = calloc(1, size);
//    memcpy(node->element, element, size);
    return node;
}

void _add_head_node(LinkedList *list, Node *node) {
    list->head = node;
}

void _add_tail_node(LinkedList *list, Node *node) {
    Node *current_node = list->head;
    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }
    current_node->next_node = node;
}

LinkedList *linked_list_create(size_t data_size) {
    LinkedList *linkedList = calloc(1, sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->data_size = data_size;
    return linkedList;
}

void linked_list_push(LinkedList *list, void *element) {
    Node *node = _create_node(list->data_size, element);
    if (linked_list_is_empty(list)) {
        _add_head_node(list, node);
    } else {
        _add_tail_node(list, node);
    }
    list->count ++;
}

bool linked_list_is_empty(LinkedList *list) {
    return list->head == NULL;
}

int linked_list_length(LinkedList *list) {
    return list->count;
}
