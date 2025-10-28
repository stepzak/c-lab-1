//
// Created by zakatinstepan on 28.10.2025.
//

#include "tests.h"

#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "calc.h"

bool test_with_args(int a, int b, int res_or_errtype, bool success) {
    result t = digit_sum(a, b);
    if (success) {
        return (t.success && t.res == res_or_errtype);
    }

    return (!t.success && t.errtype == res_or_errtype);

}

void test() {

    int cases[][4] = {
        {0, 0, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 1, 1},
        {1, 1, 2, 1},
        {2, 1, 10, 1},
        {2, 2, 11, 1},
        {12, 1, 20, 1},
        {12, 2, 21, 1},
        {21, 12, 110, 1},
        {100, 1, 101, 1},
        {222, 1, 1000, 1},
        {112, 121, 1010, 1},
        {10, 10, 20, 1},
        {11, 11, 22, 1},
        {20, 2, 22, 1},
        {102, 21, 200, 1},

        {123, 1, 0, 0},
        {1, 125, 1, 0}
    };

    for (int i = 0; i < sizeof(cases) / sizeof(cases[0]); i++) {
        int a = cases[i][0];
        int b = cases[i][1];
        int res_or_errtype = cases[i][2];
        int success = cases[i][3];

        bool test_res = test_with_args(a, b, res_or_errtype, success);
        if (test_res) {
            printf("%d test passed\n", i+1);
        }
        else {
            printf("%d test failed\n", i+1);
            printf("Args: %d+%d, res=%d, success=%d\n", a, b, res_or_errtype, success);
            printf("Result is: %d, success: %d\n", res_or_errtype, success);
            exit(-1);
        }
    }

    printf("All tests passed\n");
}
