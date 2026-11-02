#include <stdio.h>

int main(void) {
    int quantity, free;
    double price, total;
    scanf("%d %lf", &quantity, &price);
    free = quantity / 3;                     // وحدة مجانية لكل 3
    total = (quantity - free) * price;
    if (quantity >= 10)
        total = total * 0.95;         // تخفيض إضافي للكميات الكبيرة
    printf("Free units = %d\n", free);
    printf("Total = %.2f DA\n", total);
    printf("Saved = %.2f DA\n", quantity * price - total);
    return 0;
}
