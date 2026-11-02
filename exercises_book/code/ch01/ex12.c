#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2, dx, dy, d2;
    scanf("%lf %lf", &x1, &y1);   // الزبون الأول
    scanf("%lf %lf", &x2, &y2);   // الزبون الثاني
    dx = x1 - x2;                 // الفرق في عدد الطلبيات
    dy = y1 - y2;                 // الفرق في متوسط السلة
    d2 = dx * dx + dy * dy;       // مربع المسافة دون جذر
    printf("Squared distance = %.2f\n", d2);
    printf("Orders gap = %.0f\n", dx);
    return 0;
}
