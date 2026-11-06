#include <stdio.h>

long slowCalls = 0, fastCalls = 0;
long memo[100];

long fibSlow(int month) {
    slowCalls++;
    if (month <= 2) return 1;
    return fibSlow(month - 1) + fibSlow(month - 2);
}

long fibMemo(int month) {
    fastCalls++;
    if (month <= 2) return 1;
    if (memo[month] != 0) return memo[month];          // محسوبة سابقًا
    memo[month] = fibMemo(month - 1) + fibMemo(month - 2);
    return memo[month];
}

int main(void) {
    long slowValue = fibSlow(30), fastValue = fibMemo(30);
    printf("Naive:    fib(30) = %ld with %ld calls\n", slowValue, slowCalls);
    printf("Memoized: fib(30) = %ld with %ld calls\n", fastValue, fastCalls);
    fastCalls = 0;
    printf("fib(90) = %ld\n", fibMemo(90));
    printf("calls for fib(90) after cache: %ld\n", fastCalls);
    return 0;
}
