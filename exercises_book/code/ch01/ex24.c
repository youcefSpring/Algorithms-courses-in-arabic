#include <stdio.h>

int main(void) {
    double imp, clicks, cost, ctr, cpc, cpm;
    scanf("%lf %lf %lf", &imp, &clicks, &cost);
    ctr = clicks / imp * 100;     // نسبة النقر بالمئة
    cpc = cost / clicks;          // تكلفة النقرة الواحدة
    cpm = cost / imp * 1000;      // تكلفة كل ألف ظهور
    printf("CTR = %.2f %%\n", ctr);
    printf("CPC = %.2f DA\n", cpc);
    printf("CPM = %.2f DA\n", cpm);
    return 0;
}
