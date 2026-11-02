#include <stdio.h>

#define NB_PRICES 8

int main(void) {
    double prices[NB_PRICES] = {1200, 8900, 450, 15000, 5000, 7200, 300, 22000};
    double premium[NB_PRICES];                  // في أسوأ الحالات كل العناصر
    int index, nbPremium = 0;                 // nbPremium: عدد العناصر المنسوخة
    for (index = 0; index < NB_PRICES; index++)
        if (prices[index] > 5000)
            premium[nbPremium++] = prices[index];        // ننسخ ثم نزيد nbPremium
    printf("%d premium products:", nbPremium);
    for (index = 0; index < nbPremium; index++)
        printf(" %.0f", premium[index]);
    printf("\n");
    return 0;
}
