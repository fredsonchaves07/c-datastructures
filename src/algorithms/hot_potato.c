#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../include/algorithms/hot_potato.h"
#include "../../include/queue/linked_queue.h"


char *hot_potato_execute(ArrayList *list, size_t quantity) {
    LinkedQueue *queue = linked_queue_create(sizeof (char *));
    ArrayList *eliminated_list = array_list_create(sizeof (char *));
    for (int i = 0; i < array_list_length(list); i ++)
        linked_queue_enqueue(queue, array_list_get_element_index(list, i));
    while (linked_queue_length(queue) > 1) {
        for (int i = 0; i < quantity; i ++)
            linked_queue_enqueue(queue, linked_queue_dequeue(queue));
        array_list_push(eliminated_list, linked_queue_dequeue(queue));
    }
    char *str = calloc(1, array_list_length(list) * sizeof(char *));
    strcat(str, "Eliminated: ");
    strcat(str, array_list_to_string(eliminated_list));
    strcat(str, "\n");
    strcat(str, "Winner: ");
    strcat(str, linked_queue_dequeue(queue));
    strcat(str, "\n");
    return str;
}