#include <stdio.h>

int main(void) {
    double price, inflation, factor, p2, real;
    scanf("%lf %lf", &price, &inflation);
    factor = 1 + inflation / 100;              // معامل التضخم السنوي
    p2 = price * factor * factor;               // سنتان = ضرب مرتين
    real = 10000 / (factor * factor);       // القدرة الشرائية لـ 10000 دج
    printf("Price in 2 years = %.2f DA\n", p2);
    printf("Real value of 10000 DA = %.2f DA\n", real);
    return 0;
}
