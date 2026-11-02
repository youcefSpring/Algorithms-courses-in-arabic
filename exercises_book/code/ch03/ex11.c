#include <stdio.h>

int main(void) {
    int nbPages, index;
    double loadTime, min, max, sum;
    scanf("%d %lf", &nbPages, &loadTime);
    min = max = sum = loadTime;          // التهيئة بالقيمة الأولى
    for (index = 2; index <= nbPages; index++) {
        scanf("%lf", &loadTime);
        sum += loadTime;
        if (loadTime < min) min = loadTime;     // تحديث الأصغر
        if (loadTime > max) max = loadTime;     // تحديث الأكبر
    }
    printf("Min = %.0f ms, Max = %.0f ms\n", min, max);
    printf("Range = %.0f ms, Mean = %.1f ms\n", max - min, sum / nbPages);
    return 0;
}
