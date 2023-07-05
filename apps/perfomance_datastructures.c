# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include "ctype.h"
# include <time.h>
# include "../include/list/linked_list.h"
# include "../include/list/doubly_linked_list.h"
# include "../include/list/array_list.h"
# include "../include/list/doubly_circular_list.h"
# include "../include/stack/array_stack.h"

int help() {
    printf("\nWelcome to Perfomance datastructure app\n");
    printf("\n");
    printf("     Display information about builtin commands.\n\n");
    printf("     OPTIONS:\n");
    printf("        ./perfomance_datastructure.x <datastructure> <operation> <data size elements> <arguments>: To generate .csv file containing information about certain data structure operation\n\n");
    printf("     EXAMPLE: \n");
    printf("        ./perfomance_datastructure.x linked_list insert 5000: The program will use the linked list data structure with an insert operation of 5000 elements\n\n");
    printf("     DATASTRUCTURE: \n");
    printf("        linked_list: To use the linked list data structure\n");
    printf("        doubly_linked_list: To use the doubly linked list data structure\n");
    printf("        array_list: To use array list data structure\n");
    printf("        circular_list: To use circular list data structure\n");
    printf("        array_stack: To use array stack data structure\n\n");
    printf("     OPERATION: \n");
    printf("        insert: To use element insertion operation \n");
    printf("                ./perfomance_datastructure <datastructure> insert <data size elements> \n\n");
    printf("           get: To use get insertion operation \n");
    printf("                ./perfomance_datastructure <datastructure> get <data size elements> <get_element>\n\n");
    printf("        remove: To use element remove operation \n");
    printf("                ./perfomance_datastructure <datastructure> remove <data size elements> <remove_element> \n\n");
    printf("     DATA SIZE ELEMENTS: \n");
    printf("        <INT>: A number must be informed to inform the number of elements that will be added to the list \n\n");
    printf("     ARGUMENTS: \n");
    printf("        -1: To get or remove the first element of the data structure \n");
    printf("         0: To get or remove the middle element of the data structure \n");
    printf("         1: To get or remove the last element of the data structure \n\n\n");
    printf("The result will be stored in the /tmp directory\n");
    return 0;
}

void invalid_command() {
    printf("\nInvalid command! \n\n");
    printf("Use ./perfomance_datastructure.x -help for more information\n");
    exit(-1);
}

FILE *create_file(char *name) {
    FILE *file;
    char filename[100] = "tmp/";
    strcat(filename, name);
    file = fopen(filename, "w");
    fputs("datastructure;operation;element;time\n", file);
    return file;
}

void puts_data(FILE  *file, char *datastructure, char *operation, char *element, char *time) {
    fputs(datastructure, file);
    fputs(";", file);
    fputs(operation, file);
    fputs(";", file);
    fputs(element, file);
    fputs(";", file);
    fputs(time, file);
    fputs("\n", file);
}

bool is_help(char **argv) {
    return strcmp(argv[1], "-help") == 0;
}

bool is_linked_list(char **argv) {
    return strcmp(argv[1], "linked_list") == 0;
}

bool is_doubly_linked_list(char **argv) {
    return strcmp(argv[1], "doubly_linked_list") == 0;
}

bool is_array_list(char **argv) {
    return strcmp(argv[1], "array_list") == 0;
}

bool is_circular_list(char **argv) {
    return strcmp(argv[1], "circular_list") == 0;
}

bool is_array_stack(char **argv) {
    return strcmp(argv[1], "array_stack") == 0;
}

LinkedList *create_linked_list() {
    return linked_list_create(sizeof(int *));
}

DoublyLinkedList *create_doubly_linked_list() {
    return doubly_linked_list_create(sizeof(int *));
}

ArrayList *create_array_list() {
    return array_list_create(sizeof(int *));
}

DoublyCircularList *create_circular_list() {
    return doubly_circular_list_create(sizeof(int *));
}

ArrayStack *create_array_stack() {
    return array_stack_create(sizeof(int *));
}

void insert_linked_list(LinkedList *list, int elements) {
    for (int i = 0; i < elements; i ++) {
        int *index = (int *) i;
        linked_list_push(list, (int *) index);
    }
}

