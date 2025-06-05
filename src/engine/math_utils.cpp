#include "math_utils.h"

uint64_t fastPowerPos(uint64_t base, uint64_t expo) {
    uint64_t result = 1;
    while (expo > 0) {
        if (expo % 2 == 1) {
            result *= base;
        }
        base *= base;
        expo /= 2;
    }
    return result;
}