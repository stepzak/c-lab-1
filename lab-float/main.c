#include "round.h"
#include <stdio.h>
#include "tests.h"

int main() {
    test();
    double x;
    scanf("%lf", &x);

    double rounded = round(x);
    printf("%lf\n", rounded);

    return 0;
}