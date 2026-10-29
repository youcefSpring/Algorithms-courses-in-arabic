#include <stdio.h>

void binary(int n) {
    if (n < 2) {
        printf("%d", n);
        return;
    }
    binary(n / 2);
    printf("%d", n % 2);
}

int main(void) {
    binary(192); printf("\n");
    binary(168); printf("\n");
    binary(10);  printf("\n");
    return 0;
}
