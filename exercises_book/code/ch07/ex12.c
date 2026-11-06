#include <stdio.h>

double power(double base, int exponent) {
    double result = 1;
    int step;
    for (step = 0; step < exponent; step++)
        result *= base;                       // ضرب متكرر
    return result;
}

int main(void) {
    double capital, rate;
    int years, year;
    scanf("%lf %lf %d", &capital, &rate, &years);
    for (year = 1; year <= years; year++)
        printf("Year %d: %.2f DA\n", year, capital * power(1 + rate / 100, year));
    return 0;
}
