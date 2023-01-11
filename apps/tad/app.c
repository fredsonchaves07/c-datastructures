# include <stdio.h>
# include "../../include/list/linked_list.h"

int main() {
    LinkedList *list = linked_list_create(sizeof(int));
    linked_list_push(list, (int *) 1);
    linked_list_push(list, (int *) 1);
    linked_list_push(list, (int *) 1);
    printf("%d", linked_list_length(list));
    return 0;
}