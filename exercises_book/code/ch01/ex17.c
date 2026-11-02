#include <stdio.h>

int main(void) {
    double revenue, growth, factor, r1, r2, r3;
    scanf("%lf %lf", &revenue, &growth);
    factor = 1 + growth / 100;              // معامل النمو الشهري
    r1 = revenue * factor;                   // بعد شهر
    r2 = r1 * factor;                  // بعد شهرين = revenue × factor × factor
    r3 = r2 * factor;                  // بعد ثلاثة أشهر
    printf("Month 1: %.2f\n", r1);
    printf("Month 2: %.2f\n", r2);
    printf("Month 3: %.2f\n", r3);
    return 0;
}
