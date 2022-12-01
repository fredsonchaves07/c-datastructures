#include "stdio.h"

void first_example() {
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
}

void func(int *px, int *py) {
    *px = *py;
    *py = (*py) * (*px);
    *px = *px + 2;
}

void second_example() {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    func(&x, &y);
    printf("Valor de x %d\n", x);
    printf("Valor de y %d\n", y);
}

int main() {
    second_example();
    return 0;
}

