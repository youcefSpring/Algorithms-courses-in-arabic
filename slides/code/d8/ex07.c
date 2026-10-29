#include <stdio.h>

double height(double h0, int bounces) {
    if (bounces == 0)
        return h0;
    return 0.7 * height(h0, bounces - 1);
}

int main(void) {
    int b;
    for (b = 0; b <= 4; b++)
        printf("Bounce %d: %.2f m\n", b, height(2, b));
    return 0;
}
