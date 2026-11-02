#include <stdio.h>

int main(void) {
    int hour;
    double price, factor;
    scanf("%d %lf", &hour, &price);
    if ((hour >= 11 && hour <= 13) || (hour >= 19 && hour <= 21))
        factor = 1.2;                      // ساعات الذروة
    else if (hour >= 15 && hour <= 17)
        factor = 0.75;                     // الساعة السعيدة
    else if (hour >= 0 && hour <= 6)
        factor = 1.3;                      // الليل
    else
        factor = 1.0;                      // السعر العادي
    printf("Hour %d: factor %.2f -> %.2f DA\n", hour, factor, price * factor);
    return 0;
}
