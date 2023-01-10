# ifndef LINKED_LIST
# define LINKED_LIST

#include <stdlib.h>
//#include "list.h"

typedef struct _linked_list LinkedList;

LinkedList *linked_list_create(size_t data_size);

//void linked_list_push(LinkedList *list, void *element);

# endif