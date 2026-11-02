#include <stdio.h>

int main(void) {
    double prices[100], key, med;
    int nbPrices, index, scan;
    scanf("%d", &nbPrices);
    for (index = 0; index < nbPrices; index++)
        scanf("%lf", &prices[index]);
    for (index = 1; index < nbPrices; index++) {         // ترتيب بالإدراج
        key = prices[index];
        for (scan = index - 1; scan >= 0 && prices[scan] > key; scan--)
            prices[scan + 1] = prices[scan];
        prices[scan + 1] = key;
    }
    if (nbPrices % 2 == 1)
        med = prices[nbPrices / 2];               // العنصر الأوسط
    else
        med = (prices[nbPrices / 2 - 1] + prices[nbPrices / 2]) / 2;
    printf("Median price = %.2f DA\n", med);
    return 0;
}
