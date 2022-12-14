#include "stdio.h"
#include "stdlib.h"

int main() {

    // Alocação estática
//    int m[2][2][3] = {
//            {{0, 1, 2}, {4, 5, 6},
//            },
//            {{7, 8, 2}, {1, 6, 3}}
//    };

//    printf("&m = %p, m = %p \n\n", &m, m);
//    for (int k = 0; k < 2; k ++) {
//        for (int i = 0; i < 2; i ++) {
//            for (int j = 0; j < 3; j ++) {
//                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
//            }
//        }
//    }

    int values[2][2][3] = {
            {{0, 1, 2}, {4, 5, 6},
            },
            {{7, 8, 2}, {1, 6, 3}}
    };

    //Alocação dinâmica
    int ***m = calloc(2, sizeof(int**));
    for (int k = 0; k < 2; k ++) {
        m[k] = calloc(2, sizeof(int *));
        for (int j = 0; j < 3; j ++) {
            m[k][j] = calloc(3, sizeof(int));
        }
    }

    for (int i = 0; i < 2; i ++) {
        for (int k = 0; k < 2; k ++) {
            for (int j = 0; j < 3; j ++) {
                m[i][k][j] = values[i][k][j];
            }
        }
    }

    printf("&m = %p, m = %p \n\n", &m, m);
    for (int k = 0; k < 2; k ++) {
        for (int i = 0; i < 2; i ++) {
            for (int j = 0; j < 3; j ++) {
                printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n", k, i, j, &m[k][i][j], k, i, j, m[k][i][j]);
            }
        }
    }
}