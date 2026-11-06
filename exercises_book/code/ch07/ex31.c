#include <stdio.h>

double mean(double values[], int size) {
    double total = 0;
    int idx;
    for (idx = 0; idx < size; idx++) total += values[idx];
    return total / size;
}

double mySqrt(double value) {
    double guess = value > 1 ? value : 1;
    int iter;
    if (value <= 0) return 0;
    for (iter = 0; iter < 60; iter++)
        guess = (guess + value / guess) / 2;      // نيوتن
    return guess;
}

double correlation(double first[], double second[], int size) {
    double meanF = mean(first, size), meanS = mean(second, size);
    double cov = 0, varF = 0, varS = 0, devF, devS;
    int idx;
    for (idx = 0; idx < size; idx++) {
        devF = first[idx] - meanF;
        devS = second[idx] - meanS;
        cov += devF * devS;
        varF += devF * devF;
        varS += devS * devS;
    }
    return cov / mySqrt(varF * varS);
}

int main(void) {
    double ads[8] = {10, 15, 8, 20, 25, 12, 30, 18};
    double sales[8] = {210, 260, 190, 330, 370, 240, 420, 300};
    double returns[8] = {12, 9, 14, 10, 7, 15, 8, 11};
    printf("r(ads, sales)   = %.4f\n", correlation(ads, sales, 8));
    printf("r(ads, returns) = %.4f\n", correlation(ads, returns, 8));
    return 0;
}
