#include <stdio.h>

int main(void) {
    int nbDays, day, cur = 0, best = 0, end = 1;
    double prev, sales;
    scanf("%d %lf", &nbDays, &prev);
    for (day = 2; day <= nbDays; day++) {
        scanf("%lf", &sales);
        if (sales > prev)
            cur++;                // السلسلة تستمر
        else
            cur = 0;              // السلسلة انقطعت
        if (cur > best) {
            best = cur;
            end = day;
        }
        prev = sales;                 // اليوم الحالي يصبح السابق
    }
    printf("Longest growth streak: %d days (ending day %d)\n", best, end);
    return 0;
}
