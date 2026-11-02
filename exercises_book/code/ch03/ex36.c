#include <stdio.h>

int main(void) {
    double lo, hi, mid, gap;
    int it = 0;
    scanf("%lf %lf", &lo, &hi);
    while (hi - lo > 0.001) {
        mid = (lo + hi) / 2;
        gap = 5000 / mid - (2 * mid - 20);  // الطلب ناقص العرض
        if (gap > 0)
            lo = mid;             // الطلب أكبر: السعر يجب أن يرتفع
        else
            hi = mid;
        it++;                     // كل دورة تقسم المجال على 2
    }
    mid = (lo + hi) / 2;
    printf("Equilibrium price = %.3f DA (%d iterations)\n", mid, it);
    printf("Quantity = %.2f\n", 5000 / mid);
    return 0;
}
