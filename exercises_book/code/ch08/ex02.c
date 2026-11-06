#include <stdio.h>

int digitSum(long number) {
    if (number < 10)
        return (int)number;                      // رقم واحد
    return number % 10 + digitSum(number / 10);  // آخر رقم + الباقي
}

int main(void) {
    long number;
    scanf("%ld", &number);
    printf("Digit sum of %ld = %d\n", number, digitSum(number));
    return 0;
}
