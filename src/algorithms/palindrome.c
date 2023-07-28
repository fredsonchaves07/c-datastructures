#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iconv.h>

#include "../../include/algorithms/palindrome.h"
#include "../../include/stack/linked_stack.h"


char *_remove_space_blank(char *string) {
    char *result = calloc(1, strlen(string) * sizeof(char *));
    for (int i = 0, j = 0; i < strlen(string); i++, j++) {
        if (string[i] == ' ') {
            result[j] = string[i + 1];
            i++;
        } else {
            result[j] = string[i];
        }
    }
    return result;
}

char *_to_lower_case(char *string) {
    int i = 0;
    char *result = calloc(1, strlen(string) * sizeof(char *));
    while (string[i]) {
        result[i] = tolower(string[i]);
        i++;
    }
    return result;
}

char verify_accent(char ch) {
    switch (ch) {
        case 'á': case 'à': case 'â': case 'ã': return 'a';
        case 'é': case 'è': case 'ê': return 'e';
        case 'í': case 'ì': return 'i';
        case 'ó': case 'ò': case 'ô': case 'õ': return 'o';
        case 'ú': case 'ù': case 'û': return 'u';
        case 'ç': return 'c';
        default: return ch;
    }
}

char *_remove_accent(char *string) {
    char *result = calloc(1, strlen(string) * sizeof(char *));
    char with_acent[] = "äáâàãéêëèíîïìöóôòõüúûùç";
    char without_acent[] = "aaaaaeeeeiiiiooooouuuuc";
    for (int i = 0; i < strlen(string); i ++) {
        for (int j = 0; j < 24; j++) {
            if (string[i] == with_acent[j]) {
                result[i] = without_acent[j];
                i++;
                continue;
            }
        }
        result[i] = string[i];
    }
    return result;
}

bool *is_palindrome(char *string) {
    if (strcmp(string, "") == 0) return false;
    LinkedStack *stack = linked_stack_create(sizeof (char *));
    char *string_formated = _remove_accent(_to_lower_case(_remove_space_blank(string))) ;
    char *string_reverse = calloc(1, strlen(string_formated) * sizeof(char *));
    for (int i = 0; i < strlen(string_formated); i++) {
        linked_stack_push(stack, string_formated[i]);
    }
    for (int i = 0; i < strlen(string_formated); i++) {
        if (linked_stack_is_empty(stack)) break;
        string_reverse[i] = (char) linked_stack_pop(stack);
    }
    if(strcmp(string_formated, string_reverse) == 0) {
        return true;
    }
    linked_stack_clear(stack);
    return false;
}