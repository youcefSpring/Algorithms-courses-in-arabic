#include <stdio.h>

int sum(int n) {
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

int main(void) {
    printf("sum(5) = %d\n", sum(5));
    printf("sum(100) = %d\n", sum(100));
    return 0;
}
