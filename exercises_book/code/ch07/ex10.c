#include <stdio.h>

double percentChange(double oldValue, double newValue) {
    return (newValue - oldValue) / oldValue * 100;
}

int main(void) {
    double sales[4] = {80000, 92000, 87400, 104880};
    int month;
    for (month = 1; month < 4; month++)
        printf("Month %d -> %d: %+.1f%%\n", month, month + 1,
               percentChange(sales[month - 1], sales[month]));   // + لعرض الإشارة
    return 0;
}
