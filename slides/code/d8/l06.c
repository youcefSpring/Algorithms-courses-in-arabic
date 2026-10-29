#include <stdio.h>

void reverse(int n) {
    if (n == 0)
        return;
    printf("%d", n % 10);
    reverse(n / 10);
}

int main(void) {
    reverse(12345);
    printf("\n");
    return 0;
}
