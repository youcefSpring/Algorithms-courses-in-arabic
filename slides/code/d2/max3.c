#include <stdio.h>

int main(void) {
    int a, b, c, max;
    printf("Three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("Max = %d\n", max);
    return 0;
}
