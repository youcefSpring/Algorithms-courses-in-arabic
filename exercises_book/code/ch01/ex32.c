#include <stdio.h>

#define TVA  0.19                 // نسبة الرسم
#define SHIP 600.0                // مصاريف الشحن الثابتة

int main(void) {
    double p1, p2, p3, ht, tax, total;
    int q1, q2, q3;
    scanf("%lf %d", &p1, &q1);    // المنتج الأول
    scanf("%lf %d", &p2, &q2);    // المنتج الثاني
    scanf("%lf %d", &p3, &q3);    // المنتج الثالث
    ht = p1 * q1 + p2 * q2 + p3 * q3;   // مجموع الأسطر
    tax = ht * TVA;
    total = ht + tax + SHIP;
    printf("Subtotal HT = %10.2f\n", ht);
    printf("Tax 19%%     = %10.2f\n", tax);
    printf("Shipping    = %10.2f\n", SHIP);
    printf("TOTAL       = %10.2f DA\n", total);
    return 0;
}
