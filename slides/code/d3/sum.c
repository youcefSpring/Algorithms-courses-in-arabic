#include <stdio.h>

int main(void) {
    int n, i, s = 0;
    printf("n = ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        s = s + i;
    }
    printf("Sum = %d\n", s);
    return 0;
}
