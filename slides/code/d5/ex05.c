#include <stdio.h>
#define S 3
#define M 4
int main(void) {
    int v[S][M] = {{120, 150,  90, 200},
                   { 80,  60, 110,  95},
                   {200, 210, 180, 250}};
    int i, j, s;
    for (j = 0; j < M; j++) {
        s = 0;
        for (i = 0; i < S; i++)
            s += v[i][j];
        printf("Month %d: %d sales\n", j + 1, s);
    }
    return 0;
}
