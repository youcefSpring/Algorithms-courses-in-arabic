#include <stdio.h>

int isPrime(int number) {
    int divisor;
    if (number < 2) return 0;
    if (number % 2 == 0) return number == 2;
    for (divisor = 3; divisor * divisor <= number; divisor += 2)   // حتى الجذر فقط
        if (number % divisor == 0)
            return 0;
    return 1;
}

int main(void) {
    int code, count = 0;
    for (code = 1000; code <= 1100; code++)
        if (isPrime(code)) {
            printf("%d ", code);
            count++;
        }
    printf("\n%d valid coupons\n", count);
    return 0;
}
