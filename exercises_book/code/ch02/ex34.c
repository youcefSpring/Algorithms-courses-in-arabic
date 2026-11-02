#include <stdio.h>

int main(void) {
    double before, now, change, ac;
    scanf("%lf %lf", &before, &now);
    change = (now - before) / before * 100;    // التغير بالمئة
    ac = (change < 0) ? -change : change;                // القيمة المطلقة
    printf("Change = %.1f %% : ", change);
    if (ac <= 2) {
        printf("stable\n");
    } else {
        if (change > 0) printf("increase");
        else       printf("decrease");
        if (ac > 20)
            printf(" (sharp!)");          // تنبيه للتغير الكبير
        printf("\n");
    }
    return 0;
}
