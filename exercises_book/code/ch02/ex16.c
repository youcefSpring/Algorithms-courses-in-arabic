#include <stdio.h>

int main(void) {
    int month, year, days;
    scanf("%d %d", &month, &year);
    switch (month) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:     // عدة حالات تشترك في نفس الكود
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                days = 29;               // سنة كبيسة
            else
                days = 28;
            break;
        default:
            days = 0;                    // شهر غير صالح
    }
    if (days == 0)
        printf("Invalid month\n");
    else
        printf("Month %d/%d has %d days\n", month, year, days);
    return 0;
}
