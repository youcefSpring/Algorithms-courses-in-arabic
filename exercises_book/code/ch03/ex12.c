#include <stdio.h>

int main(void) {
    int nbDays, day;
    double sales, sum = 0, s2 = 0, mean, var;
    scanf("%d", &nbDays);
    for (day = 0; day < nbDays; day++) {
        scanf("%lf", &sales);
        sum += sales;                   // مجموع القيم
        s2 += sales * sales;              // مجموع المربعات
    }
    mean = sum / nbDays;
    var = s2 / nbDays - mean * mean;   // متوسط المربعات ناقص مربع المتوسط
    printf("Mean = %.2f\n", mean);
    printf("Variance = %.2f\n", var);
    return 0;
}
