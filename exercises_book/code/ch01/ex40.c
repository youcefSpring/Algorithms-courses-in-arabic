#include <stdio.h>

int main(void) {
    int orderDay, delay, deliveryDay, week, wd;
    scanf("%d %d", &orderDay, &delay);
    deliveryDay = orderDay + delay;                    // رقم يوم التسليم في السنة
    week = (deliveryDay - 1) / 7 + 1;       // نطرح 1 لأن الترقيم يبدأ من 1
    wd = (deliveryDay - 1) % 7;             // 0 أحد، 1 إثنين، ...
    printf("Delivery day = %d\n", deliveryDay);
    printf("Week = %d, weekday = %d\n", week, wd);
    return 0;
}
