#include <stdio.h>

double myExp(double value) {
    double sum = 1, term = 1;
    int rank = 1;
    while (term > 1e-12 || term < -1e-12) {
        term = term * value / rank;       // الحد التالي من السابق
        sum += term;
        rank++;
    }
    return sum;
}

int main(void) {
    double start = 1500, rate = 0.08;
    int month;
    printf("e = %.10f\n", myExp(1));
    for (month = 0; month <= 12; month += 3)
        printf("Month %2d: %.0f users\n", month, start * myExp(rate * month));
    return 0;
}
