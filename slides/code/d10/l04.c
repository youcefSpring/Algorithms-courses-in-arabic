#include <stdio.h>

void minMax(int T[], int n, int *min, int *max) {
    int i;
    *min = *max = T[0];
    for (i = 1; i < n; i++) {
        if (T[i] < *min) *min = T[i];
        if (T[i] > *max) *max = T[i];
    }
}

int main(void) {
    int A[5] = {12, 7, 19, 3, 15}, lo, hi;
    minMax(A, 5, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);
    return 0;
}
