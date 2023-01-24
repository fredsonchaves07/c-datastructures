# include "stdio.h"
# include "time.h"
# include "../include/list/linked_list.h"

int main() {
    double time_spent = 0.0;
    LinkedList *list = linked_list_create(sizeof(int *));
    clock_t begin = clock();
    for (int i = 0; i < 20000000; i ++) {
        int *index = (int *) i;
        linked_list_push(list, (int *) index);
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds\n", time_spent);
    return 0;
}