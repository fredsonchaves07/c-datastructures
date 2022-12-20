#include <stdlib.h>
#include "stdio.h"

int main() {
    int rows_size = 40000;
    int columns_size = 40000;
    int **m = NULL;
    m = calloc(rows_size, sizeof(int*));
    for (int i = 0; i < rows_size; i ++) {
        m[i] = calloc(columns_size, sizeof(int*));
    }
    for (int j = 0; j < columns_size; j++) {
        for (int i = 0; i < rows_size; i++) {
            m[i][j] = (i + j) % 2;
        }
    }
}