#include <stdio.h>
#define N 5

int main(void) {
    int T[N] = {12, 7, 9, 15, 3};
    int i, j, t;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - 1 - i; j++)
            if (T[j] > T[j + 1]) {
                t = T[j]; T[j] = T[j + 1]; T[j + 1] = t;
            }
    for (i = 0; i < N; i++) printf("%d ", T[i]);
    printf("\n");
    return 0;
}
