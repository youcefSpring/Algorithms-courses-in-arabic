#include <stdio.h>

void stats(float t[], int n, float *best, float *avg) {
    int i;
    float s = 0;
    *best = t[0];
    for (i = 0; i < n; i++) {
        s += t[i];
        if (t[i] < *best) *best = t[i];
    }
    *avg = s / n;
}
int main(void) {
    float times[5] = {10.12, 9.98, 10.05, 9.91, 10.30}, b, a;
    stats(times, 5, &b, &a);
    printf("Best = %.2f s\nAverage = %.2f s\n", b, a);
    return 0;
}
