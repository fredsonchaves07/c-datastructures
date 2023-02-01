# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include "ctype.h"
# include <time.h>
# include "../include/list/linked_list.h"

int help() {
    printf("\nWelcome to Perfomance datastructure app\n");
    printf("\n");
    printf("     Display information about builtin commands.\n\n");
    printf("     OPTIONS:\n");
    printf("        ./perfomance_datastructure.x <datastructure> <operation> <data size elements> <arguments>: To generate .csv file containing information about certain data structure operation\n\n");
    printf("     EXAMPLE: \n");
    printf("        ./perfomance_datastructure.x linked_list insert 5000: The program will use the linked list data structure with an insert operation of 5000 elements\n\n");
    printf("     DATASTRUCTURE: \n");
    printf("        linked_list: To use the linked list data structure\n\n");
    printf("     OPERATION: \n");
    printf("        insert: To use element insertion operation \n\n");
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

bool is_help(char **argv) {
    return strcmp(argv[1], "-help") == 0;
}

bool is_linked_list(char **argv) {
    return strcmp(argv[1], "linked_list") == 0;
}

void insert_linked_list(char **argv) {
    if (argv[3] == NULL || argv[4] != NULL) invalid_command();
    if (!isdigit(*argv[3]) || ((int ) (*argv[3] - 48) <= 0)) invalid_command();
}

int linked_list(char **argv) {
    if (argv[2] == NULL) invalid_command();
    if (strcmp(argv[2], "insert") == 0) insert_linked_list(argv);
    return 0;
}

int main(int argc, char **argv) {
    if (argc <= 1 || argc > 6) invalid_command();
    if (is_help(argv)) return help();
    if (is_linked_list(argv)) return linked_list(argv);
    invalid_command();
}