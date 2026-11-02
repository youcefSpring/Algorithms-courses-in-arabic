#include <stdio.h>

int main(void) {
    double c1, c2, m1, m2, s1, s2, spend, d1, d2;
    int customer, n1, n2, it = 0, changed = 1;
    scanf("%lf %lf", &c1, &c2);           // المركزان الابتدائيان
    while (changed && it < 20) {
        s1 = s2 = 0; n1 = n2 = 0;
        for (customer = 0; customer < 20; customer++) {
            spend = (customer * 37) % 50 + (customer % 2) * 60;   // إنفاق الزبون customer
            d1 = spend - c1; if (d1 < 0) d1 = -d1;  // المسافة إلى c1
            d2 = spend - c2; if (d2 < 0) d2 = -d2;  // المسافة إلى c2
            if (d1 <= d2) { s1 += spend; n1++; }    // أقرب إلى c1
            else          { s2 += spend; n2++; }
        }
        m1 = (n1 > 0) ? s1 / n1 : c1;   // المركز الجديد = المتوسط
        m2 = (n2 > 0) ? s2 / n2 : c2;
        changed = (m1 != c1 || m2 != c2);
        c1 = m1; c2 = m2;
        it++;
        printf("Iter %d: c1 = %.2f (%d), c2 = %.2f (%d)\n", it, c1, n1, c2, n2);
    }
    printf("Converged after %d iterations\n", it);
    return 0;
}
