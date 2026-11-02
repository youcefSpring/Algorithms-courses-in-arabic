#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2, x3, y3, mx, my, cov;
    int pos;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    mx = (x1 + x2 + x3) / 3;      // متوسط الأسعار
    my = (y1 + y2 + y3) / 3;      // متوسط المبيعات
    // التغاير: هل يتحرك المتغيران في نفس الاتجاه؟
    cov = ((x1 - mx) * (y1 - my) + (x2 - mx) * (y2 - my)
         + (x3 - mx) * (y3 - my)) / 3;
    pos = cov > 0;                // تعبير منطقي: 1 صحيح، 0 خطأ
    printf("Mean price = %.1f, mean sales = %.1f\n", mx, my);
    printf("Covariance = %.2f\n", cov);
    printf("Positive relation? %d\n", pos);
    return 0;
}
