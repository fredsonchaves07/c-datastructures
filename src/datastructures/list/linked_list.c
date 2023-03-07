#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../../../include/list/linked_list.h"

typedef struct _node {
    void *element;
    struct _node *next_node;
    size_t index;
} Node;

struct _linked_list {
    Node *head;
    Node *tail;
    size_t count;
    size_t data_size;
};

LinkedList *linked_list_create(size_t data_size) {
    LinkedList *linkedList = calloc(1, sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->data_size = data_size;
    return linkedList;
}

Node *_create_node(size_t size, void *element) {
    Node *node = calloc(1, sizeof(Node));
    node->next_node = NULL;
    node->element = malloc(size * sizeof(element));
    node->element = element;
    node ->index = 0;
    return node;
}

void _add_index_node(LinkedList *list) {
    Node *current_node = list->head;
    size_t index = 0;
    while (current_node != NULL) {
        if (current_node->index != index) {
            current_node->index = index;
        }
        index ++;
        current_node = current_node -> next_node;
    }
}

void _add_element_first_node(LinkedList *list, void *element, size_t index) {
    Node *node = _create_node(list->data_size, element);
    if (index != 0) node->index = index;
    if (list->head != NULL && list->head->index != 0) {
        node->next_node = list->head;
        list->count ++;
    } else if (list->head != NULL && list->head->index == 0) {
        node->next_node = list->head->next_node;
    }
    list->head = node;
    if (list->tail == NULL || list->tail->index == 0) {
        list->count ++;
        list->tail = node;
    }

}

void _add_element_last_node(LinkedList *list, void *element, size_t index) {
    Node *node = _create_node(list->data_size, element);
    Node *current_node = list->tail;
    current_node->next_node = node;
    if (index == 0) {
        node->index = current_node->index + 1;
    } else {
        node->index = index;
    }
    list->tail = node;
    list->count ++;
}

Node *_get_before_node(const LinkedList *list, Node *node) {
    Node *current_node = list->head;
    while (current_node->next_node != NULL) {
        if (current_node->next_node == node) return current_node;
        current_node = current_node->next_node;
    }
    return NULL;
}

void _add_element_index_node(LinkedList *list, void *element, int index) {
    Node *node = _create_node(list->data_size, element);
    Node *tail_node = list->tail;
    node->index = index;
    if (linked_list_is_empty(list)) {
        list->head = node;
        list->tail = node;
    } else if (index == tail_node->index) {
        Node *before_node = _get_before_node(list, tail_node);
        before_node->next_node = node;
        list->tail = node;
    } else {
        Node *current_node = list->head;
        while (current_node != NULL) {
            if (index == current_node->index) {
                Node *before_node = _get_before_node(list, current_node);
                before_node->next_node = node;
                node->next_node = current_node->next_node;
                break;
            } else if (index < current_node->index) {
                Node *before_node = _get_before_node(list, current_node);
                before_node->next_node = node;
                node->next_node = current_node;
                break;
            }
            current_node = current_node->next_node;
        }
    }
    list->count ++;
}

void linked_list_push_index(LinkedList *list, void *element, size_t index) {
    if (index == 0 || (list->head != NULL && index < list->head->index)) {
        _add_element_first_node(list, element, index);
    } else if (list->tail != NULL && index > list->tail->index) {
        _add_element_last_node(list, element, index);
    } else {
        _add_element_index_node(list, element, index);
    }
}

void linked_list_push(LinkedList *list, void *element) {
    if (linked_list_is_empty(list)) {
        _add_element_first_node(list, element, 0);
    } else {
        _add_element_last_node(list, element, 0);
    }
}

int linked_list_index_of(const LinkedList *list, void *element) {
    Node *current_node = list->head;
    int index = 0;
    while (current_node != NULL) {
        if (current_node->element == element) {
            return index;
        }
        current_node = current_node->next_node;
        index ++;
    }
    return -1;
}

void *linked_list_get_element(const LinkedList *list, void *element) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        if (current_node->element == element) return element;
        current_node = current_node->next_node;
    }
    return NULL;
}

void *_get_element_last_node(const LinkedList *list) {
    return list->tail->element;
}

void *_get_element_first_node(const LinkedList *list) {
    return list->head->element;
}

void *_get_element_index_node(const LinkedList *list, size_t index) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        if (index == current_node->index) {
            return current_node->element;
        }
        current_node = current_node->next_node;
    }
    return NULL;
}

void *linked_list_get_element_index(const LinkedList *list, size_t index) {
    if (list->head->index == index) {
        return _get_element_first_node(list);
    } else if (list->tail->index == index) {
        return _get_element_last_node(list);
    }
    return _get_element_index_node(list, index);
}

void _remove_element_first_node(LinkedList *list) {
    Node *head_node = list->head;
    list->head = list->head->next_node;
    head_node->element = NULL;
    head_node->next_node = NULL;
    head_node = NULL;
    if (linked_list_length(list) == 1) {
        list->tail = NULL;
    }
    free(head_node);
    list->count --;
}

void _remove_element_last_node(LinkedList *list) {
    Node *tail_node = list->tail;
    Node *before_node = _get_before_node(list, list->tail);
    before_node->next_node = NULL;
    list->tail = before_node;
    tail_node->element = NULL;
    tail_node = NULL;
    free(tail_node);
    list->count --;
}

void _remove_element_node_element(LinkedList *list, void *element) {
    Node *current_node = list->head->next_node;
    while (current_node != NULL) {
        if (current_node->element == element) {
            Node *before_node = _get_before_node(list, current_node);
            *before_node = *current_node->next_node;
            current_node->next_node = NULL;
            current_node->element = NULL;
            current_node = NULL;
            free(current_node);
            list->count --;
            break;
        }
        current_node = current_node->next_node;
    }
}


void linked_list_remove(LinkedList *list, void *element) {
    if (list->head->element == element) {
        _remove_element_first_node(list);
    } else if (list->tail->element == element) {
        _remove_element_last_node(list);
    } else {
        _remove_element_node_element(list, element);
    }
}

void _remove_element_index_node(LinkedList *list, int index) {
    Node *current_node = list->head->next_node;
    while (current_node != NULL) {
        if (index == current_node->index) {
            Node *before_node = _get_before_node(list, current_node);
            before_node->next_node = current_node->next_node;
            list->count --;
        }
        current_node = current_node->next_node;
    }
}

void linked_list_remove_index(LinkedList *list, size_t index) {
    if (index == list->head->index) {
        _remove_element_first_node(list);
    } else if (index == list->tail->index) {
        _remove_element_last_node(list);
    } else {
        _remove_element_index_node(list, index);
    }
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

void _free_node(Node *node) {
    free(node);
}

void linked_list_clear(LinkedList *list) {
    Node *current_node = list->head;
    while (current_node != NULL) {
        Node *next_node = current_node->next_node;
        current_node->element = NULL;
        _free_node(current_node);
        current_node = next_node;
    }
    list->head = NULL;
    list->data_size = 0;
    list->count = 0;
}

void linked_list_free(LinkedList *list) {
    linked_list_clear(list);
    free(list);
    list = NULL;
}
