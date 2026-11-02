#include <stdio.h>

int main(void) {
    int day, month, year, max;
    scanf("%d %d %d", &day, &month, &year);
    if (month == 2)
        max = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        max = 30;
    else
        max = 31;
    if (day < max) {
        day = day + 1;                // نفس الشهر
    } else {
        day = 1;                    // بداية شهر جديد
        if (month == 12) {
            month = 1;                // بداية سنة جديدة
            year = year + 1;
        } else {
            month = month + 1;
        }
    }
    printf("Delivery date: %02d/%02d/%d\n", day, month, year);
    return 0;
}
