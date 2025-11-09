//
// Created by zakatinstepan on 04.11.2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "round.h"

void test() {
    double test_cases[][2] = {
    {1.0, 1},
        {0.0, 0},
        {1.49, 1},
        {-1.49, -1},
        {-0.5, -1},
        {0.5, 1},
        {-2.7, -3},
        {2.9, 3}
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        double arg = test_cases[i][0], res = test_cases[i][1];
        double f_res = round(arg);
        if (f_res == res) {
            printf("test %d passed\n", i);
        }
        else {
            printf("test %d failed\n", i);
            printf("Expected round(%lf) = %lf, got %lf\n", test_cases[i][0], test_cases[i][1], f_res);
            exit(-1);
        }
    }
}