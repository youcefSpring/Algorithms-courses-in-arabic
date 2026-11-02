#include <stdio.h>

int main(void) {
    int number, divisor, prime;
    scanf("%d", &number);
    prime = (number >= 2);             // 0 و 1 ليسا أوليين
    // يكفي البحث حتى الجذر: إذا كان number = a × b فأحدهما <= الجذر
    for (divisor = 2; prime && divisor * divisor <= number; divisor++) {
        if (number % divisor == 0)
            prime = 0;            // وجدنا قاسمًا
    }
    if (prime)
        printf("%d is prime\n", number);
    else
        printf("%d is not prime\n", number);
    return 0;
}
