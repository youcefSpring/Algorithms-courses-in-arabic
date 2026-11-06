#include <stdio.h>

long fib(int month) {
    if (month <= 2)
        return 1;                            // الشهران الأولان
    return fib(month - 1) + fib(month - 2);  // استدعاءان عوديان
}

int main(void) {
    int month;
    for (month = 1; month <= 12; month++)
        printf("%ld ", fib(month));
    printf("\n");
    return 0;
}
