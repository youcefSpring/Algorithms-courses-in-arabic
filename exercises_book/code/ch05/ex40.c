#include <stdio.h>

#define NB 3

int main(void) {
    double step[NB][NB] = {{0.2, 0.5, 0.3},       // الرئيسية
                           {0.1, 0.6, 0.3},       // المنتج
                           {0.4, 0.2, 0.4}};      // السلة
    double twoSteps[NB][NB], rowSum;
    int from, to, mid;
    for (from = 0; from < NB; from++) {
        rowSum = 0;
        for (to = 0; to < NB; to++) {
            twoSteps[from][to] = 0;
            for (mid = 0; mid < NB; mid++)        // كل الطرق عبر صفحة وسيطة
                twoSteps[from][to] += step[from][mid] * step[mid][to];
            rowSum += twoSteps[from][to];
            printf(" %.3f", twoSteps[from][to]);
        }
        printf("  (sum %.2f)\n", rowSum);
    }
    return 0;
}