void clear_linked_list(LinkedList *list) {
    linked_list_clear(list);
}

void clear_array_list(ArrayList *list) {
    array_list_clear(list);
}

void clear_circular_list(DoublyCircularList *list) {
    circular_doubly_list_clear(list);
}

void clear_doubly_linked_list(DoublyLinkedList *list) {
    doubly_linked_list_clear(list);
}

void clear_array_stack(ArrayStack *stack) {
    array_stack_clear(stack);
}

void insert_linked_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    LinkedList *list = create_linked_list();
    FILE *file = create_file("linked_list_perfomance_insert.csv");
    for (int i = 0; i < elements; i ++) {
        double time_spent = 0.0;
        int *index = (int *) i;
        clock_t begin = clock();
        linked_list_push(list, (int *) index);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        char index_char[sizeof(elements) + 10000];
        char time_char[sizeof(elements) + 10000];
        sprintf(index_char, "%d", i);
        sprintf(time_char, "%f", time_spent);
        puts_data(file, "linked_list", "insert", index_char, time_char);
    }
    printf("File linked_list_perfomance_insert.csv generate in /tmp\n");
    fclose(file);
    clear_linked_list(list);
}

void insert_doubly_linked_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    DoublyLinkedList *list = create_doubly_linked_list();
    FILE *file = create_file("doubly_linked_list_perfomance_insert.csv");
    for (int i = 0; i < elements; i ++) {
        double time_spent = 0.0;
        int *index = (int *) i;
        clock_t begin = clock();
        doubly_linked_list_push(list, (int *) index);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        char index_char[sizeof(elements) + 10000];
        char time_char[sizeof(elements) + 10000];
        sprintf(index_char, "%d", i);
        sprintf(time_char, "%f", time_spent);
        puts_data(file, "doubly_linked_list", "insert", index_char, time_char);
    }
    printf("File doubly_linked_list_perfomance_insert.csv generate in /tmp\n");
    fclose(file);
    clear_linked_list(list);
}

void insert_array_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    ArrayList *list = create_array_list();
    FILE *file = create_file("array_list_perfomance_insert.csv");
    for (int i = 0; i < elements; i ++) {
        double time_spent = 0.0;
        int *index = (int *) i;
        clock_t begin = clock();
        array_list_push(list, (int *) index);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        char index_char[sizeof(elements) + 10000];
        char time_char[sizeof(elements) + 10000];
        sprintf(index_char, "%d", i);
        sprintf(time_char, "%f", time_spent);
        fflush(file);
        puts_data(file, "list", "insert", index_char, time_char);
    }
    printf("File array_list_perfomance_insert.csv generate in /tmp\n");
    clear_array_list(list);
}

void insert_circular_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    DoublyCircularList *list = create_circular_list();
    FILE *file = create_file("circular_list_perfomance_insert.csv");
    for (int i = 0; i < elements; i ++) {
        double time_spent = 0.0;
        int *index = (int *) i;
        clock_t begin = clock();
        doubly_circular_list_push(list, (int *) index);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        char index_char[sizeof(elements) + 10000];
        char time_char[sizeof(elements) + 10000];
        sprintf(index_char, "%d", i);
        sprintf(time_char, "%f", time_spent);
        fflush(file);
        puts_data(file, "list", "insert", index_char, time_char);
    }
    printf("File circular_list_perfomance_insert.csv generate in /tmp\n");
    clear_circular_list(list);
}

void insert_array_stack_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    ArrayStack *stack = create_array_stack();
    FILE *file = create_file("array_stack_insert.csv");
    for (int i = 0; i < elements; i ++) {
        double time_spent = 0.0;
        int *index = (int *) i;
        clock_t begin = clock();
        array_stack_push(stack, (int *) index);
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
        char index_char[sizeof(elements) + 10000];
        char time_char[sizeof(elements) + 10000];
        sprintf(index_char, "%d", i);
        sprintf(time_char, "%f", time_spent);
        fflush(file);
        puts_data(file, "list", "insert", index_char, time_char);
    }
    printf("File array_list_perfomance_insert.csv generate in /tmp\n");
    clear_array_stack(stack);
}

