#include <stdio.h>

double fastPower(double base, int exponent, int counter[]) {
    double half;
    if (exponent == 0) return 1;
    if (exponent % 2 == 1) {
        counter[0]++;
        return base * fastPower(base, exponent - 1, counter);   // أس فردي
    }
    half = fastPower(base, exponent / 2, counter);              // نحسب النصف مرة واحدة
    counter[0]++;
    return half * half;
}

int main(void) {
    int exponents[4] = {10, 100, 365, 1000}, counter[1], idx;
    double result;
    for (idx = 0; idx < 4; idx++) {
        counter[0] = 0;
        result = fastPower(1.01, exponents[idx], counter);
        printf("1.01^%-4d = %14.4f with %2d multiplications (naive: %d)\n",
               exponents[idx], result, counter[0], exponents[idx]);
    }
    return 0;
}
