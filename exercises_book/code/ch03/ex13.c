#include <stdio.h>

int main(void) {
    double value, root, old, diff;
    int it = 0;
    scanf("%lf", &value);
    root = (value > 1) ? value : 1;          // تقدير أولي موجب
    do {
        old = root;
        root = (root + value / root) / 2;      // متوسط root و value/root
        it++;
        diff = root - old;
        if (diff < 0) diff = -diff;   // القيمة المطلقة
    } while (diff > 1e-9);
    printf("sqrt(%.2f) = %.9f\n", value, root);
    printf("Iterations: %d\n", it);
    return 0;
}