void push_element_linked_list(int elements, LinkedList *list) {
    for (int i = 0; i <elements; i++) {
        int *index = (int *) i;
        linked_list_push(list, (int *) index);
    }
}

void push_element_doubly_linked_list(int elements, DoublyLinkedList *list) {
    for (int i = 0; i <elements; i++) {
        int *index = (int *) i;
        doubly_linked_list_push(list, (int *) index);
    }
}

void push_element_array_linked_list(int elements, ArrayList *list) {
    for (int i = 0; i <elements; i++) {
        int *index = (int *) i;
        array_list_push(list, (int *) index);
    }
}

void push_element_circular_list(int elements, DoublyCircularList *list) {
    for (int i = 0; i <elements; i++) {
        int *index = (int *) i;
        doubly_circular_list_push(list, (int *) index);
    }
}

void push_element_array_stack(int elements, ArrayStack *stack) {
    for (int i = 0; i <=elements; i++) {
        int *index = (int *) i;
        array_list_push(stack, (int *) index);
    }
}


void get_linked_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    LinkedList *list = create_linked_list();
    push_element_linked_list(elements, list);
    FILE *file = create_file("linked_list_perfomance_get.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    linked_list_get_element(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "linked_list", "get", index_char, time_char);
    printf("File linked_list_perfomance_get.csv generate in /tmp\n");
    fclose(file);
    clear_linked_list(list);
}

void get_doubly_linked_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    DoublyLinkedList *list = create_doubly_linked_list();
    push_element_doubly_linked_list(elements, list);
    FILE *file = create_file("doubly_linked_list_perfomance_get.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    doubly_linked_list_get_element(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "doubly_linked_list", "get", index_char, time_char);
    printf("File doubly_linked_list_perfomance_get.csv generate in /tmp\n");
    fclose(file);
    clear_doubly_linked_list(list);
}

void get_array_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    ArrayList *list = create_array_list();
    push_element_array_linked_list(elements, list);
    FILE *file = create_file("array_list_perfomance_get.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    array_list_get_element(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "array_list", "get", index_char, time_char);
    printf("File array_list_perfomance_get.csv generate in /tmp\n");
    clear_array_list(list);
}

void get_circular_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    DoublyCircularList *list = create_circular_list();
    push_element_circular_list(elements, list);
    FILE *file = create_file("circular_list_perfomance_get.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    doubly_circular_list_get_element(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "array_list", "get", index_char, time_char);
    printf("File circular_list_perfomance_get.csv generate in /tmp\n");
    clear_circular_list(list);
}

void remove_linked_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    LinkedList *list = create_linked_list();
    push_element_linked_list(elements, list);
    FILE *file = create_file("linked_list_perfomance_remove.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    linked_list_remove(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "linked_list", "remove", index_char, time_char);
    printf("File linked_list_perfomance_remove.csv generate in /tmp\n");
    fclose(file);
    clear_linked_list(list);
}

void remove_doubly_linked_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    DoublyLinkedList *list = create_doubly_linked_list();
    push_element_doubly_linked_list(elements, list);
    FILE *file = create_file("doubly_linked_list_perfomance_remove.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    doubly_linked_list_remove(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "doubly_linked_list", "remove", index_char, time_char);
    printf("File doubly_linked_list_perfomance_remove.csv generate in /tmp\n");
    fclose(file);
    clear_doubly_linked_list(list);
}

void remove_array_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    ArrayList *list = create_array_list();
    push_element_array_linked_list(elements, list);
    FILE *file = create_file("array_list_perfomance_remove.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    array_list_remove(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "array_list", "remove", index_char, time_char);
    printf("File array_list_perfomance_remove.csv generate in /tmp\n");
    fclose(file);
    clear_array_list(list);
}

