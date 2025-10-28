#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "types.h"
#include "calc.h"

int main() {
    test();
    int a, b;

    scanf("%d %d", &a, &b);
    result res = digit_sum(a, b);
    if (res.success) {
        printf("%d\n", res);
    }

    else {
        int errmsg[2] = {a, b};
        printf("'%d' is not a valid number", errmsg[res.errtype]);
        exit(1);
    }
    return 0;
}