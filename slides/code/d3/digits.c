#include <stdio.h>

int main(void) {
    int n, count = 0;
    printf("n = ");
    scanf("%d", &n);
    while (n > 0) {
        n = n / 10;
        count++;
    }
    printf("Digits = %d\n", count);
    return 0;
}
