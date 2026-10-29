#include <stdio.h>
#define T 4
#define M 3
int main(void) {
    int g[T][M] = {{2, 1, 3}, {0, 2, 1},
                   {4, 0, 2}, {1, 1, 1}};
    int i, j, s, best = 0, max = -1;
    for (i = 0; i < T; i++) {
        s = 0;
        for (j = 0; j < M; j++)
            s += g[i][j];
        printf("Team %d: %d goals\n", i + 1, s);
        if (s > max) { max = s; best = i; }
    }
    printf("Best attack: team %d\n", best + 1);
    return 0;
}
