#include "stdio.h"
#include "stdlib.h" // Contém o NULL, calloc, malloc e free

int main() {

    int v_stack[5] = {0, 10, 20, 30, 40};
    puts("### VETOR ESTÁTICO ###");
    printf("&v_stack = %p\n", &v_stack);
    printf("v_stack = %d\n\n", *v_stack);
    for (int i = 0; i < 5; i ++) {
        printf("&v_stack[%d] = %p\n", i, &v_stack[i]);
        printf("v_stack[%d] = %d", i, v_stack[i]);
        puts("\n");
    }
    puts("### VETOR DINAMICO COM MALLOC###");
    int *vh_malloc = malloc(5 * sizeof(int)); //Todos os elementos possuem "lixo de memória"
    printf("&vh_malloc = %p\n", &vh_malloc);
    printf("vh_malloc = %d\n\n", *vh_malloc);
    for (int i = 0; i < 5; i ++) {
        printf("&vh_malloc[%d] = %p\n", i, &vh_malloc[i]);
        printf("vh_malloc[%d] = %d", i, vh_malloc[i]);
        puts("\n");
    }
    puts("### VETOR DINAMICO COM CALLOC###");
    char *vh_calloc = calloc(5, sizeof(char)); //Garante que todos os elementos terão valor inicial do tipo"
    printf("&vh_calloc = %p\n", &vh_calloc);
    printf("vh_calloc = %c\n\n", *vh_calloc);
    for (int i = 0; i < 5; i ++) {
        printf("&vh_calloc[%d] = %p\n", i, &vh_calloc[i]);
        printf("vh_calloc[%d] = %c", i, vh_calloc[i]);
        puts("\n");
    }
    return 0;
}