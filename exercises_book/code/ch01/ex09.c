#include <stdio.h>

int main(void) {
    int seconds, minutes, rest;
    scanf("%d", &seconds);              // المدة بالثواني
    minutes = seconds / 60;                   // قسمة صحيحة: عدد الدقائق الكاملة
    rest = seconds % 60;                   // الباقي: الثواني المتبقية
    printf("%d s = %d min %d s\n", seconds, minutes, rest);
    return 0;
}
