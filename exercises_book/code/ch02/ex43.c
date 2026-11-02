#include <stdio.h>

int main(void) {
    double price1, price2, price3, price4, tmp;
    scanf("%lf %lf %lf %lf", &price1, &price2, &price3, &price4);
    if (price1 > price2) { tmp = price1; price1 = price2; price2 = tmp; }   // رتب الزوج الأول
    if (price3 > price4) { tmp = price3; price3 = price4; price4 = tmp; }   // رتب الزوج الثاني
    if (price1 > price3) { tmp = price1; price1 = price3; price3 = tmp; }   // price1 أصبح الأصغر
    if (price2 > price4) { tmp = price2; price2 = price4; price4 = tmp; }   // price4 أصبح الأكبر
    if (price2 > price3) { tmp = price2; price2 = price3; price3 = tmp; }   // رتب الوسطيين
    printf("Sorted: %.0f %.0f %.0f %.0f\n", price1, price2, price3, price4);
    printf("Median = %.1f\n", (price2 + price3) / 2);
    return 0;
}
