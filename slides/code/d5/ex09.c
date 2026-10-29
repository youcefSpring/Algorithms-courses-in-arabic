#include <stdio.h>
#define R 3
#define C 4
int main(void) {
    float p[R][C] = {{4.2, 4.5, 4.1, 3.9},
                     {4.8, 5.1, 4.9, 4.0},
                     {3.5, 3.8, 4.4, 4.6}};
    int i, j, bi = 0, bj = 0;
    float total = 0;
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++) {
            total += p[i][j];
            if (p[i][j] > p[bi][bj]) { bi = i; bj = j; }
        }
    printf("Total = %.1f kWh\n", total);
    printf("Best panel: (%d, %d)\n", bi, bj);
    return 0;
}
