#include "stdio.h"

int main() {
    int a = 10;
    int *p1 = &a;
    int **p2 = &p1;
    printf("Endereço de a: %p\n", &a);
    printf("Valor de a: %d\n", a);
    printf("Endereço de p1: %p\n", p1);
    printf("Valor de p1: %d\n", *p1);
    printf("Endereço de p2: %p\n", p2);
    printf("Valor de p2: %d\n", **p2);
    printf("\n");
    **p2 = 99;
    printf("Endereço de a: %p\n", &a);
    printf("Valor de a: %d\n", a);
    printf("Endereço de p1: %p\n", p1);
    printf("Valor de p1: %d\n", *p1);
    printf("Endereço de p2: %p\n", p2);
    printf("Valor de p2: %d\n", **p2);
    return 0;
}