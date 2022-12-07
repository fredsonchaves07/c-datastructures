#include "stdio.h"
#include "stdlib.h" // Contém o NULL, calloc, malloc e free

void sum_scallar(int v[], int n, int scallar) {
    for (int i = 0; i < n; i ++) {
        v[i] += scallar;
    }
}

void print_vector(const int *v, int n) {
    for (int i = 0; i < n; i ++) {
        printf("&v[%d] = %p\n", i, &v[i]);
        printf("v[%d] = %d", i, v[i]);
        puts("\n");
    }
}

int main() {
//    puts("### VETOR ESTÁTICO ###");
//    int v_stack[5] = {0, 10, 20, 30, 40};
//    print_vector(v_stack, 5);
//    sum_scallar(v_stack, 5, 9);
//    print_vector(v_stack, 5);

    puts("### VETOR DINAMICO COM CALLOC###");
    int *vh_calloc = calloc(5, sizeof(int)); //Garante que todos os elementos terão valor inicial do tipo"
    for (int i = 0; i < 5; i ++) {
        vh_calloc[i] = i * 100;
    }
    print_vector(vh_calloc, 5);
    sum_scallar(vh_calloc, 5, 9);
    print_vector(vh_calloc, 5);

    free(vh_calloc);
    vh_calloc = NULL;
    return 0;
}