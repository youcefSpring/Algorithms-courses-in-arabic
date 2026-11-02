#include <stdio.h>

int main(void) {
    double capital, rate, years, exponent, term = 1, sum = 1;
    int term_k = 0;
    scanf("%lf %lf %lf", &capital, &rate, &years);
    exponent = rate * years;
    do {
        term_k++;
        term = term * exponent / term_k;      // exponent^term_k / term_k! من الحد السابق
        sum += term;
    } while (term > 1e-12);
    printf("e^%.2f = %.10f (%d terms)\n", exponent, sum, term_k);
    printf("Continuous: %.2f DA\n", capital * sum);
    return 0;
}
