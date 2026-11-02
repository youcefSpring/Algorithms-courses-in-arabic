#include <stdio.h>

int main(void) {
    double target, sales, cum = 0;
    int maxDays, day, reached = 0;
    scanf("%lf %d", &target, &maxDays);
    for (day = 1; day <= maxDays; day++) {
        if (scanf("%lf", &sales) != 1)  // نهاية البيانات المتوفرة
            break;
        cum += sales;
        if (cum >= target) {
            reached = day;
            break;                  // نخرج من الحلقة فورًا
        }
    }
    if (reached)
        printf("Target reached on day %d (%.0f DA)\n", reached, cum);
    else
        printf("Target missed by %.0f DA\n", target - cum);
    return 0;
}
