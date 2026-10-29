#include <stdio.h>

int main(void) {
    int c;
    for (c = 0; c <= 40; c += 10)
        printf("%3d C = %5.1f F\n", c, c * 9 / 5.0 + 32);
    return 0;
}
