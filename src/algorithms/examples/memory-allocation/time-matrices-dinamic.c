#include "stdio.h"
#include "stdlib.h"

int main() {
    int rows_size = 43000;
    int columns_size = 43000;
    int **m = NULL;
    m = calloc(rows_size, sizeof(int*));
    for (int i = 0; i < rows_size; i ++) {
        m[i] = calloc(columns_size, sizeof(int*));
    }
    for (int i = 0; i < rows_size; i++) {
        for (int j = 0; j < columns_size; j++) {
            m[i][j] = (i + j) % 2;
        }
    }
    return 0;
}