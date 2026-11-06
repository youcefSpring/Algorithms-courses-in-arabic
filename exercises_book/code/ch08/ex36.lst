#include <stdio.h>

double horner(double coeffs[], int index, int degree, double value) {
    if (index == degree) return coeffs[degree];
    return coeffs[index] + value * horner(coeffs, index + 1, degree, value);
}

int main(void) {
    double coeffs[4] = {1500, 60, -0.5, 0.002};   // a0 + a1 q + a2 q^2 + a3 q^3
    double quantities[5] = {10, 50, 100, 150, 200}, cost;
    int idx;
    for (idx = 0; idx < 5; idx++) {
        cost = horner(coeffs, 0, 3, quantities[idx]);
        printf("q = %3.0f: cost %9.2f, per unit %7.2f\n",
               quantities[idx], cost, cost / quantities[idx]);
    }
    return 0;
}
