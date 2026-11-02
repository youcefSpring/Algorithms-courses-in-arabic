#include <stdio.h>

int main(void) {
    double revenue, cost, result;
    scanf("%lf %lf", &revenue, &cost);
    result = revenue - cost;               // النتيجة الصافية
    if (result > 0)
        printf("Profit: %.2f DA\n", result);
    else if (result < 0)
        printf("Loss: %.2f DA\n", -result); // نعرض الخسارة كعدد موجب
    else
        printf("Break-even\n");
    return 0;
}
