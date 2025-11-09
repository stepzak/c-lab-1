//
// Created by zakatinstepan on 03.11.2025.
//

#include "round.h"
#include "types.h"
#define bits_52 0xfffffffffffff

double round(double x) {
    DoubleUnion du;
    du.d = x;

    uint64_t sign = (du.u >> 63) & 1;
    int64_t exponent = ((du.u >> 52) & 0x7FF) - 1023;
    uint64_t mantissa = du.u & 0xFFFFFFFFFFFFF;

    if (exponent >= 52) {
        return x;
    }

    if (exponent < 0) {

        if (exponent < -1) {
            return 0.0;
        }
        double res = 1.0-2.0*sign;
        return res;

    }
    uint64_t fractional_bits = 52 - exponent;
    uint64_t fract_mask = (1ULL << fractional_bits) - 1;;

    uint64_t int_mask = ~fract_mask & 0xFFFFFFFFFFFFF;

    uint64_t first_fractional_bit = (mantissa >> (fractional_bits - 1));
    mantissa &= int_mask;
    if (first_fractional_bit) {
        du.u = (sign << 63) | ((uint64_t)(exponent + 1023) << 52) | mantissa;
        return du.d+1-2*sign;

    }
    du.u = (sign << 63) | (((uint64_t)(exponent + 1023)) << 52) | mantissa;
    return du.d;
}