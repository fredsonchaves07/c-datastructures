#include <stdlib.h>
#include <stdbool.h>
#include "../../../include/list/linked_list.h"

typedef struct _node {
    void* data;
    struct _node *next_node;
} Node;

struct _linked_list {
    enum DataType type;
    Node *head;
    size_t size;
};

size_t _get_size_t(size_t size, enum DataType type) {
    if (type == LINKED_LIST_INT) {
        return size * sizeof(int);
    } else if (type == LINKED_LIST_CHAR) {
        return size * sizeof(char);
    } else if (type == LINKED_LIST_UINT64) {
        return size * sizeof(unsigned long long );
    } else if (type == LINKED_LIST_BOOLEAN) {
        return size * sizeof(bool);
    } else if (type == LINKED_LIST_STRUCT) {
        return size * 100;
    }
    return 0;
}

LinkedList *linked_list_create(size_t size, enum DataType type) {
    size_t effective_size = _get_size_t(size, type);
    Node node = {
            .data = malloc(effective_size),
            .next_node = NULL
    };
    LinkedList *linkedList = calloc(1, sizeof(LinkedList));
    linkedList->type = type;
    linkedList->size = size;
    linkedList->head = &node;
    return linkedList;
}
