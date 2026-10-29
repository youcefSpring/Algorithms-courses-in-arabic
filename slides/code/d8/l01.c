#include <stdio.h>

long fact(int n) {
    if (n == 0)                 /* stop case */
        return 1;
    return n * fact(n - 1);     /* recursive call */
}

int main(void) {
    printf("4! = %ld\n", fact(4));
    printf("10! = %ld\n", fact(10));
    return 0;
}
