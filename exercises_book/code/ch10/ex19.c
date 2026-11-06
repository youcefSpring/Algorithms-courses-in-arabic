#include <stdio.h>

double noDiscount(double amount) { return amount; }
double fixedOff(double amount)   { return amount > 5000 ? amount - 500 : amount; }
double tenPercent(double amount) { return amount > 10000 ? amount * 0.9 : amount; }

int main(void) {
    double (*policies[3])(double) = {noDiscount, fixedOff, tenPercent};   // جدول دوال
    char codes[3] = {'N', 'F', 'P'}, campaign;
    double baskets[4] = {3000, 7500, 12000, 25000};
    double (*policy)(double) = noDiscount;
    int idx;
    scanf(" %c", &campaign);
    for (idx = 0; idx < 3; idx++)
        if (codes[idx] == campaign) policy = policies[idx];
    for (idx = 0; idx < 4; idx++)
        printf("%8.2f -> %8.2f DA\n", baskets[idx], policy(baskets[idx]));   // استدعاء عبر المؤشر
    printf("Best policy for 12000: %.2f\n",
           tenPercent(12000) < fixedOff(12000) ? tenPercent(12000) : fixedOff(12000));
    return 0;
}
