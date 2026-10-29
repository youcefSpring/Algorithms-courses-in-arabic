#include <stdio.h>
#define N 5

int main(void) {
    float T[N] = {12, 8.5, 15, 10, 9.5};
    float s = 0;
    int i;
    for (i = 0; i < N; i++) {
        s = s + T[i];
    }
    printf("Sum = %.2f\n", s);
    printf("Average = %.2f\n", s / N);
    return 0;
}
