#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void) {
    printf("gcd(48, 18) = %d\n", gcd(48, 18));
    printf("gcd(270, 192) = %d\n", gcd(270, 192));
    return 0;
}
