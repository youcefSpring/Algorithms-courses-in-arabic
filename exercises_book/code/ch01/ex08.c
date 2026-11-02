#include <stdio.h>

int main(void) {
    int priceA, priceB, tmp;
    scanf("%d %d", &priceA, &priceB);
    printf("Before: priceA = %d, priceB = %d\n", priceA, priceB);
    tmp = priceA;          // نحفظ priceA قبل أن نفقدها
    priceA = priceB;            // priceA تأخذ قيمة priceB
    priceB = tmp;          // priceB تأخذ القيمة القديمة لـ priceA
    printf("After:  priceA = %d, priceB = %d\n", priceA, priceB);
    return 0;
}
