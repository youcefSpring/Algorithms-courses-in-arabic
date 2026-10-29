#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 8, i;
    double s = 0;
    double *m = malloc(n * sizeof(double));
    if (m == NULL) return 1;
    for (i = 0; i < n; i++) {
        m[i] = 20 + i * 1.5;       /* sensor values */
        s += m[i];
    }
    printf("%d values, mean = %.2f\n", n, s / n);
    free(m);
    return 0;
}
