#include <stdio.h>

int main(void) {
    double income, rest, tax = 0;
    scanf("%lf", &income);
    rest = income;                       // الجزء الذي لم يُضرب بعد
    if (rest > 1920000) {                // الجزء فوق 1920000
        tax = tax + (rest - 1920000) * 0.33;
        rest = 1920000;
    }
    if (rest > 960000) {
        tax = tax + (rest - 960000) * 0.30;
        rest = 960000;
    }
    if (rest > 480000) {
        tax = tax + (rest - 480000) * 0.27;
        rest = 480000;
    }
    if (rest > 240000)                   // الشريحة الأولى معفاة
        tax = tax + (rest - 240000) * 0.23;
    printf("Tax = %.2f DA\n", tax);
    if (income > 0)
        printf("Effective rate = %.2f %%\n", tax / income * 100);
    return 0;
}
