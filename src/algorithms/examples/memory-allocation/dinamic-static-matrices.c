#include "stdio.h"
#include "stdlib.h"

int main() {
    int rows = 3;
    int coluns = 5;
    int **m = NULL;
    m = calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i ++) {
        m[i] = calloc(coluns, sizeof(int*));
    }
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < coluns; j ++) {
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}