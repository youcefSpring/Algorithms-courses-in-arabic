#include <stdio.h>

int isPrime(int n) {
    int d;
    if (n < 2) return 0;
    for (d = 2; d * d <= n; d++)
        if (n % d == 0) return 0;
    return 1;
}

int main(void) {
    int i;
    for (i = 1; i <= 20; i++)
        if (isPrime(i)) printf("%d ", i);
    printf("\n");
    return 0;
}
