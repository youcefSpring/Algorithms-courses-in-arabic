#include <stdio.h>

double power(double base, int exponent) {
    double result = 1;
    while (exponent-- > 0) result *= base;
    return result;
}

double monthlyPayment(double amount, double annualRate, int months) {
    double monthly = annualRate / 12 / 100;
    if (monthly == 0) return amount / months;
    return amount * monthly / (1 - 1 / power(1 + monthly, months));
}

int main(void) {
    double amount, rate, pay;
    int durations[3] = {6, 12, 24}, idx;
    scanf("%lf %lf", &amount, &rate);
    for (idx = 0; idx < 3; idx++) {
        pay = monthlyPayment(amount, rate, durations[idx]);
        printf("%2d months: %9.2f DA/month, extra cost %8.2f DA\n",
               durations[idx], pay, pay * durations[idx] - amount);
    }
    return 0;
}
