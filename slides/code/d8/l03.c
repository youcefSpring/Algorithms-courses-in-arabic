#include <stdio.h>

double power(double x, int n) {
    if (n == 0)
        return 1;
    return x * power(x, n - 1);
}

int main(void) {
    printf("2^10 = %.0f\n", power(2, 10));
    printf("1.5^3 = %.3f\n", power(1.5, 3));
    return 0;
}
