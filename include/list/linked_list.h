# ifndef LINKED_LIST
# define LINKED_LIST

#include <stdlib.h>
#include "list.h"

enum DataType {
    LINKED_LIST_INT,
    LINKED_LIST_CHAR,
    LINKED_LIST_UINT64,
    LINKED_LIST_BOOLEAN,
    LINKED_LIST_STRUCT
};

typedef struct _linked_list LinkedList;

LinkedList *linked_list_create(size_t size, enum DataType type);

# endif