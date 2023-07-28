#include "../../include/algorithms/decimal_to_binary.h"
#include "../../include/algorithms/base_converter.h"

char *execute(size_t number) {
    return converter(number, 2);
}