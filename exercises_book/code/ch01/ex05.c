#include <stdio.h>

int main(void) {
    double w1, w2, w3, total, avg;
    scanf("%lf %lf %lf", &w1, &w2, &w3);
    total = w1 + w2 + w3;         // الوزن الإجمالي
    avg = total / 3;              // total حقيقي، فالقسمة حقيقية
    printf("Total weight = %.2f kg\n", total);
    printf("Average weight = %.2f kg\n", avg);
    return 0;
}
