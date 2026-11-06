#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int compareDates(Date first, Date second) {
    if (first.year != second.year) return first.year < second.year ? -1 : 1;
    if (first.month != second.month) return first.month < second.month ? -1 : 1;
    if (first.day != second.day) return first.day < second.day ? -1 : 1;
    return 0;
}

int main(void) {
    Date orderA = {28, 10, 2026}, orderB = {3, 11, 2026};
    int result = compareDates(orderA, orderB);
    printf("A: %02d/%02d/%d  B: %02d/%02d/%d\n", orderA.day, orderA.month, orderA.year,
           orderB.day, orderB.month, orderB.year);
    if (result < 0) printf("Order A is older\n");
    else if (result > 0) printf("Order B is older\n");
    else printf("Same day\n");
    return 0;
}