void remove_circular_list_perfomance(char **argv) {
    if (argv[3] == NULL || argv[4] == NULL || argv[5] != NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    int element = atoi(argv[4]);
    if (!isdigit(*argv[4]) || element < 0 || element > elements) invalid_command();
    DoublyCircularList *list = create_circular_list();
    push_element_circular_list(elements, list);
    FILE *file = create_file("circular_list_perfomance_remove.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    doubly_circular_list_remove(list, (int *) element);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "array_list", "remove", index_char, time_char);
    printf("File circular_list_perfomance_remove.csv generate in /tmp\n");
    fclose(file);
    clear_circular_list(list);
}

void remove_array_stack_perfomance(char **argv) {
    if (argv[3] == NULL) invalid_command();
    int elements = atoi(argv[3]);
    if (!isdigit(*argv[3]) || elements <= 0) invalid_command();
    ArrayStack *stack = create_array_stack();
    push_element_array_stack(elements, stack);
    FILE *file = create_file("array_stack_perfomance_remove.csv");
    double time_spent = 0.0;
    clock_t begin = clock();
    void *element = array_stack_pop(stack);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    char index_char[sizeof(elements) + 10000];
    char time_char[sizeof(elements) + 10000];
    sprintf(index_char, "%d", element);
    sprintf(time_char, "%f", time_spent);
    puts_data(file, "array_stack", "remove", index_char, time_char);
    printf("File array-stack_perfomance_remove.csv generate in /tmp\n");
    fclose(file);
    clear_array_stack(stack);
}

int linked_list(char **argv) {
    if (argv[2] == NULL || argv[3] == NULL) invalid_command();
    if (!isdigit(*argv[3]) || atoi(argv[3]) <= 0) invalid_command();
    if (strcmp(argv[2], "insert") == 0) insert_linked_list_perfomance(argv);
    if (strcmp(argv[2], "get") == 0) get_linked_list_perfomance(argv);
    if (strcmp(argv[2], "remove") == 0) remove_linked_list_perfomance(argv);
    return 0;
}

int doubly_linked_list(char **argv) {
    if (argv[2] == NULL || argv[3] == NULL) invalid_command();
    if (!isdigit(*argv[3]) || atoi(argv[3]) <= 0) invalid_command();
    if (strcmp(argv[2], "insert") == 0) insert_doubly_linked_list_perfomance(argv);
    if (strcmp(argv[2], "get") == 0) get_doubly_linked_list_perfomance(argv);
    if (strcmp(argv[2], "remove") == 0) remove_doubly_linked_list_perfomance(argv);
    return 0;
}

int array_list(char **argv) {
    if (argv[2] == NULL || argv[3] == NULL) invalid_command();
    if (!isdigit(*argv[3]) || atoi(argv[3]) <= 0) invalid_command();
    if (strcmp(argv[2], "insert") == 0) insert_array_list_perfomance(argv);
    if (strcmp(argv[2], "get") == 0) get_array_list_perfomance(argv);
    if (strcmp(argv[2], "remove") == 0) remove_array_list_perfomance(argv);
    return 0;
}

int circular_list(char **argv) {
    if (argv[2] == NULL || argv[3] == NULL) invalid_command();
    if (!isdigit(*argv[3]) || atoi(argv[3]) <= 0) invalid_command();
    if (strcmp(argv[2], "insert") == 0) insert_circular_list_perfomance(argv);
    if (strcmp(argv[2], "get") == 0) get_circular_list_perfomance(argv);
    if (strcmp(argv[2], "remove") == 0) remove_circular_list_perfomance(argv);
    return 0;
}

int array_stack(char **argv) {
    if (argv[2] == NULL || argv[3] == NULL) invalid_command();
    if (!isdigit(*argv[3]) || atoi(argv[3]) <= 0) invalid_command();
    if (strcmp(argv[2], "insert") == 0) insert_array_stack_perfomance(argv);
    if (strcmp(argv[2], "remove") == 0) remove_array_stack_perfomance(argv);
    return 0;
}

int main(int argc, char **argv) {
    if (argc <= 1 || argc > 6) invalid_command();
    if (is_help(argv)) return help();
    if (is_linked_list(argv)) return linked_list(argv);
    if (is_doubly_linked_list(argv)) return doubly_linked_list(argv);
    if (is_array_list(argv))return array_list(argv);
    if (is_circular_list(argv))return circular_list(argv);
    if (is_array_stack(argv))return array_stack(argv);
    invalid_command();
}