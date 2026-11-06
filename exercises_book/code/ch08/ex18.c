#include <stdio.h>

int collatzLength(long number) {
    if (number == 1) return 0;
    if (number % 2 == 0) return 1 + collatzLength(number / 2);
    return 1 + collatzLength(3 * number + 1);
}

int main(void) {
    int number, len, best = 1, bestLen = 0;
    printf("27 needs %d steps\n", collatzLength(27));
    for (number = 1; number <= 1000; number++) {
        len = collatzLength(number);
        if (len > bestLen) {
            bestLen = len;
            best = number;
        }
    }
    printf("Longest under 1000: %d with %d steps\n", best, bestLen);
    return 0;
}
