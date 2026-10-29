#include <stdio.h>
#define N 5

int main(void) {
    int T[N] = {12, 7, 9, 15, 3};
    int i, max = T[0], pos = 0;
    for (i = 1; i < N; i++) {
        if (T[i] > max) {
            max = T[i];
            pos = i;
        }
    }
    printf("Max = %d at index %d\n", max, pos);
    return 0;
}
