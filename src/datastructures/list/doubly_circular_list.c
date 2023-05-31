#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/list/doubly_circular_list.h"

typedef struct _doubly_circular_node {
    void *element;
    struct _doubly_circular_node *next_node;
    struct _doubly_circular_node *prev_node;
    size_t index;
} DoublyCircularNode;

struct _doubly_circular_list {
    DoublyCircularNode *head;
    DoublyCircularNode *tail;
    size_t count;
    size_t data_size;
};

DoublyCircularList *doubly_circular_list_create(size_t data_size) {
    DoublyCircularList *doublyCircularList = calloc(1, sizeof(DoublyCircularList));
    doublyCircularList->head = NULL;
    doublyCircularList->tail = NULL;
    doublyCircularList->data_size = data_size;
    return doublyCircularList;
}

DoublyCircularNode *_create_doubly_node_circular_list(size_t size, void *element) {
    DoublyCircularNode *node = calloc(1, sizeof(DoublyCircularNode));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    node ->index = 0;
    return node;
}

void _add_index_head_circular_doubly_node(DoublyCircularNode *node, size_t index) {
    if (index != 0)
        node->index = index;
}

bool _circular_doubly_node_head_index_is_0(const DoublyCircularList *list) {
    return list->head == NULL || list->head->index == 0;
}

bool _circular_doubly_node_tail_index_is_0(const DoublyCircularList *list) {
    return list->tail == NULL || list->tail->index == 0;
}

bool _circular_doubly_tail_is_null(const DoublyCircularList *list) {
    return list->tail == NULL;
}

void _add_element_first_doubly_node_circular_list(DoublyCircularList *list, void *element, size_t index) {
    DoublyCircularNode *node = _create_doubly_node_circular_list(list->data_size, element);
    _add_index_head_circular_doubly_node(node, index);
    if (!_circular_doubly_node_head_index_is_0(list)) {
        node->next_node = list->head;
        list->head->prev_node = node;
        list->count ++;
    } else if (!doubly_circular_list_is_empty(list) && _circular_doubly_node_head_index_is_0(list)) {
        node->next_node = list->head->next_node;
        list->head->next_node->prev_node = node;
    }
    if (_circular_doubly_tail_is_null(list) || _circular_doubly_node_tail_index_is_0(list)) {
        list->count ++;
        list->tail = node;
    }
    list->head = node;
    if (list->tail != NULL) {
        list->head->prev_node = list->tail;
        list->tail->next_node = list->head;
    }
}

void _add_element_last_doubly_node_circular_list(DoublyCircularList *list, void *element, size_t index) {
    DoublyCircularNode *node = _create_doubly_node_circular_list(list->data_size, element);
    DoublyCircularNode *current_node = list->tail;
    current_node->next_node = node;
    node->prev_node = current_node;
    if (index == 0)
        node->index = current_node->index + 1;
    else
        node->index = index;
    list->tail = node;
    list->count ++;
    if (list->head != NULL) {
        list->tail->next_node = list->head;
        list->head->prev_node = list->tail;
    }
}

void doubly_circular_list_push(DoublyCircularList *list, void *element) {
    if (doubly_circular_list_is_empty(list)) {
        _add_element_first_doubly_node_circular_list(list, element, 0);
    } else {
        _add_element_last_doubly_node_circular_list(list, element, 0);
    }
}

int doubly_circular_list_length(const DoublyCircularList *list) {
    return list->count;
}

bool doubly_circular_list_is_empty(const DoublyCircularList *list) {
    return list->head == NULL;
}

char *doubly_circular_list_to_string(const DoublyCircularList *list) {

    if (doubly_circular_list_is_empty(list))
        return "[]";
    char *doubly_circular_list_data = calloc(1, list->data_size * sizeof(char *));
    strcat(doubly_circular_list_data, "[");
    DoublyCircularNode *current_node = list->head;
    while (current_node) {
        strcat(doubly_circular_list_data, (char *) current_node->element);
        if (current_node->next_node != list->head)
            strcat(doubly_circular_list_data, ", ");
        current_node = current_node->next_node;
        if (current_node == list->head) break;
    }
    return strcat(doubly_circular_list_data, "]");
}