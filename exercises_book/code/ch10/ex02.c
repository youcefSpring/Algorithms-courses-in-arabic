#include <stdio.h>

void swap(double *first, double *second) {
    double tmp = *first;
    *first = *second;                 // نعدل المتغيرات الأصلية
    *second = tmp;
}

int main(void) {
    double low, high;
    scanf("%lf %lf", &low, &high);
    if (low > high)
        swap(&low, &high);            // نمرر العناوين
    printf("Price range: %.2f - %.2f DA\n", low, high);
    return 0;
}
