#include <stdio.h>
#define N 5

int main(void) {
    int T[N] = {1, 2, 3, 4, 5};
    int i, t;
    for (i = 0; i < N / 2; i++) {
        t = T[i];
        T[i] = T[N - 1 - i];
        T[N - 1 - i] = t;
    }
    for (i = 0; i < N; i++) printf("%d ", T[i]);
    printf("\n");
    return 0;
}
