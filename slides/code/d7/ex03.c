#include <stdio.h>

float toFahrenheit(float c) {
    return c * 9 / 5 + 32;
}

int main(void) {
    int c;
    for (c = -10; c <= 40; c += 10)
        printf("%3d C = %5.1f F\n", c, toFahrenheit(c));
    return 0;
}
