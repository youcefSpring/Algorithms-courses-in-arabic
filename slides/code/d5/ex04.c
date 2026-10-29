#include <stdio.h>
#define N 4

int main(void) {
    int d[N][N] = {{  0,  50, 120, 300},
                   { 50,   0,  80, 260},
                   {120,  80,   0, 190},
                   {300, 260, 190,   0}};
    int i, j, sym = 1;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (d[i][j] != d[j][i])
                sym = 0;
    printf("City 1 -> City 4: %d km\n", d[0][3]);
    if (sym) printf("Symmetric matrix\n");
    return 0;
}
