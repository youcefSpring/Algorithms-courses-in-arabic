#include <stdio.h>

int maximum(int a, int b);   /* prototype */

int main(void) {
    printf("%d\n", maximum(7, 12));
    return 0;
}

int maximum(int a, int b) {
    if (a > b) return a;
    return b;
}
