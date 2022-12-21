#include "stdlib.h"

int main () {
    int rows_size = 43000;
    int columns_size = 43000;
    int elements_size = rows_size * columns_size;
    int *m = calloc(elements_size, sizeof(int));
    for (int i = 0; i < rows_size; i ++) {
        for (int j = 0; j < columns_size; j ++) {
            int index = (i * columns_size) + j;
            m[index] = (i + j) % 2 ;
        }
    }
    return 0;
}