#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "float_vector.h"

struct float_vector {
    int capacity;
    int size;
    float *data;
};

bool isFull(const FloatVector *floatVector) {
    return floatVector->size == floatVector->capacity;
}

FloatVector *create(int capacity) {
    FloatVector *floatVector = calloc(1, sizeof(FloatVector));
    floatVector->size = 0;
    floatVector->capacity = capacity;
    floatVector->data = calloc(capacity, sizeof(float));
    return floatVector;
}

void clear(FloatVector **pFloatVector) {
    FloatVector *floatVector = *pFloatVector;
    free(floatVector->data);
    free(floatVector);
    *pFloatVector = NULL;
}

int size(const FloatVector *floatVector) {
    return floatVector->size;
}

int capacity(const FloatVector *floatVector) {
    return floatVector->capacity;
}

void append(FloatVector *floatVector, float value) {
    if (floatVector->size == capacity(floatVector)) {
        fprintf(stderr, "Vector is full\n");
        exit(EXIT_FAILURE);
    }
    floatVector->data[floatVector->size] = value;
    floatVector->size ++;
}

void print(const FloatVector *floatVector) {
    printf("Size: %d\n", size(floatVector));
    printf("Capacity: %d\n", capacity(floatVector));
    printf("Elements: \n");
    for (int i = 0; i < size(floatVector); i ++) {
        printf("[%d] = %f\n", i, floatVector->data[i]);
    }
}
