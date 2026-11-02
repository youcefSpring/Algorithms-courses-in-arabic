#include <stdio.h>

int main(void) {
    int order, d1, d2, d3, d4, digitSum;
    scanf("%d", &order);
    d1 = order / 1000;            // رقم الآلاف
    d2 = (order / 100) % 10;      // رقم المئات
    d3 = (order / 10) % 10;       // رقم العشرات
    d4 = order % 10;              // رقم الآحاد
    digitSum = d1 + d2 + d3 + d4;    // مجموع الأرقام
    printf("Digit sum = %d\n", digitSum);
    printf("Check digit = %d\n", digitSum % 10);
    return 0;
}
