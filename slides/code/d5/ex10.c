#include <stdio.h>
#define R 3
#define C 4
int main(void) {
    int h[R][C] = {{45, 28, 33, 20},
                   {50, 61, 25, 40},
                   {18, 35, 47, 29}};
    int i, j, n = 0;
    for (i = 0; i < R; i++)
        for (j = 0; j < C; j++)
            if (h[i][j] < 30) {
                printf("Irrigate (%d, %d)\n", i, j);
                n++;
            }
    printf("Cells = %d\n", n);
    return 0;
}
