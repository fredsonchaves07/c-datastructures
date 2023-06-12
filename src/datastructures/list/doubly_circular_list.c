#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
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
    node->next_node = node;
    node->prev_node = node;
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

void _add_element_first_circular_doubly_node(DoublyCircularList *list, void *element, size_t index) {
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
    if (list->tail->next_node != list->head) {
        list->tail->next_node = list->head;
    }
    if (list->head->prev_node != list->tail) {
        list->head->prev_node = list->tail;
    }
}

void _add_element_last_circular_doubly_node(DoublyCircularList *list, void *element, size_t index) {
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
    if (list->tail->next_node != list->head) {
        list->tail->next_node = list->head;
    }
    if (list->head->prev_node != list->tail)  {
        list->head->prev_node = list->tail;
    }
}

void _add_element_index_circular_doubly_node(DoublyCircularList *list, void *element, int index) {
    DoublyCircularNode *node = _create_doubly_node_circular_list(list->data_size, element);
    DoublyCircularNode *tail_node = list->tail;
    node->index = index;
    if (doubly_circular_list_is_empty(list)) {
        list->head = node;
        list->tail = node;
    } else if (index == tail_node->index) {
        DoublyCircularNode *before_node = tail_node->prev_node;
        before_node->next_node = node;
        node->prev_node = before_node;
        list->tail = node;
    } else {
        DoublyCircularNode *current_node = list->head;
        while (current_node != NULL) {
            if (index == current_node->index) {
                DoublyCircularNode *before_node = current_node->prev_node;
                before_node->next_node = node;
                node->prev_node = before_node;
                node->next_node = current_node->next_node;
                current_node->next_node->prev_node = node;
                break;
            } else if (index < current_node->index) {
                DoublyCircularNode *before_node = current_node->prev_node;
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

void doubly_circular_list_push_index(DoublyCircularList *list, void *element, size_t index) {
    if (index == 0 || (list->head != NULL && index < list->head->index))
        _add_element_first_circular_doubly_node(list, element, index);
    else if (list->tail != NULL && index > list->tail->index)
        _add_element_last_circular_doubly_node(list, element, index);
    else
        _add_element_index_circular_doubly_node(list, element, index);
}

void *_get_element_last_circular_doubly_node(const DoublyCircularList *list) {
    return list->tail->element;
}

void *_get_element_first_circular_doubly_node(const DoublyCircularList *list) {
    return list->head->element;
}

void *_get_element_index_circular_doubly_node(const DoublyCircularList *list, size_t index) {
    DoublyCircularNode *current_node = list->head;
    while (current_node != NULL) {
        if (index == current_node->index)
            return current_node->element;
        current_node = current_node->next_node;
        if (current_node->next_node == list->head) {
            break;
        }
    }
    return NULL;
}

void *_get_element_circular_doubly_node(const DoublyCircularList *list, void *element) {
    DoublyCircularNode *current_node = list->head;
    while (current_node != NULL) {
        if (current_node->next_node == list->head) {
            break;
        }
        if (current_node->element == element)
            return current_node->element;
        current_node = current_node->next_node;
    }
    return NULL;
}

void *doubly_circular_list_get_element(const DoublyCircularList *list, void *element) {
    if (list->head->element == element)
        return _get_element_first_circular_doubly_node(list);
    else if (list->tail->element == element)
        return _get_element_last_circular_doubly_node(list);
    else
        return _get_element_circular_doubly_node(list, element);
}

void *doubly_circular_list_get_element_index(const DoublyCircularList *list, size_t index) {
    if (list->head->index == index) {
        return _get_element_first_circular_doubly_node(list);
    } else if (list->tail->index == index) {
        return _get_element_last_circular_doubly_node(list);
    }
    return _get_element_index_circular_doubly_node(list, index);
}

void _remove_element_first_circular_doubly_node(DoublyCircularList *list) {
    DoublyCircularNode *head_node = list->head;
    list->head = list->head->next_node;
    list->head->next_node->prev_node = list->head;
    head_node->element = NULL;
    head_node->next_node = NULL;
    head_node = NULL;
    if (doubly_circular_list_length(list) == 1) {
        list->tail = NULL;
    }
    if (list->tail != NULL) {
        if (list->tail->next_node != head_node) {
            list->tail->next_node = head_node;
        }
    }
    free(head_node);
    list->count --;
}

void _remove_element_last_circular_doubly_node(DoublyCircularList *list) {
    DoublyCircularNode *tail_node = list->tail;
    DoublyCircularNode *before_node = list->tail->prev_node;
    before_node->next_node = NULL;
    list->tail = before_node;
    tail_node->element = NULL;
    tail_node = NULL;
    if (list->head->prev_node != tail_node) {
        list->head->prev_node = tail_node;
    }
    free(tail_node);
    list->count --;
}

void _remove_element_circular_doubly_node_element(DoublyCircularList *list, void *element) {
    DoublyCircularNode *current_node = list->head->next_node;
    while (current_node != NULL) {
        if (current_node->element == element) {
            DoublyCircularNode *before_node = current_node->prev_node;
            *before_node = *current_node->next_node;
            current_node->next_node = NULL;
            current_node->element = NULL;
            current_node = NULL;
            free(current_node);
            list->count --;
            if (list->head->prev_node != list->tail) {
                list->head->prev_node = list->tail;
            }
            if (list->tail->next_node != list->head) {
                list->tail->next_node = list->head;
            }
            break;
        }
        current_node = current_node->next_node;
        if (current_node->next_node == list->head) {
            break;
        }
    }
}

void _remove_element_index_circular_doubly_node(DoublyCircularList *list, int index) {
    DoublyCircularNode *current_node = list->head->next_node;
    while (current_node != NULL) {
        if (index == current_node->index) {
            DoublyCircularNode *before_node = current_node->prev_node;
            before_node->next_node = current_node->next_node;
            current_node->next_node->prev_node = before_node;
            list->count --;
            if (list->head->prev_node != list->tail) {
                list->head->prev_node = list->tail;
            }
            if (list->tail->next_node != list->head) {
                list->tail->next_node = list->head;
            }
        }
        current_node = current_node->next_node;
        if (current_node->next_node == list->head) {
            break;
        }
    }
}

void doubly_circular_list_remove(DoublyCircularList *list, void *element) {
    if (list->head->element == element) {
        _remove_element_first_circular_doubly_node(list);
    } else if (list->tail->element == element) {
        _remove_element_last_circular_doubly_node(list);
    } else {
        _remove_element_circular_doubly_node_element(list, element);
    }
}

void doubly_circular_list_remove_index(DoublyCircularList *list, size_t index) {
    if (index == list->head->index) {
        _remove_element_first_circular_doubly_node(list);
    } else if (index == list->tail->index) {
        _remove_element_last_circular_doubly_node(list);
    } else {
        _remove_element_index_circular_doubly_node(list, index);
    }
}

int circular_doubly_list_index_of(const DoublyCircularList *list, void *element) {
    if (list->head->element == element) {
        return list->head->index;
    } else if (list->tail->element == element) {
        return list->tail->index;
    } else {
        DoublyCircularNode *current_node = list->head;
        while (current_node != NULL) {
            if (current_node->element == element) {
                return current_node->index;
            }
            current_node = current_node->next_node;
            if (current_node->next_node == list->head) {
                break;
            }
        }
    }
    return -1;
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

void _free_circular_doubly_node(DoublyCircularNode **node_ref) {
    DoublyCircularNode *node = *node_ref;
    free(node);
    *node_ref = NULL;
}

void circular_doubly_list_clear(DoublyCircularList *list) {
    DoublyCircularNode *current_node = list->head;
    while (current_node->next_node != list->head) {
        DoublyCircularNode *next_node = current_node->next_node;
        current_node->element = NULL;
        _free_circular_doubly_node(&current_node);
        current_node = next_node;
    }
    list->head = NULL;
    list->tail = NULL;
    list->data_size = 0;
    list->count = 0;
}

void doubly_circular_list_free(DoublyCircularList **list) {
    DoublyCircularList *list_ref = *list;
    circular_doubly_list_clear(*list);
    free(list_ref);
    list = NULL;
}