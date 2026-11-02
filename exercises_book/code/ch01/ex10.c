#include <stdio.h>

int main(void) {
    int visitors, orders;
    double rate;
    scanf("%d %d", &visitors, &orders);
    // التحويل (double) يمنع القسمة الصحيحة التي تعطي 0
    rate = (double)orders / visitors * 100;
    printf("Conversion rate = %.2f %%\n", rate);
    return 0;
}
