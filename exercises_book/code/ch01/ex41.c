#include <stdio.h>

int main(void) {
    int priceA, priceB, diff, mask, ad, max, min;
    scanf("%d %d", &priceA, &priceB);
    diff = priceA - priceB;
    mask = diff >> 31;               // كل البتات 1 إذا كان diff سالبًا، وإلا 0
    ad = (diff ^ mask) - mask;       // إذا كان سالبًا: عكس البتات ثم +1 = -diff
    max = (priceA + priceB + ad) / 2;       // الأكبر
    min = (priceA + priceB - ad) / 2;       // الأصغر
    printf("|a - b| = %d\n", ad);
    printf("Max = %d, Min = %d\n", max, min);
    return 0;
}
