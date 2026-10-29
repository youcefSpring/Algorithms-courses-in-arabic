#include <stdio.h>

int square(int x) {
    return x * x;
}

int main(void) {
    int a = 5;
    printf("%d\n", square(a));
    printf("%d\n", square(3) + square(4));
    return 0;
}
