#include <stdio.h>
#define N 6

int main(void) {
    int aqi[N] = {42, 85, 130, 60, 160, 35};
    int i, good = 0, bad = 0;
    for (i = 0; i < N; i++) {
        if (aqi[i] <= 50)
            good++;
        else if (aqi[i] > 100)
            bad++;
    }
    printf("Good = %d\n", good);
    printf("Unhealthy = %d\n", bad);
    return 0;
}
