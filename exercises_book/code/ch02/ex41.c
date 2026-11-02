#include <stdio.h>

int main(void) {
    int day, month, year, yearInCentury, century, weekday;
    scanf("%d %d %d", &day, &month, &year);
    printf("%02d/%02d/%d is a ", day, month, year);
    if (month < 3) {              // جانفي وفيفري: شهرا 13 و14 من السنة السابقة
        month = month + 12;
        year = year - 1;
    }
    yearInCentury = year % 100;              // السنة داخل القرن
    century = year / 100;              // القرن
    weekday = (day + 13 * (month + 1) / 5 + yearInCentury + yearInCentury / 4 + century / 4 + 5 * century) % 7;
    switch (weekday) {
        case 0: printf("Saturday\n"); break;
        case 1: printf("Sunday\n"); break;
        case 2: printf("Monday\n"); break;
        case 3: printf("Tuesday\n"); break;
        case 4: printf("Wednesday\n"); break;
        case 5: printf("Thursday\n"); break;
        default: printf("Friday\n");
    }
    return 0;
}
