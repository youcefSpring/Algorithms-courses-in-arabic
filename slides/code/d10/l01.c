#include <stdio.h>

int main(void) {
    int x = 5;
    int *p = &x;          /* p points to x */
    printf("x = %d\n", x);
    printf("*p = %d\n", *p);
    *p = 10;              /* changes x */
    printf("x = %d\n", x);
    return 0;
}
