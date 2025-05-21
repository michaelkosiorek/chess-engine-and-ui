#include "math_utils.h"

long long fastPower(int base, int expo) {
    long long result = 1;
    while (expo > 0) {
        if (expo % 2 == 1) { // If expo is odd
            result *= base;
        }
        base *= base;
        expo /= 2;
    }
    return result;
}