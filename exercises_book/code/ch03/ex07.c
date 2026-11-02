#include <stdio.h>

int main(void) {
    int nbPrices, index, pos;
    double price, max;
    scanf("%d %lf", &nbPrices, &price);
    max = price;                      // أول سعر هو الأكبر مبدئيًا
    pos = 1;
    for (index = 2; index <= nbPrices; index++) {
        scanf("%lf", &price);
        if (price > max) {            // وجدنا سعرًا أكبر
            max = price;
            pos = index;
        }
    }
    printf("Most expensive: %.2f DA (item #%d)\n", max, pos);
    return 0;
}
