#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/list/doubly_linked_list.h"

typedef struct _doubly_node {
    void *element;
    struct _doubly_node *next_node;
    struct _doubly_node *prev_node;
    size_t index;
} DoublyNode;

struct _doubly_linked_list {
    DoublyNode *head;
    DoublyNode *tail;
    size_t count;
    size_t data_size;
};

DoublyLinkedList *doubly_linked_list_create(size_t data_size) {
    DoublyLinkedList *doublyLinkedList = calloc(1, sizeof(DoublyLinkedList));
    doublyLinkedList->head = NULL;
    doublyLinkedList->tail = NULL;
    doublyLinkedList->data_size = data_size;
    return doublyLinkedList;
}

DoublyNode *_create_doubly_node(size_t size, void *element) {
    DoublyNode *node = calloc(1, sizeof(DoublyNode));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    node ->index = 0;
    return node;
}

void _add_index_head_doubly_node(DoublyNode *node, size_t index) {
    if (index != 0)
        node->index = index;
}

bool _doubly_node_head_index_is_0(const DoublyLinkedList *list) {
    return list->head == NULL || list->head->index == 0;
}

bool _doubly_node_tail_index_is_0(const DoublyLinkedList *list) {
    return list->tail == NULL || list->tail->index == 0;
}

bool _doubly_tail_is_null(const DoublyLinkedList *list) {
    return list->tail == NULL;
}

void _add_element_first_doubly_node(DoublyLinkedList *list, void *element, size_t index) {
    DoublyNode *node = _create_doubly_node(list->data_size, element);
    _add_index_head_doubly_node(node, index);
    if (!_doubly_node_head_index_is_0(list)) {
        node->next_node = list->head;
        list->head->prev_node = node;
        list->count ++;
    } else if (!doubly_linked_list_is_empty(list) && _doubly_node_head_index_is_0(list)) {
        node->next_node = list->head->next_node;
        list->head->next_node->prev_node = node;
    }
    if (_doubly_tail_is_null(list) || _doubly_node_tail_index_is_0(list)) {
        list->count ++;
        list->tail = node;
    }
    list->head = node;
}

void _add_element_last_doubly_node(DoublyLinkedList *list, void *element, size_t index) {
    DoublyNode *node = _create_doubly_node(list->data_size, element);
    DoublyNode *current_node = list->tail;
    current_node->next_node = node;
    node->prev_node = current_node;
    if (index == 0)
        node->index = current_node->index + 1;
    else
        node->index = index;
    list->tail = node;
    list->count ++;
}

void _add_element_index_doubly_node(DoublyLinkedList *list, void *element, int index) {
    DoublyNode *node = _create_doubly_node(list->data_size, element);
    DoublyNode *tail_node = list->tail;
    node->index = index;
    if (doubly_linked_list_is_empty(list)) {
        list->head = node;
        list->tail = node;
    } else if (index == tail_node->index) {
        DoublyNode *before_node = tail_node->prev_node;
        before_node->next_node = node;
        node->prev_node = before_node;
        list->tail = node;
    } else {
        DoublyNode *current_node = list->head;
        while (current_node != NULL) {
            if (index == current_node->index) {
                DoublyNode *before_node = current_node->prev_node;
                before_node->next_node = node;
                node->prev_node = before_node;
                node->next_node = current_node->next_node;
                current_node->next_node->prev_node = node;
                break;
            } else if (index < current_node->index) {
                DoublyNode *before_node = current_node->prev_node;
                before_node->next_node = node;
                node->prev_node = before_node;
                node->next_node = current_node;
                current_node->prev_node = node;
                break;
            }
            current_node = current_node->next_node;
        }
    }
    list->count ++;
}

void doubly_linked_list_push(DoublyLinkedList *list, void *element) {
    if (doubly_linked_list_is_empty(list)) {
        _add_element_first_doubly_node(list, element, 0);
    } else {
        _add_element_last_doubly_node(list, element, 0);
    }
}

void doubly_linked_list_push_index(DoublyLinkedList *list, void *element, size_t index) {
    if (index == 0 || (list->head != NULL && index < list->head->index))
        _add_element_first_doubly_node(list, element, index);
    else if (list->tail != NULL && index > list->tail->index)
        _add_element_last_doubly_node(list, element, index);
    else
        _add_element_index_doubly_node(list, element, index);
}

void *_get_element_last_doubly_node(const DoublyLinkedList *list) {
    return list->tail->element;
}

void *_get_element_first_doubly_node(const DoublyLinkedList *list) {
    return list->head->element;
}

void *_get_element_index_doubly_node(const DoublyLinkedList *list, size_t index) {
    DoublyNode *current_node = list->head;
    while (current_node != NULL) {
        if (index == current_node->index)
            return current_node->element;
        current_node = current_node->next_node;
    }
    return NULL;
}

void *_get_element_doubly_node(const DoublyLinkedList *list, void *element) {
    DoublyNode *current_node = list->head;
    while (current_node != NULL) {
        if (current_node->element == element)
            return current_node->element;
        current_node = current_node->next_node;
    }
    return NULL;
}

void *doubly_linked_list_get_element(const DoublyLinkedList *list, void *element) {
    if (list->head->element == element)
        return _get_element_first_doubly_node(list);
    else if (list->tail->element == element)
        return _get_element_last_doubly_node(list);
    else
        return _get_element_doubly_node(list, element);
}

bool doubly_linked_list_is_empty(const DoublyLinkedList *list) {
    return list->head == NULL;
}

int doubly_linked_list_length(const DoublyLinkedList *list) {
    return list->count;
}

char *doubly_linked_list_to_string(const DoublyLinkedList *list) {
    if (doubly_linked_list_is_empty(list))
        return "[]";
    char *doubly_linked_list_data = calloc(1, list->data_size * sizeof(char *));
    strcat(doubly_linked_list_data, "[");
    DoublyNode *current_node = list->head;
    while (current_node != NULL) {
        strcat(doubly_linked_list_data, (char *) current_node->element);
        if (current_node->next_node != NULL)
            strcat(doubly_linked_list_data, ", ");

        current_node = current_node->next_node;
    }
    return strcat(doubly_linked_list_data, "]");
}

void _free_doubly_node(DoublyNode *node) {
    free(node);
}

void doubly_linked_list_clear(DoublyLinkedList *list) {
    DoublyNode *current_node = list->head;
    while (current_node != NULL) {
        DoublyNode *next_node = current_node->next_node;
        current_node->element = NULL;
        _free_doubly_node(current_node);
        current_node = next_node;
    }
    list->head = NULL;
    list->data_size = 0;
    list->count = 0;
}

void doubly_linked_list_free(DoublyLinkedList *list) {
    doubly_linked_list_clear(list);
    free(list);
    list = NULL;
}