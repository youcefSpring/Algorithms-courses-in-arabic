#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void) {
    printf("d = %.2f km\n", distance(0, 0, 3, 4));
    printf("d = %.2f km\n", distance(2, 5, 10, 11));
    return 0;
}
