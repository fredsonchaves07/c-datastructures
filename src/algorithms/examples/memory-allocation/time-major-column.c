#include "stdio.h"

int main() {
    int rows_size = 1000;
    int columns_size = 1000;
    int m[rows_size][columns_size];
    for (int i = 0; i < columns_size; i++) {
        for (int j = 0; j < rows_size; j++) {
            m[i][j] = 100;
        }
    }
    for (int i = 0; i < columns_size; i++) {
        for (int j = 0; j < rows_size; j++) {
            m[i][j];
        }
    }
}