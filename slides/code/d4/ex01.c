#include <stdio.h>
#define N 7

int main(void) {
    int bpm[N] = {72, 75, 80, 68, 90, 77, 74};
    int i, sum = 0, max = bpm[0];
    for (i = 0; i < N; i++) {
        sum += bpm[i];
        if (bpm[i] > max)
            max = bpm[i];
    }
    printf("Average = %.1f bpm\n", (float) sum / N);
    printf("Max = %d bpm\n", max);
    return 0;
}
