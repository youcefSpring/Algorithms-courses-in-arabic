#include <stdio.h>

int main(void) {
    int nbItems, item;
    double price, sum = 0;            // المجمِّع يبدأ من الصفر
    scanf("%d", &nbItems);
    for (item = 1; item <= nbItems; item++) {    // nbItems تكرارًا بالضبط
        scanf("%lf", &price);
        sum = sum + price;            // نضيف السعر الحالي
    }
    printf("Basket total = %.2f DA\n", sum);
    return 0;
}
