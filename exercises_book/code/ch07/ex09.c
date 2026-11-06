#include <stdio.h>

int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int daysInFebruary(int year) {
    return isLeap(year) ? 29 : 28;     // دالة تستدعي دالة
}

int main(void) {
    int year, idx;
    for (idx = 0; idx < 4; idx++) {
        scanf("%d", &year);
        printf("February %d: %d days\n", year, daysInFebruary(year));
    }
    return 0;
}
