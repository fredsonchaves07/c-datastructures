#include <stdio.h>

int main() {
    int a = 10;
    int b, c;
    printf("Endereço da memória da variavel a: %p\n", &a);
    printf("Valor da variável a: %d\n", a);
    printf("Endereço da memória da variavel b: %p\n", &b);
    printf("Valor da variável b: %d\n", b);
    printf("Endereço da memória da variavel c: %p\n", &c);
    printf("Valor da variável c: %d\n\n", c);
    b = 20;
    c = a + b;
    printf("Endereço da memória da variavel a: %p\n", &a);
    printf("Valor da variável a: %d\n", a);
    printf("Endereço da memória da variavel b: %p\n", &b);
    printf("Valor da variável b: %d\n", b);
    printf("Endereço da memória da variavel c: %p\n", &c);
    printf("Valor da variável c: %d\n\n", c);
    return 1;
}