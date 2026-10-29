#include <stdio.h>

int main(void) {
    int T[4] = {10, 20, 30, 40};
    int *p = T;            /* same as &T[0] */
    int i;
    for (i = 0; i < 4; i++)
        printf("%d ", *(p + i));
    printf("\n");
    p++;                   /* next element */
    printf("%d\n", *p);
    return 0;
}
