#include <stdio.h>
#define N 5

int main(void) {
    float t[N] = {10.12, 9.98, 10.05, 9.91, 10.30};
    int i, best = 0;
    for (i = 1; i < N; i++)
        if (t[i] < t[best])
            best = i;
    printf("Winner: athlete %d\n", best + 1);
    printf("Time = %.2f s\n", t[best]);
    return 0;
}
