#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../../../include/list/linked_list.h"

typedef struct _node {
    int index;
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
    node->element = malloc(size * sizeof(element));
    node->element = element;
    return node;
}

void _add_head_node(LinkedList *list, Node *node) {
    list->head = node;
    node->index = 0;
}

void _add_tail_node(LinkedList *list, Node *node) {
    Node *current_node = list->head;
    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }
    current_node->next_node = node;
    current_node->index = linked_list_length(list);
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

void *linked_list_get_element(const LinkedList *list) {
    return list->head->element;
}

bool linked_list_is_empty(const LinkedList *list) {
    return list->head == NULL;
}

int linked_list_length(const LinkedList *list) {
    return list->count;
}

char *linked_list_to_string(const LinkedList *list) {
    if (linked_list_is_empty(list)) {
        return "[]";
    }
    char *linked_list_data = calloc(1, list->data_size * sizeof(char *));
    strcat(linked_list_data, "[");
    Node *current_node = list->head;
    while (current_node != NULL) {
        strcat(linked_list_data, (char *) current_node->element);
        if (current_node->next_node != NULL) {
            strcat(linked_list_data, ", ");
        }
        current_node = current_node->next_node;
    }
    return strcat(linked_list_data, "]");
}
