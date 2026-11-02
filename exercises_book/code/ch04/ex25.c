#include <stdio.h>

#define NB_DAYS 10

int main(void) {
    double sales[NB_DAYS] = {100, 130, 115, 160, 140, 170, 150, 190, 210, 180};
    double windowSum = 0;
    int window, day;
    scanf("%d", &window);
    for (day = 0; day < window; day++)
        windowSum += sales[day];          // النافذة الأولى
    printf("Days 1-%d: %.2f\n", window, windowSum / window);
    for (day = window; day < NB_DAYS; day++) {
        // اليوم الجديد يدخل، واليوم الأقدم يخرج
        windowSum += sales[day] - sales[day - window];
        printf("Days %d-%d: %.2f\n", day - window + 2, day + 1, windowSum / window);
    }
    return 0;
}
