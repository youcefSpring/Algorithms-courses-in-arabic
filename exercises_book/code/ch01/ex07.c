#include <stdio.h>

int main(void) {
    double buy, sell, profit, margin;
    scanf("%lf %lf", &buy, &sell);
    profit = sell - buy;              // الربح لكل وحدة
    margin = profit / sell * 100;     // الهامش بالمئة
    printf("Profit = %.2f DA\n", profit);
    printf("Margin = %.2f %%\n", margin);   // %% تطبع الرمز %
    return 0;
}
