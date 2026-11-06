#include <stdio.h>

double addTax(double value)   { return value * 1.19; }
double roundTen(double value) { return (int)(value / 10 + 0.5) * 10.0; }
double toEuro(double value)   { return value / 148.5; }

void mapArray(double *values, int size, double (*transform)(double)) {
    double *ptr;
    for (ptr = values; ptr < values + size; ptr++)
        *ptr = transform(*ptr);                // نفس الدالة لكل عنصر
}

int main(void) {
    double prices[5] = {1500, 3200, 899, 4100, 32000};
    double (*pipeline[3])(double) = {addTax, roundTen, toEuro};
    char names[3][10] = {"tax", "round", "euro"};
    int step, idx;
    for (step = 0; step < 3; step++) {
        mapArray(prices, 5, pipeline[step]);
        printf("after %-5s:", names[step]);
        for (idx = 0; idx < 5; idx++) printf(" %9.2f", prices[idx]);
        printf("\n");
    }
    return 0;
}
