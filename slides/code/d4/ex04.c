#include <stdio.h>
#define N 5

int main(void) {
    float d[N] = {1.2, 0.8, 2.5, 1.0, 1.7};   /* km */
    float total = 0;
    int i;
    for (i = 0; i < N; i++) {
        total += d[i];
        printf("Stop %d: %.1f km\n", i + 1, total);
    }
    return 0;
}
