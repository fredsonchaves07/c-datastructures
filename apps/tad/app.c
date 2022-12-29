#include "float_vector.h"

int main() {
    FloatVector *floatVector = create(10);
    append(floatVector, 10.0);
    print(floatVector);
    clear(&floatVector);
    return 0;
}