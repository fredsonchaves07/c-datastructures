#include <stdlib.h>
#include "float_vector.h"

struct float_vector {
    int capacity;
    int size;
    float *data;
};

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
