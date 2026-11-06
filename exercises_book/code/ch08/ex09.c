#include <stdio.h>

int gcd(int first, int second) {
    if (second == 0)
        return first;
    return gcd(second, first % second);
}

int main(void) {
    int returned, delivered, divisor;
    scanf("%d %d", &returned, &delivered);
    divisor = gcd(returned, delivered);
    printf("gcd = %d\n", divisor);
    printf("Return ratio: %d / %d\n", returned / divisor, delivered / divisor);
    return 0;
}
