#include <stdio.h>

#define TVA 0.19                  // نسبة الرسم 19%

int main(void) {
    double ht, tax, ttc;          // السعر دون رسوم، الرسم، السعر النهائي
    printf("Price HT: ");
    scanf("%lf", &ht);            // قراءة السعر دون رسوم
    tax = ht * TVA;               // قيمة الرسم
    ttc = ht + tax;               // السعر النهائي
    printf("\nTax = %.2f DA\n", tax);
    printf("TTC = %.2f DA\n", ttc);
    return 0;
}
