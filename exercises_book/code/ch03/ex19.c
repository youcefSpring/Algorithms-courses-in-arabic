#include <stdio.h>

int main(void) {
    long number;
    int digit, count = 0, sum = 0, big = 0;
    scanf("%ld", &number);
    do {                          // do-while: الرقم 0 له رقم واحد
        digit = number % 10;               // آخر رقم
        count++;
        sum += digit;
        if (digit > big) big = digit;
        number = number / 10;               // نحذف آخر رقم
    } while (number > 0);
    printf("Digits = %d, sum = %d, largest = %d\n", count, sum, big);
    return 0;
}
