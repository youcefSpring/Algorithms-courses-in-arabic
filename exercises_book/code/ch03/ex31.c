#include <stdio.h>

int main(void) {
    double alpha, sales, smooth;
    int nbDays, day;
    scanf("%lf %d %lf", &alpha, &nbDays, &sales);
    smooth = sales;                                // نبدأ بالملاحظة الأولى
    printf("Day 1: %.2f\n", smooth);
    for (day = 2; day <= nbDays; day++) {
        scanf("%lf", &sales);
        smooth = alpha * sales + (1 - alpha) * smooth;  // مزيج من الجديد والقديم
        printf("Day %d: %.2f\n", day, smooth);
    }
    printf("Forecast day %d: %.2f\n", nbDays + 1, smooth);
    return 0;
}
