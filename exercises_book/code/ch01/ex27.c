#include <stdio.h>

int main(void) {
    int stock, sold, rec, daily, days, rest;
    scanf("%d %d %d %d", &stock, &sold, &rec, &daily);
    stock = stock - sold + rec;           // تحديث المخزون
    days = stock / daily;             // عدد الأيام الكاملة
    rest = stock % daily;             // ما يبقى بعدها
    printf("New stock = %d\n", stock);
    printf("Covers %d full days (%d left)\n", days, rest);
    return 0;
}
