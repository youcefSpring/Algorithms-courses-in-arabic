#include <stdio.h>

typedef struct { int day, month, year; } Date;

int daysIn(int month, int year) {
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)) return 29;
    return days[month - 1];
}

Date addDays(Date date, int count) {
    while (count-- > 0) {
        date.day++;
        if (date.day > daysIn(date.month, date.year)) {   // شهر جديد
            date.day = 1;
            date.month++;
            if (date.month > 12) { date.month = 1; date.year++; }
        }
    }
    return date;
}

int main(void) {
    Date purchase = {15, 11, 2027}, due = purchase;
    int idx;
    printf("Purchase: %02d/%02d/%d\n", purchase.day, purchase.month, purchase.year);
    for (idx = 1; idx <= 4; idx++) {
        due = addDays(due, 30);
        printf("Installment %d due %02d/%02d/%d\n", idx, due.day, due.month, due.year);
    }
    return 0;
}
