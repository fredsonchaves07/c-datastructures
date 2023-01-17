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

LinkedList *linked_list_create(size_t data_size) {
    LinkedList *linkedList = calloc(1, sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->data_size = data_size;
    return linkedList;
}

Node *_create_node(size_t size, void *element) {
    Node *node = calloc(1, sizeof(Node));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    return node;
}

void _add_element_first_node(LinkedList *list, void *element) {
    Node *node = _create_node(list->data_size, element);
    Node *current_node = list->head;
    node->next_node = current_node;
    list->head = node;
    list->count ++;
}

void _add_element_last_node(LinkedList *list, void *element) {
    Node *node = _create_node(list->data_size, element);
    Node *current_node = list->head;
    while (current_node->next_node != NULL) {
        current_node = current_node->next_node;
    }
    current_node->next_node = node;
    list->count ++;
}

Node *_get_before_node(LinkedList *list, Node *node) {
    Node *current_node = list->head;
    while (current_node->next_node != NULL) {
        if (current_node->next_node == node) return current_node;
        current_node = current_node->next_node;
    }
    return NULL;
}

void _add_element_index_node(LinkedList *list, void *element, int index) {
    Node *node = _create_node(list->data_size, element);
    Node *current_node = list->head;
    int cont_index = 1;
    while (current_node != NULL) {
        if (cont_index == index) {
            Node *node_aux = current_node;
            Node *before_node = _get_before_node(list, current_node);
            current_node = node;
            before_node->next_node = current_node;
            current_node->next_node = node_aux;
            break;
        }
        cont_index ++;
        current_node = current_node->next_node;
    }
    list->count ++;
}

void linked_list_push(LinkedList *list, void *element) {
    if (linked_list_is_empty(list)) {
        _add_element_first_node(list, element);
    } else {
        _add_element_last_node(list, element);
    }
}

void linked_list_push_index(LinkedList *list, void *element, int index) {
    if (linked_list_is_empty(list)) {
        _add_element_first_node(list, element);
    } else if (index == 0) {
        _add_element_first_node(list, element);
    } else if (index > linked_list_length(list)) {
        _add_element_last_node(list, element);
    } else {
        _add_element_index_node(list, element, index);
    }
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
