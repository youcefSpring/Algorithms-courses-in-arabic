#include <stdio.h>
#define N 3

int main(void) {
    int img[N][N] = {{  0, 128, 255},
                     { 64, 200,  30},
                     {255,  10,  90}};
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            img[i][j] = 255 - img[i][j];
            printf("%4d", img[i][j]);
        }
        printf("\n");
    }
    return 0;
}
