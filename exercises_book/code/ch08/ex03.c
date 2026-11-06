#include <stdio.h>

double power(double base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * power(base, exponent - 1);
}

int main(void) {
    int weeks;
    for (weeks = 4; weeks <= 12; weeks += 4)
        printf("After %2d weeks: %.0f followers\n", weeks, 2000 * power(1.1, weeks));
    return 0;
}
