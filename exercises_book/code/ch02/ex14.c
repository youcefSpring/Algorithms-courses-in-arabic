#include <stdio.h>

int main(void) {
    double price1, price2, price3, tmp;
    scanf("%lf %lf %lf", &price1, &price2, &price3);
    if (price1 > price2) { tmp = price1; price1 = price2; price2 = tmp; }   // الآن price1 <= price2
    if (price2 > price3) { tmp = price2; price2 = price3; price3 = tmp; }   // الأكبر صعد إلى price3
    if (price1 > price2) { tmp = price1; price1 = price2; price2 = tmp; }   // نرتب الاثنين الأولين من جديد
    printf("Sorted: %.0f %.0f %.0f\n", price1, price2, price3);
    return 0;
}
