#include <stdio.h>
#define P 3
#define R 4
int main(void) {
    float t[P][R] = {{37.2, 38.1, 38.5, 37.9},
                     {36.8, 36.9, 37.0, 36.7},
                     {39.0, 39.4, 38.8, 38.2}};
    int i, j;
    float s;
    for (i = 0; i < P; i++) {
        s = 0;
        for (j = 0; j < R; j++)
            s += t[i][j];
        printf("Patient %d: %.2f C\n", i + 1, s / R);
    }
    return 0;
}
