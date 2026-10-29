#include <stdio.h>

int main(void) {
    int n, i;
    long f = 1;
    printf("n = ");
    scanf("%d", &n);
    for (i = 2; i <= n; i++) {
        f = f * i;
    }
    printf("%d! = %ld\n", n, f);
    return 0;
}
