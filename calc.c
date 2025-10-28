#include <math.h>
#include "types.h"
//
// Created by zakatinstepan on 28.10.2025.
//
int max(int a, int b) {
    return a > b ? a : b;
}

result digit_sum(int a, int b) {
    int len1 = floor(log10(a))+1;
    int len2 = floor(log10(b))+1;
    result out;
    out.res = 0;
    int maxlen = max(len1, len2);

    int res=0;
    int carry=0;

    for (int i = 0; i < maxlen; i++) {
        int d1 = a%10;
        if (d1>=3) {
            out.success = false;
            out.errtype = 0;
            return out;
        }
        int d2 = b%10;
        if (d2>=3) {
            out.success = false;
            out.errtype = 1;
            return out;
        }
        a/=10;
        b/=10;

        int x = d1 + d2 + carry;
        carry = 0;
        if (x>=3) {
            carry = 1;
            x-=3;
        }
        res+=x*pow(10, i);

    }
    res+=carry*pow(10, maxlen);
    out.success = true;
    out.res = res;
    return out;
}