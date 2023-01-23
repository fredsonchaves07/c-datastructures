# include "../include/list/linked_list.h"
# include "stdio.h"

int main() {
    LinkedList *list = linked_list_create(sizeof(int *));

    for (int i = 0; i < 1000; i ++) {
        int *index = (int *) i;
        linked_list_push(list, (int *) index);
    }
}