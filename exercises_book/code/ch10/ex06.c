#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int count, idx;
    double *amounts, total = 0;
    scanf("%d", &count);
    amounts = malloc(count * sizeof(double));     // حجم يُعرف أثناء التنفيذ
    if (amounts == NULL) {
        printf("Not enough memory\n");
        return 1;
    }
    for (idx = 0; idx < count; idx++) {
        scanf("%lf", &amounts[idx]);
        total += amounts[idx];
    }
    printf("%d orders, average %.2f DA\n", count, total / count);
    free(amounts);                                // نعيد الذاكرة
    return 0;
}
