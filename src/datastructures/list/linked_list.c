#include "../../../include/list/linked_list.h"

typedef struct _node {
    int data;
    struct _node *next_node;
} Node;

typedef struct _linked_list {
    Node *head;
} LinkedList;
